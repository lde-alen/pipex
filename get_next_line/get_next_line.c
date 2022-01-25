/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 13:15:39 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/23 13:15:45 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_ini(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_newstr(char	*str)
{
	int		i;
	int		j;
	char	*new;

	ft_ini(&i, &j);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0')
	{
		free(str);
		return (NULL);
	}
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new)
		return (NULL);
	i++;
	while (str[i])
	{
		new[j] = str[i];
		i++;
		j++;
	}
	new[j] = '\0';
	free(str);
	return (new);
}

char	*get_line(char *str)
{
	int		i;
	int		j;
	char	*line;

	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && str[i] != '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	while (str[j] && str[j] != '\n')
	{
		line[j] = str[j];
		j++;
	}
	if (str[j] == '\n')
	{
		line[j] = str[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*ft_read_next(int fd, char *str)
{
	char	*buffer;
	int		rd;

	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	rd = 1;
	while (ft_strchr(str, '\n') == NULL && rd != 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[rd] = '\0';
		str = ft_strjoin(str, buffer);
	}
	free (buffer);
	if (str[0] == '\0')
	{
		free(str);
		return (NULL);
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read_next(fd, str);
	if (!str)
		return (NULL);
	line = get_line(str);
	str = ft_newstr(str);
	return (line);
}
