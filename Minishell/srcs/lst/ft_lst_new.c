#include "../../headers/lst.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*element;

	if (!(element = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	element->content = content;
	element->next = NULL;
	element->prev = NULL;
	return (element);
}
