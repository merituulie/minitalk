/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meskelin <meskelin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 17:52:02 by meskelin          #+#    #+#             */
/*   Updated: 2023/06/12 10:42:01 by meskelin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <limits.h>
#include "libft/libft.h"

static char	*add_character(char *input, int len, int i)
{
	char	*temp;

	temp = NULL;
	temp = (char *)malloc(sizeof(*temp) * len + 1);
	if (!temp)
		exit(EXIT_FAILURE);
	if (input)
		temp = ft_memcpy(temp, input, len);
	if (!temp)
		exit(EXIT_FAILURE);
	temp[len - 1] = i;
	temp[len] = '\0';
	if (input)
		free(input);
	input = NULL;
	return (temp);
}

static void	handle_signal(int signal)
{
	static int	bit;
	static int	i;
	static char	*input;
	static int	len;

	if (signal == SIGUSR2)
		i |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		len++;
		input = add_character(input, len, i);
		if (i == '\0')
		{
			ft_putstr_fd(input, len, 1);
			if (input)
				free(input);
			input = NULL;
			len = 0;
		}
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	action;
	struct sigaction	old_action;

	pid = getpid();
	if (pid == -1)
		exit(EXIT_FAILURE);
	ft_putnbr_fd(pid, 1);
	ft_putchar_fd('\n', 1);
	sigemptyset(&action.sa_mask);
	sigaddset(&action.sa_mask, SIGUSR1);
	sigaddset(&action.sa_mask, SIGUSR2);
	action.sa_handler = &handle_signal;
	if (sigaction(SIGUSR1, &action, &old_action))
		ft_putstr_fd("SIGUSR1 error\n", 14, 1);
	if (sigaction(SIGUSR2, &action, &old_action))
		ft_putstr_fd("SIGUSR2 error\n", 14, 1);
	while (1)
		pause();
}
