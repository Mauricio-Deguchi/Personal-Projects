#include <iostream>
using namespace std;

void main()
{
	// BMI Calculator
	// weight (kg), height (m);
	// Underweight < 18.5
	// Normal weight 18.5-24.9
	// Overweight >25

	float height, weight;
	cout << "Please enter your weight in kg: " << endl;
	cin >> weight;
	cout << "Please enter your height in meters: " << endl;
	cin >> height;
	float bmi;
	bmi = weight / (height * height);
	if (bmi < 18.5)
		cout << "Underweight" << endl;
	else if ((bmi > 18.5) && (bmi < 24.9))
			cout << "Normal weight" << endl;
		else
			cout << "Overweight" << endl;
	cout << "BMI = " << bmi << endl;

	system("pause>0");
}

