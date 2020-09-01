#!/usr/bin/env bash

mkdir ${1}afbeeldingen;

for filename in ${1}*.jpg; do
  mv "$filename" ${1}afbeeldingen
done
  
find ${1} -maxdepth 1 -name '*.png' -exec mv {} ${1}afbeeldingen \;  
