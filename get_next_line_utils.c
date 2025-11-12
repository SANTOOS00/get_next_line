/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:41:47 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/11 21:04:59 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_len(char *buffer, int tmp)
{
	int	i;

	i = 0;
	if (!buffer)
		return (0);
	while (buffer[i] && (tmp || buffer[i] != '\n'))
	{
		i++;
	}
	return (i);
}

int	ft_seekchr(char *buffer, char sep)
{
	int	i;

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
