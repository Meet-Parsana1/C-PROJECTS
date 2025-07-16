#include <stdio.h>  // Standard input/output functions
#include <stdlib.h> // Standard library functions for system commands
#include <time.h>   // Time and date functions
#include <unistd.h> // Sleep function (for Unix-like systems)

// Function declarations
void fill_time(char *, int); // Fills buffer with current time in chosen format
void fill_date(char *);      // Fills buffer with current date
int input_format();          // Gets user's choice for time format
void clear_screen();         // Clears the console screen

int main()
{
      char time[50], date[100]; // Buffers to store time and date strings

      int Format = input_format(); // Get user's preferred time format

      while (1) // Infinite loop to update clock every second
      {
            fill_time(time, Format); // Get current time in chosen format
            fill_date(date);         // Get current date
            clear_screen();          // Clear the console screen

            printf("--> Current Time: %s\n\n", time); // Display current time
            printf("--> Date: %s\n", date);           // Display current date

            sleep(1); // Wait for 1 second before updating again
      }

      return 0; // End of program (never reached due to infinite loop)
}

void fill_time(char *buffer, int Format)
{
      time_t raw_time;         // Variable to store raw time value
      struct tm *current_time; // Pointer to structure with broken-down time

      time(&raw_time);                     // Get current time
      current_time = localtime(&raw_time); // Convert to local time structure

      if (Format == 1) // If user chose 24-hour format
      {
            strftime(buffer, 50, "%H:%M:%S", current_time); // Format as HH:MM:SS
      }
      else // If user chose 12-hour format
      {
            strftime(buffer, 50, "%I:%M:%S %p", current_time); // Format as HH:MM:SS AM/PM
      }
}

void fill_date(char *buffer)
{
      time_t raw_time;         // Variable to store raw time value
      struct tm *current_time; // Pointer to structure with broken-down time

      time(&raw_time);                     // Get current time
      current_time = localtime(&raw_time); // Convert to local time structure

      strftime(buffer, 100, "%A, %d %B, %Y", current_time); // Format as Day, DD Month, YYYY
}

int input_format()
{
      int Format; // Variable to store user's choice

      printf("\n\nChoose the Time Format:\n");  // Prompt user
      printf("\n 1. 24-hour format");           // Option 1
      printf("\n 2. 12-hour format (default)"); // Option 2

      printf("\n\nEnter your choice (1 or 2): "); // Ask for input
      scanf("%d", &Format);                       // Read user's choice

      return Format; // Return chosen format
}

void clear_screen()
{
// Clear the console screen
#ifdef _WIN32
      system("cls"); // Use 'cls' command for Windows
#else
      system("clear"); // Use 'clear' command for Unix-like systems
#endif
}
