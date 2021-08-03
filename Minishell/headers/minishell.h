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
	char **envv;
	char *path_bin;

}				t_minishell;

/*
**
*/
int		get_next_line(int fd, char **line);

/*
**	Inicializacion.c
*/

/*
**	prints
*/
int		print_line(char **file, char **line, int i);


#endif
