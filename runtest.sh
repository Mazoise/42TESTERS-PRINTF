#!/bin/bash

rm diff.txt &> /dev/null
rm -rf results
mkdir results
gcc -Wall -Werror -Wextra -w srcs/main_tester.c -D PRINT="printf" -o printf.out # &> /dev/null
./printf.out >> results/expected_result.txt
make -C srcs/
./srcs/tester.out >> results/test_result.txt
cp srcs/main_tester.c srcs/main_test_list.c
sed -i -e "s/PRINT(\" --- Return : %d\\\n\", /B/g" srcs/main_test_list.c
sed -i -e "s/));/);/g" srcs/main_test_list.c
gcc -Wall -Werror -Wextra -w srcs/main_test_list.c -D PRINT="printf" -o printf.out # &> /dev/null
./printf.out >> results/test_list.txt
echo ""
echo "============================================================================================================================================================="
echo "========================================================================= FT_PRINTF ========================================================================="
echo "============================================================================================================================================================="
echo ""
i=1
k=0
sed -n ${i}p results/expected_result.txt >> printf.txt
if [ -s results/test_result.txt ] ; then
while [ -s printf.txt ]
do
	rm -f printf.txt ft.txt printf_r.txt ft_r.txt
	sed -n ${i}p results/expected_result.txt >> printf.txt
	sed -n ${i}p results/test_result.txt >> ft.txt
	if [ $i -lt 10 ] ; then
		echo -n "Test   $i :"
	elif [ $i -lt 100 ] ; then
		echo -n "Test  $i :"
	else
		echo -n "Test $i :"
	fi
	DIFF=$(diff ft.txt printf.txt)
	if [ "$DIFF" == "" ] ; then
 		echo -ne "\033[0;32m \xE2\x9C\x94	\033[0m"
		let "k += 1"
	else
 		echo -ne "\033[0;31m x	\033[0m"
		echo "----------Test $i : ----------" >> diff.txt
		sed -n ${i}p results/test_list.txt >> diff.txt
		echo >> diff.txt
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
let "i -= 1"
if [ $i -eq $k ] ; then
 		echo -ne "
                              _           _
                             / \_______ /|_\\
                            /          /_/ \__
                           /             \_/ /
                         _|_              |/|_
                         _|_  O    _    O  _|_
                         _|_      (_)      _|_  \033[0;32m $k / $i : Well done ! \033[0m
                          \                 /
                           _\_____________/_
                          /  \/  (___)  \/  \\
                          \__(  o     o  )__/ "
	else
 		echo -ne "░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄░░░░░░░
░░░░░█░░░░▒▒▒▒▒▒▒▒▒▒▒▒░░▀▀▄░░░░
░░░░█░░░▒▒▒▒▒▒░░░░░░░░▒▒▒░░█░░░
░░░█░░░░░░▄██▀▄▄░░░░░▄▄▄░░░░█░░
░▄▀▒▄▄▄▒░█▀▀▀▀▄▄█░░░██▄▄█░░░░█░
█░▒█▒▄░▀▄▄▄▀░░░░░░░░█░░░▒▒▒▒▒░█
█░▒█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄▒█
░█░▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█░
░░█░░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█░░
░░░█░░░░██░░▀█▄▄▄█▄▄█▄████░█░░░
░░░░█░░░░▀▀▄░█░░░█░█▀██████░█░░ \033[0;31m $k / $i : Try Again ! \033[0m
░░░░░▀▄░░░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█░░
░░░░░░░▀▄▄░▒▒▒▒░░░░░░░░░░▒░░░█░
░░░░░░░░░░▀▀▄▄░▒▒▒▒▒▒▒▒▒▒░░░░█░
░░░░░░░░░░░░░░▀▄▄▄▄▄░░░░░░░░█░░"
	fi
echo
echo
echo

else
	echo -e "\033[0;31m \xEA\x93\xA5                    \xEA\x93\xA5 \033[0m"
	echo -ne "\033[4;31m/!\\"
	echo -ne "\033[0m\033[0;31m Does Not Compile \033[0m"
	echo -e "\033[4;31m/!\\"
	echo
	echo
fi
rm -rf results printf.txt ft.txt test.txt printf.out srcs/main_test_list.c srcs/main_test_list.c-e &> /dev/null
make -C srcs/ fclean &> /dev/null
