#include <iostream>
using namespace std;

int main(){
	float tmarks, omarks;
	float percentage;

	cout << "Enter the Total marks: ";
	cin >> tmarks;

	cout << "Enter the obtained marks: ";
	cin >> omarks;

	percentage = (omarks / tmarks) * 100;

	if (percentage > 50){
		cout << "The percentage of obtain marks is " << percentage << " % so the student is pass."<<endl;
	}
	else{
		cout << "The percentage of obtain marks is " << percentage << " % so the student is fail."<<endl;
	}



	system("pause");
	return 0;
}

