/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zserobia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 14:23:06 by zserobia          #+#    #+#             */
/*   Updated: 2024/11/23 14:23:08 by zserobia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_all_digits(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	mini_exit(t_simple_cmds *simple_cmd, t_shell *shell)
{
	int i;
	
	i = 1;
	if (!simple_cmd->str[i])
	{
		printf("exit\n");
		ft_free_tous(&shell);
		exit(0);
	}
	if (is_all_digits(simple_cmd->str[i]))
	{
		char	*endptr;
		long	exit_code;
		
		exit_code = strtol(simple_cmd->str[i], &endptr, 10);
		if (simple_cmd->str[i + 1])
		{
			printf("exit\nbash: exit: too many arguments\n");
			exit (1);
		}
		printf("exit\n");
		ft_free_tous(&shell);
		exit((int)exit_code);
	}
	else
	{
		printf("exit\nbash: exit: %s: numeric argument required\n", simple_cmd->str[i]);
		ft_free_tous(&shell);
		exit(2);
	}
}


/*if (strcmp(simple_cmd->str[0], "exit") == 0) {
    return mini_exit(simple_cmd, shell);  // Завершаем программу, вызываем exit
}
*/
