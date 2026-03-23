#include "push_swap.h"

void    pa(t_stack *a, t_stack *b, t_bench *bench)
{
    if (!a || !b || b-> size == 0)
        return ;
    push(a, pop(b));
    bench-> pa++;
    write(1, "pa\n", 3);
}

void    pb(t_stack *a, t_stack *b, t_bench *bench)
{
    if (!a || !b || a-> size == 0)
        return ;
    push(b, pop(a));
    bench-> pb++;
    write(1, "pb\n", 3);
}
