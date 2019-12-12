/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libflag.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: fenrir <fenrir@student.le-101.fr>          +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 06:35:18 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 06:44:08 by fenrir      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBFLAG_H
# define LIBFLAG_H
# include "../libftprintf.h"
# include <locale.h>

char	*ft_apost(char *res, t_printf *wip);
char	*ft_hash(char *res, t_printf *wip);
char	*ft_hflag(t_printf *wip);
char	*ft_hhflag(t_printf *wip);
char	*ft_lflag(t_printf *wip);
char	*ft_llflag(t_printf *wip);
char	*ft_plus(char *res, t_printf *wip);
size_t	ft_precision(char *res, t_printf *wip, size_t size_data);
char	*ft_size_champ(char *res, t_printf *wip, size_t size_data);
char	*ft_plus(char *res, t_printf *wip);
char	*ft_zero(char *res, t_printf *wip, size_t size_data);
#endif
