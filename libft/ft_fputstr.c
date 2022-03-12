/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:05:12 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/08 21:08:23 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fputstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_fputchar(str[i++]);
	exit(EXIT_FAILURE);
}
