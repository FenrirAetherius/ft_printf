/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   large_char.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 12:09:15 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/19 17:53:14 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <wchar.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static char *one_char(wchar_t origin)
{
	char *new;
	if (!(new = malloc(sizeof(char) * 2)))
		return (NULL);
	new[0] = (char)origin;
	new[1] = '\0';
	return (new);
}

static char *two_char(wchar_t origin)
{
	char *new;
	if (!(new = malloc(sizeof(char) * 3)))
		return (NULL);
	new[1] = 0b10000000 | (char)(origin & 0x03f);
	new[0] = 0b11000000 | (char)(origin >> 6);
	new[2] = '\0';
	return (new);
}

static char *three_char(wchar_t origin)
{
	char *new;
	if (!(new = malloc(sizeof(char) * 4)))
		return (NULL);
	new[2] = 0b10000000 | (char)(origin & 0x03f);
	new[1] = 0b10000000 | (char)((origin >> 6) & 0x03f);
	new[0] = 0b11100000 | (char)(origin >> 12);
	new[3] = '\0';
	return (new);
}

static char *four_char(wchar_t origin)
{
	char *new;
	if (!(new = malloc(sizeof(char) * 5)))
		return (NULL);
	new[3] = 0b10000000 | (char)(origin & 0x03f);
	new[2] = 0b10000000 | (char)((origin >> 6) & 0x03f);
	new[1] = 0b10000000 | (char)((origin >> 12) & 0x03f);
	new[0] = 0b11110000 | (char)(origin >> 18);
	new[4] = '\0';
	return (new);
}

char	*char_conv(wchar_t origin)
{
	if (origin <= 0x007F)
		return (one_char(origin));
	else if (origin < 0x0800)
		return (two_char(origin));
	else if (origin < 0x10000)
		return (three_char(origin));
	else if (origin < 0x110000)
		return (four_char(origin));
	else
		return (NULL);
}
/*
int main(void)
{
	wchar_t old;
	int	pre;
	char *new;
	old = 7424;
	new = char_conv(old);
	//write(1, new, strlen(new));
	pre = 2;
	if (pre >= 3 && (((new[0] >> 4) & 0x0f) == 0b01110))
		write(1, new, pre);
	write(1, "\n", 1);
	return (0);
}*/


static char	*ft_strjoin(char *s1, char *s2)
{
	unsigned long	n;
	unsigned long	m;
	unsigned long	pos;
	char			*s3;

	n = 0;
	m = 0;
	pos = 0;
	while (s1[n] != '\0')
		n++;
	while (s2[m] != '\0')
		m++;
	if (!(s3 = malloc(sizeof(char) * (n + m + 1))))
		return (NULL);
	while (pos < (n + m))
	{
		if (pos < n)
			s3[pos] = s1[pos];
		else
			s3[pos] = s2[pos - n];
		pos++;
	}
	s3[pos] = '\0';
	return (s3);
}

int main(void)
{
	wchar_t *str;
	size_t i;

	if(!(str = malloc(sizeof(wchar_t) * 6)))
		return(-1);
	str[0] = 7424;
	str[1] = 7425;
	str[2] = 7426;
	str[3] = 1792;
	str[4] = '\n';
	str[5] = 0;

	int	pre;
	size_t new_size;
	char *new;

	new = malloc(sizeof(char) * 1);
	new = "";
	i = 0;
	while (str[i])
		new = ft_strjoin(new, char_conv(str[i++]));
	pre = 7;
	new_size = strlen(new);
	if (pre >= new_size)
		write(1, new, new_size);
	else if (((((new[pre - 1] >> 4) & 0x08) == 0b00000) && pre >= 1) ||
			((((new[pre - 2] >> 4) & 0x0e) == 0b01100) && pre >= 2) ||
			((((new[pre - 3] >> 4) & 0x0f) == 0b01110) && pre >= 3) ||
			((((new[pre - 4] >> 3) & 0x01f) == 0b011110) && pre >= 4))
		write(1, new, pre);
	else if (((((new[pre - 1] >> 4) & 0x0e) == 0b01100) ||
			(((new[pre - 1] >> 4) & 0x0f) == 0b01110) ||
			(((new[pre - 1] >> 3) & 0x01f) == 0b011110)) && pre >= 1)
		write(1, new, (pre - 1));
	else if (((((new[pre - 2] >> 4) & 0x0f) == 0b01110) ||
			(((new[pre - 2] >> 3) & 0x01f) == 0b011110)) && pre >= 2)
		write(1, new, (pre - 2));
	else if ((((new[pre - 3] >> 3) & 0x01f) == 0b011110) && pre >= 3)
		write(1, new, (pre - 3));
	else
		write(1, "", 0);
	write(1, "\n", 1);
	return (0);
}
