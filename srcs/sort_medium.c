#include "push_swap.h"

void    normalize(t_stack *s)
{
    int index;
    t_node *curr;
    t_node *par;

    if(!s || !s-> top)
        return;
    curr = s-> top;
    while (curr)
    {
        index = 0;
        par = s-> top;
        while (par)
        {
            if (curr-> value > par-> value)
                index++;
            par = par-> next;
        }
        curr-> value = index;
        curr= curr-> next;
    }
}

int chunk_size(t_stack *s)
{
    if (!s)
        return (0);
    return(ft_sqrt(s-> size));
}

void    push_chunk(t_stack *a, t_stack *b, t_bench *bench, int min, int max)
{
    int size;

    if (!a || !a-> top || !b)
        return ;
    size = a-> size;
    while (size--)
    {
        if (a-> top-> value >= min && a-> top-> value <= max)
            pb(a, b, bench);
        else
            ra(a, bench);
    }
}

static void    push_max_from_b(t_stack *a, t_stack *b, t_bench *bench)
{
    int max;
    int pos;
    int mid;

    max = find_max(b);
    pos = find_pos(b, max);
    mid = b-> size / 2;
    if (pos <= mid)
    {
        while (b-> top-> value != max)
            rb(b, bench);
    }
    else
    {
        while (b-> top-> value != max)
            rrb(b, bench);
    }
    pa(a, b, bench);
}

void    sort_medium(t_stack *a, t_stack *b, t_bench *bench)
{
    int csize;
    int min;
    int max;

    if (!a || !a-> top || !b)
        return;
    normalize(a);
    csize = chunk_size(a);
    min = 0;
    max = csize - 1;
    while (a-> size > 0)
    {
        push_chunk(a, b, bench, min, max);
        min = max + 1;
        max = max + csize;
    }
    while(b-> size > 0)
        push_max_from_b(a, b, bench);
}