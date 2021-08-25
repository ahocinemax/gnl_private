/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahocine <ahocine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 01:49:37 by ahocine           #+#    #+#             */
/*   Updated: 2021/07/01 01:49:42 by ahocine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2000
# endif

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

int		ft_init_check(ssize_t *lu, char **line, int *eol, char *buff);
char	*ft_free_eof(char *reste, ssize_t lu, char *line);
void	*ft_calloc(size_t number, size_t len);
void	*ft_memset(void *dest, int c, size_t len);
void	ft_strcat(char *dest, char *src);
char	*get_next_line(int fd);
void	ft_reste(char *buff);
void	ft_line(char **line);
int		ft_strlen(char *str);
int		ft_search_end(char **str);

#endif
