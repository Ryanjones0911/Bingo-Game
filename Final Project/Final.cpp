#include <iostream>	
#include <iomanip>	//used to set width
#include <cstdlib>
#include <ctime>	//used for time to generate random number
using namespace std;


int* getArray1();	//prototype of function getArray1 function will return an int value which will be int square1
int* getArray2();	//prototype of function getArray2 function will return an int value which will be int square2
bool checkwinner(int[]);	//prototype function for checkwinner, checks both cards(square1 and square2) to see if there is a match for a bingo
void getlayout(int* nums, int player);	//prototype function for getlayout to show the layout of the cards.


int main()
{
	string game; //to keep game running
	int* p1; //pointer to array for player 1
	int* p2; //pointer to array for player 2
	bool p1win; //check win conditions for player 1
	bool p2win; // check win conditions for player 2
	srand(time(0)); //random seed

	//asks user for numbers & stores the arrays
	p1 = getArray1();
	p2 = getArray2();

	//generates card layout based on numbers in each players array
	getlayout(p1, 1);
	getlayout(p2, 2);

	while (game != "quit")
	{
		//generate & display current number drawn
		int randomNum = rand() % 30 + 10;
		cout << "The number is: " << randomNum << endl;

		//check p1 & p2 against num & sets matching board spaces to 0
		for (int i = 0; i < 24; i++)
			if (p1[i] == randomNum)
			{
				p1[i] = 0;
			}
		for (int j = 0; j < 24; j++)
			if (p2[j] == randomNum)
			{
				p2[j] = 0;
			}

		//refresh game boards
		getlayout(p1, 1);
		getlayout(p2, 2);
		
		//checks if either player has won based on conditions set in checkwinner function, & if so displays congratulations message and ends the game
		p1win = checkwinner(p1);
		p2win = checkwinner(p2);
		if (p1win && p2win)
		{
			cout << "Both players win\n";
			return 0;
		}
		if (p1win)
		{
			cout << "Player 1 wins\n";
			return 0;
		}
		if (p2win)
		{
			cout << "Player 2 wins\n";
			return 0;
		}

		//if no player has won this round, prompts user to press any key to draw another number or enter 'quit' to end the game prematurely
		cout << "Press any key to continue (type 'quit' to quit): " << endl;
		cin >> game;
	}
}


int* getArray1()		//function to ask user to enter values in for square 1
{
	int* input = new int[24];

	cout << "Player 1, enter 24 unique numbers between 10 and 40: \n";

	for (int i = 0; i < 25; i++)
	{
		cin >> input[i];


		//range check
		while (input[i] > 40 || input[i] < 10)
		{
			cout << "Enter number BETWEEN 10 and 40: ";
			cin >> input[i];
		}

		//duplicate check
		for (int j = 0; j < i; j++)
		{
			while (input[j] == input[i])
			{
				cout << "You've already entered that number. Please enter a UNIQUE number: ";
				cin >> input[i];
			}
		}
	}
	input[12] = 0; //sets middle of board to 0

	
	return input; //returns pointer to array*/
}

int* getArray2()		//function to ask user to enter values in for square 2
{
	int* input = new int[24];

	cout << "Player 2, enter 24 unique numbers between 10 and 40: \n";

	for (int i = 0; i < 25; i++)
	{
		cin >> input[i];


		//range check
		while (input[i] > 40 || input[i] < 10)
		{
			cout << "Enter number BETWEEN 10 and 40: ";
			cin >> input[i];
		}

		//duplicate check
		for (int j = 0; j < i; j++)
		{
			while (input[j] == input[i])
			{
				cout << "You've already entered that number. Please enter a UNIQUE number: ";
				cin >> input[i];
			}
		}
	}
	input[12] = 0; //sets middle of board to 0

	//print array

	return input; //returns pointer to array*/
}

