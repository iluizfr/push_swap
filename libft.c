#include "push_swap.h"

int     ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] && s1[i] == s2[i])
        i++;
    return (s1[i] - s2[i]);
}

int     check_args(int argc, char **args)
{
    int i;
    int j;
    int k;

    i = 1;
    while (i < argc)
    {
        j =  i + 1;
        while (args[j])
        {
            if ((ft_strcmp(args[i], args[j])) == 0)
                return (-1);
            j++;
        }
        k = 0;
        while (args[i][k])
        {
            if(!is_digit(args[i][k]) && !is_space(args[i][k]) && args[i][k] != '-' && args[i][k] != '+')
                return (-1);
            else if((args[i][k] == '+' || args[i][k] == '-') && !is_digit(args[i][k + 1]))
                return (-1);
            k++;
        }
        i++;
    }
    return (0);
}
