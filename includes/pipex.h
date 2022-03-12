/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:27:51 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/12 23:15:39 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* Include */
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include "../libft/libft.h"
# include <sys/errno.h>

/* Structs */
typedef struct s_pipex
{
	pid_t	child1;
	pid_t	child2;
	int		fd[2];
	int		infile;
	int		outfile;
	char	**av;
	char	**env;
	char	*path;
	char	**cmd_path;
	char	**cmd_param;
	char	*cmd;
}t_pipex;

/* Prototypes */

void	pipex(int ac, char **av, char **env);
void	ft_free_dad(t_pipex *pipex);
void	ft_free_kiddo(t_pipex *pipex);
void	ft_error(t_pipex pipex, int arg_nb);
void	ft_closaz(t_pipex *pipex);
void	first_child(t_pipex pipex, char **env);
void	second_child(t_pipex pipex, char **env);
char	*ft_getpath(char **env);

#endif
