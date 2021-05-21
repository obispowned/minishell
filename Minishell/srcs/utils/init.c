/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 19:47:46 by agutierr          #+#    #+#             */
/*   Updated: 2021/05/20 21:53:14 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	minishell_init(t_minishell *m)
{
	int	i;

	if (!(m->str_variables = malloc(sizeof(char *) * (1000 + 1))))
		return ;
	if (!(m->int_variables = malloc(sizeof(int *) * (1000 + 1))))
		return ;
	m->fixed_str_variables = m->str_variables;
	m->fixed_int_variables = m->int_variables;
	i = 0;
	while (i < 1000)
	{
		*(m->str_variables) = 0;
		*(m->int_variables) = 0;
		m->str_variables++;
		m->int_variables++;
		i++;
	}
}
