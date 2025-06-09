/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:48:04 by aanbadi           #+#    #+#             */
/*   Updated: 2025/06/09 17:48:05 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	print_env_error(char *str)
{
	ft_putstr_fd("env: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\': No such file or directory\n", STDERR_FILENO);
}

static void	print_env_var(t_env *var)
{
	if (var->key && var->equal && ft_strcmp(var->equal, ""))
	{
		ft_putstr_fd(var->key, STDOUT_FILENO);
		ft_putchar_fd('=', STDOUT_FILENO);
		ft_putendl_fd(var->value, STDOUT_FILENO);
	}
}

int	env_builtin(t_cmd cmd)
{
	t_env	**env;
	t_env	*current;

	env = ft_env_head();
	current = *env;
	if (!current)
		return (EXIT_FAILURE);
	if (count_args(cmd) > 0 && !(!ft_strcmp(cmd.tokens[1]->value, " ")
			&& cmd.tokens[1]->type == T_EXPANDED))
	{
		print_env_error(cmd.tokens[1]->value);
		return (127);
	}
	while (current)
	{
		print_env_var(current);
		current = current->next;
	}
	return (EXIT_SUCCESS);
}
