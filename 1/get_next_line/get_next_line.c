/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 16:19:33 by spark2            #+#    #+#             */
/*   Updated: 2023/04/21 20:45:07 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> //puts

void	ft_free(char **backup)
{
	free(*backup);
	*backup = 0;
}
//buffer: 데이터 임시 저장 공간
char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	char		*tmp;
	static char	*backup;
	int			i;
	ssize_t		rd_size;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	rd_size = read(fd, buf, BUFFER_SIZE);
	if (rd_size <= 0)
		return (NULL);
	if (!backup) // 존재하는 백업이 있는지 확인
	{
		backup = ft_strdup("");
		if (!backup) // 널가드
			return (0);
	}
	buf[rd_size] = '\0';
	backup = ft_strjoin_gnl(backup, buf);
	if (!backup)
	{
		ft_free(&backup);
		return (0);
	}
	while (1) //if '\n' does not exist in backup
	{
		rd_size = read(fd, buf, BUFFER_SIZE); //rd_size에 따른 처리하기 (음수 or 0)!!!!!!
		buf[rd_size] = '\0';
		tmp = backup;
		backup = ft_strjoin_gnl(tmp, buf);
		ft_free(&tmp);
		if (!backup)
		{
			return (0);
		}
		if (ft_strchr(buf, '\n') != -1)
			break ;
		if (rd_size <= 0) //nothing more to read or error
			break ;
	}
	i = ft_strchr(backup, '\n'); //find '\n' index
	if (i == -1) //if '\n' does not exist in whole line
		i = ft_strchr(backup, '\0') - 1; //i points to the end
	// printf("i: %d\n", i);
	res = ft_substr(backup, 0, i + 1); //copy until '\n' from backup to res
	// printf("res: %s\n", res);
	if (!res)
	{
		// ft_free(&res);
		return (0);
	}
	backup = ft_substr(backup, i + 1, ft_strlen(backup) - (i + 1)); //copy after '\n' from backup to backup
	if (!backup)
	{
		// ft_free(&backup);
		return (0);
	}
	if (rd_size == 0 && backup[0] == '\0') //문장 끝이거나 백업이 비어 있음
		ft_free(&backup);
	return (res);
}
