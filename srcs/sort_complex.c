#include "push_swap.h"

int bit_count(int n)
{
    int count;

    count = 0;
    while (n > 0)
    {
        count++;
        n = n >> 1;
    }
    return (count);
}

void    sort_complex(t_stack *a, t_stack *b)
{
    int i;
    int j;
    int bits;

    if (!a || !a-> top || !b)
        return;
    normalize(a);
    bits = bit_count(find_max(a));
    i = 0;
    while (i< bits)
    {
        j = a-> size;
        while (j > 0)
        { 
            if (((a-> top-> value >> i) & 1) == 0)
                pb(a, b);
            else
                ra(a);
            j--;
        }
        while (b-> size > 0)
        { 
            pa(a, b);
            //rra(a);
        }
        i++;
    }
}