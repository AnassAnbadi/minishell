/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:52:05 by aanbadi           #+#    #+#             */
/*   Updated: 2025/06/09 17:52:06 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	env_is_empty(void)
{
	char	*path;
	char	cwd[PATH_MAX];
	t_env	*node;

	path = "PATH=/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.";
	node = ft_envstr_to_lst(path);
	ft_lstadd_back_env(node);
	node = ft_envstr_to_lst(ft_strjoin("PWD=", getcwd(cwd, PATH_MAX)));
	ft_lstadd_back_env(node);
	node = ft_envstr_to_lst("SHLVL=1");
	ft_lstadd_back_env(node);
	node = ft_envstr_to_lst("_=/usr/bin/env");
	ft_lstadd_back_env(node);
	node = ft_envstr_to_lst("OLDPWD");
	ft_lstadd_back_env(node);
}

void	init_env(char **env)
{
	t_env	*node;
	int		i;

	i = 0;
	if (!env && !env[0])
		env_is_empty();
	while (env[i])
	{
		node = ft_envstr_to_lst(env[i]);
		if (!ft_strcmp(node->key, "_"))
			node->value = ft_strdup_env("env");
		ft_lstadd_back_env(node);
		i++;
	}
	ft_hpwd(ft_getenv("PWD"), 0);
}
