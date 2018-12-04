/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
/*   Updated: 2018/12/04 14:26:22 by coremart         ###   ########.fr       */
/*   Updated: 2018/11/28 17:05:18 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_color("usage: ./fillit source_file", "red");
		return (0);
	}
	ft_print_tab(ft_check_error(av[1]));
	return (0);
}
