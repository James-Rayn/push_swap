#include "push_swap.h"

static t_node *create_node(int value)
{
    t_node *node;

    node = malloc(sizeof(t_node));
    if (!node)
        return (NULL);
    node-> value = value;
    node-> next =  NULL;
    return (node);
}

void    push(t_stack *stack, int value)
{
    t_node *node;

    node = create_node(value);
    if (!node)
        return ;
    node-> next = stack-> top;
    stack-> top = node;   
    stack-> size++;
}

int    pop(t_stack *s)
{
    t_node *temp;
    int     value;

    if (!s || !s-> top)
        return (0);
    temp = s-> top;
    value = temp-> value;
    s-> top = temp-> next;
    free(temp);
    s-> size--;
    return (value);
}

t_stack *init_stack(void)
{
    t_stack *s;
    
    s = malloc(sizeof(t_stack));
    if (!s)
        return (NULL);
    s-> top = NULL;
    s-> size = 0;
    return (s);
}

void    free_stack(t_stack *s)
{
    if (!s)
        return ;
    while (s-> top)
        pop(s);
    free(s);
}