#pragma once
#include <iostream>

class String
{
public:
	String();
	String(const char* _str);

	String(const String& _other);

	~String();

public:
	size_t Length() const;
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;

	bool EqualTo(const String& _other) const;

	String& Append(const String& _str);
	String& Prepend(const String& _str);

	const char* CStr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& _str);
	size_t Find(size_t _startIndex, const String& _str);

	String& Replace(const String& _find, const String& _replace);

	String& ReadFromConsole();
	String& WriteToConsole();

	bool StartsWith(const char* prefix) const;
	String SubString(size_t start) const;

	String& Trim();

public:
	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	String& operator=(const String& _str);

	char& operator[](size_t _index);
	const char& operator[](size_t _index) const;

	friend std::ostream& operator<<(std::ostream& os, const String& str);
	friend bool operator==(const String& str1, const String& str2);

private:
	//Put your internal data structures and members here
	unsigned int m_length;
	char* m_string;
	static const size_t npos = -1;
};

