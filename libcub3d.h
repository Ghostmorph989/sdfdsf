/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libcub3d.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:18:43 by malaoui           #+#    #+#             */
/*   Updated: 2019/12/09 16:00:42 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include  "ft_printf/libftprintf.h"
#include <string.h>
#include <stddef.h>
#include "mlx.h"

typedef struct  s_range
{
    // ALL MLX NEEDS
    void    *mlx_ptr;
    void    *win_ptr;

    // SCREEN RESOLUTION
    int     display_x;
    int     display_y;

    // TEXTURE PATHS
    char *NO_path;
    char *SO_path;
    char *WE_path;
    char *EA_path;
    char *S_path;

    // FLOOR COLOR RGB
    int floor_r;
    int floor_g;
    int floor_b;

    // CEILLING COLOR RGB
    int ceilling_r;
    int ceilling_g;
    int ceilling_b;

    // MAP 
    char *map[150];
}               t_range;

t_range l;