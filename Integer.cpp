#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996);
#include "Integer.h"
#include <cstring>

Column* Integer::clone() const
{
    return new Integer(*this);
}

/*void Integer::addInteger(int number)
{
    integers.push_back(number);
    sizeInt++;
}
*/
/*
unsigned Integer::getSizeInt() const
{
    return integers.size();
}
*/
void Integer::addElement(const std::string& str)
{
    int number = str.size();
    if (number == 0)
    {
        number += 4;
    }
    else if (str == "NULL")
    {
        number = 4;
    }
    sizeNumberInt.push_back(number);
    if (str == "" || str == "NULL")
    {
        std::string tmp = "0";
        integers.push_back(std::stoi(tmp));
        
        //sizeInt++;
   }
    else {
        integers.push_back(std::stoi(str));
        //sizeInt++;
    }
}

void Integer::MoveElement(const std::string& str, int index)
{
    int number = str.size();
    if (number == 0)
    {
        number += 4;
    }
    else if (str == "NULL")
    {
        number = 4;
    }
    sizeNumberInt[index] = number;
    if (str == "" || str == "NULL")
    {
        std::string tmp = "0";
        integers[index] = std::stoi(tmp);

        
    }
    else {
        integers[index] = std::stoi(str);
        
    }
}

void Integer::deleteRow(int index)
{
    
    std::vector<int>::iterator num;
    num = integers.begin()+index;
    integers.erase(num);
    std::vector<int>::iterator tmp;
    tmp = sizeNumberInt.begin()+index;
    sizeNumberInt.erase(tmp);
   // sizeInt--;

}

int Integer::getSize() const
{
    return integers.size();
}

std::string Integer::getElement(int index) const
{
    std::string st = std::to_string(integers[index]);
   // char buff[MAX] = std::to_string(integers[index]);
   // char buff[MAX] = "nfk";
   // st = std::strcat(buff, "jgh");
    return st;
    //return integer[index];

}

void Integer::print(size_t index) const
{
        if (integers[index] == 0)
        {
            std::cout << "NULL";
        }
        else {
            std::cout << integers[index];
        }
        for (int j = 0; j < MAXSIZECELLS - sizeNumberInt[index]; j++)
        {
            std::cout << " ";
        }
        std::cout << '|';

 


}
/*
Column* Integer::read(const char* buff, Column& cl)
{
    return nullptr;
}
  */
void Integer::write(std::ofstream& file) const
{
    
    file << 1 << ' ';
    for (size_t i = 0; i < integers.size(); i++)
    {
        
         if (integers.size() - 1 == i)
        {
             if (integers[i] == 0)
             {
                 file << "NULL" << std::endl;
             }
             else {
                 file << integers[i] << std::endl;
             }
        }
        else {
             if (integers[i] == 0)
             {
                 file << "NULL" << ',';
             }
             else {
                 file << integers[i] << ',';
             }
        }
    }
}


TYPE Integer::getType() const
{
    std::cout << "Type of this column is Integer!" << std::endl;
    return TYPE::INTEGER;
   

}
