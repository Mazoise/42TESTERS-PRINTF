#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

#define APRINT(x, a, ...) PRINT(x, a, __VA_ARGS__) ; PRINT("  --- Test : \"%s...\" / * = %d", ft_substr(x, 0, 11), a)
#define BPRINT(x, ...) PRINT(x, __VA_ARGS__) ; PRINT("  --- Test : \"%s...\"", ft_substr(x, 0, 11))
#define CPRINT(x, a, b, ...) PRINT(x, a, b, __VA_ARGS__) ; PRINT("  --- Test : \"%s...\" / *1 = %d / *2 = %d", ft_substr(x, 0, 11), a, b) 
#define DPRINT(x) PRINT(x) ; PRINT("  --- Test : simple input : \"%s\"", x)

int main()
{
	int		a = -4;
	int		b;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	int		ret[1000];
	int		count = -1;
	int		fd;
	int		nb_of_tests = 350;

	ret[++count] = DPRINT("Simple input test"); //T1
	PRINT("\n");
	ret[++count] = BPRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j); //T2
	PRINT("\n");
	ret[++count] = BPRINT("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c); //T3
	PRINT("\n");
	ret[++count] = BPRINT("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c); //T4
	PRINT("\n");
	ret[++count] = BPRINT("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c); //T5
	PRINT("\n");
	ret[++count] = BPRINT("%3i, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c); //T6
	PRINT("\n");
	ret[++count] = BPRINT("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c); //T7
	PRINT("\n");
	ret[++count] = BPRINT("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c); //T8
	PRINT("\n");
	ret[++count] = BPRINT("%6i, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c); //T9
	PRINT("\n");
	ret[++count] = BPRINT("%7i, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c); //T10
	PRINT("\n");
	ret[++count] = BPRINT("%8i, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c); //T11
	PRINT("\n");
	ret[++count] = BPRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c); //T12
	PRINT("\n");
	ret[++count] = BPRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c); //T13
	PRINT("\n");
	ret[++count] = BPRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c); //T14
	PRINT("\n");
	ret[++count] = BPRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c); //T15
	PRINT("\n");
	ret[++count] = BPRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c); //T16
	PRINT("\n");
	ret[++count] = BPRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c); //T17
	PRINT("\n");
	ret[++count] = BPRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c); //T18
	PRINT("\n");
	ret[++count] = BPRINT("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c); //T19
	PRINT("\n");
	ret[++count] = BPRINT("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c); //T20
	PRINT("\n");
	ret[++count] = BPRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c); //T21
	PRINT("\n");
	ret[++count] = BPRINT("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c); //T22
	PRINT("\n");
	ret[++count] = BPRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c); //T23
	PRINT("\n");
	ret[++count] = BPRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c); //T24
	PRINT("\n");
	ret[++count] = BPRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c); //T25
	PRINT("\n");
	ret[++count] = BPRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c); //T26
	PRINT("\n");
	ret[++count] = BPRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c); //T27
	PRINT("\n");
	ret[++count] = BPRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d", i, j, k, l, m, c); //T28
	PRINT("\n");
	ret[++count] = BPRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c); //T29
	PRINT("\n");
	ret[++count] = BPRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c); //T30
	PRINT("\n");
	ret[++count] = BPRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c); //T31
	PRINT("\n");
	ret[++count] = BPRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c); //T32
	PRINT("\n");
	ret[++count] = BPRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c); //T33
	PRINT("\n");
	while (a < 5) //T34-69
	{
		ret[++count] = APRINT("%*i, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		ret[++count] = APRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		ret[++count] = APRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		ret[++count] = APRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c);
		PRINT("\n");
		a++;
	}
	a = -1;
	while(a < 5) //T70-393
	{
		b = -1;
		while (b < 5)
		{
			ret[++count] = CPRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			ret[++count] = CPRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			ret[++count] = CPRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c);
			PRINT("\n");
			b++;
		}
		a++;
	}
	ret[++count] = BPRINT("%*.*i, %*.*d", 9, 4, -42, 9, 4, 42); //T394
	PRINT("\n");
	ret[++count] = BPRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r); //T395
	PRINT("\n");
	ret[++count] = BPRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r); //T396
	PRINT("\n");
	ret[++count] = BPRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r); //T397
	PRINT("\n");
	ret[++count] = BPRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r); //T398
	PRINT("\n");
	ret[++count] = BPRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r); //T399
	PRINT("\n");
	ret[++count] = BPRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r); //T400
	PRINT("\n");
	ret[++count] = BPRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r);; //T401
	PRINT("\n");
	a = -4;
	while (a < 5) //T402-419
	{
		ret[++count] = APRINT("%*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r);
		PRINT("\n");
		ret[++count] = APRINT("%-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r);
		PRINT("\n");
		a++;
	}
	ret[++count] = BPRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e); //T403
	PRINT("\n");
	a = -1;
	while (a < 5) //T34-69
	{
		ret[++count] = APRINT("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		PRINT("\n");
		ret[++count] = APRINT("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		PRINT("\n");
		ret[++count] = APRINT("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		PRINT("\n");
		ret[++count] = APRINT("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
		PRINT("\n");
		a++;
	}
	a = -1;
	while(a < 5) //T70-393
	{
		b = -1;
		while (b < 5)
		{
			ret[++count] = CPRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			PRINT("\n");
			ret[++count] = CPRINT("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			PRINT("\n");
			ret[++count] = CPRINT("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e);
			PRINT("\n");
			b++;
		}
		a++;
	}
	ret[++count] = BPRINT("%p, %x, %p, %x, %p, %x", 209590960, 209590960, 207038912, 207038912, 1, 1); //T2
	PRINT("\n");
	a = 8;
	while (a < 12)
	{
		ret[++count] = APRINT("%*p, %*x, %*p, %*x, %*p, %*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1); //T2
		PRINT("\n");
		ret[++count] = APRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1); //T2
		PRINT("\n");
//		ret[++count] = APRINT("%0*p, %0*x, %0*p, %0*x, %0*p, %0*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1); //T2
//		PRINT("\n");
		a++;
	}
	ret[++count] = DPRINT("%%, \t, \\, \", \', +");
	PRINT("\n");
	// ret[++count] = CPRINT("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c);
	// // PRINT("\n");
	// ret[++count] = CPRINT("%*.i, %.**d, %88.*d, %*.*d, %.*8d, %.8*d", a, i, a, a, j, a, k, a, l, a, m, a, c);
	// // PRINT("\n");
	ret[++count] = APRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i);
	PRINT("\n");
	ret[++count] = APRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j);
	PRINT("\n");
	ret[++count] = APRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l);
	PRINT("\n");
	// ret[++count] = CPRINT("%599i, %599d, %599d, %599d, %599d, %599s, %599c, %599d", i, j, k, l, m, n, c, c);
	// PRINT("\n");
	ret[++count] = DPRINT("");

	count = -1;
	if (REAL_F == 1)
	{
		if((fd = open("results/expected_return.txt", O_WRONLY)) == -1)
		{
			PRINT("TESTER Error\n\n");
			return (0);
		}
		while (++count < nb_of_tests)
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
		while (++count < nb_of_tests)
		{
			ft_putnbr_fd(ret[count], fd);
			ft_putchar_fd('\n', fd);
		}
		close(fd);
	}
}