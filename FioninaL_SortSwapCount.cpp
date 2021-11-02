# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

# include "LFioArraySDK\LFioArrayLib.h"

void PrintGraphArray (int data[], int size, int index);
void SortSwap (int data[], int size, int* countSwap, int* count);

//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    const int n = 10;
    int data [n] = {};

    int countSwap = 0;
    int count = 0;

    $y; printf("\n----- Задача сортировка обменом -----\n");

    FillRandomArrayTest (data, n, 50);
    PrintArray  (data, n, "Исходный массив", n);

    SortSwap (data, n, &countSwap, &count);

    std::ofstream f;
    f.open("swap.txt");

    f << count << ";" << countSwap << "\n";
    f.close();

    PrintArray  (data, n, "Отсортированный массив", n);
    printf("обменов %d      сравнений   % d", countSwap, count);

    return 0;
    }


//-----------------------------------------------------------------------------
void SortSwap (int data[], int size, int* countSwap, int* count)
    {
     for (int j = 0; j < size; j++)
        {
        int numMin = j;
        int minElem = data[numMin];

        for (int i = j; i < size; i++)
            {
            assert (i >= j && i < size);

            if (data[i] < minElem)
                {
                //printf("*");
                minElem = data[i];
                numMin = i;

                *count += 1;
                //printf(".");
                }
            else
                {
                //printf("*");
                *count += 1;
                }

            }
        *countSwap += 1;
        data[numMin] = data [j];
        data[j] = minElem;

        }
    }
//-----------------------------------------------------------------------------
void PrintGraphArray (int data[], int size, int index)
    {
    txSetFillColor (TX_BLACK);
    txClear();

    double widthRec  = (1500 - 100) / size;
    //double heightRec = 500 / data[NumMaxArray(data, 0, size)];

    GraphicArray (data, size, index, TX_YELLOW, TX_GREEN, widthRec);

    txSleep (1000);
    }
