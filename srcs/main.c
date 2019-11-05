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
	int		nb_of_tests = 791;
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
	int		t = 50;
	int		ret[nb_of_tests];
	int		count = -1;
	int		fd;
	

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
	ret[++count] = PRINT("pp %.50d\n", 10000);
	PRINT("\n");
	ret[++count] = PRINT("p1 %.4s\n", "cccc");
	PRINT("\n");
	ret[++count] = PRINT("p2 %.10s\n", "cccc");
	PRINT("\n");
	ret[++count] = PRINT("p3 %.4s\n", NULL);
	PRINT("\n");
	ret[++count] = PRINT("p4 %.5s\n", "aaaaa");
	PRINT("\n");
	ret[++count] = PRINT("p5 %.3d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p6 %.0d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p7 %.4d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p8 %.10d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p9 %.50d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p10 %.1d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p11 %.3d\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p12 %.0d\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("p13 %.3i\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p14 %.0i\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p15 %.4i\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p16 %.10i\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p17 %.50i\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p18 %.1i\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p19 %.3x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p20 %.0x\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("p21 %.3x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p22 %.0x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p23 %.4x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p24 %.10x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p25 %.50x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p26 %.1x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p27 %.3x\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p28 %.0x\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("p29 %.3u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p30 %.0u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p31 %.4u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p32 %.10u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p33 %.50u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p34 %.1u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p35 %.3u\n", 100);
	PRINT("\n");
	ret[++count] = PRINT("p36 %.0u\n", 0);
	PRINT("\n");
	ret[++count] = DPRINT("%%\n");
	PRINT("\n");
	ret[++count] = PRINT("Hello 42 school! %s\n", NULL);
	PRINT("\n");
	ret[++count] = PRINT("%010%\n");
	PRINT("\n");
	ret[++count] = PRINT("%d\n", 2147483647);
	PRINT("\n");
	ret[++count] = PRINT("%x\n", 2147483647);
	PRINT("\n");
	ret[++count] = PRINT("%X\n", 2147483647);
	PRINT("\n");
	ret[++count] = PRINT("%x\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("%010x\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("%010x\n", 20);
	PRINT("\n");
	ret[++count] = PRINT("%010x\n", -20);
	PRINT("\n");
	ret[++count] = PRINT("%10x\n", 20);
	PRINT("\n");
	ret[++count] = PRINT("%10.2x\n", -20);
	PRINT("\n");
	ret[++count] = PRINT("%-10x\n", 50);
	PRINT("\n");
	ret[++count] = PRINT("%-15x\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("%.1x\n", 500);
	PRINT("\n");
	ret[++count] = PRINT("%*.*x\n", 50, 10, 2);
	PRINT("\n");
	ret[++count] = PRINT("%x\n", -1);
	PRINT("\n");
	ret[++count] = PRINT("%40.50d\n", 50);
    PRINT("\n");
	ret[++count] = PRINT("%d\n", -589);
    PRINT("\n");
	ret[++count] = PRINT("%-4d\n", -2464);
    PRINT("\n");
	ret[++count] = PRINT("%.5d\n", -2372);
	PRINT("\n");
	ret[++count] = PRINT("%p\n", NULL);
	PRINT("\n");
	ret[++count] = PRINT("%15p\n", NULL);
	PRINT("\n");
	ret[++count] = PRINT("%-15p\n", NULL);
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%010d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%10d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%.5d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%01.1d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%010.1d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%01.50d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%1.50d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%0100.50d]\n", -8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%010d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%10d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%.5d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%01.1d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%010.1d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%01.50d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%1.50d]\n", 8473));
    PRINT("\n");
	ret[++count] = PRINT("ret = %d\n", PRINT("%%p::[%0100.50d]\n", 8473));
	PRINT("\n");
	ret[++count] = PRINT("%c\n", 'a');
	PRINT("\n");
	ret[++count] = PRINT("%10c\n", 't');
	PRINT("\n");
	ret[++count] = PRINT("%1c\n", 'y');
	PRINT("\n");
	ret[++count] = PRINT("%50.2s\n", "Coucou");
	PRINT("\n");
	ret[++count] = PRINT("%50.2s\n", NULL);
	PRINT("\n");
	ret[++count] = PRINT("%5.0s\n", "Hello");
	PRINT("\n");
	ret[++count] = PRINT("%.1s\n", "Test");
	PRINT("\n");
	ret[++count] = PRINT("%10s\n", NULL);
	PRINT("\n");
	ret[++count] = PRINT("%10s\n", "Ok");
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("1chiffre 1 %d chiffre 2 %d\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4chiffre 1 %-12d chiffre 2 %-12d\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("t1 %050d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t2 %-50d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t3 %50.0d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t4 %50.50d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t5 %50.10d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t6 %*.*d\n", 50,  5, 10);
	PRINT("\n");
	ret[++count] = PRINT("t7 %1.50d\n", -10);
	PRINT("\n");
	ret[++count] = PRINT("t8 %1.50d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t9 %2.2d\n", 10);
	PRINT("\n");
	ret[++count] = PRINT("t10 %2.2d\n", -10);
	PRINT("\n");
	ret[++count] = PRINT("t12 %.0d\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("t13 %01d\n", -20);
	PRINT("\n");
	ret[++count] = PRINT("t14 %10d\n", 1000);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("5chiffre 1 %0d chiffre 2 %0d\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("6chiffre 1 %012d chiffre 2 %012d\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("8chiffre 1 %*d chiffre 2 %*d\n", 42, 6, 6, 6));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("15chiffre 1 %.d chiffre 2 %.d\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4caractere 1 %12c caractere 2 %12c\n", 'a', 'c'));
	PRINT("\n");
	ret[++count] = PRINT("1caractere 1 %c caractere 2 %c\n", 'a', 'c');
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("1hexa-maj 1 %X hexa-maj 2 %X\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4hexa-maj 1 %12X hexa-maj 2 %int12X\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4hexa-maj 1 %-12X hexa-maj 2 %-12X\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("5hexa-maj 1 %0X hexa-maj 2 %0X\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("6hexa-maj 1 %012X hexa-maj 2 %012X\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("8hexa-maj 1 %*X hexa-maj 2 %*X\n", 42, 6, 6, 6));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("1unsigned 1 %u unsigned 2 %u\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4unsigned 1 %12u unsigned 2 %12u\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4unsigned 1 %-12u unsigned 2 %-12u\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("5unsigned 1 %0u unsigned 2 %0u\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("6unsigned 1 %012u unsigned 2 %012u\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("8unsigned 1 %*u unsigned 2 %*u\n", 42, 6, 6, 6));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("15unsigned 1 %.u unsigned 2 %.u\n", 42, -42));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("%%\n")); 
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("%-.12u\n", -20000000));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("%-.12i\n", -20000000));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("truc\n"));
	PRINT("\n");
	ret[++count] = PRINT("04 Test de chiffre sans h : %d, et %d\n", 432767, -432767);
	PRINT("\n");
	ret[++count] = PRINT("31 This is an int : %.0d\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("32 This is an int : %0d\n", 0);
	PRINT("\n");
	ret[++count] = PRINT("percent 1 %012%\n");
	PRINT("\n");
	ret[++count] = PRINT("percent 2 %12%\n");
	PRINT("\n");
	ret[++count] = PRINT("percent 3 %-12%\n");
	PRINT("\n");
	ret[++count] = PRINT("percent 4 %0%\n");
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", t);
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("1string 1 %s string 2 %s\n", "toto", "bonjour"));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4string 1 %12s string 2 %12s\n", "toto", "bonjour"));
	PRINT("\n");
	ret[++count] = PRINT("%d\n", PRINT("4string 1 %-12s string 2 %-12s\n", "toto", "bonjour"));
	PRINT("\n");
	ret[++count] = PRINT("st1 %*.*d\n", 10, 10, 50);
	PRINT("\n");
	ret[++count] = PRINT("st2 %*.*d\n", 1, 50, 50);
	PRINT("\n");
	ret[++count] = PRINT("st3 %*.*d\n", 0, 0, 50);
	PRINT("\n");
	ret[++count] = PRINT("st4 %*.*d\n", 0, 50, 50);
	PRINT("\n");
	ret[++count] = PRINT("st5 %*.*d\n", 10, 0, 50);
	PRINT("\n");
	ret[++count] = PRINT("st6 %*.*d\n", 10, 10, 50);
	PRINT("\n");
	ret[++count] = PRINT("st12 %*d\n", 10, 50);
	PRINT("\n");
	ret[++count] = PRINT("st13 %*d\n", 0, 0);
	PRINT("\n");
	ret[++count] = PRINT("st14 %.*d\n", 0, 0);
	PRINT("\n");
	ret[++count] = PRINT("st15 %*d\n", 50, 5);
	PRINT("\n");
	ret[++count] = PRINT("st16 %0.*d\n", 50, 5);
	PRINT("\n");
	ret[++count] = PRINT("st17 %0.*d\n", 0, 0);
	PRINT("\n");
	ret[++count] = PRINT("st7 %*.*s\n", 1, 50, "hey");
	PRINT("\n");
	ret[++count] = PRINT("st8 %*.*s\n", 0, 0, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("st9 %*.*s\n", 0, 50, "hey");
	PRINT("\n");
	ret[++count] = PRINT("st10 %*.*s\n", 10, 0, "dsa");
	PRINT("\n");
	ret[++count] = PRINT("st11 %*.*s\n", 10, 10, "hello");
	PRINT("\n");
	ret[++count] = PRINT("st8 %.*s\n", 0, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("st9 %*s\n", 0, "hey");
	PRINT("\n");
	ret[++count] = PRINT("st10 %*s\n", 10, "dsa");
	PRINT("\n");
	ret[++count] = PRINT("st118 %*s\n", 100, "hello");
	PRINT("\n");
	ret[++count] = PRINT("st119 %*s\n", 1000, "hello");
	PRINT("\n");
	ret[++count] = PRINT("st120 %*s\n", 10000, "hello");
	PRINT("\n");
	ret[++count] = PRINT("st121 %*s\n", 100000, "hello");
	PRINT("\n");
	ret[++count] = PRINT("st118 %*d\n", 100, 0);
	PRINT("\n");
	ret[++count] = PRINT("st119 %*d\n", 1000, 10);
	PRINT("\n");
	ret[++count] = PRINT("st120 %*d\n", 10000, 467);
	PRINT("\n");
	ret[++count] = PRINT("st121 %*d\n", 100000, -589);
	PRINT("\n");
	ret[++count] = PRINT("ultimate1 %*d        %*i\n", 500, 0, 10, 10);
	PRINT("\n");
	ret[++count] = PRINT("ultimate2 %*d %*s %*x %*X %*i %*u\n", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60);
	PRINT("\n");
	ret[++count] = PRINT("ultimate3 %*.*d %*.*s\n", 1, 50, 5000, 1, 0, "hey");
	PRINT("\n");
	ret[++count] = PRINT("ultimate4 %*.*x %*.*X\n", 1, 50, 5000, 1, 0, 10);
	PRINT("\n");
	ret[++count] = PRINT("ultimate5 %*.*u\n", 1, 50, 5000);
	PRINT("\n");
	ret[++count] = PRINT("neg1 %*s\n", -9, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg2 %*.*s\n", -9, 4, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg3 %*s\n", -9, NULL);
	PRINT("\n");
	ret[++count] = PRINT("neg4 %*.*s\n", 0, 0, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg5 %*s\n", -100, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg6 %*s\n", -156, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg7 %*.*s\n", -1586, 15, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg8 %*.*s\n", -1586, 15, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg9 %*.*s\n", 15856, 155, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg10 %*.*s\n", -15586, 15, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg11 %*.*s\n", -15586, 15, "coucou");
	PRINT("\n");
	ret[++count] = PRINT("neg1 %*d\n", -9, 150);
	PRINT("\n");
	ret[++count] = PRINT("neg2 %*.*d\n", -9, 4, 1555);
	PRINT("\n");
	ret[++count] = PRINT("neg3 %*d\n", -9, -255);
	PRINT("\n");
	ret[++count] = PRINT("neg4 %*.*d\n", 0, 0, -30);
	PRINT("\n");
	ret[++count] = PRINT("neg5 %*d\n", -100, -589);
	PRINT("\n");
	ret[++count] = PRINT("neg6 %*d\n", -156, 15555);
	PRINT("\n");
	ret[++count] = PRINT("neg7 %*.*d\n", -1586, 15, 0);
	PRINT("\n");
	ret[++count] = PRINT("neg8 %*.*d\n", -1586, 15, 300);
	PRINT("\n");
	ret[++count] = PRINT("neg9 %*.*d\n", 15856, 155, -3000);
	PRINT("\n");
	ret[++count] = PRINT("neg10 %*.*d\n", -15586, 15, 150);
	PRINT("\n");
	ret[++count] = PRINT("neg11 %*.*d\n", -15586, 15, 0);
	PRINT("\n");
	ret[++count] = PRINT("***************%*s%*d**************%*u*************\n", 10, "coucou", 10, 10, -50, 20);
	PRINT("\n");
	ret[++count] = PRINT("taaa %100s\n", "hello");
	PRINT("\n");
	ret[++count] = PRINT("");

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