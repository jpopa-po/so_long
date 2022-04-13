/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpopa-po <jpopa-po@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/21 13:51:55 by jpopa-po          #+#    #+#             */
/*   Updated: 2022/03/27 16:55:00 by jpopa-po         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len - 1)
	{
		while (needle[n] == haystack[i + n])
		{
			if (needle[n + 1] == '\0')
				return ((char *)haystack + i);
			n++;
		}
		i++;
		n = 0;
	}
	return (0);
}
