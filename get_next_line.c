/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:47:40 by rlavallo          #+#    #+#             */
/*   Updated: 2014/11/19 18:13:13 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		read_line(int const fd, char *buff, char *str[fd])
{
	char		*new;
	char		*tmp;
	int			ret;
	
	// Looping until finding '\n' or end of file
	while (!(new = ft_strchr(str[fd], '\n')) && (ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = str[fd];
		// Joining new string to previous one
		str[fd] = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
	// Checking error and end of file
	if (ret == -1)
		return (-1);
	if (!new && ret == 0)
		return (0);
}

int		get_next_line(int const fd, char **line)
{
	static char	*str[1];
	char		*buff;
	char		*tmp;
	int			ret;
	
	// Buffer creation
	buff = ft_strnew(BUFF_SIZE);
	// Checking parameters
	if (fd < 0 || line == NULL || buff == NULL)
		return (-1);
	// Checking if str is existing on the given file descriptor and allocatinf if not
	if (str[fd] == NULL)
		str[fd] = ft_strnew(1);
	// Reading the line
	ret = read_line(fd, buff, &*str);
	// Checking error
	if (ret == -1)
		return (-1);
	// Checking end of file
	if (ret == 0)
	{
		// Returning line read
		*line = str[fd];
		str[fd] = NULL;
		return (0);
	}
	// Saving content before '\n'
	*line = ft_strsub(str[fd], 0, (ft_strchr(str[fd], '\n') - str[fd]));
	tmp = str[fd];
	// Saving content after '\n'
	str[fd] = ft_strdup(ft_strchr(tmp, '\n') + 1);
	ft_strdel(&tmp);
	return (1);
}