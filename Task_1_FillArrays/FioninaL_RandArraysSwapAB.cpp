# include <iostream>
# include "TXLib.h"

void PrintArray (int data[], int size, const char title[], int column);
void FillRandomArray (int data[], int size, int range);

void SwapPartArrayLeft  (int data [], int size, int num);
void SwapPartArrayRight (int data [], int size, int num);

void MoveLeft  (int data [], int beginNum, int size);
void MoveRight (int data [], int beginNum, int a);

void SwapAB (int data [], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int n = 8;
    int data [8] = {0, 1, 2, 3, 4, 5, 6, 7};

    $y; printf("\n\n----- Задача обмена частей массива -----\n");

    //FillRandomArray (data, n, 50);
    PrintArray (data, n, "Исходный массив", 8);

    int number;
    $y; printf("\nВведите длину части А: ");
    cin >> number;

    if (number >= n)
        {
        $r; printf("\nОбмен невозможен, массив не разделен на части А и В\n");
        }
    else
        {
        if (n - number == number)
            {
            SwapAB (data, n);
            }
        if (number < n - number)
            {
            SwapPartArrayLeft (data, n, number);
            }
        if (number > n - number)
            {
            SwapPartArrayRight (data, n, number);
            }
        }

    PrintArray (data, n, "Полученный массив после обмена местами частей А и В", 8);
    return 0;
    }

//-----------------------------------------------------------------------------
void SwapPartArrayLeft (int data [], int size, int num)
    {
    for (int i = num - 1; i > -1; i--)
        {
        MoveLeft (data, i, size);
        size -= 1;
        }
    }

//-----------------------------------------------------------------------------
void SwapPartArrayRight (int data [], int size, int num)
    {
    int a = 0;
    for (int i = num; i < size; i++)
        {
        MoveRight (data, i, a);
        a += 1;
        }
    }
//-----------------------------------------------------------------------------
void SwapAB (int data [], int size)
    {
    int temp = data[0];

    for (int i = 0; i < size / 2; i++)
        {
        assert (i          >= 0 && i          < size);
        assert (i + size/2 >= 0 && i + size/2 < size);

        temp = data[i];
        data[i] = data[i + size/2];
        data[i + size/2] = temp;
        }
    }
//-----------------------------------------------------------------------------
void MoveLeft (int data [], int beginNum, int size)
    {
    int temp = data[beginNum];

        for (int j = beginNum; j < size - 1; j++)
            {
            assert (j     >= beginNum && j     < size);
            assert (j + 1 >= beginNum && j + 1 < size);

            data[j] = data[j + 1];
            }
    data[size - 1] = temp;
    }

//-----------------------------------------------------------------------------
void MoveRight (int data [], int beginNum, int a)
    {
    int temp = data[beginNum];

    for (int j = beginNum; j > a; j--)
        {
        assert (j     >= a && j     < beginNum + 1);
        assert (j - 1 >= a && j - 1 < beginNum + 1);

        data[j] = data[j - 1];
        }
    data[a] = temp;
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
