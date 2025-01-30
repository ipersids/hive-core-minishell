/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 18:41:18 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/30 06:18:24 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# include <limits.h>

# ifndef PATH_MAX
#  define PATH_MAX 1024
# endif

extern volatile sig_atomic_t	g_status;

typedef enum e_error_code
{
	ERROR_GENERIC = 1,
	ERROR_INVALID_OPTION = 2,
	ERROR_MALLOC_FAILS = 12,
	ERROR_CMD_NOT_FOUND = 127,
	ERROR_INVALID_EXIT_CODE = 255
}	t_error_code;

typedef enum e_sig_mode
{
	SIG_INTERACTIVE_MODE,
	SIG_HEREDOC_MODE,
	SIG_DEFAULT_MODE
}	t_sig_mode;

# ifndef FD_READ
#  define FD_READ 0
# endif

# ifndef FD_WRITE
#  define FD_WRITE 1
# endif

# ifndef FORK_LEFT
#  define FORK_LEFT 0
# endif

# ifndef FORK_RIGHT
#  define FORK_RIGHT 1
# endif

# ifndef EXIT_CODE_CASE
#  define EXIT_CODE_CASE "$?"
# endif

#endif