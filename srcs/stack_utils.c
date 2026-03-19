#include "push_swap.h"

int is_valid_int(char *str)
{
    int i;

    i = 0;
    if (str[i] == '-' || str[i] == '+')
        i++;
    if (!str[i])
        return (0);
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return (0);
        i++;
    }
    return (1);
}

int is_in_range(char *str)
{
    long    n;

    n = ft_atol(str); 
    if (n > 2147483647 || n < -2147483648)
        return (0);
    return (1);
}

int has_duplicate(t_stack *s, int value)
{
    t_node *curr;

    curr = s-> top;
    while (curr)
    {
        if (curr-> value == value)
            return (1);
        curr = curr-> next;
    }
    return (0);
}
