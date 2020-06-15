#include <iostream>
#include<string>
#include<iomanip>
using namespace std;



class Array {

private:
	float number;

public:
	Array();
	Array(float n);
	void setNumber(float n);
	float getNumber();
};

Array::Array(){};

Array::Array(float n) : number(n) {};

void Array::setNumber(float n){
	number = n;
}

float Array::getNumber(){
	return number;
}

float getValueByindex(Array *arr, int i);
float getHighest(Array *arr, int sz);
float getLowest(Array *arr, int sz);
float getSum(Array *arr, int sz);
float getAvg(Array *arr, int sz);

int main() {

	int size;
	int index;
	float value;
	string option;
	Array *my_array;

	cout << "Please determine the size of your array: ";
	cin >> size;

	my_array = new Array[size];

	for (int i = 0; i < size; i++){
		cout << "Enter number #" << (i + 1) << " : ";
		cin >> value;

		cout << "What position of the array should this number be stored? ";
		cin >> index;

		my_array[index].setNumber(value);

	}

	cout << "\n\nBelow are the values stored in your array :\n";
	for (int i = 0; i < size; i++){
		cout << my_array[i].getNumber() << "\t";
	}

	do{

	cout << "\n\nPlease select one of the following options for data retrieval from the array:\n";
	cout << "-------------------------------------------------------------------------------\n";
	cout << "1: Retrieve a specific value from an array (based a specific position in the array)\n";
	cout << "2: Retrieve the highest value in the array\n";
	cout << "3: Retrieve the lowest value in the array\n";
	cout << "4: Retrieve the sum of all values in the array\n";
	cout << "5: Retrieve the average of all values in the array\n\n";


	
		cout << "ENTER AN OPTION: ";
		cin >> option;

		if (option == "1"){
			cout << "Enter the position of the array to retrieve this number: ";
			cin >> index;
			cout << "The number retrieved is: " << getValueByindex(my_array, index) << endl;
		}
		else if (option == "2"){
			cout << "The highest number in array is: " << getHighest(my_array, size) << endl;

		}
		else if (option == "3"){
			cout << "The lowest number in array is: " << getLowest(my_array, size) << endl;

		}
		else if (option == "4"){
			cout << "The sum of the values in the array is: " << getSum(my_array, size) << endl;

		}
		else if (option == "5"){
			cout << fixed << showpoint << setprecision(1);
			cout << "The average of the values in the array is: " << getAvg(my_array, size) << endl;
		}

	} while (option == "1" || option == "2" || option == "3" || option == "4" || option == "5");

	cout << "\nBye ! \n";
	system("pause");
	return 0;
}


float getValueByindex(Array *arr, int i){
	return arr[i].getNumber();
}

float getHighest(Array *arr, int sz){
	float largtest = arr[0].getNumber() ;

	for (int i = 1; i < sz; i++)
	{
		if (largtest < arr[i].getNumber())
			largtest = arr[i].getNumber();
	}

	return largtest;
}

float getLowest(Array *arr, int sz){
	float lowest = arr[0].getNumber();

	for (int i = 1; i < sz; i++)
	{
		if (lowest > arr[i].getNumber())
			lowest = arr[i].getNumber();
	}

	return lowest;
}

float getSum(Array *arr, int sz){
	float sum= 0.0 ;

	for (int i = 0; i < sz; i++)
	{
		sum += arr[i].getNumber();
	}

	return sum;
}

float getAvg(Array *arr, int sz){
	float average;

	float sum = 0.0;

	for (int i = 0; i < sz; i++)
	{
		sum += arr[i].getNumber();
	}
	
	average = sum / sz;

	return average;
}
