/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 12:04:42 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/09 12:12:02 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_free_loop(char **buffer, int fd)
{
	int	i;

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

int	ft_seekchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
