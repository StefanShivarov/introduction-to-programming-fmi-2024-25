# Символни низове в C++

Символните низове са поредици от символи, които се използват за работа с текст в програми. В C++ те могат да бъдат представени по два основни начина:

- `char[]`
- [`std::string`](https://cplusplus.com/reference/string/string/)

### Символни низове като масиви от символи

Символните масиви се дефинират като масиви от тип `char`, завършващи със специален символ `\0` - **терминираща нула**. Този символ бележи края на низа.

```cpp
#include <iostream>
using namespace std;

int main() {
    char name[] = "Stefan"; // Символен масив
    char name2[] = {'S', 't', 'e', 'f', 'a', 'n', '\0'}; // еквивалентно
    cout << name << endl; // Stefan

    // Достъп до символи по индекс
    int index = 0;
    while(name[index] != '\0') {
        cout << name[index] << " "; // S t e f a n
        index++;
    }
}
```

Размерът на масива трябва да е достатъчен, за да побере всички символи + `\0` !

```c++
    char word[] = { 'H', 'e', 'l', 'l', 'o', '\0' };
    char word[6] = { 'H', 'e', 'l', 'l', 'o' }; //обикновен масив от символи
    char word[5] = { 'H', 'e', 'l', 'l', 'o' }; //обикновен масив от символи
    char word[100] = "Hello";
    char word[5] = "Hello"; //невалидно, понеже " "включват в себе си '\0‘
    char word[6] = "Hello";
```
---
### Tерминираща нула - `\0`

Първият символ в ASCII таблицата, с код 0 – т.е **char(0)**.
Брои се като елемент и **влияе** на размера на масив.
Използва се като **прекъсвач (терминатор)** от много функции за символни низове, за да се определя края на низа.

```c++
    //Може да се сложи в средата на масив от символи
    char a []= {'H', 'e', 'l', 'l','\0', 'o'}; //символният низ е “Hell”
```

## Как изглежда в паметта

```c++
    char str[] = {'t', 'e', 's', 't', '\0'};
    char str2[] = "test"; //equivalent to str
    char str3[7] = "test";
```

![enter image description here](https://i.ibb.co/ZmRwt6R/Untitled-Diagram-drawio-5.png)

---
### Четене на символни низове от конзолата

1. **Използване на `cin`**:
Операторът `>>` чете символен низ до първия срещнат празен символ (разстояние, табулация, нов ред).

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        char name[50];
        cin >> name; // Чете до първия интервал
        cout << name << endl;

        return 0;
    }
    ```
    Ако въведете текст с интервали, ще се прочете само първата дума.

2. **Използване на `cin.getline`**
Функцията `cin.getline` позволява четене на цели редове, включително интервали, докато не се срещне символ за нов ред (`\n`) или определен максимален брой символи.

    ```cpp
    #include <iostream>
    using namespace std;

    int main() {
        char fullName[100];
        cin.getline(fullName, 100); // Чете до 99 символа или нов ред
        cout << fullName << endl;

        return 0;
    }
    ```

**Смесване на `cin` и `cin.getline`**

Когато използвате cin за четене преди `cin.getline`, може да възникне проблем: cin оставя символа за нов ред (`\n`) в буфера. Това води до незабавно прекратяване на следващото извикване на `cin.getline`.

*Решение*: **Използване на `cin.ignore`**
Функцията `cin.ignore` премахва нежелания символ от входния буфер.

```cpp
#include <iostream>
using namespace std;

int main() {
    char firstName[50], fullName[100];

    cout << "Enter first name:" << endl;
    cin >> firstName;

    // Изчистване на буфера
    cin.ignore();

    cout << "Enter full name:" << endl;
    cin.getline(fullName, 100);

    cout << "First name: " << firstName << endl;
    cout << "Full name: " << fullName << endl;

    return 0;
}
```

---

### Често използвани функции от `<cstring>`:

`strlen` – намира дължината на низа (без терминатора \0).

`strcpy` – копира един символен низ в друг.

`strcmp` – сравнява два символни низа.

`strcat` – добавя един символен низ към друг.
```cpp
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str1[50] = "Hello";
    char str2[50] = "World";

    // Дължина на низ
    cout << strlen(str1) << endl; // 5

    // Конкатенация
    strcat(str1, " "); // "Hello "
    strcat(str1, str2); // "Hello World"
    cout << str1 << endl; 

    // Сравнение
    if (strcmp(str1, str2) == 0)
        cout << "equal" << endl;
    else
        cout << "not equal" << endl;

    char str3[50];

    strcpy(str2, str3);
    cout << str3 << endl; // World

    return 0;
}
```

**Често срещани грешки:**

- Липса на терминатор `\0`: Ако терминаторът липсва, операциите със символния низ може да доведат до неочаквани резултати.
- Препълване на буфера: Уверете се, че размерът на масива е достатъчен за всички символи + терминатора.
- Прескачане на `getline` след `cin`
- Използване на неинициализирани символни масиви