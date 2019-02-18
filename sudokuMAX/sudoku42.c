/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku42.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeagan <jeagan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 04:00:06 by jeagan            #+#    #+#             */
/*   Updated: 2019/02/18 04:00:13 by jeagan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_is_nbr_ok(char val, char **tab, int x, int y)
{
	int i;
	int j;

	i = (x / 3) * 3 - 1;
	while (++i < ((x / 3) * 3) + 3)
	{
		j = (y / 3) * 3 - 1;
		while (++j < ((y / 3) * 3) + 3)
			if (tab[i][j] == val)
				return (0);
	}
	i = -1;
	while (++i < 9)
		if (tab[x][i] == val)
			return (0);
	j = -1;
	while (++j < 9)
		if (tab[j][y] == val)
			return (0);
	return (1);
}

static int	ft_board_error(char **tab)
{
	int		x;
	int		y;
	char	tmp;

	x = -1;
	while (++x < 9)
	{
		y = -1;
		while (tab[x][++y])
			if ((tab[x][y] < '1' || tab[x][y] > '9') && tab[x][y] != '.')
				return (1);
			else if (tab[x][y] != '.')
			{
				tmp = tab[x][y];
				tab[x][y] = '.';
				if (!ft_is_nbr_ok(tmp, tab, x, y))
					return (1);
				tab[x][y] = tmp;
			}
		if (y != 9)
			return (1);
	}
	return (0);
}

static void	ft_print_board(char **tab)
{
	int i;
	int j;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j] != '\0')
		{
			write(1, &tab[i][j], 1);
			if (j != 8)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}

static int	ft_board_ok(char **tab, int x, int y, int *nsol)
{
	char val;

	if (y == 9)
	{
		x++;
		y = 0;
	}
	if (x == 9)
	{
		if (*nsol < 0)
			ft_print_board(tab);
		return (++(*nsol));
	}
	if (tab[x][y] != '.')
		return (ft_board_ok(tab, x, y + 1, nsol));
	val = '1' - 1;
	while (++val <= '9')
		if (ft_is_nbr_ok(val, tab, x, y))
		{
			tab[x][y] = val;
			ft_board_ok(tab, x, y + 1, nsol);
		}
	tab[x][y] = '.';
	return (0);
}

int			main(int argc, char **argv)
{
	char	**tab;
	int		nsol;

	tab = argv + 1;
	nsol = 0;
	if (argc == 10 && !ft_board_error(tab))
	{
		ft_board_ok(tab, 0, 0, &nsol);
		if (nsol == 1)
		{
			nsol = -1;
			ft_board_ok(tab, 0, 0, &nsol);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
// 3.....84. ....8.3.. 5...64..2 .5.6..... 27..4..18 .....1.9. 7..81...6 ..9.2.... .65.....7
// 9..1....5 ..5.9.2.1 8...4.... ....8.... ...7..... ....26..9 2..3....6 ...2..9.. ..19.457.
// 1.34..26. 6.2.31.45 ..46.23.1 2...43.16 43681..72 .1.2.6.34 32.16.4.. .6832419. .41.8.623

