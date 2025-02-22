/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkhalfao <dkhalfao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:27:28 by dkhalfao          #+#    #+#             */
/*   Updated: 2025/02/18 17:47:18 by dkhalfao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	append_bit(int sig, char *byte, int *bit_count)
{
	*byte = (*byte << 1) | (sig == SIGUSR1);
	(*bit_count)++;
}

void	print_msg(char *byte, int *bit_count, int sender_pid, int *is_new_msg)
{
	if (*bit_count == 8)
	{
		if (*byte == '\0')
		{
			write(1, "\n", 1);
			*is_new_msg = 1;
		}
		else
		{
			if (*is_new_msg)
			{
				ft_putstr_fd("from client [", 1);
				ft_putnbr_fd(sender_pid, 1);
				ft_putstr_fd("] :", 1);
				*is_new_msg = 0;
			}
			write(1, byte, 1);
		}
		*byte = 0;
		*bit_count = 0;
	}
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	byte = 0;
	static int	bit_count = 0;
	static int	sender_pid = 0;
	static int	is_new_msg = 1;

	(void)context;
	if (sender_pid != info->si_pid)
	{
		sender_pid = info->si_pid;
		byte = 0;
		bit_count = 0;
		is_new_msg = 1;
	}
	append_bit(sig, &byte, &bit_count);
	print_msg(&byte, &bit_count, sender_pid, &is_new_msg);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
	return (0);
}
