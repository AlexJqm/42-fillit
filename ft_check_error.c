/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:19:17 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/05 17:51:58 by coremart         ###   ########.fr       */
/*   Updated: 2018/11/28 17:01:20 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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

static void		pc_cpy(char dst[4][4], const char src[4][4])
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!src)
	{
		while (i < 4)
		{
			while (j < 4)
			{
				dst[i][j] = '\0';
				j++;
			}
			j = 0;
			i++;
		}
	}
	else
		while (i < 4)
		{
			while (j < 4)
			{
				dst[i][j] = src[i][j];
				j++;
			}
			j = 0;
			i++;
		}
}

static t_piece		*pc_add(t_piece *num_pc, char pc[4][4], int curr_size, int fd)
{
	t_piece *tmp;
	int i;

	tmp = num_pc;
	i = 0;
	if (!(num_pc = (t_piece*)malloc(sizeof(t_piece) * (curr_size + 1))))
		ft_print_error(fd, 1);
	while (i < curr_size)
	{
		pc_cpy(num_pc[i].piece, tmp[i].piece);
		i++;
	}
	pc_cpy(num_pc[i].piece, pc);
	return (num_pc);
}

t_piece		*ft_check_error(int fd)
{
	char	*line;
	int		nb_pieces;
	int		nb_lines;
	t_piece	*num_pc;
	char	curr_pc[4][4];

	nb_lines = 0;
	nb_pieces = 1;
	num_pc = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		ft_check_line(line, fd);
		ft_memcpy(curr_pc[nb_lines], line, 4);
		nb_lines++;
		if (nb_lines == 4)
		{
			num_pc = pc_add(num_pc, curr_pc, nb_pieces - 1, fd);
			nb_pieces++;
			if (get_next_line(fd, &line) == 1)
				(line[0]) ? ft_print_error(fd, 1) : (nb_lines = 0);
		}
	}
	num_pc = pc_add(num_pc, NULL, nb_pieces - 1, fd);
	if (nb_lines == 0 || nb_pieces > 26)
		ft_print_error(fd, 1);
	return (num_pc);
}
