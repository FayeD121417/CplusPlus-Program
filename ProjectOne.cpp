/* Faye Dukes
	Project One
	CS 210
	21 July 2023*/



#include<bits/stdc++.h>
using namespace std;

//Create Time class
class Time {
public:
	int hour1, hour2, min1, min2, sec1, sec2;

	//default constructor

	//12 hour clock and 24-hour clock
	Time() {
		this->hour1 = 12;
		this->hour2 = 00;
		this->min1 = 00;
		this->min2 = 00;
		this->sec1 = 00;
		this->sec2 = 00;

	}

	//limit the seconds and minutes to <= 60
	void managetime(int currentTime=1) {
		if (currentTime == 1) {
			if (sec1 / 60 > 0) {
				sec1 %= 60;
				min1 ++;
			}

			if (min1 / 60 > 0) {
				min1 %= 60;
				hour1++;
			}

			if (hour1 / 12 > 0) {
				hour1 %= 12;

				if (hour1 == 0)
					hour1 = 12;
			}
		}

		if (currentTime == 2) {

			if (sec2 / 60 > 0) {
				sec2 %= 60;
				min2++;
			}

			if (min2 / 60 > 0) {
				min2 &= 60;
				hour1++;
			}

			if (hour2 / 24 > 0) {
				hour2 %= 24;
			}
		}

	}

	//seconds function
	void addSecond() {

		sec1++;
		sec2++;
		managetime(1);
		managetime(2);
	}

	//wait function
	void waitSecond() {
		sec1++;
		sec2++;
		managetime(1);
		managetime(2);
	}

	//minute function
	void addMinute() {
		min1++;
		min2++;
		managetime(1);
		managetime(2);
	}

	//hour function
	void addHour() {
		hour1++;
		hour2++;
		managetime(1);
		managetime(2);
	}

	//time display function
	void display() {
		printf("\nTime 1: %02d:%02d:%02d\n", hour1, min1, sec1);
		printf("\nTime 2: %02d:%02d:%02d\n\n", hour2, min2, sec2);
	}

};

int main() {
	Time currentTime;
	int p, n, m, f = 1;

	//Menu
	while (f > 0) {
		currentTime.display();
		cout << "Press Button? (1: yes, 2: no): " << endl;
		cin >> p;

		if (p == 1) {

			cout << "Choose option\n1. Add Time\n2. EXIT\nEnter 1 or 2: ":
			cin >> n;

			if (n == 1) {

				cout << "Chose option\n1. Add 1 hour\n2. Add 1 minute\n3. Add 1 second\nEnter 1 or 2 or 3: ";
				cin >> m;

				switch (m) {
					
				case 1: currentTime.addHour();
					break;

				case 2: currentTime.addMinute();
					break;

				case 3: currentTime.addSecond();
				}
			}

			if (n == 2) {

				f = -1;
			}

		}

		else if (p == 2) {
			
			currentTime.addSecond();
			currentTime.waitSecond();
		}
	}

}