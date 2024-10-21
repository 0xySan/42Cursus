#include "libft.h"
#include <stdio.h>

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list = NULL;
    t_list *new_node;
    t_list *current;
    t_list **temp;

    if (!lst || !f)
        return (NULL);

    current = lst;
    while (current)
    {
        new_node = ft_lstnew(f(current->content));
        if (!new_node)
        {
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        temp = &new_list;
        while (*temp)
            temp = &(*temp)->next;
        *temp = new_node;
        
        current = current->next;
    }
    return (new_list);
}