/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: artprevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 21:23:26 by artprevo          #+#    #+#             */
/*   Updated: 2019/07/30 20:09:09 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main()
{

	ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);
	ft_printf("@main_ftprintf:                               256\n");
	ft_printf("@main_ftprintf: %####0000 33..1d\n", 256);
	ft_printf("@main_ftprintf:                               256\n");
/*
	printf("lol, pour %6d %s tu as combien de %-4c %c total ~%*.*f soit \n", -420, "kokonut", 'k', '=', 5, 5,324653.2375);
	ft_printf("lol, pour %6d %s tu as combien de %-4c %c total ~%*.*f soit \n", -420, "kokonut", 'k', '=', 5, 5, 324653.2375);
	ft_printf("test :%#.o %#.0o\n", 0, 0);
	printf("test :%#.o %#.0o\n", 0, 0);

	ft_printf("-------------------------------\n");
	ft_printf("EASY\n");
	ft_printf("-------------------------------\n");
	ft_printf("\n");
	ft_printf("\n");
	ft_printf("test\n");
	ft_printf("test\n");
	ft_printf("1234\n");

	ft_printf("-------------------------------\n");
	ft_printf("LE POURCENTAGE\n");
	ft_printf("-------------------------------\n");
	ft_printf("%%\n");
	ft_printf("%5%\n");
	ft_printf("%-5%\n");
	ft_printf("%05%\n");
	ft_printf("%-05%\n");
	ft_printf("% h%\n");
	ft_printf("%.0%\n");

	ft_printf("-------------------------------\n");
	ft_printf("x ET X\n");
	ft_printf("-------------------------------\n");
	ft_printf("%x\n", 42);
	ft_printf("%X\n", 42);
	ft_printf("%x\n", 0);
	ft_printf("%X\n", 0);
	ft_printf("%x\n", -42);
	ft_printf("%X\n", -42);
	ft_printf("%x\n", 4294967296);
	ft_printf("%X\n", 4294967296);
	ft_printf("-------------------------------\n");

	ft_printf("%10x\n", 42);
	ft_printf("%-10x\n", 42);

	ft_printf("-------------------------------\n");
	ft_printf("%lx\n", 4294967296);
	ft_printf("%llX\n", 4294967296);

	ft_printf("-------------------------------\n");
	ft_printf("%hx\n", 4294967296);
	ft_printf("%hhX\n", 4294967296);

	ft_printf("-------------------------------\n");
	ft_printf("%x\n", 4294967295);
	ft_printf("%x\n", 4294967296);

	ft_printf("-------------------------------\n");
	ft_printf("%x\n", -4294967296);
	ft_printf("%x\n", -4294967297);

	ft_printf("-------------------------------\n");
	ft_printf("%llx\n", 9223372036854775807);

	ft_printf("-------------------------------\n");
	ft_printf("%010x\n", 542);
	ft_printf("%-15x\n", 542);
	ft_printf("%2x\n", 542);
	ft_printf("%.2x\n", 5427);
	ft_printf("%5.2x\n", 5427);

	ft_printf("-------------------------------\n");
	ft_printf("%#x\n", 42);
	ft_printf("%llx\n", 9223372036854775807);
	ft_printf("%#llx\n", 9223372036854775807);

	ft_printf("-------------------------------\n");
	ft_printf("%#x\n", 0);
	ft_printf("%#x\n", 42);
	ft_printf("%#X\n", 42);
	ft_printf("%#8x\n", 42);
	ft_printf("%#08x\n", 42);
	ft_printf("%#-08x\n", 42);

	ft_printf("-------------------------------\n");
	ft_printf("@moulitest: %#.x %#.0x\n", 0, 0);
	ft_printf("@moulitest: %.x %.0x\n", 0, 0);
	ft_printf("@moulitest: %5.x %5.0x\n", 0, 0);

	ft_printf("-------------------------------\n");
	ft_printf("STRING\n");
	ft_printf("-------------------------------\n");
	ft_printf("%s\n", "abc");
	ft_printf("%s\n", "this is a string");
	ft_printf("%s \n", "this is a string");
	ft_printf("%s  \n", "this is a string");
	ft_printf("this is a %s\n", "string");
	ft_printf("%s is a string\n", "this");
	ft_printf("Line Feed %s\n", "\n");

	ft_printf("%10s is a string\n", "this");
	ft_printf("%010s is a string\n", "this");
	ft_printf("%.2s is a string\n", "this");
	ft_printf("%5.2s is a string\n", "this");
	ft_printf("%10s is a string\n", "this");
	ft_printf("%.2s is a string\n", "this");
	ft_printf("%5.2s is a string\n", "this");

	ft_printf("%-10s is a string\n", "this");
	ft_printf("%-010s is a string\n", "this");
	ft_printf("%-.2s is a string\n", "this");
	ft_printf("%-5.2s is a string\n", "this");
	ft_printf("%-10s is a string\n","this");
	ft_printf("%-.2s is a string\n", "this");
	ft_printf("%-5.2s is a string\n", "this");

	ft_printf("%s %s\n", "this", "is");
	ft_printf("%s %s %s\n", "this", "is", "a");
	ft_printf("%s %s %s %s\n", "this", "is", "a", "multi");
	ft_printf("%s %s %s %s string. gg!\n", "this", "is", "a", "multi", "string");
	ft_printf("%s%s%s%s%s\n", "this", "is", "a", "multi", "string");

	ft_printf("@moulitest: %s\n", NULL);
	ft_printf("%.2c\n", NULL);
	ft_printf("%s %s\n", NULL, "string");

	ft_printf("-------------------------------\n");
	ft_printf("CHAR\n");
	ft_printf("-------------------------------\n");
	ft_printf("%c\n", 42);
	ft_printf("%5c\n", 42);
	ft_printf("%05c\n", 42);
	ft_printf("%-5c\n", 42);
	ft_printf("@moulitest: %c\n", 0);
	ft_printf("%2c\n", 0);
	ft_printf("null %c and text\n", 0);
	ft_printf("% c\n", 0);

	ft_printf("-------------------------------\n");
	ft_printf("OCTAL\n");
	ft_printf("-------------------------------\n");
	ft_printf("%o\n", 40);
	ft_printf("%5o\n", 41);
	ft_printf("%05o\n", 42);
	ft_printf("%-5o\n", 2500);
	ft_printf("%#6o\n", 2500);
	ft_printf("%-#6o\n", 2500);
	ft_printf("%-05o\n", 2500);
	ft_printf("%-5.10o\n", 2500);
	ft_printf("%-10.5o\n", 2500);
	ft_printf("@moulitest: %o\n", 0);
	ft_printf("@moulitest: %.o %.0o\n", 0, 0);
	ft_printf("@moulitest: %5.o %5.0o\n", 0, 0);
	ft_printf("@moulitest: %#.o %#.0o\n", 0, 0);
	ft_printf("@moulitest: %.10o\n", 42);

	ft_printf("-------------------------------\n");
	ft_printf("INT\n");
	ft_printf("-------------------------------\n");
	ft_printf("% \n", 42);

	ft_printf("%d\n", 1);
	ft_printf("the %d\n", 1);
	ft_printf("%d is one\n", 1);
	ft_printf("%d\n", -1);
	ft_printf("%d\n", 4242);
	ft_printf("%d\n", -4242);
	ft_printf("%d\n", 2147483647);
	ft_printf("%d\n", 2147483648);
	ft_printf("%d\n", -2147483648);
	ft_printf("%d\n", -2147483649);
	ft_printf("\n");
	ft_printf("% d\n", 42);
	ft_printf("% d\n", -42);
	ft_printf("%0 d\n", 42);
	ft_printf("%0 d\n", -42);
	ft_printf("% 0d\n", 42);
	ft_printf("% 0d\n", -42);
	ft_printf("\n");
	ft_printf("%+d\n", 42);
	ft_printf("%+d\n", -42);
	ft_printf("%+d\n", 0);
	ft_printf("% +d\n", 42);
	ft_printf("% +d\n", -42);
	ft_printf("%+ d\n", 42);
	ft_printf("%+ d\n", -42);
	ft_printf("%  +d\n", 42);
	ft_printf("%  +d\n", -42);
	ft_printf("%+  d\n", 42);
	ft_printf("%+  d\n", -42);
	ft_printf("% ++d\n", 42);
	ft_printf("% ++d\n", -42);
	ft_printf("%++ d\n", 42);
	ft_printf("%++ d\n", -42);
	ft_printf("\n");
	ft_printf("%0d\n", -42);
	ft_printf("%00d\n", -42);
	ft_printf("\n");
	ft_printf("%5d\n", 42);
	ft_printf("%5+d\n", 42);
	ft_printf("%05d\n", 42);
	ft_printf("%0+5d\n", 42);
	ft_printf("%5d\n", -42);
	ft_printf("%5+d\n", -42);
	ft_printf("%05d\n", -42);
	ft_printf("%0+5d\n", -42);
	ft_printf("\n");
	ft_printf("%-5d\n", 42);
	ft_printf("%-5+d\n", 42);
	ft_printf("%-05d\n", 42);
	ft_printf("%-0+5d\n", 42);
	ft_printf("%-5d\n", -42);
	ft_printf("%-5+d\n", -42);
	ft_printf("%-05d\n", -42);
	ft_printf("%-0+5d\n", -42);

	ft_printf("-------------------------------\n");
	ft_printf("INT SHORT\n");
	ft_printf("-------------------------------\n");
	ft_printf("%hd\n", 32767);
	ft_printf("%hd\n", 32768);

	ft_printf("-------------------------------\n");
	ft_printf("SIGNED CHAR\n");
	ft_printf("-------------------------------\n");
	ft_printf("%hhd\n", 127);
	ft_printf("%hhd\n", 128);
	ft_printf("%hhd\n", -128);
	ft_printf("%hhd\n", -129);

	ft_printf("-------------------------------\n");
	ft_printf("INT LONG\n");
	ft_printf("-------------------------------\n");
	ft_printf("%ld\n", 2147483647);
	ft_printf("%ld\n", -2147483648);
	ft_printf("%ld\n", 2147483648);
	ft_printf("%ld\n", -2147483649);

	ft_printf("-------------------------------\n");
	ft_printf("INT LONG LONG\n");
	ft_printf("-------------------------------\n");
	ft_printf("%lld\n", 9223372036854775807);

	ft_printf("-------------------------------\n");
	ft_printf("INTMAXXX\n");
	ft_printf("-------------------------------\n");
	ft_printf("%d\n", 9223372036854775807);

	ft_printf("-------------------------------\n");
	ft_printf("INT LE RETOUR\n");
	ft_printf("-------------------------------\n");
	ft_printf("%d\n", 4294967295);
	ft_printf("%d\n", 4294967296);
	ft_printf("%d\n", -0);
	ft_printf("%d\n", -1);

	ft_printf("%d\n", 1);
	ft_printf("%d %d\n", 1, -2);
	ft_printf("%d %d %d\n", 1, -2, 33);
	ft_printf("%d %d %d %d\n", 1, -2, 33, 42);
	ft_printf("%d %d %d %d gg!\n", 1, -2, 33, 42, 0);

	ft_printf("-------------------------------\n");
	ft_printf("PRECISION\n");
	ft_printf("-------------------------------\n");
	ft_printf("%4.15d\n", 42);
	ft_printf("%.2d\n", 4242);
	ft_printf("%.10d\n", 4242);
	ft_printf("%10.5d\n", 4242);
	ft_printf("%-10.5d\n", 4242);
	ft_printf("% 10.5d\n", 4242);
	ft_printf("%+10.5d\n", 4242);
	ft_printf("%-+10.5d\n", 4242);
	ft_printf("%03.2d\n", 0);
	ft_printf("%03.2d\n", 1);
	ft_printf("%03.2d\n", -1);
	ft_printf("@moulitest: %.10d\n", -42);
	ft_printf("@moulitest: %.d %.0d\n", 42, 43);
	ft_printf("@moulitest: %.d %.0d\n", 0, 0);
	ft_printf("@moulitest: %5.d %5.0d\n", 0, 0);

	ft_printf("-------------------------------\n");
	ft_printf("UNSIGNED\n");
	ft_printf("-------------------------------\n");
	ft_printf("%u\n", 0);
	ft_printf("%u\n", 1);
	ft_printf("%u\n", -1);
	ft_printf("%u\n", 4294967295);
	ft_printf("%u\n", 4294967296);

	ft_printf("%5u\n", 4294967295);
	ft_printf("%15u\n", 4294967295);
	ft_printf("%-15u\n", 4294967295);
	ft_printf("%015u\n", 4294967295);
	ft_printf("% u\n", 4294967295);
	ft_printf("%+u\n", 4294967295);

	ft_printf("%lu\n", 4294967295);
	ft_printf("%lu\n", 4294967296);
	ft_printf("%lu\n", -42);

	ft_printf("%llu\n", 4999999999);

	ft_printf("%u\n", 4999999999);

	ft_printf("%u\n", 4294967296);

	ft_printf("@moulitest: %.5u\n", 42);

	ft_printf("-------------------------------\n");
*/
	return (0);
}
