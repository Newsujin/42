/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 15:33:49 by spark2            #+#    #+#             */
/*   Updated: 2023/05/16 20:50:24 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		main_loop(char **backup, int fd, ssize_t *rd_size);
int		split_line(char **backup, char **res);
void	ft_free(char **backup, char **res);
char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
ssize_t	ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strdup(const char *src);
char	*ft_strjoin(char *s1, char const *s2);

#endif