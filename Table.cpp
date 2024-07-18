#include "Table.h"
#include <cstring>
#include <exception>
#include "Integer.h"
#include "DoubleNumbers.h"
#include "String.h"


void Table::resize()
{
	
		Column** tmp = new(std::nothrow) Column * [capacity *= 2];
		if (tmp == nullptr)
		{
			std::cout << "Allocation returned nullptr" << std::endl;
			free();
			throw "Greshka v zadelqneto na pamet!";

		}
		else {
			for (size_t i = 0; i < sizeCol; i++)
			{
				tmp[i] = col[i];
			}
			delete[] col;
			col = tmp;
		}
}

void Table::copy(const Table& other)
{
/*
	try {
		col = new Column * [other.capacity];
	}
	catch (std::bad_alloc&)
	{
		col = nullptr;
	}
	*/
	col = new(std::nothrow) Column * [other.capacity];
	if (col == nullptr)
	{
		std::cout << "Allocation returned nullptr" << std::endl;
		free();
		throw "Greshka v zadelqneto na pamet!";
		
	}
	else {
		sizeCol = other.sizeCol;
		capacity = other.capacity;

		
		for (size_t i = 0; i < sizeCol; i++)
		{
			col[i] = other.col[i]->clone();
		}
		this->name = other.name;
		this->fileName = other.fileName;
	}
}

void Table::free()
{
	for (size_t i = 0; i < sizeCol; i++)
	{
		delete col[i];
	}
	delete[] col;
}

Table::Table(const std::string& name, const std::string& fileName)
{
	
	col = new(std::nothrow) Column * [capacity];
	this->name = name;
	this->fileName = fileName;
}


void Table::add(const Column& column)
{
	if (sizeCol >= capacity)
	{
		resize();
	}
	col[sizeCol++] = column.clone();
	

}


void Table::writeTable(std::ofstream& file) const
{
	
	 if (!file.is_open())
	{
	    throw "Greshka s otvarqneto na faila!";
    }
	 for (size_t i = 0; i < sizeCol; i++)
	 {
		 
		 col[i]->write(file);
	 }
	 file.close();
}

unsigned Table::getSize() const
{
	return sizeCol;
}


Column* Table::operator[](int index)
{
	return col[index];

}


void Table::readTable(std::string& fileName)
{
	
   
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw "Greshka s otvarqneto na faila!";
	}
	char buff[MAX];
	while (!file.eof())
	{

		file.getline(buff, MAX);
		if (strcmp(buff, "") == 0)
		{
			break;
		}
		addFromFile(buff);
		
		for (int l = 0; buff[l] != '\0'; l++)
		{
			buff[l] = '\0';
		}
	}
	file.close();

}

std::string Table::getName() const
{
	return name;
}

std::string Table::getFileName() const
{
	return fileName;
}

void Table::printTable() const
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while (col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}
	//veche priemame che vsichki koloni na dadena tablica imat ednakuv razmer ili raven broi redove
	unsigned number = 0;
	number = col[0]->getSize(); //vzimame broq redowe na purvata kolona
	for (size_t i = 0; i < number; i++)
	{
		
		for (size_t j = 0; j < sizeCol; j++)
		{

			col[j]->print(i);
		}
		std::cout << std::endl;
	}
}

void Table::helpImport(std::string& fileName)
{
	std::ifstream file(fileName);
	if (!file.is_open())
	{
		throw "Greshka s otvarqneto na faila!";
	}
	char buff[MAX];
	file.getline(buff, MAX);
	while (!file.eof())
	{
		for (int l = 0; buff[l] != '\0'; l++)
		{
			buff[l] = '\0';
		}

		file.getline(buff, MAX);
		if (strcmp(buff, "") == 0)
		{
			break;
		}
		addFromFile(buff);
		
		
	}
	file.close();

}

void Table::helpDecribe() const
{
	for (int i = 0; i < sizeCol; i++)
	{
		col[i]->getType();
	}
}

