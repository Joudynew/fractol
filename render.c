#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static void	mandel_vs_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static void	calculate_fractal(t_complex z, t_complex c,
	t_fractal *fractal, int coords[2])
{
	int			i;
	int			color;
	t_range		color_range;
	t_range		iter_range;

	color_range.min = BLACK;
	color_range.max = WHITE;
	iter_range.min = 0;
	iter_range.max = fractal->iterations_defintion;
	i = 0;
	while (i < fractal->iterations_defintion)
	{
		z = sum_complex(square_complex(z), c);
		if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
		{
			color = map(i, color_range, iter_range);
			my_pixel_put(coords[0], coords[1], &fractal->img, color);
			return ;
		}
		++i;
	}
	my_pixel_put(coords[0], coords[1], &fractal->img, BLACK);
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			coords[2];
	t_ranges	ranges;

	ranges = setup_ranges();
	z.x = (map(x, ranges.x_range, ranges.screen_x) * fractal->zoom)
		+ fractal->shift_x;
	z.y = (map(y, ranges.y_range, ranges.screen_y) * fractal->zoom)
		+ fractal->shift_y;
	mandel_vs_julia(&z, &c, fractal);
	coords[0] = x;
	coords[1] = y;
	calculate_fractal(z, c, fractal, coords);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, fractal);
		}
	}
	mlx_put_image_to_window(fractal->mlx_connection,
		fractal->mlx_window,
		fractal->img.img_ptr,
		0, 0);
}
