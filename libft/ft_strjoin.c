/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:36:59 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/02 16:15:37 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, int len, char const s2)
{
	char	*str;
	int		index;

	index = 0;
	if (!s1)
		return (NULL);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[index++] = *(s1++);
	}
	str[index] = s2;
	str[index + 1] = '\0';
	return (str);
}
