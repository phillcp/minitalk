/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 17:04:41 by marvin            #+#    #+#             */
/*   Updated: 2021/09/07 19:12:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	static int	flag = 1;

	if (signum == SIGUSR1 && flag)
	{
		ft_putstr_fd("\nMessage sent ", 1);
		flag = 0;
	}
	if (signum == SIGUSR2)
	{
		ft_putstr_fd("-> Message recieved \n", 1);
		flag = 1;
		exit(EXIT_SUCCESS);
	}
}

void	send_bits(char *message, int pid)
{
	int	i;
	int	bit;

	bit = -1;
	i = 0;
	if (!message)
		exit(EXIT_FAILURE);
	while (1)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(1);
			usleep(100);
		}
		if (!message[i])
			break ;
		++i;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || !ft_str_isdigit(argv[1]))
	{
		ft_putstr_fd("Invalid Arguments!\n", 1);
		ft_putstr_fd("./client [PID] [STR]\n", 1);
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	pid = ft_atoi(argv[1]);
	send_bits(argv[2], pid);
}
