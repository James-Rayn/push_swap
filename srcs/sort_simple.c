#include "push_swap.h"

int find_max(t_stack *s)
{
    int     max;
    t_node *temp;

    if (!s || !s-> top)
        return (0);
    temp = s-> top;
    max = temp-> value;
    while (temp)
    {
        if (temp-> value > max)
            max = temp-> value;
        temp = temp-> next;
    }
    return (max);
}

int find_pos(t_stack *s, int value)
{
    int     pos;
    t_node  *curr;

    if (!s)
        return (-1);
    pos = 0;
    curr = s-> top;
    while (curr)
    {
        if (curr-> value == value)
            return (pos);
        pos++;
        curr = curr-> next;
    }
    return (-1);
}

void    push_max(t_stack *a, t_stack *b, t_bench *bench)
{
    int max;
    int pos;
    int mid;

    max = find_max(a);
    pos = find_pos(a, max);
    mid = a-> size / 2;
    if (pos <= mid)
    {
        while (a-> top-> value != max)
            ra(a, bench);
    }
    else
    {
        while (a-> top-> value != max)
            rra(a, bench);
    }
    pb(a, b, bench);
}

void    sort_simple(t_stack *a, t_stack *b, t_bench *bench)
{
    while (a-> size > 0)
        push_max(a, b, bench);
    while (b-> size > 0)
        pa(a, b, bench);
}