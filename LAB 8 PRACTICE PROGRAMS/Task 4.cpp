#include <iostream>
using namespace std;

int main(){
	int num,sum = 0,rem = 0;

	cout << "Enter a number: ";
	cin >> num;
	
	cout << "Number is " << num << endl;

	cout << "Digits of number are ";

	while (num != 0){
		rem = num % 10;
		num = num / 10;
		cout << rem << " ";
		sum += rem;
	}

	cout << endl;

	cout << "Digit sum for the number is " << sum << endl;

	system("pause");
	return 0;
}

