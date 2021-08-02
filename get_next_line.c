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

char	*ft_free_eof(char *tmp, ssize_t lu, char *curr_line)
{
	if (!tmp && !lu && !ft_strlen(curr_line))
	{
		free(curr_line);
		return (NULL);
	}
	else
		return (curr_line);
}

static int	ft_init(ssize_t *lu, char **curr_line, int *eol, char **tmp)
{
	*lu = 1;
	*curr_line = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!curr_line)
		return (-1);
	*eol = 0;
	if (**tmp)
		*tmp = ft_strcat(*tmp, *curr_line);
	return (0);
}

char	*get_next_line(int fd)
{
	ssize_t		lu;
	char		buff[BUFFER_SIZE + 1];
	char		*curr_line;
	int			eol;
	static char	*tmp;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1 || \
		ft_init(&lu, &curr_line, &eol, &tmp))
		return (NULL);
	printf("reste = [%s]\n", tmp);
	while (!eol && lu > 0 && !ft_search_end(tmp))
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
//		printf("tmp = [%s]\n", tmp);
	}
	curr_line = ft_line(tmp);
//	printf("curr = [%s]\n", curr_line);
	tmp = ft_reste(tmp);
	curr_line = ft_free_eof(tmp, lu, curr_line);
	return (curr_line);
}
