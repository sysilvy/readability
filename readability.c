#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Get user input
    string text = get_string("Text: ");

    // Initialize variables
    int letters = 0;
    int words = 1;
    int sentences = 0;

    // Iterate through each chars of the text
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        // Count the number of letters
        if (isalpha(text[i]))
        {
            letters++;
        }

        // Count the number of words
        if (text[i] == ' ')
        {
            words++;
        }

        // Count the number of sentences
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }

    }

    // Initialize variables for average values
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;

    // Calculate the readability
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    // Print the grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}