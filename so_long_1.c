//
// Created by fcody on 6/28/21.
//
#include "so_long.h"
#include <stdio.h>

void    png(t_data *data)
{
    char *path[10];
    int size;

    path[0] = "xpm/coll1.xpm";
    path[1] = "xpm/exit1.xpm";
    path[2] = "xpm/wall1.xpm";
    path[3] = "xpm/empt1.xpm";
    path[4] = "xpm/play0.xpm";
    path[5] = "xpm/play1.xpm";
    path[6] = "xpm/play2.xpm";
    path[7] = "xpm/play3.xpm";
    path[8] = "xpm/play4.xpm";
    path[9] = "xpm/play5.xpm";
    data->img_coll = mlx_xpm_file_to_image(data->mlx, path[0], &size, &size);
    data->img_play0 = mlx_xpm_file_to_image(data->mlx, path[4], &size, &size);
    data->img_play1 = mlx_xpm_file_to_image(data->mlx, path[5], &size, &size);
    data->img_play2 = mlx_xpm_file_to_image(data->mlx, path[6], &size, &size);
    data->img_play3 = mlx_xpm_file_to_image(data->mlx, path[7], &size, &size);
    data->img_play4 = mlx_xpm_file_to_image(data->mlx, path[8], &size, &size);
    data->img_play5 = mlx_xpm_file_to_image(data->mlx, path[9], &size, &size);
    data->img_exit = mlx_xpm_file_to_image(data->mlx, path[1], &size, &size);
    data->img_wall = mlx_xpm_file_to_image(data->mlx, path[2], &size, &size);
    data->img_empt = mlx_xpm_file_to_image(data->mlx, path[3], &size, &size);
    if(!data->img_exit || !data->img_wall || !data->img_coll || !data->img_empt || !data->img_play0 || !data->img_play1 || !data->img_play2 || !data->img_play3 || !data->img_play4 || !data->img_play5)
        data->error = 7;
}

void    png2(t_data *data)
{
    char *path[10];
    int size;

    path[0] = "xpm/0.xpm";
    path[1] = "xpm/1.xpm";
    path[2] = "xpm/2.xpm";
    path[3] = "xpm/3.xpm";
    path[4] = "xpm/4.xpm";
    path[5] = "xpm/5.xpm";
    path[6] = "xpm/6.xpm";
    path[7] = "xpm/7.xpm";
    path[8] = "xpm/8.xpm";
    path[9] = "xpm/9.xpm";
    data->img_0 = mlx_xpm_file_to_image(data->mlx, path[0], &size, &size);
    data->img_1 = mlx_xpm_file_to_image(data->mlx, path[1], &size, &size);
    data->img_2 = mlx_xpm_file_to_image(data->mlx, path[2], &size, &size);
    data->img_3 = mlx_xpm_file_to_image(data->mlx, path[3], &size, &size);
    data->img_4 = mlx_xpm_file_to_image(data->mlx, path[4], &size, &size);
    data->img_5 = mlx_xpm_file_to_image(data->mlx, path[5], &size, &size);
    data->img_6 = mlx_xpm_file_to_image(data->mlx, path[6], &size, &size);
    data->img_7 = mlx_xpm_file_to_image(data->mlx, path[7], &size, &size);
    data->img_8 = mlx_xpm_file_to_image(data->mlx, path[8], &size, &size);
    data->img_9 = mlx_xpm_file_to_image(data->mlx, path[9], &size, &size);
    if(!data->img_0 || !data->img_1 || !data->img_2 || !data->img_3 || !data->img_4 || !data->img_5 || !data->img_6 || !data->img_7 || !data->img_8 || !data->img_9)
        data->error = 7;
}

void    png3(t_data *data)
{
    char *path[3];
    int size;

    path[0] = "xpm/enemy1.xpm";
    path[1] = "xpm/enemy2.xpm";
    path[2] = "xpm/enemy3.xpm";
    data->enemy_0 = mlx_xpm_file_to_image(data->mlx, path[0], &size, &size);
    data->enemy_1 = mlx_xpm_file_to_image(data->mlx, path[1], &size, &size);
    data->enemy_2 = mlx_xpm_file_to_image(data->mlx, path[2], &size, &size);
    if(!data->enemy_0 || !data->enemy_1 || !data->enemy_2)
        data->error = 7;
}

void render_enemy(t_data *data)
{
    int x;
    int y;
    y = -1;
    while(data->map[++y])
    {
        x = -1;
        while (data->map[y][++x])
        {
            if(data->map[y][x] == 'X')
                mlx_put_image_to_window(data->mlx, data->win, data->enemy_0, x * data->cell_size,y * data->cell_size);
        }
    }
}

