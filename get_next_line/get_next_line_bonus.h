/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:15:18 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/23 13:16:05 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_red_next(int fd, char *str);
char	*get_line(char *str);
char	*ft_newstr(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buffer);
size_t	ft_strlen(char *str);

#endif
