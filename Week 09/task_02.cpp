#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

int OnlyLowerCase(char arr[], char result[]) {

	for (int i = 0; i != '\0'; i++)
	{
		if (arr[i] < '97' && arr[i]>'122')
		{
			continue;
		}
		else { result = arr[i]; }
	}
	return result[];
}

int main() {

	char arr[MAX_SIZE], result[MAX_SIZE];
	cin << arr[];

	cout << OnlyLowerCase(arr[], result[]);

}
