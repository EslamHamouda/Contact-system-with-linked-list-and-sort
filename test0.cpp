#include <iostream>
#include <conio.h>
#include <algorithm>
using namespace std;
struct contact {
	string fname;
	string lname;
	string phone;
	string address;
	string email;
	contact* next;
};
contact* head=NULL;

void InsertContactFront(string fname, string lname, string phone, string address, string email)
{
	contact* newnode = new contact;
	newnode->fname = fname;
	newnode->lname = lname;
	newnode->phone = phone;
	newnode->address = address;
	newnode->email = email;
	newnode->next = head;
	head = newnode;
}


void InsertContactBack(string fname, string lname, string phone, string address, string email)
{
	contact* newnode = new contact;
	newnode->fname = fname;
	newnode->lname = lname;
	newnode->phone = phone;
	newnode->address = address;
	newnode->email = email;
	newnode->next = NULL;
	if (head == NULL)
	{
		head = newnode;
	}
	else
	{
		contact* back = head;
		while (back->next != NULL)
		{
			back = back->next;
		}
		back->next = newnode;
	}
}


void insertContactPosition(string fname, string lname, string phone, string address, string email, int position0)
{
	contact* newnode = new contact;
	contact* position = head;
	newnode->fname = fname;
	newnode->lname = lname;
	newnode->phone = phone;
	newnode->address = address;
	newnode->email = email;
	for (int i = 1; i <= position0 - 1; i++)
	{
		position = position->next;
	}
	newnode->next = position->next;
	position->next = newnode;
}


void DeleteFirstContact()
{
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
	}
	else
	{
		contact* temp = head;
		head = head->next;
		delete temp;
	}
}


void DeleteLastContact()
{
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
	}
	else
	{
		contact* temp = head->next;
		contact* end = head;
		while (temp->next != NULL)
		{
			end = temp;
			temp = temp->next;
		}
		delete temp;
		end->next = NULL;
	}
}

void DeleteContactPosition(int position0)
{
	contact* position = head;
	contact* temp = head;
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
	}
	for (int i = 1; i <= position0 - 1; i++)
	{
		position = position->next;
	}
	temp = position;
	position = position->next;
	temp->next = position->next;
	delete position;
}


void SearchContactByName(string fname, string lname)
{
	contact* temp = head;
	while (temp != NULL)
	{
		if (temp->fname == fname||temp->lname==lname)
		{
			cout << "-------------------------------------------------------" << endl;
			cout << temp->fname << "\n" << temp->lname << "\n" << temp->phone << "\n" << temp->address << "\n" << temp->email << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		temp = temp->next;
		
	}
}


void SearchContactByNumber(string phone)
{
	contact* temp = head;
	while (temp != NULL)
	{
		if (temp->phone==phone)
		{
			cout << "-------------------------------------------------------" << endl;
			cout << temp->fname << "\n" << temp->lname << "\n" << temp->phone << "\n" << temp->address << "\n" << temp->email << endl;
			cout << "-------------------------------------------------------" << endl;
		}
		temp = temp->next;

	}
}


void DisplayContact(int position0)
{
	contact* position = head;
	for (int i = 1; i <= position0 - 1; i++)
	{
		position = position->next;
	}
	cout << "-------------------------------------------------------" << endl;
	cout << position->fname << "\n" << position->lname << "\n" << position->phone << "\n" << position->address << "\n" << position->email << endl;
	cout << "-------------------------------------------------------" << endl;
}

void UpdateContact(string fname, string lname, string phone, string address, string email, int position)
{
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
	}
	else
	{
		contact* temp = head;
		for (int i = 1; i < position; i++)
		{
			temp = temp->next;
		}
		temp->fname = fname;
		temp->lname = lname;
		temp->phone = phone;
		temp->address = address;
		temp->email = email;
	}
}



void DisplayAllContact()
{
	cout << 
		
		"----------------------------------------------------------" << endl;
	if (head == NULL)
	{
		cout << "Linked List is empty" << endl;
		cout << "----------------------------------------------------------" << endl;
	}
	contact* temp = head;
	while (temp != NULL)
	{
		cout << temp->fname << "\n" <<temp->lname<<"\n"<<temp->phone<<"\n"<<temp->address<<"\n"<<temp->email<< endl;
		cout << "----------------------------------------------------------" << endl;
		temp = temp->next;
	}
}