void Table::helpPrint(int count) const
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while(col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}
	
	//veche priemame che vsichki koloni na dadena tablica imat ednakuv razmer ili raven broi redove
	unsigned number = 0;
	int count1  = 0;
	char command[MAX];
	bool flag = true;
	number = col[0]->getSize(); //vzimame broq redowe na purvata kolona
	//vinagi ima pone edin red kolonata
	if (count < number)
	{


		for (size_t l = 0; l < count; l++)
		{
			for (size_t j = 0; j < sizeCol; j++)
			{

				col[j]->print(count1);

			}
			std::cout << std::endl;
			count1++;
		}
		count1 = count;
		while (flag)
		{
			std::cout << "Write commands" << std::endl;
			std::cin >> command;
			if (strcmp(command, "nextPage") == 0)
			{
				

				
					if ((count + count1) <= number)
					{
						for (size_t l = 0; l < count; l++)
						{
							for (size_t j = 0; j < sizeCol; j++)
							{

								col[j]->print(count1);
							}
							std::cout << std::endl;
							count1++;
						}
					//	count1 = count;
					}
					else {
						std::cout << "Nqma sledvashta stranica!" << std::endl;
					}
				
			}
			else if (strcmp(command, "previousPage") == 0)
			{
				//count1--;
				if (count1 > 0)
				{
					for (size_t l = 0; l < count; l++)
					{
						count1--;
						for (size_t j = 0; j < sizeCol; j++)
						{

							col[j]->print(count1);
						}
						std::cout << std::endl;
						//count1--;
					}
				}
				else {
					std::cout << "Nqma predishna stranica!" << std::endl;
				}
			}
			else if (strcmp(command, "exit") == 0)
			{
				flag = false;
				std::cout << "Krai s printiraneto na stranicite!" << std::endl;
			}
		}
	}
	else {
		std::cout << "Ne moje da se printirat tolkova redove" << std::endl;
		
	}
	
}

void Table::selectHelp(int number, const std::string& value) const
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while (col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}

	std::cout << "Tursim stoinost v tablica" << std::endl;
	bool flag = false;
	int num = col[number]->getSize();// vzimam broq redove na dadenata kolona
	std::vector<int> tmp;
	//std::string buff;
	//std::string buff2;
	for (int i = 0; i < num; i++)
	{
		if (col[number]->getElement(i) == value)
		{
			flag = true;
			
			tmp.push_back(i);			
		}
	}
	if (flag == false)
	{
		std::cout << "Ne namerihme takava stoinost v tablicata" << std::endl;
		
	}
	else 
	{
		//veche priemame che vsichki koloni na dadena tablica imat ednakuv razmer ili raven broi redove
		unsigned number = 0;
		int count1 = 0;
		char command[MAX];
		bool flag = true;
		int sizeTmp = tmp.size();
		number = col[0]->getSize(); //vzimame broq redowe na purvata kolona
		//vinagi ima pone edin red kolonata
		if (tmp.size() < number)
		{
			for (size_t j = 0; j < sizeCol; j++)
			{

				col[j]->print(tmp[count1]);

			}
			std::cout << std::endl;
			count1++;
			while (flag)
			{
				std::cout << "Write commands" << std::endl;
				std::cin >> command;
				if (strcmp(command, "nextPage") == 0)
				{				
					if (sizeTmp >= count1 + 1)
					{

						for (size_t j = 0; j < sizeCol; j++)
						{

							col[j]->print(tmp[count1]);
						}
						std::cout << std::endl;
						count1++;
					}
					else {
						std::cout << "Nqma sledvashta stranica!" << std::endl;
					}
				}
				else if (strcmp(command, "previousPage") == 0)
				{
					count1--;
					if (count1 >= 0)
					{
						for (size_t j = 0; j < sizeCol; j++)
							{

								col[j]->print(tmp[count1]);
							}
							std::cout << std::endl;
					}
					else {
						std::cout << "Nqma predishna stranica!" << std::endl;
					}
				}
				else if (strcmp(command, "exit") == 0)
				{
					flag = false;
					std::cout << "Krai s printiraneto na stranicite!" << std::endl;
				}
			}
		}
		else {
			std::cout << "Ne moje da se printirat tolkova redove" << std::endl;

		}
	}

	
}

void Table::select_ontoHelp(Table& resultTable,const int arr[],int arrSize, int number, const std::string& value)
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while (col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}
	std::cout << "Tursim stoinost v tablica" << std::endl;
	bool flag = false;
	int num = col[number]->getSize();// vzimam broq redove na dadenata kolona
	std::string tmp;
	std::string buff;
	//buff = resultTable;

	for (int i = 0; i < num; i++)
	{
		if (col[number]->getElement(i) == value)
		{
			flag = true;
			
			for (size_t j = 0; j < arrSize; j++)
			{
				for (size_t k = 0; k < sizeCol; k++)
				{
					if (k == arr[j] - 1)
					{
						buff = col[k]->getElement(i);

						tmp = tmp + buff;
						tmp = tmp + ",";
					}
				}
			}
			
		}
	}
	if (flag == false)
	{
		std::cout << "Ne namerihme takava stoinost v tablicata" << std::endl;
		return ;
	}
	

		resultTable.addFromSelect( tmp);
	

}

