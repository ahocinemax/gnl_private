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

char	*verify_end_file(char *tmp, ssize_t lu, char *curr_line)
{
	if (!tmp && lu == 0 && ft_strlen(curr_line) == 0)
	{
		free(curr_line);
		return (NULL);
	}
	else
		return (curr_line);
}

char	*get_next_line(int fd)
{
	ssize_t		lu;
	char		buff[BUFFER_SIZE + 1];
	char		*curr_line;
	int			eol;
	static char	*tmp;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	lu = 1;
	curr_line = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!curr_line)
		return (NULL);
	eol = 0;
	while (!eol && lu > 0)
	{
		lu = read(fd, buff, BUFFER_SIZE);
		eol = ft_search_end(buff);
		if (lu < 1)
		{
			free(curr_line);
			return (NULL);
		}
		buff[lu] = 0;
		tmp = ft_strcat(curr_line, buff);
	}
	curr_line = ft_line(tmp);
	tmp = ft_reste(tmp);
	curr_line = verify_end_file(tmp, lu, curr_line);
	return (curr_line);
}
