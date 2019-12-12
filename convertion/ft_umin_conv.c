/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_umin_conv.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/29 11:12:41 by mrozniec     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:23:04 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libconv.h"

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
	char *res;
	char *prec;
	char *temp;
	size_t size_res;

	res = ft_utoa(va_arg(wip->ap, unsigned int));
	size_res = ft_strlen(res);
	if (((wip->flags & POINT) == POINT) && (size_res < wip->precision))
	{
		if(!(prec = calloc(sizeof(char), (wip->precision + 1 - size_res))))
			return (NULL);
		prec = ft_memset(prec, '0', (sizeof(char) * (wip->precision - size_res)));
		res = ft_strjoinmod(prec, res, 3);
		size_res = wip->precision;
	}
	if (size_res >= wip->size_champ)
		return (res);
	if(!(temp = ft_calloc(sizeof(char), (wip->size_champ - size_res + 1))))
		return (NULL);
	temp = ft_memset(temp, ' ', wip->size_champ - size_res);
	if ((wip->flags & MINUS) == 0)
		return (ft_strjoinmod(temp, res, 3));
	return (ft_strjoinmod(res, temp, 3));
}
