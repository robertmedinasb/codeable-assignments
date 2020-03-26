#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 0 || height > 8);
    for (int i = 0; i < height; i++)
    {
        for (int j = (height - i); j >= 0; j--)
        {
            printf(" ");
        }
        for (int k = 1; k <= (i + 1); k++)
        {
            printf("#");
        }
        printf(" ");
        for (int a = 1; a <= (i + 1); a++)
        {
            printf("#");
        }
        printf("\n");
    }
}
