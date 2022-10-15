/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-cama <sde-cama@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 21:18:17 by sde-cama          #+#    #+#             */
/*   Updated: 2022/10/15 13:16:37 by sde-cama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "so_long.h"

// char	*ft_read_line(int fd, char *storage);
// char	*split_line(char *storage);
// char	*reset_storage(char *storage, char *tmp_storage);
// char	*make_line(char **line, char **read_buffer);
// int	ft_strchr2(char *s, char c);

// int	get_next_line(int fd, char **line)
// {
// 	static char	*storage;
// 	char		*current_line;
// 	char		*temp_storage;

// 	if ((fd < 0) || (BUFFER_SIZE <= 0))
// 		return (-1);
// 	if (storage == NULL)
// 		temp_storage = ft_strdup("");
// 	else
// 		temp_storage = ft_strdup(storage);
// 	temp_storage = ft_read_line(fd, temp_storage);
// 	if (temp_storage == NULL)
// 	{
// 		free(temp_storage);
// 		free(storage);
// 		storage = NULL;
// 		return (0);
// 	}
// 	current_line = split_line(temp_storage);
// 	storage = reset_storage(storage, temp_storage);
// 	free(temp_storage);
// 	current_line = make_line(line, &current_line);
// 	free(current_line);
// 	return (1);
// }

// char	*ft_read_line(int fd, char *storage)
// {
// 	char	*current_line;
// 	int		bytes_read;
// 	char	*tmp_storage;

// 	current_line = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if (!current_line)
// 		return (NULL);
// 	bytes_read = BUFFER_SIZE;
// 	while (bytes_read == BUFFER_SIZE && (ft_strchr(storage, '\n') == NULL))
// 	{
// 		bytes_read = read(fd, current_line, BUFFER_SIZE);
// 		if (bytes_read < 0 || (bytes_read == 0 && storage[0] == '\0'))
// 		{
// 			free(current_line);
// 			free(storage);
// 			return (NULL);
// 		}
// 		current_line[bytes_read] = '\0';
// 		tmp_storage = storage;
// 		storage = ft_strjoin(tmp_storage, current_line);
// 		free(tmp_storage);
// 	}
// 	free(current_line);
// 	return (storage);
// }

// char	*split_line(char *storage)
// {
// 	int		count;
// 	int		i;
// 	char	*new_line;

// 	count = 0;
// 	while (storage[count] != '\n' && storage[count] != '\0')
// 		count++;
// 	if (storage[count] == '\n')
// 		count++;
// 	new_line = malloc((count * sizeof(char)) + 1);
// 	i = 0;
// 	while (i < count)
// 	{
// 		new_line[i] = storage[i];
// 		i++;
// 	}
// 	new_line[count] = '\0';
// 	return (new_line);
// }

// char	*reset_storage(char *storage, char *tmp_storage)
// {
// 	free(storage);
// 	storage = ft_strchr(tmp_storage, '\n');
// 	if (storage != NULL)
// 		storage = ft_strdup(storage + 1);
// 	return (storage);
// }

// char	*make_line(char **line, char **read_buffer)
// {
// 	char	*temp;
// 	int		end_line;

// 	temp = NULL;
// 	end_line = ft_strchr2(*read_buffer, '\n');
// 	if (end_line != -1)
// 	{
// 		read_buffer[0][end_line] = '\0';
// 		*line = ft_strdup(*read_buffer);
// 		end_line++;
// 		temp = ft_strdup(*read_buffer + end_line);
// 	}
// 	else
// 		*line = ft_strdup(*read_buffer);
// 	free(*read_buffer);
// 	read_buffer = NULL;
// 	if (!line || !temp)
// 		return (NULL);
// 	return (temp);
// }

#include "so_long.h"

int ft_strchr2(char *s, char c)
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

size_t ft_strlen2(char *s)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void ft_strcopy2(char *dst, char *src, size_t len)
{
	size_t i;

	i = 0;
	if (!src || len == 0)
		return;
	while (src[i] && i < (len - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return;
}

char *ft_strjoin2(char *dst, char *src, size_t len)
{
	char *new;

	if (!dst && !src)
		return (NULL);
	new = (char *)calloc(sizeof(char), (ft_strlen2(dst) + len + 1)); // aqui
	if (!new)
		return (NULL);
	ft_strcopy2(new, dst, ft_strlen2(dst) + 1);
	ft_strcopy2((new + ft_strlen2(dst)), src, len + 1);
	if (dst)
		free(dst);
	return (new);
}

char *ft_strdup2(char *str)
{
	size_t size_str;
	char *new_str;

	size_str = ft_strlen2(str);
	new_str = (char *)calloc(sizeof(char), size_str + 1);
	if (str == NULL || !new_str)
		return (NULL);
	ft_strcopy2(new_str, str, size_str + 1);
	return (new_str);
}

void *ft_calloc2(size_t nmemb, size_t size)
{
	void *pointer;
	char *set;
	size_t i;

	i = 0;
	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	set = (char *)pointer;
	while (i < size)
	{
		set[i] = '\0';
		i++;
	}
	return (pointer);
}

static char *make_line(char **line, char **read_buffer)
{
	char *temp;
	int end_line;

	temp = NULL;
	end_line = ft_strchr2(*read_buffer, '\n');
	if (end_line != -1)
	{
		read_buffer[0][end_line] = '\0';
		*line = ft_strdup2(*read_buffer);
		end_line++;
		temp = ft_strdup2(*read_buffer + end_line);
	}
	else
		*line = ft_strdup2(*read_buffer);
	free(*read_buffer);
	read_buffer = NULL;
	if (!line || !temp)
		return (NULL);
	return (temp);
}

int read_and_join(int fd, char **read_buffer, char *line_buffer, int *bytes)
{
	char *temp;
	size_t size;

	while (*bytes && ft_strchr2(*read_buffer, '\n') == -1)
	{
		*bytes = read(fd, line_buffer, BUFFER_SIZE);
		if (*bytes < 0 || BUFFER_SIZE < *bytes)
		{
			free(line_buffer);
			return (-1);
		}
		if (*bytes)
		{
			temp = NULL;
			if (*bytes < BUFFER_SIZE)
				temp = ft_strjoin2(temp, line_buffer, *bytes);
			else
				temp = ft_strjoin2(temp, line_buffer, BUFFER_SIZE + 1);
			size = ft_strlen2(*read_buffer);
			*read_buffer = ft_strjoin2(*read_buffer, temp, (BUFFER_SIZE + size));
			free(temp);
		}
	}
	free(line_buffer);
	return (1);
}

int get_next_line(int fd, char **line)
{
	static char *read_buffer;
	char *line_buffer;
	int bytes;
	int already_read;

	bytes = 1;
	if (fd < 0 || fd > RLIMIT_NOFILE || !(line) || BUFFER_SIZE <= 0)
		return (-1);
	line_buffer = (char *)ft_calloc2(sizeof(char), BUFFER_SIZE + 1);
	if (!line_buffer)
		return (-1);
	if (!read_buffer)
		read_buffer = ft_strdup2("");
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