void getlayout(int* nums, int player)	//display for bingo cards
{

	cout << setw(60) << "Board Player " << player << "\n\n"
		<< setw(70) << "B   |   I   |   N   |   G   |   O" << endl
		<< setw(72) << "____________________________________" << endl
		<< setw(39) << nums[0] << "  |   " << nums[1] << "  |   " << nums[2] << "  |   " << nums[3] << "  |   " << nums[4] << endl
		<< setw(72) << "------------------------------------" << endl
		<< setw(39) << nums[5] << "  |   " << nums[6] << "  |   " << nums[7] << "  |   " << nums[8] << "  |   " << nums[9] << endl
		<< setw(72) << "------------------------------------" << endl
		<< setw(39) << nums[10] << "  |   " << nums[11] << "  |   " << nums[12] << "   |   " << nums[13] << "  |   " << nums[14] << endl
		<< setw(72) << "------------------------------------" << endl
		<< setw(39) << nums[15] << "  |   " << nums[16] << "  |   " << nums[17] << "  |   " << nums[18] << "  |   " << nums[19] << endl
		<< setw(72) << "------------------------------------" << endl
		<< setw(39) << nums[20] << "  |   " << nums[21] << "  |   " << nums[22] << "  |   " << nums[23] << "  |   " << nums[24] << endl << "\n\n";
}

bool checkwinner(int sq1[])		//function to check if a winner is found as the random numbers is being matched to the numbers on card
{

	bool found = false;


	if (sq1[0] == 0 && sq1[1] == 0 && sq1[2] == 0 && sq1[3] == 0 && sq1[4] == 0)	//if first row is all 0s winner
		return true;
	if (sq1[5] == 0 && sq1[6] == 0 && sq1[7] == 0 && sq1[8] == 0 && sq1[9] == 0)	//if second row is all 0s winner
		return true;
	if (sq1[10] == 0 && sq1[11] == 0 && sq1[12] == 0 && sq1[13] == 0 && sq1[14] == 0)		//if third row is all 0s winner
		return true;
	if (sq1[15] == 0 && sq1[16] == 0 && sq1[17] == 0 && sq1[18] == 0 && sq1[19] == 0)		//if forth row is all 0s winner
		return true;
	if (sq1[20] == 0 && sq1[21] == 0 && sq1[22] == 0 && sq1[23] == 0 && sq1[24] == 0)		//if fifth row is all 0s winner
		return true;
	if (sq1[0] == 0 && sq1[6] == 0 && sq1[12] == 0 && sq1[18] == 0 && sq1[24] == 0)		//if diagonal left top to bottom right is all 0s winner
		return true;
	if (sq1[4] == 0 && sq1[8] == 0 && sq1[12] == 0 && sq1[16] == 0 && sq1[20] == 0)		//if diagonal left bottom to top right is 0s winner
		return true;
	if (sq1[0] == 0 && sq1[4] == 0 && sq1[20] == 0 && sq1[244] == 0)		//if all four corner numbers are 0s winner
		return true;
	if (sq1[0] == 0 && sq1[5] == 0 && sq1[10] == 0 && sq1[15] == 0 && sq1[20] == 0)		//if first column is all 0s winner
		return true;
	if (sq1[1] == 0 && sq1[6] == 0 && sq1[11] == 0 && sq1[16] == 0 && sq1[21] == 0)		//if second column is all 0s winner
		return true;
	if (sq1[2] == 0 && sq1[7] == 0 && sq1[12] == 0 && sq1[17] == 0 && sq1[22] == 0)		//if third column is all 0s winner
		return true;
	if (sq1[3] == 0 && sq1[8] == 0 && sq1[13] == 0 && sq1[18] == 0 && sq1[23] == 0)		//if forth column is all 0s winner
		return true;
	if (sq1[4] == 0 && sq1[9] == 0 && sq1[14] == 0 && sq1[19] == 0 && sq1[24] == 0)		//if fifth column is all 0s winner
		return true;
	return false;
}