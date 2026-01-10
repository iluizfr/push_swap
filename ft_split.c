#include "push_swap.h"

int     word_len(char *str)
{
    int i;

    i = 0;
    while (str[i] && !is_space(str[i]))
        i++;
    return (i);
}

int     word_count(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i])
    {
        while (str[i] && is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
            count++;
        while (str[i] && !is_space(str[i]))
            i++;
    }
    return (count);
}

void    free_array(char **array)
{
    int     i;

    if (!array)
        return ;
    i = 0;
    while (array[i])
        free(array[i++]);
    free(array);
}

char    *ft_substr(const char *str, int start, int len)
{
	char	*sub;
	char	*ptr;
	int     slen;

	if (!str)
		return (NULL);
	slen = 0;
    while(str[slen])
        slen++;
	if (start >= slen)
		return (malloc(0));
	if (len > slen - start)
		len = slen - start;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	ptr = sub;
	str += start;
	while (len--)
		*sub++ = *str++;
	*sub = '\0';
	return (ptr);    
}

char    **ft_split(char *str)
{
    int     i;
    int     j;
    int     len;
    char    **array;

    array = (char **)malloc(sizeof(char *) * (word_count(str) + 1));
    if (!array)
        return (NULL);
    i = 0;
    j = 0;
    while (str[i])
    {
        while (is_space(str[i]))
            i++;
        if (str[i] && !is_space(str[i]))
        {
            len = word_len(str + i);
            array[j] = ft_substr(str, i, len);
            if (!array[j++])
                return(free_array(array), NULL);
            i += len;
        }
    }
    array[j] = NULL;
    return (array);
}
