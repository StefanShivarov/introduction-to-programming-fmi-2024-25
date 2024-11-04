# Quiz - подготовка за контролно 1

**1.** Кой от следните оператори не работи само с булева стойност?

- if
- switch
- &&
- ||

---

**2.** Какво ще изведе дадената операция?

```cpp
for (int i = 0; i < 100; i++) {
    for(int i = 0; i < 100; i++) {
        cout << i << " ";
    }
    cout << endl;
}
```

- Компилационна грешка
- Числата от 0 до 99
- Числата от 0 до 99 на нов ред всяко
- Числата от 0 до 99 сто пъти на отделен ред

---

**3.** Какво ще се случи при този код?

```cpp
int main() {
    f();
    return 0;
}

void f() {
    cout << "f()" << endl;
}
```

---

**4.**
Дайте кратко описание за понятието forward declaration

---

**5.**
Дайте кратко описание за понятието function overloading

---

**6.**
Какво прави следната функция?

```cpp
void swap(double a, double b) {
    double c = a;
    a = b;
    b = c;
}
```

---

**7.** Какво ще отпечата следния код?

```cpp
#include <iostream>
bool f() {
    std::cout << 5;
    return false;
}
bool g() {
    std::cout << 123;
    return true;
}
bool h() {
    std::cout << 0;
    return true;
}
void k()
{
    std::cout << (h() || g() || f()) << std::endl;
    std::cout << (g() && f() && h()) << std::endl;
}

int main()
{
    k();
}
```

---

**8.** Какво ще върне следната функция?

```cpp
double f()
{
     double num1 = 4;
     double num2 = 4 / 7;
     return (num2-- = ++num1 + 2);
}
```

---

**9.**
Какво ще изведе този код на конзолата?

```cpp
#include <iostream>

int main() {
    int x = 2;
    switch (x) {
        case 1:
            std::cout << "One" << std::endl;
        case 2:
            std::cout << "Two" << std::endl;
        case 3:
            std::cout << "Three" << std::endl;
        default:
            std::cout << "Default" << std::endl;
    }
    return 0;
}
```

---

**10.**
Какво ще изведе този код на конзолата?

```cpp
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++); {
        std::cout << "i = " << i << std::endl;
    }
    return 0;
}
```

---

**11.**
Какво ще изведе този код на конзолата?

```cpp
#include <iostream>

int main() {
    int i = 10;
    while (i = 5) {
        std::cout << i << " ";
        i--;
    }
    return 0;
}
```

---

**12.**
Напишете еквивалентен код на следния програмен фрагмент, като използвате оператор switch (и не използвате if):

```cpp
int a;
if (a == 1)
    cout << “one”;
if (a != 3)
    cout << “13”;
else if (a > 3)
    cout << “big”;
else
    cout << “error”;
```

---

**13.** Опишете последователно точно какво ще изведе на екрана следният програмен фрагмент. Обосновете писмено подробно отговора си.

```cpp
for (int i = 9; i <= 23; cout << i << endl) i++;
```

---

**14.** Ще се компилира ли следният програмен фрагмент:

```cpp
int num1 = 5;
int num2 = 13;
num2++ = ++num1 + 12;
```

В случай че компилацията е възможна, каква стойност ще има
променливата num2 след изпълнението му?
