# include "TXLib.h"
# include <stdlib.h>

# include "LFioArraySDK\LFioArrayLib.h"

void swapBubble (int data[], int beginIndex, int size);
void PrintGraphArray (int data[], int size, int index);


//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    const int n = 8;
    int data [n] = {};

    $y; printf("\n----- Задача сортировка пузырьком -----\n");

    FillRandomArrayTest (data, n, 50);
    PrintArray  (data, n, "Исходный массив", n);

    txSleep(1000);

    for (int i = 0; i < n - 1; i++)
        {
        assert (i >= 0 && i < n - 1);

        swapBubble(data, i, n);

        PrintArrayColorEnd (data, n, n - i - 1, n);
        }

    PrintArray  (data, n, "Отсортированный массив", n);

    return 0;
    }

//-----------------------------------------------------------------------------
void swapBubble (int data[], int beginIndex, int size)
    {
    for (int j = 0; j < size - beginIndex - 1; j++)
        {
        assert (j     >= 0 && j     < size - beginIndex - 1);
        assert (j + 1 >= 0 && j + 1 < size - beginIndex);

        if (data[j] > data [j + 1])
            {
            int temp = data [j];
            data[j] = data[j + 1];
            data[j + 1] = temp;
            }
        }
    }



//-----------------------------------------------------------------------------
void PrintGraphArray (int data[], int size, int index)
    {
    txSetFillColor (TX_BLACK);
    txClear();

    double widthRec  = (1200 - 100) / size;
    //double heightRec = 500 / data[NumMaxArray(data, 0, size)];

    GraphicArray (data, size, index, TX_YELLOW, TX_GREEN, widthRec);

    txSleep (1000);
    }
