/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 19:00:34 by rlavallo          #+#    #+#             */
/*   Updated: 2014/11/19 15:37:36 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	*str;
	
	if (argc == 2)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	while(1)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1)
		{
			ft_putendl("Error");
			return(0);
		}
		ft_putendl(str);
		if (ret == 0)
			return (0);
	}
	return (0);
}