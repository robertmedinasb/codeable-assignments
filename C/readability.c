#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{

    //Starting counts
    
    int letters =0;
    int words= 1;
    int sentences= 0;
    
    
    //Input text and length
    string  text = get_string("Insert your text here:");
    int length = strlen(text);
    char chars [length];
    
    //count
  
    for (int i = 0 ; i < length; i++)
    {

            chars[i]=text[i];
        
            //current and next values
            char currentchar = chars[i];
            char nextchar= chars[i+1];
        
            //letters
            if((currentchar > 96 && currentchar < 123)||(currentchar >64 && currentchar<91))
            {
                letters++;
                //words

            }
            else if (currentchar == 32)
            {
                words++;    
            }        
            else if (currentchar == 46 || currentchar ==  33 || currentchar == 63)
            {
                sentences++;
            }
                    
        

        //sentences
        
    }
    printf("letters: %i, words: %i, sentences: %i\n",letters, words, sentences);
    
    //index
    float grade = 0.0588 * (100 * (float) letters / (float) words) - 0.296 * (100 * (float) sentences / (float) words) - 15.8;
    if (grade < 16 && grade >= 0)
    {
        printf("Grade %i\n", (int) round(grade));
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}




