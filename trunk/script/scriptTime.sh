#!/bin/bash

base=../
basepath=${base}doc/out/
pathHosts=${basepath}hosts/
pathTime=${basepath}'times'/

grepVariable=("0" "INSERT" "SELECT" "DELETE");

commandoCut="cut -d ' ' -f 10"

for i in `seq 1 12`; do
	for j in `seq 1 3`; do
		grep ${grepVariable[${j}]} ${pathHosts}host${i}out.txt | cut -d ' ' -f 10 >> ${pathTime}host${i}/${grepVariable[${j}]}host${i}.txt	
	done	
	grep 'Time' ${pathHosts}host${i}out.txt | cut -d ' ' -f 10 >> ${pathTime}host${i}/timeHosts${i}.txt
done
