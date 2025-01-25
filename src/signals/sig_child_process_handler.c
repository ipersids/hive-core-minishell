/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_child_process_handler.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:38:05 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/25 02:43:09 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief Sets the signal handlers for child processes.
 * 
 * This function sets the signal handlers for child processes based on whether
 * the shell is running in interactive mode or not. In interactive mode, 
 * it ignores SIGINT and SIGQUIT signals. In non-interactive mode, it sets 
 * the default handlers for these signals.
 * 
 * @param is_interactive_mode Indicates if the shell mode.
 */
void	sig_child_process_handler(int is_interactive_mode)
{
	if (is_interactive_mode)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}
