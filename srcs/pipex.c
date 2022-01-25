/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:51:30 by lde-alen          #+#    #+#             */
/*   Updated: 2022/01/21 09:43:39 by lde-alen         ###   ########.fr       */
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
	t_pipex	pipex;

	if (ac < 5)
		ft_fputstr("ERROR: Invalid amount of arguments.\n");
	pipex.infile = open(av[1], O_RDONLY);
	if (pipex.infile == -1)
		ft_fputstr("ERROR: Invalid infile.\n");
	pipex.outfile = open (av[ac - 1], O_TRUNC | O_CREAT | O_RDWR, 000644);
	if (pipex.outfile == -1)
		ft_fputstr("ERROR: Invalid outfile.\n");
	if (pipe(pipex.fd) == -1)
		ft_fputstr("ERROR: Ivalid pipe(fd)");
	pipex.path = ft_getpath(env);
	pipex.cmd_path = ft_split(pipex.path, ':');
	pipex.child1 = fork();
	if (pipex.child1 < 0)
		ft_fputstr("ERROR: Invalid fork of child1.\n");
	else if (pipex.child1 == 0)
		first_child(pipex, av, env);
	pipex.child2 = fork();
	if (pipex.child2 < 0)
		ft_fputstr("ERROR: Invalid fork of child2.\n");
	else if (pipex.child2 == 0)
		second_child(pipex, av, env);
	ft_closaz(&pipex);
	waitpid(pipex.child1, NULL, 0);
	waitpid(pipex.child2, NULL, 0);
	ft_free_dad(&pipex);
}
