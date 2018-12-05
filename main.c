/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
/*   Updated: 2018/12/05 17:56:03 by coremart         ###   ########.fr       */
/*   Updated: 2018/11/28 17:05:18 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int fd;
	if (ac != 2)
	{
		ft_color("usage: ./fillit source_file", "red");
		return (0);
	}
	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_print_error(fd, 2);
	ft_print_tab(ft_check_error(fd));
	return (0);
}
