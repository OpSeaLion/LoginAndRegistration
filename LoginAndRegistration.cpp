#include <iostream>
#include <fstream>
#include <string>

void LogIn()
{
	std::ifstream ListOfUserPass("LoginInformation.txt");		//Txt file of Login information in the format of Username\n Password\n
	std::string ListUser, ListPass;					//Variables for usernames and passwords in the txt file.

	std::string enteredUsername, enteredPassword;	//Variables for the username and password entered by the user.

	std::cout << "Enter username: ";
	std::cin >> enteredUsername;

	std::cout << "Enter password: ";
	std::cin >> enteredPassword;

	while(getline(ListOfUserPass, ListUser))		
	{
		if(ListUser == enteredUsername)				//If the current username in the txt file matches the entered username, get the next line and check the password.
			getline(ListOfUserPass, ListPass);	
		else
			getline(ListOfUserPass, ListUser); 		//If the Username in the list is not the same as the entered username, pass the next line.
	}

	if(enteredPassword != ListPass)
		std::cout << "Access Denied.\n";
	else
		std::cout << "Access Granted.\n";
}

void Registration()
{
	std::fstream UserPassToAdd;
	UserPassToAdd.open("LoginInformation.txt", std::ios::in);
	std::string enteredUsername, enteredPassword, ListUser, ListPass;
	int i = 0;										// Variable to be used for while loops
	
	std::cout << "Enter username: ";
	std::cin >> enteredUsername;

	while(getline(UserPassToAdd, ListUser))
	{
		if(ListUser == enteredUsername)
		{
			std::cout << "That username is taken, pick another one.\n";	//If a name is already taken, set the variable.
			i = 1;
		}
	}

	UserPassToAdd.close();

	while(i == 1)
	{
		i = 0;															//At the beginning of the loop, reset the variable to 0.
		UserPassToAdd.open("LoginInformation.txt", std::ios::in);		//Re-open the stream to check the list.
		std::cout << "Enter a new username: ";
		std::cin >> enteredUsername;
		while(getline(UserPassToAdd, ListUser))
		{
			if(ListUser == enteredUsername)
			{
				std::cout << "That username is taken, pick another one.\n";
				i = 1;													//If the new name is still taken, set the variable back to 1 and loop again.		
			}
		}
		UserPassToAdd.close();
	}
	
	UserPassToAdd.open("LoginInformation.txt", std::ios::out | std::ios::app);	

	while(i == 0)
	{
		std::cout << "Enter password: ";
		std::cin >> enteredPassword;

		std::cout << "Re-enter password: ";
		std::cin >> ListPass;
		if(ListPass == enteredPassword)
		{
			ListUser = enteredUsername;
			i = 1;
		}
		else
			std::cout << "Error: password was not identical.\n";
	}
	UserPassToAdd << "\n" << ListUser << "\n" << ListPass;
}

int main(int argc, char* argv[])
{
	int WhatDoYouWantToDo = 0;
	std::cout << "1) Log in.\n";
	std::cout << "2) Sign up.\n";
	while(1)
	{
		std::cin >> WhatDoYouWantToDo;
		if(WhatDoYouWantToDo == 1)
		{
			LogIn();
			return 0;
		}
		else if(WhatDoYouWantToDo == 2)
		{
			Registration();
			return 0;
		}
		else
			std::cout << "Error: Please pick a valid option.\n";
	}
}