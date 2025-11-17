/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:49:53 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/16 19:52:45 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#define OPEN_MAX 1024

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif
#include <stdlib.h>
#include <unistd.h>
char *get_next_line(int fd);
int ft_seekchr(char *buffer, char sep);
int ft_len(char *buffer, int tmp);
#endif
