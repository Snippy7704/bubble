#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
void bubbleSort(int array[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (array[j] > array[j + 1]) {
				int tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
			}
		}
	}
}
void writeArray(int array[], int size, const char* filename) {
	FILE* file = fopen(filename, "w");
	if (file != NULL) {
		for (int i = 0; i < size; i++) {
			fprintf(file, "%d ", array[i]);
		}
		fclose(file);
	}
	else {
		printf("Ошибка открытия файла");
	}
}
void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}
int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));
	int size;
	int* array;
	char ch;
	do {
		system("cls");
		printf("\n");
		printf(" |><><><><><><>МЕНЮ<><><><><><><|\n");
		printf(" 1. Сортировка случайных чисел\n");
		printf(" 2. Сортировка введенных чисел\n");
		printf(" 3. Информация\n");
		printf(" (ESC). Выход\n");
		ch = _getch();
		switch (ch) {
		case '1':
			system("cls");
			printf("Введите количество элементов: ");
			scanf("%d", &size);
			array = (int*)malloc(size * sizeof(int));
			//Заполнение рандомными числами
			for (int i = 0; i < size; i++) {
				array[i] = rand() % 100; // от 0 до 100
			}
			//Запись исходного массива в файл
			writeArray(array, size, "original_numbers.txt");
			printf("\nИсходный массив: ");
			printArray(array, size);
			//Сортировочка с учетом времени работы
			time_t start = clock();
			bubbleSort(array, size);
			time_t stop = clock();
			double time = stop / 10000.0;
			//Запись отсортированного массива в файл
			writeArray(array, size, "sorted_numbers.txt");
			printf("\nОтсортированный массив: ");
			printArray(array, size);
			printf("\n\nВремя выполнения сортировки: %lf микросекунд", time);
			printf("\n\n\n");
			system("pause");
			free(array);
			break;
		case '2':
			system("cls");
			printf("Введите количество элементов: ");
			scanf("%d", &size);
			array = (int*)malloc(size * sizeof(int));
			//Заполнение массива вручную
			printf("Введите %d чисел: ", size);
			for (int i = 0; i < size; i++) {
				scanf("%i", &array[i]);
			}
			//Запись исходного массива в файл
			writeArray(array, size, "original_numbers.txt");
			printf("\nИсходный массив: ");
			printArray(array, size);
			//Сортировочка с учетом времени работы
			time_t start1 = clock();
			bubbleSort(array, size);
			time_t stop1 = clock();
			double time1 = stop1 / 10000.0;
			//Запись отсортированного массива в файл
			writeArray(array, size, "sorted_numbers.txt");
			printf("\nОтсортированный массив: ");
			printArray(array, size);
			printf("\n\nВремя выполнения сортировки: %lf микросекунд", time1);
			printf("\n\n\n");
			system("pause");
			free(array);
			break;
		case '3':
			system("cls");
			printf("*----------------------------------Информация-----------------------------------*\n");
			printf("Выполнили студенты группы 23ВВВ3\n");
			printf("Артем Володин (Реализация алгоритма сортировки,создание общего Git-репозитория)\n");
			printf("Батайкин Дмитрий (Тестирование программы, разработка меню)\n");
			printf("Гуреев Денис (Работа с файлами, финальная компоновка программы)\n");
			printf("\n");
			system("pause");
			break;
		}
	} while (ch != 27);
	return 0;
}