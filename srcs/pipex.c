/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:51:30 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/12 23:18:02 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_dad(t_pipex *pipex)
{
	int	i;

	i = 0;
	close(pipex->infile);
	close(pipex->outfile);
	while (pipex->cmd_path[i])
	{
		free(pipex->cmd_path[i]);
		i++;
	}
	free(pipex->cmd_path);
}

void	ft_free_kiddo(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->cmd_param[i])
	{
		free(pipex->cmd_param[i]);
		i++;
	}
	free (pipex->cmd_param);
	free (pipex->cmd);
}

char	*ft_getpath(char **env)
{
	while (ft_strncmp("PATH", *env, 4))
		env++;
	return (*env + 5);
}

void	ft_closaz(t_pipex *pipex)
{
	close(pipex->fd[0]);
	close(pipex->fd[1]);
}

void	pipex(int ac, char **av, char **env)
{
	t_pipex	pip;

	if (ac != 5)
		ft_fputstr("Please input valid amount of parameters.\n");
	else
	{
		if (pipe(pip.fd) == -1)
			return ;
		pip.av = av;
		pip.path = ft_getpath(env);
		pip.cmd_path = ft_split(pip.path, ':');
		pip.child1 = fork();
		if (pip.child1 < 0)
			exit(1);
		else if (pip.child1 == 0)
		{
			pip.infile = open(pip.av[1], O_RDONLY);
			if (pip.infile == -1)
			{
				ft_error(pip, 1);
				exit(1);
			}
			first_child(pip, env);
		}
		else
		{
			pip.child2 = fork();
			if (pip.child2 < 0)
				return ;
			else if (pip.child2 == 0)
			{
				pip.outfile = open(pip.av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 000644);
				if (pip.outfile == -1)
				{
					ft_error(pip, 4);
					exit(1);
				}
				second_child(pip, env);
			}
		}
		ft_closaz(&pip);
		waitpid(pip.child1, NULL, 0);
		waitpid(pip.child2, NULL, 0);
		ft_free_dad(&pip);
		exit(0);
	}
}
