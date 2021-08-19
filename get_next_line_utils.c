/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 01:49:51 by ahocine           #+#    #+#             */
/*   Updated: 2021/07/01 01:49:53 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = 0;
	return (dest);
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
	curr_line = (char *)calloc(len + 1, sizeof(char));
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
	reste = (char *)calloc(ft_strlen(tmp) - i + 1, sizeof(char));
	if (!reste)
		return (NULL);
	j = 0;
	while (tmp[i] && tmp[i] != '\n')
		reste[j++] = tmp[i++];
	reste[j] = 0;
	free(tmp);
	return (reste);
}

int	ft_search_end(char *str)
{
	ssize_t	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (i);
			i++;
		}
	}
	return (0);
}
