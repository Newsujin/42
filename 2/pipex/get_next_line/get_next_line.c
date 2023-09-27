/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:53:26 by spark2            #+#    #+#             */
/*   Updated: 2023/09/27 20:45:36 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main_loop(char **backup, int fd, ssize_t *rd_size)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	while (ft_gnl_strchr(*backup, '\n') == -1)
	{
		*rd_size = read(fd, buf, BUFFER_SIZE);
		if (*rd_size == -1)
		{
			free(*backup);
			*backup = NULL;
			return (1);
		}
		if (*rd_size == 0)
			break ;
		buf[*rd_size] = 0;
		tmp = *backup;
		*backup = ft_strjoin(tmp, buf);
		free(tmp);
		if (!(*backup))
			return (1);
	}
	return (0);
}

int	split_line(char **backup, char **res)
{
	ssize_t	i;
	char	*tmp;

	i = ft_gnl_strchr(*backup, '\n');
	if (i == -1)
		i = ft_strlen(*backup);
	*res = ft_substr(*backup, 0, i + 1);
	if (!(*res))
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = *backup;
	*backup = ft_substr(tmp, i + 1, ft_strlen(tmp) - (i + 1));
	if (!(*backup))
	{
		free(*res);
		free(tmp);
		return (1);
	}
	else
		free(tmp);
	return (0);
}

void	ft_free_gnl(char **backup, char **res)
{
	free(*backup);
	*backup = NULL;
	if (**res == '\0')
	{
		free(*res);
		*res = NULL;
	}
}

char	*get_next_line(int fd)
{
	ssize_t		rd_size;
	static char	*backup;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	if (main_loop(&backup, fd, &rd_size))
		return (NULL);
	if (split_line(&backup, &res))
		return (NULL);
	if (rd_size == 0 && *backup == '\0')
		ft_free_gnl(&backup, &res);
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <fcntl.h>
// int	main(int argc, char **argv)
// {
// 	char *gnl;
// 	int	fd;
// 	fd = open("hd_infile", O_CREAT | O_WRONLY | O_TRUNC, 0644);
// 	if (fd == -1)
// 		perror("파일 열기 실패");
// 	while (1)
// 	{
// 		gnl = get_next_line(0);
// 		if (!ft_strncmp(argv[2], gnl, ft_strlen(argv[2])))
// 			break ;
// 		write(fd, gnl, ft_strlen(gnl));
// 		printf("res: %s", gnl);
// 	}
// }
