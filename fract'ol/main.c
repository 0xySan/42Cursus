
#include "mlx.h"

int main()
{
    void *test = mlx_init();
    void *test2 = mlx_new_window(test, 10, 10, "test");
}