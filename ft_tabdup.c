/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:41:18 by aljacque          #+#    #+#             */
/*   Updated: 2018/12/07 15:11:12 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_tabdup(char **tab, size_t size)
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
