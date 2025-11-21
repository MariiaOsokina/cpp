#!/bin/bash

# ==========================================
#        CPPP 09 Ex01 Tester
# ==========================================

# Colors for output
GREEN='\033[0;32m'
RED='\033[0;31m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# executable name
NAME="./RPN"

# 1. COMPILATION CHECK
# Adjust the source files below if yours are in different folders (e.g., src/RPN.cpp)
echo -e "${BLUE}[*] Compiling...${NC}"
c++ -Wall -Wextra -Werror -std=c++98 main.cpp RPN.cpp -o RPN 2>/dev/null

if [ ! -f "$NAME" ]; then
    echo -e "${RED}Error: Compilation failed or $NAME not found.${NC}"
    echo "Please compile your project manually or fix the path in this script."
    exit 1
fi
echo -e "${GREEN}[*] Compilation success.${NC}"
echo ""

# Function to execute a test case
# Usage: run_test "RPN_EXPRESSION" "EXPECTED_OUTPUT"
run_test() {
    local expr="$1"
    local expected="$2"
    
    # Run the program and capture both STDOUT and STDERR
    # We use 'tr -d' to remove newlines for cleaner comparison
    local output=$($NAME "$expr" 2>&1 | tr -d '\n')

    # Comparison Logic
    if [ "$output" == "$expected" ]; then
        printf " ${GREEN}[OK]${NC}  Input: %-30s  Got: %s\n" "\"$expr\"" "$output"
    else
        # Special check for Error messages
        # If we expect "Error" and the output *contains* "Error", we count it as a pass
        # (This covers cases like "Error: bad input" vs just "Error")
        if [ "$expected" == "Error" ] && [[ "$output" == *"Error"* ]]; then
             printf " ${GREEN}[OK]${NC}  Input: %-30s  Got: %s (Matches Error)\n" "\"$expr\"" "$output"
        else
             printf " ${RED}[KO]${NC}  Input: %-30s\n" "\"$expr\""
             printf "       Expected: %s\n" "$expected"
             printf "       Got:      %s\n" "$output"
        fi
    fi
}

# ==========================================
#              TEST CASES
# ==========================================

echo -e "${BLUE}--- Subject Examples ---${NC}"
run_test "8 9 * 9 - 9 - 9 - 4 - 1 +" "42"
run_test "7 7 * 7 -" "42"
run_test "1 2 * 2 / 2 * 2 4 - +" "0"
run_test "(1 + 1)" "Error"

echo ""
echo -e "${BLUE}--- Basic Operations ---${NC}"
run_test "1 1 +" "2"
run_test "9 3 /" "3"
run_test "5 2 *" "10"
run_test "9 5 -" "4"

echo ""
echo -e "${BLUE}--- Edge Cases & Errors ---${NC}"
# Division by Zero
run_test "1 0 /" "Error"

# Numbers >= 10
run_test "10 5 +" "Error"

# Not enough operands
run_test "1 2 + +" "Error"
run_test "1 +" "Error"

# Empty / Whitespace
run_test "" "Error"
run_test "   " "Error"

# Invalid tokens
run_test "a 1 +" "Error"
run_test "1 1 &" "Error"

echo ""
echo -e "${BLUE}--- Done ---${NC}"

# Cleanup
rm -f RPN
