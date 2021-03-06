# include <iostream>
# include "TXLib.h"

void PrintArray (int data[], int size, const char title[], int column);
void FillRandomArray (int data[], int size, int range);

void SwapPartAttay (int data [], int size, int num);
void MoveRight (int data [], int size);
void MoveLeft (int data [], int size);
void SwapAB (int data [], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int n = 8;
    int data [8] = {};

    $y; printf("\n\n----- ?????? ?????? ??????? ???? ?????? ??????? -----\n");

    FillRandomArray (data, n, 50);
    PrintArray (data, n, "???????? ??????", 8);

    int number;
    $y; printf("\n??????? ????? ????? ?: ");
    cin >> number;

    if (number >= n)
        {
        $r; printf("\n????? ??????????, ?????? ?? ???????? ?? ????? ? ? ?\n");
        }
    else
        {
        if (n - number == number)
            {
            SwapAB (data, n);

            }
        PrintArray (data, n, "?????????? ?????? ????? ?????? ??????? ?????? ? ? ?", 8);
        }

    //SwapPartAttay (data, n, 9);


    return 0;
    }

//-----------------------------------------------------------------------------
void SwapPartAttay (int data [], int size, int num)
    {

    }


//-----------------------------------------------------------------------------
void SwapAB (int data [], int size)
    {
    int temp = data[0];

    for (int i = 0; i < size / 2; i++)
        {
        assert (i     >= 0 && i     < size);
        assert (i + size/2 >= 0 && i + size/2 < size);

        temp = data[i];
        data[i] = data[i + size/2];
        data[i + size/2] = temp;
        }
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
void MoveRight (int data [], int size)
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

