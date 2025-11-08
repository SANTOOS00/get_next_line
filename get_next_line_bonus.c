/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:56:40 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/08 21:03:18 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void ft_free_loop(char **buffer, int fd)
{
	int i;

	i = 0;
	while (i < fd)
	{
		if (buffer[i])
		{
			free(buffer[i]);
		}
		i++;
	}
	free(buffer);
}
char **ft_add_pointeur(char **buffer, int fd, int fd_9dm)
{
	char **buffer_jdid;
	int i = 0;

	buffer_jdid = malloc (sizeof (char *) * fd - 1);
	if (!buffer_jdid)
		return (ft_free_loop(buffer,fd_9dm),NULL);
	while (i < fd_9dm - 2)
	{
		buffer_jdid[i] = buffer[i];
		i++;
	}
	while (i < fd - 1)
	{
		buffer_jdid[i] = NULL;
		i++;
	}
	return (free (buffer), buffer_jdid);
}
int ft_seekchr(char *str, char c)
{
	int i;
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
int ft_len(char *str, int tmp)
{
	int i;

	i = 0;
	if (!str)
	{
		return(0);
	}
	while (str[i] && (tmp || str[i] != '\n'))
	{
		i++;
	}
	return (i);
}

char *ft_extract_line(char *buffer)
{
	char *str;
	if (!buffer)
		return (NULL);
	int size = ft_len(buffer, 0);
	str = malloc (sizeof(char) * (size + 1));
	if (!str)
		return (free(buffer),NULL);
	int i = 0;
	while (i < size)
	{
		str[i] = buffer[i];
		i++;
	}
	str[i] = '\0';
	return (str);	
}

char *ft_weldstr(char *s1, char *s2)
{
	char *str;
	int i;
	int j;

	j = 0;
	i = 0;
	str = malloc (sizeof (char) * (ft_len(s1 , 1) + ft_len(s2 , 1) + 1));
	if (!str)
		return (free(s1),NULL);
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (free (s1),str);
}

char *ft_slice_line(char *buffer)
{
	char *str;
	int i = 0;
	if(!buffer)
		return (NULL);
	int size = ft_len(buffer, 0);
	if (buffer[size] == '\n')
		size++;
	else
		return (free(buffer),NULL);
	int sizebuffer = ft_len(&buffer[size],1);
	str = malloc (sizeof(char) * (sizebuffer + 1));
	if (!str)
		return (free(buffer),NULL);
	while (sizebuffer > i && buffer[size])
		str[i++] = buffer[size++];  
	str[i] = '\0';
	return (free(buffer),str);
}
char *get_next_line_bonus(int fd)
{
	static char **buffer;
	static int fd_9dim;
	char *line;
	char *buf;
	int n;
	
	if (fd > fd_9dim)
	{
		buffer = ft_add_pointeur(buffer,fd, fd_9dim);
		if (!buffer)
			return (NULL);
		fd_9dim = fd;
	}
	line = malloc (BUFFER_SIZE + 1);
	if (!line)
		return (NULL);
	n = read(fd,line, BUFFER_SIZE);
	while (n && n != -1)
	{
		line[n] = '\0';
		buffer[fd - 2] = ft_weldstr(buffer[fd - 2], line);
		if (!buffer[fd - 2] || ft_seekchr(line,'\n'))
			break;
		read(fd, buffer, BUFFER_SIZE);
	}
	free(line);
	if (!buffer[fd - 2])
	{
		return (ft_free_loop(buffer, fd),NULL);
	}
	buf  = ft_extract_line(buffer[fd - 2]);
	buffer[fd - 2] = ft_slice_line(buffer[fd - 2]);
	return (buf);
}