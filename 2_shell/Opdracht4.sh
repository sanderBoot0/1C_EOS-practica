#!/usr/bin/env bash

touch log.txt;

for filename in `find ${1}`; do
    if ${2} $filename; then  
        echo "Command \"${2}\" for file ${filename} Succeeded" >> log.txt;
    else
        echo "Command \"${2}\" for file ${filename} Failed" >> log.txt;
    fi
done
