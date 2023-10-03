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
        || game->F = 0 || game->C = 0)
        {
            write(2, "error at line value\n", 21);
            exit (1);
        }
    return (0);
}

int color_value(char *line, int *i)
{
    int j;
    int x;//k
    int color;
    char *rgb;

    if (line[*i] == ',')
        (*i)++;
    while (line[*i] && line[*i] == ' ')
        (*i)++;
    if (line[*])
        j = *i;
    while (line[*i] && line[*i] != ',' && line[*i] != ' ')
		(*i)++;
	rgb = ft_substr(line, j, *i - j);
    while (rgb[k])
    {
        if(!ft_isdigit(rgb[k]))
        {
            write(2, "error at color value\n", 21);
            exit (1);
        }
        i++;
    }
    //check for rgb 0;
    color = ft_atoi(rgb);
    free(rgb);
    if (color < 0 || color > 255)
    {
        write(2, "error at color value\n", 21);
        exit (1);
    }
    return (color);
}
void	color_pars(t_game *game, char *line, int token, int i)
{
	int		color[3];
	int		n;

	n = 0;
	while (n < 3)
	{
		skipe_spaces(line, &i);
		color[n] = get_color(line, &i);
        n++;
	}
	if (line[i])
    {
        write(2, "error is invalid\n", 21);
        exit (1);
    }
	check_nums(line);//check_lenght
	free(line);
}