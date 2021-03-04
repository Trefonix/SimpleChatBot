#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include "chatfunctions.h"
#include "joke.h"

struct tm *get_time() {
	time_t timeT;
	
	time(&timeT);

	return localtime(&timeT);
} 


void greeting()
{

	printf("Hello, welcome to this amazing chat bot, written in C!\n");
	printf("Type help to show the available commands\n");

	//conditions of time and greeting
	int currentHour = get_time()->tm_hour;

	if (currentHour >= 0 && currentHour < 12)
	{
		printf("   _____                 _   __  __                  _             \n");
		printf("  / ____|               | | |  \\/  |                (_)            \n");
		printf(" | |  __  ___   ___   __| | | \\  / | ___  _ __ _ __  _ _ __   __ _ \n");
		printf(" | | |_ |/ _ \\ / _ \\ / _` | | |\\/| |/ _ \\| '__| '_ \\| | '_ \\ / _` |\n");
		printf(" | |__| | (_) | (_) | (_| | | |  | | (_) | |  | | | | | | | | (_| |\n");
		printf("  \\_____|\\___/ \\___/ \\__,_| |_|  |_|\\___/|_|  |_| |_|_|_| |_|\\__, |\n");
		printf("                                                              __/ |\n");
		printf("                                                             |___/ \n");
	}
	else if (currentHour >= 12 && currentHour < 17)
	{
		printf("   _____                 _             __ _                                    \n");
		printf("  / ____|               | |     /\\    / _| |                                   \n");
		printf(" | |  __  ___   ___   __| |    /  \\  | |_| |_ ___ _ __ _ __   ___   ___  _ __  \n");
		printf(" | | |_ |/ _ \\ / _ \\ / _` |   / /\\ \\ |  _| __/ _ \\ '__| '_ \\ / _ \\ / _ \\| '_ \\ \n");
		printf(" | |__| | (_) | (_) | (_| |  / ____ \\| | | ||  __/ |  | | | | (_) | (_) | | | |\n");
		printf("  \\_____|\\___/ \\___/ \\__,_| /_/    \\_\\_|  \\__\\___|_|  |_| |_|\\___/ \\___/|_| |_|\n");
	}
	else if (currentHour >= 17 && currentHour < 20)
	{
		printf("   _____                 _   ______               _             \n");
		printf("  / ____|               | | |  ____|             (_)            \n");
		printf(" | |  __  ___   ___   __| | | |____   _____ _ __  _ _ __   __ _ \n");
		printf(" | | |_ |/ _ \\ / _ \\ / _` | |  __\\ \\ / / _ \\ '_ \\| | '_ \\ / _` |\n");
		printf(" | |__| | (_) | (_) | (_| | | |___\\ V /  __/ | | | | | | | (_| |\n");
		printf("  \\_____|\\___/ \\___/ \\__,_| |______\\_/ \\___|_| |_|_|_| |_|\\__, |\n");
		printf("                                                           __/ |\n");
		printf("                                                          |___/ \n");
	}
}

void take_input(char * input)
{	
	printf("chatbot ~ >> ");
	fgets(input,200,stdin); //copy input from stdin to input pointer
	
	//Convert to lowercase
	for (int i = 0; input[i] != '\0'; i++) {
		if (input[i] >= 'A' && input[i] <= 'Z') {
			input[i] |= 'A' ^ 'a';
		} else if (input[i] == '\n') {
			input[i] == '\0';
		}
	}
}

// Populates `response` with an output derived fom `input`.
void respond_to(char * input, char * response)
{
	response[0] = '\0';  // Remove the previous response.

	//Possible user requests:
	// hello
	// how are you
	// tell me a joke
	// what is the time
	// what is the date

	// To add:
	// 


	//Scans the input for a "hello" message and will respond accordingly if found
	if (strstr(input, "hello") != NULL || strstr(input, "hi") != NULL) {
		strcpy(response, "Hello there\n"); //has to be the classic obi-wan kenobi response
	}

	//Scans the input for a "how are you" message and responds accordingly
	if (strstr(input, "how are you") != NULL || strstr(input, "how r u") != NULL || strstr(input, "how you doing") != NULL || strstr(input, "hows u") != NULL || strstr(input, "whats poppin") != NULL) {
		strcpy(response, "I'm very well today, thank you for asking.\n");
	}
	
	//Scans the input for signs of the user wanting a joke and tells them one 
	if (strstr(input, "joke") != NULL) {
		telljoke();
	}
	
	// Scans the input for signs of the user wanting the time and gives them it.
	if (strstr(input, "time") != NULL) {
		strftime(response, 200, "It is %H:%M!\n", get_time());
	}

	// Scans the input for signs of the user wanting the date and gives them it.
	if (strstr(input, "date") != NULL) {
		strftime(response, 200, "It is %Y-%m-%d!\n", get_time());
	}

}











