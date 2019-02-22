int ft_atoi(char *str)
{
	int	i;
	int	sig;
	int	ret;

	sig = 1;
	ret = 0;
	i = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
		|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sig = -1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		ret = ret * 10 + (str[i] - '0');
		++i;
	}
	return (ret * sig);
}