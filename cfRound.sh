#!/bin/bash
path="codeforces/rounds"
mkdir -p "$path/$1"
touch "$path/$1/"/{a,b,c}.cpp
cat template.cpp > "$path/$1/"a.cpp
cat template.cpp > "$path/$1/"b.cpp
cat template.cpp > "$path/$1/"c.cpp
code "$path/$1/"a.cpp