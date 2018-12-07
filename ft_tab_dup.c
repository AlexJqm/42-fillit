/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_dup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:41:18 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/07 15:12:21 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

char	**ft_tab_dup(char **tab, size_t size)
{
	char **res;
	size_t i;

	i = 0;
	if (!(res = (char**)malloc(sizeof(char*) * size)))
		return (0);
	while (i < size)
		res = ft_memdup(tab[i++], size);
	return (res)
}
