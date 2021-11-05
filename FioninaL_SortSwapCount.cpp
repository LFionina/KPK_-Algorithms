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

    const int k = 100;
    int data [k] = {};

    std::ofstream f;
    f.open("swap.txt");

    $y; printf("\n----- Задача сортировка обменом -----\n");

    int n = 5;

    for (int z = 0; z < 5; z++)
        {
        int countSwap = 0;
        int count = 0;

        FillRandomArrayTest (data, n, 50);
        PrintArray  (data, n, "Исходный массив", 10);

        SortSwap (data, n, &countSwap, &count);


        f << n << " " << count << " " << countSwap << "\n";


        PrintArray  (data, n, "Отсортированный массив", 10);
        printf("обменов %d      сравнений   % d", countSwap, count);

        n += 5;
        }

    f.close();

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
