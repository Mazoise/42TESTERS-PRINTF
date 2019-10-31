rm results/* diff.txt &> /dev/null
cp ../*.h includes/ &> /dev/null
cp ../*/*.h includes/ &> /dev/null
gcc srcs/main.c -w -D PRINT="printf" -I ./includes -o printf.out >> /dev/null
./printf.out >> results/expected_result.txt
make -C srcs/ re > /dev/null 2> results/compilerror.txt
./srcs/tester.out > results/test_result.txt #2> results/error.txt

i=1
sed -n ${i}p results/expected_result.txt >> printf.txt

while [ -s printf.txt ]
do
	rm -f printf.txt ft.txt
	sed -n ${i}p results/expected_result.txt >> printf.txt
	sed -n ${i}p results/test_result.txt >> ft.txt
	if [ $i -lt 10 ] ; then
		echo -n "Test   $i :" 
	elif [ $i -lt 100 ] ; then
		echo -n "Test  $i :" 
	else
		echo -n "Test $i :"
	fi
	if diff ft.txt printf.txt >> diff.txt ; then
 		echo -ne "\033[0;32m[OK]	\033[0m" && echo "No Diff" >> diff.txt
	else
 		 echo -ne "\033[0;31m[KO]	\033[0m"
	fi
	let "j = $i % 10"
	if [ $j -eq 0 ] ; then
		echo
	fi
	let "i += 1"
done
echo
rm includes/* printf.txt ft.txt printf.out &> /dev/null
make -C srcs/ fclean > /dev/null 2> results/compilerror.txt