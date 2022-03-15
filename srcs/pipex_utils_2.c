/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 14:20:31 by lde-alen          #+#    #+#             */
/*   Updated: 2022/03/15 14:23:32 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t					i;
	unsigned const char		*tmp_src;
	unsigned char			*tmp_dest;

	tmp_src = (unsigned const char *)src;
	tmp_dest = (unsigned char *)dst;
	i = 0;
	if (!(tmp_dest || tmp_src))
		return (NULL);
	while (i < n)
	{
		*tmp_dest = *tmp_src;
		tmp_dest++;
		tmp_src++;
		i++;
	}
	return (dst);
}
