#pragma once
#include "Column.h"
#include "Integer.h"
#include "DoubleNumbers.h"
#include <string>
#include "String.h"
#include <vector>
#include <iostream>
class Factory
{
public:

	virtual Column* createColumnsFromFile(const char* buff);
	virtual Column* createColumns(const Column& column);
	
};

