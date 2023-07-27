#!/bin/bash

TIMEFORMAT=%R

PROBLEM_ID=$1
PROBLEM="${PROBLEM_ID}"

SUBMISSION=$2

PROBLEM_FOLDER=$(ls judge-data | grep $PROBLEM)
JUDGE_DATA="./judge-data/${PROBLEM_FOLDER}/judge"

for input in $(ls $JUDGE_DATA); do
    if [[ $input == *.in ]]; then
        answer_file="${input%.*}.ans"
        echo "Running test case $input"
        SECONDS=0
        ./$SUBMISSION < $JUDGE_DATA/$input > output.txt
        echo $SECONDS
        if [ $SECONDS -gt 1 ]; then
            echo TLE
            break
        fi
        diff -w $JUDGE_DATA/$answer_file output.txt || break
    fi
done
