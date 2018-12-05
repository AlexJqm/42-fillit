/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:07:48 by coremart          #+#    #+#             */
/*   Updated: 2018/12/05 17:53:23 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>

char	**ft_fillit(t_piece *tab)
{
	size_t	size;
	size_t	i;
	size_t	j;
	size_t	res_size;	
	char	**res;

	size = ft_tab_size(tab);
	res_size = ft_next_sqrt(size);
	i = 0;
	j = 0;
	while (1)
	{
		if (!(res = (char**)malloc(sizeof(char*) * res_size)))
			ft_print_error(-1, 1);
		while (i < res_size)
		{
			if (!(res[i++] = (char*)malloc(res_size)))
				ft_print_error(-1, 1);
			while (j < res_size)
				res[i][j++] = 0;
			j = 0;
		}
		if (is_fill(tab, res, res_size++))
			break;
		i = 0;
		j = 0;
		while (i < res_size)
			free(res[i++]);
		free(res);
		i = 0;
	}
}
