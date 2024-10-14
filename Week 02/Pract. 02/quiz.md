**1.** Какво ще отпечата на екрана следният код?

```c++
#include <iostream>
int main()
{
    int i = 9;
    while (i = 12)
    {
        if (i == 0)
            break;
        if (i == 9)
            continue;
        i--;
        std::cout << i << std::endl;
    }
}
```

**2.** Какво ще отпечата на екрана следният код?

```c++
#include <iostream>
int main()
{
    int a = 10;
    while (a)
    {
        a++;
        std::cout << a--;
        a--;
    }
}
```

**3.** Каквa е разликата между двата фрагмента код?

```c++
#include <iostream>
int main()
{
    int a = 0;
    while (a)
    {
        std::cout << "a";
    }
}
```

```c++
#include <iostream>
int main()
{
    int a = 0;
    do
    {
        std::cout << "a";
    } while(a);
}
```
