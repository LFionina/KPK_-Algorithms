# include "TXLib.h"
# include <stdlib.h>


#include <iostream>
#include <fstream>
#include <iomanip>

# include "LFioArraySDK\LFioArrayLib.h"

//-----------------------------------------------------------------------------
int main ()
    {
    txCreateWindow (1500, 800);

    string a;
    int y12;
    int y22;
    int x2;

    int x = 200;
    int y = 700;

    int y11 = y;
    int y21 = y;
    int x1 = x+10;

    txSetColor(TX_WHITE, 2);
    txLine (x     , y,       x + 1000, y);
    txLine (x + 10, y + 10 , x + 10,   y - 600);

    std::fstream f;
    f.open("swap.txt");

    if (f)
        {
        while (!f.eof())
            {
            //чтение очередного значения из потока F в переменную a
            f >> x2 >> y12 >> y22;

            txSetColor(TX_WHITE, 2);
            txLine (x + x2*10, y + 10 , x + x2*10,   y - 10);

            txSetColor(TX_GREEN, 2);
            txLine (x1, y11, x + x2*10, y - y12);
            txSetColor(TX_RED, 2);
            txLine (x1, y21, x + x2*10, y - y22);

            x1  = x + x2*10;
            y11 = y - y12;

            x1  = x + x2*10;
            y21 = y - y22;

            //cout<<y1<<"   "<<y2<<"\n";
            //увеличение количества считанных чисел

            }
         }


    f.close();

    return 0;
    }
