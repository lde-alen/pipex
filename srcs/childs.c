/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:57:21 by lde-alen          #+#    #+#             */
/*   Updated: 2022/02/25 14:32:01 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*get_cmd(char **path, char *cmd)
{
	char	*tmp;
	char	*str;

	while (*path)
	{
		tmp = ft_strjoin(*path, "/");
		str = ft_strjoin(tmp, cmd);
		if (access (str, 0) == 0)
			return (str);
		free (str);
		path++;
	}
	return (NULL);
}

void	first_child(t_pipex pipex, char **av, char **env)
{
	dup2(pipex.fd[1], 1);
	close(pipex.fd[0]);
	dup2(pipex.infile, 0);
	pipex.cmd_param = ft_split(av[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_param[0]);
	if (!pipex.cmd)
	{
		ft_free_kiddo(&pipex);
		ft_fputstr("ERROR: Invalid command.\n");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_param, env);
}

void	second_child(t_pipex pipex, char **av, char **env)
{
	dup2(pipex.fd[0], 0);
	close(pipex.fd[1]);
	dup2(pipex.outfile, 1);
	pipex.cmd_param = ft_split(av[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_path, pipex.cmd_param[0]);
	if (!pipex.cmd)
	{
		ft_free_kiddo(&pipex);
		ft_fputstr("");
		exit(1);
	}
	execve(pipex.cmd, pipex.cmd_param, env);
}
