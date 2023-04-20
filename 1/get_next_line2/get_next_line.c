/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:19:33 by spark2            #+#    #+#             */
/*   Updated: 2023/04/20 21:57:10 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //puts

void	ft_free(char **backup)
{
	free(*backup);
	(*backup)[0] = 0;
}
//buffer: 데이터 임시 저장 공간
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	static char	*backup;
	int			i;
	ssize_t		rd_size;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);

	if (!backup) // 존재하는 백업이 있는지 확인
	{
		backup = ft_strdup("");
		if (!backup) // 널가드
			return (0);
	}
	if (ft_strchr(backup, '\n') != -1)
	{
		// 잘라서 담고
		// backup 은 개행 이후만 남기고
		// 담아둔거 반환
	}

	// rd_size = read(fd, buf, BUFFER_SIZE);
	// if (rd_size <= 0)
	// 	return (NULL);
	// buf[rd_size] = '\0';
	// backup = ft_strjoin_gnl(backup, buf);
	// if (!backup)
	// {
	// 	ft_free(&backup);
	// 	return (0);
	// }
	while (ft_strchr(backup, '\n') == -1) //if '\n' does not exist in backup
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		buf[rd_size] = '\0';
		backup = ft_strjoin_gnl(backup, buf);
		if (!backup)
		{
			ft_free(&backup);
			return (0);
		}
		if (rd_size == 0) //nothing more to read
			break ;
	}
	i = ft_strchr(backup, '\n'); //find '\n' index
	if (i == -1) //if '\n' does not exist in whole line
		i = ft_strchr(backup, '\0'); //i points to the end
	// printf("i: %d\n", i);
	res = ft_substr(backup, 0, i + 1); //copy until '\n' from backup to res
	if (!res)
	{
		ft_free(&res);
		return (0);
	}
	backup = ft_substr(backup, i + 1, ft_strlen(backup) - (i + 1)); //copy after '\n' from backup to backup
	if (!backup)
	{
		ft_free(&backup);
		return (0);
	}
	if (rd_size == 0 && backup[0] == '\0') //문장 끝이거나 백업이 비어 있음
		ft_free(&backup);
	return (res);
}
