/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unite <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 23:26:56 by unite             #+#    #+#             */
/*   Updated: 2020/02/22 18:40:56 by unite            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <string.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

int				ft_printf(char const *str, ...);

int				main(void)
{
	clock_t		time0;
	long		l = 2147483647;
	long long	ll = 9223372036854775807;
	char		c = 0;
	size_t		rounds_ft_printf = 0;
	size_t		rounds_printf = 0;
	float		ratio;

	time0 = clock();
	while ((double)(clock() - time0) / CLOCKS_PER_SEC < 15)
	{
		dprintf(2, "\n");
		dprintf(2, "%%\n");
		dprintf(2, "%d\n", 42);
		dprintf(2, "%d%d\n", 42, 41);
		dprintf(2, "%d%d%d\n", 42, 43, 44);
		dprintf(2, "%ld\n", l);
		dprintf(2, "%lld\n", ll);
		dprintf(2, "%x %X %p %20.15d\n", 505, 505, &ll, 54321);
		dprintf(2, "%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
		dprintf(2, "%s%s%s\n", "test", "test", "test");
		rounds_printf += 1;
	}

	time0 = clock();
	while ((double)(clock() - time0) / CLOCKS_PER_SEC < 15)
	{
		ft_dprintf(2, "\n");
		ft_dprintf(2, "%%\n");
		ft_dprintf(2, "%d\n", 42);
		ft_dprintf(2, "%d%d\n", 42, 41);
		ft_dprintf(2, "%d%d%d\n", 42, 43, 44);
		ft_dprintf(2, "%ld\n", l);
		ft_dprintf(2, "%lld\n", ll);
		ft_dprintf(2, "%x %X %p %20.15d\n", 505, 505, &ll, 54321);
		ft_dprintf(2, "%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
		ft_dprintf(2, "%s%s%s\n", "test", "test", "test");
		rounds_ft_printf += 1;
	}

	ratio = (float)rounds_ft_printf / (float)rounds_printf;
	printf("Estimated speed (w/r printf): %d%%\n", (int)(ratio * 100));
	return (0);
}
