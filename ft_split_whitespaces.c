/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeagan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 18:25:25 by jeagan            #+#    #+#             */
/*   Updated: 2019/02/14 18:25:30 by jeagan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_white(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int		ft_nbw(char *s)
{
	int		i;
	int		nbw;

	nbw = 0;
	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] && ft_white(s[i]))
			++i;
		if (s[i] && !ft_white(s[i]))
			++nbw;
		while (s[i] && !ft_white(s[i]))
			++i;
	}
	return (nbw);
}

char	*ft_w_str(char *s)
{
	int		i;
	char	*ws;

	i = 0;
	while (s[i] && !ft_white(s[i]))
		++i;
	if (s && (!(ws = (char *)malloc(sizeof(char) * (i + 1)))))
		return ((char*)0);
	i = -1;
	while (s[++i] && !ft_white(s[i]))
		ws[i] = s[i];
	ws[i] = '\0';
	return (ws);
}

char	**ft_split_whitespaces(char *s)
{
	int		i;
	int		nbw;
	char	**ts;

	if (s && !(ts = (char **)malloc(sizeof(char *) * (ft_nbw(s) + 1))))
		return ((char**)0);
	i = 0;
	nbw = 0;
	while (nbw < ft_nbw(s))
	{
		while (s[i] && ft_white(s[i]))
			++i;
		if (s[i] && !ft_white(s[i]))
		{
			ts[nbw] = ft_w_str(&s[i]);
			++nbw;
		}
		while (s[i] && !ft_white(s[i]))
			++i;
	}
	ts[nbw] = 0;
	return (ts);
}
