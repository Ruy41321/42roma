#include "includes/so_long.h"
 
int on_destroy(t_pointers *ptr)
{
	mlx_destroy_window(ptr->mlx, ptr->win);
	mlx_destroy_display(ptr->mlx);
	free(ptr->mlx);
	exit(0);
	return (0);
}
 
int on_keypress(int keysym, t_pointers *ptr)
{
	(void)ptr;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}
 
int main(void)
{
	t_pointers ptr;
 
	ptr.mlx = mlx_init();
	if (!ptr.mlx)
		return (1);
	ptr.win = mlx_new_window(ptr.mlx, 600, 400, "SO_LONG");
	if (!ptr.win)
		return (free(ptr.mlx), 1);

	mlx_hook(ptr.win, KeyRelease, KeyReleaseMask, &on_keypress, &ptr);

	mlx_hook(ptr.win, DestroyNotify, StructureNotifyMask, &on_destroy, &ptr);

	mlx_loop(ptr.mlx);
	return (0);
}