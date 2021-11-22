// IslandAdventure.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Developed by M Nickbakhsh
//Updated 29/10/2020 for the TOGA students

//Change examples comment
#include <iomanip>
using namespace std;
#include <string>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>	//Used for random numbers
#include <time.h> //Used for initialising the random numeber seed.

//Set up
	//Vairable delairation.
		//Array Vairablres
	int i, j, score_x, score_y;	//Used for holding the index vairable for the array build up.
	
	//const int aSize = 20;	//Used to define the array's size.	//Here it is used for 0-1
	const int XSIZE = 20;	//Keeps track of the array's size, and it's min value; For each of it's dimensions
		const int XMIN = 0;
	const int YSIZE = 10;
		const int YMIN = 0;
	//string island[aSize][aSize];	//2d array defined using the sizes passed in; AS it is not the array has 2 sets of 20.
	short int island[XSIZE][YSIZE];	//2D array defined using the sizes passed in.
	short int hint_square = 0;	//Used for drawing hints to the screen.
	
		//player vairables 
	char key_press;	//Holds the indivual key press
	int ascii_value;	//Used to hold the ascii value of the inputted button to be used as controls
	int player_hitpoints = 3;	//Used to keep track of the players current hit points
		const int player_starting_x = 1;	//Defines their starting point, so I don't ahve to change it each time manually
		const int player_starting_y = 1;
	int player_score = 0;	//Keeps track of the players score
		
		int player_current_x = 5;	//Holds the plauers current position, will be altered as they move
		int player_current_y = 5;
		
	class square_tile //Square class;
	{		//Vairables
		private:	//Values for the square
			int x;	//Positonal counters, used to keep track of where the square currently is.
			int y;
			bool state;	//Donotates if it is a reward square or a damage square
		
			//Methods
		public:
				//constructor 
			square_tile()	//Constructor call to set default values;
			{
				x = 0;
				y = 0;
				state = false;	//Defaults to being a score square.
			}
				//getters
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
				x = new_position;	//Uses the passed in value to update position of the square
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

//check play space boundaries
int checkBoundries( int position_to_check, int maximum, int minimum )	//Used to keep the player within predefined boundaries
{
	if( position_to_check >= maximum )
	{
		return maximum --;
		cout << "moving  value down" << endl;
	}
		
	else if( position_to_check <= minimum )
	{
		return minimum ++;
		cout << "moving  value up" << endl;
	}
	
	else
	{
		return position_to_check;
		cout << "Not moving value" << endl;
	}
}

int main()
{	
	srand (time(NULL));	//Has to be done in the main or it will not work
	
	square_tile score_square; //Defining the two squares
	square_tile damage_square;
		damage_square.set_state( true );	//Set now so it does not need to be changed later
//Setting positions
	//Score square
	score_square.set_x( rand() % ( XSIZE - 1) );	//passes in a value less than the max array size
	score_square.set_y( rand() % ( YSIZE - 1) );
		//Damage square 
	damage_square.set_x( rand() % ( XSIZE - 1 ) );
	damage_square.set_y( rand() % ( YSIZE - 1 ) );	//Need to make a check to ensure there is no overlap	//Later 
	
	if( ( score_square.get_x() == damage_square.get_x() ) && ( score_square.get_y() == damage_square.get_y() ) )	//ensures they are not the same value
	{
		while( true )
		{
			damage_square.set_x( rand() % ( XSIZE - 1 ) );
			damage_square.set_y( rand() % ( YSIZE - 1 ) );	//Need to make a check to ensure there is no overlap	//Later 
			
			if( ( score_square.get_x() == damage_square.get_x() ) && ( score_square.get_y() == damage_square.get_y() ) )
			{
				break;	//Exits the while loop
			}
			
			else
			{
				damage_square.set_x( rand() % ( XSIZE - 1 ) );
				damage_square.set_y( rand() % ( YSIZE - 1 ) );	//Need to make a check to ensure there is no overlap	//Later 
			}
		}
	}
	
	else
	{
		;
	}
	
	//Setting the values of locations on the island
	for (size_t i = 0; i < ( XSIZE + 1 ) ; i++)
	{
		for (size_t j = 0; j < ( YSIZE + 1 ) ; j++)
		{
			island[ i ][ j ] = 0;//initialising island map, 0 values have nothing in their cell
		}
	}
	//Setting the co-ordinates.
	island[ score_square.get_x() ][ score_square.get_y() ] = 1;
	island[ damage_square.get_x() ][ damage_square.get_y() ] = 2;
	
	bool flag = true;//this variable is used to exit the loop when the player inputs an invalid value to escape the game
	cout << "Use arrow keys for the navigation, when you press anything else you forfit the game,  your current location is " << player_current_x << " " << player_current_y << endl;
	
	while (flag)
	{
		
		if( island[ player_current_x ][ player_current_y ] == 1 )
		{
			//Score reward if there is a match
			player_score ++;	//Incriments their score up.
			//Then to move/ reset the score and damage squares=
				//Reset Island
			island[ score_square.get_x() ][ score_square.get_y() ] = 0;
			island[ damage_square.get_x() ][ damage_square.get_y() ] = 0;
				//Set Island stats 
			score_square.set_x( rand() % ( XSIZE - 1) );//Score square
			score_square.set_y( rand() % ( YSIZE - 1) );
	 
			damage_square.set_x( rand() % ( XSIZE - 1 ) );//Damage square
			damage_square.set_y( rand() % ( YSIZE - 1 ) );	
			
			if( ( score_square.get_x() == damage_square.get_x() ) && ( score_square.get_y() == damage_square.get_y() ) )	//ensures they are not the same value
			{
				while( true )
				{
					damage_square.set_x( rand() % ( XSIZE - 1 ) );
					damage_square.set_y( rand() % ( YSIZE - 1 ) );	//Need to make a check to ensure there is no overlap	//Later 
					
					if( ( score_square.get_x() == damage_square.get_x() ) && ( score_square.get_y() == damage_square.get_y() ) )
					{
						break;	//Exits the while loop
					}
					
					else
					{
						damage_square.set_x( rand() % ( XSIZE - 1 ) );
						damage_square.set_y( rand() % ( YSIZE - 1 ) );	//Need to make a check to ensure there is no overlap	//Later 
					}
				}
			}
			
			else
			{
				;
			}
			
					//Changing Island properties for the next targers
			island[ score_square.get_x() ][ score_square.get_y() ] = 1;
			island[ damage_square.get_x() ][ damage_square.get_y() ] = 2;
			
			//system("CLS");
		cout<< "Score co-ordinates " << score_square.get_x() << " " << score_square.get_y() << endl;
		cout<< "Damage co-ordinates " << damage_square.get_x() << " " << damage_square.get_y() << endl;
		cout<< "Your current position of x = " << player_current_x << " and y = " << player_current_y << endl;
		cout<< "The players current health is " << player_hitpoints << " with a score of " << player_score << endl;
		cout<< "" << endl;
		
		}
		
		else if( island[ player_current_x ][ player_current_y ] == 2 )
		{
			//Damage the player
			player_hitpoints --;	//Player takes damage 
			cout<< "You took one point of damage, you have " << player_hitpoints << " left" << endl;
		}
		
		else
		{
			;
		}
		
		//Player hitpoint evaluation
		switch( player_hitpoints )
		{
			case 0:
				cout<< "You have died" << endl;
				flag = false;
				
				break;
				
			default:
				break;
		}
		
		if (_getch() != 0)
		{
			key_press = _getch(); // need to include conio.h
			ascii_value = key_press;
			//cout << ascii_value << endl; You can use this for testing
			switch (ascii_value)
			{
				case 72://integer value for the UP key
				player_current_x --;
				break;
				
				case 80://integer value for DOWN key
				player_current_x ++;
				break;
				
				case 77:// integer value for the RIGHT key
				player_current_y ++;
				break;
				
				case 75:// integer value for the LEFT key
				player_current_y --;
				break;
				
				default:
				cout<< "Terminating game input" << endl;
				flag = false;
				break;
			}
		}
		
		//Player hints 
		if( player_current_x == score_square.get_x() )
		{
			cout<< "Getting warmer" << endl;
		}
		
		else if( player_current_y == score_square.get_y() )
		{
			cout<< "Getting closer" << endl;
		}
		
		else
		{
			;
		}
		
		//Used to correct the position if they are out of bounds.
		player_current_x = checkBoundries( player_current_x, XSIZE, XMIN );
		player_current_y = checkBoundries( player_current_y, YSIZE, YMIN );
		
		/* Here is where we clear the screen */
		//system("CLS");
		cout<< "Score co-ordinates " << score_square.get_x() << " " << score_square.get_y() << endl;
		cout<< "Damage co-ordinates " << damage_square.get_x() << " " << damage_square.get_y() << endl;
		cout<< "Your current position of x = " << player_current_x << " and y = " << player_current_y << endl;
		cout<< "The players current health is " << player_hitpoints << " with a score of " << player_score << endl;
		cout<< "" << endl;
	}
	
	cout << "Thank you for playing Island Adventures, you had a score of" << player_score << endl;
}