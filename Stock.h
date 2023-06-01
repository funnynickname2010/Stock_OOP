#pragma once
#include "Product.h"
#include <iostream>
#include <fstream>
#include <iomanip>



#define SETW_PARAM 15
#define STOCK_CAPACITY 5
#define FILE_NAME_STOCK "stock_data.txt"

using namespace std;

class Stock
{
public:

	int size_allocated; //How many elements it can contain without additional memory allocation
	int size_filled; //How many elements it currently contains
	string file_name;
	bool is_a_bucket;

	Product* stock_array; //= new Product[size_allocated];

	void ChangeQuantity(int index, int delta);
	void AddNewProduct(Product myProduct);  //Doesn't consider array's length
	void RemoveProduct(int index);
	int Search(char* myname);

	int DownloadFromFile();
	bool UploadToFile();

	void CheckOut(); //Used only in Stock bucketStock

	Stock();
	~Stock();
};
