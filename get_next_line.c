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

int	ft_init_check(ssize_t *lu, char **line, int *eol, char *buff)
{
	*line = (char *)ft_calloc((86 + 1), sizeof(char));
	if (!line)
		return (-1);
	*lu = 1;
	*eol = -1;
	ft_strcat(*line, buff);
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

void	ft_reste(char *buff)
{
	int		i;
	int		j;

	if (!buff)
		return ;
	i = ft_search_end(&buff);
	if (i < 0)
		i = ft_strlen(buff);
	while (buff[i] && buff[i] == '\n')
		i++;
	j = 0;
	while (buff[i + j])
	{
		buff[j] = buff[i + j];
		j++;
	}
	buff[j] = 0;
}

char	*ft_free_eof(char *buff, ssize_t lu, char *line)
{
	if (lu < 1 && !ft_strlen(line) && !ft_strlen(buff))
	{
		free(line);
		line = NULL;
		printf("eof reached\n");
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{


	static char	buff[BUFFER_SIZE + 1];
	ssize_t		lu;
	char		*line;
	int			eol;

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE < 1 || \
		ft_init_check(&lu, &line, &eol, buff))
	{
		free(line);
		line = NULL;
		return (NULL);
	}
	while (eol < 0 && lu > 0)
	{
		lu = read(fd, buff, BUFFER_SIZE);
		if (lu < 0)
		{
			free(line);
			line = NULL;
			return (NULL);
		}
		buff[lu] = 0;
		ft_strcat(line, buff);
		eol = ft_search_end(&line);
	}
	ft_line(&line);
	ft_reste(buff);
	line = ft_free_eof(buff, lu, line);
//	printf("curr : %s\n", line);
	return (line);
}
