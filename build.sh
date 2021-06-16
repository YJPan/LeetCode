#!/bin/bash

if [[ "$@" == *.cpp ]]; then
    g++ $1 -o answer -std=c++11
    ./answer
elif [[ "$@" == *.py ]]; then
    python3 $1
elif [[ "$@" == *.go ]]; then
    go run $1
else
    FILETYPE="cpp"

    if [[ "$1" == "cpp" || "$1" == "py" || "$1" == "cpp" ]]; then
        FILETYPE=$1
        shift
    fi

    TITLE="$@"
    filename=`python3 -c "
title = \"$TITLE\"
num, name = title.split('. ')
num = int(num)
name = '_'.join(name.split()) + '.$FILETYPE'
print(f'{num:04d}_{name}')
    "`

    echo "Generating $filename ..."

    cp template.$FILETYPE $filename
fi
