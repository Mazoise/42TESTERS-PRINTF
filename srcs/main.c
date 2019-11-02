#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

int main()
{
	int		a = -4;
	int		b;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	c = 'a';
	int		ret[1000];
	int		count = -1;
	int		fd;

	ret[++count] = PRINT("Simple input test"); //T1
	PRINT("\n");
	ret[++count] = PRINT("%i, %d, %d, %d, %d, %s, %c, %d", i, j, k, l, m, n, c, c); //T2
	PRINT("\n");
	ret[++count] = PRINT("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c); //T3
	PRINT("\n");
	ret[++count] = PRINT("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c); //T4
	PRINT("\n");
	ret[++count] = PRINT("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c); //T5
	PRINT("\n");
	ret[++count] = PRINT("%3i, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c); //T6
	PRINT("\n");
	ret[++count] = PRINT("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c); //T7
	PRINT("\n");
	ret[++count] = PRINT("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c); //T8
	PRINT("\n");
	ret[++count] = PRINT("%6i, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c); //T9
	PRINT("\n");
	ret[++count] = PRINT("%7i, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c); //T10
	PRINT("\n");
	ret[++count] = PRINT("%8i, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c); //T11
	PRINT("\n");
	ret[++count] = PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c); //T12
	PRINT("\n");
	ret[++count] = PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c); //T13
	PRINT("\n");
	ret[++count] = PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c); //T14
	PRINT("\n");
	ret[++count] = PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c); //T15
	PRINT("\n");
	ret[++count] = PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c); //T16
	PRINT("\n");
	ret[++count] = PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c); //T17
	PRINT("\n");
	ret[++count] = PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c); //T18
	PRINT("\n");
	ret[++count] = PRINT("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c); //T19
	PRINT("\n");
	ret[++count] = PRINT("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c); //T20
	PRINT("\n");
	ret[++count] = PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c); //T21
	PRINT("\n");
	ret[++count] = PRINT("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c); //T22
	PRINT("\n");
	ret[++count] = PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c); //T23
	PRINT("\n");
	ret[++count] = PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c); //T24
	PRINT("\n");
	ret[++count] = PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c); //T25
	PRINT("\n");
	ret[++count] = PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c); //T26
	PRINT("\n");
	ret[++count] = PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c); //T27
	PRINT("\n");
	ret[++count] = PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d", i, j, k, l, m, c); //T28
	PRINT("\n");
	ret[++count] = PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c); //T29
	PRINT("\n");
	ret[++count] = PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c); //T30
	PRINT("\n");
	ret[++count] = PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c); //T31
	PRINT("\n");
	ret[++count] = PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c); //T32
	PRINT("\n");
	ret[++count] = PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c); //T33
	PRINT("\n");
	while (a < 5) //T34-69
	{
		ret[++count] = PRINT("%*i, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		ret[++count] = PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		ret[++count] = PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		ret[++count] = PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		a++;
	}
	a = -4;
	while(a < 5) //T70-393
	{
		b = -4;
		while (b < 5)
		{
			ret[++count] = PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			ret[++count] = PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			ret[++count] = PRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			ret[++count] = PRINT("%-0*.*i, %-0*.*d, %-0*.*d, %-0*.*d, %-0*.*d, %-0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			b++;
		}
		a++;
	}

	// ret[++count] = PRINT("%%, \%, %, \t, \\, \", \', \+, +", i);
	// // PRINT("\n");
	// ret[++count] = PRINT("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c);
	// // PRINT("\n");
	// ret[++count] = PRINT("%*.i, %.**d, %88.*d, %*.*d, %.*8d, %.8*d", a, i, a, a, j, a, k, a, l, a, m, a, c);
	// // PRINT("\n");
	// ret[++count] = PRINT("%-00000-----*i, %-.0*d, %---.--*d, %-----.*d, %0000000000.000*d, %...00*d", a, i, a, j, a, k, a, l, a, m, a, c);
	// // PRINT("\n");
	// ret[++count] = PRINT("%.-.-.-.-*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %....*d, %.*.d", a, i, a, j, a, k, a, l, a, m, a, c);
	// // PRINT("\n");
	// ret[++count] = PRINT("%599i, %599d, %599d, %599d, %599d, %599s, %599c, %599d", i, j, k, l, m, n, c, c);
	// PRINT("\n");
	ret[++count] = PRINT("");

	count = -1;
	if (REAL_F == 1)
	{
		if((fd = open("results/expected_return.txt", O_WRONLY)) == -1)
		{
			PRINT("TESTER Error\n\n");
			return (0);
		}
		while (++count < 1000)
		{
			ft_putnbr_fd(ret[count], fd);
			ft_putchar_fd('\n', fd);
		}
		close(fd);
	}
	else
	{
		if((fd = open("results/test_return.txt", O_WRONLY)) == -1)
		{
			PRINT("TESTER Error\n\n");
			return (0);
		}
		while (++count < 1000)
		{
			ft_putnbr_fd(ret[count], fd);
			ft_putchar_fd('\n', fd);
		}
		close(fd);
	}
}