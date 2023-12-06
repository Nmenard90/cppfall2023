#include <iostream>
#include <string>
#include <math.h>
using namespace std;

/*********************************************************************/
/* Nicholas Menard
/* Lab 2 Solution                                                    
/* This program tests the functionality of the cd class
/* as well as all the previous things from lab 1
/*********************************************************************/            




// class declaration
class CD
{
	private:
		string artist;
		string title;
		int yearReleased;

	public:
		CD();
		void setArtist(string);
		void setTitle(string);
		void setYearReleased(int);
		string getArtist();
		string getTitle();
		int getYearReleased();
};

CD::CD()
{
	//constructor
	// initialize attributes to null values
	artist = "";
	title = "";
	yearReleased = 0;
}

//mutators
void CD::setArtist(string a)
{artist = a;}
void CD::setTitle(string b)
{title = b;}
void CD::setYearReleased(int c)
{yearReleased = c;}

//accesors
string CD::getArtist()
{return artist;}
string CD::getTitle()
{return title;}
int CD::getYearReleased()
{return yearReleased;}

// function prototypes
int getMathBreakOption();
int mainMenuOption();
void CDTest();
void mathBreakMenu();
void evenOdd();
bool isEven(int);
bool isPrime(int);
void primeNumber();

/**************************************************/
/* Function:   main                                     
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This is the main function that  calls
/* functions functions for each menu option
/**************************************************/

int main()
{
	int option;
	// call value once itt is validated in 
	// maunmenuoption function
	option = mainMenuOption();

	while(option !=3)
	{
		switch(option)
		{
			case 1:
				CDTest();
				break;
			case 2:
				mathBreakMenu();
				break;
		}
		option = mainMenuOption();
 	} 
	return 0;
}

/**************************************************/
/* Function:   mainMenuOption                                     
/* Inputs:     none 
/* Outputs:    int. ruturns the user inputt value  once it is validated
/* Purpose:    displayes the main menu and validates input        
/**************************************************/
 
int mainMenuOption()
{
int choice;
	cout << "\nMain Menu:" << endl;
	cout << "1. Display Test CD. " << endl;
    cout << "2. Math Break" << endl;
    cout << "3. Quit" << endl;
    cout << "Enter your choice:"<<endl;
	cin  >> choice;
	
while(choice <1 || choice >3)
{
	cout << "Invalid option please try again"<< endl;
	cout << "Enter Option"<< endl;
	cin >> choice;
}
return choice;
}

/**************************************************/
/* Function: mathBreakMenu                                       
/* Inputs: none
/* Outputs:none
/* Purpose:This function sends you to each game       
/**************************************************/

void mathBreakMenu()
{
	int number;
	
	// get value from mathbreak option function
	// to make sure e have a valid input
	number = getMathBreakOption();

	while (number != 3)
	{
		switch (number)
		{
			case 1:
				evenOdd();
				break;
			case 2:
				primeNumber();
				break;
		}
		number = getMathBreakOption();
	}
}

/**************************************************/
/* Function:   getmathbreakoption                                       
/* Inputs:     none
/* Outputs:    int 
/* Purpose:    displays math break option and validates input        
/**************************************************/

int getMathBreakOption()
{
	int choice;
	
	//display the math break menu
	cout << "\nMath Break Menu:" << endl;
    cout << "1. Even or Odd" << endl;
    cout << "2. Prime Number" << endl;
    cout << "3. End my Math Break" << endl;
    cout << "Enter your choice: "<< endl;
    
	// input from user
    cin >> choice;
	
	// Validate input if validated pass
	// if not ask for another option
	while (choice < 1 || choice > 3)
	{
		cout <<"Invalid choice. Please enter 1, 2, or 3." << endl;
		cout << "Enter option: ";
		cin >> choice;
	}
	// return value in option if validated
	return choice;
}

/**************************************************/
/* Function:   evenOdd                                       
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This function displays the even or odd game
/* and validates input. If the the boolean function 
/* returns a value then it displays the value       
/**************************************************/
	
