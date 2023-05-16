#include "Product.h"

Product& Product::operator =(const Product& op2)
{
	name_len_filled = op2.name_len_filled;
	quantity = op2.quantity;
	price = op2.price;

	for (int i = 0; i < name_len_filled + 1; i++)
	{
		name[i] = op2.name[i];
	}

	return *this;
}

//Product::~Product()
//{
//	delete[] name;
//}

Product::Product()
{
	name = new char[name_len];
	name_len_filled = 0;
	quantity = -1;
	price = -1;
}

int Product::LexicographicallyCompareNames(const Product& op2)
{
	int which_is_greater = -1;

	for (int i = 0; (i < name_len_filled) && (i < op2.name_len_filled); i++)
	{
		if (name[i] > op2.name[i])
		{
			which_is_greater = 0;
			break;
		}
		else if (name[i] < op2.name[i])
		{
			which_is_greater = 1;
			break;
		}
	}

	if (which_is_greater == -1)
	{
		if (name_len_filled < op2.name_len_filled)
		{
			which_is_greater = 1;
		}
		else if (name_len_filled > op2.name_len_filled)
		{
			which_is_greater = 0;
		}
	}
	
	return which_is_greater;
}

int Product::LexicographicallyCompareNames(char* myname)
{
	Product op2;

	for (int i = 0; i < name_len ; i++)
	{
		op2.name[i] = myname[i];

		if (op2.name[i] == '\0')
		{
			op2.name_len_filled = i;
			break;
		}
	}

	int which_is_greater = -1;

	for (int i = 0; (i < name_len_filled) && (i < op2.name_len_filled); i++)
	{
		if (name[i] > op2.name[i])
		{
			which_is_greater = 0;
			break;
		}
		else if (name[i] < op2.name[i])
		{
			which_is_greater = 1;
			break;
		}
	}

	if (which_is_greater == -1)
	{
		if (name_len_filled < op2.name_len_filled)
		{
			which_is_greater = 1;
		}
		else if (name_len_filled > op2.name_len_filled)
		{
			which_is_greater = 0;
		}
	}

	return which_is_greater;
}