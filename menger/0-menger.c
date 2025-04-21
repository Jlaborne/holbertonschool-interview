#include "menger.h"
#include <stdio.h>
#include <math.h>  // Pour pow()

/**
 * is_space - Vérifie si une case doit être vide (' ') ou pleine ('#')
 * @x: Coordonnée en X
 * @y: Coordonnée en Y
 *
 * Return: 1 si vide, 0 si pleine
 */
int is_space(int x, int y)
{
    while (x > 0 || y > 0)
    {
        if (x % 3 == 1 && y % 3 == 1)
            return 1;  // Case centrale = vide
        x /= 3;
        y /= 3;
    }
    return 0;  // Case pleine
}

/**
 * menger - Dessine une éponge de Menger de niveau donné
 * @level: Niveau de l’éponge (>= 0)
 */
void menger(int level)
{
    if (level < 0)
        return;

    int size = pow(3, level);  // Taille de l’éponge : 3^level

    for (int y = 0; y < size; y++)
    {
        for (int x = 0; x < size; x++)
        {
            if (is_space(x, y))
                putchar(' ');
            else
                putchar('#');
        }
        putchar('\n');
    }
}