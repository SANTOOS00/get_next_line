/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moerrais <moerrais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:49:53 by moerrais          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2025/11/07 01:45:57 by moerrais         ###   ########.fr       */
=======
<<<<<<< HEAD
/*   Updated: 2025/11/07 01:45:57 by moerrais         ###   ########.fr       */
=======
/*   Updated: 2025/11/07 10:23:27 by moerrais         ###   ########.fr       */
>>>>>>> 39e5e24 (get_next_line)
>>>>>>> 78dce3a (get_next_linr_1337)
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

char *get_next_line(int fd);
		

#endif
