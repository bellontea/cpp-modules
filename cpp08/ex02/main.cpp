#include "MutantStack.hpp"
#include <iostream>
#include <stack>
#include <list>

int main(int argc, char** argv)
{

	(void)argc;
	(void)argv;

	/*** Subject tests ***/

	{MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);}

	std::cout << std::endl;

{	std::list<int> mstack;
	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;
	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);
	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}}

	/*** My tests ***/

	// MutantStack<std::string> args;

	// for (int i = 1; i < argc; i++)
	// 	args.push(argv[i]);

	// {
	// std::cout << "iterator test" << std::endl;
	// MutantStack<std::string>::iterator it = args.begin();
	// MutantStack<std::string>::iterator ite = args.end();
	// ++it;
	// --it;
	// while (it != ite) 
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// }

	// {
	// std::cout << "reverse_iterator test" << std::endl;
	// MutantStack<std::string>::reverse_iterator it = args.rbegin();
	// MutantStack<std::string>::reverse_iterator ite = args.rend();
	// ++it;
	// --it;
	// while (it != ite) 
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// }

	// {
	// std::cout << "const_iterator test" << std::endl;
	// MutantStack<std::string>::const_iterator it = args.cbegin();
	// MutantStack<std::string>::const_iterator ite = args.cend();
	// ++it;
	// --it;
	// while (it != ite) 
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// }

	// {
	// std::cout << "const_reverse_iterator test" << std::endl;
	// MutantStack<std::string>::const_reverse_iterator it = args.crbegin();
	// MutantStack<std::string>::const_reverse_iterator ite = args.crend();
	// ++it;
	// --it;
	// while (it != ite) 
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	// }

	/*** Copy constructor and operator= ***/

	// MutantStack<int> stack1;
	// stack1.push(1);
	// stack1.push(2);
	// stack1.push(3);
	// MutantStack<int> stack2 = stack1;
	// MutantStack<int>::iterator it = stack2.begin();
	// MutantStack<int>::iterator ite = stack2.end();

	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	
	// MutantStack<int> stack3;
	// stack1.push(3);

	// stack3 = stack2;

	// it = stack3.begin();
	// ite = stack3.end();

	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }

	return 0;
}