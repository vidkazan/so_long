//
// Created by fcody on 6/28/21.
//
#include "so_long.h"


int     ft_strlen_2(char **str)
{
    int len;
    len = 0;
    while(str[len])
        len++;
    return (len);
}

void    error_msg_10(t_data *data)
{
    if(data->error == 10)
        ft_putstr_fd("Error : pls enter MAP NAME as an argument\n",2);
    if(data->error == 11)
        ft_putstr_fd("Error :  more than one EXIT or PLAYER on the map \n",2);
    if(data->error == 12)
        ft_putstr_fd("Error :  restricted symbols on the MAP \n",2);
    if(data->error == 13)
        ft_putstr_fd("Error :  map is OK, but final resolution is too big to render \n",2);
    if(data->error == 20)
        ft_putstr_fd("Error :  enemy error \n",2);
}

void    error_msg(t_data *data)
{
    if(data->error > 9)
        error_msg_10(data);
    if(data->error == 1)
        ft_putstr_fd("Error : MAP is not rectangle:(\n",2);
    if(data->error == 3)
        ft_putstr_fd("Error : no EXIT on the map:(\n",2);
    if(data->error == 4)
        ft_putstr_fd("Error : no PLAYER on the map:(\n",2);
    if(data->error == 5)
        ft_putstr_fd("Error : no COLLECTIBLES on the map:(\n",2);
    if(data->error == 6)
        ft_putstr_fd("Error : MAP is not surrounded by WALLS:(\n",2);
    if(data->error == 7)
        ft_putstr_fd("Error : failed to load XMP texture file:(\n",2);
    if(data->error == 8)
        ft_putstr_fd("Error : failed to load BER map file:(\n",2);
    if(data->error == 9)
        ft_putstr_fd("Error : failed to allocate memory:(\n",2);
}

void    file_load(t_data *data, int ac, char **av)
{
    if(!av[1])
    {
        data->error = 10;
        game_close(data);
    }
    data->fd = open(av[1], O_RDONLY);
    if(data->fd < 0)
    {
        data->error = 8;
        game_close(data);
    }
    if(ac > 2)
        ft_putstr_fd("Why so many arguments?) The first will be used...",1);
}

void    map_validation_core(t_data *data, int y)
{
    int x;

    x = 0;
    while (data->map[y][x])
    {
        if(((y == 0 || y == ft_strlen_2(data->map) - 1) || (x == 0 || (unsigned long)x == ft_strlen(data->map[y]) - 1)) && (data->map[y][x] != '1'))
            data->error = 6;
        if (data->map[y][x] == 'C')
            data->fish_count++;
        else if (data->map[y][x] == 'E')
            data->exit_count++;
        else if (data->map[y][x] == 'P')
            data->player_count++;
        else if(data->map[y][x] == 'X')
            data->enemy_count++;
        else if(data->map[y][x] != '0' && data->map[y][x] != '1')
            data->error = 12;

        x++;
    }
}

void    map_validation(t_data *data)
{
    int y;

    ft_putstr_fd("Checking map...\n", 1);
    y = 0;
    while (data->map[y])
    {
        if (ft_strlen(data->map[0]) != ft_strlen(data->map[y]))
            data->error = 1;
        map_validation_core(data, y++);
    }
    if(data->player_count > 1 || data->exit_count > 1)
        data->error = 11;
    else if(!data->exit_count)
        data->error = 3;
    else if(!data->player_count)
        data->error = 4;
    if(!data->fish_count)
        data->error = 5;
    if(data->enemy_count != 1)
        data->error = 20;
    if(data->error)
        game_close(data);
}