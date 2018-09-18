/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbonan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:36:48 by smbonan           #+#    #+#             */
/*   Updated: 2018/06/27 12:58:51 by smbonan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		end_line(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

int				get_line(const int fd, char *buf, char *s[fd])
{
	int		i;
	char	*temp;

	while ((end_line(buf) != 1) && ((i = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[i] = '\0';
		temp = s[fd];
		s[fd] = ft_strjoin(temp, buf);
		ft_strdel(&temp);
	}
	ft_strdel(&buf);
	if (i < 0)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	int			i;
	char		*buf;
	char		*str;
	char		*temp;
	static char	*s[2147483647];

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	if ((i = get_line(fd, buf, s)) == -1)
		return (-1);
	if ((str = ft_strchr(s[fd], '\n')))
	{
		*line = ft_strsub(s[fd], 0, str - s[fd]);
		temp = s[fd];
		s[fd] = ft_strdup(str + 1);
		ft_strdel(&temp);
		return (1);
	}
	*line = ft_strdup(s[fd]);
	ft_strdel(&s[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
