/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:40:20 by agutierr          #+#    #+#             */
/*   Updated: 2021/08/05 21:11:00 by agutierr         ###   ########.fr       */
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

void read_in(void)
{
	
}

void reset_prompt(void)
{
	minishell_steps();
}

void start_prompt(void)
{
	write (1, "minishell>$: ", 1);
}

void	minishell_steps(void)
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

	shell = fill_struct(argc, argv, env);
	while (1)
	{
		minishell_steps();
		signal(SIGINT, &reset_prompt);
	}
	print_matrix(shell.envv);
	return (0);
}
