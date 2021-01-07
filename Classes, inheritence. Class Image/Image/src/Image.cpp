#include <iostream>
#include <cstring>
#include "Image.hpp"
#include <stdlib.h>

using namespace std;

Image::Image(int width, int height):
width(width),height(height), ptr(allock(width,height)) // lista inicjalizujaca
{
    fillInImage(0);
}

Image::~Image()
{
    deallock();
}

byte** Image::allock(int width, int height) const
{
    byte** newptr;
    try
    {
        newptr = new byte*[height];
        for (int i=0;i<height;i++)
            {
            newptr[i] = new byte[width];
            memset(newptr[i],0xFF,width); //wypelnianie funckji
            }
    }
    catch(const bad_alloc &)
    {
      cout << "alloc error - Blad alokacji pamieci" << endl;
      abort();
    }
    return newptr;
}

void Image::fillInImage(byte value)
{
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            ptr[i][j] = value;
}

byte Image::readPixel(int x, int y) const
{
    return ptr[x][y];

}

void Image::writePixel(int x, int y, byte value)
{
    ptr[x][y] = value;
}

int Image::getWidth() const
{
    return width;
}

int Image::getHeight() const
{
    return height;
}

void Image::flipVertical()                  // odwracanie wertykalne
{
    byte tmp;
    for (int i=0; i<height; i++)
    for (int j=0; j<(width/2); j++)
    {
        tmp = ptr[i][j];
        ptr[i][j] = ptr[i][(width-1)-j];
        ptr[i][(width-1)-j] = tmp;
    }
}

void Image::flipHorizontal()                // odwracanie horyzontalne
{
    byte tmp;
    for (int j=0; j<width; j++)
    for (int i=0; i<(height/2); i++)
    {
        tmp = ptr[i][j];
        ptr[i][j] = ptr[(height-1)-i][j];
        ptr[(height-1)-i][j] = tmp;
    }
}

void Image::deallock() const
{
    for(int i=0;i<height;i++) delete [] ptr[i];
    delete[] ptr;
}

Image::Image(Image& right):width(right.width),height(right.height), ptr(allock(right.width,right.height))
{
    for (int i=0; i<height;i++)
    {
        for (int j=0;j<width;j++) ptr[i][j]=right.ptr[i][j];
    }
}

ostream &operator<<(ostream &os, const Image &right)                // przeciazanie operatora <<
{
    for (int i=0;i<right.height;i++)
    {
        os << "\n";
        for (int j=0;j<right.width; j++)
        {
            os << " " << (int)right.ptr[i][j];
        }
    }
    return os;
}

Image & Image::operator=(const Image &right)                        // przeciazenie operatora =
{
        if (this != &right)
        {
            deallock();
            height=right.height;
            width=right.width;
            ptr=allock(right.width,right.height);
                for(int i=0;i<height;i++)
                    {
                    for(int j=0;j<width;j++) ptr[i][j]=right.ptr[i][j];
                    }
        }
    return *this;
}

byte& Image::operator()(int x, int y)                                 // przeciazenie operatora ()
{
    return ptr[x][y];
}

byte Image::operator()(int x, int y) const
{
    return ptr[x][y];
}



