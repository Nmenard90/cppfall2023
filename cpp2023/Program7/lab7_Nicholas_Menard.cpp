#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <iomanip>
using namespace std;

/*********************************************************************/
/* Nicholas Menard
/* Lab 7 Solution                                                    
/* This program Manage a collection of CDs, allowing users to add, edit, and delete CDs,
/* manage tracks, and perform various operations on the CD collection. It also includes
/* a math break menu with various games
/*********************************************************************/            


// Forward declaration
class CD;

// Function prototypes
void displayTracks(CD& cd);
void editTracks(CD& cd);
void addTracks(CD& cd);
void deleteAllTracks(CD& cd);
bool findCDRecursive(CD cds[], int size, string artist, string title);
void stringReverseMenu();
void reverseString(string str, int pos);



// class declaration
class CD
{
	private:
		string artist;
		string title;
		int yearReleased;
		int numTracks;
    	string* tracks; // pointer to an array of strings

	public:
		CD();
		CD(string, string, int);
		~CD(); // Destructor to free dynamically allocated memory
		void setArtist(string);
		void setTitle(string);
		void setYearReleased(int);
		void setNumTracks(int);
		void setTrackName(int, string);
		string getArtist();
		string getTitle();
		int getYearReleased();
		int getNumTracks();
		void deleteTracks(); // Function to delete tracks array
	    string getTrackName(int index);
		
};

CD::CD()
{
    // Default constructor
    artist = "";
    title = "";
    yearReleased = 0;
    numTracks = 0;
    tracks = nullptr; // Initialize the pointer to nullptr
}


CD::CD(string a, string b, int c)
{
    artist = a;
    title = b;
    yearReleased = c;
    numTracks = 0;
    tracks = nullptr;
}

CD::~CD()
{
    // Destructor
    deleteTracks(); // Free memory before object is destroyed
}
 

//mutators
void CD::setArtist(string a)
{artist = a;}
void CD::setTitle(string b)
{title = b;}
void CD::setYearReleased(int c)
{yearReleased = c;}
void CD::setNumTracks(int numberOfTracks)
{
    numTracks = numberOfTracks;
    tracks = new string[numTracks]; // Allocate memory for the tracks array
}
void CD::setTrackName(int index, string trackName)
{
    if (index >= 0 && index < numTracks)
        tracks[index] = trackName;
}

//accesors
string CD::getArtist()
{return artist;}
string CD::getTitle()
{return title;}
int CD::getYearReleased()
{return yearReleased;}
int CD::getNumTracks() { return numTracks; }
string CD::getTrackName(int index)
{
    if (index >= 0 && index < numTracks)
        return tracks[index];
    else
        return ""; // Return an empty string for invalid index
}
void CD::deleteTracks()
{
    if (tracks != nullptr)
    {
        delete[] tracks; // Free the dynamically allocated memory
        tracks = nullptr; // Set the pointer to nullptr after deletion
        numTracks = 0;
    }
}

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
void addTracksMenu(CD findaCD[], int count);
void deleteAllTracks(CD allCDs[], int count);
void findCDRecursiveMenu(CD findaCD[], int count);
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

    while (option != 10)
    {
        switch (option)
        {
        case 1:
            numCDs = readCD(collection);
            isFileRead = true; // Set the flag to true
            cout << numCDs << " CDs have been read." << endl;
            break;
        case 2:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                displayCollection(collection, numCDs);
            }
            break;
        case 3:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                sortcd(collection, numCDs);
                displayCollection(collection, numCDs);
            }
            break;
        case 4:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                findcd(collection, numCDs);
            }
            break;
        case 5:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                findCDRecursiveMenu(collection, numCDs);
            }
            break;
        case 6:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                editACD(collection, numCDs);
            }
            break;
        case 7:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                addTracksMenu(collection, numCDs);
            }
            break;
        case 8:
            if (!isFileRead)
            {
                cout << "Please read the collection first (Option 1) before using other options." << endl;
            }
            else
            {
                deleteAllTracks(collection, numCDs);
            }
            break;
        case 9:
            mathBreakMenu();
            break;
        }
        option = mainMenuOption();
    }
    return 0;
}
/**************************************************/
/* Function:   mainMenuOption                                       
/* Inputs:     None
/* Outputs:    int - User's menu choice
/* Purpose:    Display the main menu and get user input       
/**************************************************/
 
