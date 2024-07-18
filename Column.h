#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996);
#pragma once
#include <fstream>
#include <string>
#include <cstring>
#include <iostream>
enum TYPE
{
	INTEGER = 1,
	DOUBLE = 2,
	STRING = 3
};


const int MAX = 128;
const int MAXSIZECELLS = 20;
//const int MAXROWCOLUMN = 4;
class Column
{

//protected:
	//TYPE type;
public:
	//Column() = default;
	virtual ~Column() = default;
	virtual Column* clone() const = 0;
	virtual void addElement(const std::string& str) = 0;
	virtual void MoveElement(const std::string& str, int index) = 0;
	virtual void deleteRow(int index) = 0;
	virtual int getSize() const = 0;
	virtual TYPE getType() const = 0;
	virtual std::string getElement(int index) const = 0;
	
	virtual void print(size_t index) const = 0;
	//virtual Column* read(const char* buff)  = 0;
	virtual void write(std::ofstream& file) const = 0;
};

