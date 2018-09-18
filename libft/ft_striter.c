/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbonan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 07:56:34 by smbonan           #+#    #+#             */
/*   Updated: 2018/06/06 13:17:23 by smbonan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char*))
{
	int		i;

	i = 0;
	if (s != NULL && f != NULL)
	{
		while (s[i])
		{
			(*f)(&s[i]);
			i++;
		}
	}
}
