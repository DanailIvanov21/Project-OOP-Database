#pragma once
#include "Column.h"
#include <string>
#include "Integer.h"
#include "DoubleNumbers.h"
#include "String.h"
#include <vector>
#include <iostream>
#include "Factory.h"
#include <fstream>

class Table
{
private:
	std::string name;
	std::string fileName;

	Column** col;
	unsigned sizeCol = 0;
	unsigned capacity = 8;
	void resize();
	void copy(const Table& other);
	void free();
	Factory factory;

public:
	Table(const std::string& name, const std::string& fileName);
	Table(const Table& other);
	Table& operator=(const Table& other);
	~Table();

	void add(const Column& column);
	void addFromFile(const char* buff);
	void writeTable(std::ofstream& file) const;
	unsigned getSize() const;
	//Column* getColumn(int index) const;
	 Column* operator[](int index);
	 //Column operator[](int index) const;

	//Columns&
	void readTable(std::string& file);
	std::string getName() const;
	std::string getFileName() const;

	void printTable() const;
	void helpImport(std::string& fileName);

	void helpDecribe() const;
	void helpPrint(int count) const;
	void selectHelp(int number, const std::string& value) const;
	void select_ontoHelp(Table& resultTable, const int arr[],int arrSize, int number, const std::string& value);
	void addFromSelect( const std::string& buff);
	void addNewColumn(int columnType);
	void helpDeleteRow(int number, const std::string& value);
	void helpInsert(const char arr[], int sizeArr);
	void helpUpdate(int searchColumn, const std::string& value, int targetColumn, const std::string& targetValue);
	
};

