#include <iostream>
#include <string>
#include "book.h"
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <sstream>
#include <chrono> //NOLINT (build/c++11)

using namespace std;

std::vector<book> readFile(string infile);
void writeFile(string outfile, std::vector<book> output);

char getUserChoice();
void createFile(int found, string fileName);

int linearSearch(std::vector<book> list, std::vector<book> requests);
int binarySearch(std::vector<book> list, std::vector<book> requests);

int main(int argc, char *argv[])
{

    if(argc < 4)
    {
        std::cerr << "Usage: .SearchNewBooks <newBooks.dat> <requests.dat> <result_file.dat>\n";

        return 0;
    }



    std::vector<book> newBooks;
    std::vector<book> requests;

    newBooks = readFile(argv[1]);
    requests = readFile(argv[2]);
    int found;

    char userChoice;
    bool done = false;

    cout << "Choice of search method ([l]inear, [b]inary)?" << endl;
    userChoice = getUserChoice();

    std::sort(newBooks.begin(), newBooks.end());

    std::chrono::high_resolution_clock::time_point start;
    start = std::chrono::high_resolution_clock::now();
    

    while (!done)
    {
        switch (userChoice) 
        {

            case 'l':
                found = linearSearch(newBooks, requests);
                done = true;
                break;
            case 'b':
                found = binarySearch(newBooks, requests);
                done = true;
                break;
            default:
                std::cerr << "Incorrect choice" << endl;
                userChoice = getUserChoice();
        }

    }

    auto end = std::chrono::high_resolution_clock::now();
    double elapsed_us = std::chrono::duration<double, std::micro>(end - start).count();
    std::cout << "CPU time: " << elapsed_us << " microseconds" << endl;

    createFile(found, argv[3]);

    return 0;
}



void createFile(int found, string fileName)
{
    ofstream myFile;
    myFile.open(fileName);
    myFile << found;
    myFile.close();

}




int binarySearch(std::vector<book> list, std::vector<book> requests)
{

    
    int count = 0;

    int middle;
    

    for(unsigned int i = 0; i < requests.size(); i++)
    {
        int low = 0;
        int high = list.size();

        while (high - low > 1)
        {
            middle = (low+high)/2;

            if(list[middle] < requests[i])
            {
                low = middle+1;
            }
            else
            {
                high = middle;
            }
            
        }
        if (list[low] == requests[i] || list[high] == requests[i]) 
        {
            count++;
        }

    }
    //cout << count << endl;

    return count;
}




int linearSearch(std::vector<book> list, std::vector<book> requests)
{
    bool counted = false;
    int count = 0;
    for (unsigned int i=0; i < requests.size(); i++ )
    {
        counted = false;
        for (unsigned int j = 0; j < list.size(); j++)
        {
            if (requests[i] == list[j] && !counted)
            {
                count++;
                counted = true;
                
            }
        }
    }

    //cout << count << endl;
    return count;
}


char getUserChoice()
{
    char input;
    cin >> input;
    return input;

}


std::vector<book> readFile(string infile)
{
    std::vector<book> input (0);
    int i = 0;
    book tempBook;
    string newline, tempString;

    ifstream myfile (infile);

    if (!myfile.is_open())
    {
        std::cerr << "Error: connot open file " << infile << endl;
        return input;
    }

    while (getline (myfile, newline) )
    {
        stringstream ss(newline);
        getline(ss, tempString, ',');
        tempBook.ISBN = stoi(tempString);
        getline(ss, tempBook.bookName, ',');
        getline(ss, tempBook.bookType, ',');
        input.push_back(tempBook);
        i++;
    }

    myfile.close();


    return input;

}