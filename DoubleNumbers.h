#pragma once
#include "Column.h"
#include <vector>
class DoubleNumbers :public Column
{
private:
	std::vector<double> doubles;
	std::vector<int> sizeNumberDouble;
	//unsigned sizeDouble = 0;
	//unsigned maxDoubleSize = 0;
public:
	Column* clone() const override;
	//void addDoubles(double number);
	//unsigned getSizeDouble() const;
	void addElement(const std::string& str) override;
	void MoveElement(const std::string& str, int index) override;
	void deleteRow(int index) override;
	int getSize() const override;
	std::string getElement(int index) const override;
protected:

	void print(size_t index) const override;
	//Column* read(const char* buff) override;
	void write(std::ofstream& file) const override;
	TYPE getType() const override;
};



