/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_space.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 00:03:16 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 00:03:41 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libftprintf.h"

char *ft_plus(char *res, t_printf *wip)
{
	return (ft_strjoinmod(" ", res, 2));
}
