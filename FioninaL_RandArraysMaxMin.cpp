# include <iostream>
# include "TXLib.h"

void PrintArray (int data[], int size, const char title[], int column);
void FillRandomArray (int data[], int size, int range);

void NumMaxArray (int data[], int size);
void NumMinArray (int data[], int size);

//-----------------------------------------------------------------------------
int main ()
    {
    int data [20] = {};

    $y; printf("\n\n----- ������ ������ ������ ������������� �������� -----\n");

    FillRandomArray (data, 20, 50);
    PrintArray  (data, 20, "�������� ������", 7);
    NumMaxArray (data, 20);
    NumMinArray (data, 20);

    return 0;
    }

//-----------------------------------------------------------------------------
void NumMinArray (int data[], int size)
    {
    int numMin = 0;
    int minElem = data[0];

    for (int i = 1; i < size; i++)
        {
        if (data[i] < minElem)
            {
            minElem = data[i];
            numMin = i;
            }
        }
    $y; printf("����� ������������  �������� = %2d\n", numMin);
    }

//-----------------------------------------------------------------------------
void NumMaxArray (int data[], int size)
    {
    int numMax = 0;
    int maxElem = data[0];

    for (int i = 1; i < size; i++)
        {
        if (data[i] > maxElem)
            {
            maxElem = data[i];
            numMax = i;
            }
        }
    $y; printf("����� ������������� �������� = %2d\n", numMax);
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

