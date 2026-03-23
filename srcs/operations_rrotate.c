#include "push_swap.h"

static void    reverse_rotate(t_stack *s)
{
    t_node *prev;
    t_node *curr;

    if (!s || !s-> top || !s-> top-> next)
        return ;
    prev = NULL;
    curr = s-> top;
    while (curr-> next)
    {
        prev = curr;
        curr = curr-> next;
    }
    prev-> next = NULL;
    curr-> next = s-> top;
    s-> top = curr;
}

void    rra(t_stack *a, t_bench *bench)
{
    reverse_rotate(a);
    bench-> rra++;
    write(1, "rra\n", 4);
}

void    rrb(t_stack *b, t_bench *bench)
{
    reverse_rotate(b);
    bench-> rrb++;
    write(1, "rrb\n", 4);
}

void    rrr(t_stack *a, t_stack *b, t_bench *bench)
{
    if (!a || !b)
        return ;
    reverse_rotate(a);
    reverse_rotate(b);
    bench-> rrr++;
    write(1, "rrr\n", 4);
}
