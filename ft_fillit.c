/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 16:07:48 by coremart          #+#    #+#             */
/*   Updated: 2018/12/07 16:46:58 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "includes/fillit.h"
#include <stdlib.h>
#include <stdio.h>

static char		**fill_with(char piece[4][4], const char **tab, size_t size, size_t pos)
{
	size_t i;
	size_t j;
	size_t k;
	size_t l;
	char **res;

	i = pos / 4;
	j = pos % 4;
	k = 0;
	l = 0;
	if (!(res = ft_tab_dup(tab, size)))
		return (NULL);
	while (k < 4)
	{
		while (l < 4)
		{
			if (piece[k][l] != '.')
			{
				if (i + k >= size || j + l >= size || res[i + k][j + l])
				{
					ft_free_tab(res, size);
					return (NULL);
				}
				res[i + k][j + l] = piece[k][l];
			}
			l++;
		}
		l = 0;
		k++;
	}
	return (res);
}

static int		is_fill(t_piece *tab, const char **res, size_t size, size_t pos)
{
	if (!tab->piece[0][0] && res)
	{
		ft_print_res(res, size);
		return (1);
	}
	if (!res || pos > size * size)
		return (0);
	return (is_fill(tab + 1, (const char **)fill_with(tab->piece, res, size, pos), size, 0) || is_fill(tab, res, size, pos + 1));
}

void	ft_fillit(t_piece *tab, int fd)
{
	size_t	size;
	size_t	i;
	size_t	res_size;
	char	**res;

	size = ft_tab_size(tab);
	res_size = ft_next_sqrt(size * 4);
	i = 0;
	while (1)
	{
		if (!(res = (char**)malloc(sizeof(char*) * res_size)))
			ft_print_error(fd, 1);
		while (i < res_size)
		{
			if (!(res[i] = (char*)malloc(res_size)))
				ft_print_error(fd, 1);
			ft_bzero(res[i++], res_size);
		}
		if (is_fill(tab, (const char **)res, res_size, 0))
			break;
		i = 0;
		while (i < res_size)
			free(res[i++]);
		free(res);
		i = 0;
		res_size++;
	}
}
