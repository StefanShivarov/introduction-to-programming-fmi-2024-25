#include <iostream>
using namespace std;

bool getKthBitFromRightToLeft(int num, int k) {
    return num & (1 << k);
}

int toggleKthBit(int n, int k)
{
    return n ^ (1 << k);
}

int main() {
    // ...
}