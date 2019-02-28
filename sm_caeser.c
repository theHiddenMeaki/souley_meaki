// Meaki Johoa Souley
// program that cipher a text with the caesar algorithma.
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // check the number of argument passed by the user is two or not
    if (argc == 2)
    {
        //convert the argument from string to integer
        int key = atoi(argv[1]);
        string plaintext = get_string("Plaintext: ");

        //print out the ciphertext
        printf("Ciphertext: ");

        //interate the number
        for (int i = 0, n = strlen(plaintext); i < n ; i++)
        {
            //check wether the caracters are alphabetic
            if (isalpha(plaintext[i]))
            {
                //check wether the caracters are upper
                if (isupper(plaintext[i]))
                {
                    // print out the caracters step by step
                    printf("%c", (((plaintext[i] - 'A') + key) % 26) + 'A');

                }

                //check wether the caracters are upper
                if (islower(plaintext[i]))
                {
                    // print out the caracters step by step
                    printf("%c", (((plaintext[i] - 'a') + key) % 26) + 'a');
                }
            }
            else
            {
                //print out the result in case the
                printf("%c", plaintext[i]);
            }

        }
        printf("\n");
    }
    else
    {
        printf("You have to enter at least two argument\n");
    }

}