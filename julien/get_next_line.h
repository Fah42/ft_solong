/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juchene <juchene@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 14:20:46 by juchene           #+#    #+#             */
/*   Updated: 2022/06/14 11:27:27 by juchene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_buff_adjust(char *s, size_t n);
char	*ft_strjoin(char *dest, char *src);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_found_nl(char *s);
int		ft_strlen(char *s);

#endif
