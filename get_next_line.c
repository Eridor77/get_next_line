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

char	*ft_strndup(const char *s, size_t length)
{
	char	*cpy;
	size_t	i;

	i = 0;
	if (length > ft_strlen(s))
		length = ft_strlen(s);
	cpy = (char *)malloc((length + 1) * sizeof(char));
	while (i != length)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

size_t	len(const char *str, char c)
{
	size_t	i;
	
	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

char	*ft_strcdup(const char *str, char c)
{
	char	*new;
	
	new = ft_strndup(str, len(str, c));
	return (new);
}

int		read_line(char **buf, int fd)
{
	char	buffer[BUFF_SIZE + 1];
	int		ret;
	
	ret = 1;
	while (ft_strstr(*buf, "\n") == 0 && ret != 0)
	{
		if ((ret = read(fd, buffer, BUFF_SIZE)) == -1)
			return (-1);
		buffer[ret] = '\0';
		*buf = ft_strjoin(*buf, buffer);
		ft_memset(buffer, 0, ret);
	}
	return (ret);
}

int		get_next_line(int const fd, char **line)
{
	static char	*buf;
	char	*tmp;
	int		ret;
	
	if (BUFF_SIZE >= MAX_SIZE_BUFFER || BUFF_SIZE <= 0 || fd == 1)
		return (-1);
	if ((ret = read_line(&buf, fd)) == -1)
		return (-1);
	*line = ft_strcdup(buf, '\n');	
	tmp = buf;
	buf = ft_strdup(buf + len(buf, '\n') + 1);	
	free(tmp);
	return (ret == 0) ? 0 : 1;
}