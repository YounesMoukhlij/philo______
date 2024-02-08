#include "philo.h"

int ft_is_digits(char *str)
{
    int i = 0;
    int s = ft_atoi(str);
    while (str[i])
    {
        if (str[i] >= '0' && str[i] <= '9')
            i++;
        else 
            return 0;
    }
    if (s > 24634545)//max int 
        return 0;
    return 1;
}
int main (int ac , char **av)
{
    int i = 1;
    int ar[5];
    int j = 0;
    if (ac == 6 || ac == 5)
    {
        while(i <= ac -1)
        {
            if (ft_is_digits(av[i]))
                ar[j] = ft_atoi(av[i]);
            else
                ft_error(1);
            i++;
            j++;
        }
        if (ac == 5)
            ar[j] = 0;
    }
    else 
        ft_error(1);
    ft_set_element(ar);
}