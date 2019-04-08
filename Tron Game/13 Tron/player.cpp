#include "player.hpp"

player::player(Color c)
{
    x=rand() % W;
    y=rand() % H;
    color=c;
    dir=rand() % 4;
}

void player::tick()
{
  if (dir==0) y+=1;
  if (dir==1) x-=1;
  if (dir==2) x+=1;
  if (dir==3) y-=1;
	if (x>=W) x=0;  if (x<0) x=W-1;
  if (y>=H) y=0;  if (y<0) y=H-1;
  if (jump == true) jumpCount++;
  if (jumpCount == 10) jump = false;
}

Vector3f player::getColor()
    {return Vector3f(color.r,color.g,color.b);}

void player::setBoardWidth(int width)
{
    W = width;
}

void player::setBoardHeight(int height)
{
    H = height;
}

int player::getX()
{
  return x;
}

int player::getY()
{
  return y;
}

int player::getDir()
{
  return dir;
}

Color player::getPColor()
{
  return color;
}

bool player::getJump()
{
  return jump;
}

void player::setX(int a)
{
  x = a;
}

void player::setY(int a)
{
  y = a;
}

void player::setDir(int a)
{
  dir = a;
}

void player::PJump()
{
  jump = true;
  jumpCount = 0;
}