/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 04:02:03 by moerrais          #+#    #+#             */
/*   Updated: 2025/11/10 04:04:00 by moerrais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	int		s;
	char	str[7];

	fd = open("test.txt", O_RDWR, 0644);
	printf("%d", fd);
	if (fd == -1)
		return (perror("open"), 1);
	write(fd, "hello\n", 6);
	printf("%d\n", fd);
	lseek(fd, 0, SEEK_SET);
	s = read(fd, str, 6);
	if (s == -1)
	{
		perror("read");
		close(fd);
		return (1);
	}
	str[s] = '\0';
	printf("%d\n", s);
	printf("%s\n", str);
	close(fd);
	return (0);
}
