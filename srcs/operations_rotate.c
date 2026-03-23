#include "push_swap.h"

static void    rotate(t_stack *s)
{
    t_node *temp;
    t_node *last;
    
    if (!s || !s-> top || !s-> top-> next)
        return ;
    temp = s-> top;
    s-> top = s-> top-> next;
    last = s-> top;
    while (last-> next)
        last = last-> next;
    last-> next = temp;
    temp-> next = NULL;
}

void    ra(t_stack *a, t_bench *bench)
{
    rotate(a);
    bench-> ra++;
    write(1, "ra\n", 3);
}

void    rb(t_stack *b, t_bench *bench)
{
    rotate(b);
    bench-> rb++;
    write(1, "rb\n", 3);
}

void    rr(t_stack *a, t_stack *b, t_bench *bench)
{
    if (!a || !b)
        return ;
    rotate(a);
    rotate(b);
    bench-> rr++;
    write(1, "rr\n", 3);
}