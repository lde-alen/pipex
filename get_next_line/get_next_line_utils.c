/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:15:34 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/23 13:19:17 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (0);
}

static void	ft_ini2(size_t *i, size_t *j)
{
	*i = -1;
	*j = 0;
}

char	*ft_strjoin(char *str, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!str)
	{
		str = (char *)malloc(sizeof(char));
		str[0] = '\0';
	}
	if (!str || !buffer)
		return (NULL);
	new = (char *)malloc(sizeof(char) * \
		(ft_strlen(str) + ft_strlen(buffer) + 1));
	if (!new)
		return (NULL);
	ft_ini2(&i, &j);
	if (str)
	{
		while (str[++i] != '\0')
			new[i] = str[i];
	}
	while (buffer[j] != '\0')
		new[i++] = buffer[j++];
	new[ft_strlen(str) + ft_strlen(buffer)] = '\0';
	free (str);
	return (new);
}
