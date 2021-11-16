//
// Created by fcody on 6/28/21.
//
#include "so_long.h"

void    game_free(t_data *data)
{
    int i = 0;
    if(data->map)
    {
        while (data->map[i])
        {
            free(data->map[i]);
            data->map[i++] = NULL;
        }
        free(data->map);
        data->map = NULL;
    }
    if(!data->start) {
        free(data);
        data = NULL;
    }
}

int     game_close(t_data *data)
{
    if(data->error)
        error_msg(data);
    if(data->epic_win == 1)
    {
        ft_putstr_fd("\nFat Cat got home for ", 1);
        ft_putnbr_fd(data->counter, 1);
        ft_putstr_fd(" moves", 1);
        ft_putstr_fd("\n\n",1);
    }
    else
        ft_putstr_fd("Closing...\n",1);
    if(data->mlx)
    {
        if(data->img)
            mlx_destroy_image(data->mlx, data->img);
        if(data->win)
            mlx_destroy_window(data->mlx, data->win);
    }
    if(data)
        game_free(data);
    if(data->start && !data->error)
        return (0);
    while(1);
    exit(0);
}

void    map_load(t_data *data)
{
    char map[107000];
    int ret;

    ft_putstr_fd("Loading map...\n",1);
    ft_bzero(map, 107000);
    ret = read(data->fd, map, 106999);
        if (ret < 0)
        {
            data->error = 8;
            game_close(data);
        }
        if(!*map)
        {
            data->error = 5;
            game_close(data);
        }
    data->map = ft_split(map, '\n');
    if(!data->map)
    {
        data->error = 9;
        game_close(data);
    }
    map_validation(data);
}

void    data_init(t_data *data)
{
    data->count_line_height = 10;
    data->win_w = 0;
    data->win_h = 0;
    data->cell_size = 50;
    data->error = 0;
    data->counter = 0;
    data->win = 0;
    data->fish_count = 0;
    data->fish_eaten = 0;
    data->mlx = NULL;
    data->win = NULL;
    data->map = NULL;
    data->img = NULL;
    data->fd = -1;
    data->player_count = 0;
    data->exit_count = 0;
    data->render_cycle = 0;
    data->permit = 0;
    data->enemy_count = 0;
    data->lose = 0;
    data->start = 1;
    data->start_alert_def = 0;
    data->epic_win = 0;
}

void    game(t_data *data, int ac, char **av)
{
    data_init(data);
    file_load(data,ac,av);
    map_load(data);
    map_render_param_proc(data);
    map_render(data);
}

int     main(int ac, char **av)
{
    t_data *data;

    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
    {
        ft_putstr_fd("Error : failed to allocate memory:(\n",2);
        return (0);
    }
    data->ac = ac;
    data->av = av;
    game(data, ac, av);
    return (0);
}
