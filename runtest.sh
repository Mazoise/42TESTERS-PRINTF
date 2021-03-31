#!/bin/bash

rm diff.txt &> /dev/null
rm -rf results
mkdir results
gcc -Wall -Werror -Wextra -pthread -w srcs/main_tester.c -D PRINT="printf" -o printf.out # &> /dev/null
./printf.out >> results/expected_result.txt
make -C srcs/
./srcs/tester.out >> results/test_result.txt
RET=$?
cp srcs/main_tester.c srcs/main_test_list.c
sed -i -e "s/PRINT(\" --- Return : %d\\\n\", /B/g" srcs/main_test_list.c
sed -i -e "s/));/);/g" srcs/main_test_list.c
gcc -Wall -Werror -Wextra -pthread -w srcs/main_test_list.c -D PRINT="printf" -o printf.out # &> /dev/null
./printf.out >> results/test_list.txt
echo ""
echo "============================================================================="
echo "================================= FT_PRINTF ================================="
echo "============================================================================="
echo ""
test_count=$(wc -l results/expected_result.txt | cut -f 1 -d " ")
i=1
k=0
sed -n ${i}p results/test_result.txt >> ft.txt
if [ $RET -ne 127 ] ; then
	while [ -s ft.txt ] && [[ $i -le $test_count ]] ; do
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
		let "j = $i % 5"
		if [ $j -eq 0 ] ; then
			echo
		fi
		let "i += 1"
	done
	let "i -= 1"
	if [[ $i -ne $test_count ]] ; then
		if [ $RET -eq 124 ] ; then
			echo -ne "\033[0;31m TIMEOUT \033[0m"
		elif [ $RET -eq 139 ] ; then
			echo -ne "\033[0;31m SEGFAULT \033[0m"
		elif [ $RET -gt 0 ]; then
		echo -ne "\033[0;31m PROGRAM RETURNED ERROR $RET \033[0m"
		fi
	else
		echo
		echo
		if [[ $i -eq $k ]] ; then
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
			echo -ne "
        ░░░░░▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄░░░░░░░
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
	fi
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
