/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:09:14 by coremart          #+#    #+#             */
/*   Updated: 2018/12/07 16:05:10 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <unistd.h>
#include <stdio.h>

void	ft_print_res(const char **tab, size_t size)
{
	size_t i;
	size_t j;
	char point;

	i = 0;
	j = 0;
	point = '.';
	while (i < size)
	{
		while (j < size)
		{
			printf("j :%zu\n", j);
			if (tab[i][j])
				write(1, &tab[i][j], 1);
			else
				write(1, &point, 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
