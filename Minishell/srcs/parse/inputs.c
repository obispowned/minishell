/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:47:20 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/15 19:58:01 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/*void		free_tab(char **str)
{
	char	**tabb;

	tabb = str;
	while (*tabb)
	{
		free(*tabb);
		tabb++;
	}
	free(tabb);
}*/

/*
**	Recibe una serie de cadenas y devuelve esa misma matriz pero con su contenido modificado.
**	Ahora, cada cadena que comenzó con uno o varios espacios comienza sin ellos.
*/
/*static char	**tab_remove_front_spaces(char **str)
{
	char	**tabb;
	char	*str;
	char	*aux;

	tabb = str;
	while (*str)
	{
		aux = *str;
		while (**str == ' ' || **str == '\t')
			(*str)++;
		str = ft_strdup(*str);
		free(aux);
		*str = str;
		str++;
	}
	return (tabb);
}*/

/*
**	Recibe una serie de cadenas y devuelve esa misma matriz pero con su contenido modificado.
**	Ahora, cada cadena que no tenga más de una palabra tiene todos sus espacios eliminados,
**	y aquellas cadenas con más de una palabra, solo tiene un espacio entre la primera y la segunda.
*/
/*
static char	**tab_remove_middle_spaces(char **t, char **fixed_t)
{
	char	*str;
	char	*aux;
	int		i;

	while (*t)
	{
		i = 0;
		aux = *t;
		while ((*t)[i] && (*t)[i] != ' ')
			i++;
		if ((*t)[i] == ' ' && (*t)[i + 1] == ' ')
		{
			(*t)[i++] = 0;
			while ((*t)[i] == ' ' && (!(*t)[i + 1] || (*t)[i + 1] == ' '))
				i++;
			str = ft_strjoin(*t, (*t) + i);
		}
		else
			str = ft_strdup(*t);
		free(aux);
		*t = str;
		t++;
	}
	return (fixed_t);
}*/


/*
**	Recibe una serie de cadenas y devuelve esa misma matriz pero con su contenido modificado.
**	Ahora cada cadena que terminó con uno o varios espacios termina sin ellos.
*/
/*static char	**tab_remove_last_spaces(char **str, char **ads)
{
	while (*str)
	{
		*str = str_flip(*str);
		str++;
	}
	str = tab_remove_front_spaces(ads);
	while (*str)
	{
		*str = str_flip(*str);
		str++;
	}
	return (ads);
}*/

/*
**	Recibe el puntero a una matriz de cadenas y lo llena con la lectura de la entrada del usuario (tab),
**	el usuario puede escribir muchos comandos separados por ';' y shell debe ejecutarlo por separado
**	La funcion devuelte un puntero a ese (tab);
*/
/*char		**user_input(char **str)
{
	int		sz;
	char	input[ARG_MAX];

	write(1, "-> $ ", 5);
	if ((sz = read(0, input, ARG_MAX)) < 0)
	{
		printf("Error: unable to read the input.\n");
		return (NULL);
	}
	else
	{
		input[sz - 1] = 0;
		*str = tab_remove_front_spaces(ft_split(input, ';'));
		*str = tab_remove_middle_spaces(*str, *str);
		*str = tab_remove_last_spaces(*str, *str);
	}
	return (*str);
}*/
