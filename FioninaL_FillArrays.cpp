# include "TXLib.h"

void PrintArray (int data[], int size, const char title[]);
void FillArray  (int data[], int size, int start, int step);

void FillArray_exam1_way1 (int data[], int size);
void FillArray_exam1_way2 (int data[], int size);
void FillArray_exam1_way3 (int data[], int size);
void FillArray_exam1_way4 (int data[], int size);

void FillArray_exam2_way1 (int data[], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int data [20] = {};

    $y; printf("\n 1 задача ------------------------------------\n");
    FillArray_exam1_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 1");

    FillArray_exam1_way2 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 2");

    FillArray_exam1_way3 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 3");

    FillArray_exam1_way4 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 4");

    $y; printf("\n 2 задача ------------------------------------\n");

    FillArray_exam2_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 2 способ 1");
    return 0;
    }

//-----------------------------------------------------------------------------
void FillArray_exam2_way1 (int data[], int size)
    {
    for (int i = 0; i < size; i = i + 6)
        {
        data[i] = 1;
        }
    for (int i = 1; i < size; i = i + 6)
        {
        data[i] = 2;
        }
    for (int i = 2; i < size; i = i + 6)
        {
        data[i] = 3;
        }
    for (int i = 3; i < size; i = i + 6)
        {
        data[i] = 3;
        }
    for (int i = 4; i < size; i = i + 6)
        {
        data[i] = 2;
        }
    for (int i = 5; i < size; i = i + 6)
        {
        data[i] = 1;
        }
    }

//-----------------------------------------------------------------------------
void FillArray_exam1_way4 (int data[], int size)
    {
    data[0] = 1;

    for (int i = 1; i < size; i++)
        {
        if (i % 3 == 0)
            {
            assert (i     >= 0 && i     < size);
            assert (i - 3 >= 0 && i - 3 < size);

            data[i] = data[i - 3];
            }
        if (i % 3 == 1)
            {
            assert (i     >= 0 && i     < size);
            assert (i - 1 >= 0 && i - 1 < size);

            data[i] = data[i - 1] + 1;
            }
        if (i % 3 == 2)
            {
            assert (i     >= 0 && i     < size);
            assert (i - 1 >= 0 && i - 1 < size);
            assert (i - 2 >= 0 && i - 2 < size);

            data[i] = data[i - 1] + data[i - 2];
            }
        }
    }
//-----------------------------------------------------------------------------
void FillArray_exam1_way3 (int data[], int size)
    {
    for (int  i = 1; i < size; i++)
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


