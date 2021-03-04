#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random_number(int min_num, int max_num); //copied from internet


char * messages[] = {
    "See ya later, alligator!",
    "Catch you on the flip side!",
    "Adios, Amigos!",
    "Asta la vista, baby!",
    "Thank you for your cooperation. Farewell."
};

void goodbye(){

    int bye = random_number(0,4);

    puts(messages[bye]);

}

//Random number function. Hmmmmm.
int random_number(int min_num, int max_num)
{
 int result = 0, low_num = 0, hi_num = 0;

 if (min_num < max_num)
 {
  low_num = min_num;
  hi_num = max_num + 1; // include max_num in output
  } else {
  low_num = max_num + 1; // include max_num in output
  hi_num = min_num;
  }

 srand(time(NULL));
 result = (rand() % (hi_num - low_num)) + low_num;
 return result;
}
