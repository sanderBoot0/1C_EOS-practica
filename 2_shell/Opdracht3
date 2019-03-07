#!/usr/bin/env bash

for filename in `find ${1}*.jpg`; do
    convert ${filename} -resize 128x128 ${filename%.*}.png
done
