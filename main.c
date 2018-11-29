/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
/*   Updated: 2018/11/29 11:12:45 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"

#include <unistd.h>

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_color("usage: ./fillit source_file", "red");
		ft_putchar('\n');
		return (0);
	}
	ft_print_tab(ft_check_error(av[1]));
	return (0);
}
