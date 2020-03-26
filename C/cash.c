#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float ammount;
    int cents;
    int quarters = 0;
    int dimes = 0;
    int nickels = 0;
    int pennies = 0;

    do
    {
        ammount = get_float("Ammount: $");
        cents = ammount * 100;
        printf("The Ammount in cents is: $%i\n", cents);

    } while (cents < 0);
    while (cents > 24)
    {
        quarters++;
        cents = cents - 25;
    }
    while (cents > 9)
    {
        dimes++;
        cents = cents - 10;
    }
    while (cents > 4)
    {
        nickels++;
        cents = cents - 5;
    }
    while (cents > 0)
    {
        pennies++;
        cents = cents - 1;
    }

    printf("¢25: %i, ¢10:%i, ¢5:%i, ¢1:%i\n", quarters, dimes, nickels, pennies);
}
