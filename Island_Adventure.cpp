// IslandAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Developed by M Nickbakhsh
//Updated 29/10/2020 for the TOGA students

//Change examples comment
#include <iomanip>
using namespace std;
#include <string>
#include <iostream>
#include <conio.h>
#include <stdlib.h>	//Used for random numbers
#include <time.h> //Used for initialising the random numeber seed.

	
//Set up
	//Vairable delairation.
		//Array Vairablres
	int i, j;	//Used for holding the index vairable for the array build up.
	
	const int aSize = 20;	//Used to define the array's size.	//Here it is used for 0-1
	string island[aSize][aSize];	//2d array defined using the sizes passed in; AS it is not the array has 2 sets of 20.
	
	srand( time( NULL ) );	//Initialised the randon numebr seed.
	
		//player vairables 
	char key_press;	//Holds the indivual key press
	int ascii_value;	//Used to hold the ascii value of the inputted button to be used as controls
	int player_hitpoints = 3;	//Used to keep track of the players current hit points
		const int player_starting_x = 1;	//Defines their starting point, so I don't ahve to change it each time manually
		const int player_starting_y = 1;
		
		int player_current_x = 0;	//Holds the plauers current position, will be altered as they move
		int player_current_y = 0;
		
	//Square class;
	class Square
	{		//Vairables
		private:	//Values for the square
			int x;	//Positonal counters, used to keep track of where the square currently is.
			int y;
			bool state;	//Donotates if it is a reward square or a damage square
			//Constructor
		Square()	//Constructor call to set default values;
		{
			x = 0;
			y = 0;
			state = false:	//Defaults to being a score square.
		}
		
			//Methods
				//Getters
		public:
			int get_x()
			{
				return x;
			}
			
			int get_y()
			{
				return y;
			}
			
			bool get_state()
			{
				return state;
			}
			
					//Setters
			void set_x( int new_position )	//Used to define the position of x, with an arguement
			{
				x = new_position;
			}
				
			void set_y( int new_position )	//^ but for Y
			{
				y = new_position;
			}
			
			void set_state( bool new_state )	//Used to define what type of square it will be
			{
				state = new_state;
			}
	};
	
//check array limits
int checkBoundries( position_to_check )	//Used to keep the player within predefined boundaries
{
	switch( position_to_check )
	{
		case: 10
			return 9;
			break;
			
		case: -1
			return 0;
			break;
	}
}

int main()
{	
	for (size_t i = 0; i < (sizeof(island) / sizeof(island[0])) - 1; i++)
		{
		for (size_t j = 0; j < (sizeof(island) / sizeof(island[0])) - 1; j++)
			{
			//initialising island map
			island[i][j] = "Nothing here";
			}
		}
		
	//Setting the values of locations on the island
	/*island[0][0] = "Welcome to Island Adventure";
	island[0][5] = "C++ is a middle level language ";


	island[0][8] = "C++ syntax may be difficult, but it is a very powerful language ";
	island[0][9] = "C++ language was developed by Bjarne Stroustrup ";
	island[3][6] = "C++ Standard Library is a collection of classes and functions ";*/
	
	cout << island[1][1] << endl;
	bool flag = true;//this variable is used to exit the loop when
	
	//any keys other than the arrow keys are pressed
	cout << "Use arrow keys for the navigation, when you press anything else you forfit the game \n";
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
				
				default:
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