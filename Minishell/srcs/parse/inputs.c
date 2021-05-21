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

# include "minishell.h"


/*
**	Recibe un array de strings y libera todo.
*/
void		free_tab(char **tab)
{
	char	**fixed_tab;

	fixed_tab = tab;
	while (*tab)
	{
		free(*tab);
		tab++;
	}
	free(fixed_tab);
}

/*
**	Recibe una serie de cadenas y devuelve esa misma matriz pero con su contenido modificado.
**	Ahora, cada cadena que comenzó con uno o varios espacios comienza sin ellos.
*/
static char	**tab_remove_front_spaces(char **tab)
{
	char	**fixed_tab;
	char	*str;
	char	*aux;

	fixed_tab = tab;
	while (*tab)
	{
		aux = *tab;
		while (**tab == ' ' || **tab == '\t')
			(*tab)++;
		str = ft_strdup(*tab);
		free(aux);
		*tab = str;
		tab++;
	}
	return (fixed_tab);
}

/*
**	Recibe una serie de cadenas y devuelve esa misma matriz pero con su contenido modificado.
**	Ahora, cada cadena que no tenga más de una palabra tiene todos sus espacios eliminados,
**	y aquellas cadenas con más de una palabra, solo tiene un espacio entre la primera y la segunda.
*/
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
}


/*
**	Recibe una serie de cadenas y devuelve esa misma matriz pero con su contenido modificado.
**	Ahora cada cadena que terminó con uno o varios espacios termina sin ellos.
*/
static char	**tab_remove_last_spaces(char **tab, char **fixed_tab)
{
	while (*tab)
	{
		*tab = str_flip(*tab);
		tab++;
	}
	tab = tab_remove_front_spaces(fixed_tab);
	while (*tab)
	{
		*tab = str_flip(*tab);
		tab++;
	}
	return (fixed_tab);
}

/*
**	Recibe el puntero a una matriz de cadenas y lo llena con la lectura de la entrada del usuario (tab),
**	el usuario puede escribir muchos comandos separados por ';' y shell debe ejecutarlo por separado
**	La funcion devuelte un puntero a ese (tab);
*/
char		**user_input(char ***tab)
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
		*tab = tab_remove_front_spaces(ft_split(input, ';'));
		*tab = tab_remove_middle_spaces(*tab, *tab);
		*tab = tab_remove_last_spaces(*tab, *tab);
	}
	return (*tab);
}
