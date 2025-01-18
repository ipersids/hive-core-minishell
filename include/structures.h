/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipersids <ipersids@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:35:41 by ipersids          #+#    #+#             */
/*   Updated: 2025/01/19 00:33:18 by ipersids         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

/* ------------------------------ Environment ------------------------------ */

typedef struct s_env
{
	char			**envp;
	unsigned int	len;
	unsigned int	capacity;	
}	t_env;

/* ------------------------------- Minishell ------------------------------- */

typedef struct s_mshell
{
	t_env	env;
	int		exit_code;
	int		is_parent;
}			t_mshell;


#endif