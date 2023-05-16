#pragma once
#define NAME_LEN 30

class Product
{
public:

	char* name;
	int quantity = -1;
	double price = -1;
	int name_len_filled = 0;

	int LexicographicallyCompareNames(const Product&);
	int LexicographicallyCompareNames(char* myname); //Link?

	Product();
	//~Product();

	Product& operator =(const Product& op2);

	const int name_len = NAME_LEN; //A half solution, not gonna do for a real project. A vector-type name is probably needed
};