void    render_cell(t_data *data, int h, int w)
{
    int start_x;
    int start_y;
    int x;
    int y;

    start_x = w * data->cell_size;
    start_y = h * data->cell_size;
    x = start_x;
    y = start_y;
    if(data->map[h][w] == 'C')
        mlx_put_image_to_window(data->mlx, data->win,data->img_coll,x,y);
    else if(data->map[h][w] == '1')
        mlx_put_image_to_window(data->mlx, data->win,data->img_wall,x,y);
    else if(data->map[h][w] == 'E')
        mlx_put_image_to_window(data->mlx, data->win,data->img_exit,x,y);
    else if(data->map[h][w] == 'P')
        cat_fatness(data, x,y);
    else
        mlx_put_image_to_window(data->mlx, data->win,data->img_empt,x,y);
}

void    render_while_bg_counter(t_data *data)
{
    int h;
    int w;

    h = -1;
    while (++h < data->count_line_height)
    {
        w = -1;
        while (++w < data->win_w)
            mlx_pixel_put(data->mlx, data->win, w, data->win_h + h, 0x00FFFFFF);
    }
}

void    render_counter(t_data *data)
{
    render_while_bg_counter(data);
    if(!data->epic_win && !data->lose) {
        mlx_put_image_to_window(data->mlx, data->win, data->img_0, 5, data->win_h);
        mlx_put_image_to_window(data->mlx, data->win, data->img_0, 15, data->win_h);
        mlx_put_image_to_window(data->mlx, data->win, data->img_0, 25, data->win_h);
        mlx_put_image_to_window(data->mlx, data->win, data->img_0, 35, data->win_h);
    }
}

void    render_cells(t_data *data)
{
    int h = 0;
    int w;

    while(h < data->map_h)
    {
        w = 0;
        while(w < data->map_w)
           render_cell(data, h, w++);
        h++;
    }
    if(!data->lose && !data->epic_win)
        render_counter(data);
    render_enemy(data);
}

void    render_state(t_data *data)
{
    int i;
    int j;

    i = -1;
    while (++i < data->map_h)
    {
        j = -1;
        while(++j < data->map_w) {
            if(data->map[i][j] != 'X' && data->lose)
                data->map[i][j] = '0';
            if(data->map[i][j] != 'P' && data->epic_win)
                data->map[i][j] = '0';
        }
    }
    render_cells(data);
    render_while_bg_counter(data);
    if(data->lose)
        mlx_string_put(data->mlx, data->win, 0, data->win_h + 7, 0x00000000, "You lose:)Press ESC to exit or F to pay replay with faster enemy");
    if(data->epic_win)
        mlx_string_put(data->mlx, data->win, 0, data->win_h + 7, 0x00000000, "You WIN:)Press ESC to exit  or F to pay replay with faster enemy");
}

void render_next_frame_start(t_data *data, int enemy_counter)
{
    if(!data->start_alert_def)
    {
        start_alert(data);
        data->start_alert_def++;
    }
    if(enemy_counter % 15000 == 0)
    {
        data->start = 0;
        render_cells(data);
        enemy_path_counting(data);
    }
}

void render_next_frame_final_blinding(t_data *data, int enemy_counter, int enem_posx, int enem_posy)
{
    if(data->lose && enemy_counter % 2000 == 0 )
        mlx_put_image_to_window(data->mlx, data->win, data->enemy_0, enem_posx * data->cell_size, enem_posy * data->cell_size);
    if(data->lose && enemy_counter % 2000 == 1000 )
        mlx_put_image_to_window(data->mlx, data->win, data->img_empt, enem_posx * data->cell_size, enem_posy * data->cell_size);
    if(data->epic_win && enemy_counter % 2000 == 0 )
        mlx_put_image_to_window(data->mlx, data->win, data->img_play3, data->player_posx * data->cell_size, data->player_posy * data->cell_size);
    if(data->epic_win && enemy_counter % 2000 == 1000 )
        mlx_put_image_to_window(data->mlx, data->win, data->img_empt, data->player_posx * data->cell_size, data->player_posy * data->cell_size);
}

