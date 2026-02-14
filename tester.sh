#!/bin/bash

PUSH_SWAP="./push_swap"
INPUT=$(gshuf -i 1-500 -n 500)

echo "Testing input.."
echo "--------------------------"

OPERATIONS=$($PUSH_SWAP $INPUT)

COUNT=$(echo "$OPERATIONS" | wc -l)
echo "Moves: $COUNT"
echo "--------------------------"

RESULT=$(echo "$INPUT" | tr ' ' '\n' | sort -n | tr '\n' ' ')

FINAL=$(echo "$INPUT" | tr ' ' '\n' | sort -n | tr '\n' ' ')

if [ "$RESULT" = "$FINAL" ]; then
	echo "Is sorted!"
else
	echo "Not sorted.."
fi