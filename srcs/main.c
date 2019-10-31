#include <stdio.h>
#include <unistd.h>
#include "ft_printf.h"

int main()
{
	int		a = 0;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	c = 'a';
	
	PRINT("Simple input test\n"); //T1
	PRINT("%i, %d, %d, %d, %d, %s, %c, %d\n", i, j, k, l, m, n, c, c); //T2
	PRINT("%0i, %0d, %0d, %0d, %0d, %0s, %0c, %0d\n", i, j, k, l, m, n, c, c); //T3
	while(a < 8)
	{
		PRINT("%*i, %*d, %*d, %*d, %*d, %*d\n", a, i, a, j, a, k, a, l, a, m, a, c); //T4, 8, 12, 16, 20, 24, 28, 32
		PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d\n", a, i, a, j, a, k, a, l, a, m, a, c); //T5, 9, 13, 21, 25, 29, 33
		PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d\n", a, i, a, j, a, k, a, l, a, m, a, c); //T6, 10, 14, 22, 26, 30, 34
		PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d\n", a, i, a, j, a, k, a, l, a, m, a, c); //T7, 11, 15, 23, 27, 31, 35
		a++;
	}
	PRINT("%%, \%, %, \t, \\, \", \', \+, +\n", i); //T36
	PRINT("%5999999999999999990i, %5999999999999999990d, %5999999999999999990d, %5999999999999999990d, %5999999999999999990d, %5999999999999999990s, %5999999999999999990c, %5999999999999999990d\n", i, j, k, l, m, n, c, c);


	PRINT("");
}