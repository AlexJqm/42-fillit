/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:08:33 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/22 18:13:14 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_printerror(int fd, int num)
{
	if (num == 1)
	{
		write(1, "error\n", 6);
		close(fd);
		exit(0);
	}
	else if (num == 2)
	{
		write(-1, "usage: ./fillit source_file\n", 28);
		close(fd);
		exit(0);
	}
	else
	{
		close(fd);
		exit(0);
	}
}
