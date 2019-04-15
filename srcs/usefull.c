/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamigore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:32:11 by tamigore          #+#    #+#             */
/*   Updated: 2019/01/07 17:51:58 by tamigore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_itoa(int x)
{
    unsigned int    y;
    char            *str;
    int             neg;
    int             count;

    neg = 0;
    count = 1;
    if (x < 0)
        neg = 1;
    y = ABS(x);
    while (y >= 10)
    {
        y /= 10;
        count++;
    }
    if (!(str = (char *)malloc(count + 1 + neg)))
        return (NULL);
    str[neg + count--] = '\0';
    y = ABS(x);
    while (y > 0)
    {
        str[neg + count--] = (y % 10) + '0';
        y /= 10;
    }
    if (neg == 1)
        *str = '-';
    return (str);
}

char    ft_pars_char(char *str)
{
    static  const   char    *cut = "diuoxXcsfeEgGpn";
    int     x;
    int     y;

    x = 0;
    while(str[x])
    {
        y = 0;
        while(cut[y])
        {
            if(cut[y] == str[x])
                return(cut[y]);
            y++;
        }
        x++;
    }
    return(0);
}

int    ft_count(char *str)
{
    static  const   char    *cut = "diuoxXcsfeEgGpn";
    int     x;
    int     y;

    x = 0;
    while(str[x])
    {
        y = 0;
        while(cut[y])
        {
            if(cut[y] == str[x])
                return(x);
            y++;
        }
        x++;
    }
    return(0);
}
