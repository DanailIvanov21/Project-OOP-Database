#define _CRT_SECURE_NO_WARNING
#include "Factory.h"
#include "fstream"
#include <cstring>
#pragma warning(dasable: 4996);
Column* Factory::createColumnsFromFile(const char* buff)
{
    char buff2[MAX];
	char buff4[MAX] = "NULL";
    char symbol;
    size_t count = 0;
	size_t sizeBuff = strlen(buff) + 1;
	if (buff[0] == '1')
	{
		Integer integer;
		for (size_t i = 2; i < sizeBuff; i++)
		{
			symbol = buff[i];
			if (symbol == ',')
			{
				
					buff2[count] = '\0';
					integer.addElement(buff2);
			
				for (int k = 0; buff2[k] != '\0'; k++)
				{
					buff2[k] = '\0';
				}
				count = 0;
			}
			else if (symbol == '\0')
			{
	
				
					buff2[count] = '\0';
					integer.addElement(buff2);
				
				
				for (int r = 0;buff2[r] != '\0'; r++)
				{
					buff2[r] = '\0';
				}
				count = 0;
				return integer.clone();
			}
			else {
				buff2[count++] = symbol;
			}
		}
	}
	else if (buff[0] == '2')
	{
		DoubleNumbers dbl;
		for (size_t i = 2; i < sizeBuff; i++)
		{
			symbol = buff[i];
			if (symbol == ',')
			{
			
				
				
					buff2[count] = '\0';
					dbl.addElement(buff2);
			
				
				for (int k = 0;buff2[k] != '\0'; k++)
				{
					buff2[k] = '\0';
				}
				count = 0;
			}
			else if (symbol == '\0')
			{
			
				
					buff2[count] = '\0';
					dbl.addElement(buff2);
				
			
				for (int r = 0;buff2[r] != '\0'; r++)
				{
					buff2[r] = '\0';
				}
				count = 0;

				return dbl.clone();
				break;
			}
			else {
				buff2[count++] = symbol;
			}
		}
	}
	else  if (buff[0] == '3')
	{
		String str;
		for (size_t i = 2; i < sizeBuff; i++)
		{
			symbol = buff[i];
			if (symbol == ',')
			{
				buff2[count] = '\0';
				str.addElement(buff2);
				for (int k = 0;  buff2[k] != '\0'; k++)
				{
					buff2[k] = '\0';
				}
				count = 0;
			}
			else if (symbol == '\0')
			{
				buff2[count] = '\0';
				str.addElement(buff2);
				
				for (int r = 0; buff2[r] != '\0'; r++)
				{
					buff2[r] = '\0';
				}
				count = 0;

				return str.clone();
				break;
			}
			else {
				buff2[count++] = symbol;
			}
		}
	}
	else {
	/*
		std::cout << "Nevaliden obekt shte se chete" << std::endl;
		throw "Nevaliden obekt za chetene!";
		*/
		return nullptr;
	}

}

   


Column* Factory::createColumns(const Column& column)
{
    
    return column.clone();
}
