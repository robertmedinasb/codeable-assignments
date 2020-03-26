#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;

    do
    {
        height = get_int("Height: ");
    } while (height < 0);
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
        printf("\n");
    }
}
