#include "Stock.h"
#include "Product.h"
#include <fstream>
#define NAME_MAIN_LN 30

#define FILE_NAME_BUCKET "bucket_data.txt"

int UserInterface();
Product Product_input(Stock& mystock);
void Product_print(const Product& myProduct);
void NameGetter(char*& op, int ln);

int main()
{
	Stock myStock;
	Stock myBucket;
	myBucket.file_name = FILE_NAME_BUCKET;

	if (myStock.DownloadFromFile() == 0)
	{
		cout << "Error downloading from the file stock." << endl;
	}

	if (myBucket.DownloadFromFile() == 0)
	{
		cout << "Error downloading from the file bucket." << endl;
	}

	int first_boot = 1;

	if (first_boot == 1)
	{
		int switch_option = UserInterface();

		do
		{
			char* temp_name = new char[NAME_MAIN_LN];
			int index_of_the_element_in_the_array;


			switch (switch_option)
			{
				cout << endl;

			case 1:

				myStock.AddNewProduct(Product_input(myStock));
				break;

			case 2:

				cout << "Product's name: ";

				NameGetter(temp_name, NAME_MAIN_LN);

				if (myStock.Search(temp_name) != -1)
				{
					Product_print(myStock.stock_array[myStock.Search(temp_name)]);  //More checking
				}


				break;

			case 3:

				cout << endl << "Product's name: ";

				NameGetter(temp_name, NAME_MAIN_LN);

				int number;

				cout << "Quantity: ";
				cin >> number;

				index_of_the_element_in_the_array = myStock.Search(temp_name);

				if (index_of_the_element_in_the_array == -1)
				{
					cout << endl << "No such product in stock" << endl;
				}
				else if (number > myStock.stock_array[index_of_the_element_in_the_array].quantity)
				{
					cout << endl << "There's only " << myStock.stock_array[index_of_the_element_in_the_array].quantity << " items in stock, do you want to add them all? 1 - yes, 0 - no " << endl;
					int answ;
					cin >> answ;
					if (answ == 1)
					{
						if (myBucket.size_filled < myBucket.size_allocated)
						{
							myBucket.AddNewProduct(myStock.stock_array[index_of_the_element_in_the_array]);
							myBucket.stock_array[myBucket.Search(temp_name)].quantity = myStock.stock_array[index_of_the_element_in_the_array].quantity;
							myStock.ChangeQuantity(index_of_the_element_in_the_array, -myStock.stock_array[index_of_the_element_in_the_array].quantity);
						}
						else
						{
							std::cout << "No free space in the bucket." << std::endl;
						}
					}
					else
					{
						break;
					}
				}
				else if (myBucket.Search(temp_name) == -1) //If we don't already have the chosen element in the bucket
				{
					if (myBucket.size_filled < myBucket.size_allocated)
					{
						myBucket.AddNewProduct(myStock.stock_array[index_of_the_element_in_the_array]);
						myBucket.stock_array[myBucket.Search(temp_name)].quantity = number;
						myStock.ChangeQuantity(index_of_the_element_in_the_array, -number);
					}
					else
					{
						std::cout << "No free space in the bucket." << std::endl;
					}
				}
				else if (myBucket.Search(temp_name) != -1) //If we already have the chosen element in the bucket in some quantity
				{
					myBucket.stock_array[myBucket.Search(temp_name)].quantity += number;
					myStock.ChangeQuantity(index_of_the_element_in_the_array, -number);
				}
				break;


			case 4:

				cout << "Product's name: " << endl;

				NameGetter(temp_name, NAME_MAIN_LN);

				index_of_the_element_in_the_array = myStock.Search(temp_name);

				if (index_of_the_element_in_the_array != -1)
				{
					int delta;

					cout << "Delat: ";
					cin >> delta;

					if (delta < 0 && -delta > myStock.stock_array[index_of_the_element_in_the_array].quantity)
					{
						cout << endl << "Delta is negative and is greater than the number of items in stock." << endl;
					}
					else
					{
						myStock.ChangeQuantity(index_of_the_element_in_the_array, delta);
					}
				}
				else
				{
					cout << endl << "No such element in stock" << endl;
				}

				break;

			case 5:

				cout << "Product's name: " << endl;

				NameGetter(temp_name, NAME_MAIN_LN);

				index_of_the_element_in_the_array = myBucket.Search(temp_name);

				if (index_of_the_element_in_the_array != -1)
				{
					int delta;

					cout << "Delta: ";
					cin >> delta;

					if (delta < 0 && -delta > myBucket.stock_array[index_of_the_element_in_the_array].quantity)
					{
						cout << endl << "Delta is negative and is greater than the number of items in the bucket." << endl;
					}
					else
					{
						myBucket.ChangeQuantity(index_of_the_element_in_the_array, delta);
					}
					break;
				}
				else
				{
					cout << endl << "No such element in stock" << endl;
				}

				break;

			case 6:

				cout << endl << "Product's name: ";

				NameGetter(temp_name, NAME_MAIN_LN);

				index_of_the_element_in_the_array = myBucket.Search(temp_name);

				if (index_of_the_element_in_the_array != -1)
				{
					myBucket.RemoveProduct(index_of_the_element_in_the_array);
				}
				else
				{
					cout << endl << "No such product in the bucket." << endl;
				}


				break;

			case 7:

				cout << endl << "Product's name: ";


				NameGetter(temp_name, NAME_MAIN_LN);

				index_of_the_element_in_the_array = myStock.Search(temp_name);

				if (index_of_the_element_in_the_array != -1)
				{
					myStock.RemoveProduct(index_of_the_element_in_the_array);

					if (myBucket.Search(temp_name) != -1) //Remove the product from the bucket too
					{
						myBucket.RemoveProduct(index_of_the_element_in_the_array);
					}
				}
				else
				{
					cout << endl << "No such product in stock." << endl;
				}


				break;

			case 8:

				myBucket.CheckOut();



				break;

			case 9:

				myBucket.size_filled = 0; //�������
				break;

			case 10:

				return 0;

			case 11:

				myStock.CheckOut();
				break;
			}

			cout << endl << "Option: ";
			std::cin.ignore(INT_MAX, '\n');
			cin >> switch_option;
			delete[] temp_name;

		} while (switch_option != 10);
	}

	if (myStock.UploadToFile() == 0)
	{
		cout << "Error uploading to the file stock." << endl;
	}

	if (myBucket.UploadToFile() == 0)
	{
		cout << "Error uploading to the file bucket." << endl;
	}
}

