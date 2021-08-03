#include "../../headers/minishell.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	t_list	*aux;

	aux = *alst;
	*alst = new;
	new->next = aux;
	aux->prev = new;
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list		*p;

	p = ft_lstlast(alst);
	if (new)
	{
		if (*alst != NULL)
		{
			p->next = new;
			new->next = NULL;
			new->prev = p;
		}
		else
		{
			*alst = new;
			new->next = NULL;
			new->prev = NULL;
		}
	}
}

t_list	*ft_lstlast(t_list **lst)
{
	t_list	*p;

	p = (*lst);
	if (p)
	{
		while (p->next != NULL)
			p = p->next;
		return (p);
	}
	else
		return (0);
}
