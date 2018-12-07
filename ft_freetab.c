/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:33:57 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/07 14:40:35 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"

void	ft_freetab(char **tab, size_t size)
{
	int	i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
	tab = NULL;
}
