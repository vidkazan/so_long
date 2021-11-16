//
// Created by fcody on 6/28/21.
//
#include "so_long.h"

void    get_player_pos(t_data *data)
{
    int h;
    int w;

    h = 0;
    while(h < data->map_h)
    {
        w = 0;
        while(w < data->map_w)
        {
            if(data->map[h][w] == 'P')
            {
                data->player_posx = w;
                data->player_posy = h;
                break;
            }
            w++;
        }
        h++;
    }
}

void    map_render_param_proc(t_data *data)
{

    data->map_w = ft_strlen(*data->map);
    data->map_h = ft_strlen_2(data->map);
    if(data->map_h > 327 || data->map_w > 327 )
    {
        data->error = 13;
        game_close(data);
    }
    data->win_h = data->map_h * data->cell_size;
    data->win_w = data->map_w * data->cell_size;
    get_player_pos(data);
}

void    cat_fatness(t_data *data, int x, int y)
{
    int fish_ratio;
    fish_ratio = data->fish_eaten * 100 / data->fish_count;
    if(((fish_ratio >= 0 && fish_ratio < 16 )&& data->fish_count > 5) ||(data->fish_count <= 5 && data->fish_eaten == 0))
        mlx_put_image_to_window(data->mlx, data->win,data->img_play0,x,y);
    else if(((fish_ratio >= 16 && fish_ratio < 33 )&& data->fish_count > 5) ||(data->fish_count <= 5 && data->fish_eaten == 1))
        mlx_put_image_to_window(data->mlx, data->win,data->img_play1,x,y);
    else if(((fish_ratio >= 33 && fish_ratio < 50 )&& data->fish_count > 5) ||(data->fish_count <= 5 && data->fish_eaten == 2))
        mlx_put_image_to_window(data->mlx, data->win,data->img_play2,x,y);
    else if(((fish_ratio >= 50 && fish_ratio < 66 )&& data->fish_count > 5) ||(data->fish_count <= 5 && data->fish_eaten == 3))
        mlx_put_image_to_window(data->mlx, data->win,data->img_play3,x,y);
    else if(((fish_ratio >= 66 && fish_ratio < 100 )&& data->fish_count > 5) ||(data->fish_count <= 5 && data->fish_eaten == 4))
        mlx_put_image_to_window(data->mlx, data->win,data->img_play4,x,y);
    else if(((fish_ratio == 100 )&& data->fish_count > 5) ||(data->fish_count <= 5 && data->fish_eaten == 5))
        mlx_put_image_to_window(data->mlx, data->win,data->img_play5,x,y);
}

void num_to_img(int num, int x, t_data *data)
{
    if(num == 9)
        mlx_put_image_to_window(data->mlx, data->win, data->img_9, x, data->win_h);
    if(num == 8)
        mlx_put_image_to_window(data->mlx, data->win, data->img_8, x, data->win_h);
    if(num == 7)
        mlx_put_image_to_window(data->mlx, data->win, data->img_7, x, data->win_h);
    if(num == 6)
        mlx_put_image_to_window(data->mlx, data->win, data->img_6, x, data->win_h);
    if(num == 5)
        mlx_put_image_to_window(data->mlx, data->win, data->img_5, x, data->win_h);
    if(num == 4)
        mlx_put_image_to_window(data->mlx, data->win, data->img_4, x, data->win_h);
    if(num == 3)
        mlx_put_image_to_window(data->mlx, data->win, data->img_3, x, data->win_h);
    if(num == 2)
        mlx_put_image_to_window(data->mlx, data->win, data->img_2, x, data->win_h);
    if(num == 1)
        mlx_put_image_to_window(data->mlx, data->win, data->img_1, x, data->win_h);
    if(num == 0)
        mlx_put_image_to_window(data->mlx, data->win, data->img_0, x, data->win_h);
}

void render_move_count(t_data *data)
{
    int num;
    num = data->counter;
    if (num > 9999)
        num -= 10000;
    num_to_img(num % 10, 35, data);
    num_to_img(num / 10 % 10, 25, data);
    num_to_img(num / 100 % 10, 15, data);
    num_to_img(num / 1000 % 10, 5, data);
}

void    move_changing_states(t_data *data, int dy, int dx)
{
    if(data->map[data->player_posy + dy][data->player_posx + dx] != '1')
    {
        if(data->map[data->player_posy + dy][data->player_posx + dx] != 'E')
        {
            if(data->map[data->player_posy + dy][data->player_posx + dx] == 'X')
                data->lose = 1;
            if(data->map[data->player_posy + dy][data->player_posx + dx] == 'C')
                data->fish_eaten++;
            data->player_posy += dy;
            data->player_posx += dx;
            data->counter++;
        }
        else if (data->fish_count == data->fish_eaten)
        {
            data->player_posy += dy;
            data->player_posx += dx;
            data->epic_win = 1;
            data->counter++;
        }
        render_move_count(data);
    }
    data->map[data->player_posy][data->player_posx] = 'P';
    render_cell(data, data->player_posy, data->player_posx);
    render_cell(data, data->player_posy - dy, data->player_posx - dx);
}

void    move(t_data *data, int dy, int dx)
{
    data->permit = 0;
    data->map[data->player_posy][data->player_posx] = '0';
    move_changing_states(data, dy,dx);
    data->render_cycle = 0;
    if(!data->epic_win && !data->lose)
        enemy_path_counting(data);
    if(data->lose || data->epic_win)
        render_state(data);
}

int     key_hook(int keycode, t_data *data)
{
    if(keycode == 13 && !data->lose && !data->epic_win && !data->start)
        move(data, -1, 0);
    else if(keycode == 0 && !data->lose && !data->epic_win && !data->start)
        move(data, 0, -1);
    else if(keycode == 1 && !data->lose && !data->epic_win && !data->start)
        move(data, 1, 0);
    else if(keycode == 2 && !data->lose && !data->epic_win && !data->start)
        move(data, 0, 1);
    else if(keycode == 53 && !data->start)
        game_close(data);
    else if(keycode == 3)
    {
        data->start = 1;
        game_close(data);
        game(data, data->ac, data->av);
    }
    return (0);
}

void    start_alert(t_data *data)
{
    int i;
    int j;
    i = -1;
    while(++i < data->map_h)
    {
        j = -1;
        while (++j < data->map_w)
            mlx_put_image_to_window(data->mlx, data->win, data->img_empt, j * data->cell_size,i * data->cell_size);
    }
    render_while_bg_counter(data);
    mlx_string_put(data->mlx, data->win, 5, data->win_h + 5, 0x00000000, "Welcome SoLongCat:)");
}