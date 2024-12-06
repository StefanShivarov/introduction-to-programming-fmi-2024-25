#include <iostream>
using namespace std;
const int MAX_SIZE = 100;


int ChangeSymbols(char sentence[], char result[], char x, char a, char b) {

	int counter = 0;
	int i = 0;
	while (sentence[i] != '\0')
	{
		if (sentence[i] == x)
		{
			counter++;
			if (counter % 2 == 0)
			{
				result[i] = b;
			}
			else { result[i] = a; }
		}
		else { result[i] = sentence[i]; }
		i++;
	}
	result[i] = '\0';
	cout << result;
	return 0;
}

int main() {
	char sentence[MAX_SIZE], result[MAX_SIZE], x, a, b;
	cin.getline(sentence, MAX_SIZE);
	cin >> x;
	cin >> a;
	cin >> b;
	ChangeSymbols(sentence, result, x, a, b);
	return 0;
}