int UserInterface()
{
	cout << "--------------INTERFACE---------------" << endl;
	cout << " Options: " << endl;
	cout << "1. Append a product to the stock" << endl;
	cout << "2. Product's data" << endl;
	cout << "3. Add a product to the bucket" << endl;
	cout << "4. Change quantity of a product in stock" << endl;
	cout << "5. Change quantity of a product in the bucket" << endl;
	cout << "6. Delete a product from the bucket" << endl;
	cout << "7. Delete a product from the stock" << endl;
	cout << "8. Checkout" << endl;
	cout << "9. Clear bucket" << endl;
	cout << "10. Exit" << endl;
	cout << "11. Debug.Stock Checkout" << endl;

	int res;
	cin >> res;

	return res;
}

void NameGetter(char*& op, int ln)
{
	cin.ignore();
	cin.get(op, ln);
}

Product Product_input(Stock& mystock)
{
	Product myProduct;


	//Inputting name

	char* service_name_array = new char[myProduct.name_len];

	cout << "Input name: ";

	cin.ignore();
	cin.get(service_name_array, myProduct.name_len);

	int i = 0;
	while (service_name_array[i - 1] != '\0') //Really it's valid data
	{
		myProduct.name[i] = service_name_array[i];

		if (myProduct.name[i] == '\0')
		{
			myProduct.name_len_filled = i;
		}

		i++;
	}

	delete[] service_name_array;

	if (mystock.size_allocated < mystock.size_filled)
	{

		//Inputting price and quantity

		do
		{
			cout << "Input price: ";
			cin >> myProduct.price;
		} while (myProduct.price <= 0);

		do
		{
			cout << "Input quantity: ";
			cin >> myProduct.quantity;
		} while (myProduct.quantity <= 0);

		cout << endl;
	}
	else if ((mystock.Search(myProduct.name) != -1))
	{
		do
		{
			cout << "Input quantity: ";
			cin >> myProduct.quantity;
		} while (myProduct.quantity <= 0);

		cout << endl;
	}

	return myProduct;
}

void Product_print(const Product& myProduct)
{
	int i = 0;
	cout << endl << "name" << setw(SETW_PARAM) << "price" << setw(SETW_PARAM) << "quantity" << endl;

	while ((myProduct.name[i] != '\0') && (i < myProduct.name_len))
	{
		cout << myProduct.name[i];
		i++;
	}

	cout << setw(SETW_PARAM) << myProduct.price << setw(SETW_PARAM) << myProduct.quantity << endl;
}