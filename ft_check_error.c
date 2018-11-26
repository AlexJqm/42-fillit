/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:19:17 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/26 12:05:12 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	void	ft_check_line(char *str, int fd)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] == 35 || str[i] == 46)
			i++;
		if ((str[i] != 35 || str[i] != 46) && i != 4)
			ft_print_error(fd, 1);
	}
}

static	int		ft_count_piece(char *str, int nb_lines, int fd)
{
	int nb_piece;

	nb_piece = 1;
	if (str[1] == '\0')
	{
		nb_piece++;
		nb_lines = 0;
	}
	if (str[1] != '\0' || nb_piece > 26)
		ft_print_error(fd, 1);
	return (nb_piece);
}

int				ft_check_error(char *file)
{
	char	*line;
	int		fd;
	int		nb_pieces;
	int 	nb_lines;

	*line = NULL;
	nb_lines = -1;
	if (fd = open(file, O_RDONLY) == -1)
		ft_print_error(fd, 2);
	while (get_next_line(fd, &line) == 1)
	{
		while (nb_lines++ <= 4)
			ft_check_line(line, fd);
		nb_piece += ft_count_piece(line, &nb_lines, fd);
	}
	close(fd);
	return (nb_piece);
}
