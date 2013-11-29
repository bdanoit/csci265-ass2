/********** Output module---implementation **********/

#include <stdio.h>
#include "kwic.h"
#include "Output.h"
#include "ShiftSort.h"

/***** local constants *****/

/***** local types *****/

/***** exported functions *****/

void OUInit(void)
{
	/* intentionally empty */
}

void OUPrint(void)
{
        int i,j,s;
	int keyWordIndex;
	int keyWordLength;
	int keyWordFound;
	for (i = 0; i < SSNumLines(); i++) {
		int numWords = SSNumWords(i);
		const char* keyWord = SSGetWord(i,0);
		keyWordIndex = 0;
		keyWordFound = 0;
		keyWordLength = 0;
		for (j = 0; j < numWords; j++) {
			int shiftNum = SSGetShiftNum(i);

			/* reverse word shifting */
			const char* curWord;
			if (j < shiftNum)
			{
				curWord = SSGetWord(i,numWords-shiftNum+j);
				printf("%s", curWord);
			}
			else
			{
				curWord = SSGetWord(i,j-shiftNum);
				printf("%s",SSGetWord(i,j-shiftNum));
			}
			
			/* determine underlining index and length */
			if (curWord == keyWord)
			{
			        keyWordFound = 1;
				const char *s;
				for (s = curWord; *s; ++s)
				{
				}
				keyWordLength = (s - curWord);  
			}
			else if(!keyWordFound)
			{
			        const char *s;
			        for (s = curWord; *s; ++s)
				{
				}
			        keyWordIndex += (s - curWord)+1;  
			}

			/* space follows every word but the last */
			if (j != SSNumWords(i)-1)
				printf(" ");
		}
		printf("\n");

		/* underline keyWord */
		for(j = 0; j < keyWordIndex; j++)
		{
		        printf (" ");
		}
		for (j = 0; j < keyWordLength; j++)
		{ 
		        printf("-");
		}
		printf("\n");
	}
}
