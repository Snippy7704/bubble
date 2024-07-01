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
		printf("������ �������� �����");
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
		printf(" |><><><><><><>����<><><><><><><|\n");
		printf(" 1. ���������� ��������� �����\n");
		printf(" 2. ���������� ��������� �����\n");
		printf(" 3. ����������\n");
		printf(" (ESC). �����\n");
		ch = _getch();
		switch (ch) {
		case '1':
			system("cls");
			printf("������� ���������� ���������: ");
			scanf("%d", &size);
			array = (int*)malloc(size * sizeof(int));
			//���������� ���������� �������
			for (int i = 0; i < size; i++) {
				array[i] = rand() % 100; // �� 0 �� 100
			}
			//������ ��������� ������� � ����
			writeArray(array, size, "original_numbers.txt");
			printf("\n�������� ������: ");
			printArray(array, size);
			//������������ � ������ ������� ������
			time_t start = clock();
			bubbleSort(array, size);
			time_t stop = clock();
			double time = stop / 10000.0;
			//������ ���������������� ������� � ����
			writeArray(array, size, "sorted_numbers.txt");
			printf("\n��������������� ������: ");
			printArray(array, size);
			printf("\n\n����� ���������� ����������: %lf �����������", time);
			printf("\n\n\n");
			system("pause");
			free(array);
			break;
		case '2':
			system("cls");
			printf("������� ���������� ���������: ");
			scanf("%d", &size);
			array = (int*)malloc(size * sizeof(int));
			//���������� ������� �������
			printf("������� %d �����: ", size);
			for (int i = 0; i < size; i++) {
				scanf("%i", &array[i]);
			}
			//������ ��������� ������� � ����
			writeArray(array, size, "original_numbers.txt");
			printf("\n�������� ������: ");
			printArray(array, size);
			//������������ � ������ ������� ������
			time_t start1 = clock();
			bubbleSort(array, size);
			time_t stop1 = clock();
			double time1 = stop1 / 10000.0;
			//������ ���������������� ������� � ����
			writeArray(array, size, "sorted_numbers.txt");
			printf("\n��������������� ������: ");
			printArray(array, size);
			printf("\n\n����� ���������� ����������: %lf �����������", time1);
			printf("\n\n\n");
			system("pause");
			free(array);
			break;
		case '3':
			system("cls");
			printf("*----------------------------------����������-----------------------------------*\n");
			printf("��������� �������� ������ 23���3\n");
			printf("����� ������� (���������� ��������� ����������,�������� ������ Git-�����������)\n");
			printf("�������� ������� (������������ ���������, ���������� ����)\n");
			printf("������ ����� (������ � �������, ��������� ���������� ���������)\n");
			printf("\n");
			system("pause");
			break;
		}
	} while (ch != 27);
	return 0;
}