#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string myFile = "";
    cout << "Enter the name of the file you would like to access, or enter XXXX to quit:";
    cin >> myFile;

    while (myFile!= "XXXX") // While not quit
    {
        ofstream output;

        output.open(myFile); // Opening file asked for 
      
        cout << "Enter text: "; //Gathering user input for file
        string NewText;
   
        cin.ignore(); // flush buffer
        std::getline(std::cin, NewText);
       
        output << NewText << endl;; // inputting new text to file
        output.close(); // Closing file

        cout << "Enter the forbidden word: ";
        string forbidden;
        cin >> forbidden;
        fstream editedString; // creating edited string that will be outputted
      
        editedString.open(myFile); // openning filed asked for, with new string
        if (editedString.is_open()) {//if the file is open
            string tString;
            
            while (getline(editedString, tString)) 
            {
                stringstream stream(tString);
                
                while (stream.good()) 
                {
                    string newString;
                    getline(tString, newString, ' ');
                    
                    if (newString.compare(forbidden) != 0)
                        cout << newString << " ";
                }
                cout << endl;
            }
            editedString.close();
        }
        cout << "Enter the name of the file you would like to access, or enter XXXX to quit:";
        cin >> myFile;
    }

    return 0;
}
