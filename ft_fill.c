/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:57:35 by coremart          #+#    #+#             */
/*   Updated: 2018/11/22 18:35:45 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fillit.h"

/*
**	fill a tab of pieces
*/
t_piece		**ft_fillit(char *file, int nb_pcs)
{
	t_piece		*num_pc[nb_pcs + 1];
	int		fd;
	int		i;
	int		j;

	tab[nb_pcs] = NULL;
	i = 0;
	j = 0;
	if ((fd = open(file, O_RDONLY)) <= 0)
		ft_print_error(fd, 1);
	while (j < nb_pcs)
	{
		while (i < 4)
		{
			if (get_next_line(fd, &(num_pc[j]->piece[i])) != 1)
				ft_print_error(fd, 1);
			i++;
		}
		j++;
	}
	return(num_pc);
}
