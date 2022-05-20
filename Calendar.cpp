/* Author: Irene Zaugg, S02672231
Class: CSC 234 - 601
Instructor: Robert Gilanyi

This program takes as input from the user a year and numerical day of the week, then prints a 12-month calendar
using the input starting day.*/

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

void printHeading(int month, int year);
void printLine();
int numberOfDays(int day, int year);
void printCalendar(int datePosition, int month, int year);

const int CAL_WIDTH = 29;

int main()
{
	int day;
	int year;

	// Get user input.
	cout << "Enter a year: " << endl;

	while (!(cin >> year)) {
		cout << "Incorrect input.  Please enter the year as a number: " << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	
	cout << "Enter a numerical day of the week as a starting day (1 = Sunday, 2 = Monday, etc.): " << endl;
	
	while (!(cin >> day) || (day < 1 || day > 7)) {
		cout << "Incorrect input.  Please enter a numerical day of the week (1 - 7): " << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}
	
	// Each date is printed 4 spaces apart.  Set starting day to position.
	day *= 4;
	printCalendar(day, 1, year); // Recursively print calendar months, starting with January 1.

	return 0;
}

void printHeading(int month, int year)
{
	string monthName;
	switch (month)
	{
	case 1:
		monthName = "January";
		break;
	case 2:
		monthName = "February";
		break;
	case 3:
		monthName = "March";
		break;
	case 4:
		monthName = "April";
		break;
	case 5:
		monthName = "May";
		break;
	case 6:
		monthName = "June";
		break;
	case 7:
		monthName = "July";
		break;
	case 8:
		monthName = "August";
		break;
	case 9:
		monthName = "September";
		break;
	case 10:
		monthName = "October";
		break;
	case 11:
		monthName = "November";
		break;
	case 12:
		monthName = "December";
		break;
	default:
		monthName = "";
		break;
	}

	printf("%14s %d\n", monthName.c_str(), year);
	printLine();
	printf(" Sun Mon Tue Wed Thu Fri Sat\n");

}

void printLine() {
	for (int i = 0; i < CAL_WIDTH; i++) {
		cout << "-";
	}
	cout << endl;
}

int numberOfDays(int month, int year) {
	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
		if (year % 4 == 0 || year % 400 == 0)
			return 29;
		else
			return 28;
	else
		return 31;
}

void printCalendar(int datePosition, int month, int year) {
	printHeading(month, year);

	int currentDate = 1;
	
	// Print spaces before first printed day.
	for (int i = 4; i < datePosition; i++) {
		cout << " ";
	}
	
	while (currentDate <= numberOfDays(month, year)) {
		printf("%4d", currentDate);
		currentDate++;
		datePosition += 4;
		if (datePosition > CAL_WIDTH) {
			cout << endl;
			datePosition = 4;
		}
	}
	
	cout << endl;
	cout << endl;

	month++;
	if (month <= 12)
		printCalendar(datePosition, month, year);
}