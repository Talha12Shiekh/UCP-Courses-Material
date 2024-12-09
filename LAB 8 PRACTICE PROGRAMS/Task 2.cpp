#include <iostream>
using namespace std;

int main(){
	int num,esum = 0,osum = 0;

	cout << "Enter a number: ";
	cin >> num;

	cout << "Even Numbers are: ";

	for (int i = 0; i <= num; i += 2){
		cout << i << " ";
		esum += i;
	}

	cout << endl;

	cout << "Sum of even number : " << esum << endl;

	cout << "Odd Numbers are: ";

	for (int i = 1; i <= num; i += 2){
		cout << i << " ";
		osum += i;
	}

	cout << endl;

	cout << "Sum of odd number : " << osum << endl;

	if (esum > osum){
		cout << "The Even sum is greater than Odd Sum" << endl;
	}
	else {
		cout << "The Odd sum is greater than Even Sum" << endl;
	}





	system("pause");
	return 0;
}

