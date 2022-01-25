/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 04:32:43 by lde-alen          #+#    #+#             */
/*   Updated: 2022/01/21 04:35:12 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* Include */
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <sys/uio.h>

# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdio.h>
# include <../get_next_line/get_next_line.h>

/* Structs */
typedef struct s_pipexB
{
	pid_t	pid;
	int		infile;
	int		outfile;
	int		here_doc;
	int		cmd_nmbs;
	int		pipe_nmbs;
	int		*pipe;
	int		idx;
	char	*env_path;
	char	**cmd_path;
	char	*cmd;
	char	**cmd_param;
}t_pipexB;

/* Prototypes */

void	pipex(int ac, char **av, char **env);

#endif