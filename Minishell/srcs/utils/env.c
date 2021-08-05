/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:57:52 by agutierr          #+#    #+#             */
/*   Updated: 2021/08/05 21:21:30 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/minishell.h"

char	**get_all_path(char **envp)
{
	int		i;
	char	**str;

	i = get_position(envp);
	str = split(envp[i], ':');
	return (str);
}

int	check_line(char *envp)
{
	int		i;
	char	*path;

	path = "PATH=";
	i = 0;
	while (i < 5)
	{
		if (path[i] != envp[i])
			return (0);
		i++;
	}
	return (1);
}

int	get_position(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (check_line (envp[i]))
			return (i);
		i++;
	}
	return (-1);
}

static int		ft_envlen(char **envv)
{
	int		i;
	int		count;

	i = -1;
	count = 0;
	while (envv[++i])
		count++;
	return (count);
}

t_minishell	fill_struct(int argc, char **argv, char **env)
{
	t_minishell shell;
	int		i;
    int     len; //si lo uso sin len me da error en los flags porque no me reconoce que lo use

    len = ft_envlen(env);
	i = 0;
	(void)argc;
	(void)argv;
	if (argc != 1)
		print_exit("Arranque mnishell sin argumetos\n");
	shell.envv = (char **)malloc(sizeof(char *) * (len + 1));
	while (env[i])
	{
		shell.envv[i] = ft_strdup(env[i]);
		if (!(shell.envv[i]))
			print_exit("El programa fallo en funcion fill_struct\n");
		i++;
	}
	shell.path_bin = get_all_path(env);
	shell.path_bin[0] = strchr(shell.path_bin[0], '/');
	return (shell);
}