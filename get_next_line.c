/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coremart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 17:20:49 by coremart          #+#    #+#             */
/*   Updated: 2018/11/29 14:32:26 by coremart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fillit.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>

static t_list	*ft_get_fd(t_list **lst, const int fd)
{
	t_list		*tmp;

	tmp = *lst;
	if (!*lst)
		return ((*lst = ft_lstnew("\0", (size_t)fd)));
	while (1)
	{
		if (tmp->content_size == (size_t)fd)
			return (tmp);
		if (!tmp->next)
			break ;
		tmp = tmp->next;
	}
	return ((tmp->next = ft_lstnew("\0", (size_t)fd)));
}

static char		*ft_cpyfromcr(char *str)
{
	char	*tmp;

	tmp = str;
	if (!(str = ft_strdup(ft_strchr(tmp, '\n') + 1)))
		return (NULL);
	free(tmp);
	return (str);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_list			*cur;
	char			buff[BUFF_SIZE + 1];
	ssize_t			rd;
	char			*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 0 || read(fd, buff, 0) < 0)
		return (-1);
	cur = ft_get_fd(&lst, fd);
	while (!ft_strchr((cur->content) ? cur->content : "\0", '\n') &&
			(rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		tmp = cur->content;
		if (!(cur->content = ft_strjoin(tmp, buff)))
			return (-1);
		free(tmp);
	}
	if (!cur->content || !ft_strlen(cur->content))
		return (0);
	if (!(*line = ft_strndup(cur->content, ft_strclen(cur->content, '\n'))))
		return (-1);
	if (!ft_strchr(cur->content, '\n'))
		ft_strdel((char**)&cur->content);
	else
		if (!(cur->content = ft_cpyfromcr(cur->content)))
			return (-1);
	return (1);
}
