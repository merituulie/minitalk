/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:52:05 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/05 17:01:56 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "client.h"
#include "libft/libft.h"

static int	get_pid(char *pid)
{
	int	server_pid;

	server_pid = ft_atoi(pid);
	if (server_pid == -1 || server_pid == 0
		|| server_pid > 99998 || kill(server_pid, 0) == -1)
		exit(EXIT_FAILURE);
	return (server_pid);
}

static void	send_terminator(int pid, int len)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR1);
		usleep(len);
		i++;
	}
}

static void	send_character(char ch, int pid, int len)
{
	int	i;

	i = 0;
	if (!ft_isascii(i))
	{
		ft_putstr_fd("Encountered a non-ascii value\n", 31, 1);
		return ;
	}
	while (i < 8)
	{
		if (((ch >> i) & 1) == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(len);
		i++;
	}
}

static int	send_signal(int pid, int len, char *input)
{
	unsigned int	j;
	char			ch;

	j = 0;
	while (input[j])
	{
		ch = input[j];
		send_character(ch, pid, len);
		usleep(len);
		j++;
	}
	usleep(len);
	send_terminator(pid, len);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	len;

	if (argc != 3)
		exit(EXIT_FAILURE);
	if (argv[2][0] == '\0')
		exit(EXIT_SUCCESS);
	pid = get_pid(argv[1]);
	len = WAIT + (ft_strlen(argv[2]) / 200);
	if (!send_signal(pid, len, argv[2]))
		return (1);
	return (0);
}
