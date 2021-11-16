#ifndef _SO_LONG_H_
#define _SO_LONG_H_

#include <stdlib.h>
#include <fcntl.h>
#include "mlx/mlx.h"
# include <unistd.h>

typedef	struct	s_list
{
    void			*content;
    struct s_list	*next;
}				t_list;

typedef struct	s_split_next
{
    size_t start;
    size_t length;
}				t_split_next;

typedef struct	s_data {
    void	*mlx;
    void	*win;
    void    *img;
    void    *addr;
    int     win_w;
    int     win_h;
    int     line_length;
    int     bits_per_pixel;
    int     endian;
    char    **map;
    int     map_h;
    int     map_w;
    int     cell_size;
    int     error;
    int     player_posx;
    int     player_posy;
    int     counter;
    int     epic_win;
    void    *img_coll;
    void    *img_wall;
    void    *img_exit;
    void    *img_empt;
    void    *img_play0;
    void    *img_play1;
    void    *img_play2;
    void    *img_play3;
    void    *img_play4;
    void    *img_play5;
    void    *img_0;
    void    *img_1;
    void    *img_2;
    void    *img_3;
    void    *img_4;
    void    *img_5;
    void    *img_6;
    void    *img_7;
    void    *img_8;
    void    *img_9;
    void    *enemy_0;
    void    *enemy_1;
    void    *enemy_2;
    int enemy_count;
    int fish_count;
    int fish_eaten;
    int fd;
    int exit_count;
    int player_count;
    int count_line_height;
    int start_alert_def;
    int **path;
    int path_count_char;
    int path_count;
    int render_cycle;
    int permit;
    int lose;
    int start;
    int ac;
    char **av;
}				t_data;

void game(t_data *data, int ac, char **av);
int     ft_strlen_2(char **str);
void    error_msg(t_data *data);
void    game_free(t_data *data);
int     game_close(t_data *data);
void    png(t_data *data);
void    map_validation(t_data *data);
void    map_load(t_data *data);
void    map_render_param_proc(t_data *data);
void    data_init(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void    cat_fatness(t_data *data, int x, int y);
void    render_cell(t_data *data, int h, int w);
void    render_cells(t_data *data);
void    move(t_data *data, int dy, int dx);
int     key_hook(int keycode, t_data *data);
void    start_alert(t_data *data);
void    map_render(t_data *data);
void    file_load(t_data *data, int ac, char **av);
void    map_validation_core(t_data *data, int y);
char    **ft_split(char const *s, char c);
void    ft_bzero(void *s, size_t n);
void    ft_putchar_fd(char c, int fd);
void    ft_putnbr_fd(int n, int fd);
void    ft_putstr_fd(char *s, int fd);
char    *ft_strchr(const char *s, int c);
char    *ft_strdup(const char *s1);
char    **ft_ptrstrdup(char **s1);
char    *ft_strjoin(char const *s1, char const *s2);
size_t  ft_strlen(const char *s);
size_t  ft_ptrstrlen(char **s);
char    *ft_substr(char const *s, unsigned int start, size_t len);
void    enemy_path_counting(t_data *data);
void    render_state(t_data *data);
void    render_while_bg_counter(t_data *data);


#endif