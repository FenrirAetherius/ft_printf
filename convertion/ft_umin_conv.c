/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_umin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:12:41 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 13:21:19 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

static int	malsize(unsigned int n)
{
	unsigned int m;

	m = 2;
	if (n > 0)
		m = 1;
	while (n != 0)
	{
		n = n / 10;
		m++;
	}
	return (m);
}

static char	*ft_utoa(unsigned int n)
{
	unsigned int	m;
	unsigned int	temp;
	char			*s;

	temp = n;
	m = malsize(n);
	if (!(s = malloc(sizeof(char) * m)))
		return (NULL);
	s[m - 1] = '\0';
	while (m > 1)
	{
		s[m - 2] = (temp % 10) + 48;
		temp = temp / 10;
		m--;
	}
	return (s);
}

char		*ft_umin_conv(t_printf *wip)
{
	return (ft_utoa(va_arg(wip->ap, unsigned int)));
}
