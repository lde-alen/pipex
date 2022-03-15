/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 09:27:51 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/15 18:34:31 by lde-alen         ###   ########.fr       */
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
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_fputchar(char c);
void	ft_fputstr(char *str);
void	*ft_memcpy(void *dst, const void *src, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_error(t_pipex pipex, int arg_nb);
void	ft_fork1(t_pipex *pip, char **env);
void	ft_fork2(char **env, int ac, t_pipex *pip);
void	ft_free_dad(t_pipex *pipex);
void	ft_free_kiddo(t_pipex *pipex);
void	ft_error(t_pipex pipex, int arg_nb);
void	ft_closaz(t_pipex *pip);
void	first_child(t_pipex pipex, char **env);
void	second_child(t_pipex pipex, char **env);
size_t	ft_strlen(const char *s);
char	*ft_getpath(char **env);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);

#endif
