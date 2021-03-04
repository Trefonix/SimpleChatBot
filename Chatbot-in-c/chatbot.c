#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "chatfunctions.h"
#include "goodbye.h"

int main(void)
{
	// declare necessary stuff
	bool quit = false;
	
	// TODO: implement the clear.c file as startup animation
	// startup();

	// say greeting
	greeting();

	// chatbot logic loop
	do
	{
		// longest response is 200 chars atm!
		char input[200];
		char response[200];

		take_input(input);
		respond_to(input, response);
		printf("%s", response);

		// check if user wants to exit
		if (strcmp(input, "quit") == 0)
		{
			quit = true;
			//printf("User selected Quit.\n");
		}
	} while (quit == false);

	// say goodbye
	goodbye();

	return 0;
}
