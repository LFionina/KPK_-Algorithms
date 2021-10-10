# include "TXLib.h"

void PrintArray (int data[], int size, const char title[]);
void FillArray  (int data[], int size, int start, int step);

void FillArray_exam1_way1   (int data[], int size);
void FillArray_exam1_way2   (int data[], int size);
void FillArray_exam1_way2_1 (int data[], int size);
void FillArray_exam1_way3   (int data[], int size);
void FillArray_exam1_way4   (int data[], int size);

void FillArray_exam2_way1 (int data[], int size);
void FillArray_exam2_way2 (int data[], int size);

void FillArray_exam3_way1 (int data[], int size);

void FillArray_exam4_way1 (int data[], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int data [20] = {};

 /*   $y; printf("\n\n 1 задача ------------------------------------\n");
    FillArray_exam1_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 1");

    FillArray_exam1_way2 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 2");

    FillArray_exam1_way2_1 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 2-1");

    FillArray_exam1_way3 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 3");

    FillArray_exam1_way4 (data, 20);
    PrintArray (data, 20, "Массив задание 1 способ 4");

    $y; printf("\n\n 2 задача ------------------------------------\n");

    FillArray_exam2_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 2 способ 1");

    FillArray_exam2_way2 (data, 20);
    PrintArray (data, 20, "Массив задание 2 способ 2");

    $y; printf("\n\n 3 задача ------------------------------------\n");

    FillArray_exam3_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 3 способ 1");

 */
    $m; printf("\n\n 4 задача ------------------------------------\n");

    FillArray_exam4_way1 (data, 20);
    PrintArray (data, 20, "Массив задание 4 способ 1");
    return 0;
    }

//-----------------------------------------------------------------------------
void FillArray_exam4_way1 (int data[], int size)
    {
    for (int i = 0; i < size/2; i = i + 1)
        {
        assert (i            >= 0 && i            < size);
        assert (size - 1 - i >= 0 && size - 1 - i < size);

        data[i] = i*2 + 1;
        data[size - 1 - i] = data[i] + 1;
        }
    if (size % 2 != 0)  data[size / 2 ] = size;

    }



//-----------------------------------------------------------------------------
void FillArray_exam3_way1 (int data[], int size)
    {
    for (int i = 0; i < size; i = i + 4)
        {
        data[i] = 1;
        }
    for (int i = 1; i < size; i = i + 4)
        {
        data[i] = 2;
        }
    for (int i = 2; i < size; i = i + 4)
        {
        data[i] = 3;
        }
    for (int i = 3; i < size; i = i + 4)
        {
        data[i] = 2;
        }
    }

//-----------------------------------------------------------------------------
void FillArray_exam2_way2 (int data[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        int k = i % 6;
        if (k % 5 + 1 <= (5 - k) % 6 + 1)
            {
            data[i] = k % 5 + 1;
            }
        else
            {
            data[i] = (5 - k) % 6 + 1;
            }
        }
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
void FillArray_exam1_way2_1 (int data[], int size)
    {
    for (int i = 0; i < size; i++)
        {
        data[i] = i % 3 + 1;
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
        if (i % 11 == 0) printf ("\n");

        $c; printf ("[%2d] = ",i);
        $g; printf ("%3d",data[i]);
        if (i != size - 1)
            {
            $c; printf (", ");
            }
        }

    printf ("\n");
    }


