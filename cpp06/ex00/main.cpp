#include <iostream>
#include <iomanip>
#include <limits>
#include <cerrno>
#include <cmath>
#include <stdint.h>

void cast_char(char arg)
{
	std::cout << "char: '" << arg << "'" << std::endl;
	std::cout << "int: " << static_cast<int> (arg) << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float> (arg) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double> (arg) << std::endl;
}

void cast_int(int arg)
{
	if (arg > 127 || arg < -128)
		std::cout << "char: impossible\n";
	else if(isprint(arg))
		std::cout << "char: '" << static_cast<char> (arg) << "'" << std::endl;
	else 
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << arg << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "float: " << static_cast<float> (arg) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(1) << "double: " << static_cast<double> (arg) << std::endl;
}

void cast_float(float arg, int point)
{
	if (arg > 127 || arg < -128)
		std::cout << "char: impossible\n";
	else if(isprint(arg))
		std::cout << "char: '" << static_cast<char> (arg) << "'" << std::endl;
	else 
		std::cout << "char: Non displayable\n";
	if (static_cast<double>(arg) >= INT32_MIN && static_cast<double>(arg) <= INT32_MAX)
		std::cout << "int: " << static_cast<int> (arg) << std::endl;
	else
		std::cout << "int: impossible\n";
	
	if (point > 0)
		point--;
	std::cout << std::fixed << std::setprecision(point) << "float: " << arg << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(point) << "double: " << static_cast<double> (arg) << std::endl;
	
}

void cast_double(double arg, int point)
{
	if (arg > 127 || arg < -128)
		std::cout << "char: impossible\n";
	else if(isprint(arg))
		std::cout << "char: '" << static_cast<char> (arg) << "'" << std::endl;
	else 
		std::cout << "char: Non displayable\n";
	
	if (arg >= INT32_MIN && arg <= INT32_MAX)
		std::cout << "int: " << static_cast<int> (arg) << std::endl;
	else
		std::cout << "int: impossible\n";
	
		std::cout << std::fixed << std::setprecision(point) << "float: " << static_cast<float> (arg) << "f" << std::endl;
	std::cout << std::fixed << std::setprecision(point) << "double: " << arg << std::endl;
}

void print_error()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible\n";
}

void convert(std::string arg)
{
	errno = 0;

	char *endp = 0;
	int size = arg.size();
	if (size == 1 && !isdigit(arg[0]))
	{
		cast_char(arg[0]);
		return ;
	}

	int i = 1;
	int point = 0;
	for (; i < size; i++)
	{
		if (arg[i] == '.')
			point = i;
		if (!isdigit(arg[i]))
			break;
	}

	if (point > 0)
		point = size - point - 1;
	if (i == size)
	{
		long val_int = strtol(arg.c_str(), &endp, 10);
		if (errno == ERANGE || *endp != 0 || val_int < INT32_MIN || val_int > INT32_MAX)
		{
			print_error();
			return ;
		}
		cast_int(val_int);
		return ;
	}

	if (arg[size - 1] == 'f' && arg.compare(std::string("-+").find(arg[0]) != std::string::npos, 4, "inf"))
	{
		arg[size - 1] = 0;
		float val_float = strtof(arg.c_str(), &endp);
		if (errno == ERANGE || *endp != 0)
		{
			print_error();
			return ;
		}
		cast_float(val_float, point);
		return ;
	}

	double val_double = strtod(arg.c_str(), &endp);
	if (errno == ERANGE || *endp != 0)
	{
		print_error();
		return ;
	}
	cast_double(val_double, point);
	return ;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (1);

	convert(argv[1]);

	return 0;
}