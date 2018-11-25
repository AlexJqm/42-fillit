/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
/*   Updated: 2018/11/25 11:44:47 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "fillit.h"

int		main(int ac, char **av)
{
	int		nb_pcs;

	if (ac != 2)
	{
		write(-1, "usage: ./fillit source_file\n", 28);
		return (0);
	}
	if (!(nb_pcs = ft_check_error(av[1])))
	{
		write(-1, "error\n", 6);
		return (0);
	}
	ft_print_tab(ft_fill(av[1], nb_pcs));
	return (0);
}
