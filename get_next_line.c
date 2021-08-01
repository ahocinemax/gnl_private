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

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_search_end(char *str)
{
	ssize_t	i;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			return (i);
	return (0);
}

/*static void	ft_print_int(char *buff, ssize_t lu, int eol)
{
	write(1, "buff = ", 8);
	ft_putstr(buff);
	write(1, "\n", 1);
	write(1, "lu = ", 6);
	ft_putnbr_fd(lu, 1);
	write(1, " eol = ", 7);
	ft_putnbr_fd(eol, 1);
	write(1, "\n", 1);
}*/

/*void	ft_read_and_join(char **buff, char **curr_line)
{
	;
}*/

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
//	curr_line = (char *)calloc(BUFFER_SIZE + 1, sizeof(char));
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
	free(buff);
	
	return (curr_line);
}

int	main(void)
{
	int		fd;
	char	*ret;
	int		i = 1;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		printf("\e[31mError: open failed\e[0m\n");
	else
	{
		ret = get_next_line(fd);
		printf("%d line : %s\n", i++, ret);
		ret = get_next_line(fd);
		printf("%d line : %s\n", i++, ret);
		ret = get_next_line(fd);
		printf("%d line : %s\n", i++, ret);
		}
	return (0);
}
