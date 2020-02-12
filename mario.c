#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do 
    {
        height = get_int("How tall the pyramids should be?\n");
    }
    while (height < 1 || height > 8);
    for (int i = 0; i < height; i++)
    {
        for (int n = 0; n < height - i - 1; n++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("  ");
        for (int h = 0; h < i + 1; h++)
        {
            printf("#");
        }
        printf("\n");
    }

}
