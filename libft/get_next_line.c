/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcremin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 15:22:13 by jcremin           #+#    #+#             */
/*   Updated: 2019/04/30 12:52:21 by jcremin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		valid_next_line(char **bank_line, char **line)
{
	char		*trash;

	if ((*bank_line)[0] == '\0')
		return (0);
	if (ft_strchr(*bank_line, '\n') != NULL)
	{
		*(ft_strchr(*bank_line, '\n')) = '\0';
		*line = ft_strdup(*bank_line);
		trash = ft_strdup(ft_strchr(*bank_line, '\0') + 1);
		free(*bank_line);
		if (trash)
		{
			*bank_line = ft_strdup(trash);
			free(trash);
		}
	}
	else
	{
		*line = ft_strdup(*bank_line);
		ft_memdel((void **)bank_line);
	}
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	int			br;
	char		buf[BUFF_SIZE + 1];
	static char	*bank[MAX_FD];
	char		*trash;

	if (fd == -1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!bank[fd])
		bank[fd] = ft_strnew(0);
	while (ft_strchr(bank[fd], '\n') == NULL)
	{
		br = read(fd, buf, BUFF_SIZE);
		buf[br] = '\0';
		if (br == 0)
			break ;
		trash = ft_strjoin(bank[fd], buf);
		free(bank[fd]);
		bank[fd] = ft_strdup(trash);
		if (!bank[fd])
			bank[fd] = ft_strnew(0);
		free(trash);
	}
	return (valid_next_line(&bank[fd], line));
}
