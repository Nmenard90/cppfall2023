

#include <iostream>
using namespace std;

*********************************************************************/
/* Nicholas Menard
/* Lab 1 Solution                                                    
/* This program has a main menu and a submenu. When the user inputs a 1 the program will take them to a submenu that has two games. One is an even and odd
/* game and one is a prime number game.
/* when the user exits a game it will take them back to the sub menu
/* when the user exits the maain menu the program will terminate
                            
/*********************************************************************/ 

// Function prototypes
void mainMenu(); // protoype for the main menu function. It will display the menu options and ask for interger input
void subMenu(); // prototype for submenu function. If the user inputs 1 into the main menu main will call the submenu function to display the game options 
void evenOrOdd(); // function prototype for the even or odd game. continues to loop until the user selects 0 to exit the loop and leave the game
void isPrime();  // logical function prototype for prime number arithmetic. I'm not great at math but it seems to work.

.
/********************************************************************/
/* Function:   main                                     
/* Inputs:       1 or 2                                      
/* Outputs:      sub menu or exit
/* Purpose:    This function asks for input and leads the user to the submenu or exits the program         
/********************************************************************/
int main()
{
    int choice;
	do
	{
		mainMenu();
		cin >> choice;
		
		
		switch(choice)
		{
			case 1:
				subMenu();
				break;
			case 2: 
				cout << "Goodbye" << endl;
				break;
			default:
				cout << "Invalid choice please enter a 1 or a 2. " << endl;
				break;
		}
	}
	while (choice !=2);
	return 0;
			
}
	

/********************************************************************/
/* Function:  mainMenu                                       
/* Inputs:     none                                           
/* Outputs:    no return values                     
/* Purpose:    This function just displays the main menu         
/********************************************************************/
void mainMenu()
{
    cout << "Main Menu:" << endl;
    cout << "1. Math Break" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter your choice: ";
    
    
}

/********************************************************************/
/* Function:   subMenu                                      
/* Inputs:       choice, number choice leads to each game depending on what choice the user makes
/* 				number is the number the user inputs once theyre in either game                                          
/* Outputs:   The game menus or exit back to main menu                  
/* Purpose:    This is the submenu function. It takes the user to a game depending on thier choice
/*				Once they are in the menu it will run the functions of each game until the user exits      
/********************************************************************/
void subMenu()
{
    int choice,number;
    do
    {
	
    cout << "\nMath Break Menu:" << endl;
    cout << "1. Even or Odd" << endl;
    cout << "2. Prime Number" << endl;
    cout << "3. End my Math Break" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
        case 1:
        	
            evenOrOdd();
            break;
        case 2:
            isPrime();
            break;
           case 3:
           continue; // will go back to main menu  
        default:
            cout << "Invalid choice. Please enter 1, 2, or 3." << endl;
            break;
    }
	}while (choice!=3);
	
}

/********************************************************************/
/* Function:   isprime                                      
/* Inputs:       num ,prime: number is the number that the user enters that we want to check 
/*				prime is the boolean logic if a number is prime  it will set the variable to true or false
/* Outputs:    returns the number and if the number is prime or nott                     
/* Purpose:    this funtion takes a number input and displays if it is prime or not until the user selects 0 to leave the game.        
/********************************************************************/ 
void isPrime()
{ 
   int num;
   bool prime;
   // input validation for making sure number is positive 
   do{
   	// display message
   	cout << "enter an interger(press 0 to quit.\n";
   	// ask for input
   	cin >> num;
   	if (num < 0)
   	{
   		cout << "please enter a positive number.\n";
   		prime = false;
   	}
   	else if (num > 0)
   	{
   		prime = true;
   		if (num <=1)
   		prime = false;
   		else
   		{
   			for (int i = 2;i * i<= num && prime; i++)
   			{
   				if (num % i == 0)
   				{
   					prime = false;
				}
			}
		}
   		if(prime)
   		cout << num << " is prime.\n";
   		else
   		cout << num << " is not prime.\n";
   		
	}
	
	}while (num != 0);
   
}

/********************************************************************/
/* Function:   evenOrOdd                                       
/* Inputs:       num asks a user for a number                 
/* Outputs:    returns a number and if that number is even or odd                     
/* Purpose:    this function uses interger division to see if a number is even or odd
/********************************************************************/
void evenOrOdd() 
{
int num;
// input validation for the number being greater than 0
	do
	{
    	do
		{
        	cout<<"Enter any number greater than 0.\nEnter 0 to go back.\n";
        	cin>>num;
		
	
		}
	while (num < 0);
if (num%2==0)
    cout <<num<<" is even.\n";
else
    cout<<num<<" is odd.\n";

	}
	while (num!=0);
    
}