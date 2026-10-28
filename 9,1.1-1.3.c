1.1
#include <stdio.h>

#define ROW 9
#define COL 9

int main(void)
{
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", col * row);
        printf("\n");           // переход на новую строку после каждой строки таблицы
    }
    return 0;
}

1.2

#include <stdio.h>

#define ROW 9
#define COL 9

int main(void)
{
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", col * row);
        printf("\n");           // переход на новую строку после каждой строки таблицы
    }
    return 0;
}

1.3

#include <stdio.h>

#define ROW 9
#define COL 9

int main(void)
{
    int row, col;
    printf("\n");
    for (row = 1; row <= ROW; ++row)
    {
        for (col = 1; col <= COL; col++)
            printf("%5d", col * row);
        printf("\n");           // переход на новую строку после каждой строки таблицы
    }
    return 0;
}
