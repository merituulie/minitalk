/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 14:05:43 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/05 15:52:02 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*str;
	char	*dest;

	str = (char *)src;
	dest = (char *)dst;
	if (!str && !dest && n > 0)
		return (NULL);
	while (n-- > 0)
		*(dest++) = *(str++);
	return (dst);
}
