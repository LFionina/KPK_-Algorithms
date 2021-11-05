# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

# include "SortArraySDK\SortArrayLib.h"

void Interface ();
void Button      (int x, int y, const char num[], const char text[]);
void ButtonCheck (int x, int y, const char num[], const char text[]);

//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    Interface();

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

    return 0;
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
