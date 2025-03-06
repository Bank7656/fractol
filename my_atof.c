/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thacharo <thacharo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 01:12:18 by thacharo          #+#    #+#             */
/*   Updated: 2025/03/07 02:37:09 by thacharo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double get_integer(const char **str);
static double get_fraction(const char **str);
static int  get_exponent(const char **str);

double my_atof(const char *str)
{
    int     sign;
    int     exponent;
    double  integer;
    double  fraction;
    double  result;

    sign = 1;
    while (*str == ' ' || *str == '\t')
        str++;
    if (*str == '-')
    {
        sign = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    integer = get_integer(&str);
    fraction = get_fraction(&str);
    exponent = get_exponent(&str);
    result = (integer + fraction) * pow(10, exponent);
    return (sign * result);
}

static double get_integer(const char **str)
{
    double value;

    value = 0.0;
    while (ft_isdigit(**str))
    {
        value = value * 10.0 + (**str - '0');   
        (*str)++;
    }
    return (value);
}

static double get_fraction(const char **str)
{
    double  value;
    double  divisor;
    
    if (**str != '.')
        return (0.0);
    (*str)++;
    value = 0.0;
    divisor = 10.0;
    while (ft_isdigit(**str))
    {
        value = value + (**str - '0') / divisor;
        divisor *= 10;
        (*str)++;
    }
    return (value);
}

static int  get_exponent(const char **str)
{
    int sign;
    int exponent;

    sign = 1;
    exponent = 0;
    if (**str != 'e' && **str != 'E')
        return (0);
    (*str)++;
    if (**str == '-')
    {
        sign = -1;
        (*str)++;
    }
    else if (**str == '+')
        (*str)++;
    while (ft_isdigit(**str))
    {
        exponent = exponent * 10 + (**str - '0');
        (*str)++;
    }
    return (sign * exponent);
}

// // Test cases
// int main() {
//     const char *test_cases[] = {
//         "123.456", "-123.456", "0.0001", "-0.0001", "+42.42",
//         "3.14e2", "-2.5E-3", "1.79769e+308", "-1e309", "abc", "1.2.3"
//     };

//     for (int i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
//         printf("my_atof(\"%s\") = %g\n", test_cases[i], atof(test_cases[i]));
//     }

//     return 0;
// }