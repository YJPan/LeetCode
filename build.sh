#!/bin/bash

if [[ "$@" == *.cpp ]]; then
    g++ $1 -o ans -std=c++11
elif [[ "$@" == *.py ]]; then
    python3 $1
elif [[ "$@" == *.go ]]; then
    go run $1
else
    TITLE="$@"
    filename=`python3 -c "
title = \"$TITLE\"
num, name = title.split('. ')
num = int(num)
name = '_'.join(name.split()) + '.cpp'
print(f'{num:04d}_{name}')
    "`
    echo "Generating $filename ..."
    cp template.cpp $filename
fi
