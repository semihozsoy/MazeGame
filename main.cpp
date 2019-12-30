#include <iostream>
#include<string> //
//#include <conio.h> //the library that makes our game more good looking
#include <time.h> //the library that help us at time code
//#include <windows.h> //the library that help us at moving car slowly at random conrtoller
using namespace std;


void doSomething(string *&carLoc, int next);
void move(string *&carLoc, int next);

int point = 0;
int random;
int life = 2;
string driver = " S";
bool check = false;
bool gameEnd = false;
bool lost = false;
int gameTime = 30;
bool controllerfot = false;

int main() {

	clock_t startTime = clock();
	clock_t testTime;
	clock_t timePassed;
	int secondsPassed = 0;
	int time1;
	int time2;
	int time3;

	while (check == false) {

		char select;
		cout << "Choose a driver: 1)S 2)A 3)C \n " << endl;
		cin >> select;
		if (select == '1' || select == '2' || select == '3') {
			check = true;
		}

		switch (select) {
		case '1':
			driver = " S";
			break;
		case '2':
			driver = " A";
			break;
		case '3':
			driver = " C";
			break;
		default:
			cout << "Please enter driver " << endl;
			break;
		}

	}

	char input;
	string *carPoint = NULL;

	//this is our first map
	string maze1[15][15] =
	{
		{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
		{ " #",driver," #"," #"," #"," #"," #"," ."," ."," ."," ."," #"," #"," #"," #" },
		{ " #"," ."," #"," #"," #"," #"," #"," ."," #"," #"," ."," ."," ."," #"," #" },
		{ " #"," ."," #"," #"," #"," #"," ."," ."," #"," #"," #"," #"," ."," #"," #" },
		{ " #"," ."," #"," #"," #"," ."," ."," #"," #"," #"," #"," #"," ."," #"," #" },
		{ " #"," ."," #"," #"," #"," ."," #"," #"," #"," #"," #"," #"," ."," ."," @" },
		{ " #"," ."," #"," #"," #"," ."," ."," #"," #"," #"," #"," #"," #"," #"," #" },
		{ " #"," ."," ."," #"," #"," #"," ."," ."," ."," #"," #"," #"," #"," #"," #" },
		{ " #"," #"," ."," ."," #"," #"," #"," #"," ."," ."," ."," #"," #"," #"," #" },
		{ " #"," #"," #"," ."," #"," #"," #"," #"," #"," #"," ."," ."," #"," #"," #" },
		{ " #"," #"," #"," ."," #"," #"," #"," #"," #"," #"," #"," ."," ."," #"," #" },
		{ " #"," #"," ."," ."," #"," #"," #"," #"," #"," #"," #"," #"," ."," #"," #" },
		{ " #"," #"," ."," #"," #"," #"," #"," #"," ."," ."," ."," ."," ."," #"," #" },
		{ " #"," #"," ."," ."," ."," ."," ."," ."," ."," #"," #"," #"," #"," #"," #" },
		{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" }
	};



	carPoint = &maze1[1][1];

	srand(time(NULL));

	//random bonus number
	//random bonus placement
	int b = rand() % 5;  int x; int y;
	for (int i = 0; i <= b; ++i) {
		x = rand() % 14 + 1;
		y = rand() % 14 + 1;
		if (maze1[x][y] == " .") {
			maze1[x][y] = " X";
		}
		else if (maze1[x][y] == " #")
			b++;
	}

	//printing map on the screen
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 15; ++j) {

			cout << maze1[i][j];
		}
		cout << endl;
	}

	//time code
	testTime = clock();
	timePassed = startTime - testTime;
	secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

	string controller;
	while (controllerfot == false) {
		cout << "1)random 2)user : ";
		cin >> controller;
		if (controller == "1" || controller == "2") {
			controllerfot = true;
		}
	}

	if (controller == "1") {
		while (!gameEnd) {
			testTime = clock();
			timePassed = startTime - testTime;
			secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

			if (secondsPassed >= gameTime) {
				cout << "Time is over !!!! " << endl;
				lost = true;
				break;
			}

			int next_pos;

			if (gameEnd == false) {
				testTime = clock();
				timePassed = startTime - testTime;
				secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);
				//our cheating code
				int a = rand() % 4;
				if (a == 0) {
					next_pos = -15;
					doSomething(carPoint, next_pos);
				}
				else if (a == 1) {
					next_pos = +15;
					doSomething(carPoint, next_pos);
				}
				else if (a == 2) {
					next_pos = -1;
					doSomething(carPoint, next_pos);
				}
				else if (a == 3) {
					next_pos = +1;
					doSomething(carPoint, next_pos);
				}
				Sleep(100);
			}
			//The code delete everything at screen
			system("CLS");

			for (int i = 0; i < 15; ++i)
			{
				for (int j = 0; j < 15; ++j)
				{

					cout << maze1[i][j];
				}
				cout << endl;
			}
		}
	}

	else if (controller == "2") {
		//the gameplay
		while (!gameEnd) {
			testTime = clock();
			timePassed = startTime - testTime;
			secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

			if (secondsPassed >= gameTime) {
				cout << "Time is over !!!! " << endl;
				lost = true;
				break;
			}

			input = _getch();
			int next_pos;

			if (gameEnd == false) {
				testTime = clock();
				timePassed = startTime - testTime;
				secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);
				//our cheating code
				if (input == 'e')

					gameEnd = true;
				// we can control our car with w a s d and also u h j k
				else if (input == 'w' || input == 'u')
				{
					next_pos = -15;
					doSomething(carPoint, next_pos);
				}
				else if (input == 's' || input == 'j')
				{
					next_pos = 15;
					doSomething(carPoint, next_pos);

				}
				else if (input == 'a' || input == 'h')
				{
					next_pos = -1;
					doSomething(carPoint, next_pos);

				}
				else if (input == 'd' || input == 'k')
				{
					next_pos = 1;
					doSomething(carPoint, next_pos);

				}
			}
			//The code delete everything at screen
			system("CLS");

			for (int i = 0; i < 15; ++i)
			{
				for (int j = 0; j < 15; ++j)
				{

					cout << maze1[i][j];
				}
				cout << endl;
			}
		}
	}
	// If time is over this code is going to stop the game
	if (secondsPassed >= gameTime) {
		cout << "Time is over !!!! " << endl;
		lost = true;
	}

	time1 = secondsPassed;
	point += (gameTime - secondsPassed) * 2;

	if (lost == false) {
		cout << "Congrulations! You have passed the first level !!!! " << endl;
	}
	else if (lost == true) {
		cout << "Score: " << point << endl;
		cout << "You have failed !!!! " << endl;

	}

	if (!lost) {
		gameEnd = false;
		//Here is our second map
		string maze2[20][20] =
		{
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #",driver," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," ."," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," ."," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," ."," #"," #"," #"," #"," #"," #"," #"," #"," ."," ."," ."," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," ."," ."," ."," ."," #"," #"," #"," #"," #"," ."," #"," ."," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," ."," #"," #"," #"," #"," #"," ."," #"," ."," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," ."," #"," #"," #"," #"," #"," ."," #"," ."," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," ."," #"," #"," #"," #"," #"," ."," #"," ."," #"," #"," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," ."," ."," #"," #"," #"," #"," ."," #"," ."," ."," ."," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," ."," #"," #"," #"," #"," ."," #"," #"," #"," ."," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," ."," #"," #"," ."," ."," ."," #"," #"," #"," ."," #"," #"," #"," #"," #" },
			{ " #"," #"," #"," #"," #"," ."," #"," #"," ."," #"," #"," #"," #"," #"," ."," #"," #"," ."," ."," @" },
			{ " #"," #"," #"," #"," #"," ."," ."," ."," ."," #"," #"," #"," #"," #"," ."," #"," #"," ."," #"," #" },
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," ."," ."," ."," ."," #"," #" },
			{ " #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #"," #" }
		};

		carPoint = &maze2[5][1];

		srand(time(NULL));
		//random bonus number
		//random bonus placement
		//for second map
		int mp2b = rand() % 5;  int mpb2x; int mpb2y;
		for (int i = 0; i <= mp2b; ++i) {
			mpb2x = rand() % 19 + 1;
			mpb2y = rand() % 19 + 1;
			if (maze2[mpb2x][mpb2y] == " .") {
				maze2[mpb2x][mpb2y] = " X";
			}
			else if (maze2[mpb2x][mpb2y] == " #")
				mp2b++;
		}

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {

				cout << maze2[i][j];
			}
			cout << endl;
		}
		controllerfot = false;
		string controller2;
		while (controllerfot == false) {
			cout << "1)random 2)user ";
			cin >> controller2;
			if (controller2 == "1" || controller2 == "2") {
				controllerfot = true;
			}
		}

		startTime = clock();
		secondsPassed = 0;

		if (controller2 == "1") {
			while (!gameEnd) {
				testTime = clock();
				timePassed = startTime - testTime;
				secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

				if (secondsPassed >= gameTime) {
					cout << "Time is over !!!! " << endl;
					lost = true;
					break;
				}

				int next_pos;

				if (gameEnd == false) {
					testTime = clock();
					timePassed = startTime - testTime;
					secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);
					//our cheating code
					int a = rand() % 4;
					if (a == 0) {
						next_pos = -20;
						doSomething(carPoint, next_pos);
					}
					else if (a == 1) {
						next_pos = +20;
						doSomething(carPoint, next_pos);
					}
					else if (a == 2) {
						next_pos = -1;
						doSomething(carPoint, next_pos);
					}
					else if (a == 3) {
						next_pos = +1;
						doSomething(carPoint, next_pos);
					}
					Sleep(100);
				}
				//The code delete everything at screen
				system("CLS");

				for (int i = 0; i < 20; ++i)
				{
					for (int j = 0; j < 20; ++j)
					{

						cout << maze2[i][j];
					}
					cout << endl;
				}
			}
		}

		else if (controller2 == "2") {
			while (!gameEnd) {

				testTime = clock();
				timePassed = startTime - testTime;
				secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

				if (secondsPassed >= gameTime) {
					cout << "Time is over !!!! " << endl;
					lost = true;
					break;
				}

				input = _getch();
				int next_pos;

				if (gameEnd == false) {
					if (input == 'e')

						gameEnd = true;

					else if (input == 'w' || input == 'u')
					{
						next_pos = -20;
						doSomething(carPoint, next_pos);
					}
					else if (input == 's' || input == 'j')
					{
						next_pos = 20;
						doSomething(carPoint, next_pos);

					}
					else if (input == 'a' || input == 'h')
					{
						next_pos = -1;
						doSomething(carPoint, next_pos);

					}
					else if (input == 'd' || input == 'k')
					{
						next_pos = 1;
						doSomething(carPoint, next_pos);

					}
				}
				system("CLS");

				for (int i = 0; i < 20; ++i)
				{
					for (int j = 0; j < 20; ++j)
					{

						cout << maze2[i][j];
					}
					cout << endl;
				}

			}
		}

		time2 = secondsPassed;
		point += (gameTime - secondsPassed) * 2;
		if (lost == false) {
			cout << "Congrulations! You have passed the second level !!!! " << endl;
		}
		else if (lost == true) {
			cout << "Score: " << point << endl;
			cout << "Finished level 1 in " << time1 << " seconds." << endl;
			cout << "You have failed !!!! " << endl;
		}

	}
	if (!lost) {
		gameEnd = false;
		//Here is our random map
		string mapRandom[20][20];
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				mapRandom[i][j] = " #";
			}
		}

		srand(time(NULL));
		int a = 0, b = 0;
		for (a, b; a < 20, b < 20; a, b) {

			int k = rand() % 2;
			if (k == 0) {
				mapRandom[a][b] = " .";
				a += 1;
			}
			else if (k == 1) {
				mapRandom[a][b] = " .";
				b += 1;
			}
		}
		if (a == 20 && b != 20) {
			mapRandom[19][b] = " @";
		}
		else if (b == 20 && a != 20) {
			mapRandom[a][19] = " @";
		}


		carPoint = &mapRandom[0][0];
		mapRandom[0][0] = driver;

		srand(time(NULL));
		//random bonus number
		//random bonus placement
		//for second map
		int mp2b = rand() % 5;  int mpb2x; int mpb2y;
		for (int i = 0; i <= mp2b; ++i) {
			mpb2x = rand() % 19 + 1;
			mpb2y = rand() % 19 + 1;
			if (mapRandom[mpb2x][mpb2y] == " .") {
				mapRandom[mpb2x][mpb2y] = " X";
			}
			else if (mapRandom[mpb2x][mpb2y] == " #")
				mp2b++;
		}

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j) {

				cout << mapRandom[i][j];
			}
			cout << endl;
		}
		controllerfot = false;
		string controllerRandom;
		while (controllerfot == false) {
			cout << "1)random 2)user ";
			cin >> controllerRandom;
			if (controllerRandom == "1" || controllerRandom == "2") {
				controllerfot = true;
			}
		}

		startTime = clock();
		secondsPassed = 0;

		if (controllerRandom == "1") {
			while (!gameEnd) {
				testTime = clock();
				timePassed = startTime - testTime;
				secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

				if (secondsPassed >= gameTime) {
					cout << "Time is over !!!! " << endl;
					lost = true;
					break;
				}

				int next_pos;

				if (gameEnd == false) {
					testTime = clock();
					timePassed = startTime - testTime;
					secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);
					//our cheating code
					int a = rand() % 2;
					if (a == 0) {
						next_pos = +20;
						doSomething(carPoint, next_pos);
					}
					else if (a == 1) {
						next_pos = +1;
						doSomething(carPoint, next_pos);
					}
					Sleep(100);

				}
				//The code delete everything at screen
				system("CLS");

				for (int i = 0; i < 20; ++i)
				{
					for (int j = 0; j < 20; ++j)
					{

						cout << mapRandom[i][j];
					}
					cout << endl;
				}
			}
		}
		else if (controllerRandom == "2") {
			while (!gameEnd) {

				testTime = clock();
				timePassed = startTime - testTime;
				secondsPassed = (int)(-timePassed / (double)CLOCKS_PER_SEC);

				if (secondsPassed >= gameTime) {
					cout << "Time is over !!!! " << endl;
					lost = true;
					break;
				}

				input = _getch();
				int next_pos;

				if (gameEnd == false) {
					if (input == 'e')

						gameEnd = true;

					else if (input == 'w' || input == 'u')
					{
						next_pos = -20;
						doSomething(carPoint, next_pos);
					}
					else if (input == 's' || input == 'j')
					{
						next_pos = 20;
						doSomething(carPoint, next_pos);

					}
					else if (input == 'a' || input == 'h')
					{
						next_pos = -1;
						doSomething(carPoint, next_pos);

					}
					else if (input == 'd' || input == 'k')
					{
						next_pos = 1;
						doSomething(carPoint, next_pos);

					}
				}
				system("CLS");

				for (int i = 0; i < 20; ++i)
				{
					for (int j = 0; j < 20; ++j)
					{

						cout << mapRandom[i][j];
					}
					cout << endl;
				}

			}
		}
		time3 = secondsPassed;
		startTime = clock();
		secondsPassed = 0;
		if (lost == false) {
			cout << "Congrulations you have finished !!!! " << endl;
			cout << "Score: " << point << endl;
			cout << "Finished level 1 in " << time1 << " seconds." << endl;
			cout << "Finished level 2 in " << time2 << " seconds." << endl;
			cout << "Finished level 3 in " << time3 << " seconds." << endl;

		}
		else if (lost == true) {

			cout << "You have failed !!!! " << endl;
			cout << "Score: " << point << endl;
			cout << "Finished level 1 in " << time1 << " seconds." << endl;
			cout << "Finished level 2 in " << time2 << " seconds." << endl;
		}
	}
	system("PAUSE");
	return 0;
}

//Here are our bonuses and effects to car
void doSomething(string *&carLoc, int next) {
	//if you crash to wall you lose life and your car is gooing to be smaller
	if (*(carLoc + next) == " #") {
		if (driver == " A") {
			driver = " a";
		}
		else if (driver == " C") {
			driver = " c";
		}
		else if (driver == " S") {
			driver = " s";
		}
	}
	//if you take bonus you gain life max. 2 and if you were small you become bigger
	else if (*(carLoc + next) == " X") {
		move(carLoc, next);
		//here is our random point bonus code
		random = rand() % 2; // this code will give you random value 1 or 0
		if (random == 1) {
			point = point + 1;
		}
		else if (random == 0) {
			point = point - 1;
		}
		if (driver == " a")
			driver = " A";
		if (driver == " c")
			driver = " C";
		if (driver == " s")
			driver = " S";
	}
	else if (*(carLoc + next) == " .") {
		move(carLoc, next);
	}
	// if our car reach to @ you won the level
	else if (*(carLoc + next) == " @") {
		gameEnd = true;
	}

}

//this function is moving our car
void move(string*& carLoc, int next) {

	*carLoc = " .";
	carLoc = carLoc + next;
	*carLoc = driver;
}
