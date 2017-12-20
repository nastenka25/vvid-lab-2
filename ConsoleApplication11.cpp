// ConsoleApplication11.cpp: îïðåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïðèëîæåíèÿ.
//

#include "stdafx.h"
#include <iostream>
#include <clocale>
#include <Windows.h>

using namespace std;

int printmenu();//ìåíþ
void printarr(int** arr, int rows, int cols);//ââîä ìàññèâà
int** deletearr(int** arr, int rows);//óäàëåíèå ìàññèâà
int sampling(int chislo);//îòáîð äàííûõ
void manualinput(int** arr, int rows, int cols);//çàïîëíåíèå ìàññèâà ñ êëàâèàòóðû
void randominput(int** arr, int rows, int cols);//ðàíäîìíîå çàïîëíåíèå
void thrinkarr(int** arr, int &rows, int &cols);//ñæàòèå ìàññèâà
int main()
{
	setlocale(LC_ALL, "Russian");//ðóññêèé òåêñò
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
		case 1://ââîä ýëåìåíòîâ ìàòðèöû
		{
			
			deletearr(arr, rows);
			f = 1;
			cout << "Ââåäèòå êîëè÷åñòâî ñòðîê ìàòðèöû\n";
			rows = sampling(chislo);
			cout << "Ââåäèòå êîëè÷åñòâî ñòîëáöîâ ìàòðèöû\n";
			cols = sampling(chislo);
			arr = new int*[rows];//ìàñññèâ óêàçàòåëåé (ñòðî÷êè)
			for (int i = 0; i < rows; i++)
			{
				arr[i] = new int[cols];
			}
			int t = 0;
			cout << "Åñëè âû õîòèòå, ÷òîáû ìàññèâ áûë çàïîëíåí ñëó÷àéíûìè çíà÷åíèÿìè, òî íàæìèòå 1.\nÅñëè õîòèòå çàïîëíèòü åãî ñàìîñòîÿòåëüíî, òî íàæìèòå 2\n";
			cin >> t;
			while ((t < 1) || (t > 2))
			{
				cout << "Ââåäåíî íåêîððåêòíîå çíà÷åíèå!\n";
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
		case 2://ñóììà ýëåìåíòîâ ðàñïîëîæåííûõ âûøå ãëàâíîé äèàãîíàëè
		{
			
			if (f == 0)
			{
				cout << "Ìàññèâ îòñóòñòâóåò! Ââåäèòå ìàññèâ!\n";
			}
			break;
		}

		case 3://ñæàòèå ìàññèâà
		{
			if (f == 0)
			{
				cout << "Ìàññèâ îòñóòñòâóåò! Ââåäèòå ìàññèâ!\n";
			}
			else
			{
			 thrinkarr(arr, rows, cols);
			}
			break;
		}
		case 4://âûâîä ìàññèâà íà ýêðàí
		{
			if (f == 0)
			{
				cout << "Ìàññèâ îòñóòñòâóåò! Ââåäèòå ìàññèâ!\n";
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
			cout << "Òàêîãî ïóíêòà ìåíþ íåò. Ïîæàëóéñòà, ïîïðîáóéòå ñíîâà.";
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
		
		cout << "Ìåíþ ïðîãðàììû\n1. Ââîä ýëåìåíòîâ ìàòðèöû\n2. Ñóììà ìîäóëåé ýëåìåíòîâ ðàñïîëîæåííûõ âûøå ãëàâíîé äèàãîíàëè\n3. Îáðàáîòêà ìàòðèöû\n4. Âûâîä ìàòðèöû íà ýêðàí\n0. Âûõîä\n";
		int m;
		cin >> m;
		return m;

	}
	
	void printarr(int **arr, int rows, int cols)
	{
			
			cout << "Ïîëó÷åííûé ìàññèâ:\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{
					cout << arr[i][j] << "\t";

				}
				cout << endl;
			}
	}
	int** deletearr(int** arr, int rows)//óäàëèòü ìàññèâ
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
			cout << "Ââåäåíî íåêîððåêòíîå çíà÷åíèå!\n";
			cin >> chislo;
		}
		return chislo;
	}
		void manualinput(int** arr, int rows, int cols)
		{
			cout << "ââåäèòå ýëåìåíòû ìàòðèöû\n";
			for (int i = 0; i < rows; i++)
			{
				for (int j = 0; j < cols; j++)
				{

					cin >> arr[i][j];//ââîä ñ êëàâèàòóðû
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
			
