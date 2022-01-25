/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-alen <lde-alen@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 03:21:16 by lde-alen          #+#    #+#             */
/*   Updated: 2021/12/23 13:29:41 by lde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Combines all strings in the argument list and puts the result into
 * the returned string with dynamically allocated memory.
 * 
 * @param s1 
 * @param s2 
 * @return char* (FREE REQ)
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		i;
	size_t		len_s1;
	size_t		len_s2;
	char		*str;

	if (s1 && s2)
	{
		len_s1 = ft_strlen((char *)s1);
		len_s2 = ft_strlen((char *)s2);
		str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
		if (!str)
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len_s1] = s2[i];
			len_s1++;
		}
		str[len_s1] = '\0';
		return (str);
	}
	return (NULL);
}
