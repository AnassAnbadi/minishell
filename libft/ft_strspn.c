/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:54:57 by aanbadi           #+#    #+#             */
/*   Updated: 2025/06/09 17:54:58 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

size_t	ft_strspn(const char *str, const char *accept)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_strchr(str[i], accept))
			break ;
		i++;
	}
	return (i);
}
