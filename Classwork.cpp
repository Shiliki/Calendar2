/*#include <iostream>;
#include <cstdio>;

using namespace std;

int main() {
	// Get input from the user.
	int year;
	int dayOfTheWeek;

	cout << "Enter a year: " << endl;
	while (!(cin >> year)) {
		cout << "Please enter an integer: " << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}

	cout << "Enter a day: " << endl;
	while (!(cin >> day) && (day < 1 || day > 7) {
		cout << "Please enter an integer between 1 and 7: " << endl;
		cin.clear();
		cin.ignore(100, '\n');
	}

	for (int i = 1; i <= 12; i++) {
		string monthName;
		int numOfDays;
		switch (i) {
		case 1:
			monthName = "January";
			numOfDays = 31;
			break;
		case 2:
			//leap year
			break;
		default:
			break;
		}

		// print calendar
		printf();
	}

	return 0;
}*/