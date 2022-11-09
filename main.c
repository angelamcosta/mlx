/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 18:09:42 by anlima            #+#    #+#             */
/*   Updated: 2022/11/09 18:47:43 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct s_vars
{
	int		pos;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	int		img_width;
	int		img_height;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	(void)vars;
	if (keycode)
		printf("keycode: %d\n", keycode);
	if (keycode == 32 && vars->pos++)
	{
		mlx_clear_window(vars->mlx, vars->mlx_win);
		mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->img, 15 + vars->pos, 15);
	}
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->mlx_win);
		exit(0);
	}
	return (0);
}

int	main(void)
{
	t_vars vars;

	vars.pos = 0;
	vars.mlx = mlx_init(); //inicia o mlx
	vars.mlx_win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!"); // cria a janela
	vars.img = mlx_xpm_file_to_image(vars.mlx, "./teste.xpm", &vars.img_width, &vars.img_height); //carrega a imagem no ponteiro 


	//funcao para detetar teclas e eventos
	mlx_hook(vars.mlx_win, 2, 1L<<0, close, &vars);

	//cria o loop do mlx
	mlx_loop(vars.mlx);
}
