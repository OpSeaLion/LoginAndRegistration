# LoginAndRegistration
A simple practice project of a login and registration screen.

Creating the username and password check is easy enough. Next comes registration. My question is, is it possible to create and hold usernames/passwords across program activations? More learning must be done.

I managed to create a "server" in the form of a txt file in the same directory. With a few tinkering of fstream, I managed to create a functioning registration with the ability to check if the username is taken and to double check the password in the registration. I also beefed up the login as a result of the "server". Initially, my first thought was to create two lists of a password and a username, but I quickly realized the problem of having to associate a username to a password. So I simply kept the password in the line directly below its respective username. I still have yet to figure out a way to censor the password, but maybe that'll be a bonus feature I'll add later on. A fun little project, if I may say so myself. 
