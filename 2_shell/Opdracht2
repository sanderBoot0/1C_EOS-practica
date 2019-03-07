#!/usr/bin/env bash

numberOne=0;
numberTwo=0;
numberThree=0;

for filename in `find ${1}`; do 
    case $filename in 
        *.${2})
            let "numberOne += 1"
        ;;
        *.${3})
            let "numberTwo += 1"
        ;;
        *.${4})
            let "numberThree += 1"
        ;;
        *)
            
        ;;
    esac
done

echo "${2} occurees $numberOne times";
echo "${3} occures $numberTwo times";
echo "${4} occures $numberThree times";
