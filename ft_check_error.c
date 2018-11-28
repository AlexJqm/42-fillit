/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:19:17 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/28 17:01:20 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <fcntl.h>
#include <unistd.h>

static void		ft_check_line(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 35 && str[i] != 46)
			ft_print_error(fd, 1);
		i++;
	}
	if (i != 4)
		ft_print_error(fd, 1);
}

int				ft_check_error(char *file)
{
	char	*line = NULL;
	int		fd;
	int		nb_pieces;
	int		nb_lines;
	/*t_pieces	*num_pc;*/

	nb_lines = 0;
	nb_pieces = 1;
	if ((fd = open(file, O_RDONLY)) == -1)
		ft_print_error(fd, 2);
	while (get_next_line(fd, &line) == 1)
	{
		if (nb_lines == 4 && line[0] == '\0')
		{
			nb_lines = -1;
			nb_pieces++;
		}
		else if (nb_lines == 4)
			ft_print_error(fd, 1);
		else
		{
			ft_check_line(line, fd);
/*			if(!(ft_strdup(num_pc[nb_pcs - 1].pieces[nb_lines], line))
				ft_print_error(fd, 1);*/
		}
		nb_lines++;
	}
	if (nb_lines == 0 || nb_pieces > 26)
		ft_print_error(fd, 1);
	close(fd);
	return (nb_pieces);
}
