rm diff.txt &> /dev/null
rm -rf includes results
mkdir includes results
cp ../*.h includes/ &> /dev/null
cp ../*/*.h includes/ &> /dev/null
touch results/expected_return.txt results/test_return.txt
gcc srcs/main.c srcs/ft_putnbr_fd.c srcs/ft_putchar_fd.c srcs/ft_substr.c -D PRINT="printf" -D REAL_F=1 -I ./includes -o printf.out # &> /dev/null
./printf.out >> results/expected_result.txt
make -C srcs/ 
./srcs/tester.out >> results/test_result.txt
echo ""
echo "============================================================================================================================================================="
echo "========================================================================= FT_PRINTF ========================================================================="
echo "============================================================================================================================================================="
echo ""
i=1
sed -n ${i}p results/expected_result.txt >> printf.txt
sed -n ${i}p results/test_result.txt >> ft.txt
if [ -s ft.txt ] ; then
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
	DIFF=$(diff ft.txt printf.txt)
	if [ "$DIFF" == "" ] ; then
 		echo -ne "\033[0;32m\xE2\x9C\x94\033[0m"
	else
 		echo -ne "\033[0;31mx\033[0m"
		echo "----------Test $i : Output value ----------" >> diff.txt
		echo "$DIFF" >> diff.txt
		echo >> diff.txt
	fi
	DIFF=$(diff ft_r.txt printf_r.txt)
	if [ "$DIFF" == "" ] ; then
 		echo -ne "\033[0;32m \xE2\x9C\x94	\033[0m"
	else
 		echo -ne "\033[0;31m x	\033[0m"
		echo "----------Test $i : Return value ----------" >> diff.txt
		echo "$DIFF" >> diff.txt
		echo >> diff.txt

	fi
	let "j = $i % 10"
	if [ $j -eq 0 ] ; then
		echo
	fi
	let "i += 1"
done
echo
echo
if diff results/expected_result.txt results/test_result.txt &> /dev/null ; then
 		echo -ne "Output values :\033[0;32m [OK]\033[0m"
	else
 		echo -ne "Output values :\033[0;31m [KO]\033[0m"
	fi
echo
if diff results/expected_return.txt results/test_return.txt &> /dev/null ; then
 		echo -ne "Return values:\033[0;32m [OK]\033[0m"
	else
 		echo -ne "Return values:\033[0;31m [KO]\033[0m"
	fi
echo

else
	echo -e "\033[0;31m _                    _\033[0m"
	echo -nee "\033[4;31m/!\\"
	echo -ne "\033[0m\033[0;31m Does Not Compile \033[0m"
	echo -e "\033[4;31m/!\\"
	echo
	echo
fi
rm -rf includes results printf.txt printf_r.txt ft_r.txt ft.txt printf.out &> /dev/null
make -C srcs/ fclean &> /dev/null
