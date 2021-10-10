# include "TXLib.h"

void PrintArray (int data[], int size, const char title[]);
void FillArray  (int data[], int size, int start, int step);

//-----------------------------------------------------------------------------
int main ()
    {
    int data [20] = {};

    FillArray (data, 20, 0, 10);
    PrintArray (data, 20, "ваш массив:");

    return 0;
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
    $y; printf ("\n%s: \n", title);

    for (int i = 0; i < size; i++)
        {
        if (i % 5 == 0) printf ("\n");

        $c; printf ("[%2d] = ",i);
        $g; printf ("%3d",data[i]);
        $c; printf (", ");
        }

    printf ("\n");
    }


