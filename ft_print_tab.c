/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:36:12 by coremart          #+#    #+#             */
/*   Updated: 2018/11/28 16:29:10 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <unistd.h>

#include <stdio.h>
#include <stdlib.h>

static void		ft_print_pc(t_piece pc)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= 4)
	{
		while (j <= 4)
		{
			write(1, &(pc.piece[i][j]), 1);
			j++;
		}
		j = 0;
		i++;
	}
}

void			ft_print_tab(t_piece *tab)
{
	printf("OK\n");
	exit(0);
	int i;

	i = 0;
	while (tab[i].piece[0])
	{
		ft_print_pc(tab[i]);
		write(1, "\n", 1);
		i++;
	}
}
