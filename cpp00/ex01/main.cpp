#include "PhoneBook.hpp"

void add(PhoneBook &book)
{
	Contact new_contact = Contact();
	std::string input;

	for (size_t i = 0; i < FIELD_SIZE; i++)
	{
		std::cout << "Enter " << Contact::get_field_name(i) << ": ";
		std::getline(std::cin, input);
		if (input == "")
		{
			i--;
			std::cout << "Incorrect input\n";
		}
		else
			new_contact.set_field(Contact::get_field_name(i), input);
	}
	
	book.AddContact(new_contact);
}

void search(PhoneBook &book)
{
	std::cout << "*********************************************\n";
	std::cout << "****************MY PHONEBOOK*****************\n";
	std::cout << "*********************************************\n";

	std::cout << "|     INDEX|FIRST NAME| LAST NAME| NICK NAME|\n";
	std::cout << "*********************************************\n";
	std::cout << "|          |          |          |          |\n";

	Contact contact;
	std::string field;
	for (size_t i = 0; i < CONTACTS_SIZE; i++)
	{
		contact = book.GetContact(i);
		if (contact.get_field("firstname") == "")
			break;
		
		std::cout << "|";
		std::cout.width(10);
		std::cout << i + 1;

		for (size_t j = 0; j < 3; j++)
		{
			std::cout << "|";
			field = contact.get_field(Contact::get_field_name(j));
			std::cout.width(10);
			if (field.size() > 10)
				std::cout << field.substr(0, 9) + ".";
			else
				std::cout << field;
		}
		std::cout << "|\n";
	}

	std::cout.width(10);
	std::cout << "|          |          |          |          |\n";
	std::cout << "*********************************************\n";

	if (book.GetContact(0).get_field("firstname") == "")
		return;

	int index;
	std::cout << "Enter index of contact for more information > ";
	while (!(std::cin >> index) || book.GetContact(index - 1).get_field("firstname").empty())
	{
		std::cin.clear();
		std::cin.ignore(INT32_MAX, '\n');
		std::cout << "Invalid index, enter again: ";
	}
	std::cin.ignore(INT32_MAX, '\n');
	book.GetContact(index - 1).print_contact();
}

int main()
{
	std::string command;
	PhoneBook book;

	while (true)
	{
		std::cout << "Enter command > ";
		std::getline(std::cin, command);
		if (command == "ADD")
			add(book);
		else if (command == "SEARCH")
			search(book);
		else if (command == "EXIT")
			return (0);
	}
	
}