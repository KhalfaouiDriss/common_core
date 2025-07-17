/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khalfaoui47 <khalfaoui47@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 20:30:32 by sel-bech          #+#    #+#             */
/*   Updated: 2025/07/17 03:41:31 by khalfaoui47      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_builtin(char *cmd)
{
	if (!cmd)
		return (0);
	if (ft_strncmp(cmd, "echo", 5) == 0 || ft_strncmp(cmd, "pwd", 4) == 0
		|| ft_strncmp(cmd, "cd", 3) == 0 || ft_strncmp(cmd, "exit", 5) == 0
		|| ft_strncmp(cmd, "export", 7) == 0 || ft_strncmp(cmd, "env", 4) == 0
		|| ft_strncmp(cmd, "unset", 6) == 0 || ft_strncmp(cmd, "chnm", 5) == 0)
	{
		return (1);
	}
	return (0);
}

int	execute_builtin(t_shell *shell, char *cmd, char **args)
{
	int	i;

	i = 0;
	if (ft_strncmp(cmd, "echo", 5) == 0)
		return (ft_echo(args), 0);
	else if (ft_strncmp(cmd, "cd", 3) == 0)
		return (ft_cd(shell, args), shell->exit_status);
	else if (ft_strncmp(cmd, "pwd", 4) == 0)
		return (ft_pwd(shell, args), shell->exit_status);
	else if (ft_strncmp(cmd, "export", 6) == 0)
		return (ft_export(shell, args), shell->exit_status);
	else if (ft_strncmp(cmd, "unset", 5) == 0)
		return (ft_unset(&(shell->env), args), 0);
	else if (ft_strncmp(cmd, "env", 3) == 0)
	{
		i = 0;
		while (args[i] && ft_strncmp(args[i], "env", 3) == 0)
			i++;
		ft_env(shell->env, 1);
		return (shell->exit_status);
	}
	else if (ft_strncmp(cmd, "exit", 5) == 0)
		return (ft_exit(shell, args));
	else if(ft_strncmp(cmd, "chnm", 5) == 0)
	{
		if(!args[1])
		{
			ft_putstr_fd("chmn need argement : used to change user name\n", 2);
			shell->user_name = "47";
			shell->exit_status = 47;
			return(shell->exit_status);
		}
		else
			shell->user_name = ft_strdup(args[1]);
	}
	return (127);
}
