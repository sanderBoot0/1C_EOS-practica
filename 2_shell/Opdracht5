#!/usr/bin/env bash

naam="whoami";

read -p "Geef een naam: " tmpNaam;

if [ "$tmpNaam" != "" ]; then
    naam="$tmpNaam";
fi

samePW=false;

while [ ${samePW} = false ]; do
    read -s -p "Geef een wachtwoord: " pass;
    echo;
    read -s -p "Herhaal wachtwoord: " tmpPass;
    echo;

    if [ "${pass}" = "${tmpPass}" ] && [[ ${pass} =~ [A-Z] ]] && [[ ${pass} =~ [a-z] ]] && [[ ${pass} =~ [0-9] ]]; then
        echo "Correct password!";
        samePW=true;
    fi
done

touch ${1}.txt;
echo "${naam} ${pass}" > ${1}.txt;
md5sum ${1}.txt > ${1}.txt;
