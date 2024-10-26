#include <iostream>

using namespace std;

<<<<<<< HEAD
int main() {
	int prompt_number = 0;
	int negative_number = 0;
	int counter = 0;

	cout << "Please enter the number which will start a cycle: ";
	while (counter < 3) {
		cin >> prompt_number;
		
		if (prompt_number >= 0) {
			negative_number = 0;
			counter = 0;
		}

		if (prompt_number < 0) {
			if (negative_number > prompt_number) {
				negative_number = prompt_number;
			}

			++counter;
		}
	}

	cout << "Out: " << negative_number;

	return 0;
=======
const unsigned int MAX_COUNT_OF_NEGATIVES = 3;

int main() {
    unsigned int countOfNegatives = 0;
    int smallestNum = 0;

    while (countOfNegatives < MAX_COUNT_OF_NEGATIVES) {
        int num = 0;
        cin >> num;

        if (num < 0) {
            ++countOfNegatives;
            if (num < smallestNum) { smallestNum = num; }
        } else {
            countOfNegatives = 0;
            smallestNum = 0;
        }
    }

    cout << "The smallest num is: " << smallestNum << endl;

    return 0;
>>>>>>> d9ac78b35c03d404cd5c1b8683aa291082fec931
}