void sorted()
{
	struct contact* temp = head;
	struct contact* temp1;
	while (temp != NULL)
	{
		temp1 = temp->next;
		while (temp1 != NULL)
		{
			string str1 = temp->fname;
			string str2 = temp1->fname;
			transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
			transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
			if (str1 > str2)
			{
				string st = temp->fname;
				temp->fname = temp1->fname;
				temp1->fname = st;

				string st2 = temp->lname;
				temp->lname = temp1->lname;
				temp1->lname = st;

				string st3 = temp->phone;
				temp->phone = temp1->phone;
				temp1->phone = st;

				string st4 = temp->address;
				temp->address = temp1->address;
				temp1->address = st;


				string st5 = temp->email;
				temp->email = temp1->email;
				temp1->email = st;
			}
			temp1 = temp1->next;
		}
		temp = temp->next;
	}
}

int main()
{
	do
	{
		int n;
		string fname, lname, phone, address, email;
		int search;

		cout << "\n";
		cout << "Select an option by number :" << "\n\n";
		cout << "1 ) add Contact to begining of list" << endl;
		cout << "2 ) add Contact to end of list" << endl;
		cout << "3 ) add Contact in any position" << endl;
		cout << "4 ) delete Contact from begining of list" << endl;
		cout << "5 ) delete Contact from end of list" << endl;
		cout << "6 ) delete Contact in any position" << endl;
		cout << "7 ) find specific contact by searching based on first name and last name" << endl;
		cout << "8 ) find specific contact by searching based on phone number" << endl;
		cout << "9 ) display specific contact by searching" << endl;
		cout << "10 ) update contact" << endl;
		cout << "11 ) show all of contacts" << endl;
		cout << "0 ) enter zero to exit" << endl;
		cout << "   select : ";
		cin >> n;
		switch (n) {

		case 1:

			cout << "please enter first name , last name , phone , address , email :" << endl << " :==> ";
			cin >> fname >> lname >> phone >> address >> email;
			InsertContactFront(fname, lname, phone, address, email);
			cout << "done :D" << endl;

			break;

		case 2:

			cout << "please enter first name , last name , phone , address , email :" << endl << " :==>  ";
			cin >> fname >> lname >> phone >> address >> email;
			InsertContactBack(fname, lname, phone, address, email);
			cout << "done :D" << endl;

			break;


		case 3:

			cout << "\n please enter number of position :" << endl << " :==>  ";
			cin >> search;
			cout << "\n please enter first name , last name , phone , address , email :" << endl << " :==>  ";
			cin >> fname >> lname >> phone >> address >> email;
			insertContactPosition(fname, lname, phone, address, email, search);

			break;

		case 4:
			DeleteFirstContact();
			cout << "\n=== deleted successful ===== \n" << endl;

			break;

		case 5:
			DeleteLastContact();
			cout << "\n=== deleted successful ===== \n" << endl;

			break;

		case 6:
			cout << "\n please enter number of position :" << endl << " :==>  ";
			cin >> search;
			DeleteContactPosition(search);
			cout << "\n=== deleted successful ===== \n" << endl;
			break;

		case 7:

			cout << "=== searching by first name and last name ===== \n" << endl << "enter first name and last name :==>";
			cin >> fname>>lname;
			SearchContactByName(fname, lname);

			break;

		case 8:

			cout << "=== searching by phone number ===== \n" << endl << "enter phone number :==>";
			cin >> phone;
			SearchContactByNumber(phone);

			break;


		case 9:


			cout << "=== enter position of contact to display it ===== \n" << endl << "enter position :==>";
			cin >> search;
			DisplayContact(search);

			break;

		case 10:

			cout << "=== enter position of contact to update it ===== \n" << endl << "enter position :==>";
			cin >> search;
			cout << "\n please enter first name , last name , phone , address , email :" << endl << " :==>  ";
			cin>> fname >> lname >> phone >> address >> email;
			UpdateContact(fname, lname, phone, address, email, search);

			break;

		case 11:

			cout << "\n=== all contacts in list ===\n" << endl;
			sorted();
			DisplayAllContact();

			break;

		case 0:
		
			system("CLS");
			break;
		}

	} while (true);
	

	
}