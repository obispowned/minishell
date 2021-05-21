/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:40:54 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/21 18:07:34 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <term.h>
# include <termios.h>
# include "headers/lst.h"
# include "headers/libft.h"

#define ARG_MAX 262144

typedef struct	s_minishell
{
	int			parser_block;
	int			dollar_question;
	char		**fixed_tab;
	char		**str_variables;
	char		**fixed_str_variables;
	int			**int_variables;
	int			**fixed_int_variables;
}				t_minishell;


/*
**	Inicializacion.c
*/

void			minishell_init(t_minishell *m);

int		user_input(char **line, t_list *list);
char	*ft_strdup(const char *src);
int		print_line(char **file, char **line, int i);
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, unsigned int len);


#endif
