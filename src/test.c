#include <stdlib.h>
#include <stdio.h>

typedef struct	s_display
{
	int ncols;
	int nrows;
	int argc;
}				t_display;

int	get_index_right(int i, t_display *display);
int	get_index_left(int i, t_display *display);
int	get_index_top(int i, t_display *display);
int	get_index_bottom(int i, t_display *display);

int main(int argc, char **argv)
{
	t_display disp;
	int i = atoi(argv[1]);

	disp.ncols = 3;
	disp.nrows = 3;
	disp.argc = 7;

	int right = get_index_right(i, &disp);
	int left = get_index_left(i, &disp);
	int top = get_index_top(i, &disp);
	int bottom = get_index_bottom(i, &disp);

	int x;
	int y;
	int k;

	for (x = 0; x < disp.nrows; x++)
	{
		for (y = 0; y < disp.ncols; y++)
		{
			k = y * disp.nrows + x;

			if 		(k == i)		putchar('o');
			else if (k == right)	putchar('R');
			else if (k == left)		putchar('L');
			else if (k == top)		putchar('T');
			else if (k == bottom)	putchar('B');
			else if (k < disp.argc)	putchar('X');
			else					putchar(' ');
		}
		putchar('\n');
	}

	printf("Right = %i\n", get_index_right(i, &disp));
	printf("Left = %i\n", get_index_left(i, &disp));
	printf("Top = %i\n", get_index_top(i, &disp));
	printf("Bottom = %i\n", get_index_bottom(i, &disp));
}