void evenOdd()
{	//initialize num variable
	int num;
	// Display even or odd menu
	cout << "Even or Odd " << endl;
	cout << "Please enter a positive interger or press 0(zero) to quit: "<<endl;
	// get input
	cin >> num;
		
	// validate input make sure number is more than 0
	// if it isnt display error message 
	// then ask for another number
	while (num < 0)
	{
		// error message for invalid input
		cout << "invalid number - the number must be 0 or greater." <<endl;
		cout << "Please enter a positive interger or press 0(zero) to quit: "<<endl;
		// ask for new number 
		cin >> num;
	}
		
	while (num != 0)
	{	// pass the number into the boolean function
		// if true display the number is even
		// if flase display th number is odd
		if (isEven(num))
		{
			cout << num << " is even." <<endl;
		}
		else
		{
			cout << num << " is odd."<<endl;
		}
		cout << "Please enter a positive interger or press 0(zero) to quit: "<<endl;
		cin >> num;
		while (num < 0)
		{
		// do the same as above but for a new value.
		// error message for invalid input
		cout << "invalid number - the number must be 0 or greater." <<endl;
		cout << "Please enter a positive interger or press 0(zero) to quit:"<<endl;
		// ask for new number 
		cin >> num;
		}
	}
		
}

/**************************************************/
/* Function:   isEven()                                    
/* Inputs:     int 
/* Outputs:    bool
/* Purpose:    This function blah, blah, blah...        
/**************************************************/

bool isEven(int num)
{
	// return the value if it 
	//divides evenly
	return num%2==0;

}
/**************************************************/
/* Function:   primeNumber()                                      
/* Inputs:     none
/* Outputs:    none
/* Purpose:    this is the function of the prime number game.
/* it tells you if a number is prime or not        
/**************************************************/
// Prime number menu selection

void primeNumber()
{
	int value;
	//display instructions 
	cout << "\nPrime Number " << endl;
	cout << "Please enter a positive interger or press 0(zero) to quit: "<< endl;
	// get valur from user input
	cin >> value;
	
	//validate input 
	while (value < 0)
	{
		// error message for invalid input
		cout << "invalid number - the number must be 0 or greater." <<endl;
		cout << "Please enter a positive interger or press 0(zero) to quit: "<<endl;
		// ask for new number 
		cin >> value;
	}
	while (value != 0)
	{
		if (isPrime(value))
		{
			cout << value << " is prime."<< endl;
			
		}
		else
		{
			cout << value << " is not prime." << endl;
		}
		cout << "Please enter a positive interger or press 0(zero) to quit: "<<endl;
		cin >> value;
		
		while (value < 0)
		{
		// do the same as above but for a new value.
		// error message for invalid input
		cout << "invalid number - the number must be 0 or greater." <<endl;
		cout << "Please enter a positive interger or press 0(zero) to quit: "<<endl;
		// ask for new number 
		cin >> value;
		}
	}
}

/**************************************************/
/* Function:   isPrime()                                     
/* Inputs:     int
/* Outputs:    bool
/* Purpose:    boolean logic function to test if a number
/*        is prime
/**************************************************/


bool isPrime(int number)
{
	//declare variables 
	//maxValue for the limiter
	// i for the control
	int maxValue, i;
	
	// Set the limit for the loop
	// Itll will be the square root of the interger
	// plus 1
	// The arithmetic is over my head but it works.
	maxValue = sqrt(number) + 1;
	
	// see of any number between 2 and the sqaure root
	// of the number divides into the number.
	// if i gets to the value of number 
	// it is prime
	// any value less that that is not prime
	for(i=2;(i < maxValue)&& (number%i); i++);
	
	// if index value is not less than the max value limit
	//return true
	return !(i<maxValue);
}

 
/**************************************************/
/* Function:   cdtest()                                       
/* Inputs:     none
/* Outputs:    none
/* Purpose:    tests the function of the cd class        
/**************************************************/ 

void CDTest()
{
	CD testCD;
	
	testCD.setArtist("Pink Floyd.");
	testCD.setTitle("The Dark Side of the Moon.");
	testCD.setYearReleased(1973);
	
	cout <<"\nThe artist name is "<< testCD.getArtist() << endl;
	cout <<"\nThe title of the album is "<< testCD.getTitle() << endl;
	cout <<"\nThe year the album was released is "<< testCD.getYearReleased() << endl;
	
}



