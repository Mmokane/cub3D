#include "../includes/cub3d.h"

int player_exist(char c)
{
    if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
        return (1);
    return (0);
}

int lines_value(t_game *game)
{
    if (game->we == NULL || game->no == NULL
        || game->ea == NULL || game->so == NULL
        || game->F = -1 || game->C = -1)
        {
            write(2, "error at line value\n", 21);
            exit (1);
        }
    return (0);
}