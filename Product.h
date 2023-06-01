#pragma once
#define NAME_LEN 30

class Product
{
public:

	char* name;
	int quantity = -1;
	double price = -1;
	int name_len_filled = 0;
	const int name_len = NAME_LEN; //A half solution, not gonna do for a real project. A vector-type name is probably needed

	int LexicographicallyCompareNames(const Product&); //Both return 0 if the first is greater, 1 if the second is greater and -1 if they're equal
	int LexicographicallyCompareNames(char* myname); //Link?

	Product();
	~Product();
	Product(const Product& op2);

	Product& operator =(const Product& op2);
};
