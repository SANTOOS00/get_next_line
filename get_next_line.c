/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:09:13 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/07 10:40:54 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
int ft_str_null_end_new(char *buffer)
{
	int i;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		i++;
	}
	return (i);
}
int ft_strlen(char *buffer)
{
	int i;

	i = 0;
	if (!buffer)
	{
		return (0);
	}
	while (buffer[i])
	{
		i++;
	}
	return (i);
}
int ft_strchr(char *buffer, char sep)
{
	int i;
	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == sep)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
char *ft_strlcpy(char *buffer)
{
	int i = 0;
	if (!buffer)
	{
		return NULL;
	}
	int size = ft_str_null_end_new(buffer);
	if (*(buffer + size) == '\n')
	{
		size++;
	}
	char *res = malloc (sizeof (char) * (size + 1));
	if (!res)
	{
		free(buffer);
		return (NULL);
	}
	while (i < size)
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_ta3dilline(char *buffer)
{
	if (!buffer)
	{
		return (NULL);
	}
	int size = ft_str_null_end_new(buffer);
	char *line;
	int sizeline;
	int i = 0;
	
	if (*(buffer + size) == '\n')
		size++;
	else
	{
		free(buffer);
		return NULL;	
	}
	sizeline = ft_strlen(&buffer[size]);
	line = malloc (sizeof(char) * (sizeline + 1));
	if (!line)
	{
		free(buffer);
		return NULL;
	}
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
void ft_strlcat(char *s1, char *s2, char *str)
{
	int sizes1 = ft_strlen(s1);
	int sizes2 = ft_strlen(s2);
	int i = 0;
	int c = 0;
	while ((sizes1 + sizes2) > i)
	{
		if (sizes1 > i)
		{
			str[i] = s1[i];
			i++;
		}
		else
		{
			str[i++] = s2[c++];
		}
	}
	str[i] = '\0';
	free(s1);
}
char *ft_strjoin(char *buffer, char *line)
{
	int sizebuffer = ft_strlen(buffer);
	int sizeline = ft_strlen(line);
	char *str;
	str = malloc (sizeof(char) * (sizebuffer + sizeline + 1));
	if (!str)
	{
		free (buffer);
		return (NULL);
	}
	ft_strlcat(buffer,line,str);
	return (str);
}
char *ft_t3dil_and_read_line(int fd ,char *buffer)
{
	char line[BUFFER_SIZE];
	
	while ((read(fd , line,BUFFER_SIZE)) > 0)
	{
		buffer = ft_strjoin(buffer,line);
		if(ft_strchr(buffer,'\n'))
		{
			return (buffer);
		}
	}
	return (buffer);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char *tmp;
	
	buffer = ft_t3dil_and_read_line(fd,buffer);
	tmp = ft_strlcpy(buffer);
	buffer = ft_ta3dilline(buffer);	

	return (tmp);
}