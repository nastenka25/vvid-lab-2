#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <Windows.h>

using namespace std;

int printmenu();//меню
void printarr(int** arr, int rows, int cols);//ввод массива
int** deletearr(int** arr, int rows);//удаление массива
int sampling(int chislo);//отбор данных
void manualinput(int** arr, int rows, int cols);//заполнение массива с клавиатуры
void randominput(int** arr, int rows, int cols);//рандомное заполнение
void summarr(int** arr, int rows, int cols);//сумма элементов выше главное диагонали
void thrinkarr(int** arr, int &rows, int &cols);//сжатие массива
int main()
{
	setlocale(LC_ALL, "Russian");//русский текст
	setlocale(LC_ALL, "rus");
	int cols = 0, rows = 0, chislo = 0, f = 0, summ = 0, m = 0, t = 0, i = 0, j = 0;
	int **arr = NULL;
	bool Exit = false;


	while (!Exit)
	{
		int menu = 0;
		menu = printmenu();
		
		switch (menu)
		{
		case 1://ввод элементов матрицы
		{
			
			deletearr(arr, rows);
			f = 1;
			cout << "Введите количество строк матрицы\n";
			rows = sampling(chislo);
			cout << "Введите количество столбцов матрицы\n";
			cols = sampling(chislo);
			arr = new int*[rows];//масссив указателей (строчки)
			for (int i = 0; i < rows; i++)
			{
				arr[i] = new int[cols];
			}
			int t = 0;
			cout << "Если вы хотите, чтобы массив был заполнен случайными значениями, то нажмите 1.\nЕсли хотите заполнить его самостоятельно, то нажмите 2\n";
			cin >> t;
			while ((t < 1) || (t > 2))
			{
				cout << "Введено некорректное значение!\n";
				cin >> t;
			}
			if (t == 1)
			{
				randominput(arr, rows, cols);
			}
			else
			{
				manualinput(arr, rows, cols);
			}
			break;
		}
		case 2://сумма элементов расположенных выше главной диагонали
		{
			
			if (f == 0)
			{
				cout << "Массив отсутствует! Введите массив!\n";
			}
			else
			{
				summarr(arr, rows, cols);

			}
			break;
		}

		case 3://сжатие массива
		{
			if (f == 0)
			{
				cout << "Массив отсутствует! Введите массив!\n";
			}
			else
			{
			 thrinkarr(arr, rows, cols);
			}
			break;
		}
		case 4://вывод массива на экран
		{
			if (f == 0)
			{
				cout << "Массив отсутствует! Введите массив!\n";
			}
			else
		
			printarr(arr, rows, cols);
			break;
		}
		case 0:
		{
			{
				Exit = true;
				break;
			}
			break;
		}
		default:
		{
			cout << "Такого пункта меню нет. Пожалуйста, попробуйте снова.";
			getchar();
			getchar();
		}
		}
	}

	deletearr(arr, rows);
	return 0;
}
	


	int printmenu()
	{
		
		cout << "Меню программы\n1. Ввод элементов матрицы\n2. Сумма модулей элементов расположенных выше главной диагонали\n3. Обработка матрицы\n4. Вывод матрицы на экран\n0. Выход\n";
		int m;
		cin >> m;
		return m;

	}
	
	void printarr(int **arr, int rows, int cols)
	{
			
			cout << "Полученный массив:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << "\t";

				}
				cout << endl;
			}
	}
	int** deletearr(int** arr, int rows)//удалить массив
		{
			int i;

			if (arr != NULL)
			{
				for (i = 0; i < rows; i++)
				{
					delete[] arr[i];
				}
				delete[] arr;
			}
			return arr;
		}
	int sampling(int chislo)
	{
		cin >> chislo;
		while (chislo <= 0)
		{
			cout << "Введено некорректное значение!\n";
			cin >> chislo;
		}
		return chislo;
	}
		void manualinput(int** arr, int rows, int cols)
		{
			cout << "введите элементы матрицы\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{

					cin >> arr[i][j];//ввод с клавиатуры
				}
			}
			
		}
	void randominput(int** arr, int rows, int cols)
		{
			
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					arr[i][j] = rand();
				}

			}
			
		}
	void summarr(int** arr, int rows, int cols)
		{
			int summ = 0, max = 0;
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					if (j > i)
					{
						max = arr[i][j];
						summ += abs(max);
					}
				}
			}
			cout << "Сумма модулей элементов\n";
			cout << summ << "\n";
		
		}
	void thrinkarr(int **arr, int &rows, int &cols)
	{
		
			int i, j, t = 0, x;
			for (i = 0; i < rows; i++)
			{
				t = 0;
				for (j = 0; j < cols; j++)
				{
					if (arr[i][j] != 0)
					{
						t = 1;
					}
				}
				if (t == 0)
				{
					for (x = i; x < rows - 1; x++)
					{
						for (j = 0; j < cols; j++)
						{
							arr[x][j] = arr[x + 1][j];
						}
					}
					rows--;
					i--;
				}
			}
			for (i = 0; i < cols; i++)
			{
				t = 0;
				for (j = 0; j < rows; j++)
				{
					if (arr[j][i] != 0)
					{
						t = 1;
					}
				}
				if (t == 0)
				{
					for (x = i; x < cols - 1; x++)
					{
						for (j = 0; j < rows; j++)
						{
							arr[j][x] = arr[j][x + 1];
						}
					}
					cols--;
					i--;
				}
			}
	
	
}
			