int mainMenuOption()
{
    int choice;
    cout << "\nMain Menu:" << endl;
    cout << "1. Read Collection " << endl;
    cout << "2. Display Collection" << endl;
    cout << "3. Sort Collection" << endl;
    cout << "4. Find a CD " << endl;
    cout << "5. Find A CD *recursive Version* " << endl;
    cout << "6. Edit a CD" << endl;
    cout << "7. Add tracks for a CD" << endl;
    cout << "8. Delete all Tracks for a CD " << endl;
    cout << "9. Math Break Menu " << endl;
    cout << "10. Quit " << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;

    while (choice < 1 || choice > 9)
    {
        cout << "Invalid option please try again" << endl;
        cout << "Enter Option" << endl;
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

	while (number != 4)
	{
		switch (number)
		{
			case 1:
				evenOdd();
				break;
			case 2:
				primeNumber();
				break;
			case 3:
				stringReverseMenu();
				break;
				
		}
		number = getMathBreakOption();
	}
}
/**************************************************/
/* Function:   findCDRecursiveMenu                                      
/* Inputs:     findaCD - an array of CD objects
               count - the number of CDs in the collection
/* Outputs:    None
/* Purpose:    Display a menu to prompt the user to enter an artist and title,
               then call the findCDRecursive function to search for the CD in the collection
               using a recursive algorithm. Display whether the CD is found or not.       
/**************************************************/

void findCDRecursiveMenu(CD findaCD[], int count)
{
    string artist, title;
    
    cin.ignore(100, '\n');
    cout << "Enter artist: ";
    getline(cin, artist);

    cout << "Enter title: ";
    getline(cin, title);
	// Call the findCDRecursive function to search for the CD in the collection
    bool found = findCDRecursive(findaCD, count, artist, title);

    if (found)
    {
        cout << "CD found in the collection!" << endl;
    }
    else
    {
        cout << "CD not found in the collection." << endl;
    }
}

/**************************************************/
/* Function:   findCDRecursive                                     
/* Inputs:     cds - Array of CDs
               size - Number of CDs in the collection
               artist - Artist name to find
               title - Title to find
/* Outputs:    bool - True if the CD is found, false otherwise
/* Purpose:    Recursive function to find a specific CD in the collection       
/**************************************************/

bool findCDRecursive(CD cds[], int size, string artist, string title)
{
    // Base case: If the size is 0, the CD is not found
    if (size == 0)
        return false;

    // Check if the current CD matches the specified artist and title
    if (cds[size - 1].getArtist() == artist && cds[size - 1].getTitle() == title)
        return true;

    // Recursive case: Search in the remaining CDs
    return findCDRecursive(cds, size - 1, artist, title);
}

/**************************************************/
/* Function:   stringReverseMenu                                       
/* Inputs:     None
/* Outputs:    None
/* Purpose:   Display a menu to prompt the user to enter a string,
               then call the reverseString function to reverse the entered string
               and display the reversed string.        
/**************************************************/

void stringReverseMenu()
{
    string userString;

    cout << "Enter a string to reverse: ";
    cin.ignore();
    getline(cin, userString); // Get the entire line, including spaces


    cout << "Reversed string: ";
    
    // Call the reverseString function with the entered string and its length
    reverseString(userString, userString.length() - 1); 
    cout << endl;
}

/**************************************************/
/* Function:   reverseString                                       
/* Inputs:     str - String to reverse
               pos - Current position in the string
/* Outputs:    None
/* Purpose:    Recursive function to reverse a string and print it       
/**************************************************/

void reverseString(string str, int pos)
{
    if (pos >= 0) // Base case: If the current position is not negative, continue the reversal
    {
        cout << str[pos];// // Print the character at the current position in reverse order
        reverseString(str, pos - 1); // // Recursive call: Move to the next position in reverse order
    }
    // The recursion will continue until the base case is reached (pos < 0)
}

/**************************************************/
/* Function:   addTracksMenu                                       
/* Inputs:     findaCD - Array of CDs
/*             count - Number of CDs in the collection
/* Outputs:    None
/* Purpose:    Display menu for adding tracks to a CD       
/**************************************************/

void addTracksMenu(CD findaCD[], int count)
{
    string artist, title;
    int i;
    bool found = false;

    cin.ignore(100, '\n');
    cout << "What artist would you like to add tracks for? " << endl;
    getline(cin, artist);
    
    cout << "What title would you like to add tracks for? " << endl;
    getline(cin, title);

	 // Search for the CD in the collection based on artist and title
    i = 0;
    while (i < count && !(title == findaCD[i].getTitle() && artist == findaCD[i].getArtist()))
    {
        i++;
    }

    if (i < count)
    {
        addTracks(findaCD[i]);  // Call the addTracks function for the found CD
        cout << "Tracks added for CD: " << title << " by " << artist << endl;
    }
    else
    {
        cout << "CD with title \"" << title << "\" by artist \"" << artist << "\" is not in the collection" << endl;
    }
    // The function does not directly modify the CD object array but may indirectly modify CD objects if addTracks is called
}


/**************************************************/
/* Function:   addTracks                                       
/* Inputs:     cd - CD object
/* Outputs:    None
/* Purpose:    Add tracks to a specific CD       
/**************************************************/

void addTracks(CD& cd)
{
    int numTracks;
    cout << "Enter the number of tracks: ";
    cin >> numTracks; // get number of tracks from user

    cd.setNumTracks(numTracks); // set number based on user input

    for (int i = 0; i < numTracks; ++i)
    {
        string trackName;
        cout << "Enter track #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, trackName);
        cd.setTrackName(i, trackName);
    }
}

/**************************************************/
/* Function:   displayTracks                                       
/* Inputs:     cd - CD object
/* Outputs:    None
/* Purpose:    Display the tracks of a CD       
/**************************************************/

void displayTracks(CD& cd)
{
    if (cd.getNumTracks() > 0)
    {
        cout << "Tracks:" << endl;
        for (int i = 0; i < cd.getNumTracks(); ++i)
        {
            cout << setw(5) << i + 1 << ". " << cd.getTrackName(i) << endl;
        }
    }
    else
    {
        cout << "No tracks available for this CD." << endl;
    }
}

/**************************************************/
/* Function:   editTracks                                       
/* Inputs:     cd - Reference to a CD object
/* Outputs:    None
/* Purpose:    Modify the tracks of a CD by updating the number of tracks
               and setting the names for each track based on user input       
/**************************************************/

void editTracks(CD& cd)
{
    int numTracks;
    cout << "Enter the number of tracks: ";
    cin >> numTracks;

    cd.setNumTracks(numTracks); // Update the number of tracks for the CD


    for (int i = 0; i < numTracks; ++i) // Loop to set the names for each track based on user input
    {
        string trackName; // Declare a variable to store the track name
        cout << "Enter track #" << i + 1 << ": ";
        cin.ignore();
        getline(cin, trackName); // Get the entire line as the track name (allows spaces)
        cd.setTrackName(i, trackName); // Set the track name for the current index in the CD object
    }
}

/**************************************************/
/* Function:   deleteAllTracks                                       
/* Inputs:     allCDs - Array of CD objects
               count - Number of CD objects in the array
/* Outputs:    None
/* Purpose:    Delete all tracks for a specific CD based on user input of artist
               and title. Displays appropriate messages if the CD is found or not.       
/**************************************************/


void deleteAllTracks(CD allCDs[], int count)
{
    string artist, title;
    int i = 0;
    bool found = false;

    cin.ignore(100, '\n');
    cout << "Enter the artist of the CD you want to delete tracks for: ";
    getline(cin, artist);

    cout << "Enter the title of the CD you want to delete tracks for: ";
    getline(cin, title);

    // Find the CD in the collection based on artist, title, and the presence of tracks
    while (i < count && !(artist == allCDs[i].getArtist() && title == allCDs[i].getTitle() && allCDs[i].getNumTracks() > 0))
    {
        i++;
    }

    if (i < count) // Check if the CD was found
    {
        found = true;
        allCDs[i].deleteTracks(); // Delete all tracks for the found CD
        cout << "All tracks deleted for CD: " << title << " by " << artist << endl;
    }

    if (!found) // Display a message if the CD was not found or has no tracks
    {
        cout << "CD with artist \"" << artist << "\" and title \"" << title << "\" not found or has no tracks." << endl;
    }
}

/**************************************************/
/* Function:   getMathBreakOption                                       
/* Inputs:     None
/* Outputs:    int - User's math break menu choice
/* Purpose:    Display the math break menu and get user input       
/**************************************************/

int getMathBreakOption()
{
	int choice;
	
	//display the math break menu
	cout << "\nMath Break Menu:" << endl;
    cout << "1. Even or Odd" << endl;
    cout << "2. Prime Number" << endl;
    cout << "3. String reverse" << endl;
    cout << "4. End my Math Break" << endl;
    cout << "Enter your choice: "<< endl;
    
	// input from user
    cin >> choice;
	
	// Validate input if validated pass
	// if not ask for another option
	while (choice < 1 || choice > 4)
	{
		cout <<"Invalid choice. Please enter a number 1-4." << endl;
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
/* Function:   isEven                                       
/* Inputs:     num - Integer number
/* Outputs:    bool - True if the number is even, false otherwise
/* Purpose:    Check if a number is even       
/**************************************************/

bool isEven(int num)
{
	// return the value if it 
	//divides evenly
	return num%2==0;

}
/**************************************************/
/* Function:   primeNumber                                       
/* Inputs:     None
/* Outputs:    None
/* Purpose:    Math break menu option for prime number game       
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
/* Function:   readCD                                       
/* Inputs:     readCollection - Array of CDs
/* Outputs:    Number of CDs read from the file
/* Purpose:    Read CDs from a file and populate the collection       
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
/* Function:   displayCollection                                       
/* Inputs:     readCollection - Array of CDs
/*             count - Number of CDs in the collection
/* Outputs:    None
/* Purpose:    Display the collection of CDs with their tracks       
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
		 displayTracks(readCollection[i]);
	}
}
/**************************************************/
/* Function:   sortcd                                       
/* Inputs:     allCDs - Array of CDs
/*             count - Number of CDs in the collection
/* Outputs:    None
/* Purpose:    Sort the CD collection alphabetically       
/**************************************************/
void sortcd(CD allCDs[], int count)
{
	bool swapped = true;
	int last;
	CD temp;
	
	while(swapped)
	{
		swapped = false;
		for(int i=0, last=count-1; i<last; i++)
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
/* Inputs:     findaCD - Array of CDs
/*             count - Number of CDs in the collection
/* Outputs:    None
/* Purpose:    Find a specific CD in the collection       
/**************************************************/

void findcd(CD findaCD[], int &count)
{
	string artist, title;
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
/* Function:   editACD                                       
/* Inputs:     findaCD - Array of CDs
/*             count - Number of CDs in the collection
/* Outputs:    None
/* Purpose:    Edit information for a specific CD       
/**************************************************/

void editACD(CD findaCD[], int count)
{
	string artist, title;
	int i ;
	bool found = false;  // initialize variable to false 
	
	 cin.ignore(100, '\n');
    cout << "What is the artist of the album you want to edit? " << endl;
    getline(cin, artist);
    
	cin.ignore(100,'\n');
	cout << "what is the title of the album you want to edit? " << endl;
	getline(cin,title);
	
	
	
	i = 0; // start index at 0
	 while (i < count && !(title == findaCD[i].getTitle() && artist == findaCD[i].getArtist())) // Make sure the title and artist match
	{
		if (title == findaCD[i].getTitle()) // if title entereed matches whats stored in object set flag to true
				found = true;
		else 
				i++; // if the above conditions arent met continu
	}
	 if (i < count)// if flag becomes true call 
	{
		editOneCD(&findaCD[i]); // take  the "i-th" element in the array and point to it. Using below function
								// modify data stored in that element of the array.
		cout << title << " by " << artist << " has been edited\n";
	}
	else 
			cout << title << " by " << artist << " is not in the collection" << endl; // if title and artist isnt in the collection throw error
			
			
}
/**************************************************/
/* Function:   editOneCD                                       
/* Inputs:     oneCD - Pointer to a CD object
/* Outputs:    None
/* Purpose:    Edit information for a specific CD       
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
