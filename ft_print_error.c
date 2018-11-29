/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:08:33 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/28 17:05:27 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_print_error(int fd, int num)
{
	if (num == 1)
	{
		ft_color("error", "red");
		close(fd);
		exit(0);
	}
	else if (num == 2)
	{
		ft_color("usage: ./fillit source_file", "red");
		close(fd);
		exit(0);
	}
	else
	{
		close(fd);
		exit(0);
	}
}
