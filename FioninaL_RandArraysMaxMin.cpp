# include <iostream>
# include "TXLib.h"

void PrintArray (int data[], int size, const char title[], int column);
void FillRandomArray (int data[], int size, int range);

int NumMaxArray (int data[], int size);
int NumMinArray (int data[], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int data [20] = {};

    $y; printf("\n\n----- ������ ������ ������ ������������� �������� -----\n");

    FillRandomArray (data, 20, 50);
    PrintArray  (data, 20, "�������� ������", 7);

    int numMax = NumMaxArray (data, 20);
    $y; printf("����� ������������� �������� = %2d\n", numMax);

    int numMin = NumMinArray (data, 20);
    $y; printf("����� ������������  �������� = %2d\n", numMin);
    return 0;
    }

//-----------------------------------------------------------------------------
int NumMinArray (int data[], int size)
    {
    int numMin = 0;
    int minElem = data[0];

    for (int i = 1; i < size; i++)
        {
        assert (i >= 1 && i < size);

        if (data[i] < minElem)
            {
            minElem = data[i];
            numMin = i;
            }
        }
    return numMin;
    }

//-----------------------------------------------------------------------------
int NumMaxArray (int data[], int size)
    {
    int numMax = 0;
    int maxElem = data[numMax];

    for (int i = 1; i < size; i++)
        {
        assert (i >= 1 && i < size);

        if (data[i] > maxElem)
            {
            maxElem = data[i];
            numMax = i;
            }
        }
    return numMax;
    }


//{-----------------------------------------------------------------------------
//! ���������� ������� ���������� ������� �� ������������� ������������ 0 ���������,
//! ��������� ������������ ����������
//!
//! @param data[]   data[] - ������ ��� ���������
//! @param size     size   - ���������� ��������� � �������
//! @param range    range  - ������ ���������
//!
//}-----------------------------------------------------------------------------
void FillRandomArray (int data[], int size, int range)
    {
    for (int i = 0; i < size; i++)
        {
        assert (i >= 0 && i < size);

        data[i] = rand() % range - range / 2;
        }
    }

//{-----------------------------------------------------------------------------
//! ����� ��������� ������� �� �������.
//!
//! @param data[]   data[]  - ������ ��� ������
//! @param size     size    - ���������� ��������� � �������
//! @param title[]  title[] - ���������� �����
//! @param column   column  - ���������� ������� ��� ������ ���������
//!
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

