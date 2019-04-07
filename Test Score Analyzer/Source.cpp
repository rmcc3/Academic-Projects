// Raymond McCann
// CSC 205-51
// Assignment: 6
// Purpose: Calculate student test scores using pointers.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constant variables
const int NUM_Q = 50; // Number of test questions
const int NUM_STUDENTS = 5;


// Function prototypes
void getData(string *, int *, const int);
void display(const string *, const int *, int *, int *, double *, const int);
void calculate(const int *, int *, int *, const int);
int findHigh(const string *, const int *, const int);
double findAverage(const int *, const int);

int main()
{
	// Create an arrays for the students.
	string id[NUM_STUDENTS];
	int correct[NUM_STUDENTS];
	int incorrect[NUM_STUDENTS];
	int score[NUM_STUDENTS];
	double average;

	getData(id, correct, NUM_STUDENTS);
	calculate(correct, incorrect, score, NUM_STUDENTS);

	average = findAverage(score, NUM_STUDENTS);

	display(id, correct, incorrect, score, &average, NUM_STUDENTS);


	system("PAUSE");
	return 0;
}

void getData(string *id, int *correct, const int num_students)
{
	for (int index = 0; index < num_students-1; index++)
	{
		cout << "Student's ID: ";
		cin >> *(id + index);

		cout << "Number of correct answers: ";
		cin >> *(correct + index);
	}
}

void calculate(const int *correct, int *incorrect, int *score, const int num_students)
{
	for (int index = 0; index < num_students-1; index++)
	{
		// Calculate the number of incorrect answers.
		*(incorrect + index) = (NUM_Q - *(correct + index));

		// Calculate score.
		*(score + index) = (2 * *(correct + index));
	}
}

double findAverage(const int *score, const int num_students)
{
	double currentScore = 0;

	for(int index = 0; index < num_students-1; index++)
	{
		currentScore += *(score + index);
	}
	return (currentScore / (num_students - 1));
}

int findHigh(const string *id, const int *score, const int num_students)
{
	int highestScore = 0;

	for (int index = 0; index < num_students-1; index++)
	{
		if (*(score + index) > highestScore)
			highestScore = *(score + index);
	}

	return highestScore;
}

void display(const string *id, const int *correct, int *incorrect, int *score, double *average, const int num_students)
{
	const int high = findHigh(id, score, num_students);

	const char separator = ' ';
	const int width = 20;

	system("CLS");

	cout << left << setw(width) << setfill(separator) << "ID";
	cout << left << setw(width) << setfill(separator) << "Correct Answers";
	cout << left << setw(width) << setfill(separator) << "Incorrect Answers";
	cout << left << setw(width) << setfill(separator) << "Score\n" << endl;

	for (int index = 0; index < num_students-1; index++)
	{
		cout << left << setw(width) << setfill(separator) << *(id + index);
		cout << left << setw(width) << setfill(separator) << *(correct + index);
		cout << left << setw(width) << setfill(separator) << *(incorrect + index);
		cout << left << setw(width) << setfill(separator) << *(score + index) << endl;
	}

	cout << "\nSummary:\n" << endl;
	cout << "Test Score Average: " << *average << endl;
	cout << "Highest Test Score: " << high << endl;
}
