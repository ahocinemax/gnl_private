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
	if (lu < BUFFER_SIZE && !ft_search_end(tmp))
	{
		printf("fin\n");
		free(curr_line);
		return (NULL);
	}
	else
		return (curr_line);
}

void	ft_strcpy(char **dst, char **src)
{
	size_t	i;

	i = 0;
	if (!(*src))
		return ;
	while (*src[i])
	{
		*dst[i] = *src[i];
		i++;
	}
}

int	ft_init_check(ssize_t *lu, char **curr_line, int *eol, char **tmp)
{
	*lu = 1;
	*curr_line = (char *)calloc((ft_strlen(*tmp) + 1), sizeof(char));
	if (!curr_line)
		return (-1);
	*eol = 0;
	if (*tmp && eol)
		ft_strcat(*curr_line, *tmp);
	return (0);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*tmp;
	ssize_t		lu;
	char		*curr_line;
	int			eol;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1 || \
		ft_init_check(&lu, &curr_line, &eol, &tmp))
		return (NULL);
	while (!eol && lu > 0 && !ft_search_end(tmp))
	{
		lu = read(fd, buff, BUFFER_SIZE);
		eol = ft_search_end(buff);
		if (lu < 1 && !eol && !(*tmp))
		{
			free(curr_line);
			return (NULL);
		}
		buff[lu] = 0;
		tmp = ft_strcat(curr_line, buff);
	}
	curr_line = ft_line(tmp);
	tmp = ft_reste(tmp);
	return (curr_line);
}
