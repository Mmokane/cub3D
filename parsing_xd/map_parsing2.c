#include "../includes/cub3d.h"

int player_exist(char c)
{
    if (c == 'W' || c == 'N' || c == 'E' || c == 'S')
        return (1);
    return (0);
}

int lines_value(t_game *game)
{
    printf("YETETES\n");
    printf("game->map->we = %s\n", game->map->we);
    printf("game->map->no = %s\n", game->map->no);
    printf("game->map->ea = %s\n", game->map->ea);
    printf("game->map->so = %s\n", game->map->so);
    printf("game->map->F = %d\n", game->map->F);
    printf("game->map->C = %d\n", game->map->C);
    if (game->map->we == NULL || game->map->no == NULL
        || game->map->ea == NULL || game->map->so == NULL
        || game->map->F == -1 || game->map->C == -1)
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

    while (!ft_isdigit(line[*i]))
        (*i)++;
    if (line[*i] == ',')
		(*i)++;
	while (line[*i] && line[*i] == ' ')
		(*i)++;
	j = *i;
	while (line[*i] && line[*i] != ',' && line[*i] != ' ')
		(*i)++;
	rgb = ft_substr(line, j, *i - j);
    x = -1;
    while (rgb[++x])
    {
        if(!ft_isdigit(rgb[x]))
        {
            write(2, "error at color values\n", 21);
            exit (1);
        }
    }
    color = ft_atoi(rgb);
    printf("color = %d\n", color);
    if (!rgb[0])
		ft_putstr_fd("Error hhhh \n", 2);
    free(rgb);
    if (color < 0 || color > 255)
    {
        write(2, "error at color valueeee\n", 21);
        exit (1);
    }
    return (color);
}
void	color_pars(char *line, int i, int token, t_game *game)
{
	int		color[3];
	int		n;

	n = 0;
	while (n < 3)
	{
		space_skipper(line, &i);
		color[n] = color_value(line, &i);
        n++;
	}
	if (line[i])
    {
        write(2, "error h is invalid\n", 18);
        exit (1);
    }
	check_nums(line);//check_lenght
    printf("T_F = %d\n", T_F);
    printf("T_C = %d\n", T_C);
    printf("F hhh = %d\n", game->map->F);
    printf("C hhh = %d\n", game->map->C);
    if (token == T_F && game->map->F == -1)
		game->map->F = (color[0] << 16) + (color[1] << 8) + color[2];
	else if(token == T_C && game->map->C == -1)
		game->map->C = (color[0] << 16) + (color[1] << 8) + color[2];   
	free(line);
    printf("F zp= %d\n", game->map->F);
    printf("C zp= %d\n", game->map->C);
}