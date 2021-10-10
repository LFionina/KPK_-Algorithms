# include "TXLib.h"

void PrintArray (int data[], int size, const char title[]);
void FillArray  (int data[], int size, int start, int step);

void FillArray_exam1_way1 (int data[], int size);
void FillArray_exam1_way2 (int data[], int size);
//-----------------------------------------------------------------------------
int main ()
    {
    int data [20] = {};

    FillArray_exam1_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 1:");

    FillArray_exam1_way2 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 2:");
    return 0;
    }


//-----------------------------------------------------------------------------
void FillArray_exam1_way2 (int data[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        data[i] = (i + 1) % 3;
        if (data[i] == 0)
            {
            data[i] = 3;
            }
        }
}
//-----------------------------------------------------------------------------
void FillArray_exam1_way1 (int data[], int size)
    {
    for (int  i = 0; i < size; i = i + 3)
        {
        data[i] = 1;
        }
    for (int  i = 1; i < size; i = i + 3)
        {
        data[i] = 2;
        }
    for (int  i = 2; i < size; i = i + 3)
        {
        data[i] = 3;
        }
}

//-----------------------------------------------------------------------------
void FillArray (int data[], int size, int start, int step)
    {
    data[0] = start;

    for (int i = 1; i < size; i++)
        {
        assert (i     >= 0 && i     < size);
        assert (i - 1 >= 0 && i - 1 < size);

        data [i] = data[i - 1] + step;
        }
    }

//-----------------------------------------------------------------------------
void PrintArray (int data[], int size, const char title[])
    {
    $y; printf ("\n%s:", title);

    for (int i = 0; i < size; i++)
        {
        if (i % 8 == 0) printf ("\n");

        $c; printf ("[%2d] = ",i);
        $g; printf ("%3d",data[i]);
        $c; printf (", ");
        }

    printf ("\n");
    }


