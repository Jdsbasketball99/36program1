#include <string>
#include "book.h"

using namespace std;




bool book::operator==(const book& right)
{
    if (ISBN == right.ISBN && bookName == right.bookName && bookType == right.bookType)
    {
        return true;
    }
    else
    {
        return false;
    }
    

}


bool book::operator<(const book& right)
{
    if (ISBN != right.ISBN)
    {
        return (ISBN < right.ISBN);
    }
    else if(bookName != right.bookName)
    {
        if (bookName < right.bookName)
        {
            return false;
        }
        else 
        {
            return true;
        }
        
    }
    else
    {
        if (bookType == "new" && right.bookType != "new")
        {
            return true;
        }
        else if (bookType != "new" && right.bookType == "new")
        {
            return false;
        }
        else if (bookType == "digital" && right.bookType != "digital")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    

}
