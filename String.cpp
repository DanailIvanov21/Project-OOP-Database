#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996);
#include "String.h"

Column* String::clone() const
{
    return new String(*this);
}

/*void String::addStr(const char* str)
{
    string.push_back(str);
    sizeString++;
}
*/
/*
unsigned String::getSizeString() const
{
    return sizeString;
}
*/
void String::addElement(const std::string& str)
{
    int number = str.size();
    if (str == "")
    {
        number = 4;
    }
    sizeNumberString.push_back(number);
    if (str == "")
    {

        string.push_back("NULL");
        //sizeString++;
    }
    else {
        string.push_back(str);
        //sizeString++;
    }
}

void String::MoveElement(const std::string& str, int index)
{
    int number = str.size();
    if (str == "")
    {
        number = 4;
    }
    sizeNumberString[index] = number;
    if (str == "")
    {

        string[index] = "NULL";
        
    }
    else {
        string[index] = str;
       
    }
}

void String::deleteRow(int index)
{
    std::vector<std::string>::iterator num;
    num = string.begin()+index;
    string.erase(num);
    std::vector<int>::iterator tmp;
    tmp = sizeNumberString.begin()+index;
    sizeNumberString.erase(tmp);
   // sizeString--;
}

int String::getSize() const
{
    return string.size();
    
}

std::string String::getElement(int index) const
{
    return string[index];
}

void String::print(size_t index) const
{

         std::cout << string[index];
            
            for (int j = 0; j < MAXSIZECELLS - sizeNumberString[index]; j++)
            {
                std::cout << " ";
            }
            std::cout << '|';
       
    


}
/*
Column* String::read(const char* buff)
{
    return nullptr;
}
*/
void String::write(std::ofstream& file) const
{
    file << 3 << ' ';
    for (size_t i = 0; i < string.size(); i++)
    {
        if (string.size() - 1 == i)
        {
            file << string[i] << std::endl;
        }
        else {
            file << string[i] << ',';
        }
    }
}

TYPE String::getType() const
{
    std::cout << "Type of this column is String!" << std::endl;
    return TYPE::STRING;
}
