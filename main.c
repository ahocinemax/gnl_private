/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/23 06:17:10 by jodufour          #+#    #+#             */
/*   Updated: 2021/07/01 03:42:34 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		while ((ret = get_next_line(fd, &line)) == 1)
		{
			printf("\e[33mLine Read:\e[0m [%s]\n\n", line);
			free(line);
		}
		if (!ret)
			printf("\e[32mEOF Reached:\e[0m [%s]\n\n", line);
		else if (ret == -1)
			printf("\e[31mError: get_next_line() failed\e[0m\n\n");
		else
			printf("\e[31mError: Unexpected return value: %d\e[0m\n\n", ret);
		free(line);
		close(fd);
	}
	system("leaks a.out | grep 'leaks'");
	return (0);
}
