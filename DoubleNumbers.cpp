#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996);
#include "DoubleNumbers.h"

Column* DoubleNumbers::clone() const
{
    return new DoubleNumbers(*this);
}

/*void DoubleNumbers::addDoubles(double number)
{
    doubles.push_back(number);
    sizeDouble++;
}
*/
/*
unsigned DoubleNumbers::getSizeDouble() const
{
    return sizeDouble;
}
*/
void DoubleNumbers::addElement(const std::string& str)
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
    sizeNumberDouble.push_back(number);
    if (str == "" || str == "NULL")
    {
        std::string tmp = "0";
        doubles.push_back(std::stod(tmp));
        //sizeDouble++;
    }
    else {
        doubles.push_back(std::stod(str));
        //sizeDouble++;
    }
}

void DoubleNumbers::MoveElement(const std::string& str, int index)
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
    sizeNumberDouble[index] = number;
    if (str == "" || str == "NULL")
    {
        std::string tmp = "0";
        doubles[index] = std::stod(tmp);
       
    }
    else {
        doubles[index] = std::stod(str);
        
    }
}

void DoubleNumbers::deleteRow(int index)
{
    std::vector<double>::iterator num;
    num = doubles.begin()+index;
    doubles.erase(num);
    std::vector<int>::iterator tmp;
    tmp = sizeNumberDouble.begin()+index;
    sizeNumberDouble.erase(tmp);
    //sizeDouble--;
}

int DoubleNumbers::getSize() const
{
    return doubles.size();
}

std::string DoubleNumbers::getElement(int index) const
{
    std::string tmp = std::to_string(doubles[index]);
    return tmp;
   
}

void DoubleNumbers::print(size_t index) const
{
    
            if (doubles[index] == 0)
            {
                std::cout << "NULL";
            }
            else {
                std::cout << doubles[index];
            }
            for (int j = 0; j < MAXSIZECELLS - sizeNumberDouble[index]; j++)
            {
                std::cout << " ";
            }
            std::cout << '|';
      
    


}
/*
Column* DoubleNumbers::read(const char* buff)
{
   
    return nullptr;
}
*/
void DoubleNumbers::write(std::ofstream& file) const
{
    file << 2 << ' ';
    for (size_t i = 0; i < doubles.size(); i++)
    {
        if (doubles.size() - 1 == i)
        {
            if (doubles[i] == 0)
            {
                file << "NULL" << std::endl;
            }
            else {
                file << doubles[i] << std::endl;
            }
        }
        else {
            if (doubles[i] == 0)
            {
                file << "NULL" << ',';
            }
            else 
            {
                file << doubles[i] << ',';
            }
        }
    }
}

TYPE DoubleNumbers::getType() const
{
    std::cout << "Type of this column is DoubleNumbers!" << std::endl;
    return TYPE::DOUBLE;
}
