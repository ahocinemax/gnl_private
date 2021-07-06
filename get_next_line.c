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
			return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		lu;
	char		buff[BUFFER_SIZE + 1];
	static char	*curr_line;
	
	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	lu = 1;
	curr_line = ft_strjoin(curr_line, buff);
	while (!ft_search_end(buff) && lu > 0)
	{
		lu = (read(fd, buff, BUFFER_SIZE) > 0);
		if (lu < 0)
		{
			free(curr_line);
			return (-1);
		}
		buff[lu] = 0;
		curr_line = ft_strjoin(curr_line, buff);
	}
	return (1);
}
