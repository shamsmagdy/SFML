#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void main()
{

  string playerName;
  
        int nScore = 65;
      string currentPlayer;
   
        ifstream inFile;
    
        ofstream outFile;
   
        outFile.open("draft.txt");
 
        cout << "  Game Over!! ";
    
        cout << "\nPlease enter your name: ";
    
        getline(cin, playerName);
    
        cout << "\n";
    
        cout << playerName << "! You Scored: " << nScore << "pts" << endl;
   
        cout << " --------- Top Scores--------------\n";
    

        outFile << playerName << "\t" << nScore;
   
        outFile.close();
   
        inFile.open("draft.txt");
   
        if (inFile.is_open())
           
            cout << inFile.rdbuf();
  
        inFile.close();
    
        outFile.close();

}