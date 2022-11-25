#ifndef CONTROLCOORD_H_INCLUDED
#define CONTROLCOORD_H_INCLUDED
#include<windows.h>
#include<stdlib.h>
#include<conio.h>
class Controlcoord
{
    public:
    void setxy(int x, int y)
{
  static HANDLE h = NULL;
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };
  SetConsoleCursorPosition(h,c);
}


};

#endif // CONTROLCOORD_H_INCLUDED
