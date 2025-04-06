#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}

static int	get_smooth_color(double iteration, t_fractal *fractal)
{
	double	normalized;
	int		r;
	int		g;
	int		b;

	normalized = iteration / fractal->iterations_defintion;
	
	// Deep blue to light blue gradient
	if (normalized < 0.2)
	{
		// Deep space blue to royal blue
		r = (int)(normalized * 5 * 30);
		g = (int)(normalized * 5 * 30);
		b = 100 + (int)(normalized * 5 * 155);
	}
	else if (normalized < 0.5)
	{
		// Royal blue to sky blue
		r = 30 + (int)((normalized - 0.2) * 3.33 * 40);
		g = 30 + (int)((normalized - 0.2) * 3.33 * 150);
		b = 255;
	}
	else if (normalized < 0.8)
	{
		// Sky blue to cyan
		r = 70 + (int)((normalized - 0.5) * 3.33 * 0);
		g = 180 + (int)((normalized - 0.5) * 3.33 * 75);
		b = 255;
	}
	else 
	{
		// Cyan to white (highlight)
		r = 70 + (int)((normalized - 0.8) * 5 * 185);
		g = 255;
		b = 255;
	}
	
	// Ensure values stay in range 0-255
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	
	return ((r << 16) | (g << 8) | b);
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
	double		zx_squared;
	double		zy_squared;
	double		smooth_i;
	int			color;

	i = 0;
	zx_squared = 0;
	zy_squared = 0;
	
	while (i < fractal->iterations_defintion)
	{
		zx_squared = z.x * z.x;
		zy_squared = z.y * z.y;
		
		if ((zx_squared + zy_squared) > fractal->escape_value)
		{
			// Smooth coloring formula
			smooth_i = i + 1 - log(log(sqrt(zx_squared + zy_squared))) / log(2.0);
			color = get_smooth_color(smooth_i, fractal);
			my_pixel_put(coords[0], coords[1], &fractal->img, color);
			return;
		}
		
		z = sum_complex(square_complex(z), c);
		++i;
	}
	// Change this line to use BLACK for the interior points
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
