#pragma once
#include <vector>
#include "Table.h"
#include <iostream>
#include <string>
class AllTables
{

private:
	std::vector<Table> tables;
	//unsigned sizeTables = 0;
public:
	void addTable(const Table& table);
	unsigned getSizeTable() const;
	void save() const;
	void open(std::ifstream& file);
	void allTablesPrint() const;
	void saveAs(std::ofstream& file) const;
	void import(const char* str);
	void showTables()  const;

	void describe(const std::string& name) const;
	void print(const std::string& name, int count) const;
	void export1(const std::string& name, const std::string& fileName) const;
	void select(int number, const std::string& value, const std::string& name) const;
	void select_onto(const std::string& resultTable, const int arr[],int arrSize, int number, const std::string& value, const std::string& name);
	void addColumn(const std::string& name, int columnType);
	void insert(const std::string& name, const char arr[], int sizeArr);
	void deleteRow(const std::string& name, int number, const std::string& value);
	void update(const std::string& name, int searchColumn, const std::string& value, int targetColumn, const std::string& targetValue);
};

