#include <iostream>
#include <fstream>
#include "Column.h"
#include "Integer.h"
#include "DoubleNumbers.h"
#include "String.h"
#include "Table.h"
#include "AllTables.h"
#include <string>
int main()
{
    std::ifstream file("AllTables.txt");
    if (!file.is_open())
    {
        std::cout << "File not open" << std::endl;
        return 0;
    }
    else
    {
        bool flag = true;
        char command[MAX];

        AllTables allTables;

        do {
            std::cout << "Write commands:" << std::endl;
            std::cin >> command;
            if (strcmp(command, "open") == 0)
            {
                allTables.open(file);
            }
            else if (strcmp(command, "save") == 0)
            {
                allTables.save();
            }
            else if (strcmp(command, "saveAs") == 0)
            {
                std::string tmp = "F:\\OOP 2023\\Project Baza danni\\anotherfile.txt";
                std::ofstream fileTableall(tmp);
                if (!fileTableall.is_open())
                {
                    std::cout << "Error opening the file!" << std::endl;
                    return -1;
                }
                allTables.saveAs(fileTableall);

            }
            else if (strcmp(command, "import") == 0)
            {
                allTables.import("newFile.txt");
            }
            else if (strcmp(command, "showtables") == 0)
            {
                allTables.showTables();
            }
            else if (strcmp(command, "describe") == 0)
            {
                allTables.describe("Table2");
                allTables.describe("Table1");
                allTables.describe("Table3");
            }
            else if (strcmp(command, "print") == 0)
            {

                allTables.print("Table2", 1);
                allTables.print("Table1", 2);
                allTables.print("Table3", 1);
            }
            else if (strcmp(command, "export") == 0)
            {
                allTables.export1("Table1", "Table1Next.txt");
                allTables.export1("Table2", "Table2Next.txt");
                allTables.export1("Table3", "Table3Next.txt");
            }
            else if (strcmp(command, "select") == 0)
            {
                allTables.select(2, "8", "Table1");
                allTables.select(1, "uchebnik", "Table2");
                allTables.select(0, "38", "Table3");
            }
            else if (strcmp(command, "select_onto") == 0)
            {
                int arr[2] = { 1,2 };
                int arr2[1] = { 1 };
                allTables.select_onto("result_table", arr, 2, 2, "8", "Table1");
                allTables.select_onto("result_table1", arr, 1, 1, "uchebnik", "Table2");
            }
            else if (strcmp(command, "addcolumn") == 0)
            {
                allTables.addColumn("Table1", 1);
                allTables.save();
                allTables.addColumn("Table2", 2);
                allTables.addColumn("Table3", 3);
                allTables.save();
            }
            else if (strcmp(command, "delete") == 0)
            {
                allTables.deleteRow("Table3", 0, "46");
                allTables.save();
                allTables.deleteRow("Table1", 2, "8");
                allTables.deleteRow("Table2", 1, "uchebnik");
                allTables.save();
            }
            else if (strcmp(command,"update") == 0)
            {
                allTables.update("Table1", 2, "8", 0, "note");
                allTables.save();
            }
            else if (strcmp(command, "insert") == 0)
            
            {
                char arr3[12] = "5,5.20,5.60";
                char arr4[11] = "ste,4.50,6";
                allTables.insert("Table3", arr3, 12);
                allTables.save();
                allTables.insert("Table1", arr4, 11);
                allTables.save();
            }
            else if (strcmp(command, "allTablesPrint") == 0)
            {
                allTables.allTablesPrint();
            }
            else if (strcmp(command, "exit") == 0)
            {

                flag = false;
            }

        } while (flag);

    }

}
  
/*
* 3 uchebnik,NULL,pomagalo
2 2.52,-8.37,123.456
1 8,6,8

* 1 -5,3,8
3 uchebnik,NULL,pomagalo
2 5.56,8.4,4.5

1 38, NULL, 5
2 - 8.6, 1.4, 5.2
2 - 3.5, NULL, 5.6

 */