void Table::addFromSelect(const std::string& buff)
{
	
	int length = buff.length();
	char* array = new char[length + 1];
	strcpy(array, buff.c_str());
	char buff2[MAX];
	strcpy(buff2, array);
	

	delete[] array;

	char buff3[MAX];
	//char buff4[MAX] = "NULL";
	char symbol;
	size_t count = 0;
	size_t sizeBuff = strlen(buff2) + 1;

	Integer integers;
	DoubleNumbers doubles;
	String strings;

	bool isInt = false;
	bool isDbl = false;
	bool isStr = false;
	int countD = 0;// broqch na tochki .

		for (size_t i = 0; i < sizeBuff; i++)
		{
			symbol = buff2[i];
			if (symbol == ',')
			{
				buff3[count] = '\0';
			
				for (int i = 0; i < strlen(buff3); i++)
				{
					if (buff3[i] >= '0' && buff3[i] <= '9' && buff3[i] != '.' && isDbl == false)
					{
						isInt = true;
					}
					else if (((buff3[i] >= '0' && buff3[i] <= '9') || buff3[i] == '.'))
					{
						if (buff3[i] == '.')
						{
							countD++;
						}
						if (countD == 1)
						{
							isInt = false;
							isDbl = true;
						}
						else
						{
							isDbl = false;
						}

					}
					else if ((buff3[i] >= 'a' && buff3[i] <= 'z') || (buff3[i] >= 'A' && buff3[i] <= 'Z'))
					{
						isDbl = false;
						isInt = false;
						isStr = true;
						break;
					}

				}
				countD = 0;
				if (isStr == true)
				{
					strings.addElement(buff3);
				}
				else if (isInt == true)
				{
					integers.addElement(buff3);
				}

				else if (isDbl == true)
				{
					doubles.addElement(buff3);
				}
				isInt = false;
				isDbl = false;
				isStr = false;
				for (int k = 0; buff3[k] != '\0'; k++)
				{
					buff3[k] = '\0';
				}
				count = 0;
			}
			else if (symbol == '\0')
			{

				buff3[count] = '\0';
				for (int i = 0; i < strlen(buff3); i++)
				{
					if (buff3[i] >= '0' && buff3[i] <= '9' && buff3[i] != '.' && isDbl == false)
					{
						isInt = true;
					}
					else if (((buff3[i] >= '0' && buff3[i] <= '9') || buff3[i] == '.'))
					{
						if (buff3[i] == '.')
						{
							countD++;
						}
						if (countD == 1)
						{
							isInt = false;
							isDbl = true;
						}
						else
						{
							isDbl = false;
						}

					}
					else if ((buff3[i] >= 'a' && buff3[i] <= 'z') || (buff3[i] >= 'A' && buff3[i] <= 'Z'))
					{
						isDbl = false;
						isInt = false;
						isStr = true;
						break;
					}

				}
				countD = 0;
				if (isStr == true)
				{
					strings.addElement(buff3);
				}
				else if (isInt == true)
				{
					integers.addElement(buff3);
				}

				else if (isDbl == true)
				{
					doubles.addElement(buff3);
				}
				isInt = false;
				isDbl = false;
				isStr = false;
				for (int r = 0;buff3[r] != '\0'; r++)
				{
					buff3[r] = '\0';
				}
				count = 0;
				//return integer.clone();
			}
			else {
				buff3[count++] = symbol;
			}
			
		}

		if (integers.getSize() != 0)
		{
			Column* ptr = integers.clone();
			if (ptr != nullptr)
			{
				if (sizeCol == capacity)
				{
					resize();
				}
				col[sizeCol++] = ptr;

			}
	    }
		if (doubles.getSize() != 0)
		{
			Column* ptr1 = doubles.clone();
			if (ptr1 != nullptr)
			{
				if (sizeCol == capacity)
				{
					resize();
				}
				col[sizeCol++] = ptr1;

			}
		}
		 if (strings.getSize() != 0)
		{
			Column* ptr2 = strings.clone();
			if (ptr2 != nullptr)
			{
				if (sizeCol == capacity)
				{
					resize();
				}
				col[sizeCol++] = ptr2;

			}
		}
	
}

