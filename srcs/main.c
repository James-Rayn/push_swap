#include "push_swap.h"

static int  has_bench_flag(int argc, char **argv)
{
    int i;

    i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--bench") == 0)
            return (1);
        i++;
    }
    return (0);
}

static char    *get_strategy(char *flag)
{
    if (ft_strcmp(flag, "--simple") == 0)
        return ("simple | O(n^2)");
    else if (ft_strcmp(flag, "--medium") == 0)
        return ("medium | O(n sqrt n)");
    else if (ft_strcmp(flag, "--complex") == 0)
        return ("complex | O(n log n)");
    return ("adaptive | O(n log n)");
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
        if (argv[i][0] == '-' && argv[i][1] == '-')
        {
            i++;
            continue ;
        }
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

static void    run_strategy(t_stack *a, t_stack *b, t_bench *bench, char **argv, char **strategy)
{
    if (ft_strcmp(argv[1], "--simple") == 0)
    {
        *strategy = "simple | O(n^2)";
        sort_simple(a, b, bench);
    }
    else if (ft_strcmp(argv[1], "--medium") == 0)
    {
        *strategy = "medium | O(n sqrt n)";
        sort_medium(a, b, bench);
    }
    else if (ft_strcmp(argv[1], "--complex") == 0)
    {
        *strategy = "complex | O(n log n)";
        sort_complex(a, b, bench);
    }
    else
    {
        *strategy = "adaptive | O(n log n)";
        sort_adaptive(a, b, bench);
    }
}

int main(int argc, char **argv)
{
    int     bench_mode;
    double  disorder;
    t_stack *a;
    t_stack *b;
    t_bench bench;
    char    *strategy;

    if (argc < 2)
        return (0);
    bench_mode = has_bench_flag(argc, argv);
    a = parse_args(argc, argv);
    if (!a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    disorder = compute_disorder(a);
    b = init_stack();
    init_bench(&bench);
    strategy = "adaptive | O(n log n)";
    run_strategy(a, b, &bench, argv, &strategy);
    if (bench_mode)
        print_bench(&bench, disorder, strategy);
    free_stack(a);
    free_stack(b);
    return (0);
}