#include <iostream>

using namespace std;

<<<<<<< HEAD
int main() {
	int prompt_number = 0;
	int positive_number = 0;
	int counter = 0;

	cout << "Please enter the number which will start a cycle: ";
	while (counter < 5) {
		cin >> prompt_number;
		
		if (prompt_number >= 0) {
			positive_number += prompt_number;
			++counter;
		}
	}

	cout << "Out: " << positive_number;

	return 0;
=======
const unsigned int MAX_COUNT_OF_POSITIVES = 5;

int main() {
    unsigned int countOfPositives = 0, sumOfPositives = 0;

    while (countOfPositives < MAX_COUNT_OF_POSITIVES) {
        int num = 0;
        cin >> num;

        if (num > 0) { 
            ++countOfPositives; 
            sumOfPositives += num;
        }
    }

    cout << "The sum is: " << sumOfPositives << endl;

    return 0;
>>>>>>> d9ac78b35c03d404cd5c1b8683aa291082fec931
}