/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mquero <mquero@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 08:53:14 by mquero            #+#    #+#             */
/*   Updated: 2025/01/27 11:21:07 by mquero           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

volatile sig_atomic_t	g_status = 0;

void print_values(char **values) 
{
    if (values) {
        for (int i = 0; values[i] != NULL; i++) {
            printf("%s", values[i]);
            if (values[i + 1] != NULL) {
                printf(", "); // Separate multiple values with a comma
            }
        }
    }
}

void print_ast(t_ast *node, int depth)
{
    if (node == NULL) {
        return;
    }
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("Type: %d, Value: ", node->type);
    print_values(node->value);
    printf("\n");
    if (node->left || node->right) {
        print_ast(node->left, depth + 1);
        print_ast(node->right, depth + 1);
    }
}
int	main(int argc, char **argv, char **envp)
{
	struct sigaction	sa;
	char				*line; // add to t_mshell as input
    t_ast				*root; // add to t_mshell as root
	t_mshell			ms;

	if (argc != 1 || !argv || !envp)
	{
		ft_putstr_fd("Usage: ./minishell\n", 2);
		exit(EXIT_FAILURE);
	}
	init_minishell_struct(&ms, envp);
	sig_sigaction_init(&sa, sig_handler_main);
	while (1)
	{
		root = NULL;
		line = readline("minishell> ");
		if (line == NULL)
			break ;
		if (line[0] == '\0')
		{
			free(line);
			continue;
		}
        root = parse_input(line); /** @bug if nothing allocated better to return NULL; case ./minishell <ENTER> (line is empty) */
        //print_ast(root, 0);
		printf("\n------------\n");
		exe_ast_tree(root, &ms);
		printf("exit code: %d\n", ms.exit_code);
		add_history(line);
		//free(line);
		free_ast(root); /** @bug set root to NULL in free_ast to avoid segfault in ./minishell <cntr+D> case */
	}
	rl_clear_history(); // call from exit_destroy_minishell(&ms)
	free(line); // call from exit_destroy_minishell(&ms)
	exit_destroy_minishell(&ms);
	free_ast(root); // call from exit_destroy_minishell(&ms)
	write(1, "Good luck!\n", 11);
	return (0);
}
