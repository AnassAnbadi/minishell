/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aanbadi <aanbadi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:53:10 by aanbadi           #+#    #+#             */
/*   Updated: 2025/06/09 17:53:11 by aanbadi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	popen_err(char *s1, char *s2)
{
	char	*err_msg;

	err_msg = ft_strjoin(ft_strjoin("minishell: ", s1), ": ");
	err_msg = ft_strjoin(err_msg, s2);
	err_msg = ft_strjoin(err_msg, "\n");
	write(STDERR_FILENO, err_msg, ft_strlen(err_msg));
}

int	ft_open(char *path, int oflag, int mode)
{
	int		fd;

	fd = 0;
	if (!ft_strncmp(path, "~/", 2))
		path = ft_strjoin(ft_getenv("HOME"), path + 1);
	if (mode == -1)
		fd = open(path, oflag);
	else
		fd = open(path, oflag, mode);
	if (fd == -1)
	{
		popen_err(path, strerror(errno));
		ft_set_status(EXIT_FAILURE);
	}
	return (fd);
}
