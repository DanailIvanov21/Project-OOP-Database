#pragma once
#include "Column.h"
#include <string>
#include <vector>
class String :public Column
{
private:
	std::vector<std::string> string;
	std::vector<int> sizeNumberString;
	//unsigned sizeString = 0;
	//unsigned maxSizeString = 0;
public:
	Column* clone() const override;
	//void addStr(const char* str);
	//unsigned getSizeString() const;
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

