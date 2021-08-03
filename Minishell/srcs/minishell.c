/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:40:20 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/21 20:35:55 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/minishell.h"
/*

int		user_historial(char **line, t_list *list)
{
	int	l;

	//get_next_line(0, line);
	l = read(0, line, 100);
	write(1, line, l);
	if (!list)
		ft_lstnew(*line);
	else
		ft_lstadd_front(&list, ft_lstnew(*line));
	return(1);
}


int		main(void)
{
	t_list	list;
	char	*line;
	struct termios term;
	//char	*term_name = "xterm-256color";

	write(1, "Minishell: ", 11);
	tcgetattr(0, &term);
	term.c_lflag &= ~(ECHO); //con esto desactivamos el modo echo de la terminal y no nos dejara ver lo que escribimos en stdin
	term.c_lflag &= ~(ICANON);
	term.c_cc[VMIN] = 1; //Con esto decimos cuantos caracteres antes de que imprima nada
	term.c_cc[VTIME] = 0;
	tcsetattr(0, TCSANOW, &term);
	line = NULL;
	//tgetent(0, term_name);
	user_input(&line, &list);
	while (1)
	{
		user_input(&line, &list);
	}
	return (0);
}*/

char	**get_all_path(char **envp, char *search)
{
	int		i;
	char	**str;

	i = get_position(envp);
	str = ft_split(envp[i], ':');
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

void reset_prompt()
{
	minishell_steps();
}

void start_prompt()
{
	write (1, "ft_bash-3.2$ \n", 1);
}

void	print_matrix(char **str)
{
	int j, i;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			write(1, &str[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}

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

	i = 0;
	(void)argc;
	(void)argv;
	if (argc != 1)
		print_exit("Arranque mnishell sin argumetos\n");
	shell.envv = (char **)malloc(sizeof(char *) * (ft_envlen(env) + 1));
	while (env[i])
	{
		shell.envv[i] = ft_strdup(env[i]);
		if (!(shell.envv[i]))
			print_exit("El programa fallo en funcion fill_struct\n");
		i++;
	}
	shell.path_bin = get_all_path(env, "PATH=");
	shell.path_bin[0] = strchr(shell.path_bin[0], '/');
	return (shell);
}

void	minishell_steps()
{
	start_prompt();
	//read_in();
	//lexical
	//parser
	//execute
}

int		main(int argc, char **argv, char **env)
{
	t_minishell shell;
	char	**g_env;

	shell = fill_struct(argc, argv, env);
	while (1)
	{
		minishell_steps();
		signal(SIGINT, reset_prompt);
	}
	print_matrix(g_env);
	return (0);
}
