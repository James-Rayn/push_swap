#include "push_swap.h"

static void swap(t_stack *s)
{
    int temp;

    if (s-> size < 2)
        return ;
    temp = s-> top-> value;
    s-> top-> value = s-> top-> next-> value;
    s-> top-> next-> value = temp;
}

void    sa(t_stack *a)
{
    swap(a);
    write(1, "sa\n", 3);
}

void    sb(t_stack *b)
{
    swap(b);
    write(1, "sb\n", 3);
}

void    ss(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    swap(a);
    swap(b);
    write(1, "ss\n", 3);
}