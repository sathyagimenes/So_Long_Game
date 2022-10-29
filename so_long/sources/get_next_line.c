/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:18:17 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/29 18:06:50 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	read_and_join(int fd, char **read_buffer, char *line_buffer, int *bytes);
static char	*make_line(char **line, char **read_buffer);
int	ft_strchr_utils(char *s, char c);
char	*ft_strjoin_utils(char *dst, char *src, size_t len);

int	get_next_line(int fd, char **line)
{
	static char	*read_buffer;
	char		*line_buffer;
	int			bytes;
	int			already_read;

	bytes = 1;
	if (fd < 0 || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	line_buffer = (char *)ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	if (!line_buffer)
		return (-1);
	if (!read_buffer)
		read_buffer = ft_strdup("");
	already_read = read_and_join(fd, &read_buffer, line_buffer, &bytes);
	if (already_read == -1)
		return (-1);
	read_buffer = make_line(line, &read_buffer);
	if (!bytes)
	{
		free(read_buffer);
		return (0);
	}
	return (1);
}

static int read_and_join(int fd, char **read_buffer, char *line_buffer, int *bytes)
{
	size_t size;

	while (*bytes && ft_strchr_utils(*read_buffer, '\n') == -1)
	{
		*bytes = read(fd, line_buffer, BUFFER_SIZE);
		if (*bytes < 0 || BUFFER_SIZE < *bytes)
		{
			free(line_buffer);
			return (-1);
		}
		if (*bytes)
		{
			size = ft_strlen(*read_buffer);
			*read_buffer = ft_strjoin_utils(*read_buffer, line_buffer, (BUFFER_SIZE + size));
		}
	}
	free(line_buffer);
	return (1);
}

static char *make_line(char **line, char **read_buffer)
{
	char *temp;
	int end_line;

	temp = NULL;
	end_line = ft_strchr_utils(*read_buffer, '\n');
	if (end_line != -1)
	{
		read_buffer[0][end_line] = '\0';
		*line = ft_strdup(*read_buffer);
		end_line++;
		temp = ft_strdup(*read_buffer + end_line);
	}
	else
		*line = ft_strdup(*read_buffer);
	free(*read_buffer);
	read_buffer = NULL;
	if (!line || !temp)
		return (NULL);
	return (temp);
}

int ft_strchr_utils(char *s, char c)
{
	int i;

	i = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

char *ft_strjoin_utils(char *dst, char *src, size_t len)
{
	char *new;

	if (!dst && !src)
		return (NULL);
	new = (char *)ft_calloc(sizeof(char), (ft_strlen(dst) + len + 1)); // aqui
	if (!new)
		return (NULL);
	ft_strcpy(new, dst, ft_strlen(dst) + 1);
	ft_strcpy((new + ft_strlen(dst)), src, len + 1);
	if (dst)
		free(dst);
	return (new);
}
