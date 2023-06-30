/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ik_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spark2 <spark2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 21:36:41 by spark2            #+#    #+#             */
/*   Updated: 2023/06/30 21:38:29 by spark2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	my_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	src_len;

	src_len = 0;
	while (*(src + src_len))
		src_len++;
	if (dstsize == 0)
		return (src_len);
	i = 0;
	while (*(src + i) && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	**make_wdspace(char **arv, int *wdcnt, int arc, int *i)
{
	char	**res;
	int		j;
	int		flag;

	*wdcnt = 0;
	while (++(*i) < arc)
	{
		j = 0;
		flag = 0;
		while (arv[*i][j])
		{
			if (arv[*i][j] != ' ')
			{
				(*wdcnt)++;
				while (arv[*i][j] != ' ' && arv[*i][j])
					j++;
				flag = 1;
				continue ;
			}
			j++;
		}
		if (flag == 0)
			return (NULL);
	}
	res = malloc(sizeof(char *) * (*wdcnt + 1));
	res[*wdcnt] = 0;
	return (res);
}

char	**make_chspace(char **arv, char **res, int *wd_idx, int arc)
{
	int	i;
	int	ch_len;

	i = 0;
	while (++i < arc)
	{
		ch_len = 0;
		while (arv[i][ch_len])
		{
			if (arv[i][ch_len] != ' ')
			{
				while (arv[i][ch_len] != ' ' && arv[i][ch_len])
					ch_len++;
				res[*wd_idx] = malloc(sizeof(char) * (ch_len + 1));
				my_strlcpy(res[(*wd_idx)++], arv[i], ch_len + 1);
				if (arv[i][ch_len] == ' ')
					ch_len++;
				arv[i] += ch_len;
				ch_len = 0;
				continue ;
			}
			ch_len++;
		}
	}
	return (res);
}

char	**arv_split_space(char **arv, int *arc)
{
	char	**res;
	int		i;
	int		wdcnt;
	int		wd_idx;

	i = 0;
	res = make_wdspace(arv, &wdcnt, *arc, &i);
	if (res == 0)
		return (NULL);
	wd_idx = 0;
	res = make_chspace(arv, res, &wd_idx, *arc);
	if (res == 0)
	{
		while (wd_idx >= 0)
			free(res[wd_idx--]);
		free(res);
		return (NULL);
	}
	*arc = wdcnt;
	return (res);
}