void Table::addNewColumn(int columnType)
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while(col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}
	//veche priemame che vsichki koloni na dadena tablica imat ednakuv razmer ili raven broi redove
	unsigned number = 0;
	std::string tmp = "";
    number = col[0]->getSize(); //vzimame broq redowe na purvata kolona
	
	if (columnType == 1)
	{
		Integer integers;
		for (int i = 0; i < number; i++)
		{
			integers.addElement(tmp);
		}
		add(integers);
	}
	else if (columnType == 2)
	{
		DoubleNumbers doubles;
		for (int i = 0; i < number; i++)
		{
			doubles.addElement(tmp);
		}
		add(doubles);
	}
	else if (columnType == 3)
	{
		String strings;
		for (int i = 0; i < number; i++)
		{
			strings.addElement(tmp);
		}
		add(strings);
	}

}

void Table::helpDeleteRow(int number, const std::string& value)
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while (col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}
	std::cout << "Tursim stoinost v tablica" << std::endl;
	bool flag = false;
	int num = col[number]->getSize();// vzimam broq redove na dadenata kolona
	for (int i = 0; i < num; i++)
	{
		if (col[number]->getElement(i) == value)
		{
			flag = true;
			for (size_t j = 0; j < sizeCol; j++)
			{
				for (int k = i; k < num; k++)
				{
					if (k + 1 < num)
					{

						col[j]->MoveElement(col[j]->getElement(k + 1), k);
					}

				}
			}
			for (int h = 0; h < sizeCol; h++)
			{
				col[h]->deleteRow(num - 1);
				//col[h] red num - 1 se iztriva
			}
			num--;
			i--;
			
		}
	}
	if (flag == false)
	{
		std::cout << "Ne namerihme takava stoinost v tablicata" << std::endl;
	}
}

void Table::helpInsert(const char arr[], int sizeArr)
{
	char buff[MAX];
	char symbol;
	int count = 0;
	int index = 0;
	std::string tmp;
	for(int i = 0; i < sizeArr; i++)
	{

		symbol = arr[i];
			if (symbol == ',')
			{
				buff[count] = '\0';
				if(index < sizeCol)
				{
					tmp = buff;
					col[index++]->addElement(tmp);
				}
				else {
					break;
				}
				for (int k = 0; buff[k] != '\0'; k++)
				{
					buff[k] = '\0';
				}
				count = 0;
			}
			else if (symbol == '\0')
			{
				buff[count] = '\0';
				if (index < sizeCol)
				{
					tmp = buff;
					col[index++]->addElement(tmp);
				}
				else {
					break;
				}
				for (int l = 0; l < buff[l] != '\0'; l++)
				{
					buff[l] = '\0';
				}
				count = 0;
				
			}
			else {
				buff[count++] = symbol;
			}
		
	}
}

void Table::helpUpdate(int searchColumn, const std::string& value, int targetColumn, const std::string& targetValue)
{
	int maxSize = 0;
	for (int i = 0; i < sizeCol; i++)
	{
		if (col[i]->getSize() > maxSize)
		{
			maxSize = col[i]->getSize();
		}
	}

	for (int j = 0; j < sizeCol; j++)
	{
		while (col[j]->getSize() < maxSize)
		{
			col[j]->addElement("");
		}
	}
	std::cout << "Tursim stoinost v tablica" << std::endl;
	bool flag = false;
	int num = col[searchColumn]->getSize();// vzimam broq redove na dadenata kolona
	for (int i = 0; i < num; i++)
	{
		if (col[searchColumn]->getElement(i) == value)
		{
			flag = true;
			for (size_t j = 0; j < sizeCol; j++)
			{
				if (j == targetColumn)
				{
					col[j]->MoveElement(targetValue, i);
				}

			}
		}
			
	}
	if (flag == false)
	{
		std::cout << "Ne namerihme takava stoinost v tablicata" << std::endl;
	}

}




Table::Table(const Table& other)
{
	copy(other);
}

Table& Table::operator=(const Table& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}

Table::~Table()
{
	free();

}



void Table::addFromFile(const char* buff)
{
	
	Column* ptr = factory.createColumnsFromFile(buff);
	/*if (buff[0] == '1')
	{
		//Integer integers;
		//Column* ptr = read(buff, integers);
		//col[sizeCol++]->read(buff);
	}
	*/
	if (ptr != nullptr)
	{
		if (sizeCol == capacity)
		{
			resize();
		}
		col[sizeCol++] = ptr;
		//col[sizeCol++]->read(buff);

	}
}
