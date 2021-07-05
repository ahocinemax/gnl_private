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

int	ft_search_end(char *line)
{
	while (*line)
		line++;
	
}

int	get_next_line(int fd, char **line)
{
	ssize_t	i;
	char	buff[BUFFER_SIZE + 1];
	static char	*curr_line;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (-1);
	while (read(fd, buff, BUFFER_SIZE))
	{

	}
	return (0);
}