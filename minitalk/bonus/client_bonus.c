/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:27:49 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/18 17:45:21 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	g_flag = 0;

void	handler(int sig)
{
	if (sig == SIGUSR1)
		g_flag = 1;
	if (sig == SIGUSR2)
		ft_putstr_fd("send Message succusfuly\n", 1);
}

void	send_char(char c, int pid)
{
	int	i;
	int	p;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			p = kill(pid, SIGUSR1);
		else
			p = kill(pid, SIGUSR2);
		if (p == -1)
		{
			ft_putstr_fd("PID Invalid\n", 1);
			exit(0);
		}
		while (!g_flag)
			;
		g_flag = 0;
		i--;
	}
}

void	send_message(char *msg, int pid)
{
	while (*msg)
	{
		send_char(*msg, pid);
		msg++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: a.out <PID> <message>\n", 1);
		return (1);
	}
	pid = atoi(argv[1]);
	if (pid <= 0)
	{
		ft_putstr_fd("Invalid PID\n", 1);
		return (1);
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	send_message(argv[2], pid);
	return (0);
}
