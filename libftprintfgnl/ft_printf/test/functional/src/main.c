/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/04 17:33:51 by unite             #+#    #+#             */
/*   Updated: 2020/07/02 00:18:20 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "unity.h"
#include "ft_printf.h"

void	setUp(void)
{
	return ;
}

void	tearDown(void)
{
	return ;
}

void	test_output(const char *expected, const char *format, ...)
{
	static char	zero = 0;
	char		buffer[100];
	int 		pipefd[2];
	va_list		ap;
	char		*str;

	va_start(ap, format);
	pipe(pipefd);
	ft_vdprintf(pipefd[1], format, ap);
	write(pipefd[1], &zero, 1);
	read(pipefd[0], buffer, 100);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, buffer, format);
	close(pipefd[0]);
	close(pipefd[1]);
	va_end(ap);

	va_start(ap, format);
	ft_vsprintf(buffer, format, ap);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, buffer, format);
	va_end(ap);

	va_start(ap, format);
	ft_vasprintf(&str, format, ap);
	TEST_ASSERT_EQUAL_STRING_MESSAGE(expected, str, format);
	free(str);
	va_end(ap);
}

void	test_rc(int expected, const char *format, ...)
{
	int			rc;
	int 		pipefd[2];
	va_list		ap;

	va_start(ap, format);
	pipe(pipefd);

	rc = ft_vdprintf(pipefd[1], format, ap);
	TEST_ASSERT_EQUAL_MESSAGE(expected, rc, format);

	close(pipefd[0]);
	close(pipefd[1]);
	va_end(ap);
}

void	test_basic(void)
{
	test_output("", "");
	test_output("\\n", "\\n");
	test_output("test", "test");
	test_output("test\\n", "test\\n");
	test_output("1234", "1234");
}

void	test_pc(void)
{
	test_output("%", "%%");
	test_output("    %", "%5%");
	test_output("%    ", "%-5%");
	test_output("%", "%.0%");
	test_output("%", "%%", "test");
	test_output("%", "%   %", "test");
}

void	test_x(void)
{
	test_output("2a", "%x", 42);
	test_output("0", "%x", 0);
	test_output("ffffffd6", "%x", -42);
	test_output("0", "%x", 4294967296);
	test_output("        2a", "%10x", 42);
	test_output("2a        ", "%-10x", 42);
	test_output("100000000", "%lx", 4294967296);
	test_output("0", "%hx", 4294967296);
	test_output("000000021e", "%010x", 542);
	test_output("21e            ", "%-15x", 542);
	test_output("21e", "%2x", 542);
	test_output("1533", "%.2x", 5427);
	test_output(" 1533", "%5.2x", 5427);
	test_output("0x2a", "%#x", 42);
	test_output("0x7fffffffffffffff", "%#llx", 9223372036854775807lu);
	test_output("0", "%#x", 0);
	test_output("0x2a", "%#x", 42);
	test_output("    0x2a", "%#8x", 42);
	test_output("0x00002a", "%#08x", 42);
	test_output("0x2a    ", "%#-08x", 42);
	test_output("@moulitest:  ", "@moulitest: %#.x %#.0x", 0, 0);
	test_output("@moulitest:  ", "@moulitest: %.x %.0x", 0, 0);
	test_output("@moulitest:            ", "@moulitest: %5.x %5.0x", 0, 0);
}

void	test_xx(void)
{
	test_output("2A", "%X", 42);
	test_output("0", "%X", 0);
	test_output("FFFFFFD6", "%X", -42);
	test_output("0", "%X", 4294967296);
	test_output("100000000", "%llX", 4294967296);
	test_output("0", "%hhX", 4294967296);
	test_output("0X2A", "%#X", 42);
}

void	test_s(void)
{
	test_output("abc", "%s", "abc");
	test_output("this is a string", "%s", "this is a string");
	test_output("this is a string ", "%s ", "this is a string");
	test_output("this is a string  ", "%s  ", "this is a string");
	test_output("this is a string", "this is a %s", "string");
	test_output("this is a string", "%s is a string", "this");
	test_output("Line Feed \\n", "Line Feed %s", "\\n");
	test_output("..a stuff b", "..%s stuff %s", "a", "b");
	test_output("      this is a string", "%10s is a string", "this");
	test_output("th is a string", "%.2s is a string", "this");
	test_output("   th is a string", "%5.2s is a string", "this");
	test_output("           is a string", "%10s is a string", "");
	test_output(" is a string", "%.2s is a string", "");
	test_output("      is a string", "%5.2s is a string", "");
	test_output("helworld", "%3.3s%3.7s", "hello", "world");
	test_output("hello    wor", "%3.7s%7.3s", "hello", "world");
	test_output("helloworld", "%3s%3s", "hello", "world");
	test_output("                          (null)", "%32s", NULL);
	test_output("(null)                          ", "%-32s", NULL);
	test_output("NULL", "%.9s", "NULL");
	test_output("NUL", "%.3s", "NULL");
	test_output("(null)", "%.09s", NULL);
	test_output("yo    boi", "%.5s%7s", "yo", "boi");
	test_output("this       is a string", "%-10s is a string", "this");
	test_output("th is a string", "%-.2s is a string", "this");
	test_output("th    is a string", "%-5.2s is a string", "this");
	test_output("           is a string", "%-10s is a string", "");
	test_output(" is a string", "%-.2s is a string", "");
	test_output("      is a string", "%-5.2s is a string", "");
	test_output("nark nark       ", "%-16s", "nark nark");
	test_output("this is", "%s %s", "this", "is");
	test_output("this is a", "%s %s %s", "this", "is", "a");
	test_output("this is a multi", "%s %s %s %s", "this", "is", "a", "multi");
	test_output("this is a multi string. gg!", "%s %s %s %s string. gg!", "this", "is", "a", "multi", "string");
	test_output("thisisamultistring", "%s%s%s%s%s", "this", "is", "a", "multi", "string");
	test_output("@moulitest: (null)", "@moulitest: %s", NULL);
}

void	test_c(void)
{
	test_output("*", "%c", 42);
	test_output("    *", "%5c", 42);
	test_output("*    ", "%-5c", 42);
}

void	test_o(void)
{
	test_output("50", "%o", 40);
	test_output("   51", "%5o", 41);
	test_output("00052", "%05o", 42);
	test_output("4704 ", "%-5o", 2500);
	test_output(" 04704", "%#6o", 2500);
	test_output("04704 ", "%-#6o", 2500);
	test_output("4704 ", "%-05o", 2500);
	test_output("0000004704", "%-5.10o", 2500);
	test_output("04704     ", "%-10.5o", 2500);
	test_output("@moulitest: 0", "@moulitest: %o", 0);
	test_output("@moulitest:  ", "@moulitest: %.o %.0o", 0, 0);
	test_output("@moulitest:            ", "@moulitest: %5.o %5.0o", 0, 0);
	test_output("@moulitest: 0 0", "@moulitest: %#.o %#.0o", 0, 0);
	test_output("@moulitest: 0000000052", "@moulitest: %.10o", 42);
	test_output("this 0 number", "this %#o number", 0);
	test_output("  0", "%#3o", 0);
	test_output("0  ", "%#-3o", 0);
	test_output("%#o 0 ==  0", "%%#o 0 ==  %#o", 0);
}

void	test_d(void)
{
	test_output("1", "%d", 1);
	test_output("the 1", "the %d", 1);
	test_output("1 is one", "%d is one", 1);
	test_output("-1", "%d", -1);
	test_output("4242", "%d", 4242);
	test_output("-4242", "%d", -4242);
	test_output("2147483647", "%d", 2147483647);
	test_output("-2147483648", "%ld", -2147483648);
	test_output("-2147483648", "%d", -2147483648);
	test_output("2147483647", "%ld", 2147483647);
	test_output(" 42", "% d", 42);
	test_output("-42", "% d", -42);
	test_output("+42", "%+d", 42);
	test_output("-42", "%+d", -42);
	test_output("+0", "%+d", 0);
	test_output("+42", "% +d", 42);
	test_output("-42", "% +d", -42);
	test_output("+42", "%+ d", 42);
	test_output("-42", "%+ d", -42);
	test_output("+42", "%  +d", 42);
	test_output("-42", "%  +d", -42);
	test_output("+42", "%+  d", 42);
	test_output("-42", "%+  d", -42);
	test_output("+42", "% ++d", 42);
	test_output("-42", "% ++d", -42);
	test_output("+42", "%++ d", 42);
	test_output("-42", "%++ d", -42);
	test_output("-42", "%0d", -42);
	test_output("-42", "%00d", -42);
	test_output("   42", "%5d", 42);
	test_output("00042", "%05d", 42);
	test_output("+0042", "%0+5d", 42);
	test_output("  -42", "%5d", -42);
	test_output("-0042", "%05d", -42);
	test_output("-0042", "%0+5d", -42);
	test_output("42   ", "%-5d", 42);
	test_output("42   ", "%-05d", 42);
	test_output("-42  ", "%-5d", -42);
	test_output("-42  ", "%-05d", -42);
	test_output("32767", "%hd", 32767);
	test_output("-32768", "%hd", -32768);
	test_output("127", "%hhd", 127);
	test_output("128", "%hhd", 128);
	test_output("-128", "%hhd", -128);
	test_output("-129", "%hhd", -129);
	test_output("2147483647", "%ld", 2147483647);
	test_output("-2147483648", "%ld", -2147483648);
	test_output("2147483648", "%ld", 2147483648);
	test_output("-2147483649", "%ld", -2147483649);
	test_output("9223372036854775807", "%lld", 9223372036854775807);
	test_output("-9223372036854775808", "%lld", -9223372036854775808u);
	test_output("1", "%d", 1);
	test_output("1 -2", "%d %d", 1, -2);
	test_output("1 -2 33", "%d %d %d", 1, -2, 33);
	test_output("1 -2 33 42", "%d %d %d %d", 1, -2, 33, 42);
	test_output("1 -2 33 42 gg!", "%d %d %d %d gg!", 1, -2, 33, 42, 0);
	test_output("000000000000042", "%4.15d", 42);
	test_output("4242", "%.2d", 4242);
	test_output("0000004242", "%.10d", 4242);
	test_output("     04242", "%10.5d", 4242);
	test_output("04242     ", "%-10.5d", 4242);
	test_output("     04242", "% 10.5d", 4242);
	test_output("    +04242", "%+10.5d", 4242);
	test_output("+04242    ", "%-+10.5d", 4242);
	test_output(" 00", "%03.2d", 0);
	test_output(" 01", "%03.2d", 1);
	test_output("-01", "%03.2d", -1);
	test_output("@moulitest: -0000000042", "@moulitest: %.10d", -42);
	test_output("@moulitest: 42 43", "@moulitest: %.d %.0d", 42, 43);
	test_output("@moulitest:  ", "@moulitest: %.d %.0d", 0, 0);
	test_output("@moulitest:            ", "@moulitest: %5.d %5.0d", 0, 0);
	test_output("    +", "%+5.0i", 0);
	test_output("    +", "%+5.i", 0);
	test_output("    +", "%+5.0d", 0);
	test_output("    +", "%+5.d", 0);
}

void	test_u(void)
{
	test_output("0", "%u", 0);
	test_output("1", "%u", 1);
	test_output("4294967295", "%u", -1);
	test_output("4294967295", "%u", 4294967295);
	test_output("0", "%u", 4294967296);
	test_output("4294967295", "%5u", 4294967295);
	test_output("     4294967295", "%15u", 4294967295);
	test_output("4294967295     ", "%-15u", 4294967295);
	test_output("000004294967295", "%015u", 4294967295);
	test_output("4294967295", "% u", 4294967295);
	test_output("4294967295", "%+u", 4294967295);
	test_output("4294967295", "%lu", 4294967295);
	test_output("4294967296", "%lu", 4294967296);
	test_output("4999999999", "%llu", 4999999999);
	test_output("@moulitest: 00042", "@moulitest: %.5u", 42);
}

void	test_f(void)
{
	test_output("TEST: (null)", "TEST: %f", 0.0 / 0.0);
	test_output("TEST: (inf)", "TEST: %f", 1.0 / 0.0);
	test_output("TEST: (-inf)", "TEST: %f", -1.0 / 0.0);
	test_output("7.500000", "%f", 7.5);
	test_output("-3.850000", "%f", -3.85);
	test_output("573.924000", "%f", 573.924);
	test_output("-958.125000", "%f", -958.125);
	test_output("23.000410", "%f", 23.00041);
	test_output("-99.999999", "%f", -99.999999);
	test_output("23.375094", "%f", 23.375094499);
	test_output("-0.999999", "%f", -0.99999949);
	test_output("1.000000", "%f", 1.0);
	test_output("4.000000", "%f", 3.9999999);
	test_output("-6.000000", "%f", -5.9999999);
	test_output("1.0", "%.1f", 1.0);
	test_output("this 2 float", "this %.0f float", 1.6);
	test_output("7", "%.0f", 7.4);
	test_output("-0", "%.0f", -0.00032);
	test_output("this 1.5 float", "this %.1f float", 1.5);
	test_output("this 1.500 float", "this %.3f float", 1.5);
	test_output("-3.850", "%.3f", -3.85);
	test_output("-0.000", "%.3f", -0.00032);
	test_output("1.0000000", "%.7f", 1.0);
	test_output("-7.3", "%#.1f", -7.3);
	test_output("    7", "%5.0f", 7.3);
	test_output("  7.3", "%5.1f", 7.3);
	test_output("7.300", "%5.3f", 7.3);
	test_output("-7.300000", "%5.6f", -7.3);
	test_output("-7   ", "%-5.0f", -7.3);
	test_output(" 7   ", "% -5.0f", 7.3);
	test_output(" 7.300", "% -5.3f", 7.3);
	test_output("-7   ", "% -5.0f", -7.3);
	test_output("-7.300", "% -5.3f", -7.3);
	test_output("-985.765426", "%Lf", -985.765426499l);
	test_output("0.089426", "%Lf", 0.08942555l);
	test_output("43.440000", "%Lf", 43.4399999l);
	test_output("0.0000039", "%.7Lf", 0.0000039l);
	test_output("9873.0000010", "%.7Lf", 9873.000001l);
}

void	test_asterix(void)
{
	test_output("  1", "%*d", 3, 1);
	test_output("02", "%.*d", 2, 2);
}

void	test_b(void)
{
	test_output("101", "%b", 5);
	test_output("-101", "%b", -5);
	test_output("0", "%b", 0);
}

void	test_colors(void)
{
	test_output("\x1B[32mgreen\x1B[0m", "{green}green{eoc}");
	test_output("\x1B[31mred\x1B[0m", "{red}red{eoc}");
	test_output("\x1B[36mcyan\x1B[0m", "{cyan}cyan{eoc}");
	test_output("\x1B[33myellow\x1B[0m", "{yellow}yellow{eoc}");
	test_output("\x1B[35mmagenta\x1B[0m", "{magenta}magenta{eoc}");
	test_output("\x1B[34mblue\x1B[0m", "{blue}blue{eoc}");
	test_rc(-1, "{unicorns}unicorns!{eoc}");
}

int		main(void)
{
	UNITY_BEGIN();

	RUN_TEST(test_basic);
	RUN_TEST(test_pc);
	RUN_TEST(test_x);
	RUN_TEST(test_xx);
	RUN_TEST(test_o);
	RUN_TEST(test_u);
	RUN_TEST(test_d);
	RUN_TEST(test_s);
	RUN_TEST(test_c);
	RUN_TEST(test_f);
	RUN_TEST(test_b);
	RUN_TEST(test_asterix);
	RUN_TEST(test_colors);

	return (UNITY_END());
}
