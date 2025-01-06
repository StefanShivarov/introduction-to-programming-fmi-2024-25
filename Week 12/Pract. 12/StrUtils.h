#pragma once
/*
* This is a header file. It contains code that does not have a main function (is built and compiled but not run)
* It can be linked to other files
* This header file contains the utility functions for working with char arrays that we have discussed
* during practicums and seminars and lectures
*/

const size_t MAX_ARRAY_SIZE = 100;

//counts the length of an array without the \0
unsigned myStrLen(const char* arr)
{
	if (arr == nullptr || (*arr) == '\0') //array is not initialised or is empty
		return 0;

	unsigned length = 0;
	while (*arr)
	{
		length++;
		arr++;
	}

	return length;
}

//note - not safe! We assume that the dest has enough space for the entirety of src
void myStrCpy(char* dest, const char* src)
{
	if (dest == nullptr || src == nullptr)
		return; //unitialised arrays
	if (*src == '\0')
		return; //nothing to copy

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	*dest = '\0'; //don't forget the /0!
}

void myStrCat(char* dest, const char* src)
{
	if (dest == nullptr || src == nullptr)
		return; //unilitialised arrays
	if (*src == '\0')
		return; //nothing to concatenate

	//find the end of the dest array
	while (*dest)
	{
		dest++;
	}

	//copy the src into the end of the dest
	myStrCpy(dest, src);
	//myStrCpy takes care of adding the \0 at the end
}
