/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:38:29 by coremart          #+#    #+#             */
/*   Updated: 2018/11/25 11:44:31 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define BUFF_SIZE 100

typedef struct	s_piece
{
	char	piece[4][4];
}				t_piece;

int			ft_check_error(char *file);
void		ft_print_error(int fd, int num);
t_piece		*ft_fill(char *file, int nb_pcs);
int			get_next_line(const int fd, char **line);
void		ft_print_tab(t_piece *tab);

#endif
