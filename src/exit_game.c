/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtanigaw <dtanigaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 02:51:35 by dtanigaw          #+#    #+#             */
/*   Updated: 2021/08/11 05:14:12 by dtanigaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
/*
void	sl_display_game_over_screen(t_env *env)
{
	static int	i;

	if (i < 3200)

}
*/
int    sl_exit_game(t_env *env, char *err_mess)
{
 //   free(env->map);
/*
	mlx_destroy_image(env->mlx_ptr, env->bkgd.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.wall.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.bomb.item_bomb.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.exit_pipe.state0.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.exit_pipe.state1.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.exit_pipe.state2.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.exit_pipe.state3.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.exit_pipe.state4.mlx_img);
	mlx_destroy_image(env->mlx_ptr, env->tex.exit_pipe.state5.mlx_img);
	mlx_destroy_window(env->mlx_ptr, env->win_ptr);*/
	mlx_destroy_display(env->mlx_ptr);
	mlx_loop_end(env->mlx_ptr);
	ft_free(env->mlx_ptr);
    if (err_mess)
	{
        printf("%s\n", err_mess);
		exit(EXIT_FAILURE);
	}
	else
		exit(EXIT_SUCCESS);
	return (0);
}

void	sl_exit_game_over(t_env *env)
{
	static int	i;
	int			collected;
	int			to_collect;

	collected = env->tex.bomb.collected;
	to_collect = env->tex.bomb.to_collect;
	if (i <= CENTER_MESS_TIME)
		sl_put_centered_message_to_window(env, "GAME OVER !");
	else
	{
		printf("\n");
		printf("GAME OVER\n");
		printf("Collected items: %d/%d\n", collected, to_collect);
		sl_exit_game(env, NULL);
	}
	++i;
}