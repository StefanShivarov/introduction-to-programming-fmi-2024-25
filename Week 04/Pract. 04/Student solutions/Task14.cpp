#include <iostream>
#include <vector>

using namespace std;

void readMatrix(vector<vector<int> >& matrix);
bool isMultiplicationPossible(const vector<vector<int> >& matrix1, const vector<vector<int> >& matrix2);
vector<vector<int> > multiplyMatrices(const vector<vector<int> >& matrix1, const vector<vector<int> >& matrix2);
void printMatrix(const vector<vector<int> >& matrix);

int main() {
    unsigned int n = 0, m = 0, p = 0, q = 0;

    cout << "N: ";
    cin >> n;
    cout << "M: ";
    cin >> m;

    vector<vector<int> > matrix1(n, vector<int>(m));
    readMatrix(matrix1);

    cout << "P: ";
    cin >> p;
    cout << "Q: ";
    cin >> q;

    vector<vector<int> > matrix2(p, vector<int>(q));
    readMatrix(matrix2);


    if (isMultiplicationPossible(matrix1, matrix2)) {
        printMatrix(multiplyMatrices(matrix1, matrix2));
    } else {
        cout << "Multiplication is not possible" << endl;
    }

    return 0;
}

void readMatrix(vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cin >> matrix[i][j];
        }
    }
}

bool isMultiplicationPossible(const vector<vector<int> >& matrix1, const vector<vector<int> >& matrix2) {
    return matrix1[0].size() == matrix2.size();
}

vector<vector<int> > multiplyMatrices(const vector<vector<int> >& matrix1, const vector<vector<int> >& matrix2) {
    vector<vector<int> > result(matrix1.size(), vector<int>(matrix2[0].size()));

    for (int i = 0; i < matrix1.size(); ++i) {
        for (int j = 0; j < matrix2[0].size(); ++j) {
            for (int k = 0; k < matrix1[0].size(); ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    return result;
}

void printMatrix(const vector<vector<int> >& matrix) {
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}