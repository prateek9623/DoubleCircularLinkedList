#include"DoubleCircularLinkedList.h"

int main() {
	int ch;
	DoubleCircularLinkedList dcll;
	do {
		system("cls");
		cout << "1.Insert by position"<<endl;
		cout << "2.Insert by value"<<endl;
		cout << "3.Delete by value" << endl;
		cout << "4.Find the Middle element" << endl;
		cout << "5.Search any value" << endl;
		cout << "6.Check if is palindrome or not" << endl;
		cout << "7.Reverse" << endl;
		cout << "8.Display" << endl;
		cout << "9.Exit" << endl;
		cout << "Enter your choice..." << endl;
		cin >> ch;
		switch (ch)
		{
		case 1:
		{
			int val, pos;
			cout << "Enter value and at what position you wanna insert..";
			cin >> val >> pos;
			if(dcll.insertByPos(pos, val))
				cout<<"Insert Successfull";
			else
				cout << "Insert Unsuccessfull";
		}
		break;
		case 2: {
			int val;
			cout << "Enter value you want to insert";
			cin >> val;
			 if(dcll.insertByVal( val))
				cout << "Value Inserted";
			else
				cout << "Value Not Inserted";
		}			
		break;
		case 3: {
			int val;
			cout << "Enter Value to be deleted";
			cin >> val;
			if (dcll.deleteByVal(val))
				cout << "Value Deleted";
			else
				cout << "Value not Found";
		}
		break;
		case 4:
			cout << "Middle value of List is::" << dcll.findMiddle();
			break;
		case 5:
		{
			int val;
			cout << "Enter Value to be searched::";
			cin >> val;
			if (dcll.searchByVal(val))
				cout << "Value Found";
			else
				cout << "Value not found";
		}
		break;
		case 6:
			if (dcll.checkPalindrome())
				cout << "List is Palindrome";
			else
				cout << "List is not a Palindrome";
			break;
		case 7:
			if (dcll.reverse()) {
				cout << "List Reversed"<<endl;
				dcll.display();
			}
			else {
				cout << "List is Empty or having a single Value";
			}
			break;
		case 8:
			dcll.display();
			break;
		case 9:
			cout << "Thank you";
			break;
		default:
			cout << "Invalid choice";
			break;
		}
		_getwch();
	} while (ch != 9);

	return 0;
}