/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:41:24 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/15 08:45:05 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler_main(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (SIGINT == sig)
	{
		g_status = sig;
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (SIGQUIT == sig)
	{
		g_status = sig;
		return ;
	}
}
