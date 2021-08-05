/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:40:54 by agutierr          #+#    #+#             */
/*   Updated: 2021/08/05 21:21:00 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include <string.h>
# include <fcntl.h>
# include <term.h>
# include <termios.h>
# include "lst.h"
# include "libft.h"

#define ARG_MAX 262144

typedef struct	s_minishell
{
	char **envv;		//aqui guardo todas las variables de entorno
	char **path_bin;     //aqui guardo las rutas de PATH, cada una en un string
	char *user_input;	//aqui guardamos la tarea que ingresa el usuario

}				t_minishell;

/*
**	main run
*/
void read_in(void);
void reset_prompt(void);
void start_prompt(void);
void	minishell_steps(void);

/*
**
*/
int		get_next_line(int fd, char **line);

/*
**	env.c
*/
char		**get_all_path(char **envp);
int			check_line(char *envp);
int			get_position(char **envp);
static int	ft_envlen(char **envv);
t_minishell	fill_struct(int argc, char **argv, char **env);

/*
**	prints
*/
int		print_line(char **file, char **line, int i);
void	print_exit(char *str);
void	print_matrix(char **str);


#endif