void startup()
{
system("@cls||clear");

sleep(0.1);

printf("⠀⠀⠀⠀⣀⣤\n⠀⠀⠀⠀⣿⠿⣶\n⠀⠀⠀⠀⣿⣿⣀\n⠀⠀⠀⣶⣶⣿⠿⠛⣶\n⠤⣀⠛⣿⣿⣿⣿⣿⣿⣭⣿⣤\n⠒⠀⠀⠀⠉⣿⣿⣿⣿⠀⠀⠉⣀\n⠀⠤⣤⣤⣀⣿⣿⣿⣿⣀⠀⠀⣿\n⠀⠀⠛⣿⣿⣿⣿⣿⣿⣿⣭⣶⠉\n⠀⠀⠀⠤⣿⣿⣿⣿⣿⣿⣿\n⠀⠀⠀⣭⣿⣿⣿⠀⣿⣿⣿\n⠀⠀⠀⣉⣿⣿⠿⠀⠿⣿⣿\n⠀⠀⠀⠀⣿⣿⠀⠀⠀⣿⣿⣤\n⠀⠀⠀⣀⣿⣿⠀⠀⠀⣿⣿⣿\n⠀⠀⠀⣿⣿⣿⠀⠀⠀⣿⣿⣿\n⠀⠀⠀⣿⣿⠛⠀⠀⠀⠉⣿⣿\n⠀⠀⠀⠉⣿⠀⠀⠀⠀⠀⠛⣿\n⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⣿⣿\n⠀⠀⠀⠀⣛⠀⠀⠀⠀⠀⠀⠛⠿⠿⠿\n⠀⠀⠀⠛⠛\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⣀⣶⣀\n⠀⠀⠀⠒⣛⣭\n⠀⠀⠀⣀⠿⣿⣶\n⠀⣤⣿⠤⣭⣿⣿\n⣤⣿⣿⣿⠛⣿⣿⠀⣀\n⠀⣀⠤⣿⣿⣶⣤⣒⣛\n⠉⠀⣀⣿⣿⣿⣿⣭⠉\n⠀⠀⣭⣿⣿⠿⠿⣿\n⠀⣶⣿⣿⠛⠀⣿⣿\n⣤⣿⣿⠉⠤⣿⣿⠿\n⣿⣿⠛⠀⠿⣿⣿\n⣿⣿⣤⠀⣿⣿⠿\n⠀⣿⣿⣶⠀⣿⣿⣶\n⠀⠀⠛⣿⠀⠿⣿⣿\n⠀⠀⠀⣉⣿⠀⣿⣿\n⠀⠶⣶⠿⠛⠀⠉⣿\n⠀⠀⠀⠀⠀⠀⣀⣿\n⠀⠀⠀⠀⠀⣶⣿⠿\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠶⠀⠀⣀⣀\n⠀⠀⠀⠀⠀⠀⣀⣀⣤⣤⣶⣿⣿⣿⣿⣿⣿\n⠀⠀⣀⣶⣤⣤⠿⠶⠿⠿⠿⣿⣿⣿⣉⣿⣿\n⠿⣉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⣤⣿⣿⣿⣀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿⣶⣤\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⣿⣿⠿⣛⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠛⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⠿⠀⣿⣿⣿⠛\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⠿⣿⠀⠀⣿⣶\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠛⠀⠀⣿⣿⣶\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⠤\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿\n");

sleep(1);

system("@cls||clear");

printf("\n⠀⠀⣀\n⠀⠿⣿⣿⣀\n⠀⠉⣿⣿⣀\n⠀⠀⠛⣿⣭⣀⣀⣤\n⠀⠀⣿⣿⣿⣿⣿⠛⠿⣶⣀\n⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⣉⣶\n⠀⠀⠉⣿⣿⣿⣿⣀⠀⠀⣿⠉\n⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿\n⠀⣀⣿⣿⣿⣿⣿⣿⣿⣿⠿\n⠀⣿⣿⣿⠿⠉⣿⣿⣿⣿\n⠀⣿⣿⠿⠀⠀⣿⣿⣿⣿\n⣶⣿⣿⠀⠀⠀⠀⣿⣿⣿\n⠛⣿⣿⣀⠀⠀⠀⣿⣿⣿⣿⣶⣀\n⠀⣿⣿⠉⠀⠀⠀⠉⠉⠉⠛⠛⠿⣿⣶\n⠀⠀⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿\n⠀⠀⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠉⠉\n⣀⣶⣿⠛\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⣿⣿⣿⣤⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤⣿\n⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣶⣿⣿⣿⣶⣶⣤⣶⣶⠶⠛⠉⠉\n⠀⠀⠀⠀⠀⠀⣤⣿⠿⣿⣿⣿⣿⣿⠀⠀⠉⠀⠀⠀⠀⠀⠀\n⠛⣿⣤⣤⣀⣤⠿⠉⠀⠉⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠉⠉⠉⠉⠉⠀⠀⠀⠀⠉⣿⣿⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠛⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣛⣿⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⠛⠿⣿⣿⣿⣶⣤⠀⠀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⠀⣿⠛⠉⠀⠀⠀⠛⠿⣿⣿⣶⣀⠀⠀⠀⠀\n⠀⠀⠀⠀⠀⠀⣿⣀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠛⠿⣶⣤⠀⠀\n⠀⠀⠀⠀⠀⠛⠿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⠿⠀\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠛⠉⠉⠀\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⠀⠀⣤⣶⣶\n⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣀⣀\n⠀⠀⠀⠀⠀⣀⣶⣿⣿⣿⣿⣿⣿\n⣤⣶⣀⠿⠶⣿⣿⣿⠿⣿⣿⣿⣿\n⠉⠿⣿⣿⠿⠛⠉⠀⣿⣿⣿⣿⣿\n⠀⠀⠉⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣤⣤\n⠀⠀⠀⠀⠀⠀⠀⣤⣶⣿⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⣀⣿⣿⣿⣿⣿⠿⣿⣿⣿⣿\n⠀⠀⠀⠀⣀⣿⣿⣿⠿⠉⠀⠀⣿⣿⣿⣿\n⠀⠀⠀⠀⣿⣿⠿⠉⠀⠀⠀⠀⠿⣿⣿⠛\n⠀⠀⠀⠀⠛⣿⣿⣀⠀⠀⠀⠀⠀⣿⣿⣀\n⠀⠀⠀⠀⠀⣿⣿⣿⠀⠀⠀⠀⠀⠿⣿⣿\n⠀⠀⠀⠀⠀⠉⣿⣿⠀⠀⠀⠀⠀⠀⠉⣿\n⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⠀⠀⠀⣀⣿\n⠀⠀⠀⠀⠀⠀⣀⣿⣿\n⠀⠀⠀⠀⠤⣿⠿⠿⠿\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⣀\n⠀⠀⣶⣿⠿⠀⠀⠀⣀⠀⣤⣤\n⠀⣶⣿⠀⠀⠀⠀⣿⣿⣿⠛⠛⠿⣤⣀\n⣶⣿⣤⣤⣤⣤⣤⣿⣿⣿⣀⣤⣶⣭⣿⣶⣀\n⠉⠉⠉⠛⠛⠿⣿⣿⣿⣿⣿⣿⣿⠛⠛⠿⠿\n⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠿\n⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⣭⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⠿\n⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⠿\n⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⣿⠛⠿⣿⣤\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⠀⠀⠀⣿⣿⣤\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⠀⠀⠀⣶⣿⠛⠉\n⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠀⠀⠉\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⠀⠀⣶⣿⣶\n⠀⠀⠀⣤⣤⣤⣿⣿⣿\n⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣶\n⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⣿\n⠀⠀⣿⣉⣿⣿⣿⣿⣉⠉⣿⣶\n⠀⠀⣿⣿⣿⣿⣿⣿⣿⣿⠿⣿\n⠀⣤⣿⣿⣿⣿⣿⣿⣿⠿⠀⣿⣶\n⣤⣿⠿⣿⣿⣿⣿⣿⠿⠀⠀⣿⣿⣤\n⠉⠉⠀⣿⣿⣿⣿⣿⠀⠀⠒⠛⠿⠿⠿\n⠀⠀⠀⠉⣿⣿⣿⠀⠀⠀⠀⠀⠀⠉\n⠀⠀⠀⣿⣿⣿⣿⣿⣶\n⠀⠀⠀⠀⣿⠉⠿⣿⣿\n⠀⠀⠀⠀⣿⣤⠀⠛⣿⣿\n⠀⠀⠀⠀⣶⣿⠀⠀⠀⣿⣶\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣭⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⣤⣿⣿⠉\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣶\n⠀⠀⠀⠀⠀⣀⣀⠀⣶⣿⣿⠶\n⣶⣿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣤⣤\n⠀⠉⠶⣶⣀⣿⣿⣿⣿⣿⣿⣿⠿⣿⣤⣀\n⠀⠀⠀⣿⣿⠿⠉⣿⣿⣿⣿⣭⠀⠶⠿⠿\n⠀⠀⠛⠛⠿⠀⠀⣿⣿⣿⣉⠿⣿⠶\n⠀⠀⠀⠀⠀⣤⣶⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿⣿⣿⠒\n⠀⠀⠀⠀⣀⣿⣿⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⣿⣿⣿⠛⣭⣭⠉\n⠀⠀⠀⠀⠀⣿⣿⣭⣤⣿⠛\n⠀⠀⠀⠀⠀⠛⠿⣿⣿⣿⣭\n⠀⠀⠀⠀⠀⠀⠀⣿⣿⠉⠛⠿⣶⣤\n⠀⠀⠀⠀⠀⠀⣀⣿⠀⠀⣶⣶⠿⠿⠿\n⠀⠀⠀⠀⠀⠀⣿⠛\n⠀⠀⠀⠀⠀⠀⣭⣶\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⣤⣤\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿\n⠀⠀⣶⠀⠀⣀⣤⣶⣤⣉⣿⣿⣤⣀\n⠤⣤⣿⣤⣿⠿⠿⣿⣿⣿⣿⣿⣿⣿⣿⣀\n⠀⠛⠿⠀⠀⠀⠀⠉⣿⣿⣿⣿⣿⠉⠛⠿⣿⣤\n⠀⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⠛⠀⠀⠀⣶⠿\n⠀⠀⠀⠀⠀⠀⠀⠀⣀⣿⣿⣿⣿⣤⠀⣿⠿\n⠀⠀⠀⠀⠀⠀⠀⣶⣿⣿⣿⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠿⣿⣿⣿⣿⣿⠿⠉⠉\n⠀⠀⠀⠀⠀⠀⠀⠉⣿⣿⣿⣿⠿\n⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⠉\n⠀⠀⠀⠀⠀⠀⠀⠀⣛⣿⣭⣶⣀\n⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠉⠛⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⣿⣿\n⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣉⠀⣶⠿\n⠀⠀⠀⠀⠀⠀⠀⠀⣶⣿⠿\n⠀⠀⠀⠀⠀⠀⠀⠛⠿⠛\n");

sleep(1);

system("@cls||clear");

printf("⠀⠀⠀⣶⣿⣶\n⠀⠀⠀⣿⣿⣿⣀\n⠀⣀⣿⣿⣿⣿⣿⣿\n⣶⣿⠛⣭⣿⣿⣿⣿\n⠛⠛⠛⣿⣿⣿⣿⠿\n⠀⠀⠀⠀⣿⣿⣿\n⠀⠀⣀⣭⣿⣿⣿⣿⣀\n⠀⠤⣿⣿⣿⣿⣿⣿⠉\n⠀⣿⣿⣿⣿⣿⣿⠉\n⣿⣿⣿⣿⣿⣿\n⣿⣿⣶⣿⣿\n⠉⠛⣿⣿⣶⣤\n⠀⠀⠉⠿⣿⣿⣤\n⠀⠀⣀⣤⣿⣿⣿\n⠀⠒⠿⠛⠉⠿⣿\n⠀⠀⠀⠀⠀⣀⣿⣿\n⠀⠀⠀⠀⣶⠿⠿⠛\n");

sleep(1);

system("@cls||clear");
}