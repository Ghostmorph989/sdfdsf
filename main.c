/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malaoui <malaoui@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 21:09:20 by malaoui           #+#    #+#             */
/*   Updated: 2019/12/09 16:14:13 by malaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcub3d.h"

int     ft_manage_events(int key, void *p)
{
    p = NULL;
    ft_printf("key = : %d\n", key);
    mlx_clear_window(l.mlx_ptr, l.win_ptr);
    return (0);
}

void    ft_collect_content(char *line)
{
    int i;
    int j;
    char **data;

    i = 0;
    j = 0;
    data = NULL;
    if (line == NULL)
        return ;
    if (ft_isdigit(*line) == 0)
        data = ft_split(line, ' ');
    else
    {
        if (line != NULL)
        {
            while (l.map[i] != '\0')
            {
                l.map[i] = ft_strdup(line);
                i++;
            }
        }
    }
    while (data[i] != '\0')
    {
        if (ft_memcmp(data[i], "R", 1) == 0)
        {
            l.display_x = ft_atoi(data[++i]);
            l.display_y = ft_atoi(data[++i]);
        }
        else if (ft_memcmp(data[i], "NO", 2) == 0)
            l.NO_path = ft_substr(data[i], 3, ft_strlen(data[i]));
        else if (ft_memcmp(data[i], "SO", 2) == 0)
            l.SO_path = ft_substr(data[i], 3, ft_strlen(data[i]));
        else if (ft_memcmp(data[i], "WE", 2) == 0)
            l.WE_path = ft_substr(data[i], 3, ft_strlen(data[i]));
        else if (ft_memcmp(data[i], "EA", 2) == 0)
            l.EA_path = ft_substr(data[i], 3, ft_strlen(data[i]));
        else if (ft_memcmp(data[i], "S", 2) == 0)
            l.S_path = ft_substr(data[i], 3, ft_strlen(data[i]));
        else if (ft_memcmp(data[i], "F", 2) == 0)
        {
            l.floor_r = ft_atoi(data[++i]);
            l.floor_g = ft_atoi(data[++i]);
            l.floor_b = ft_atoi(data[++i]);
        }
        else if (ft_memcmp(data[i], "C", 1) == 0)
        {
            l.ceilling_r = ft_atoi(data[++i]);
            l.ceilling_g = ft_atoi(data[++i]);
            l.ceilling_b = ft_atoi(data[++i]);
        }
    }
    i++;
}

int     main(void)
{
    int fd;
    char *line;
    int i;

    i = 0;
    fd = open("map.cub", O_RDONLY);
    while (get_next_line(fd, &line) == 1)
        ft_collect_content(line);
    if (!(l.mlx_ptr = mlx_init()))
        return (0);
    l.win_ptr = mlx_new_window(l.mlx_ptr, l.display_x, l.display_x, "Cub3d");
    // while (l.map[i] != '\0')
    // {
    //     ft_printf("%s\n", l.map[i++]);
    // }
    mlx_key_hook(l.win_ptr, ft_manage_events, NULL);
    mlx_loop(l.mlx_ptr);
    return (0);
}