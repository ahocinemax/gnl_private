/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 01:49:51 by ahocine           #+#    #+#             */
/*   Updated: 2021/07/01 01:49:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int n)
{
	if (n < 0)
		ft_putchar('-');
	if (n < 0)
		n *= -1;
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

static void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		ft_putchar(s[i++]);
}

int	main(void)
{
	char	*ret;
	int		fd;
	int		i;

	i = 1;
	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		while ((ret = get_next_line(fd)))
		{
			ft_putstr("****************************************************\nline ");
			ft_putnbr(i++);
			ft_putstr(" : [");
			ft_putstr(ret);
			ft_putstr("]\n****************************************************\n\n");
		}
		close(fd);
	}
	return (0);
}
