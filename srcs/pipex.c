/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:51:30 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/15 21:52:26 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_dad(t_pipex *pipex)
{
	int	i;

	i = 0;
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

void	ft_closaz(t_pipex *pip)
{
	close(pip->fd[0]);
	close(pip->fd[1]);
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
		ft_fork1(&pip, env);
		if (pip.child1 != 0)
		{
			ft_fork2(env, ac, &pip);
			ft_closaz(&pip);
			waitpid(pip.child1, NULL, 0);
			waitpid(pip.child2, NULL, 0);
			ft_free_dad(&pip);
		}
	}
}
