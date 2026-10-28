/*
 * Автор: <ФИО>, группа <номер>
 * Работа 8. Задание 3, вариант 7.
 * Программа вычисляет значение ряда
 * x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + x^13/13!
 * для заданного пользователем x с использованием цикла for.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TERMS_COUNT 7       /* число членов ряда */
#define ANSWER_NO   'n'     /* ответ, завершающий программу */

double series_sum(double x, int terms);

int main(void) {
	double x;       /* аргумент ряда */
	double sum;     /* значение ряда */
	char answer;    /* ответ пользователя о продолжении */

	system("chcp 1251 > nul");
	printf("Программа вычисляет значение ряда\n");
	printf("x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - x^11/11! + x^13/13!\n");
	printf("для заданного значения x.\n");

	do {
		printf("\nВведите x: ");
		if (scanf("%lf", &x) != 1) {
			printf("Ошибка ввода.\n");
			return EXIT_FAILURE;
		}

		sum = series_sum(x, TERMS_COUNT);
		printf("Значение ряда: %.8f\n", sum);
		printf("Контроль, sin(x): %.8f\n", sin(x));

		printf("\nПродолжить? (Да - любой символ, нет - %c): ", ANSWER_NO);
		scanf(" %c", &answer);
	} while (answer != ANSWER_NO);

	return EXIT_SUCCESS;
}

/*
 * вычисляет сумму первых terms членов знакочередующегося ряда
 * x - x^3/3! + x^5/5! - ...
 * x - значение аргумента
 * terms - число суммируемых членов (terms >= 1)
 * возвращает значение суммы
 * каждый следующий член получается из предыдущего умножением
 * на -x^2 / ((2k) * (2k + 1)), поэтому степени и факториалы
 * отдельно не вычисляются, а знак чередуется без условного оператора
 */
double series_sum(double x, int terms) {
	double term = x;    /* текущий член ряда со знаком */
	double sum = x;     /* накопленная сумма */
	int k;              /* номер члена ряда */

	for (k = 1; k < terms; k++) {
		term *= -x * x / ((2.0 * k) * (2.0 * k + 1.0));
		sum += term;
	}
	return sum;
}
