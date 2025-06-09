/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:52:43 by aanbadi           #+#    #+#             */
/*   Updated: 2025/06/09 17:52:44 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_redirect(t_token *token)
{
	return ((token->type == T_LESS || token->type == T_GREATER
			|| token->type == T_DOUBLE_LESS
			|| token->type == T_DOUBLE_GREATER));
}

int	check_valid_xpnd(int c)
{
	if (ft_isalnum(c) || c == '_')
		return (1);
	return (0);
}

int	check_operator(t_token *token)
{
	if (check_redirect(token) || token->type == T_PIPE)
		return (1);
	return (0);
}
