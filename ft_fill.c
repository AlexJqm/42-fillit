/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:57:35 by coremart          #+#    #+#             */
/*   Updated: 2018/11/25 13:15:26 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include "fillit.h"

/*
**	fill a tab of pieces
*/
t_piece		*ft_fill(char *file, int nb_pcs)
{
	t_piece	*num_pc;
	int		fd;
	int 	i;
	int 	j;

	fd = -1;
	if(!(num_pc = (t_piece*)malloc(sizeof(num_pc) * (nb_pcs + 1))))
		ft_print_error(fd, 1);
	num_pc[nb_pcs].piece[0][0] = '\0';
	i = 0;
	j = 0;
	if ((fd = open(file, O_RDONLY)) <= 0)
		ft_print_error(fd, 1);
	while (j < nb_pcs)
	{
		while (i < 4)
		{
			if (get_next_line(fd, (char**)&(num_pc[j].piece[i])) != 1)
				ft_print_error(fd, 1);
			i++;
		}
		i = 0;
		j++;
	}
	return(num_pc);
}
