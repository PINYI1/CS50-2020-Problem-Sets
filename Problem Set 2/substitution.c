#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    //Test the validity of argument
    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    else
    {
        if (strlen(argv[1]) != 26) //Note function doesn't receive an array value; it receives a pointer value
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        else
        {
            for (int i = 0; i < 26 ; i++)
            {
                if (!isalpha(argv[1][i]))
                {
                    printf("Key must only contain alphabetic characters.\n");
                    return 1;
                }
                else
                {
                    for (int j = i + 1; j < 26; j++)
                    {
                        if (argv[1][i] == argv[1][j])
                        {
                            printf("Key must only contain repeated characters.\n");
                            return 1;
                        }
                        else
                        {}
                    }
                }
            }
        }
    }



    string plaintext = get_string("plaintext: ");

    char alphabets[26] =
    {
        'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
        'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q',
        'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'
    };


    for (int i = 0, n = strlen(plaintext); i < n ; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (plaintext[i] == alphabets[j])
            {
                plaintext[i] = tolower(argv[1][j]);
                break; //if the condition is met, break the loop
            }
            else if (plaintext[i] == toupper(alphabets[j]))
            {
                plaintext[i] = toupper(argv[1][j]);
                break;
            }
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
