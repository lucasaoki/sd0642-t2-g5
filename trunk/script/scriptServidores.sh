#!/bin/bash

base=../
binfolder=${base}bin/
basepath=${base}doc/out/
pathServer=${basepath}server/
pathHosts=${basepath}hosts/

echo É necessário estar logado no servidor X-men para execucao
echo do teste.

hostsClients=("0" "ciclope" "wolwerine" "magneto" "hulk" "colossus" "tempestade" "demolidor" "noturno" "vampira" "gambit" "elektra" "anjo")

echo Servidor RPC
ssh -f x-men "./pw2_server >> ${pathServer}serverXMENout.txt " 

for	i in `seq 1 12`; do
	echo Host $i 
	ssh -f ${hostsClients[${i}]} "export LOCALHOST" 
	ssh -f ${hostsClients[${i}]} "${binfolder}pw2_client x-men >> ${pathHosts}host${i}out.txt" 
done

