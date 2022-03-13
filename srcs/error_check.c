/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:42:22 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/13 18:53:52 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_error(t_pipex pipex, int arg_nb)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(pipex.av[arg_nb], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}

void	ft_fork1(t_pipex *pip, char **env)
{
	pip->infile = open(pip->av[1], O_RDONLY);
	if (pip->infile == -1)
	{
		ft_error(*pip, 1);
		exit(1);
	}
	first_child(*pip, env);
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
