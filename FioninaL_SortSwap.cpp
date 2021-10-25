# include "TXLib.h"
# include <stdlib.h>

# include "LFioArraySDK\LFioArrayLib.h"

void swapElem (int data[], int beginIndex, int endIndex);
void PrintGraphArray (int data[], int size, int index);


//-----------------------------------------------------------------------------
int main ()
    {
     txCreateWindow (1500, 800);

    const int n = 8;
    int data [n] = {};

    $y; printf("\n----- Задача сортировка обменом -----\n");

    FillRandomArrayTest (data, n, 50);
    PrintArray  (data, n, "Исходный массив", n);

    txSleep(1000);

    for (int i = 0; i < n; i++)
        {
        int indexMin = NumMinArray (data, i, n);

        swapElem(data, i, indexMin);

        PrintGraphArray (data, n, i+1);

        //PrintArrayColor  (data, n, i+1, n);
        }

   // PrintArray  (data, n, "Отсортированный массив", n);

   // GraphicArray (data, n, 2, TX_YELLOW, TX_GREEN);


    return 0;
    }

//-----------------------------------------------------------------------------
void swapElem (int data[], int beginIndex, int endIndex)
    {
    int temp = data [beginIndex];

    data[beginIndex] = data[endIndex];
    data[endIndex] = temp;
    }


//-----------------------------------------------------------------------------
void PrintGraphArray (int data[], int size, int index)
    {
    txSetFillColor (TX_BLACK);
    txClear();

    double widthRec  = (1200 - 100) / size;
    //double heightRec = 500 / data[NumMaxArray(data, 0, size)];
    txSelectFont ("Arial", 30);
    txDrawText   (50, 750, 1200, 790, "0            1           2           3           4           5           6           7 ");

    GraphicArray (data, size, index, TX_YELLOW, TX_GREEN, widthRec);

    txSleep (1000);
    }
