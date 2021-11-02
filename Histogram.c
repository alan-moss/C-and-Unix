#include <stdio.h>
#include <ctype.h>

#define MAXROWS 100
#define NUM_ALPHABETS 26

int main()
{
	int count, i, j, k;

	char sentence[MAXROWS];
	char alphabets[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
	int frequency[NUM_ALPHABETS] = {0};

	// step 1: Write a function that reads a sentence from the keyboard (2 points)
		fgets(sentence, MAXROWS, stdin);
	// step 2: Find out the frequency of the alphabets in the sentence, ignore uppercase and lowercase in the sentence (4 points)
	
	// While sentence has characters left
	for(i = 0; sentence[i] != '\n'; i++)
	{
		for(j = 0; j < NUM_ALPHABETS; j++)
		{
			// toupper to ignore case, increase frequency if matches
			if(toupper(sentence[i]) == alphabets[j])
				frequency[j]++;
		}
	}
	// step 3: Print the histogram as shown in the screenshot (4 points)
	printf("%s%15s%15s\n", "Alphabets", "Frequency", "Histogram");

	for(j = 0; j < NUM_ALPHABETS; j++)
	{
		printf("%c%15d               ", alphabets[j], frequency[j]);
		for(k = 0; k < frequency[j]; k++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}
	return 0;
}
