#include "push_swap.h"

static double  compute_disorder(t_stack *s)
{
    int     error;
    int     peer;
    t_node  *curr;
    t_node  *next;

    if (!s || !s-> top)
        return (0.0);
    curr = s-> top;
    error = 0;
    peer = 0;
    while (curr)
    {
        next = curr-> next;
        while (next)
        {
            if (curr-> value > next-> value)
                error++;
            peer++;
            next = next-> next;
        }
        curr = curr-> next;
    }
    if (peer == 0)
        return (0.0);
    return((double)error / peer);
}

void    sort_adaptive(t_stack *a, t_stack *b)
{
    double  disorder;

    if (!a || !a-> top || !b)
        return ;
    disorder = compute_disorder(a);
    if (disorder < 0.2)
        sort_simple(a, b);
    else if (disorder < 0.5)
        sort_medium(a, b);
    else
        sort_complex(a, b);
}