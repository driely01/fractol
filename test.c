#include <mlx.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 100

int main() {
    double xMin = -1.5, xMax = 1.5;
    double yMin = -1.5, yMax = 1.5;
    double real, imaginary, r2, i2;
    int x, y, iterations;
    void *mlx;
    void *window;
    int *img;

    mlx = mlx_init();
    window = mlx_new_window(mlx, WIDTH, HEIGHT, "Buddha Fractal");
    img = mlx_new_image(mlx, WIDTH, HEIGHT);

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            real = xMin + (xMax - xMin) * x / WIDTH;
            imaginary = yMax - (yMax - yMin) * y / HEIGHT;
            r2 = real * real;
            i2 = imaginary * imaginary;
            iterations = 0;

            while (r2 + i2 <= 4 && iterations < MAX_ITER) {
                imaginary = 2 * real * imaginary + 0.25;
                real = r2 - i2 + 0.6;
                r2 = real * real;
                i2 = imaginary * imaginary;
                iterations++;
            }

            mlx_pixel_put(mlx, window, x, y, (iterations % 50) << 16 | (iterations % 50) << 8 | (iterations % 50));
        }
    }

   // mlx_put_image_to_window(mlx, window, img, 0, 0);
    mlx_loop(mlx);

    return 0;
}
