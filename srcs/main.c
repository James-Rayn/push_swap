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
    int     start;
    t_stack *a;
    t_stack *b;

    if (argc < 2)
        return (0);
    start = 1;
    if (argv[1][0] == '-' && argv[1][1] == '-')
        start = 2;
    a = parse_args(argc - start + 1, argv + start - 1);
    if (!a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    b = init_stack();
    if (start == 2)
    {
        if (ft_strcmp(argv[1], "--simple") == 0)
            sort_simple(a, b);
        else if (ft_strcmp(argv[1], "--medium") == 0)
            sort_medium(a, b);
        else if (ft_strcmp(argv[1], "--complex") == 0)
            sort_complex(a, b);
        else
            sort_adaptive(a, b);
    }
    else
        sort_adaptive(a, b);
    free_stack(a);
    free_stack(b);
    return (0);
}