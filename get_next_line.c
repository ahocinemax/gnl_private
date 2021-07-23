/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 01:49:25 by ahocine           #+#    #+#             */
/*   Updated: 2021/07/01 01:49:27 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search_end(char *str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		lu;
	char		buff[BUFFER_SIZE + 1];
	static char	*curr_line;
	int			eol;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	lu = read(fd, buff, BUFFER_SIZE);
	curr_line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
//	printf("buff : '%s'\n", buff);
	eol = ft_search_end(buff);
	while (eol && lu)
	{
		lu = read(fd, buff, BUFFER_SIZE);
		eol = ft_search_end(buff);
		if (lu < 0)
		{
			free(curr_line);
			return (NULL);
		}
//		printf("lu, eol : %d, %ld\n", eol, lu);
		if (eol < lu)
			buff[eol] = 0;
		else
			buff[lu] = 0;
//		printf("curr_line = %s\n", curr_line);
//		printf("buff = %s\n", buff);
		curr_line = ft_strjoin(curr_line, buff);
	}
	return (curr_line);
}

int	main(void)
{
	int		fd;
	char	*ret;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		ret = get_next_line(fd);
		printf("ret : %s\n", ret);
		while (ret)
		{
			printf("current_line = %s\n", ret);
			ret = get_next_line(fd);
		}
	}
	printf("No more line.\n");
	return (0);
}
