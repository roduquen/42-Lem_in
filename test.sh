#!/bin/zsh
echo "enter number of test you want to do :"
read size
i=0
gen=0
lemin=0
ended=0
while [ $i != $size ]
	do
		./generator --big-superposition > test
		gen=$(($gen + `cat test | grep "lines" | awk '{if(NR % 2)print $0}' | cut -d' ' -f 7,8 | cut -d ' ' -f 2`))
		lemin=$((lemin + `./lem-in < test | grep L | wc -l`))
		i=$(($i + 1))
		ended=$(($ended + 1))
		echo "$ended / $(($size * 2))"
	done
i1=0
gen1=0
lemin1=0
while [ $i1 != $size ]
	do
		./generator --big > test
		gen1=$(($gen1 + `cat test | grep "lines" | awk '{if(NR % 2)print $0}' | cut -d' ' -f 7,8 | cut -d ' ' -f 2`))
		lemin1=$((lemin1 + `./lem-in < test | grep L | wc -l`))
		i1=$(($i1 + 1))
		ended=$(($ended + 1))
		echo "$ended / $(($size * 2))"
	done
echo "\nBIG SUPERPOSITION :\n\nNombre de coups de Lemin : $lemin\nNombre de coups du generateur : $gen\nPartie actuel : $i"
echo "difference : $(($lemin - $gen))\n"
echo "BIG :\n\nNombre de coups de Lemin : $lemin1\nNombre de coups du generateur : $gen1\nPartie actuel : $i1\n"
echo "difference : $(($lemin1 - $gen1))"
