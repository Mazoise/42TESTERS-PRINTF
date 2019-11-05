#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_printf.h"

// #define PRINT(x, a, ...) PRINT(x, a, __VA_ARGS__) ; PRINT("  --- Test : \"%s...\" / * = %d", ft_substr(x, 0, 11), a)
// #define PRINT(x, ...) PRINT(x, __VA_ARGS__) ; PRINT("  --- Test : \"%s...\"", ft_substr(x, 0, 11))
// #define PRINT(x, a, b, ...) PRINT(x, a, b, __VA_ARGS__) ; PRINT("  --- Test : \"%s...\" / *1 = %d / *2 = %d", ft_substr(x, 0, 11), a, b) 
// #define PRINT(x) PRINT(x) ; PRINT("  --- Test : simple input : \"%s\"", x)

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
	int		t = 50;

	PRINT(" --- Return : %d\n", PRINT("Simple input test"));
	PRINT(" --- Return : %d\n", PRINT("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X", i, j, k, l, m, n, c, c, j, j, j)); //T2
	PRINT(" --- Return : %d\n", PRINT("%0i, %0d, %0d, %0d, %0d, %0d", i, j, k, l, m, c)); //T3
	PRINT(" --- Return : %d\n", PRINT("%1i, %1d, %1d, %1d, %1d, %1d", i, j, k, l, m, c)); //T4
	PRINT(" --- Return : %d\n", PRINT("%2i, %2d, %2d, %2d, %2d, %2d", i, j, k, l, m, c)); //T5
	PRINT(" --- Return : %d\n", PRINT("%3i, %3d, %3d, %3d, %3d, %3d", i, j, k, l, m, c)); //T6
	PRINT(" --- Return : %d\n", PRINT("%4i, %4d, %4d, %4d, %4d, %4d", i, j, k, l, m, c)); //T7
	PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c)); //T8
	PRINT(" --- Return : %d\n", PRINT("%6i, %6d, %6d, %6d, %6d, %6d", i, j, k, l, m, c)); //T9
	PRINT(" --- Return : %d\n", PRINT("%7i, %7d, %7d, %7d, %7d, %7d", i, j, k, l, m, c)); //T10
	PRINT(" --- Return : %d\n", PRINT("%8i, %8d, %8d, %8d, %8d, %8d", i, j, k, l, m, c)); //T11
	PRINT(" --- Return : %d\n", PRINT("%0.i, %0.d, %0.d, %0.d, %0.d, %0.d", i, j, k, l, m, c)); //T12
	PRINT(" --- Return : %d\n", PRINT("%.0i, %.0d, %.0d, %.0d, %.0d, %.0d", i, j, k, l, m, c)); //T13
	PRINT(" --- Return : %d\n", PRINT("%0.0i, %0.0d, %0.0d, %0.0d, %0.0d, %0.0d", i, j, k, l, m, c)); //T14
	PRINT(" --- Return : %d\n", PRINT("%-0i, %-0d, %-0d, %-0d, %-0d, %-0d", i, j, k, l, m, c)); //T15
	PRINT(" --- Return : %d\n", PRINT("%0-i, %0-d, %0-d, %0-d, %0-d, %0-d", i, j, k, l, m, c)); //T16
	PRINT(" --- Return : %d\n", PRINT("%-.i, %-.d, %-.d, %-.d, %-.d, %-.d", i, j, k, l, m, c)); //T17
	PRINT(" --- Return : %d\n", PRINT("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c)); //T18
	PRINT(" --- Return : %d\n", PRINT("%-i, %-d, %-d, %-d, %-d, %-d", i, j, k, l, m, c)); //T19
	PRINT(" --- Return : %d\n", PRINT("%.i, %.d, %.d, %.d, %.d, %.d", i, j, k, l, m, c)); //T20
	PRINT(" --- Return : %d\n", PRINT("%-0.0i, %-0.0d, %-0.0d, %-0.0d, %-0.0d, %-0.0d", i, j, k, l, m, c)); //T21
	PRINT(" --- Return : %d\n", PRINT("%00i, %00d, %00d, %00d, %00d, %00d", i, j, k, l, m, c)); //T22
	PRINT(" --- Return : %d\n", PRINT("%1.i, %1.d, %1.d, %1.d, %1.d, %1.d", i, j, k, l, m, c)); //T23
	PRINT(" --- Return : %d\n", PRINT("%.1i, %.1d, %.1d, %.1d, %.1d, %.1d", i, j, k, l, m, c)); //T24
	PRINT(" --- Return : %d\n", PRINT("%1.1i, %1.1d, %1.1d, %1.1d, %1.1d, %1.1d", i, j, k, l, m, c)); //T25
	PRINT(" --- Return : %d\n", PRINT("%-1i, %-1d, %-1d, %-1d, %-1d, %-1d", i, j, k, l, m, c)); //T26
	PRINT(" --- Return : %d\n", PRINT("%-01i, %-01d, %-01d, %-01d, %-01d, %-01d", i, j, k, l, m, c)); //T27
	PRINT(" --- Return : %d\n", PRINT("%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d", i, j, k, l, m, c)); //T28
	PRINT(" --- Return : %d\n", PRINT("%-.1i, %-.1d, %-.1d, %-.1d, %-.1d, %-.1d", i, j, k, l, m, c)); //T29
	PRINT(" --- Return : %d\n", PRINT("%-0.1i, %-0.1d, %-0.1d, %-0.1d, %-0.1d, %-0.1d", i, j, k, l, m, c)); //T30
	PRINT(" --- Return : %d\n", PRINT("%-1.0i, %-1.0d, %-1.0d, %-1.0d, %-1.0d, %-1.0d", i, j, k, l, m, c)); //T31
	PRINT(" --- Return : %d\n", PRINT("%-1.1i, %-1.1d, %-1.1d, %-1.1d, %-1.1d, %-1.1d", i, j, k, l, m, c)); //T32
	PRINT(" --- Return : %d\n", PRINT("%1.0i, %1.0d, %1.0d, %1.0d, %1.0d, %1.0d", i, j, k, l, m, c)); //T33
	while (a < 5) //T34-69
	{
		PRINT(" --- Return : %d\n", PRINT("%*i, %*d, %*d, %*d, %*d, %*d", a, i, a, j, a, k, a, l, a, m, a, c));
		PRINT(" --- Return : %d\n", PRINT("%0*i, %0*d, %0*d, %0*d, %0*d, %0*d", a, i, a, j, a, k, a, l, a, m, a, c));
		PRINT(" --- Return : %d\n", PRINT("%-*i, %-*d, %-*d, %-*d, %-*d, %-*d", a, i, a, j, a, k, a, l, a, m, a, c));
		PRINT(" --- Return : %d\n", PRINT("%.*i, %.*d, %.*d, %.*d, %.*d, %.*d", a, i, a, j, a, k, a, l, a, m, a, c));
		a++;
	}
	a = -1;
	while(a < 5) //T70-393
	{
		b = -1;
		while (b < 5)
		{
			PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d, %*.*d, %*.*d, %*.*d, %*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			PRINT(" --- Return : %d\n", PRINT("%-*.*i, %-*.*d, %-*.*d, %-*.*d, %-*.*d, %-*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			PRINT(" --- Return : %d\n", PRINT("%0*.*i, %0*.*d, %0*.*d, %0*.*d, %0*.*d, %0*.*d", a, b, i, a, b, j, a, b, k, a, b, l, a, b, m, a, b, c));
			b++;
		}
		a++;
	}
	PRINT(" --- Return : %d\n", PRINT("%*.*i, %*.*d", 9, 4, -42, 9, 4, 42)); //T394
	PRINT(" --- Return : %d\n", PRINT("%12.12i, %12.12d", -42, 42)); //T394
	PRINT(" --- Return : %d\n", PRINT("%1s, %1s, %1s, %1s, %1s", n, o, p, q, r)); //T395
	PRINT(" --- Return : %d\n", PRINT("%2s, %2s, %2s, %2s, %2s", n, o, p, q, r)); //T396
	PRINT(" --- Return : %d\n", PRINT("%3s, %3s, %3s, %3s, %3s", n, o, p, q, r)); //T397
	PRINT(" --- Return : %d\n", PRINT("%4s, %4s, %4s, %4s, %4s", n, o, p, q, r)); //T398
	PRINT(" --- Return : %d\n", PRINT("%15s, %15s, %15s, %15s, %15s", n, o, p, q, r)); //T399
	PRINT(" --- Return : %d\n", PRINT("%16s, %16s, %16s, %16s, %16s", n, o, p, q, r)); //T400
	PRINT(" --- Return : %d\n", PRINT("%17s, %17s, %17s, %17s, %17s", n, o, p, q, r));; //T401
	a = -4;
	while (a < 5) //T402-419
	{
		PRINT(" --- Return : %d\n", PRINT("%*s, %*s, %*s, %*s, %*s", a, n, a, o, a, p, a, q, a, r));
		PRINT(" --- Return : %d\n", PRINT("%-*s, %-*s, %-*s, %-*s, %-*s", a, n, a, o, a, p, a, q, a, r));
		PRINT(" --- Return : %d\n", PRINT("%0*s, %0*s, %0*s, %0*s, %0*s", a, n, a, o, a, p, a, q, a, r));
		a++;
	}
	PRINT(" --- Return : %d\n", PRINT("%u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X, %u, %x, %X", i, i, i, j, j, j, k, k, k, l, l, l, m, m, m, c, c, c, d, d, d, e, e, e)); //T403
	a = -1;
	while (a < 5) //T34-69
	{
		PRINT(" --- Return : %d\n", PRINT("%*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X, %*u, %*x, %*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		PRINT(" --- Return : %d\n", PRINT("%0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		PRINT(" --- Return : %d\n", PRINT("%-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X, %-*u, %-*x, %-*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		PRINT(" --- Return : %d\n", PRINT("%.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X, %.*u, %.*x, %.*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e));
		a++;
	}
	a = -1;
	while(a < 5) //T70-393
	{
		b = -1;
		while (b < 5)
		{
			PRINT(" --- Return : %d\n", PRINT("%*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X, %*.*u, %*.*x, %*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			PRINT(" --- Return : %d\n", PRINT("%0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X, %0*.*u, %0*.*x, %0*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			PRINT(" --- Return : %d\n", PRINT("%-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X, %-*.*u, %-*.*x, %-*.*X", a, b, i, a, b, i, a, b, i, a, b, j, a, b, j, a, b, j, a, b, k, a, b, k, a, b, k, a, b, l, a, b, l, a, b, l, a, b, m, a, b, m, a, b, m, a, b, c, a, b, c, a, b, c, a, b, d, a, b, d, a, b, d, a, b, e, a, b, e, a, b, e));
			b++;
		}
		a++;
	}
	PRINT(" --- Return : %d\n", PRINT("%p, %x, %p, %x, %p, %x", 209590960, 209590960, 207038912, 207038912, 1, 1)); //T2
	a = 8;
	while (a < 12)
	{
		PRINT(" --- Return : %d\n", PRINT("%*p, %*x, %*p, %*x, %*p, %*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1)); //T2
		PRINT(" --- Return : %d\n", PRINT("%-*p, %-*x, %-*p, %-*x, %-*p, %-*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1)); //T2
//		PRINT(" --- Return : %d\n", PRINT("%0*p, %0*x, %0*p, %0*x, %0*p, %0*x", a, 209590960, a, 209590960, a, 207038912, a, 207038912, a, 1, a, 1)); //T2
		a++;
	}
	PRINT(" --- Return : %d\n", PRINT("%%, \t, \\, \", \', +"));
	// PRINT(" --- Return : %d\n", PRINT("%5i, %5d, %5d, %5d, %5d, %5d", i, j, k, l, m, c));
	// PRINT(" --- Return : %d\n", PRINT("%*.i, %.**d, %88.*d, %*.*d, %.*8d, %.8*d", a, i, a, a, j, a, k, a, l, a, m, a, c));
	PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, i, a, i, a, i, a, i, a, i));
	PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, j, a, j, a, j, a, j, a, j));
	PRINT(" --- Return : %d\n", PRINT("%-00000-----*i, %---0.*d, %0-0-0-0-0.*d, %-0-0-0-0-.*d, %-----.*d", a, l, a, l, a, l, a, l, a, l));
	// PRINT(" --- Return : %d\n", PRINT("%599i, %599d, %599d, %599d, %599d, %599s, %599c, %599d", i, j, k, l, m, n, c, c));
	// PRINT(""));
	PRINT(" --- Return : %d\n", PRINT("pp %.50d", 10000));
	PRINT(" --- Return : %d\n", PRINT("p1 %.4s", "cccc"));
	PRINT(" --- Return : %d\n", PRINT("p2 %.10s", "cccc"));
	PRINT(" --- Return : %d\n", PRINT("p3 %.4s", NULL));
	PRINT(" --- Return : %d\n", PRINT("p4 %.5s", "aaaaa"));
	PRINT(" --- Return : %d\n", PRINT("p5 %.3d", 100));
	PRINT(" --- Return : %d\n", PRINT("p6 %.0d", 100));
	PRINT(" --- Return : %d\n", PRINT("p7 %.4d", 100));
	PRINT(" --- Return : %d\n", PRINT("p8 %.10d", 100));
	PRINT(" --- Return : %d\n", PRINT("p9 %.50d", 100));
	PRINT(" --- Return : %d\n", PRINT("p10 %.1d", 100));
	PRINT(" --- Return : %d\n", PRINT("p11 %.3d", 100));
	PRINT(" --- Return : %d\n", PRINT("p12 %.0d", 0));
	PRINT(" --- Return : %d\n", PRINT("p13 %.3i", 100));
	PRINT(" --- Return : %d\n", PRINT("p14 %.0i", 100));
	PRINT(" --- Return : %d\n", PRINT("p15 %.4i", 100));
	PRINT(" --- Return : %d\n", PRINT("p16 %.10i", 100));
	PRINT(" --- Return : %d\n", PRINT("p17 %.50i", 100));
	PRINT(" --- Return : %d\n", PRINT("p18 %.1i", 100));
	PRINT(" --- Return : %d\n", PRINT("p19 %.3x", 100));
	PRINT(" --- Return : %d\n", PRINT("p20 %.0x", 0));
	PRINT(" --- Return : %d\n", PRINT("p21 %.3x", 100));
	PRINT(" --- Return : %d\n", PRINT("p22 %.0x", 100));
	PRINT(" --- Return : %d\n", PRINT("p23 %.4x", 100));
	PRINT(" --- Return : %d\n", PRINT("p24 %.10x", 100));
	PRINT(" --- Return : %d\n", PRINT("p25 %.50x", 100));
	PRINT(" --- Return : %d\n", PRINT("p26 %.1x", 100));
	PRINT(" --- Return : %d\n", PRINT("p27 %.3x", 100));
	PRINT(" --- Return : %d\n", PRINT("p28 %.0x", 0));
	PRINT(" --- Return : %d\n", PRINT("p29 %.3u", 100));
	PRINT(" --- Return : %d\n", PRINT("p30 %.0u", 100));
	PRINT(" --- Return : %d\n", PRINT("p31 %.4u", 100));
	PRINT(" --- Return : %d\n", PRINT("p32 %.10u", 100));
	PRINT(" --- Return : %d\n", PRINT("p33 %.50u", 100));
	PRINT(" --- Return : %d\n", PRINT("p34 %.1u", 100));
	PRINT(" --- Return : %d\n", PRINT("p35 %.3u", 100));
	PRINT(" --- Return : %d\n", PRINT("p36 %.0u", 0));
	PRINT(" --- Return : %d\n", PRINT("%%"));
	PRINT(" --- Return : %d\n", PRINT("Hello 42 school! %s", NULL));
	PRINT(" --- Return : %d\n", PRINT("%010%"));
	PRINT(" --- Return : %d\n", PRINT("%d", 2147483647));
	PRINT(" --- Return : %d\n", PRINT("%x", 2147483647));
	PRINT(" --- Return : %d\n", PRINT("%X", 2147483647));
	PRINT(" --- Return : %d\n", PRINT("%x", 0));
	PRINT(" --- Return : %d\n", PRINT("%010x", 0));
	PRINT(" --- Return : %d\n", PRINT("%010x", 20));
	PRINT(" --- Return : %d\n", PRINT("%010x", -20));
	PRINT(" --- Return : %d\n", PRINT("%10x", 20));
	PRINT(" --- Return : %d\n", PRINT("%10.2x", -20));
	PRINT(" --- Return : %d\n", PRINT("%-10x", 50));
	PRINT(" --- Return : %d\n", PRINT("%-15x", 0));
	PRINT(" --- Return : %d\n", PRINT("%.1x", 500));
	PRINT(" --- Return : %d\n", PRINT("%*.*x", 50, 10, 2));
	PRINT(" --- Return : %d\n", PRINT("%x", -1));
	PRINT(" --- Return : %d\n", PRINT("%40.50d", 50));
	PRINT(" --- Return : %d\n", PRINT("%d", -589));
	PRINT(" --- Return : %d\n", PRINT("%-4d", -2464));
	PRINT(" --- Return : %d\n", PRINT("%.5d", -2372));
	PRINT(" --- Return : %d\n", PRINT("%p", NULL));
	PRINT(" --- Return : %d\n", PRINT("%15p", NULL));
	PRINT(" --- Return : %d\n", PRINT("%-15p", NULL));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%010d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%10d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%.5d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%01.1d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%010.1d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%01.50d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%1.50d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%0100.50d]", 8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%010d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%10d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%.5d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%01.1d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%010.1d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%01.50d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%1.50d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%%p::[%0100.50d]", -8473));
	PRINT(" --- Return : %d\n", PRINT("%c", 'a'));
	PRINT(" --- Return : %d\n", PRINT("%10c", 't'));
	PRINT(" --- Return : %d\n", PRINT("%1c", 'y'));
	PRINT(" --- Return : %d\n", PRINT("%50.2s", "Coucou"));
	PRINT(" --- Return : %d\n", PRINT("%50.2s", NULL));
	PRINT(" --- Return : %d\n", PRINT("%5.0s", "Hello"));
	PRINT(" --- Return : %d\n", PRINT("%.1s", "Test"));
	PRINT(" --- Return : %d\n", PRINT("%10s", NULL));
	PRINT(" --- Return : %d\n", PRINT("%10s", "Ok"));
	PRINT(" --- Return : %d\n", PRINT("1chiffre 1 %d chiffre 2 %d", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("4chiffre 1 %-12d chiffre 2 %-12d", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("t1 %050d", 10));
	PRINT(" --- Return : %d\n", PRINT("t2 %-50d", 10));
	PRINT(" --- Return : %d\n", PRINT("t3 %50.0d", 10));
	PRINT(" --- Return : %d\n", PRINT("t4 %50.50d", 10));
	PRINT(" --- Return : %d\n", PRINT("t5 %50.10d", 10));
	PRINT(" --- Return : %d\n", PRINT("t6 %*.*d", 50,  5, 10));
	PRINT(" --- Return : %d\n", PRINT("t7 %1.50d", -10));
	PRINT(" --- Return : %d\n", PRINT("t8 %1.50d", 10));
	PRINT(" --- Return : %d\n", PRINT("t9 %2.2d", 10));
	PRINT(" --- Return : %d\n", PRINT("t10 %2.2d", -10));
	PRINT(" --- Return : %d\n", PRINT("t12 %.0d", 0));
	PRINT(" --- Return : %d\n", PRINT("t13 %01d", -20));
	PRINT(" --- Return : %d\n", PRINT("t14 %10d", 1000));
	PRINT(" --- Return : %d\n", PRINT("5chiffre 1 %0d chiffre 2 %0d", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("6chiffre 1 %012d chiffre 2 %012d", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("8chiffre 1 %*d chiffre 2 %*d", 42, 6, 6, 6));
	PRINT(" --- Return : %d\n", PRINT("15chiffre 1 %.d chiffre 2 %.d", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("4caractere 1 %12c caractere 2 %12c", 'a', 'c'));
	PRINT(" --- Return : %d\n", PRINT("1caractere 1 %c caractere 2 %c", 'a', 'c'));
	PRINT(" --- Return : %d\n", PRINT("1hexa-maj 1 %X hexa-maj 2 %X", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("4hexa-maj 1 %12X hexa-maj 2 %int12X", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("4hexa-maj 1 %-12X hexa-maj 2 %-12X", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("5hexa-maj 1 %0X hexa-maj 2 %0X", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("6hexa-maj 1 %012X hexa-maj 2 %012X", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("8hexa-maj 1 %*X hexa-maj 2 %*X", 42, 6, 6, 6));
	PRINT(" --- Return : %d\n", PRINT("1unsigned 1 %u unsigned 2 %u", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("4unsigned 1 %12u unsigned 2 %12u", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("4unsigned 1 %-12u unsigned 2 %-12u", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("5unsigned 1 %0u unsigned 2 %0u", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("6unsigned 1 %012u unsigned 2 %012u", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("8unsigned 1 %*u unsigned 2 %*u", 42, 6, 6, 6));
	PRINT(" --- Return : %d\n", PRINT("15unsigned 1 %.u unsigned 2 %.u", 42, -42));
	PRINT(" --- Return : %d\n", PRINT("%%")); 
	PRINT(" --- Return : %d\n", PRINT("%-.12u", -20000000));
	PRINT(" --- Return : %d\n", PRINT("%-.12i", -20000000));
	PRINT(" --- Return : %d\n", PRINT("truc"));
	PRINT(" --- Return : %d\n", PRINT("04 Test de chiffre sans h : %d, et %d", 432767, -432767));
	PRINT(" --- Return : %d\n", PRINT("31 This is an int : %.0d", 0));
	PRINT(" --- Return : %d\n", PRINT("32 This is an int : %0d", 0));
	PRINT(" --- Return : %d\n", PRINT("percent 1 %012%"));
	PRINT(" --- Return : %d\n", PRINT("percent 2 %12%"));
	PRINT(" --- Return : %d\n", PRINT("percent 3 %-12%"));
	PRINT(" --- Return : %d\n", PRINT("percent 4 %0%"));
	PRINT(" --- Return : %d\n", PRINT("1string 1 %s string 2 %s", "toto", "bonjour"));
	PRINT(" --- Return : %d\n", PRINT("4string 1 %12s string 2 %12s", "toto", "bonjour"));
	PRINT(" --- Return : %d\n", PRINT("4string 1 %-12s string 2 %-12s", "toto", "bonjour"));
	PRINT(" --- Return : %d\n", PRINT("st1 %*.*d", 10, 10, 50));
	PRINT(" --- Return : %d\n", PRINT("st2 %*.*d", 1, 50, 50));
	PRINT(" --- Return : %d\n", PRINT("st3 %*.*d", 0, 0, 50));
	PRINT(" --- Return : %d\n", PRINT("st4 %*.*d", 0, 50, 50));
	PRINT(" --- Return : %d\n", PRINT("st5 %*.*d", 10, 0, 50));
	PRINT(" --- Return : %d\n", PRINT("st6 %*.*d", 10, 10, 50));
	PRINT(" --- Return : %d\n", PRINT("st12 %*d", 10, 50));
	PRINT(" --- Return : %d\n", PRINT("st13 %*d", 0, 0));
	PRINT(" --- Return : %d\n", PRINT("st14 %.*d", 0, 0));
	PRINT(" --- Return : %d\n", PRINT("st15 %*d", 50, 5));
	PRINT(" --- Return : %d\n", PRINT("st16 %0.*d", 50, 5));
	PRINT(" --- Return : %d\n", PRINT("st17 %0.*d", 0, 0));
	PRINT(" --- Return : %d\n", PRINT("st7 %*.*s", 1, 50, "hey"));
	PRINT(" --- Return : %d\n", PRINT("st8 %*.*s", 0, 0, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("st9 %*.*s", 0, 50, "hey"));
	PRINT(" --- Return : %d\n", PRINT("st10 %*.*s", 10, 0, "dsa"));
	PRINT(" --- Return : %d\n", PRINT("st11 %*.*s", 10, 10, "hello"));
	PRINT(" --- Return : %d\n", PRINT("st8 %.*s", 0, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("st9 %*s", 0, "hey"));
	PRINT(" --- Return : %d\n", PRINT("st10 %*s", 10, "dsa"));
	PRINT(" --- Return : %d\n", PRINT("st118 %*s", 100, "hello"));
	PRINT(" --- Return : %d\n", PRINT("st119 %*s", 1000, "hello"));
	PRINT(" --- Return : %d\n", PRINT("st120 %*s", 10000, "hello"));
	PRINT(" --- Return : %d\n", PRINT("st121 %*s", 100000, "hello"));
	PRINT(" --- Return : %d\n", PRINT("st118 %*d", 100, 0));
	PRINT(" --- Return : %d\n", PRINT("st119 %*d", 1000, 10));
	PRINT(" --- Return : %d\n", PRINT("st120 %*d", 10000, 467));
	PRINT(" --- Return : %d\n", PRINT("st121 %*d", 100000, -589));
	PRINT(" --- Return : %d\n", PRINT("ultimate1 %*d        %*i", 500, 0, 10, 10));
	PRINT(" --- Return : %d\n", PRINT("ultimate2 %*d %*s %*x %*X %*i %*u", 1, 5000, 1, "hey", 10, 54700, 1, 300, 10000, -55, 1, -60));
	PRINT(" --- Return : %d\n", PRINT("ultimate3 %*.*d %*.*s", 1, 50, 5000, 1, 0, "hey"));
	PRINT(" --- Return : %d\n", PRINT("ultimate4 %*.*x %*.*X", 1, 50, 5000, 1, 0, 10));
	PRINT(" --- Return : %d\n", PRINT("ultimate5 %*.*u", 1, 50, 5000));
	PRINT(" --- Return : %d\n", PRINT("neg1 %*s", -9, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg2 %*.*s", -9, 4, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg3 %*s", -9, NULL));
	PRINT(" --- Return : %d\n", PRINT("neg4 %*.*s", 0, 0, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg5 %*s", -100, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg6 %*s", -156, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg7 %*.*s", -1586, 15, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg8 %*.*s", -1586, 15, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg9 %*.*s", 15856, 155, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg10 %*.*s", -15586, 15, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg11 %*.*s", -15586, 15, "coucou"));
	PRINT(" --- Return : %d\n", PRINT("neg1 %*d", -9, 150));
	PRINT(" --- Return : %d\n", PRINT("neg2 %*.*d", -9, 4, 1555));
	PRINT(" --- Return : %d\n", PRINT("neg3 %*d", -9, -255));
	PRINT(" --- Return : %d\n", PRINT("neg4 %*.*d", 0, 0, -30));
	PRINT(" --- Return : %d\n", PRINT("neg5 %*d", -100, -589));
	PRINT(" --- Return : %d\n", PRINT("neg6 %*d", -156, 15555));
	PRINT(" --- Return : %d\n", PRINT("neg7 %*.*d", -1586, 15, 0));
	PRINT(" --- Return : %d\n", PRINT("neg8 %*.*d", -1586, 15, 300));
	PRINT(" --- Return : %d\n", PRINT("neg9 %*.*d", 15856, 155, -3000));
	PRINT(" --- Return : %d\n", PRINT("neg10 %*.*d", -15586, 15, 150));
	PRINT(" --- Return : %d\n", PRINT("neg11 %*.*d", -15586, 15, 0));
	PRINT(" --- Return : %d\n", PRINT("***************%*s%*d**************%*u*************", 10, "coucou", 10, 10, -50, 20));
	PRINT(" --- Return : %d\n", PRINT("taaa %100s", "hello"));
	PRINT(" --- Return : %d\n", PRINT(""));
}
