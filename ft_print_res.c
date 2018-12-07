/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_res.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 15:09:14 by coremart          #+#    #+#             */
/*   Updated: 2018/12/07 15:53:30 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include <unistd.h>

void	ft_print_res(const char **tab, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			write(1, &tab[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}
