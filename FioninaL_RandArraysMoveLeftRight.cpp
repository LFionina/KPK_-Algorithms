# include <iostream>
# include "TXLib.h"

void PrintArray (int data[], int size, const char title[], int column);
void FillRandomArray (int data[], int size, int range);

void MoveLeft  (int data [], int size);
void MoveRightEndToBegin (int data [], int size);
void MoveRightBeginToEnd (int data [], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int n = 5;
    int data [5] = {};

    $y; printf("\n\n----- Задача циклического сдвига элементов массива -----\n");

    FillRandomArray (data, n, 50);
    PrintArray (data, n, "Исходный массив 1", 8);

    MoveLeft (data, n);
    PrintArray (data, n, "Полученный массив сдвигом влево", 8);

    $y; printf("\n------------------------------------------------\n");
    FillRandomArray (data, n, 50);
    PrintArray (data, n, "Исходный массив 2", 8);

    MoveRightEndToBegin (data, n);
    PrintArray (data, n, "Полученный массив сдвигом вправо: обход с конца массива", 8);

    $y; printf("\n------------------------------------------------\n");
    FillRandomArray (data, n, 50);
    PrintArray (data, n, "Исходный массив 3", 8);

    MoveRightBeginToEnd (data, n);
    PrintArray (data, n, "Полученный массив сдвигом вправо: обход с начала массива", 8);

    return 0;
    }

//-----------------------------------------------------------------------------
void MoveLeft (int data [], int size)
    {
    int temp = data[0];

    for (int i = 0; i < size - 1; i++)
        {
        assert (i     >= 0 && i     < size);
        assert (i + 1 >= 0 && i + 1 < size);

        data[i] = data[i + 1];
        }
    data[size - 1] = temp;
    }

//-----------------------------------------------------------------------------
void MoveRightEndToBegin (int data [], int size)
    {
    int temp = data[size - 1];

    for (int i = size - 1; i > 0; i--)
        {
        assert (i     >= 0 && i     < size);
        assert (i - 1 >= 0 && i - 1 < size);

        data[i] = data[i - 1];
        }
    data[0] = temp;
    }

//-----------------------------------------------------------------------------
void MoveRightBeginToEnd (int data [], int size)
    {
    int tempPrev = data[0];
    int tempPos  = data[0];

    for (int i = 0; i < size - 1; i++)
        {
        assert (i     >= 0 && i     < size);
        assert (i + 1 >= 0 && i + 1 < size);

        tempPos = data[i + 1];
        data[i + 1] = tempPrev;
        tempPrev = tempPos;
        }
    data[0] = tempPrev;
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
    $y; printf ("\n%s", title);

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

