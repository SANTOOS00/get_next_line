/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:09:13 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/12 01:53:26 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *buffer)
{
	int		i;
	int		size;
	char	*res;

	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_len(buffer, 0);
	if (buffer[size] == '\n')
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (free(buffer), NULL);
	while (i < size)
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_slice_line(char *buffer)
{
	int		size;
	char	*line;
	int		sizeline;
	int		i;

	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_len(buffer, 0);
	if (buffer[size] == '\n')
		size++;
	else
		return (free(buffer), NULL);
	sizeline = ft_len(&buffer[size], 1);
	line = malloc(sizeof(char) * (sizeline + 1));
	if (!line)
		return (free(buffer), NULL);
	while (sizeline > i && buffer[size])
		line[i++] = buffer[size++];
	line[i] = '\0';
	return (free(buffer), line);
}

char	*ft_weldstr(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = malloc(ft_len(s1, 1) + ft_len(s2, 1) + 1);
	if (!res)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	if (s1)
	{
		free(s1);
	}
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		n;
	char		line[BUFFER_SIZE];
	char		*buf;

	if (fd >= OPEN_MAX)
		return (NULL);
	n = read(fd, line, BUFFER_SIZE);
	while (n != -1 && n)
	{
		line[n] = '\0';
		buffer = ft_weldstr(buffer, line);
		if (ft_seekchr(buffer, '\n'))
			break ;
		n = read(fd, line, BUFFER_SIZE);
	}
	if (!buffer)
		return (NULL);
	buf = ft_extract_line(buffer);
	buffer = ft_slice_line(buffer);
	return (buf);
}
