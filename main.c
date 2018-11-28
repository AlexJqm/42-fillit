/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
/*   Updated: 2018/11/28 13:18:37 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"

#include <unistd.h>

int		main(int ac, char **av)
{
	int		nb_pcs;

	if (ac != 2)
	{
		write(1, "OK\n", 3);
		ft_color("usage: ./fillit source_file", "red");
		ft_putchar('\n');
		return (0);
	}
	if (!(nb_pcs = ft_check_error(av[1])))
	{
		write(1, "OK\n", 3);
		ft_color("error", "red");
		ft_putchar('\n');
		return (0);
	}
	write(1, "OK\n", 3);
	ft_print_tab(ft_fillit(av[1], nb_pcs));
	return (0);
}
