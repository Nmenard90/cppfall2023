#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

/*********************************************************************/
/* Nicholas Menard
/* Lab 3 Solution                                                    
/* This program gives you options to read and display a collection 
/* of cds from a file and will not work until the file is read
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
		CD(string, string, int);
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

CD::CD(string a, string b, int c)
{
	artist = a;
	title = b;
	yearReleased = c;
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
int readCD(CD readCollection[]);
void mathBreakMenu();
void evenOdd();
bool isEven(int);
bool isPrime(int);
void primeNumber();
void displayCollection(CD readCollection[], int count);
void sortcd(CD allCDs[], int count);
void findcd(CD findaCD[], int &count);
void editACD(CD findaCD[], int count);
void editOneCD(CD *oneCD);
/**************************************************/
/* Function:   main                                     
/* Inputs:     none
/* Outputs:    none
/* Purpose:    This is the main function that  calls
/* functions  for each menu option none of the options will work if
/* the file is not read first
/**************************************************/
const int MAX_CDS = 28;
bool isFileRead = false;

int main()
{
    int option, numCDs;
    CD collection[MAX_CDS];

    // Main menu options
    option = mainMenuOption();

    while (option != 7) {
        switch (option) {
            case 1:
                numCDs = readCD(collection);
                isFileRead = true; // Set the flag to true
                cout << numCDs << " CDs have been read." << endl;
                break;
            case 2:
                if (!isFileRead) {
                    cout << "Please read the collection first (Option 1) before using other options." << endl;
                } else {
                    displayCollection(collection, numCDs);
                }
                break;
            case 3:
                if (!isFileRead) {
                    cout << "Please read the collection first (Option 1) before using other options." << endl;
                } else {
                    sortcd(collection, numCDs);
                     displayCollection(collection, numCDs);
                    
                }
                break;
            case 4:
                if (!isFileRead) {
                    cout << "Please read the collection first (Option 1) before using other options." << endl;
                } else {
					findcd(collection, numCDs);
                }
                break;
            case 5:
                if (!isFileRead) {
                    cout << "Please read the collection first (Option 1) before using other options." << endl;
                } else {
                    editACD(collection, numCDs);
                }
                break;
            case 6:
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
	cout << "1. Read Collection " << endl;
    cout << "2. Display Collection" << endl;
    cout << "3. Sort Collection" << endl;
    cout << "4. Find a CD " << endl;
    cout << "5. Edit a CD " << endl;
    cout << "6. Math Break " << endl;
    cout << "7. Quit " << endl;
    cout << "Enter your choice:"<<endl;
	cin  >> choice;
	
while(choice <1 || choice >7)
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
/* Outputs:    array of cds
/* Purpose:    tests the function of the cd class        
/**************************************************/ 

int readCD(CD readCollection[])
{
    ifstream CDFile;
    string artist, title;
    int yearReleased;
    int i = 0;
    CDFile.open("cd.txt");

    if (CDFile) {
        isFileRead = true; // Set the flag to true
        // Read the file and populate the CD collection
        while (getline(CDFile, artist) && (i < MAX_CDS - 1)) {
            getline(CDFile, title);
            CDFile >> yearReleased;
            CDFile.ignore();
            CD aCD(artist, title, yearReleased);
            readCollection[i] = aCD;
            i++;
        }
        CDFile.close();
    } else {
        cout << "Error: Unable to read the file." << endl;
    }

    return i;
}
/**************************************************/
/* Function:   displaycollection                                    
/* Inputs:     int count cd array
/* Outputs:    array of cds
/* Purpose:    displays the cds in format      
/**************************************************/
void displayCollection(CD readCollection[], int count)
{
	cout << "\n CD Collection" << endl;
	cout <<"\nArtist                   Title                                         Year\n";
	
	for(int i=0;i < count;i++)
	{
		cout << left << setw(25) << readCollection[i].getArtist()
		<< left << setw(30) << readCollection[i].getTitle()
		<< right << setw(20) << readCollection[i].getYearReleased() << endl;
	}
}
/**************************************************/
/* Function:   sortcd                                    
/* Inputs:     int bool
/* Outputs:    cd array and the count
/* Purpose:    This function sorts the cd collection
/**************************************************/
void sortcd(CD allCDs[], int count)
{
	bool swapped = true;
	int last;
	CD temp;
	
	while(swapped)
	{
		swapped = false;
		for(int i=0, last=count-2; i<last; i++)
		{
			if (allCDs[i].getArtist() > allCDs[i+1].getArtist())
			{
				temp = allCDs[i];
				allCDs[i] = allCDs[i+1];
				allCDs[i+1] = temp;
				swapped = true;
			}
			  
		}
		last--;
	}
}
/**************************************************/
/* Function:   findcd                                    
/* Inputs:     cd array and count
/* Outputs:    none
/* Purpose:    This function finds a cd Based on user input      
/**************************************************/

void findcd(CD findaCD[], int &count)
{
	string artist,title;
	int i ;
	bool found = false;
	
	cin.ignore(100,'\n');
	cout << "What  artist would you like to search for? " << endl;
	getline(cin,artist);
	cout << "what title would you like to search for?" << endl;
	getline(cin,title);
	
	i = 0;
	while (i<count && !found)
	{
		if (artist == findaCD[i].getArtist() && title == findaCD[i].getTitle())
				found = true;
		else 
				i++;
	}
	if (found)
	{
		cout << artist <<" " << title << " is in the collection!" << endl;
		
	}
	else 
			cout << artist << " " << title << " is not in the collection" << endl;
}
/**************************************************/
/* Function:   editcd                                    
/* Inputs:     cd array int count
/* Outputs:    none
/* Purpose:    asks for user to input the title of a CD and then searches for eleement in the array that matches   
/**************************************************/
void editACD(CD findaCD[], int count)
{
	string title;
	int i ;
	bool found = false;  // initialize variable to false 
	
	cin.ignore(100,'\n');
	cout << "what is the title of the album you want to edit? " << endl;
	getline(cin,title);
	
	
	
	i = 0; // start index at 0
	while (i<count && !found) // while index element is less then total elements in the number of cds
							 //  and boolen value is not false 
	{
		if (title == findaCD[i].getTitle()) // if title entereed matches whats stored in object set flag to true
				found = true;
		else 
				i++; // if the above conditions arent met continu
	}
	if (found) // if flag becomes true call 
	{
		editOneCD(&findaCD[i]); // take  the "i-th" element in the array and point to it. Using below function
								// modify data stored in that element of the array.
		cout << title << " has been edited\n";
	}
	else 
			cout << title << " is not in the collection" << endl; // if title isnt in the collection throw error
}
/**************************************************/
/* Function:   editone                                
/* Inputs:     class instance var oneCD 
/* Outputs:    none
/* Purpose:    edits a specicif part or each album based on what user chooses   
/**************************************************/
void editOneCD(CD *oneCD) // pointer at class memeber instance 
{
	int field;
	string artist, title;
	int yearReleased;	
	
	do
	{
		cout << "\nFields to Edit\n";
		cout << "1. Artist\n"
		     << "2. Title\n"
		     << "3. Year Released\n"
			 << "4: Done\n";
		cout << "Enter field to edit: ";
		cin >> field; 
		cin.ignore();
		
		switch (field)
		{
			case 1:
				cout << "Enter new artist: ";
				getline(cin, artist);      //get the artist name
				oneCD->setArtist(artist); // change artist if artist is chosen using pointer ref
				break;
			case 2:
				cout << "Enter new title: ";
				getline(cin, title);      // get title name from user
				oneCD->setTitle(title);   // set the new title using pointer ref
				break;
			case 3:
				cout << "Enter new  Release year: ";
				cin >> yearReleased;       // get the year released from user
				oneCD->setYearReleased(yearReleased);  // set the new title using point ref 
				break;
		}
	} while (field != 4); // validate input.
}
