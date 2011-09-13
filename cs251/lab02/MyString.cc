// CS251 Data Structures
// String Implementation

// IMPORTANT: See the MyString.h file for a description of
// what each method needs to do.

#include <stdio.h>
#include <string.h>
#include "MyString.h"

// My own implementation of strlen
int
MyString::slength(const char *s) const
{
    int count;
    count = 0;
    
    while (*s++)
    {
        count++;
    }
    
    return count;
}

// Initialize _s. Allocate memory for _s and copy s into _s
void
MyString::initialize(const char * s)
{
    int size;
    size = slength(s) + 1;
    
    _s = new char[size];
    
    strcpy(_s, s);
}

// Create a MyString from a C string
MyString::MyString(const char * s)
{
    initialize(s);
}

// Create a MyString from a copy of another string
MyString::MyString(const MyString &s)
{
    initialize(s._s);
}

// Create a MyString with an empty string
MyString::MyString()
{
    _s = new char[1];
    *_s = 0;
}

// Assignment operator. Without this operator the assignment is
// just a shallow copy that will copy the pointer _s. If the original _s
// goes away then the assigned _s will be a dangling reference.
MyString &
MyString::operator = (const MyString & other) {
    if (this != &other) // protect against invalid self-assignment
    {
        delete [] _s;

        initialize(other._s);

        return *this;
    }
}

// Obtain a substring of at most n chars starting at location i
// if i is larger than the length of the string return an empty string.
MyString
MyString::substring(int i, int n)
{
    if (i > length())
    {
        return MyString();
    }
    
    char *_sub;
    _sub = new char[n + 1];
    
    int j;
    for (j = 0; j < n; j++)
    {
        _sub[j] = _s[i+j];
    }
    
    _sub[n] = '\0';

    MyString sub;
    sub = MyString(_sub);
    
    return sub;
}

// Remove at most n chars starting at location i
void
MyString::remove(int i, int n)
{
    if (i > length())
    {
        return;
    }
    
    if (i + n > length())
    {
        return;
    }
    
    int c;
    for (c = 0; c < n; c++)
    {
    	int j;
    	for (j = i; j < length() - 1; j++)
    	{
    	    _s[j] = _s[j + 1];
    	}
    }
    
    _s[length() - n] = '\0';

    return;
}

// Return true if strings "this" and s are equal
bool
MyString::operator == (const MyString & s)
{
    int i;
    i = 0;
    
    while ((_s[i] != '\0' && s._s[i] != '\0') &&
           (_s[i] == s._s[i]))
    {
        i++;
    }
    
    return ((_s[i] - s._s[i]) == 0);
}


// Return true if strings "this" and s are not equal
bool
MyString::operator != (const MyString &s)
{
    int i;
    i = 0;
    
    while ((_s[i] != '\0' && s._s[i] != '\0') &&
           (_s[i] == s._s[i]))
    {
        i++;
    }
    
    return ((_s[i] - s._s[i]) != 0);
}

// Return true if string "this" and s is less or equal
bool
MyString::operator <= (const MyString &s)
{
    int i;
    i = 0;
    
    while ((_s[i] != '\0' && s._s[i] != '\0') &&
           (_s[i] == s._s[i]))
    {
        i++;
    }
    
    return ((_s[i] - s._s[i]) <= 0);
}

// Return true if string "this" is greater than s
bool
MyString::operator > (const MyString &s)
{
    int i;
    i = 0;
    
    while ((_s[i] != '\0' && s._s[i] != '\0') &&
           (_s[i] == s._s[i]))
    {
        i++;
    }
    
    return ((_s[i] - s._s[i]) > 0);
}

// Return character at position i.  Return '\0' if out of bounds.
char
MyString::operator [] (int i)
{
    if (i > length())
    {
    	return '\0';
    }
    
    char *ret = new char();
    ret = _s+i;
    
    return *ret;
}

// Return C representation of string
const char *
MyString::cStr()
{
    return _s;
}

// Get string length of this string.
int
MyString::length() const
{
    return slength(_s);
}

// Destructor. Deallocate the space used by _s
MyString::~MyString()
{
    delete [] _s;
}

// Concatanate two strings (non member method)
MyString operator + (const MyString &s1, const MyString &s2)
{
    MyString s;
    delete s._s;
    
    int size;
    size = s1.length() + s2.length() + 1;
    
    s._s = new char[size];
    
    strcpy(s._s, s1._s);
    strcpy(s._s + s1.length(), s2._s);
    
    return s;
}

