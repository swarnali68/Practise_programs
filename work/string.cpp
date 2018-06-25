#include<iostream>
#include<string.h>

using namespace std;

class String
{
	private:
		char* str;
		int len;

	public:
		String();  //Default Constructor
		String(const char* str);  //Paramterised Constructor
		String(const String& cobj); //copy constructor
		String& operator=(const String& aobj); //Assignment operator
};

String::String()
{
	str = '\0';
}

String::String(const char* str)
{
	len = strlen(str);
	this->str = new char[len];
	//strcpy(str, "Hi");
	//str = "Hi";
	strcpy(this->str, str);
}

String::String(const String& cobj)
{
	cout<<"In copy";
	len = strlen(cobj.str);
	str = new char(len);
	strcpy(str, cobj.str);
}

String& String::operator=(const String& aobj)
{
	cout<<"In assignment";
	if(this != &aobj)
	{
		len = strlen(str);
		str = new char(len);
		strcpy(str,aobj.str);
	}
	return *this;
}

int main()
{
	String s1;
	String s2("Hello");
	String s3 = s2;
	//s1 = s3;	
	return 0;
}
