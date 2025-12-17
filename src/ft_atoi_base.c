/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayfang <fayfang@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 14:50:33 by fayfang           #+#    #+#             */
/*   Updated: 2025/12/15 10:05:44 by fayfang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

int	ft_basematch(const char c, const char *base)
{
	size_t	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_basecount(const char *str, const char *base)
{
	size_t	i;

	i = 0;
	while (str[i] && ft_strchr(base, str[i]))
		i++;
	return (i);
}

int	ft_power(int n, int p)
{
	int	num;

	num = 1;
	while (p > 0)
	{
		num *= n;
		p--;
	}
	return (num);
}

int	ft_atoi_base(const char *str, const char *base)
{
	int		sign;
	int		num;
	int		size;
	size_t	i;
	size_t	j;

	i = 0;
	sign = 1;
	num = 0;
	size = ft_strlen(base);
	while (ft_isspace(str[i]))
		i++;
	if (ft_issign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	j = ft_basecount(str + i, base);
	while (ft_basematch(str[i], base) > -1)
	{
		num = num + ft_basematch(str[i++], base) * ft_power(size, j - 1);
		j--;
	}
	return (num * sign);
}
