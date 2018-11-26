/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:19:17 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/26 11:50:45 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	ASCII CODE
	# = 35 || . = 46 || \n = 10
*/

static	void	ft_check_line(char *str, int nb_lines int fd)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		/* Parcour la chaine temps que la valeur est egale a '#' ou '.' jusqu'a \n */
		if (str[i] == 35 || str[i] == 46)
			i++;
		/* Si le charactere est different de '#' ou '.' et que le nb line est > a 4 caracteres return error */
		if ((str[i] != 35 || str[i] != 46) && i != 4)
			ft_print_error(fd, 1);
	}
	nb_lines++;
}

static	int		ft_count_piece(char *str, int nb_lines)
{
	int nb_piece;

	nb_piece = 1;
	/* Lorsque le premier caractere de la ligne est \0, ajoute une piece */
	if (str[1] == '\0' && nb_lines == 4)
		nb_piece++;
	else if (nb_piece > 26 || nb_lines > 4)
		ft_print_error(fd, 1);
	return (nb_piece);
}

int				ft_check_error(char *file)
{
	char	*line;
	int		fd;
	int		nb_pieces;
	int		nb_lines;

	*line = NULL;
	if (fd = open(file, O_RDONLY) == -1)
		ft_print_error(fd, 2);
	while (get_next_line(fd, &line) == 1)
	{
		/* Verifie que la ligne contient uniquement des '#' '.'
		ET qu'elle ne contient que 4 caracteres. */
		ft_check_line(line, &nb_lines, fd);
		/* Calcule le nombre de pieces dans le fichier et
		retourne error si le nombre de pieces est trop eleves */
		nb_piece += ft_count_piece(line, nb_lines);

	}
	close(fd);
	return (nb_piece);
}
