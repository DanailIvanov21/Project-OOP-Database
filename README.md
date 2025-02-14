# Project-OOP-Database
В рамките на този проект трябва да се реализира приложение, което поддържа операции с прости бази от данни. 
Базите от данни се състоят от серии от таблици, като всяка таблица е записана в собствен файл. Базата от данни е записана в главен файл (каталог), които съдържа списък от таблиците в базата, като за всяка таблица е зададено име и файл, в който таблицата е записана.
Поддържани типове данни
Всяка “колона” на таблица в базата от данни има тип, като в една таблица може да има едновременно колони от различни типове. Вашето приложение трябва да поддържа следните типове:

Цяло число – поредица от цифри, без никакви други символи между тях. В началото на числото може да има знак '+' или '-'. 
Например: 123; -123; +123.

Дробно число – поредица от цифри, следвана от символ за точка и след нея друга поредица от цифри. В началото на числото може да има знак '+' или '-'. 
Например: 123.456; -123.456; +123.456.

Символен низ (стринг) – поредица от произволни символи, оградени в кавички. Подобно на низовете в C++, ако в даден низ трябва да бъде включен символа за кавичка, 
то той трябва да бъде представен като \". За да бъде включена наклонена черта, тя трябва да бъде представена като \\.
Например: "Hello world!"; "C:\\temp\\"; "\"This is a quotation\"".

Освен конкретна стойност, дадена клетка в даден ред на таблицата може да е “празна”. Такива клетки да се обозначават специално и да е изписват като “NULL”.

След като приложението отвори дадена база, чрез нейния основен файл, то трябва да може да извършва посочените по-долу операции, в допълнение на 
общите операции (close, save, save as, help и exit):

### import <file name>
- Добавя в базата данни нова таблица от файл. Във файла е записана информация за типа на всяка колона. Всяка таблица има име. При опит за добавяне на таблица с име,
- което съвпада с името на някоя вече съществуваща таблица, системата да дава грешка. Добавената таблица се записва в каталога на базата от данни.
### showtables  
- Показва списък с имената на всички таблици.
### describe <name>
- Показва информация за типовете на колоните на дадена таблица.
### print <name>
- Показва всички редове от дадена таблица. Да се реализира диалогов режим, позволяващ съдържанието на таблицата да се преглежда по страници (такива, че се събират на един екран)
- със следните команди: следваща страница, предишна страница, изход.
### export <name> <file name>
- Записва съдържанието на таблица в текстов файл, форматирано по подходящ начин..
### select <column-n> <value> <table name>
- Извежда всички редове от таблицата, които съдържат стойността “value” в клетката с дадения пореден номер. Да се реализира извеждане по страници.
### select_onto <result_table> [<comumn_1>, <column_2>, ...] <column-n> <value> <table name>
- Подобно на select, но резултатът се записва в нова таблица с името result_table, и съдържа само колоните с номера изброени в списъка, ограден от []. В този списък номерата могат да се повтарят и да са в произволен ред. Този ред трябва да се запази в резултатната таблица. 
### addcolumn <table name> <column name> <column type>
- Добавя нова колона (с най-голям номер) в дадена таблица. За всички съществуващи редове от таблицата, стойността на тази колона да е празна.
### update <table name> <search column n> <search value> <target column n> <target value>
- За всички редове в таблицата, чиято колона с пореден номер <search column n> съдържа стойността <search column value> се променят така, че колоната им с пореден номер <target column n> да получи стойност <target value>. Да се поддържа стойност NULL.
### delete <table name> <search column n> <search value> 
- Изтрива всички редове в таблицата, чиято колона <search column n> съдържа стойността <search column value>.
### insert <table name> <column 1> … <column n>
- Вмъква нов ред в таблицата със съответните стойности.

###  Общи команди
Дадените по-долу команди се поддържат в голяма част от проектите. Под всяка от тях е даден пример за нейната работа:
### Open
- Зарежда съдържанието на даден файл. Ако такъв не съществува се създава нов с празно съдържание.
Всички останали команди могат да се изпълняват само ако има успешно зареден файл.
След като файлът бъде отворен и се прочете, той се затваря и приложението вече не трябва да работи с него, освен ако потребителят не поиска да запише обратно направените промени (вижте командата save по-долу), в който случай файлът трябва да се отвори наново. За целта трябва да се избере подходящо представяне на информацията от файла.
Ако при зареждането на данните, приложението открие грешка, то трябва да се изведе подходящо съобщение за грешка и да се прекрати изпълнението.
 > open C:\Temp\figures.svg
Successfully opened figures.svg
### Save
- Записва направените промени обратно в същия файл, от който са били прочетени данните.
 > save
Successfully saved figures.svg
### Save As
- Записва направените промени във файл, като позволява на потребителя да укаже неговия път.
> saveas "C:\Temp\another file.xml"
Successfully saved another file.xml
### Exit
Излиза от програмата




