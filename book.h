#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;


class book
{
    public:

    int ISBN;
    string bookType;
    string bookName;


    bool operator<(const book& right);
    bool operator==(const book& right);


};

#endif