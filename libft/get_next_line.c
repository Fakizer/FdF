/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvlasenk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 11:36:36 by vvlasenk          #+#    #+#             */
/*   Updated: 2016/12/05 11:36:37 by vvlasenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*box = NULL;
	t_gnl			*buf;
	char			*mas;
	int				col;

	if (fd < 0 || !(mas = ft_memalloc(BUFF_SIZE)))
		return (-1);
	if ((col = read(fd, mas, 0)) < 0)
		return (-1);
	if (!(box))
		box = ft_list(box, fd);
	buf = ft_list(box, fd);
	while ((col = read(fd, mas, BUFF_SIZE) > 0))
	{
		if (ft_up_buf(&buf->str))
			return (-1);
		ft_strncat(buf->str, mas, BUFF_SIZE);
		ft_bzero(mas, BUFF_SIZE);
		if (ft_strchr(buf->str, '\n'))
			break ;
	}
	ft_strdel(&mas);
	return (ft_strok(&buf->str, line));
}

t_gnl	*ft_list(t_gnl *list, int fd)
{
	t_gnl *buf_list;
	t_gnl *mas;

	if (list == NULL)
	{
		list = (t_gnl*)malloc(sizeof(*list));
		list->fd = fd;
		list->next = NULL;
		list->str = ft_strnew(0);
		return (list);
	}
	buf_list = list;
	while (buf_list)
	{
		if (buf_list->fd == fd)
			return (buf_list);
		mas = buf_list;
		buf_list = buf_list->next;
	}
	buf_list = (t_gnl*)malloc(sizeof(*buf_list));
	buf_list->fd = fd;
	buf_list->next = NULL;
	buf_list->str = ft_strnew(0);
	mas->next = buf_list;
	return (buf_list);
}

int		ft_up_buf(char **buf)
{
	char	*mas;
	size_t	len;

	len = ft_strlen(*buf);
	if (!(mas = ft_strnew(len)))
		return (1);
	ft_strncpy(mas, *buf, len);
	free(*buf);
	if (!(*buf = ft_strnew(len + BUFF_SIZE)))
		return (1);
	ft_strncpy(*buf, mas, len);
	free(mas);
	return (0);
}

int		ft_strok(char **buf, char **line)
{
	size_t	i;

	if (ft_strchr(*buf, '\n'))
	{
		i = ft_strlen(*buf) - ft_strlen(ft_strchr(*buf, '\n'));
		*line = ft_strnew(i);
		ft_strncpy(*line, *buf, i);
		*buf = ft_strsub(*buf, i + 1, ft_strlen(ft_strchr(*buf, '\n')));
		return (1);
	}
	else
	{
		if (ft_strlen(*buf) == 0)
		{
			*line = ft_strdup("");
			*buf = ft_strdup("");
			return (0);
		}
		i = ft_strlen(*buf);
		*line = ft_strnew(i);
		ft_strncpy(*line, *buf, i);
		*buf = ft_strdup("");
		return (1);
	}
}
