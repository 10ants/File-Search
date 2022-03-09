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

    while (myFile!= "XXXX") // while quit is not wanted
    {
        ofstream output;

        output.open(myFile);
      
        cout << "Enter text: "; // Enter text to be added to file
        string text;
   
        cin.ignore(); // flush buffer
        std::getline(std::cin, text);
       
        output << text << endl;; // inputting new text to file
        output.close();

        cout << "Enter the forbidden word: ";
        string forbidden;
        cin >> forbidden;
        fstream editedString;
      
        editedString.open(myFile); // reading file
        if (editedString.is_open()) {//if the file is open
            string temp;
            
            while (getline(editedString, temp)) 
            {
                stringstream stream(temp);
                
                while (stream.good()) 
                {
                    string newString;
                    getline(stream, newString, ' ');
                    
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
