/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:56:40 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/08 17:53:06 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void ft_freeloop(char **buffer)
{
	int i;

	i = 0;
	while (buffer[i])
	{
		ferr(buffer[i]);
		i++;
	}
	ferr(buffer);
}
char **ft_add_arry(char **buffer,int fd,int file_9dam)
{
	char **buffer_jdid;
	int i = 0;
	buffer_jdid = malloc(sizeof (char **) * (fd + 1));
	if (!buffer_jdid)
	{
		return (ft_ferrloop(buffer), 0);
	}
	while (file_9dam > i)
	{
		buffer_jdid[i] = buffer[i];
	}
	buffer_jdid[fd] = 0;
	return (buffer_jdid);
}
int ft_len(char *str , int tmp)
{
	int i;

	i = 0;
	while (str[i] && (tmp || str[i] != '\n'))
	{
		i++;
	}
	return (i);
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

int ft_strchr(char *buffer, char c)
{
	int i; 

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}
char *ft_extract_line(char *buffer)
{
	char *res;
	int sizeline;
	int i;
	
	i = 0;
	if (!buffer)
		return (NULL);
	sizeline = ft_len(buffer , 0);
	if (buffer[sizeline] == '\n')
		sizeline++;
	res = malloc (sizeof (char) * sizeline + 1);
	if (!res)
		return NULL;
	while (sizeline  > i && buffer[i])
	{
		res[i] = buffer[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *ft_trim_buffer(char *buffer)
{
	char *res;
	int i = 0;
	int size = ft_len(buffer , 0);
	int sizeline = ft_len(&buffer[size] , 1);
	
	res = malloc(sizeof (char) * (sizeline + 1));
	if (!res)
		return (free(buffer),NULL);
	while (size < sizeline)
	{
		res[i++] = buffer[size++];
	}
	res[i] = '\0';
	ferr(buffer);
	return (res);
}
char *get_next_line(int fd)
{
	static char **buffer;
	static int file_number = 0;
	char *line;
	int n;
	char *buf;

	line = malloc (BUFFER_SIZE + 1);
	if(!line)
		return (NULL);
	if (file_number < fd)
	{
		buffer = ft_add_arry(buffer, fd - 2,file_number - 2);
		file_number = fd;
	}
	n = read(fd, line, BUFFER_SIZE);
	while (n && n != -1)
	{
		line[n] = '\0';
		buffer[fd - 2] = ft_strjoine(line,&buffer[fd - 2]);
		if (ft_strchr(line,'\n'))
			break;
		n = read(fd, line, BUFFER_SIZE);
	}
	free(line);
	if (!buffer)
		return (NULL);
	buf = ft_extract_line(&buffer[fd - 2]);
	buffer[fd - 2] = ft_trim_buffer(&buffer[fd - 2]);
	return (buf);	
}


