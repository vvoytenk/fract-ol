/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 13:17:14 by vvoytenk          #+#    #+#             */
/*   Updated: 2018/02/27 19:09:00 by vvoytenk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					get_next_line(const int fd, char **line)
{
	static t_list	*list = NULL;
	t_list			*begin;
	char			temp[1];

	if (fd < 0 || !line || (read(fd, temp, 0)) < 0)
		return (-1);
	begin = list;
	while (begin)
	{
		if (begin->content_size == (size_t)fd)
			return (get_next(begin, line));
		begin = begin->next;
	}
	begin = ft_lstnew(NULL, 0);
	begin->content_size = (size_t)fd;
	ft_lstadd(&list, begin);
	return (get_next(list, line));
}

int					get_next(t_list *list, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	ssize_t			bytes;

	while ((bytes = read((int)list->content_size, buf, BUFF_SIZE)) > 0)
	{
		buf[bytes] = '\0';
		if (list->content == NULL)
			list->content = ft_strdup(buf);
		else
		{
			temp = list->content;
			list->content = ft_strjoin(temp, buf);
			free(temp);
		}
		if (ft_strchr(list->content, '\n'))
			break ;
	}
	return (get_line((char **)&(list->content), line));
}

int					get_line(char **content, char **line)
{
	char			*temp;
	ssize_t			i;

	i = 0;
	if (*content == NULL)
		return (0);
	if (ft_strchr(*content, '\n'))
	{
		while (((*content)[i] != '\n'))
			i++;
		*line = ft_strsub(*content, 0, i);
		temp = *content;
		*content = ft_strdup(temp + i + 1);
		if ((*content)[0] == '\0')
			ft_strdel(content);
		ft_strdel(&temp);
	}
	else
	{
		*line = ft_strdup(*content);
		ft_strdel(content);
	}
	if (*line == NULL)
		return (-1);
	return (1);
}
