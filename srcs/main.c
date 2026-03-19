#include "push_swap.h"
#include <stdio.h>

void    print_stack(t_stack *s)
{
    t_node *curr;

    curr = s-> top;
    while (curr)
    {
        printf("%d ", curr-> value);
        curr = curr-> next;
    }
}

static t_stack *parse_args(int argc, char **argv)
{
    t_stack *s;
    int     i;
    int     value;

    s = init_stack();
    i = 1;
    while (i < argc)
    {
        if (!is_valid_int(argv[i]) || !is_in_range(argv[i]))
            return (free_stack(s), NULL);
        value = ft_atol(argv[i]);
        if (has_duplicate(s, value))
            return (free_stack(s), NULL);
        push(s, value);
        i++;
    }
    return (s);
}

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    a = parse_args(argc, argv);
    if (!a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    b = init_stack();
    sort_simple(a, b);
    free_stack(a);
    free_stack(b);
    return (0);
}