/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2dim_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:58:42 by coremart          #+#    #+#             */
/*   Updated: 2018/12/07 17:30:57 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"

void	**ft_2dim_realloc(void **tab, size_t cur_size, size_t new_size)
{
	size_t			i;
	unsigned char	**res;

	i = -1;
	if (!(res = (unsigned char**)malloc(sizeof(unsigned char*) * new_size)))
		return (NULL);
	while (++i < cur_size)
		if (!(res[i] = ft_realloc(*((unsigned char**)tab + i),
		cur_size, new_size)))
			return (NULL);
	free(tab);
	return ((void**)res);
}
