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

int	get_next_line(int fd, char **line)
{
	size_t		i;
	char		*buff_tmp;
	static char	*curr_line;

	if (fd < 0 || !line || read(fd, BUFFER_SIZE, 0) < 0)
		return (-1);
	read(fd, curr_line, BUFFER_SIZE);
	return (0);
}
