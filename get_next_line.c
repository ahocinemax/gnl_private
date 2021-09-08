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

int	ft_init_check(ssize_t *lu, char **line, char **reste)
{
	if (BUFFER_SIZE < 1)
		return (-1);
	*line = (char *)ft_calloc((4096 + 1), sizeof(char));
	if (!(*line))
		return (-1);
	*lu = 1;
	if (*reste)
	{
		ft_strcat(*line, *reste);
		free(*reste);
	}
	while (**line == '\n')
		(*line)++;
	return (0);
}

void	ft_line(char **line)
{
	int		len;

	if (!(*line))
		return ;
	len = ft_search_end(line);
	if (len < 0)
		len = ft_strlen(*line);
	(*line)[len] = 0;
}

char	*ft_reste(char *buf)
{
	int		i;
	int		j;
	char	*res;
	int		len_buf;

	if (buf == NULL)
		return (NULL);
	i = ft_search_end(&buf);
	if (i == -1)
	{
		printf("\e[31mNo rest, returning NULL\e[0m\n");
		return (NULL);
	}
	while (*buf == '\n')
		(buf)++;
	while (buf[i] && buf[i] == '\n')
		i++;
	printf("eol reste = %d\n", i);
	len_buf = ft_strlen(buf);
	res = (char *)ft_calloc(len_buf - i + 1, sizeof(char));
	if (!res)
		return (NULL);
	j = 0;
	while (buf[i + j] && i + j < len_buf)
	{
		res[j] = buf[i + j];
		j++;
	}
	buf[0] = 0;
	res[j] = 0;
	return (res);
}

void	ft_free_eof(ssize_t lu, char **line, char **reste, int f)
{
	if (lu < 1 && ft_strlen(*line) < 1)
	{
		free(*line);
		*line = NULL;
	}
	if (ft_strlen(*reste) < 1)
	{
		free(*reste);
		*reste = NULL;
	}
	if (*reste && !*line && **line == '\n')
		*line = get_next_line(f);
}

char	*get_next_line(int f)
{
	char		buf[BUFFER_SIZE + 1];
	ssize_t		lu;
	char		*line;
	static char	*reste;

	if (f < 0 || read(f, NULL, 0) < 0 || ft_init_check(&lu, &line, &reste))
		return (NULL);
	while (ft_search_end(&line) < 0 && lu > 0)
	{
		lu = read(f, buf, BUFFER_SIZE);
		if (lu < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buf[lu] = 0;
		ft_strcat(line, buf);
	}
	printf("lu = [%s]\n", line);
	ft_line(&line);
	printf("line = [%s]\n", line);
	printf("buffer = [%s]\n", buf);
	reste = ft_reste(buf);
	printf("reste = [%s]\n", reste);
	ft_free_eof(lu, &line, &reste, f);
	return (line);
}
