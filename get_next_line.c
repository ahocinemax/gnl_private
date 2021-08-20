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

int	ft_init_check(ssize_t *lu, char **curr_line, int *eol, char **tmp)
{
	*lu = 1;
	*curr_line = (char *)ft_calloc((4095 + 1), sizeof(char));
	if (!curr_line)
		return (-1);
	*eol = 0;
	if (*tmp)
		ft_strcat(*curr_line, *tmp);
	return (0);
}

char	*ft_line(char *tmp)
{
	char	*curr_line;
	int		i;
	int		len;

	if (!tmp)
		return (NULL);
	len = ft_search_end(tmp);
	if (!len)
		len = ft_strlen(tmp);
	curr_line = (char *)ft_calloc(len + 1, sizeof(char));
	if (!curr_line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] == '\n')
		i++;
	while (tmp[i] && i < len)
	{
		curr_line[i] = tmp[i];
		i++;
	}
	return (curr_line);
}

char	*ft_reste(char *tmp)
{
	char	*reste;
	int		i;
	int		j;

	if (!tmp)
		return (NULL);
	i = ft_search_end(tmp) + 1;
	while (tmp[i] && tmp[i] == '\n')
		i++;
	reste = (char *)ft_calloc(ft_strlen(tmp) - i + 1, sizeof(char));
	if (!reste)
		return (NULL);
	j = 0;
	while (tmp[i])
		reste[j++] = tmp[i++];
	reste[j] = 0;
	free(tmp);
	return (reste);
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
	while (!eol && lu > 0)
	{
		lu = read(fd, buff, BUFFER_SIZE);
		eol = ft_search_end(buff);
		if (lu < 1 && !eol && !(*tmp))
		{
			printf("fin\n");
			free(curr_line);
			return (NULL);
		}
		buff[lu] = 0;
		tmp = ft_strcat(curr_line, buff);
	}
	//printf("curr_line : [%s]\n", curr_line);
	curr_line = ft_line(tmp);
	if (ft_search_end(tmp))
		tmp = ft_reste(tmp);
	else
		free(tmp);
	return (curr_line);
}
