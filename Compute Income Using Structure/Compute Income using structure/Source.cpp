// Raymond McCann
// CSC 205-51
// Assignment: 7
// Purpose: Compute Income using structures
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;


// If set to true, the program will auto fill with values at run time.
constexpr bool TEST = false;

// Number of employees.
const int NUM_EMPS = 5;

/**
 * 
 */
struct incomeInfo
{
	string emp_id;
	double pay;
	double bonus;
	double totPay;
};

incomeInfo employee[NUM_EMPS];

// Function Prototypes
void getIncome(incomeInfo [], int);
void compute(incomeInfo [], int);
double payroll(incomeInfo [], int);
void display(incomeInfo[], double, int);

int main()
{
	char loopTheResults = 'y';
	double total;

	while (loopTheResults == 'y') {
		// If test is enabled, the program will start with pre-filled values from the sample data.
		// This is used to make testing easier during the debugging process. 
		// Should not be used to test manual inputs.
		if (TEST)
		{
			employee[0].emp_id = "123";
			employee[0].pay = 5000.00;
			employee[0].bonus = 500.25;

			employee[1].emp_id = "133";
			employee[1].pay = 4000.00;
			employee[1].bonus = 0.00;

			employee[2].emp_id = "167";
			employee[2].pay = 3500.75;
			employee[2].bonus = 100.00;

			employee[3].emp_id = "156";
			employee[3].pay = 6200.50;
			employee[3].bonus = 0.00;

			employee[4].emp_id = "195";
			employee[4].pay = 2000.00;
			employee[4].bonus = 300.00;

			compute(employee, NUM_EMPS);
			total = payroll(employee, NUM_EMPS);
			display(employee, total, NUM_EMPS);
		}

		if (!TEST)
			getIncome(employee, NUM_EMPS);

		compute(employee, NUM_EMPS);
		total = payroll(employee, NUM_EMPS);
		display(employee, total, NUM_EMPS);

		cout << "Would you like to enter another data set? (Y/N) ";
		cin >> loopTheResults;
		loopTheResults = tolower(loopTheResults);

		while ((loopTheResults != 'y') && (loopTheResults != 'n'))
		{
			cout << "ERROR: Enter Y/N :";
			cin >> loopTheResults;
			loopTheResults = tolower(loopTheResults);
		}

		if (loopTheResults == 'n')
			break;
	}

	return 0;
}

void getIncome(incomeInfo employee[], int NUM_EMPS)
{
	cout << "Please enter the ID's pay, and bonuses for the employee." << endl;

	for(int i = 0; i < NUM_EMPS; i++)
	{
		cout << "Employee ID: ";
		cin >> employee[i].emp_id;

		cout << "Pay for employee #" << employee[i].emp_id << ": ";
		cin >> employee[i].pay;

		cout << "Bonus for employee #" << employee[i].emp_id << ": ";
		cin >> employee[i].bonus;
	}
}

// Calculate total pay including bonus.
void compute(incomeInfo *e_ptr, int NUM_WORKERS)
{
	for (int i = 0; i < NUM_WORKERS; i++)
	{
		(e_ptr + i)->totPay = ((e_ptr + i)->pay + (e_ptr + i)->bonus);
	}
}

// Calculate the total payroll of all employees combined.
double payroll(incomeInfo *e_ptr, int NUM_WORKERS)
{
	double totalPayroll = 0;
	for (int i = 0; i < NUM_WORKERS; i++)
	{
		totalPayroll += (e_ptr + i)->totPay;
	}

	return totalPayroll;
}

void display(incomeInfo employee[], double total, int NUM_WORKERS)
{
	const char separator = '$';
	const int nameWidth = 20;
	const int width = 20;

	int highestPaidEmployee = NULL;

	system("CLS");
	setprecision(2);

	printf("%-25s%-25s%-20s%-25s\n", "ID", "Pay", "Bonus", "Total Pay");

	for (int index = 0; index < NUM_WORKERS; index++)
	{
		printf("%-25s$%-24.2f$%-19.2f$%-10.2f\n", employee[index].emp_id.c_str(), employee[index].pay, employee[index].bonus, employee[index].totPay);

		// Simple check to see if the employee is paid more than another.
		if (employee[index].totPay > employee[highestPaidEmployee].totPay)
			highestPaidEmployee = index;
	}

	cout << "\n\nTotal Payroll amount: " << setprecision(2) << fixed << "$" << total << endl;
	cout << "Highest Pay: " << setprecision(2) << fixed << "$" << employee[highestPaidEmployee].totPay << "\n" << endl;
}