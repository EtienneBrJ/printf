/**
 * _atoi - convert a string to an integer
 * @s: a pointer
 *
 * Return: an integer
 */
int _atoi(char *s)
{
	int ite1 = 0, ite2, num = 0, sign = 1;

	while (s[ite1] != '\0' && (s[ite1] < '0' || s[ite1] > '9'))
	{
		if (s[ite1] == '-')
		{
			sign *= -1;
		}
		ite1++;
	}
	ite2 = ite1;
	while (s[ite2] >= '0' && s[ite2] <= '9')
	{
		num = (num * 10) + (s[ite2] - '0') * sign;
		ite2++;
	}
	return (num);
}
