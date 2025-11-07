/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:09:13 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/07 14:38:59 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int ft_len(char *buffer, int tmp)
{
	int i;

	i = 0;
	if (!buffer)
		return 0;
	while (buffer[i] && (tmp || buffer[i] != '\n'))
	{
		i++;
	}	
	return (i);
}
int ft_contains_char(char *buffer, char sep)
{
	int i;
	i = 0;
	while (buffer && buffer[i])
	{
		if (buffer[i] == sep)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
char *ft_extract_line(char *buffer)
{
	int i = 0;
	if (!buffer)
		return NULL;
	int size = ft_len(buffer,0);
	if (*(buffer + size) == '\n')
		size++;
	char *res = malloc (sizeof (char) * (size + 1));
	if (!res)
		return (free (buffer),NULL);
	while (i < size)
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_trim_buffer(char *buffer)
{
	int size;
	char *line;
	int sizeline;
	int i = 0;
	if (!buffer)
		return (NULL);
	size = ft_len(buffer,0);
	if (buffer[size] == '\n')
		size++;
	else
		return (free (buffer),NULL);	
	sizeline = ft_len(&buffer[size],1);
	line = malloc (sizeof(char) * (sizeline + 1));
	if (!line)
		return (free(buffer),NULL);
	while (sizeline > i)
	{
		line[i] = buffer[size];
		i++;
		size++;
	}
	line[i] = '\0';
	return (free(buffer) ,line);
}

char *ft_strjoin_custom(char *s1, char *s2)
{
	int i;
	int j;
	char *res;

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
	return (free(s1),res);
}

char *get_next_line(int fd)
{
	static char *buffer;
	char tmp[BUFFER_SIZE];
	int n;
	char *buf;
	
	while ((n = read (fd , tmp,BUFFER_SIZE)) > 0)
	{
		tmp[n] = '\0';
		buffer = ft_strjoin_custom(buffer,tmp);
		if(ft_contains_char(buffer,'\n'))
			break;
	}
	if (!buffer)
		return NULL;
	buf = ft_extract_line(buffer);
	buffer = ft_trim_buffer(buffer);
	return (buf);
}