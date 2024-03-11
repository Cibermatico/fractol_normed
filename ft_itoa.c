/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsquarci <lsquarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 10:09:30 by lsquarci          #+#    #+#             */
/*   Updated: 2024/03/11 10:09:32 by lsquarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	ft_magnitude(int number)
{
	int	res;

	res = 0;
	if (number == 0)
		return (1);
	while (number >= 1)
	{
		number = number / 10;
		res = res + 1;
	}
	return (res);
}

static int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power == 0)
		return (1);
	while (power >= 1)
	{
		result = nb * result;
		power--;
	}
	return (result);
}

static void	initialize(int *a, int *b, int *c)
{
	*a = 0;
	*b = 0;
	*c = 0;
}

static void	sign_handle(int *a, int *b, int *c)
{
	*a = -*a;
	*b = 1;
	*c = 1;
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int		i;
	int		power;
	int		sign;

	initialize(&i, &power, &sign);
	if (nbr == -2147483648)
		return (ft_strdup("-2147483648"));
	if (nbr < 0)
		sign_handle(&nbr, &sign, &i);
	result = (char *)malloc((ft_magnitude(nbr) + 1 + sign) * sizeof(char)); //malloc2
	if (!result)
		return (NULL);
	power = ft_iterative_power(10, ft_magnitude(nbr) - 1);
	while (power >= 1)
	{
		result[i++] = (nbr / power) + 48;
		nbr = nbr % power;
		power = power / 10;
	}
	if (sign == 1)
		*result = '-';
	result[i] = '\0';
	return (result);
} //free();

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_total_lenght(int size, char **ptr)
{
	int	i;
	int	j;
	int	total_lenght;

	i = 0;
	j = 0;
	total_lenght = 0;
	while (i < size)
	{
		while (ptr[i][j] != '\0')
		{
			j++;
		}
		total_lenght = total_lenght + j;
		i++;
		j = 0;
	}
	return (total_lenght);
}

void	silly_function(int *a, int *b, int *c, int *d)
{
	*a = 0;
	*b = 0;
	*c = 0;
	*d = 0;
}

void	main_function(int size, char **matrix, char *s, char *output)
{
	int	t;
	int	i;
	int	j;
	int	k;

	silly_function(&i, &j, &t, &k);
	while (i < size)
	{
		while (matrix[i][j] != '\0')
		{
			output[k] = matrix[i][j];
			j++;
			k++;
		}
		t = 0;
		while ((t < ft_strlen(s)) && i < (size - 1))
		{
			output[k] = s[t];
			t++;
			k++;
		}
		j = 0;
		i++;
		output[k] = '\0';
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char));
		*result = '\0';
		return (result);
	}
	result = (char *)malloc((ft_total_lenght(size, strs)) * sizeof(char)
			+ (ft_strlen(sep) * (size - 1)) * sizeof(char));
	if (result == NULL)
		return (0);
	main_function(size, strs, sep, result);
	return (result);
}

char *ft_dtoa(double nbr)
{
    char    *result;
    double  dec_part;
    int     int_part;
    char    *dec_str;
    char    *int_str;
    char    **str_num;

    
    int_part = (int)nbr;
    dec_part = (nbr - int_part)* 1000000; 
    int_str = ft_itoa(int_part);
    dec_str = ft_itoa((int)dec_part);
    str_num = (char **)malloc(2 * sizeof(char *));
    str_num[0] = int_str;
    str_num[1] = dec_str;
    result = (char *)malloc(ft_strlen(int_str) + ft_strlen(dec_str) + 2);
    result = ft_strjoin(2, str_num,".");
    free(str_num[0]);
    free(str_num[1]);
    free(str_num);
    printf("%s\n",int_str);
    return result;
}




