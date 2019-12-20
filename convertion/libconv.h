/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   libconv.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mrozniec <mrozniec@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 02:30:42 by fenrir       #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 03:42:41 by mrozniec    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LIBCONV_H
# define LIBCONV_H
# include "../libftprintf.h"
# include "../flags/libflag.h"

typedef union s_doubles
{
  double  d;
  struct {
    unsigned int manl  :32;
    unsigned int manh  :20;
    unsigned int exp   :11;
    unsigned int sign  :1;
  } bits;
} t_doubles;

char	*ft_xmin_conv(t_printf *wip);
char	*ft_xmaj_conv(t_printf *wip);
char	*ft_umin_conv(t_printf *wip);
char	*ft_dmin_conv(t_printf *wip);
char	*ft_perc_conv(t_printf *wip);
char	*ft_cmin_conv(t_printf *wip);
char	*ft_smin_conv(t_printf *wip);
char	*ft_pmin_conv(t_printf *wip);
char	*ft_nmin_conv(t_printf *wip);
#endif
