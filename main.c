/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <coremart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:01:03 by coremart          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2018/11/29 11:12:45 by coremart         ###   ########.fr       */
=======
/*   Updated: 2018/11/28 17:05:18 by aljacque         ###   ########.fr       */
>>>>>>> 9943acf84cd3eb5708e3517cca7c78cf5d16ac56
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
<<<<<<< HEAD
	ft_print_tab(ft_check_error(av[1]));
=======
	if (!(nb_pcs = ft_check_error(av[1])))
	{
		ft_color("error", "red");
		return (0);
	}
	/*ft_print_tab(ft_fillit(av[1], nb_pcs));*/
>>>>>>> 9943acf84cd3eb5708e3517cca7c78cf5d16ac56
	return (0);
}
