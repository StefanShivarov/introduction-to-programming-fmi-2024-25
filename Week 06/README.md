# Матрици (продължение): Диагонали на матрица и спирали

### Диагонали на матрица

![](https://www.opentechguides.com/images/howto/howto_24301.webp)

#### Главен диагонал

Главният диагонал на квадратна матрица се състои от елементите, при които индексите на реда и колоната са равни: А[i][j], i = j.

#### Второстепенен диагонал

Второстепенният диагонал съдържа елементите, при които индексите на реда и колоната са взаимно допълващи до размера на матрицата n: А[i][j], j = n - 1 - i.

**Примерен код за намиране на сумите на двете диагонали**:

```cpp
const int SIZE = 3;

int main() {
    int mainDiagonalSum = 0;
    int secondaryDiagonalSum = 0;
    int matrix[SIZE][SIZE] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    for (int i = 0; i < SIZE; i++) {
        mainDiagonalSum += matrix[i][i];
        secondaryDiagonalSum += matrix[i][SIZE - 1 - i];
    }

    std::cout << "Main diagonal sum: " << mainDiagonalSum << std::endl;
    std::cout << "Secondary diagonal sum: " << secondaryDiagonalSum << std::endl;
}
```

---

### Друго по-интересно диагонално обхождане на матрица:

![](https://media.geeksforgeeks.org/wp-content/uploads/zigzag-1.png)

```cpp
#include <iostream>
using namespace std;

const int ROWS = 5;
const int COLS = 4;

void printMatrixDiagonals(const int matrix[ROWS][COLS]) {
    // Обхождаме диагоналите, които започват от първата колона
    for (int startRow = 0; startRow < ROWS; ++startRow) {
        int row = startRow;
        int col = 0;
        // Преминаваме диагонално нагоре вдясно
        while (row >= 0 && col < COLS) {
            cout << matrix[row][col] << " ";
            row--;
            col++;
        }
        cout << endl;
    }

    // Обхождаме диагоналите, които започват от последния ред (без първата клетка)
    for (int startCol = 1; startCol < COLS; ++startCol) {
        int row = ROWS - 1;
        int col = startCol;
        // Преминаваме диагонално нагоре вдясно
        while (row >= 0 && col < COLS) {
            cout << matrix[row][col] << " ";
            row--;
            col++;
        }
        cout << endl;
    }
}


int main() {
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
        {17, 18, 19, 20}
    };

    printMatrixDiagonals(matrix);

    /*
    1
    5 2
    9 6 3
    13 10 7 4
    17 14 11 8
    18 15 12
    19 16
    20
    */
}

```

---

### Спирално преминаване през матрица

![](https://files.prepinsta.com/2022/05/Spiral-Traversal-of-a-Matrix-in-Python-768x421.webp)

```cpp
#include <iostream>
using namespace std;

const int ROWS = 4;
const int COLS = 4;
const int MAX_SIZE = 50;

void spiralTraversal(const int matrix[ROWS][COLS]) {
    int i, left = 0, right = COLS - 1, top = 0, bottom = ROWS - 1;

    while (left <= right && top <= bottom) {

        /* Print the first row
        from the remaining rows */
        for (i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++;

        /* Print the last column
        from the remaining columns */
        for (i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;

        /* Print the last row from
        the remaining rows */
        if (top <= bottom) {
            for (i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        /* Print the first column from
        the remaining columns */
        if (left <= right) {
            for (i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    int matrix[ROWS][COLS] = {
        { 1, 2, 3, 4 },
        { 5, 6, 7, 8 },
        { 9, 10, 11, 12 },
        { 13, 14, 15, 16 }
    };

    spiralTraversal(matrix); // 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10
}
```
