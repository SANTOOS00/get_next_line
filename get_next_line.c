/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:09:13 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/07 13:56:13 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int ft_strlen_custom(char *buffer, int tmp)
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
	int size = ft_strlen_custom(buffer,0);
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
	int size = ft_strlen_custom(buffer,0);
	char *line;
	int sizeline;
	int i = 0;
	if (!buffer)
		return (NULL);
	
	if (*(buffer + size) == '\n')
		size++;
	else
		return (free (buffer),NULL);	
	sizeline = ft_strlen_custom(&buffer[size],1);
	line = malloc (sizeof(char) * (sizeline + 1));
	if (!line)
		return (free (buffer),NULL);
	while (sizeline > i)
	{
		line[i] = buffer[size];
		i++;
		size++;
	}
	line[i] = '\0';
	free(buffer);
	return (line);
}
void ft_concat_strings(char *s1, char *s2, char *dest)
{
	int sizes1 = ft_strlen_custom(s1,1);
	int sizes2 = ft_strlen_custom(s2,1);
	int i = 0;
	int c = 0;
	while ((sizes1 + sizes2) > i)
	{
		if (sizes1 > i)
		{
			dest[i] = s1[i];
			i++;
		}
		else
			dest[i++] = s2[c++];
	}
	dest[i] = '\0';
	free(s1);
}
char *ft_strjoin_custom(char *buffer, char *line)
{
	int sizebuffer = ft_strlen_custom(buffer,1);
	int sizeline = ft_strlen_custom(line,1);
	char *str;
	str = malloc (sizeof(char) * (sizebuffer + sizeline + 1));
	if (!str)
		return (free (buffer),NULL);
	ft_concat_strings(buffer,line,str);
	return (str);
}
char *ft_read_until_newline(int fd ,char *buffer)
{
	char tmp[BUFFER_SIZE];
	int bytes_read;
	
	while ((bytes_read = read (fd , tmp,BUFFER_SIZE)) > 0)
	{
		tmp[bytes_read] = '\0';
		buffer = ft_strjoin_custom(buffer,tmp);
		if (!buffer)
			return (NULL);
		if(ft_contains_char(buffer,'\n'))
			return (buffer);
	}
	return (buffer);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *tmp;
	
	buffer = ft_read_until_newline(fd,buffer);
	tmp = ft_extract_line(buffer);
	buffer = ft_trim_buffer(buffer);	

	return (tmp);
}