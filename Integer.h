#pragma once
#include "Column.h"
#include  <vector>

class Integer :public Column
{
private:
	std::vector<int> integers;
	std::vector<int> sizeNumberInt;//pazi razmer na vseki element vuv vektora
	//unsigned sizeInt = 0;
	//unsigned maxSizeInt = 0;
public:
	Column* clone() const override;
	//void addInteger(int number);
	//unsigned getSizeInt() const;
	void addElement(const std::string& str) override;
	 void MoveElement(const std::string& str, int index) override;
	 void deleteRow(int index) override;
	int getSize() const override;
	 std::string getElement(int index) const override;
protected:
	
	 void print(size_t index) const override;
	// Column* read(const char* buff, Column& cl) override ;
	 void write(std::ofstream& file) const override;
	 TYPE getType() const override;

};

