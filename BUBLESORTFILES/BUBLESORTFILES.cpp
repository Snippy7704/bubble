//

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <time.h>



//запись чисел в файл

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



//вывод массива данных

void printArray(int array[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
}



///////////////////////////////////////////////////////////////////////////////////////////////////////



int main() {
	setlocale(LC_ALL, "");
	srand(time(NULL));

	//FILE* file;
	int size;
	printf("Введите количество элементов: ");
	scanf("%d", &size);

	int* array = (int*)malloc(size * sizeof(int));



	for (int i = 0; i < size; i++) {
		array[i] = rand() % 100; //рандомное число
	}


	//запись исходного массива

	writeArray(array, size, "original_numbers.txt");
	printf("\nИсходный массив: ");
	printArray(array, size);


	//сортировочка с учетом времени работы

	time_t start = clock();
	//bubbleSort(array, size);
	time_t stop = clock();
	double time = (stop - start) / 1000.0;


	//запись отсортированного массива

	writeArray(array, size, "sorted_numbers.txt");
	printf("\nОтсортированный массив: ");
	printArray(array, size);


	printf("\n\nВремя выполнения сортировки: %lf секунд", time);
	printf("\n\n\n");
	system("pause");

	free(array);
	return 0;
}

