# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/06 18:03:26 by kasakamo          #+#    #+#              #
#    Updated: 2025/07/07 17:26:30 by kasakamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

OK=0
KO=0
ERR=0

test_case() {
	INPUT="$*"
	echo -n "Test: $INPUT  -> "

	OUTPUT=$(./push_swap $INPUT 2>ps_err.txt)
	EXIT_CODE=$?

	if grep -q "Error" ps_err.txt || [ $EXIT_CODE -ne 0 ]; then
		printf "${RED}Error${NC} (push_swap error)\n"
		ERR=$((ERR+1))
		return
	fi

	if [ -z "$OUTPUT" ]; then
		printf "${GREEN}OK${NC} (0 ops)\n"
		OK=$((OK+1))
		return
	fi

	RESULT=$(echo "$OUTPUT" | ./checker_linux $INPUT 2>&1)

	if [ "$RESULT" = "OK" ]; then
		OPS=$(echo "$OUTPUT" | wc -l)
		printf "${GREEN}OK${NC} (%d ops)\n" "$OPS"
		OK=$((OK+1))
	elif [ "$RESULT" = "KO" ]; then
		printf "${RED}KO${NC}\n"
		KO=$((KO+1))
	else
		printf "${RED}Error${NC} ($RESULT)"
		ERR=$((ERR+1))
	fi
}

echo "⏳ Running test cases..."

# --- Basic ---
test_case 1
test_case 1 2
test_case 2 1
test_case 3 2 1
test_case 1 5 2 4 3
test_case 10 20 30 40 50

# --- Sorted ---
test_case 1 2 3 4 5

# --- Reverse ---
test_case 5 4 3 2 1

# --- Duplicates (err) ---
test_case 1 2 2 3

# --- Invalid (err) ---
test_case a b c
test_case 3.14 42
test_case 2147483648	# INT_MAX + 1
test_case -2147483649	# INT_MIN - 1

# --- Random 5 numbers ---
for i in {1..5}; do
	ARGS=$(shuf -i 1-100 -n 6 | tr '\n' ' ')
	test_case "$ARGS"
done

# --- Random 100 (optional, slow) ---
ARGS=$(shuf -i 1-500 -n 100 | tr '\n' ' ')
test_case "$ARGS"

echo ""
echo "✅ OK: $OK"
echo "❌ KO: $KO"
echo "❕ ERR: $ERR"
