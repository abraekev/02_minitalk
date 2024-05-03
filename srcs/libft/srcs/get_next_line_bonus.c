/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abraekev <abraekev@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:58:41 by abraekev          #+#    #+#             */
/*   Updated: 2024/04/03 14:09:10 by abraekev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Get the real OPEN_MAX by using
	long OPEN_MAX = sysconf(_SC_OPEN_MAX));
*/

static int	frees_and_nulls(char **s1, char **s2)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (0);
}

static int	update_line(char *buffer, int bytes_read, char **line)
{
	char	*tmp;
	size_t	line_len;
	size_t	i;

	if (!(*line))
		*line = (char *)ft_calloc(bytes_read + 1, 1);
	if (!(*line))
		return (frees_and_nulls(&buffer, NULL));
	line_len = ft_strlen(*line);
	tmp = malloc(line_len + bytes_read + 1);
	if (!tmp)
		return (frees_and_nulls(&buffer, line));
	ft_strlcpy(tmp, *line, line_len + bytes_read + 1);
	i = line_len;
	while (i < line_len + bytes_read)
	{
		tmp[i] = buffer[i - line_len];
		i++;
		if (tmp[i - 1] == '\n' || !tmp[i - 1])
			break ;
	}
	tmp[i] = 0;
	free(*line);
	*line = tmp;
	return (1);
}

static int	read_and_update(int fd, char **buffer, char **line, int bytes_read)
{
	if (!(*buffer))
		*buffer = (char *)ft_calloc(BUFFER_SIZE + 1, 1);
	if (!(*buffer))
		return (-1);
	bytes_read = read(fd, *buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		(*buffer)[bytes_read] = 0;
		if (!update_line(*buffer, bytes_read, line))
			return (-1);
		if (ft_strchr(*buffer, '\n'))
		{
			ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1, BUFFER_SIZE + 1);
			break ;
		}
		bytes_read = read(fd, *buffer, BUFFER_SIZE);
	}
	return (bytes_read);
}

static int	check_and_update(char **buffer, char **line)
{
	int	bytes_read;

	bytes_read = (int)ft_strlen(*buffer);
	if (!update_line(*buffer, bytes_read, line))
		return (0);
	if (ft_strchr(*buffer, '\n'))
		ft_strlcpy(*buffer, ft_strchr(*buffer, '\n') + 1, BUFFER_SIZE + 1);
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffers[OPEN_MAX];
	char		*line;
	int			bytes_read;

	if (fd < 0 || fd >= OPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	if (buffers[fd] && *buffers[fd])
		if (!check_and_update(&buffers[fd], &line))
			return (NULL);
	if ((!buffers[fd] || !*buffers[fd]) && (!line || !ft_strchr(line, '\n')))
	{
		bytes_read = read_and_update(fd, &buffers[fd], &line, -1);
		if (bytes_read < 0)
		{
			frees_and_nulls(&buffers[fd], &line);
			return (NULL);
		}
		if (!bytes_read && buffers[fd])
			frees_and_nulls(&buffers[fd], NULL);
	}
	return (line);
}
