/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:42:22 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/15 18:49:44 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_fputchar(char c)
{
	write(2, &c, 1);
}

void	ft_fputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_fputchar(str[i]);
		i++;
	}
	exit (EXIT_FAILURE);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0 || !s)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

void	ft_error(t_pipex pipex, int arg_nb)
{
	ft_putstr_fd("bash: ", STDERR_FILENO);
	ft_putstr_fd(pipex.av[arg_nb], STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
}
