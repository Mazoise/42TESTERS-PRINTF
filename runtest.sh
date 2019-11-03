rm diff.txt &> /dev/null
cp ../*.h includes/ &> /dev/null
cp ../*/*.h includes/ &> /dev/null
touch results/expected_return.txt results/test_return.txt
gcc srcs/main.c srcs/ft_putnbr_fd.c srcs/ft_putchar_fd.c -D PRINT="printf" -D REAL_F=1 -I ./includes -o printf.out &> /dev/null
./printf.out >> results/expected_result.txt
make -C srcs/ 
./srcs/tester.out >> results/test_result.txt
echo ""
echo "============================================================================================================================================================="
echo "========================================================================= FT_PRINTF ========================================================================="
echo "============================================================================================================================================================="
echo ""
echo "Test values are : i = 8, j = -12, k = 123456789, l = 0, m = -12345678, *n = \"abcdefghijklmnop\", c = 'a'" >> diff.txt && echo >> diff.txt && echo >> diff.txt
i=1
sed -n ${i}p results/expected_result.txt >> printf.txt

while [ -s printf.txt ]
do
	rm -f printf.txt ft.txt printf_r.txt ft_r.txt
	sed -n ${i}p results/expected_result.txt >> printf.txt
	sed -n ${i}p results/test_result.txt >> ft.txt
	sed -n ${i}p results/expected_return.txt >> printf_r.txt
	sed -n ${i}p results/test_return.txt >> ft_r.txt
	if [ $i -lt 10 ] ; then
		echo -n "Test   $i :" 
	elif [ $i -lt 100 ] ; then
		echo -n "Test  $i :" 
	else
		echo -n "Test $i :"
	fi
	echo "----------Test $i ----------" >> diff.txt
	echo -n "String : " >> diff.txt
	if diff ft.txt printf.txt >> diff.txt ; then
 		echo -ne "\033[0;32m\xE2\x9C\x94\033[0m" && echo "No Diff" >> diff.txt
	else
 		 echo -ne "\033[0;31mx\033[0m"
	fi
	echo -n "Return : " >> diff.txt
	if diff ft_r.txt printf_r.txt >> diff.txt ; then
 		echo -ne "\033[0;32m \xE2\x9C\x94	\033[0m" && echo "No Diff" >> diff.txt
	else
 		 echo -ne "\033[0;31m x	\033[0m"
	fi
	let "j = $i % 10"
	if [ $j -eq 0 ] ; then
		echo
	fi
	let "i += 1"
done
echo
rm includes/* results/* printf.txt printf_r.txt ft_r.txt ft.txt printf.out &> /dev/null
make -C srcs/ fclean &> /dev/null