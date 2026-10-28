/*
 * Автор: <ФИО>, группа <номер>
 * Работа 10. Задание 2.
 * Программа вычисляет sin(x) тремя способами: функцией стандартной
 * библиотеки, суммой N членов ряда Маклорена и суммой ряда
 * с заданной точностью eps. Результаты сравниваются.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_TERMS   1000    /* ограничение числа членов ряда по точности */
#define ANSWER_NO   'n'     /* ответ, завершающий программу */

double sin_n(double x, int n_terms);
double sin_eps(double x, double eps);
int read_double(const char *prompt, double *ptr_value);
void print_result(const char *name, double value, double reference);

int main(void) {
	double x;       /* аргумент в радианах */
	double eps;     /* заданная точность */
	int n_terms;    /* число суммируемых членов ряда */
	char answer;    /* ответ пользователя о продолжении */

	system("chcp 1251 > nul");
	printf("Программа вычисляет sin(x) тремя способами и сравнивает\n");
	printf("результаты: sin() из библиотеки, сумма N членов ряда,\n");
	printf("сумма ряда с заданной точностью.\n");

	do {
		if (!read_double("\nВведите x (в радианах): ", &x)) {
			printf("Ошибка ввода.\n");
			return EXIT_FAILURE;
		}
		printf("Введите число членов ряда N: ");
		if (scanf("%d", &n_terms) != 1 || n_terms < 1) {
			printf("Ошибка: N должно быть целым числом >= 1.\n");
			return EXIT_FAILURE;
		}
		if (!read_double("Введите точность eps (например 0.000001): ", &eps)
				|| eps <= 0) {
			printf("Ошибка: eps должна быть положительной.\n");
			return EXIT_FAILURE;
		}

		printf("\n");
		print_result("sin() из math.h", sin(x), sin(x));
		print_result("сумма N членов ряда", sin_n(x, n_terms), sin(x));
		print_result("ряд с точностью eps", sin_eps(x, eps), sin(x));

		printf("\nПродолжить? (Да - любой символ, нет - %c): ", ANSWER_NO);
		scanf(" %c", &answer);
	} while (answer != ANSWER_NO);

	return EXIT_SUCCESS;
}

/*
 * вычисляет sin(x) как сумму первых n_terms членов ряда Маклорена
 * x - аргумент в радианах
 * n_terms - число суммируемых членов ряда (n_terms >= 1)
 * возвращает приближённое значение sin(x)
 * очередной член получается из предыдущего умножением
 * на -x^2 / ((2k) * (2k + 1))
 */
double sin_n(double x, int n_terms) {
	double term = x;    /* текущий член ряда */
	double sum = x;     /* накопленная сумма */
	int k;              /* номер члена ряда */

	for (k = 1; k < n_terms; k++) {
		term *= -x * x / ((2.0 * k) * (2.0 * k + 1.0));
		sum += term;
	}
	return sum;
}

/*
 * вычисляет sin(x) рядом Маклорена с заданной точностью
 * x - аргумент в радианах
 * eps - точность: суммирование идёт, пока модуль члена ряда >= eps
 * возвращает приближённое значение sin(x)
 * число членов ограничено константой MAX_TERMS
 */
double sin_eps(double x, double eps) {
	double term = x;    /* текущий член ряда */
	double sum = x;     /* накопленная сумма */
	int k = 1;          /* номер члена ряда */

	while (fabs(term) >= eps && k < MAX_TERMS) {
		term *= -x * x / ((2.0 * k) * (2.0 * k + 1.0));
		sum += term;
		k++;
	}
	return sum;
}

/*
 * выводит приглашение и читает вещественное число
 * prompt - текст приглашения
 * ptr_value - указатель на переменную для результата
 * возвращает 1 при успешном вводе и 0 при ошибке
 */
int read_double(const char *prompt, double *ptr_value) {
	printf("%s", prompt);
	return scanf("%lf", ptr_value) == 1;
}

/*
 * выводит значение и абсолютную погрешность относительно эталона
 * name - название способа вычисления
 * value - полученное значение
 * reference - эталонное значение (sin из стандартной библиотеки)
 */
void print_result(const char *name, double value, double reference) {
	printf("%s: %.8f (погрешность %.2e)\n", name, value, fabs(value - reference));
}
