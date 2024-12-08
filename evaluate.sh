#!/bin/bash

echo ....................;

$1 < $2  > $3 &&

echo ....................;

# ./a.out < input.txt > output_temp.txt;

# if [[ $? -eq 0 ]]; then
    # echo "s"
# fi