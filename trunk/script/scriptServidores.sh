#!/bin/bash

base='sd0642-t2-g5'/
binfolder=${base}bin/
basepath=${base}doc/out/
pathServer=${basepath}server/
pathHosts=${basepath}hosts/

echo É necessário estar logado no servidor X-men para execucao
echo do teste.

hostsClients=("0" "ciclope" "wolverine" "magneto" "hulk" "colossus" "tempestade" "demolidor" "noturno" "vampira" "gambit" "elektra" "anjo")

#echo Servidor RPC
#ssh -f x-men "./server >> ${pathServer}serverXMENout.txt " 

for	i in `seq 1 12`; do
	echo Host $i 
	ssh -f ${hostsClients[${i}]} "./${binfolder}client x-men >> ${pathHosts}host${i}out.txt" 
done

