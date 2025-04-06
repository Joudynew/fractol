#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h> // Make sure this is included
# include <X11/X.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"

# define ERROR_MESSAGE "\"./fractol mandelbrot\" or \"./fractol julia <x> <y>\""

# define WIDTH 1000
# define HEIGHT 1000

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF

# define DEEP_SPACE_BLUE 0x000033      // Deep dark blue for space-like backgrounds
# define COSMIC_PURPLE 0x4B0082        // Deep indigo/purple
# define NEBULA_PINK 0xFF1493         // Vibrant pink
# define AURORA_GREEN 0x7FFF00        // Bright chartreuse green
# define QUANTUM_TEAL 0x008B8B        // Dark cyan/teal
# define SOLAR_GOLD 0xFFD700          // Bright gold
# define PLASMA_ORANGE 0xFF8C00       // Dark orange
# define GALACTIC_RED 0x8B0000        // Dark red
# define VOID_BLACK 0x0A0A0A          // Near-black for depth
# define CELESTIAL_CYAN 0x00FFFF      // Bright cyan
# define FUSION_MAGENTA 0xFF00FF      // Bright magenta
# define NEUTRON_WHITE 0xF8F8FF      // Ghost white
# define ELECTRON_BLUE 0x1E90FF      // Dodger blue
# define PHOTON_YELLOW 0xFFFF00      // Bright yellow
# define ANTIMATTER_VIOLET 0x9400D3  // Dark violet
# define QUASAR_AZURE 0x007FFF       // Azure blue

typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;

typedef struct s_img
{
	void	*img_ptr;
	char	*pixels_ptr;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;

	double	escape_value;
	int		iterations_defintion;
	double	shift_x;
	double	shift_y;
	double	zoom;
	double	julia_x;
	double	julia_y;
}				t_fractal;

typedef struct	s_range
{
	double	min;
	double	max;
}				t_range;

typedef struct s_ranges
{
	t_range	x_range;
	t_range	y_range;
	t_range	screen_x;
	t_range	screen_y;
}				t_ranges;

t_ranges	setup_ranges(void);

int			ft_strncmp(char *s1, char *s2, int n);
void		putstr_fd(char *s, int fd);
double		atodbl(char *s);

void		fractal_init(t_fractal *fractal);

void		fractal_render(t_fractal *fractal);

double		map(double unscaled_num, t_range new_range, t_range old_range);
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);

int			key_handler(int keysym, t_fractal *fractal);

int			close_handler(t_fractal *fractal);
int			mouse_handler(int button, int x, int y, t_fractal *fractal);

#endif