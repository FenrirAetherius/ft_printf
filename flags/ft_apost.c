/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_apost.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:32:26 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:39:31 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libflag.h"

char *ft_apost(char *res, t_printf *wip)
{
	int		i;
	char	*new;
	char	*temp;

	i = -1;
	if (!(new = ft_calloc(sizeof(char), 1)))
		return (NULL);
	while (res[++i] >= '0' && res[i] <= '9')
		i++;
	while (i > 3)
	{
		i -= 3;
		temp = ft_strjoin(localeconv()->thousands_sep, (res + i));
		res[i] = '\0';
		new = ft_strjoinmod(temp, new, 3);
	}
	new = ft_strjoinmod(res, new, 3);
	return (new);
}
