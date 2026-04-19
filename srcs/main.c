// #include "push_swap.h"

// static int  has_bench_flag(int argc, char **argv)
// {
//     int i;

//     i = 1;
//     while (i < argc)
//     {
//         if (ft_strcmp(argv[i], "--bench") == 0)
//             return (1);
//         i++;
//     }
//     return (0);
// }

// static char    *get_strategy(char *flag)
// {
//     if (ft_strcmp(flag, "--simple") == 0)
//         return ("simple | O(n^2)");
//     else if (ft_strcmp(flag, "--medium") == 0)
//         return ("medium | O(n sqrt n)");
//     else if (ft_strcmp(flag, "--complex") == 0)
//         return ("complex | O(n log n)");
//     return ("adaptive | O(n log n)");
// }

// static t_stack *parse_args(int argc, char **argv)
// {
//     t_stack *s;
//     int     i;
//     int     value;

//     s = init_stack();
//     i = 1;
//     while (i < argc)
//     {
//         if (argv[i][0] == '-' && argv[i][1] == '-')
//         {
//             i++;
//             continue ;
//         }
//         if (!is_valid_int(argv[i]) || !is_in_range(argv[i]))
//             return (free_stack(s), NULL);
//         value = ft_atol(argv[i]);
//         if (has_duplicate(s, value))
//             return (free_stack(s), NULL);
//         push(s, value);
//         i++;
//     }
//     return (s);
// }

// static void    run_strategy(t_stack *a, t_stack *b, t_bench *bench, char **argv, char **strategy)
// {
//     if (ft_strcmp(argv[1], "--simple") == 0)
//     {
//         *strategy = "simple | O(n^2)";
//         sort_simple(a, b, bench);
//     }
//     else if (ft_strcmp(argv[1], "--medium") == 0)
//     {
//         *strategy = "medium | O(n sqrt n)";
//         sort_medium(a, b, bench);
//     }
//     else if (ft_strcmp(argv[1], "--complex") == 0)
//     {
//         *strategy = "complex | O(n log n)";
//         sort_complex(a, b, bench);
//     }
//     else
//     {
//         *strategy = "adaptive | O(n log n)";
//         sort_adaptive(a, b, bench);
//     }
// }

// int main(int argc, char **argv)
// {
//     int     bench_mode;
//     double  disorder;
//     t_stack *a;
//     t_stack *b;
//     t_bench bench;
//     char    *strategy;

//     if (argc < 2)
//         return (0);
//     bench_mode = has_bench_flag(argc, argv);
//     a = parse_args(argc, argv);
//     if (!a)
//     {
//         write(2, "Error\n", 6);
//         return (1);
//     }
//     disorder = compute_disorder(a);
//     b = init_stack();
//     init_bench(&bench);
//     strategy = "adaptive | O(n log n)";
//     run_strategy(a, b, &bench, argv, &strategy);
//     if (bench_mode)
//         print_bench(&bench, disorder, strategy);
//     free_stack(a);
//     free_stack(b);
//     return (0);
// }

#include "push_swap.h"

