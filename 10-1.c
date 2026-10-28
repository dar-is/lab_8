/*
 * Автор: <ФИО>, группа <номер>
 * Работа 10. Задание 1.
 * Программа вычисляет значения двух функций F1(x) и F2(x),
 * их произведение, разность квадратов и удвоенную сумму.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MENU_EXIT   0   /* пункты меню */
#define MENU_FA     1
#define MENU_FB     2
#define MENU_PROD   3
#define MENU_DIFF   4
#define MENU_SUM    5
#define MENU_ALL    6

#define SUM_FACTOR      2.0 /* множитель для удвоенной суммы */
#define BRANCH_LIMIT    3.0 /* граница ветвления функции F1 */

double fa(double x);
double fb(double x);
double calc_product(double x);
double calc_diff_squares(double x);
double calc_double_sum(double x);

int main(void) {
	int choice; /* выбранный пункт меню */
	double x;   /* аргумент функций */

	system("chcp 1251 > nul");
	printf("Программа вычисляет функции F1(x) и F2(x), их произведение,\n");
	printf("разность квадратов и удвоенную сумму для заданного x.\n");
	printf("F1(x) = x^2 - 3x + 9 при x <= 3, 1 / (x^3 + 3) при x > 3\n");
	printf("F2(x) = x * exp(sin(x^2))\n");

	do {
		printf("\nМеню:\n");
		printf("%d - значение F1(x)\n", MENU_FA);
		printf("%d - значение F2(x)\n", MENU_FB);
		printf("%d - произведение F1(x) * F2(x)\n", MENU_PROD);
		printf("%d - разность квадратов F1(x)^2 - F2(x)^2\n", MENU_DIFF);
		printf("%d - удвоенная сумма 2 * (F1(x) + F2(x))\n", MENU_SUM);
		printf("%d - все результаты\n", MENU_ALL);
		printf("%d - выход\n", MENU_EXIT);
		printf("Ваш выбор: ");
		if (scanf("%d", &choice) != 1) {
			printf("Ошибка ввода.\n");
			return EXIT_FAILURE;
		}

		if (choice >= MENU_FA && choice <= MENU_ALL) {
			printf("Введите x: ");
			if (scanf("%lf", &x) != 1) {
				printf("Ошибка ввода.\n");
				return EXIT_FAILURE;
			}
		}

		switch (choice) {
		case MENU_FA:
			printf("fa(x) = %f\n", fa(x));
			break;
		case MENU_FB:
			printf("fb(x) = %f\n", fb(x));
			break;
		case MENU_PROD:
			printf("произведение = %f\n", calc_product(x));
			break;
		case MENU_DIFF:
			printf("разность квадратов = %f\n", calc_diff_squares(x));
			break;
		case MENU_SUM:
			printf("удвоенная сумма = %f\n", calc_double_sum(x));
			break;
		case MENU_ALL:
			printf("fa(x) = %f , fb(x) = %f\n", fa(x), fb(x));
			printf("произведение = %f\n", calc_product(x));
			printf("разность квадратов = %f\n", calc_diff_squares(x));
			printf("удвоенная сумма = %f\n", calc_double_sum(x));
			break;
		case MENU_EXIT:
			printf("Работа завершена.\n");
			break;
		default:
			printf("Нет такого пункта меню.\n");
			break;
		}
	} while (choice != MENU_EXIT);

	return EXIT_SUCCESS;
}

/*
 * вычисляет значение кусочно-заданной функции F1
 * x - аргумент функции
 * возвращает x^2 - 3x + 9 при x <= 3 и 1 / (x^3 + 3) при x > 3
 * на ветке x > 3 знаменатель всегда положителен, деления на ноль нет
 */
double fa(double x) {
	double y;

	if (x <= BRANCH_LIMIT) {
		y = x * x - 3 * x + 9;
	} else {
		y = 1 / (x * x * x + 3);
	}
	return y;
}

/*
 * вычисляет значение функции F2
 * x - аргумент функции
 * возвращает x * exp(sin(x^2))
 */
double fb(double x) {
	double y;

	y = x * exp(sin(x * x));
	return y;
}

/*
 * вычисляет произведение значений функций
 * x - аргумент функций
 * возвращает F1(x) * F2(x)
 */
double calc_product(double x) {
	return fa(x) * fb(x);
}

/*
 * вычисляет разность квадратов значений функций
 * x - аргумент функций
 * возвращает F1(x)^2 - F2(x)^2
 */
double calc_diff_squares(double x) {
	return fa(x) * fa(x) - fb(x) * fb(x);
}

/*
 * вычисляет удвоенную сумму значений функций
 * x - аргумент функций
 * возвращает 2 * (F1(x) + F2(x))
 */
double calc_double_sum(double x) {
	return SUM_FACTOR * (fa(x) + fb(x));
}
