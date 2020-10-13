#include <iostream>
#include <string>
#include "book.h"
#include <vector>
#include <fstream>

using namespace std;

void readFile(string inFile);


int main( string inNewBooks, string inRequests)
{


std::vector<book> newBooks;
std::vector<book> requests;




}


void readFile(string inFile, std::vector<book> input)
{

    string line;

    fstream myfile ("inFile");

    if (myfile.is_open());
    {
        while ( getline (myfile, line) )
        {
            cout << line << '\n';
        }
        myfile.close();
    }

}