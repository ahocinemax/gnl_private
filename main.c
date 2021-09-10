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

int	main(void)
{
	char	*ret;
	int		fd;
	int		i;

	ret = NULL;
	i = 1;
	fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		ret = get_next_line(fd);
		while (ret)
		{
			printf("line %d = \e[33m[%s]\e[0m\n", i++, ret);
			if (ret)
				free(ret);
			ret = get_next_line(fd);
		}
		close(fd);
	}
	return (0);
}
