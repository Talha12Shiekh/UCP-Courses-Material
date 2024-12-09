#include <iostream>
using namespace std;

int main(){
	int num,rem = 0,revnumber = 0,initalnum =  0;

	cout << "Enter a number: ";
	cin >> num;

	initalnum = num;

	while (num != 0){
		rem = num % 10;
		num = num / 10;
		revnumber = (revnumber * 10) + rem;
	}

	if (initalnum == revnumber){
		cout << "This is palindrome number " << endl;
	}
	else {
		cout << "This is Not palindrome number " << endl;
	}


	system("pause");
	return 0;
}

