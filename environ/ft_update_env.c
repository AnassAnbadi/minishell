/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_update_env.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:51:58 by aanbadi           #+#    #+#             */
/*   Updated: 2025/06/09 17:51:59 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	**ft_env_head(void)
{
	static t_env	*head;

	return (&head);
}

void	ft_update_env(char *key, char *value)
{
	t_env	**env;
	t_env	*node;

	env = ft_env_head();
	node = *env;
	while (node)
	{
		if (node->key && !ft_strcmp(node->key, key))
			node->value = ft_strdup_env(value);
		node = node->next;
	}
}

void	ft_append_env(char *key, char *value)
{
	t_env	**env;
	t_env	*node;

	env = ft_env_head();
	node = *env;
	while (node)
	{
		if (node->key && !ft_strcmp(node->key, key))
			node->value = ft_strjoin_env(node->value, value);
		node = node->next;
	}
}
