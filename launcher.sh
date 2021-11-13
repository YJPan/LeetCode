#!/bin/bash

FILETYPE="cpp"

if [[ $# -lt 1 ]]; then
    echo ""
    echo "Usage: ./launcher.sh <filetype> title_of_problem"
    echo ""
    echo "The defualt filetype is \"$FILETYPE\" (cpp, py, go are supported)"
    echo ""
    exit 0
fi

if [[ "$@" == *.cpp ]]; then
    g++ $1 -o answer -std=c++17

    if [[ -f "./answer" ]]; then
        ./answer
    fi
elif [[ "$@" == *.py ]]; then
    python3 $1
elif [[ "$@" == *.go ]]; then
    go run $1
else
    if [[ "$1" == "cpp" || "$1" == "py" || "$1" == "cpp" ]]; then
        FILETYPE=$1
        shift
    fi

    echo "Purge old files ..."
    rm -f ./answer

    TITLE="$@"
    filename=`python3 -c "
title = \"$TITLE\"
num, name = title.split('. ')
num = int(num)
name = '_'.join(name.split()) + '.$FILETYPE'
print(f'{num:04d}_{name}')
    "`

    echo "Generate $filename ..."

    cp template.$FILETYPE cpp/$filename
fi
