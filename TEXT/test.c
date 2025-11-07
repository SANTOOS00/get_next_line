#include <stdio.h>


int ft_strlen(char *str)
{
	int i;
	i = 0;
	while (str[i])
	{

		i++;
	}
	return (i);
}
int main()
{
	char str[9];
	int i = ft_strlen(str);
	printf ("%d\n",i);
	str[0] = 'a';
	str[0] = 'd';
	str[0] = 'c';
	str[0] = 'f';
	i = ft_strlen(str);
	printf("%d\n",i);
}