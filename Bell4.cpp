/*Rachel Bell
This program calculates the monthly cell phone bill based on the number of phones lines, data plan
and extra data the user inputs*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int choice, phonelines;
	double extra, phonecharge, taxandcharges, extraCharge, dataCharge, total, extraGB;

	//constant for tax rate
	const double taxrate = .1025;

	//constants for data charges
	const double oneGB = 30.0,
		threeGB = 45.0,
		sixGB = 60.0,
		twelveGB = 80.0,
		eighteenGB = 100.0;

	//constants for menu choices
	const int ONE_GIG = 1,
		THREE_GIG = 2,
		SIX_GIG = 3,
		TWELVE_GIG = 4,
		EIGHTEEN_GIG = 5;

	cout << "--------Cell Phone Bill Calculator--------\n" << endl;

	//get the number of phonelines
	cout << "Enter the number of phone lines : ";
	cin >> phonelines;

	//display menu choices
	cout << "\nAvailable Data Plans\n"
		<< setw(15) << right <<"1. 1GB - $30\n"
		<< setw(15) << right <<"2. 3GB - $45\n"
		<< setw(15) << right <<"3. 6GB - $60\n"
		<< setw(16) << right <<"4. 12GB - $80\n"
		<< setw(17) << right <<"5. 18GB - $100\n"
		<< setw(30) << right <<"Enter your plan < 1 - 5 > : ";
	cin >> choice;

	cout << fixed << showpoint << setprecision(2);
	//dataplan choices
	if (choice == ONE_GIG)
		dataCharge = oneGB;
	else if (choice == THREE_GIG)
		dataCharge = threeGB;
	else if (choice == SIX_GIG)
		dataCharge =sixGB;
	else if (choice == TWELVE_GIG)
		dataCharge = twelveGB;
	else if (choice == EIGHTEEN_GIG)
		dataCharge = eighteenGB;
	else if (choice > 5)
	{
		cout << "Please run the program again and enter a valid choice ( 1 - 5 )";
		cout << endl;
		system("pause");
		exit(-1);
	} 
	
	//Ask user for how many extraGBs
		cout << "\nHow many extra GBs of data did you use : ";
		cin >> extra;
		extraGB = ceil(extra);

		//calc extraGB charge
		if (extraGB == 1)
			extraCharge = 15;
		else if (extraGB > 1)
			extraCharge = 15 + (10 * (extraGB - 1));
		else
			extraCharge = 0;
		
		//calculations that will display
	phonecharge = phonelines * 20;
	taxandcharges = (phonecharge + dataCharge + extraCharge) * taxrate;
	total = phonecharge + dataCharge + extraCharge + taxandcharges;
	
	//display
	cout << "\n\n\tMonthly Cell Phone Bill\n" << endl;
	cout << setw(25) << left << "Phone Charge" << right << setw(3) << "$" << setw(7) << phonecharge << endl;
	cout << setw(25) << left << "Data Charge" << right << setw(3) << "$" << setw(7) << dataCharge << endl;
	cout << setw(25) << left << "Extra Data Charge" << right << setw(3) << "$" << setw(7) << extraCharge << endl;
	cout << setw(25) << left << "Taxes and Surcharges" << right <<  setw(3) << "$" << setw(7) << taxandcharges<< endl;
	cout << setw(25) << left << "Total" << right << setw(3) << "$" << setw(7) << total << endl << endl;


	system("pause");
	return 0;
}