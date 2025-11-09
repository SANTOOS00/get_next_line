/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:09:13 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/09 13:44:59 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_extract_line(char *buffer)
{
	int		x;
	int		size;
	char	*res;

	x = 0;
	if (!buffer)
		return (NULL);
	size = ft_len(buffer, 0);
	if (buffer[size] == '\n')
		size++;
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (free(buffer), NULL);
	while (x < size)
	{
		res[x] = buffer[x];
		x++;
	}
	res[x] = '\0';
	return (res);
}

char	*ft_trim_buffer(char *buffer)
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

char	*ft_strjoin_custom(char *s1, char *s2)
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
	return (free(s1), res);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		n;
	char		*tmp;
	char		*buf;

	tmp = malloc(BUFFER_SIZE + 1);
	if (!tmp)
		return (NULL);
	n = read(fd, tmp, BUFFER_SIZE);
	while (n != -1 && n)
	{
		tmp[n] = '\0';
		buffer = ft_strjoin_custom(buffer, tmp);
		if (ft_contains_char(buffer, '\n'))
			break ;
		n = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	if (!buffer)
		return (NULL);
	buf = ft_extract_line(buffer);
	buffer = ft_trim_buffer(buffer);
	return (buf);
}
