# include <iostream>
# include "TXLib.h"

void PrintArray (int data[], int size, const char title[], int column);
void FillRandomArray (int data[], int size, int range);

void SwapElemArray (int data [], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int n = 20;
    int data [20] = {};

    $y; printf("\n\n----- Задача обмена значениями соседних элементов массива -----\n");

    FillRandomArray (data, n, 50);
    PrintArray (data, n, "Исходный массив", 8);

    SwapElemArray (data, n);
    PrintArray (data, n, "Полученный массив", 8);

    return 0;
    }

//-----------------------------------------------------------------------------
void SwapElemArray (int data [], int size)
    {
    int temp = 0;

    for (int i = 0; i < size - 1; i += 2)
        {
        assert (i     >= 0 && i     < size);
        assert (i + 1 >= 0 && i + 1 < size);

        temp = data [i];
        data[i] = data[i + 1];
        data[i + 1] = temp;
        }
    }

//-----------------------------------------------------------------------------
void FillRandomArray (int data[], int size, int range)
    {
    for (int i = 0; i < size; i++)
        {
        data[i] = rand() % range - range / 2;
        }
    }

//-----------------------------------------------------------------------------
void PrintArray (int data[], int size, const char title[], int column)
    {
    $y; printf ("\n%s:", title);

    for (int i = 0; i < size; i++)
        {
        if (i % column == 0) printf ("\n");

        $c; printf ("[%2d] = ",i);
        $g; printf ("%3d",data[i]);
        if (i != size - 1)
            {
            $c; printf (", ");
            }
        }

    printf ("\n");
    }

