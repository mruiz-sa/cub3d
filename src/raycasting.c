/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarzana <amarzana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:41:59 by amarzana          #+#    #+#             */
/*   Updated: 2023/01/16 11:27:37 by amarzana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	init_pos_calculate_ray(int x, t_control *ctr)
{
	t_ray	*ray;

	ray = ctr->ray;
	ray->map_x = ctr->pos_x;
	ray->map_y = ctr->pos_y;
	ray->hit = 0;
	ray->camera_x = 2 * x / (double) ctr->width - 1;
	ray->raydir_x = ctr->dir_x + ctr->plane_x * ray->camera_x;
	ray->raydir_y = ctr->dir_y + ctr->plane_y * ray->camera_x;
}

void	get_deltadist(t_control *ctr)
{
	t_ray	*ray;

	ray = ctr->ray;
	if (ray->raydir_x == 0)
		ray->deltadist_x = 1e30;
	else
		ray->deltadist_x = fabs(1 / ray->raydir_x);
	if (ray->raydir_y == 0)
		ray->deltadist_y = 1e30;
	else
		ray->deltadist_y = fabs(1 / ray->raydir_y);
}

void	get_step_sidedist(t_control *ctr)
{
	t_ray	*ray;

	ray = ctr->ray;
	if (ray->raydir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (ctr->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - ctr->pos_x) * ray->deltadist_x;
	}
	if (ray->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (ctr->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - ctr->pos_y) * ray->deltadist_y;
	}
}

void	dda_algorithm(t_control *ctr)
{
	t_ray	*ray;

	ray = ctr->ray;
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (ctr->state->only_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	calculate_dist_draw(t_control *ctr)
{
	t_ray	*ray;

	ray = ctr->ray;
	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedist_x - ray->deltadist_x);
	else
		ray->perpwalldist = (ray->sidedist_y - ray->deltadist_y);
	ray->lineheight = ctr->height / ray->perpwalldist;
	ray->drawstart = -ray->lineheight / 2 + ctr->height / 2;
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	ray->drawend = ray->lineheight / 2 + ctr->height / 2;
	if (ray->drawend >= ctr->height)
		ray->drawend = ctr->height - 1;
}
