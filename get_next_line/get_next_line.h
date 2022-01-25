/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:15:50 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/23 13:15:57 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_red_next(int fd, char *str);
char	*get_line(char *str);
char	*ft_newstr(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buffer);
size_t	ft_strlen(char *str);

#endif
