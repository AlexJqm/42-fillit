/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aljacque <aljacque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:19:17 by aljacque          #+#    #+#             */
/*   Updated: 2018/11/22 18:47:22 by aljacque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
	ASCII CODE
	# = 35 || . = 46 || \n = 10
*/

void			ft_printerror(fd);

static	void	ft_checkline(char *str, int nb_piece, int fd)
{
	int i;

	i = 0;
	while (str[i] != '\n')
	{
		/* Parcour la chaine temps que la valeur est egale a '#' ou '.' jusqu'a \n */
		if (str[i] == 35 || str[i] == 46)
			i++;
		/* Si le charactere est different de '#' ou '.' et que la line est > a 4 caracteres return error */
		if ((str[i] != 35 || str[i] != 46) && i != 4)
			ft_printerror(fd, 1);
	}
}

static	int		ft_countpiece(char *str)
{
	int nb_piece;

	nb_piece = 1;
	/* Lorsque le premier caractere de la ligne est \0, ajoute une piece */
	if (str[1] == '\0')
		nb_piece++;
	else if (nb_piece > 26)
		ft_checkerror(fd, 1);
	return (nb_piece);
}

int				ft_checkerror(char *file)
{
	char	*line;
	int		fd;
	int		nb_pieces;

	*line = NULL;
	if (fd = open(file, O_RDONLY) == -1)
		ft_printerror(fd, 2);
	while (get_next_line(fd, &line) == 1)
	{
		/* Verifie que la ligne contient uniquement des '#' '.'
		ET qu'elle ne contient que 4 caracteres. */
		ft_checkline(line, &nb_piece, fd);
		/* Calcule le nombre de pieces dans le fichier et
		retourne error si le nombre de pieces est trop grand */
		nb_piece += ft_countpiece(line);

	}
	close(fd);
	return (nb_piece);
}
