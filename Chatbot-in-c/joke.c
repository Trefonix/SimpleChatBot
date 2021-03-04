#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

//Takes the joke response and converts it to lower case.
void take_joke_response(char * input)
{	
	printf("chatbot ~ joke >> ");
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

//Generates a random number function
int random_num(int nMin, int nMax)
{
    srand(time(NULL));

    int nRandonNumber = rand()%((nMax+1)-nMin) + nMin;
    return nRandonNumber;
}

//Function to tell the joke
void telljoke()
{
    //Two joke arrays - one for knockknock jokes and one for random jokes._

    char * knockKnockSetup[] = {
		"Doris",
        "Nobel",
        "Luke",
        "Figs",
        "Mikey",
        "Dishes",
        "Wire",
        "Avenue",
        "Ben",
        "Candice"
	};

    char * knockKnockPunchline[] = {
		"Doris locked that's why I'm knocking.",
        "Nobel... That's why I knocked.",
        "Luke through the peephole and find out...",
        "Figs the doorbell, it's broken.",
        "Mikey doesn't work, so help me out, would you?",
        "Dishes the police, come out with your hands up!",
        "Wire you asking me?",
        "Avenue knocked on this door before?",
        "Ben knocking on this door all morning, let me in!",
        "Candice door open, or what?"
	};

    
    //Two arrays - one for setups and one for punchlines (10 in total)
    char * randJokesSetups[] = {
        "What do you call a man with a rubber toe?",
        "What's Forrest Gump's computer password?",
        "Did you hear the story about the haunted lift?",
        "Why didn't the skeleton cross the road?",
        "Why was the big cat disqualified from the race?",
        "What did the mountain climber name his son?",
        "I'm reading a book about anti-gravity.",
        "I fear for the calendar.",
        "I gave away all my used batteries today.",
        "Did you hear about the restaurant on the moon?"
    };
    
    char * randJokesPunchline[] = {
        "Roberto!",
        "1forest1",
        "It really raised my spirits!" ,
        "Because he had no guts!",
        "Because it was a cheetah!",
        "Cliff",
        "It's impossible to put down.",
        "It's days are numbered.",
        "Free of charge!",
        "Great food, no atmosphere!"
    };

    
    
    //Two input buffers
    char input[200];
    char response[200];
    
    //Two types of joke (1 = knock knock joke, 2 = regular joke)
    int knockknock = random_num(0,1);

    //Select a random joke. between 1-10 for either type of joke 
    int randJokeNum = random_num(0,9);


    if (knockknock) 
    {
        //Knock Knock bit
        printf("Knock Knock...\n");
        
        //Who's there bit
        take_joke_response(input);
        if (strstr(input, "who") != NULL && strstr(input, "there") != NULL) 
        {
		    strcpy(response,knockKnockSetup[randJokeNum]);
	    } 
        else 
        {
			puts("I guess you don't want to play then :(");
			return;
		}
        
        //Person at the door
        puts(response);

        //Person at the door who?
        take_joke_response(input);
        if (strstr(input,"who")!= NULL) 
        {
            strcpy(response,knockKnockPunchline[randJokeNum]);
        } 
        else 
        {
            puts("I guess you don't want to play then :(");
			return;
        }

        // Punchline
        puts(response);

    } 

    else 
    {

        //Sets the joke up
        puts(randJokesSetups[randJokeNum]);

        //Sleeps for dramatic effect
        sleep(3);

        //Delivers the punchline
        puts(randJokesPunchline[randJokeNum]);
        
    }
}