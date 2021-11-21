// IslandAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Developed by M Nickbakhsh
//Updated 29/10/2020 for the TOGA students
#include <iomanip>
using namespace std;
#include <string>
#include <iostream>
#include <conio.h>

	const int aSize = 20;
	int x = 0, y = 0;
	void checkBoundries();
	
		//check array limits
void checkBoundries()
{
	if (x == 10)
		x = 9;
	if (x == -1)
		x = 0;
	if (y == -1)
		y = 0;
	if (y == 10)
		y = 9;
}

int main()
{
	//
	int i, j;
	char key_press;
	int ascii_value;
	string island[aSize][aSize];
	cout << "Weclome to Island Adventure\n";
	
	for (size_t i = 0; i < (sizeof(island) / sizeof(island[0])) - 1; i++)
		{
		for (size_t j = 0; j < (sizeof(island) / sizeof(island[0])) - 1; j++)
			{
			//initialising island map
			island[i][j] = "Nothing here";
			}
		}
		
	//Setting the values of locations on the island
	island[0][0] = "Welcome to Island Adventure";
	island[0][5] = "C++ is a middle level language ";


	island[0][8] = "C++ syntax may be difficult, but it is a very powerful language ";
	island[0][9] = "C++ language was developed by Bjarne Stroustrup ";
	island[3][6] = "C++ Standard Library is a collection of classes and functions ";
	
	cout << island[1][1] << endl;
	bool flag = true;//this variable is used to exit the loop when
	
	//any keys other than the arrow keys are pressed
	cout << "Use arrow keys for the navigation \n";
	while (flag)
	{
		if (_getch() != 0)
		{
			key_press = _getch(); // need to include conio.h
			ascii_value = key_press;
			//cout << ascii_value << endl; You can use this for testing
			switch (ascii_value)
			{
				case 72://integer value for the UP key
				x--;
				break;
				
				case 80://integer value for DOWN key
				x++;
				break;
				
				case 77:// integer value for the RIGHT key
				y++;
				break;
				
				case 75:// integer value for the LEFT key
				y--;
				break;
				
				case 0:
				flag = false;
				break;
			}
		checkBoundries();
		/* Here is where we clear the screen */
		system("CLS");
		cout << "Your current position of x = " << x << " and y = " << y <<
		endl;
		cout << island[x][y] << endl;
		}
	}
	
	cout << "Thank you for playing Island Adventures \n";
}
		
	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu 3
	//Island Adventure
	// Debug program: F5 or Debug > Start Debugging menu
	// Tips for Getting Started:
	// 1. Use the Solution Explorer window to add/manage files
	// 2. Use the Team Explorer window to connect to source control
	// 3. Use the Output window to see build output and other messages
	// 4. Use the Error List window to view errors
	// 5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	// 6. In the future, to open this project again, go to File > Open > Project and select the .sln file