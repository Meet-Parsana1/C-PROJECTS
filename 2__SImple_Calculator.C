#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
      int Choice;

      double n1, n2, Result;

      while (1)
      {
            printf("\n\n__________________________________________\n\n");

            printf("Welcome to the Simple Calculator!\n\n");

            printf("Choose one of the Following Operations: \n\n");

            char Operations[7][20] = {"1. Add\n", "2. Subtract\n", "3. Multiply\n", "4. Divide\n", "5. Modulus\n", "6. Power\n", "7. Exit\n"};

            for (int i = 0; i < 7; i++)
            {
                  for (int j = 0; j < 20; j++)
                  {
                        printf("%c", Operations[i][j]);
                  }
            }

            printf("\nEnter your choice (1-7): ");
            scanf("%d", &Choice);

            if (Choice == 7)
            {
                  break;
            }

            if (Choice < 1 || Choice > 6)
            {
                  fprintf(stderr, "\nInvalid Choice! Please select a valid operation(1-7).\n\n");
                  continue; // Skip to the next iteration of the loop
            }

            printf("\nEnter the First Number: ");
            scanf("%lf", &n1);

            printf("\nFinally, Enter the Second Number: ");
            scanf("%lf", &n2);

            switch (Choice)
            {
            case 1:
                  Result = n1 + n2;
                  printf("\nThe Result of Addition is: %.2lf\n\n", Result);
                  break;

            case 2:
                  Result = n1 - n2;
                  printf("\nThe Result of Subtraction is: %.2lf\n\n", Result);
                  break;

            case 3:
                  Result = n1 * n2;
                  printf("\nThe Result of Multiplication is: %.2lf\n\n", Result);
                  break;

            case 4:
                  if (n2 != 0)
                  {
                        Result = n1 / n2;
                        printf("\nThe Result of Division is: %.2lf\n\n", Result);
                  }
                  else
                  {
                        printf("\nError: Division by Zero is not defined.\n\n");
                  }
                  break;

            case 5:
                  if (n2 != 0)
                  {
                        Result = (int)n1 % (int)n2; // As only integers can be used for modulus operation
                        // Casting to int to perform modulus operation
                        printf("\nThe Result of Modulus is: %.2lf\n\n", Result);
                  }
                  else
                  {
                        printf("\nError: Modulus by Zero is not Defined.\n\n");
                  }
                  break;

            case 6:
                  if (n2 >= 0)
                  {
                        Result = pow(n1, n2);
                        printf("\nThe Result of Power is: %.2lf\n\n", Result);
                  }
                  else
                  {
                        printf("\nError: Power with Negative Exponent is not defined for real numbers.\n\n");
                  }
                  break;
            }
      }

      return 0;
}