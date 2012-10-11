#!/bin/bash

base=../
basepath=${base}doc/out/
pathHosts=${basepath}hosts/
pathTime=${basepath}times/

commandoCut=cut -d ' ' -f 10

for i in `seq 1 12`; do
	${commandoCut} ${pathHosts}host${i}out.txt >> ${pathTime}timeHosts${i}.txt
done
