/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 05:09:13 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/07 02:04:55 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strchr(char *str ,char sep)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == sep)
		{
			return i;
		}
		i++;
	}
	return (0);
}
int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}
char *ft_strjoin(char *s1, char *s2)
{
	char *buffer;
	int sizes1;
	int sizes2;

	sizes1 = ft_strlen(s1);
	sizes2 = ft_strlen(s2);
	buffer = malloc (sizeof(char) * (sizes1 + sizes2 + 1));
	if (!buffer)
	{
		return (NULL);
	}
	int i = 0;
	int ss = 0;
	while (s1[i])
	{
		buffer[i] = s1[i];
		i++;
	}
	if (s2)
	{
		while (s2[ss])
		{
			buffer[i] = s2[ss];
			i++;	
			ss++;
		}	
	}
	buffer[i] = '\0';
	free (s2);
	return (buffer);
}
char *ft_cheak_en_newlwn(int fd, char *buffer)
{
	char line[BUFFER_SIZE];
	while (read(fd,line, BUFFER_SIZE) > 0)	
	{
		buffer = ft_strjoin(line,buffer);
		if(ft_strchr(line, '\n'))
		{
			return (buffer);	
		}
	}
	return (buffer);
}
char *ft_mun_line(char *buffer)
{
	int size;
	char *tmp = buffer;
	char *str;
	int sizelen;

	size = 0;
	if (!(size = (ft_strchr(buffer , '\n'))))
	{
		size = ft_strlen(buffer);
	}
	sizelen = ft_strlen (&buffer[size]);
	
	free(tmp);
	return (buffer);
}
char *get_next_line(int fd)
{
	static char *buffer;
	char tmp;
	buffer = ft_cheak_en_newlwn(fd,buffer);
	
	tmp = ft_mun_line(buffer);
	return (tmp);
	
}