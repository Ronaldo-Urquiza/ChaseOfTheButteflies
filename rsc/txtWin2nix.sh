#!/bin/bash

##################################################################################
#																			 	 #
# Script para corrigir arquivos txt proveniente do ambiente Windows para *nix	 #
#																			 	 #
##################################################################################

function usage()
{
	echo -n "\
Usage:
   $0 [-b] Arq1 [Arq2] [ArqN]
   -b: backup de original acrescentando ~ ao final
"
	exit 1
}

[[ $# -eq 0 ]] && usage

backup=0

[[ $# -gt 0 && $1 = '-b' ]] && { backup=1; shift; } 

[[ $# -eq 0 ]] && usage

for arq
do
	(( backup == 1 )) && cp "$arq" "$arq"~
	sed -i 's/\cM// ' "$arq"
done

