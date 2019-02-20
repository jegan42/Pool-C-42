/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeagan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 01:44:29 by jeagan            #+#    #+#             */
/*   Updated: 2019/02/11 01:44:35 by jeagan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lo(char c)
{
	return ('a' <= c && c <= 'z');
}

int		ft_hi(char c)
{
	return ('A' <= c && c <= 'Z');
}

int		ft_nu(char c)
{
	return ('0' <= c && c <= '9');
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (ft_hi(str[i]))
			str[i] = str[i] - 'A' + 'a';
	if (ft_lo(str[0]))
		str[0] = str[0] - 'a' + 'A';
	i = -1;
	while (str[++i])
		if (ft_lo(str[i]))
			if (!ft_nu(str[i - 1]) && !ft_lo(str[i - 1]) && !ft_hi(str[i - 1]))
				str[i] = str[i] - 'a' + 'A';
	return (str);
}
