/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:38:29 by coremart          #+#    #+#             */
/*   Updated: 2018/11/22 18:11:55 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct	s_piece
{
	char	piece[4][4];
}				t_piece;

int		ft_check_error(char *file);
void		ft_print_error(int fd, int num;
void		ft_fillit(char *file, int nb_pcs);

#endif