int check_duplicates_argv(int argc, char **argv)
{
    int i = 1;
    while (i < argc)
    {
        int j = i + 1;
        while (j < argc)
        {
            if (ft_strcmp(argv[i], argv[j]) == 0)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

char **flags_tab(int argc, char **argv)
{
    int count = 0;
    int i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-')
            count++;
        i++;
    }
    char **tab = malloc(sizeof(char *) * (count + 1));
    int j = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-')
            tab[j++] = argv[i];
        i++;
    }
    tab[j] = NULL;
    return (tab);
}

int chech_invalid_flags(char **flags)
{
    int i = 0;
    while (flags[i])
    {
        if (ft_strcmp(flags[i], "--simple") != 0 && ft_strcmp(flags[i], "--medium") != 0 && ft_strcmp(flags[i], "--complex") != 0 && ft_strcmp(flags[i], "--adaptive") != 0 && ft_strcmp(flags[i], "--bench") != 0)
            return (1);
        i++;
    }
    return (0);
}

int check_double_strategies(char **flags)
{
    int i = 0;
    int count = 0;
    while (flags[i])
    {
        if (ft_strcmp(flags[i], "--simple") == 0 || ft_strcmp(flags[i], "--medium") == 0 || ft_strcmp(flags[i], "--complex") == 0 || ft_strcmp(flags[i], "--adaptive") == 0)
            count++;
        i++;
    }
    if (count > 1)
        return (1);
    return (0);
}

char **argv_without_flags(int argc, char **argv)
{
    int count = 0;
    int i = 1;
    while (i < argc)
    {
        if (argv[i][0] != '-' || argv[i][1] != '-')
            count++;
        i++;
    }
    char **tab = malloc(sizeof(char *) * (count + 1));
    int j = 0;
    i = 1;
    while (i < argc)
    {
        if (argv[i][0] != '-' || argv[i][1] != '-')
            tab[j++] = argv[i];
        i++;
    }
    tab[j] = NULL;
    return (tab);
}

int check_invalid_argv(char **argv_without_flags)
{
    int i = 0;
    while (argv_without_flags[i])
    {
        if (!is_valid_int(argv_without_flags[i]))
            return (1);
        i++;
    }
    return (0);
}

char *ft_strdup(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    char *dup = malloc(sizeof(char) * (i + 1));
    i = 0;
    while (s[i])
    {
        dup[i] = s[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}

char *strategy_flag_used(int argc, char **argv)
{
    int i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--simple") == 0 || ft_strcmp(argv[i], "--medium") == 0 || ft_strcmp(argv[i], "--complex") == 0 || ft_strcmp(argv[i], "--adaptive") == 0)
            return (ft_strdup(argv[i] + 2));
        i++;
    }
    return (ft_strdup("adaptive"));
}

int has_bench_flag(int argc, char **argv)
{
    int i = 1;
    while (i < argc)
    {
        if (ft_strcmp(argv[i], "--bench") == 0)
            return (1);
        i++;
    }
    return (0);
}

int check_args_error(int argc, char **argv)
{
    if (check_duplicates_argv(argc, argv))
        return (1);
    char **argv_without_flag = argv_without_flags(argc, argv);
    if (check_invalid_argv(argv_without_flag))
        return (1);
    char **flags = flags_tab(argc, argv);
    if (chech_invalid_flags(flags))
        return (1);
    if (check_double_strategies(flags))
        return (1);
    return (0);
}

void run_stategy(t_stack *a, t_stack *b, t_bench *bench,char *strategy)
{
    if (ft_strcmp(strategy, "simple") == 0)
        sort_simple(a, b, bench);
    else if (ft_strcmp(strategy, "medium") == 0)
        sort_medium(a, b, bench);
    else if (ft_strcmp(strategy, "complex") == 0)
        sort_complex(a, b, bench);
    else
        sort_adaptive(a, b, bench);
}

static t_stack *parse_args(int argc, char **argv)
{
    t_stack *s;
    int     i;
    int     value;

    s = init_stack();
    // i = 1;
    // while (i < argc)
    i = argc - 1;
    while (i >= 1)
    {
        if (argv[i][0] == '-' && argv[i][1] == '-')
        {
            i--;
            continue ;
        }
        if (!is_valid_int(argv[i]) || !is_in_range(argv[i]))
            return (free_stack(s), NULL);
        value = ft_atol(argv[i]);
        if (has_duplicate(s, value))
            return (free_stack(s), NULL);
        push(s, value);
        // i++;
        i--;
    }
    return (s);
}

#include <stdio.h>

int main(int argc, char **argv)
{
    if (argc < 2)
        return (0);
    if (check_args_error(argc, argv))
    {
        write(2, "Error\n", 6);
        return (1);
    }
    char *strategy = strategy_flag_used(argc, argv);
    t_stack *a = parse_args(argc, argv);
    if (!a)
    {
        write(2, "Error\n", 6);
        return (1);
    }
    t_stack *b = init_stack();
    t_bench bench = {0};
    double disorder = compute_disorder(a);
    if (disorder == 0.00)
    {
        if (has_bench_flag(argc, argv))
            print_bench(&bench, disorder, strategy);
        return (0);
    }
    run_stategy(a, b, &bench, strategy);
    if (has_bench_flag(argc, argv))
        print_bench(&bench, disorder, strategy);
    ////////////////////////////////////////////
    printf("=== Debug affichage apres tri: ===\n");
    t_node *tmp = a->top;
    while (tmp)
    {
        printf("%d\n", tmp->value);
        tmp = tmp->next;
    }
    ////////////////////////////////////////////
    free_stack(a);
    free_stack(b);
    free(strategy);
    return (0);
}
