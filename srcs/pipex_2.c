/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:56:24 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/15 21:12:23 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1 && str2 && i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

void	ft_fork1(t_pipex *pip, char **env)
{
	pip->child1 = fork();
	if (pip->child1 < 0)
		exit(1);
	else if (pip->child1 == 0)
	{
		pip->infile = open(pip->av[1], O_RDONLY);
		if (pip->infile == -1)
		{
			ft_error(*pip, 1);
			exit(1);
		}
		first_child(*pip, env);
	}
}

void	ft_fork2(char **env, int ac, t_pipex *pip)
{
	pip->child2 = fork();
	if (pip->child2 < 0)
		return ;
	else if (pip->child2 == 0)
	{
		pip->outfile = open(pip->av[ac - 1], \
		O_TRUNC | O_CREAT | O_RDWR, 000644);
		if (pip->outfile == -1)
		{
			ft_error(*pip, 4);
			exit(1);
		}
		second_child(*pip, env);
	}
}
