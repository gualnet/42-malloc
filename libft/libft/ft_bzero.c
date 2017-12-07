/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galy <galy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:19:55 by galy              #+#    #+#             */
/*   Updated: 2016/11/16 18:05:12 by galy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (n > 0)
	{
		i = 0;
		str = (unsigned char *)s;
		while (i < n)
		{
			str[i] = '\0';
			i++;
		}
	}
}
