# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

#include "SortArraySDK\SortArrayLib.h"

void Interface ();
void Button      (int x, int y, const char num[], const char text[]);
void ButtonCheck (int x, int y, const char num[], const char text[]);

void SortFileChange  (const char namefile[], int data[], int size, int sortType);
void SortGraphChange (const char namefile[]);

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

            SortGraphChange ("SortArraySDK\\files\\swap.txt");
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

            SortFileChange  ("SortArraySDK\\files\\bubble.txt", data, k, 2 );

            SortGraphChange ("SortArraySDK\\files\\bubble.txt");

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

            ramka("Cортировка вставками");

            FillRandomArrayTest (data, k, 50);

            SortFileChange  ("SortArraySDK\\files\\insert.txt", data, k, 3 );

            SortGraphChange ("SortArraySDK\\files\\insert.txt");

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
            Interface();
            }

        Sleep (10);
        }

    return 0;
    }



//-----------------------------------------------------------------------------
void SortGraphChange (const char namefile[])
    {
    int x = 300; int y = 700;

    int yCount_2;
    int yCountSwap_2;
    int x2;

    int yCount_1 = y;
    int yCountSwap_1 = y;
    int x1 = x + 10;

    std::fstream f;
    f.open(namefile);

    if (f)
        {
        while (!f.eof())
            {
            f >> x2 >> yCount_2 >> yCountSwap_2;

            txSetColor(TX_WHITE, 2);
            txLine (x + x2*15, y + 5, x + x2*15, y - 5);

            txSelectFont ("Arial", 25);
            txDrawText   (x + x2*15 - 7, 710, x + x2*15 + 7, 740, "n");

            txSetColor(RGB(146, 208,  80), 3);
            txLine (x1, yCount_1,     x + x2*15, y - yCount_2/3);

            txSetColor(RGB(255, 102, 255), 3);
            txLine (x1, yCountSwap_1, x + x2*15, y - yCountSwap_2/3);

            x1  = x + x2*15;
            yCount_1 = y - yCount_2/3;

            //x1  = x + x2*15;
            yCountSwap_1 = y - yCountSwap_2/3;

            }
         }


    f.close();
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
        FillRandomArrayTest (data, size, 50);


        /*
        switch (sortType)
            {
            case 1:
              SortSwap   (data, n, &countSwap, &count);
              break;
            case 2:
              SortBubble (data, n, &countSwap, &count);
              break;
            case 3:
              SortInsert (data, n, &countSwap, &count);
              break;
            }
         */

        if (sortType == 1)   SortSwap   (data, n, &countSwap, &count);
        else if (sortType == 2)   SortBubble (data, n, &countSwap, &count);
        else if (sortType == 3)   SortInsert (data, n, &countSwap, &count);


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
    txRectangle (250, 760, 1450, 100);

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
    txDrawText   (290, 710, 305, 730, "0");

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
    txSetColor (RGB(146, 208,  80));
    txDrawText (250, 141,  850, 171, "-  количество сравнений");
    txSetColor (RGB(255, 102, 255));
    txDrawText (850, 141, 1450, 171, "-  количество перестановок");
    }
