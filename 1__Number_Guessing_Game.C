#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

      int Guess, Random;
      int No_of_Guesses = 0;
      srand(time(NULL)); // Seed the random number generator, it means that the random numbers will be different each time the program runs. In simple words, srand() function demands some input to generate random numbers, and we use time(NULL) to get the current time as a seed.

      printf("\n\nWelcome to the World of Guessing Numbers!\n\n");
      Random = rand() % 100 + 1; // rand() function generates a random number in the range of 0 to RAND_MAX(means in Whole integer number family), which is usually a large number. By using the modulo operator (%) with 100, we limit the range to 0-99, and then we add 1 to shift it to the range of 1-100.

      do
      {
            printf("Please enter your Guess between(1 to 100): ");
            scanf("%d", &Guess);
            No_of_Guesses++;

            if (Guess < Random)
            {
                  printf("\nGuess a Larger number.\n\n");
            }
            else if (Guess > Random)
            {
                  printf("\nGuess a Smaller number.\n\n");
            }
            else
            {
                  printf("\n\nCongratulations! You have Guessed the correct number in %d attempts.\n", No_of_Guesses);
            }
      } while (Guess != Random);

      printf("\nBye Bye, thanks for playing!\n");
      printf("\nDeveloped By: Meet Parsana.\n\n");

      return 0;
}