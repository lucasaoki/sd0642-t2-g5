#!/bin/bash

base=../
basepath=${base}doc/out/
pathHosts=${basepath}hosts/
pathTime=${basepath}'times'/

grepVariable=("0" "INSERT" "SELECT" "DELETE");

commandoCut="cut -d ' ' -f 10"

for i in `seq 1 12`; do
	for j in `seq 1 3`; do
		grep ${grepVariable${i}} | ${commandoCut} >> ${pathTime}${grepVariable}Hosts${i}.txt	
	done	
	${commandoCut} ${pathHosts}host${i}out.txt >> ${pathTime}timeHosts${i}.txt
done
