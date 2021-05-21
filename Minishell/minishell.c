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

# include "minishell.h"



/*int	minishell(char *line)
{

}*//*
static int	set_terminal_mode(struct termios term, const int mode)
{
	char*	term_name;

	if (mode == 0)
	{
		if ((term_name = getenv("TERM")) == NULL)
			return (-1);
		ioctl(0, TCGETS, &shell->term);
		term.c_lflag &= ~ICANON;
		term.c_cc[VMIN] = 1;
		term.c_cc[VTIME] = 0;
		ioctl(0, TCGETS, &shell->term_save);
		ioctl(0, TCSETS, &shell->term);
	}
	if (mode == 1)
		ioctl(0, TCSETS, &term.term_save);
	return (0);
}
*/

int		user_input(char **line, t_list *list)
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
		//write(1, "Minishell: ", 11);
/*		else							GESTION DE ERRORES Y PROGRAMA EN SI
			minishell(line);*/
		user_input(&line, &list);
	}
	return (0);
}
