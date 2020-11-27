# 42TESTERS-PRINTF

If you want to be a good developer, please make your own tests. You should only use testers when you're correcting someone or just before submitting your work to see what tests you haven't thought of doing. If you finish a project without testing it yourself, you've only done a quarter of it.

1 - cd to the folder with your fonctions

2 - git clone https://github.com/Mazoise/42TESTERS-PRINTF.git

3 - cd 42TESTERS-PRINTF

4 - bash run_test.sh

5 - check diff.txt in case of errors

Path to your project's Makefile can be changed in srcs/Makefile (Default : LIBPATH = ../../)

WARNING if you are working on Linux : Some undefined behaviours are present in this tester because they might be tested by moulinette. For example null strings (line 185 of my main) and null pointers (lines 156-163 and line 169) which will not give the same result on linux and macos.


\
<br>
Remerciements :
addubois pour la troll face et hellokitty
