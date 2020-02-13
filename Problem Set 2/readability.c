#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int num_letter = 0;
    int num_sentences = 0;
    int num_word = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            num_letter ++;
        }
        else if (text[i] == ' ')
        {
            num_word ++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            num_sentences ++;
        }
    }
    float L = (float) num_letter / (float) num_word * 100;
    float S = (float) num_sentences / (float) num_word * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }

}
