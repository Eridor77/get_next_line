/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlavallo <rlavallo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/15 18:47:59 by rlavallo          #+#    #+#             */
/*   Updated: 2014/11/19 18:11:25 by rlavallo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# define BUFF_SIZE 32
# define MAX_SIZE_BUFFER 8000000

# include "libft/includes/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int const fd, char **line);

#endif
