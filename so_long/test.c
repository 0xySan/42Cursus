/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etaquet <etaquet@student.42lehavre.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:09:10 by etaquet           #+#    #+#             */
/*   Updated: 2024/10/30 01:45:21 by etaquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// -----------------------------------------------------------------------------
// Codam Coding College, Amsterdam @ 2022-2023 by W2Wizard.
// See README in the root project for more information.
// -----------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "includes/so_long.h"

#define WIDTH 512
#define HEIGHT 512

static mlx_image_t* image;

// -----------------------------------------------------------------------------

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void ft_randomize(void* param)
{
	(void)param;
	for (uint32_t i = 0; i < image->width; ++i)
	{
		for (uint32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;
	static bool key_states[4] = {false, false, false, false};

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP) && !key_states[0])
	{
		image->instances[0].y -= (HEIGHT/4);
		key_states[0] = true;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_UP))
		key_states[0] = false;
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN) && !key_states[1])
	{
		image->instances[0].y += (HEIGHT/4);
		key_states[1] = true;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_DOWN))
		key_states[1] = false;
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT) && !key_states[2])
	{
		image->instances[0].x -= (HEIGHT/4);
		key_states[2] = true;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_LEFT))
		key_states[2] = false;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT) && !key_states[3])
	{
		image->instances[0].x += (HEIGHT/4);
		key_states[3] = true;
	}
	else if (!mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		key_states[3] = false;
}
// -----------------------------------------------------------------------------

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t main(void)
{
	mlx_t* mlx;

	if (!(mlx = mlx_init(WIDTH, HEIGHT, "So_long", false)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	xpm_t* xpm = mlx_load_xpm42("./xpm_textures/wall.xpm42");
	if (!xpm)
		error();
	mlx_image_t* img = mlx_texture_to_image(mlx, &xpm->texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();
	mlx_set_setting(MLX_STRETCH_IMAGE, false);
	mlx_set_setting(MLX_MAXIMIZED, false);
	if (!(image = mlx_new_image(mlx, 128, 128)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_hook, mlx);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	printf("Exiting the game.\n");
	return (EXIT_SUCCESS);
}

/* #include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "MLX42.h"
#define WIDTH 128
#define HEIGHT 64

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	// Start mlx
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Test", true);
	if (!mlx)
		error();

	// Try to load the file
	mlx_texture_t* texture = mlx_load_png("/home/oxy/Downloads/kys.png");
	if (!texture)
		error();
	
	// Convert texture to a displayable image
	mlx_image_t* img = mlx_texture_to_image(mlx, texture);
	if (!img)
		error();

	// Display the image
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
		error();

	mlx_loop(mlx);

	mlx_delete_image(mlx, img);
	mlx_delete_texture(texture);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
} */