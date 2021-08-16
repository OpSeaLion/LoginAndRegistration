#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
	std::string username = "Raymond";
	int password = 1234;

	std::string enteredUsername;
	int enteredPassword = 0;

	std::cout << "Enter username: ";
	std::cin >> enteredUsername;

	std::cout << "\n" << "Enter password: ";
	std::cin >> enteredPassword;

	std:: cout << "\n";

	if(enteredPassword != password || enteredUsername != username)
		std::cout << "Access Denied.";
	else
		std::cout << "Access Granted.";
}