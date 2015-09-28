/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:47:40 by rlavallo          #+#    #+#             */
/*   Updated: 2015/09/28 16:36:47 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(int const fd, char *buff, char *str[fd])
{
	char		*new;
	char		*tmp;
	int			ret;

	while (!(new = ft_strchr(str[fd], '\n')) &&
			(ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str[fd];
		str[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	if (ret == -1)
		return (-1);
	if (!new && ret == 0)
		return (0);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str[1];
	char		*buff;
	char		*tmp;
	int			ret;

	buff = ft_strnew(BUFF_SIZE);
	if (fd < 0 || line == NULL || buff == NULL)
		return (-1);
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	ret = read_line(fd, buff, &*str);
	if (ret == -1)
		return (-1);
	if (ret == 0)
	{
		*line = str[fd];
		str[fd] = NULL;
		return (0);
	}
	*line = ft_strsub(str[fd], 0, (ft_strchr(str[fd], '\n') - str[fd]));
	tmp = str[fd];
	str[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}