void    enemy_move(t_data *data, int *enem_posy, int *enem_posx)
{
    data->map[data->path[data->render_cycle][1]][data->path[data->render_cycle][0]] = '0';
    data->map[data->path[data->render_cycle + 1][1]][data->path[data->render_cycle + 1][0]] = 'X';
    *enem_posy = data->path[data->render_cycle + 1][1];
    *enem_posx = data->path[data->render_cycle + 1][0];
    if(*enem_posx == data->player_posx && *enem_posy == data->player_posy)
//    if((*enem_posx + 1 == data->player_posx && *enem_posy == data->player_posy) || (*enem_posx == data->player_posx && *enem_posy + 1 == data->player_posy) || (*enem_posx - 1 == data->player_posx && *enem_posy == data->player_posy) || (*enem_posx == data->player_posx && *enem_posy - 1 == data->player_posy))
    {
        data->lose = 1;
        render_state(data);
    }
    mlx_put_image_to_window(data->mlx, data->win, data->img_empt, data->path[data->render_cycle][0] * data->cell_size,data->path[data->render_cycle][1] * data->cell_size);
    mlx_put_image_to_window(data->mlx, data->win, data->enemy_0, data->path[data->render_cycle + 1][0] * data->cell_size,data->path[data->render_cycle + 1][1] * data->cell_size);
    data->render_cycle++;
    data->path_count--;
}

int render_next_frame(void *data_void)
{
    static int enemy_counter;
    static int enem_posx;
    static int enem_posy;

    t_data *data = (t_data *)data_void;
    enemy_counter++;
    while((data->path_count + 1) > 0 && enemy_counter % 6000 == 0 && data->permit == 1 && data->path && !data->lose)
    {
        enemy_counter++;
        enemy_move(data, &enem_posy, &enem_posx);
    }
    if((data->epic_win || data->lose))
        render_next_frame_final_blinding(data,enemy_counter, enem_posx, enem_posy);
    if(data->start)
        render_next_frame_start(data, enemy_counter);
    return 0;
}

int min_route_num_finder_res(int *pos_arr, int pos_count)
{
    int i;
    int j;
    int flag;

    i = -1;
    while (++i < pos_count)
    {
        j = -1;
        flag = 0;
        while (++j < pos_count)
        {
            if(pos_arr[i] > pos_arr[j])
                flag = 1;
        }
        if(flag == 0)
            return pos_arr[i];
    }
    return 0;
}

int pos_count_count(int *arr)
{
    int i;
    int pos_count;

    pos_count = 0;
    i = -1;
    while (++i < 4)
    {
        if(arr[i] > 0)
            pos_count++;
    }
    return pos_count;
}

int     min_route_num_finder(int a, int b, int c, int d)
{
    int i;
    int pos_count;
    int pos_count_tmp;
    int *pos_arr;
    int arr[4];

    arr[0] = a;
    arr[1] = b;
    arr[2] = c;
    arr[3] = d;
    pos_arr = NULL;
    pos_count = pos_count_count(arr);
    pos_arr = (int *) malloc(sizeof (int) * pos_count);
    i = -1;
    pos_count_tmp = pos_count;
    pos_count_tmp--;
    while (++i < 4)
    {
        if(arr[i] > 0)
            pos_arr[pos_count_tmp--] = arr[i];
    }
    i = min_route_num_finder_res(pos_arr, pos_count);
    free(pos_arr);
    pos_arr = NULL;
    return i;
}

