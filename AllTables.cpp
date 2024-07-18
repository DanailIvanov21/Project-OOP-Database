#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable: 4996);
#include "AllTables.h"
#include <exception>
#include <fstream>
void AllTables::addTable(const  Table& table)
{
    tables.push_back(table);
    //sizeTables++;
}

unsigned AllTables::getSizeTable() const
{
   
    return tables.size();
}

void AllTables::save() const
{
    
    for (size_t i = 0; i < tables.size(); i++)
    {
        std::ofstream file(tables[i].getFileName());
        tables[i].writeTable(file);
    }
    std::ofstream fileAll("AllTables.txt");
    if (!fileAll.is_open())
    {
        std::cout << "Ne zarejda faila" << std::endl;
    }
    else {
        for (size_t j = 0; j < tables.size(); j++)
        {
            fileAll << tables[j].getName() << ',';
            fileAll << tables[j].getFileName() << std::endl;
        }
        fileAll.close();
    }
}

void AllTables::open(std::ifstream& file)
{
   // AllTables allTable;
    if (!file.is_open())
    {
        throw "Greshka s otvarqneto na faila!";
    }
    char buff[MAX];

    char buff2[MAX] = "";
    char symbol;
    std::string name;
    std::string fileName;
    size_t sizeBuff = 0;
    size_t count = 0;
    //unsigned int currentPos =  file.tellg();
    while (!file.eof())
    {

        file.getline(buff, MAX);
        if (strcmp(buff, "") == 0)
        {
            break;
        }
        sizeBuff = strlen(buff) + 1;
        for (size_t i = 0; i < sizeBuff; i++)
        {
            symbol = buff[i];
            if (symbol == ',')
            {
                buff2[count] = '\0';
                name = buff2;
                for (int k = 0; buff2[k] != '\0'; k++)
                {
                    buff2[k] = '\0';
                }
                count = 0;
            }
            else if(symbol == '\0')
            {
                buff2[count] = '\0';
                fileName = buff2;
                for (int l = 0; l < buff[l] != '\0'; l++)
                {
                    buff[l] = '\0';
                }
                for (int r = 0; buff2[r] != '\0'; r++)
                {
                    buff2[r] = '\0';
                }
                count = 0;
                Table table(name, fileName);
                table.readTable(fileName);
                addTable(table);
            }
            else {
                buff2[count++] = symbol;
            }
        }
    }
    file.close();

}

void AllTables::allTablesPrint() const
{
    for (size_t i = 0; i < tables.size(); i++)
    {
       
        std::cout << "Print Table" << std::endl;
        tables[i].printTable();
        std::cout << std::endl;
    }
}

void AllTables::saveAs(std::ofstream& file) const
{
    for (size_t i = 0; i < tables.size(); i++)
    {
        std::ofstream file1(tables[i].getFileName());
        tables[i].writeTable(file1);
    }
    
    
   
        for (size_t j = 0; j < tables.size(); j++)
        {
            file << tables[j].getName() << ',';
            file << tables[j].getFileName() << std::endl;
        }
        file.close();
   
}

void AllTables::import(const char* str)
{
    std::ifstream nameFile(str);
   if (!nameFile.is_open())
    {
        std::cout << "Greshka pri otvarqneto!" << std::endl;
        throw "Greshka!";
    }
    
    
    char buff[MAX];

    std::string name;
    std::string fileName;
   
        nameFile.getline(buff, MAX);
        nameFile.close();
        std::string tmp = buff;
        for (size_t i = 0; i < tables.size(); i++)
        {
            if (tmp == tables[i].getName())
            {
                throw "Ima takava tablica sus sushtoto ime";
            }
            
        }
        std::cout << "nqma tablica s tova ime i shte q dobavim" << std::endl;
        name = tmp;
        //char buff2[MAX] = nameFile;
        fileName = str;
        Table table(name, fileName);
        table.helpImport(fileName);
        addTable(table);
        std::ofstream fileAll("AllTables.txt");
    if (!fileAll.is_open())
    {
        std::cout << "Ne zarejda faila" << std::endl;
    }
    else {
        for (size_t j = 0; j < tables.size(); j++)
        {
            fileAll << tables[j].getName() << ',';
            fileAll << tables[j].getFileName() << std::endl;
        }
        fileAll.close();
    }
   
}

void AllTables::showTables() const
{
    std::cout << "Name of tables!" << std::endl;
    for (int i = 0; i < tables.size(); i++)
    {

        std::cout << tables[i].getName() << std::endl;
    }
}

void AllTables::describe(const std::string& name) const
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            tables[i].helpDecribe();


            flag = true;
            break;
        }
        
    }
    if (!flag)
    {
        std::cout << "Ne namerih takava tablica" << std::endl;
    }
}

void AllTables::print(const std::string& name, int count) const
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            tables[i].helpPrint(count);


            flag = true;
            break;
        }

    }
    if (!flag)
    {
        std::cout << "Ne namerih takava tablica" << std::endl;
    }
}

void AllTables::export1(const std::string& name, const std::string& fileName) const
{
    for (size_t i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {

            std::ofstream file(fileName);
            tables[i].writeTable(file);
            break;
        }
    }
   

}

void AllTables::select(int number, const std::string& value, const std::string& name) const
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            flag = true;
            tables[i].selectHelp(number, value);
            
        }

    }
    if (flag == false)
    {
        std::cout << "Ne namerihme takava tablicata s name" << std::endl;
    }
}

void AllTables::select_onto(const std::string& resultTable, const int arr[],int arrSize, int number, const std::string& value, const std::string& name)
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            flag = true;
            char fileName[MAX];
            std::cin >> fileName;

            Table resultTable(resultTable, fileName);
            tables[i].select_ontoHelp(resultTable,arr, arrSize, number, value);
            addTable(resultTable);
            save();
          // tables[i].select_ontoHelp(resultTable,arr,arrSize,number, value);

        }

    }
    if (flag == false)
    {
        std::cout << "Ne namerihme takava tablicata s name" << std::endl;
    }
}

void AllTables::addColumn(const std::string& name, int columnType)
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            tables[i].addNewColumn(columnType);


            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        std::cout << "Ne namerihme takava tablicata s name" << std::endl;
    }
}

void AllTables::insert(const std::string& name, const char arr[], int sizeArr)
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            tables[i].helpInsert(arr, sizeArr);


            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        std::cout << "Ne namerihme takava tablicata s name" << std::endl;
    }
}

void AllTables::deleteRow(const std::string& name, int number, const std::string& value)
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            tables[i].helpDeleteRow(number, value);


            flag = true;
            break;
        }
    }
    if (flag == false)
    {
        std::cout << "Ne namerihme takava tablicata s name" << std::endl;
    }
}

void AllTables::update(const std::string& name, int searchColumn, const std::string& value, int targetColumn, const std::string& targetValue)
{
    bool flag = false;
    for (int i = 0; i < tables.size(); i++)
    {
        if (name == tables[i].getName())
        {
            flag = true;
            tables[i].helpUpdate(searchColumn, value, targetColumn, targetValue);

        }

    }
    if (flag == false)
    {
        std::cout << "Ne namerihme takava tablicata s name" << std::endl;
    }
}




