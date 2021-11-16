//
// Created by fcody on 6/28/21.
//
#include "so_long.h"

char
*ft_strchr(const char *s, int c)
{
    int	i;

    if (!s)
        return (NULL);
    i = 0;
    while (s[i])
    {
        if (s[i] == (char)c)
            return ((char*)(s + i));
        i++;
    }
    if (s[i] == (char)c)
        return ((char*)(s + i));
    return (NULL);
}

char
*ft_strdup(const char *s1)
{
    char	*str;
    size_t	i;

    if (!s1)
        return (NULL);
    str = (char*)malloc(sizeof(*s1) * (ft_strlen(s1) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

char    **ft_ptrstrdup(char **s1)
{
    char	**str;
    size_t	i;

    if (!s1)
        return (NULL);
    str = (char**)malloc(sizeof(char *) * (ft_ptrstrlen(s1) + 1));
    if (!str)
        return (NULL);
    i = 0;
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    str[i] = 0;
    return (str);
}

char
*ft_strjoin(char const *s1, char const *s2)
{
    char	*str;
    size_t	i;
    size_t	j;

    str = (char*)malloc(
            sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s1[i])
    {
        str[j++] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        str[j++] = s2[i];
        i++;
    }
    str[j] = 0;
    return (str);
}

size_t
ft_strlen(const char *s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

size_t
ft_ptrstrlen(char **s)
{
    size_t	i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char
*ft_substr(char const *s, unsigned int start, size_t len)
{
    size_t	i;
    size_t	j;
    char	*str;

    str = (char*)malloc(sizeof(*s) * (len + 1));
    if (!str)
        return (NULL);
    i = 0;
    j = 0;
    while (s[i])
    {
        if (i >= start && j < len)
        {
            str[j] = s[i];
            j++;
        }
        i++;
    }
    str[j] = 0;
    return (str);
}
