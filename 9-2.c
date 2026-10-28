2 длинное

#include <stdio.h>

int main(void)
{
    char answer;

    do
    {
        long long x;
        int d[20];              // d[0] - младшая (последняя) цифра, d[n-1] - старшая
        int n = 0;

        printf("\nВведите целое число: ");
        if (scanf("%lld", &x) != 1)
        {
            printf("Ошибка ввода.\n");
            return 1;
        }
        if (x < 0) x = -x;

        // разложение числа на цифры
        do
        {
            d[n++] = (int)(x % 10);
            x /= 10;
        } while (x > 0);

        int c3 = 0, lastRep = 0, evenCnt = 0, gt5 = 0;
        int sumOdd = 0, sumGe7 = 0, sumEvenNoLast = 0;
        unsigned long long prodNonZero = 1;
        int hasNonZero = 0;

        for (int i = 0; i < n; i++)
        {
            if (d[i] == 3) c3++;                        // 1
            if (d[i] == d[0]) lastRep++;                // 2
            if (d[i] % 2 == 0) evenCnt++;               // 3
            if (d[i] > 5) gt5++;                        // 4
            if (d[i] % 2 != 0) sumOdd += d[i];          // 5
            if (d[i] >= 7) sumGe7 += d[i];              // 6
            if (d[i] != 0)                              // 7
            {
                prodNonZero *= d[i];
                hasNonZero = 1;
            }
            if (i > 0 && d[i] % 2 == 0)                 // 9 (i = 0 - последняя цифра)
                sumEvenNoLast += d[i];
        }
        if (!hasNonZero) prodNonZero = 0;

        printf("\nЦифр в числе: %d\n", n);
        printf("1)  Количество цифр 3: %d\n", c3);
        printf("2)  Повторений последней цифры (%d): %d\n", d[0], lastRep);
        printf("3)  Количество чётных цифр: %d\n", evenCnt);
        printf("4)  Количество цифр больше 5: %d\n", gt5);
        printf("5)  Сумма нечётных цифр: %d\n", sumOdd);
        printf("6)  Сумма цифр >= 7: %d\n", sumGe7);
        printf("7)  Произведение цифр без нулей: %llu\n", prodNonZero);

        // 8: предпоследняя цифра = d[1], вторая цифра (слева) = d[n-2]
        if (n >= 2)
            printf("8)  Произведение предпоследней и второй цифры: %d\n", d[1] * d[n - 2]);
        else
            printf("8)  Недостаточно цифр\n");

        printf("9)  Сумма чётных цифр без последней: %d   <-- вариант 9\n", sumEvenNoLast);

        // 10: соседние одинаковые цифры
        printf("10) Рядом стоящие одинаковые цифры: ");
        int pairs = 0;
        for (int i = n - 1; i > 0; i--)                 // слева направо
            if (d[i] == d[i - 1])
            {
                printf("%d%d ", d[i], d[i - 1]);
                pairs++;
            }
        if (pairs == 0) printf("нет");
        printf("\n");

        // 11: сумма первой и второй половины (при нечётном n средняя цифра не учитывается)
        int half = n / 2, sumRight = 0, sumLeft = 0;
        for (int i = 0; i < half; i++)
        {
            sumRight += d[i];               // младшие цифры
            sumLeft  += d[n - 1 - i];       // старшие цифры
        }
        printf("11) Сумма первой половины = %d, второй = %d, %s\n",
               sumLeft, sumRight, sumLeft == sumRight ? "равны" : "не равны");

        // 12: разряды считаем с младшего (1-й разряд = d[0])
        int sumOddPos = 0, sumEvenPos = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) sumOddPos += d[i];      // 1, 3, 5... разряды
            else            sumEvenPos += d[i];     // 2, 4, 6... разряды
        }
        printf("12) Сумма цифр нечётных разрядов = %d, чётных = %d, произведение = %d\n",
               sumOddPos, sumEvenPos, sumOddPos * sumEvenPos);

        printf("\nПродолжить? (Да - y, нет - n): ");
        scanf(" %c", &answer);          // пробел перед %c пропускает символ перевода строки

    } while (answer != 'n' && answer != 'N');

    return 0;
}

