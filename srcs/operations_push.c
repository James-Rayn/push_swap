#include "push_swap.h"

void    pa(t_stack *a, t_stack *b)
{
    if (!a || !b || b-> size == 0)
        return ;
    push(a, pop(b));
    write(1, "pa\n", 3);
}

void    pb(t_stack *a, t_stack *b)
{
    if (!a || !b || a-> size == 0)
        return ;
    push(b, pop(a));
    write(1, "pb\n", 3);
}