void free_int_arr(int **arr, int size)
{
    int i;

    i = -1;
    while(++i < size)
    {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}

void map_route_writing(int i, int j, t_data *data, int **map_route)
{
    int k;

    k = data->path_count;
    data->path[data->path_count + 1][0] = j;
    data->path[data->path_count + 1][1] = i;
    while(k > 0)
    {
        if (map_route[i - 1][j] && map_route[i - 1][j] == k)
            i -= 1;
        else if (map_route[i + 1][j] && map_route[i + 1][j] == k)
            i += 1;
        if (map_route[i][j - 1] && map_route[i][j - 1] == k)
            j -= 1;
        else if (map_route[i][j + 1] && map_route[i][j + 1] == k)
            j += 1;
        data->path[k][0] = j;
        data->path[k][1] = i;
        k--;
    }
    free_int_arr(map_route, data->map_h);
    data->permit = 1;
}

void finding_enemy_int(int **map_route, int *i, int *j, int size_h, int size_w)
{
    while (++(*i) < size_h)
    {
        *j = -1;
        while (++(*j) < size_w)
        {
            if(map_route[*i][*j] == -80)
                return;
        }
    }
}

void map_route_writing_init(t_data *data,int **map_route, int xx, int yx)
{
    int i;
    int j;
    int k;

    i = -1;
    j = -1;
    if(data->path)
        free_int_arr(data->path, data->path_count + 2);
    data->path = NULL;
    finding_enemy_int(map_route, &i, &j, data->map_h, data->map_w);
    data->path_count = min_route_num_finder(map_route[i + 1][j], map_route[i - 1][j], map_route[i][j + 1], map_route[i][j - 1]);
    data->path = (int **)malloc(sizeof (int*) * (data->path_count + 2));
    k = -1;
    while (++k < data->path_count + 2)
    {
        data->path[k] = (int *) malloc(sizeof(int) * 2);
        data->path[k][0] = 0;
        data->path[k][1] = 0;
    }
    data->path[0][0] = xx;
    data->path[0][1] = yx;
    map_route_writing(i, j, data, map_route);
}

void finding_enemy_char(t_data *data, int *i, int *j)
{
    while(data->map[++(*i)])
    {
        *j = -1;
        while (data->map[*i][++(*j)])
        {
            if(data->map[*i][*j] == 'X')
                return;
        }
    }
}

void    map_proc(int **map_route, t_data *data)
{
    int xx;
    int yx;
    int i;
    int j;
    int x;
    int nums_count;
    int y;
    int count;

    x = -1;
    y = -1;
    finding_enemy_char(data, &y, &x);
    xx = x;
    yx = y;
    count = 0;
    while(1)
    {
        count++;
        nums_count = 1;
        if(count > 1)
        {
            nums_count = 0;
            i = -1;
            while (++i < data->map_h)
            {
                j = -1;
                while (++j < data->map_w)
                {
                    if(map_route[i][j] == (count - 1))
                        nums_count++;
                }
            }
        }
        if(nums_count < 1 && count > 1)
            break;
        while (nums_count--)
        {
            i = 0;
            while (++i < data->map_h - 1)
            {
                if(count < 2) {
                    break;
                }
                j = 0;
                while (++j < data->map_w - 1)
                {
                    if((map_route[i][j] == count - 1 ) && ((map_route[i - 1][j] == 0) || (map_route[i][j + 1]  == 0) || (map_route[i][j - 1]  == 0) || (map_route[i + 1][j]  == 0)))
                        break;
                }
                if((map_route[i][j] == count - 1) && ((map_route[i - 1][j] == 0) || (map_route[i][j + 1]  == 0) || (map_route[i][j - 1]  == 0) || (map_route[i + 1][j]  == 0)))
                {
                    y = i;
                    x = j;
                    break;
                }
            }
            if (map_route[y - 1][x] == 0)
                map_route[y - 1][x] = count;
            if (map_route[y + 1][x] == 0)
                map_route[y + 1][x] = count;
            if (map_route[y][x - 1] == 0)
                map_route[y][x - 1] = count;
            if (map_route[y][x + 1] == 0)
                map_route[y][x + 1] = count;
        }
    }
    map_route_writing_init(data, map_route, xx, yx);
}

void    enemy_path_counting(t_data *data)
{
    int **map_route_int;
    int i;
    int j;

    map_route_int = (int **)malloc(sizeof (int *) * data->map_h);
    i = -1;
    while (++i < data->map_h)
        map_route_int[i] = (int *) malloc(sizeof (int) * data->map_w);
    i = -1;
    while (++i < data->map_h)
    {
        j = -1;
        while (++j < data->map_w)
        {
            map_route_int[i][j] = data->map[i][j];
            if(map_route_int[i][j] == 49 || map_route_int[i][j] == 88 || map_route_int[i][j] == 67 || map_route_int[i][j] == 80 || map_route_int[i][j] == 69)
                map_route_int[i][j] = -map_route_int[i][j];
            if(map_route_int[i][j] == 48)
                map_route_int[i][j] = 0;
        }
    }
    map_proc(map_route_int, data);
}

void    map_render(t_data *data)
{
    ft_putstr_fd("Loading game...\n",1);
     data->mlx = mlx_init();
     data->win = mlx_new_window(data->mlx, data->win_w, data->win_h + data->count_line_height, "Soo Long Cat");
     data->img = mlx_new_image(data->mlx, data->win_w, data->win_h);
     data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_length, &data->endian);
     png(data);
     png2(data);
     png3(data);
     if(data->error)
         game_close(data);
//     mlx_key_hook(data->win, key_hook, data);
     mlx_hook(data->win, 2,0,key_hook,data);
     mlx_hook(data->win, 17,0,game_close,data);
     mlx_loop_hook(data->mlx, render_next_frame, (void *)data);
     mlx_loop(data->mlx);
}
