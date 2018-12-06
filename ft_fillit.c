/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:07:48 by coremart          #+#    #+#             */
/*   Updated: 2018/12/06 17:36:56 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>

static int	is_fill(t_piece *tab, char **res, size_t size, int pos)
{
	if (!tab.piece[0][0])
		return (1);
	if (!fill_with(tab.piece, res, size, pos))
		return (is_fill(tab + 1, res, size, pos));
	else
		return (is_fill(tab, res, size, pos));
	if (pos == size * size)
	else if (pos = size * size)
		return (0);
	return (is_fill(tab, res, size, pos + 1));
}

char		**ft_fillit(t_piece *tab)
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
			ft_print_error(fd, 1);
		while (i < res_size)
		{
			if (!(res[i++] = (char*)malloc(res_size)))
				ft_print_error(fd, 1);
			while (j < res_size)
				res[i][j++] = 0;
			j = 0;
		}
		if (is_fill(tab, res, res_size++, 0))
			break;
		i = 0;
		j = 0;
		while (i < res_size)
			free(res[i++]);
		free(res);
		i = 0;
	}
}
