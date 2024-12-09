# Динамична памет. Stack и Heap. Memory leak. Оператори new и delete. 

### Стекова памет (Stack)
- predefined size/предварително определен размер(~2MB)
- паметта се заделя по време на компилация на програмата (**compile time**).
- паметта автоматично се освобождава/трие/маркира като свободна - при излизането от scope-а, в който е дефинирана.

```c++
int value = 5; //allocated on the Stack
```
---
### Динамична памет (Heap)
- паметта се заделя по време на изпълнение на програмата (**runtime**).
- Позволява динамично създаване на масиви и обекти без предварително да е известна големината им.

```c++
int value = 5; //allocated on the Stack
int* p = &value; //pointer allocated on the Stack
int* hValue = new int; //hValue is allocated on the stack
                       //allocates 1 integer on the Heap
*hValue = 5; //dereference to give value to the Heap allocated int

int size;
cin >> size;
int *arr = new int[size]; // dynamically allocated array on the Heap, arr points to the first element of the array, size consecutive ints in heap
```

![Memory](https://dotnettutorials.net/wp-content/uploads/2022/03/word-image-3.png)

### Оператор `new`
- Връща указтел към началото на паметта

```c++
new int[n];  //n НЕ е задължително да е константа!
```

- Заделянето на динамична памет е много "бавна" операция!!
- Динамична памет НЕ се трие автоматично.
---

### Memory leak
![Memory-Leak-example](https://www.baeldung.com/wp-content/uploads/2018/11/Memory-_Leak-_In-_Java.png)

След приключването на функцията ще се изчисти паметта в стека, но НЕ и паметта в heap-а. <br />
За това ние трябва ръчно да я маркираме като свободна. <br />
Ако не я изчистим, то ще се получи отечка на памет (**memory leak**). Това става чрез операторите `delete` и `delete[]`.

```c++
void f()
{
  int x = 40; //allocated on the Stack
  char ch[2] = {'a', 'b'}; //allocated on the Stack
  int* ptr = new int[3]; //allocated on the Heap
}
```
### Оператор `delete`/`delete[]`
- Oсвобождава/маркира като свободна динамична памет! <br />
- Зачиства заделените в heap-а елементи
```c++
void f()
{
  int x = 40;
  char ch[2] = {'a', 'b'};
  int* ptr = new int[3];
  delete[] ptr; //free allocated Heap memory
}
```

*credits: https://github.com/GeorgiTerziev02/Introduction_to_programming_FMI/blob/main/Sem.%2011/README.md*