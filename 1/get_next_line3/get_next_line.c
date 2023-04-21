#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h> //open

// int	main()
// {
// 	int		fd;
// 	char	*line;

// 	fd = open("text.txt", O_RDONLY);
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		printf("%s", line);
// 	}
// 	return (0);
// }

//backup, res에 개행 기준으로 나눠 담기
void	split_line(char **backup, char **res)
{
	int	i;

	i = ft_strchr(*backup, '\n'); //find '\n' index
	if (i == -1) //if '\n' does not exist in whole line
		i = ft_strlen(*backup); //i points to the end
	// printf("i: %d\n", i);
	*res = ft_substr(*backup, 0, i + 1); //copy until '\n' from backup to res
	if (!res)
	{
		free(res);
		*res = 0;
	}
	*backup = ft_substr(*backup, i + 1, ft_strlen(*backup) - (i + 1)); //copy after '\n' from backup to backup
	if (!backup)
	{
		free(backup);
		*backup = 0;
	}
}

char	*get_next_line(fd)
{
	int			rd_size;
	static char	*backup;
	char		buf[BUFFER_SIZE + 1];
	char		*res;
	char		*tmp;

	//예외처리
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	//backup 비어 있을 때
	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup) //널 가드
			return (NULL);
	}

	//backup에 개행이 있다면 개행 전후 backup, res에 각각 저장 후 반환
	if (ft_strchr(backup, '\n') != -1)
	{
		split_line(&backup, &res);
		return (res);
	}

	//backup에 개행이 없는 동안 buffer_size만큼 읽고 backup에 붙이기
	while (ft_strchr(backup, '\n') == -1)
	{
		rd_size = read(fd, buf, BUFFER_SIZE);
		if (rd_size < 0) //read 에러
			break ;
		if (rd_size == 0) //EOF
			break ;
		buf[rd_size] = 0;
		tmp = backup;
		backup = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (!backup)
			return (NULL);
	}

	split_line(&backup, &res);

	//EOF or empty backup
	if (rd_size == 0 && *backup == '\0')
	{
		free(backup);
		backup = NULL;
		res = 0;
	}
	return (res);
}
