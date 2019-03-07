#!/usr/bin/env bash

mkdir ${1}Vakantie

for filename in `find ${1} -maxdepth 1 | grep vakantie`; do
    mv "$filename" ${1}Vakantie
done
