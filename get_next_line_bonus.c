/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:56:40 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/12 01:59:53 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_len(char *str, int tmp)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && (tmp || str[i] != '\n'))
		i++;
	return (i);
}

char	*ft_extract_line(char *buffer)
{
	char	*str;
	int		size;
	int		i;

	if (!buffer)
		return (NULL);
	size = ft_len(buffer, 0);
	if (buffer[size] == '\n')
		size++;
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (free(buffer), NULL);
	i = 0;
	while (i < size)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_weldstr(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = malloc(sizeof(char) * (ft_len(s1, 1) + ft_len(s2, 1) + 1));
	if (!str)
		return (free(s1), NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	if (!s1)
		free(s1);
	return (str);
}

char	*ft_slice_line(char *buffer)
{
	char	*str;
	int		i;
	int		size;
	int		sizebuffer;

	i = 0;
	if (!buffer)
		return (NULL);
	size = ft_len(buffer, 0);
	if (buffer[size] == '\n')
		size++;
	else
		return (free(buffer), NULL);
	sizebuffer = ft_len(&buffer[size], 1);
	str = malloc(sizeof(char) * (sizebuffer + 1));
	if (!str)
		return (free(buffer), NULL);
	while (sizebuffer > i && buffer[size])
		str[i++] = buffer[size++];
	str[i] = '\0';
	return (free(buffer), str);
}

char	*get_next_line_bonus(int fd)
{
	ssize_t		n;
	static char	*buffer[1024];
	char		line[BUFFER_SIZE];
	char		*buf;

	if (fd >= OPEN_MAX)
		return (NULL);
	if (!line)
		return (NULL);
	n = read(fd, line, BUFFER_SIZE);
	while (n && n != -1)
	{
		line[n] = '\0';
		buffer[fd] = ft_weldstr(buffer[fd], line);
		if (ft_seekchr(buffer[fd], '\n'))
			break ;
		n = read(fd, buffer, BUFFER_SIZE);
	}
	if (!buffer[fd])
		return (NULL);
	buf = ft_extract_line(buffer[fd]);
	buffer[fd] = ft_slice_line(buffer[fd]);
	return (buf);
}
