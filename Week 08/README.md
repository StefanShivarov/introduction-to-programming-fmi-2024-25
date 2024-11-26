# Указатели. Aдресна аритметикa.

### Указатели

Указател е променлива, която съхранява адреса в паметта на друга променлива. Вместо да съдържа стойност директно, указателят посочва мястото, където се намира тази стойност.

```cpp
int a = 5;          // Обикновена променлива
int* ptr = &a;        // Указател към променливата 'a'

cout << ptr << endl; // 00000046508FFBA4 (адрес)
cout << *ptr << endl; // 5
```

- `*ptr` - **дереферация**

- Указателите могат да имат неутрална стойност - `nullptr`
- `nullptr` сочи към адрес 0x00000000
- `nullptr` не може да се дереферира!
- Може да съдържа както адреса на някоя променлива, така и нулев адрес (`nullptr`) или някоя непозволена памет (което е източник на грешки).
- Адресът, който съдържа указателят, може да се променя.
- Може да се извършват промени по данните в съответния адрес.

```cpp
int* ptr = nullptr;
cout << ptr << endl; // 0000000000000000
int num = 7;
cout << ptr << endl;
ptr = &num;

cout << ptr << endl; // 000000733EAFF604
cout << *ptr << endl; // 7

(*ptr)++;

cout << num << endl; // 8 (променихме стойноста на променливата num, чрез указателя ptr, сочещ към адреса на num)

int anotherNumber = 24;

ptr = &anotherNumber;

cout << ptr << endl; // 000000733EAFF624
cout << *ptr << endl; // 24

(*ptr)--;

cout << num << endl; // 8
cout << anotherNumber << endl; // 23
```
### Указатели към константи/Константни указатели
Указателите към константа – НЕ може да се променя стойността на променливата, към която сочат.
- `const int*` - указател към константа
- `int const*` - указател към константа

```cpp
const int q = 5;
int const* p = &q;

*p = 7; // Compilation error

const int q2 = 7;

p = &q2; // valid	
```

Константните указатели са като референциите, но са указатели.
Може да се променя стойността на променливата, но НЕ може да се променя да сочи към друга променлива.
- `int* const` – константен указател

```cpp
int q = 5;
int *const p = &q;
*p = 7; // valid

const int q2 = 7;
p = &q2; // Compilation error
```

#### Spiral Rule
Правилото гласи, започнете от името на променливата и се придвижваме по посока на часовниковата стрелка до следващия указател или тип.

![Spiral rule](https://velog.velcdn.com/images/beechwood/post/31ad6ffd-74cd-4bd9-8205-4c3bf7bba574/image.png)


---

### Адресна аритметика

Адресната аритметика позволява манипулация на адреси в указатели.

Чрез операторите +, -, +=, -=, ++, -- можем да местим адреса към който сочи указател с даден брой позиции. Тези позиции се изчисляват спрямо големината в байтове на конкретния тип (`sizeof(int) = 4`, `sizeof(bool) = 1` и т.н.). Тоест ако имаме `int* ptr`, то при `ptr++`, той ще се премести с 4 байта напред, ако е `bool* ptr`, ще се премести с 1 байт.

```cpp
#include <iostream>
using namespace std;

int main() {

    int num = 10;
    int* ptr = &num;

    cout << ptr << endl; // 0000000F56FDFC74
    cout << ++ptr << endl; // 0000000F56FDFC78
    
    ptr += 3;

    cout << ptr << endl; // 0000000F56FDFC84

    ptr -= 4;

    cout << ptr << endl; // 0000000F56FDFC74

    bool* anotherPtr = nullptr;
    cout << anotherPtr << endl; // 0000000000000000
    cout << ++anotherPtr << endl; // 0000000000000001
    cout << ++anotherPtr << endl; // 0000000000000002
    cout << ++anotherPtr << endl; // 0000000000000003
}
```

#### Указатели и масиви

```cpp
int arr[] = {1, 2, 3};
int* ptr = arr; // ptr сочи към първия елемент на масива arr

cout << ptr[0] << endl; // 1
cout << ptr[1] << endl; // 2
```

![enter image description here](https://i.ibb.co/cDcX8st/Untitled-Diagram-drawio-3.png)

```cpp
ptr++; // изместваме адреса към който сочи ptr с 1 място (4 bytes = sizeof(int)), сега ще сочи към втория елемент

cout << ptr[0]; //2;
cout << ptr[1]; //3;
```

![enter image description here](https://i.ibb.co/xLLsVK5/Untitled-Diagram-drawio-4.png)

Тоест `ptr[i]` е еквивалентно на `*(ptr + i)`