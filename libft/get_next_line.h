/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrambelo <mrambelo@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:50:40 by mrambelo          #+#    #+#             */
/*   Updated: 2025/02/06 09:03:27 by mrambelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_strchr_g(const char *str, int searchChar);
char	*check_and_fill_new_line(char *line_static, int len);
char	*fill_line_static(char *line_static, int fd, char *buffer);
char	*helper(char *stat, char *buff);
char	*ft_strjoin_g(char const *s1, char const *s2);
size_t	ft_strlen_g(const char *str);
void	*ft_calloc(size_t elementCount, size_t elementSize);

#endif
