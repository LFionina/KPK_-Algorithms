# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortArraySDK\SortArrayLib.h"

void Interface ();
void Button      (int x, int y, const char num[], const char text[]);
void ButtonCheck (int x, int y, const char num[], const char text[]);

void SortFileChange (const char namefile[], int data[], int size, int sortType);

void ramka (const char title[]);

//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    Interface();

    const int k = 100;
    int data [k] = {};


    while (!(txGetAsyncKeyState (VK_ESCAPE)))
        {
        if (txGetAsyncKeyState ('1'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            ButtonCheck(20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("Cортировка обменом");

            FillRandomArrayTest (data, k, 50);

            SortFileChange ("SortArraySDK\\files\\swap.txt", data, k, 1 );

            }

        else if (txGetAsyncKeyState ('2'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            ButtonCheck (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("Пузырьковая сортировка");

            FillRandomArrayTest (data, k, 50);

            SortFileChange ("SortArraySDK\\files\\bubble.txt", data, k, 2 );

            }
        else if (txGetAsyncKeyState ('3'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            ButtonCheck (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("... сортировка");

            FillRandomArrayTest (data, k, 50);

            }
        else if (txGetAsyncKeyState ('4'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            ButtonCheck (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("/// сортировка");

            FillRandomArrayTest (data, k, 50);

            }
        else if (txGetAsyncKeyState ('5'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            ButtonCheck (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            ramka("**** сортировка");

            FillRandomArrayTest (data, k, 50);

            }
        else if (txGetAsyncKeyState ('0'))
            {
            txSetColor (RGB (191, 191, 191));
            txSetFillColor (RGB (191, 191, 191));
            txRectangle (0, 100, 250, 800);
            Button (20, 103, "1", "Обмен");
            Button (20, 203, "2", "Пузырек");
            Button (20, 303, "3", "Вставками");
            Button (20, 403, "4", "Быстрая");
            Button (20, 503, "5", "Шелла");
            Button (20, 688, "0", "Очистить");

            txSetColor (RGB (10, 10, 10));
            txSetFillColor (RGB (10, 10, 10));
            txRectangle (400, 101, 1400, 171);
            }

        Sleep (10);
        }

    /*
    string a;
    int y12;
    int y22;
    int x2;

    int x = 300;
    int y = 700;

    int y11 = y;
    int y21 = y;
    int x1 = x+10;

    txSetColor(TX_WHITE, 2);
    txLine (x     , y,       x + 1100, y);
    txLine (x + 10, y + 10 , x + 10,   y - 570);

    std::fstream f;
    f.open("swap.txt");

    if (f)
        {
        while (!f.eof())
            {
            //чтение очередного значения из потока F в переменную a
            f >> x2 >> y12 >> y22;

            txSetColor(TX_WHITE, 2);
            txLine (x + x2*20, y + 10 , x + x2*20,   y - 10);

            txSetColor(TX_GREEN, 2);
            txLine (x1, y11, x + x2*20, y - y12);
            txSetColor(TX_RED, 2);
            txLine (x1, y21, x + x2*20, y - y22);

            x1  = x + x2*20;
            y11 = y - y12;

            x1  = x + x2*20;
            y21 = y - y22;

            //cout<<y1<<"   "<<y2<<"\n";
            //увеличение количества считанных чисел

            }
         }


    f.close();
    */

    return 0;
    }




//-----------------------------------------------------------------------------
void SortFileChange (const char namefile[], int data[], int size, int sortType )
    {
    std::ofstream f;
    f.open(namefile);

    int n = 5;

    for (int z = 0; z < 10; z++)
        {
        int countSwap = 0;
        int count = 0;

        if (sortType == 1)   SortSwap   (data, n, &countSwap, &count);
        if (sortType == 2)   SortBubble (data, n, &countSwap, &count);

        f << n << " " << count << " " << countSwap << "\n";

        n += 5;
        }

    f.close();
    }

//-----------------------------------------------------------------------------
void Interface ()
    {
    txSetFillColor (RGB (191, 191, 191));
    txClear();

    txSetColor (RGB (191, 191, 191));
    txSetFillColor (RGB (10, 10, 10));
    txRectangle (250, 750, 1450, 100);

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial Black", 50, 0, FW_BOLD);
    txDrawText   (100, 10, 1400, 70, "СОРТИРОВКА МАССИВОВ");

    Button (20, 103, "1", "Обмен");
    Button (20, 203, "2", "Пузырек");
    Button (20, 303, "3", "Вставками");
    Button (20, 403, "4", "Быстрая");
    Button (20, 503, "5", "Шелла");

    Button (20, 688, "0", "Очистить");

    txSetColor(TX_WHITE, 2);
    txLine (300, 700, 1400, 700);
    txLine (310, 710,  310, 130);

    txSelectFont ("Arial", 30);
    txDrawText   (290, 700, 305, 730, "0");

    }

//-----------------------------------------------------------------------------
void Button (int x, int y, const char num[], const char text[])
    {
    txSetColor (RGB (151, 151, 151));
    txSetFillColor (RGB (121, 121, 121));
    txRectangle (x + 3, y + 3, x + 210 + 3, y + 60 + 3);

    txSetFillColor (RGB (161, 161, 161));
    txRectangle (x, y, x + 210, y + 60);

    txSetColor (RGB (121, 121, 121), 2);
    txLine (x + 40, y, x + 40 , y + 60);

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial", 30, 0, FW_BOLD);
    txDrawText   (x, y, x + 40, y + 60, num);
    txDrawText   (x + 45, y, x + 210, y + 60, text);

    }

//-----------------------------------------------------------------------------
void ButtonCheck (int x, int y, const char num[], const char text[])
    {
    txSetColor (RGB (151, 151, 151));
    txSetFillColor (RGB (121, 121, 121));
    txRectangle (x - 3, y - 3, x + 210 - 3, y + 60 - 3);

    txSetFillColor (RGB (141, 141, 111));
    txRectangle (x, y, x + 210, y + 60);

    txSetColor (RGB (121, 121, 121), 2);
    txLine (x + 40, y, x + 40 , y + 59);

    txSetColor (RGB (10, 10, 10));
    txSelectFont ("Arial", 30, 0, FW_BOLD);
    txDrawText   (x, y, x + 40, y + 60, num);
    txDrawText   (x + 45, y, x + 210, y + 60, text);

    }

//-----------------------------------------------------------------------------
void ramka (const char title[])
    {
    txSetColor (RGB (10, 10, 10));
    txSetFillColor (RGB (10, 10, 10));
    txRectangle (400, 101, 1400, 171);

    txSelectFont ("Arial", 40);
    txSetColor (TX_YELLOW);
    txDrawText (250, 101, 1450, 141, title);
    txSelectFont ("Arial", 30);
    txSetColor (TX_GREEN);
    txDrawText (250, 141,  850, 171, "-  количество сравнений");
    txSetColor (TX_MAGENTA);
    txDrawText (850, 141, 1450, 171, "-  количество перестановок");
    }
