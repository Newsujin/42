/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 20:53:26 by spark2            #+#    #+#             */
/*   Updated: 2023/08/01 20:54:04 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "so_long.h"

int	main_loop(char **backup, int fd, ssize_t *rd_size)
{
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;

	while (ft_strchr(*backup, '\n') == -1)
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

	i = ft_strchr(*backup, '\n');
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

void	ft_free(char **backup, char **res)
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
		ft_free(&backup, &res);
	return (res);
}
