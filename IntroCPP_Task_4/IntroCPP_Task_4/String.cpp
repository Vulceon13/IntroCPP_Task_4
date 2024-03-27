#include "String.h"
#include <iostream>
using namespace std;

// Constructor Function
String::String()
{
    m_length = 0;
    m_string = new char[static_cast<unsigned int>(m_length) + 1];
    m_string[0] = '\0';
}

// C-Style Version of the Constructor Function
String::String(const char* _str)
{
    m_length = strlen(_str);
    m_string = new char[static_cast<unsigned int>(m_length) + 1];
    strncpy_s(m_string, static_cast<unsigned int>(m_length) + 1, _str, _TRUNCATE);
}

// Copy Constructor Funcotion 
String::String(const String& _other)
{
    m_length = _other.m_length;
    m_string = new char[static_cast<unsigned int>(m_length) + 1];
    strncpy_s(m_string, static_cast<unsigned int>(m_length) + 1, _other.m_string, _TRUNCATE);
}

// Destructor Function
String::~String()
{
    delete[] m_string;
}

// Function to Find the Length of a String
size_t String::Length() const
{
    return m_length;
}

// Gives Access to Characters at a Given Index 
char& String::CharacterAt(size_t _index)
{
    if (_index < m_length)
        return m_string[_index];
    else
        throw std::out_of_range("Index out of range");
}

// This is a Const Version of The Code Above
const char& String::CharacterAt(size_t _index) const
{
    if (_index < m_length)
        return m_string[_index];
    else
        throw std::out_of_range("Index out of range");
}

// Checks if 2 Strings are Equal to each other
bool String::EqualTo(const String& _other) const
{
    return strcmp(m_string, _other.m_string) == 0;
}

// Adding a string to another string
String& String::Append(const String& _str)
{
    char* new_string = new char[m_length + _str.m_length + 1];
    strncpy_s(new_string, m_length + 1, m_string, _TRUNCATE);
    strncat_s(new_string, m_length + _str.m_length + 1, _str.m_string, _TRUNCATE);

    delete[] m_string;
    m_string = new_string;
    m_length += _str.m_length;

    return *this;
}

// Adding a string to the beginning of another string 
String& String::Prepend(const String& _str)
{
    char* new_string = new char[m_length + _str.m_length + 1];
    strncpy_s(new_string, _str.m_length + 1, _str.m_string, _TRUNCATE);
    strncat_s(new_string, m_length + _str.m_length + 1, m_string, _TRUNCATE);
    m_string[m_length] = '\0';

    delete[] m_string;
    m_string = new_string;
    m_length += _str.m_length;

    return *this;
}

// Converts string to a C-Style String
const char* String::CStr() const
{
    return m_string;
}

// Converts the string to all lowercase
String& String::ToLower()
{
    for (size_t i = 0; i < m_length; ++i)
        m_string[i] = tolower(m_string[i]);

    return *this;
}

// Converts the string to all uppercase
String& String::ToUpper()
{
    for (size_t i = 0; i < m_length; ++i)
        m_string[i] = toupper(m_string[i]);

    return *this;
}

// Function to find a substring
size_t String::Find(const String& _str)
{
    for (size_t i = 0; i <= m_length - _str.m_length; ++i)
    {
        if (strncmp(m_string + i, _str.m_string, _str.m_length) == 0)
            return i;
    }
    return npos;
}

// Function to find a substring with a given index
size_t String::Find(size_t _startIndex, const String& _str)
{
    if (_startIndex >= m_length || _str.m_length > m_length - _startIndex) // Checking if the start index is valid and the substring can fit in the remaining string
        return npos;

    for (size_t i = _startIndex; i <= m_length - _str.m_length; ++i)
    {
        if (strncmp(m_string + i, _str.m_string, _str.m_length) == 0)
        {
            cout << "Match found at index: " << i << endl;
            return i;
        }
        cout << "No match at index: " << i << ". Checking next index." << endl;
    }
    cout << "No match found." << endl;
    return npos;
}

// Function to replace one substring with another string 
String& String::Replace(const String& _find, const String& _replace)
{
    size_t pos = Find(_find);
    while (pos != npos)
    {
        // Remove the substring to be replaced
        memmove(m_string + pos, m_string + pos + _find.m_length, m_length - pos - _find.m_length + 1);
        m_length -= _find.m_length;

        // Insert the new string
        char* new_string = new char[m_length + _replace.m_length + 1];
        memcpy(new_string, m_string, pos);
        strncpy_s(new_string + pos, _replace.m_length + 1, _replace.m_string, _replace.m_length);
        strncpy_s(new_string + pos + _replace.m_length, m_length - pos + 1, m_string + pos, m_length - pos);

        delete[] m_string;
        m_string = new_string;
        m_length += _replace.m_length;

        pos = Find(pos + _replace.m_length, _find);
    }

    return *this;
}

// Function to read the console
String& String::ReadFromConsole()
{
    char buffer[4096];
    cin.getline(buffer, sizeof(buffer));
    *this = buffer;
    return *this;
}

// Function to wrtie to the console
String& String::WriteToConsole()
{
    cout << m_string;
    return *this;
}


// Checks if string starts with a specified prefix
bool String::StartsWith(const char* prefix) const
{
    size_t prefixLength = strlen(prefix);
    if (prefixLength > m_length)
        return false;
    return strncmp(m_string, prefix, prefixLength) == 0;
}

// Get a subString of a string  starting from a specified index
String String::SubString(size_t start) const 
{
    if (start >= m_length)
        return String(); 

    return String(m_string + start); 
}

// Trim leading and trailing whitespaces from the string
String& String::Trim() {
    size_t start = 0;
    while (start < m_length && std::isspace(m_string[start])) {
        start++;
    }

    size_t end = m_length - 1;
    while (end > start && std::isspace(m_string[end])) {
        end--;
    }

    m_length = end - start + 1;
    memmove(m_string, m_string + start, m_length);
    m_string[m_length] = '\0';

    return *this;
}

bool String::operator!=(const String& _other)
{
    return !EqualTo(_other);
}


String& String::operator=(const String& _str)
{
    if (this != &_str)
    {
        delete[] m_string;
        m_length = _str.m_length;
        m_string = new char[m_length + 1];
        strncpy_s(m_string, m_length + 1, _str.m_string, _TRUNCATE);
    }
    return *this;
}


char& String::operator[](size_t _index)
{
    return CharacterAt(_index);
}


const char& String::operator[](size_t _index) const
{
    return CharacterAt(_index);
}

std::ostream& operator<<(std::ostream& os, const String& str) 
{
    os << str.CStr();  // This defines the << operator for String class
    return os;
}


bool operator==(const String& str1, const String& str2) 
{
    return str1.EqualTo(str2); // This defines the == operator for String class 
}