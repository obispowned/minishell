/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agutierr <agutierr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 20:58:10 by agutierr          #+#    #+#             */
/*   Updated: 2021/08/05 21:19:42 by agutierr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../headers/minishell.h"

void	print_exit(char *str)
{
	printf("%s", str);
	exit(0);
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