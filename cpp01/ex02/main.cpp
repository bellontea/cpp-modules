#include <iostream>

int main()
{
	std::string stringVAR("HI THIS IS BRAIN");
	std::string *stringPTR = &stringVAR;
	std::string &stringREF = stringVAR;

	std::cout << "stringVAR memory = " << &stringVAR << std::endl;
	std::cout << "stringPTR memory = " << stringPTR << std::endl;
	std::cout << "stringREF memory = " << &stringREF << std::endl;

	std::cout << "stringVAR value = " << stringVAR << std::endl;
	std::cout << "stringPTR value = " << *stringPTR << std::endl;
	std::cout << "stringREF value = " << stringREF << std::endl;
}