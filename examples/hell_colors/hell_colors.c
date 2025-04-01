#include <stdio.h>

#define HELL_COLORS_IMPLEMENTATION
#include "../../hell_colors.h"

int main()
{
    RGB color = { 100, 20, 150};

    print_rgb(color);
    printf("\n----\n");

    color = lighten_color(color, 0.7);

    print_rgb(color);
    printf("\n----\n");


    for (int i = 0; i < 10; i++)
    {
        color = saturate_color(color, i * 0.1);
        print_rgb(color);
    }
    printf("\n----\n");

    return 0;
}
