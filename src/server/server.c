/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 16:00:56 by marvin            #+#    #+#             */
/*   Updated: 2021/09/07 19:22:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*print_string(char *message)
{
	ft_putstr_fd(message, 1);
	ft_putchar_fd('\n', 1);
	free(message);
	return (NULL);
}

void	send_signal(int pid, int signum)
{			
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid = 0;
	static char	*message = 0;

	(void)context;
	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bit;
	if (++bit == 8)
	{
		if (!c)
		{
			message = print_string(message);
			send_signal(pid, SIGUSR2);
		}
		else
			message = ft_strcat_char(message, c);
		bit = 0;
		c = 0xFF;
	}
	send_signal(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sig;
	pid_t				pid;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	pid = getpid();
	ft_putstr_fd("PID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	while (1)
		pause();
}
