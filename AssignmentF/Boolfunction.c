#include "Boolfunction.h"
#include <stdbool.h>
#include <string.h>


//This is the main function of the program. It compares a word in the BST and the enter word.
bool Compare(char *word1, char word2[])
{
	//temp2 and temp1 are used for don't alter the original word.
	bool star = false;
	int lastchar = strlen(word2) - 1;
	char temp1[20];
	char temp2[20];
	strcpy(temp1, word1);
	char *ptr = temp1;

	//The first steps is to find if there is a star in the entered word.
	for (int i = 0;i < strlen(word2);i++)
	{
		if (word2[i] == '*')
		{
			star = true;
			break;
		}
	}
	if (star) // Then if it's the case, we have different ways in function of the position of the star.
	{
		if (word2[0] == '*')//First position
		{
			strcpy(temp2, word2);
			char *newword = temp2;
			newword++; //We take the word without the star.
			while (stricmp(ptr, newword) != 0 && ((*ptr >= 'a'&& *ptr <= 'z')|| (*ptr >= 'A'&& *ptr <= 'Z')))
				// While the both word are not equal and the first letter of the node word is a letter
			{
				ptr++;
			}
			if (!((*ptr >= 'a'&& *ptr <= 'z') || (*ptr >= 'A'&& *ptr <= 'Z'))) return false;
			else return true;
		}

		else if (word2[lastchar] == '*') //Last position
		{
			strcpy(temp2, word2);
			char *newword = temp2;
			strrev(newword); // We put the word in the inverse order
			newword++; // We remove the star
			strrev(newword); // We put the word in the original order
			while (stricmp(ptr, newword) != 0 && ((*ptr >= 'a'&& *ptr <= 'z') || (*ptr >= 'A'&& *ptr <= 'Z')))
				//same condition as before
			{
				strrev(ptr);
				ptr++;
				strrev(ptr);
			}
			if (!((*ptr >= 'a'&& *ptr <= 'z') || (*ptr >= 'A'&& *ptr <= 'Z'))) return false;
			else return true;
		}

		else
		{
			char letter;
			int count = 0;
			// We will compare each letter of the both word one by one
			for (int i = 0;i < strlen(word2);i++)
			{
				count = i;
				letter = *(ptr + i);
				if (letter != word2[i]) // If letter are different
				{
					if (word2[i] == '*'); // If the letter of the entered word is a star, we continue.
					else break; // Either we stop the loop.
				}
			}
			if (letter == word2[count]) return true; //If the last compard letters are equals, return true.
			else return false;
		}
	}
	else
		// We don't have any star, so we just compare the both word.
	{
		if (stricmp(word1, word2) == 0)return true;
		else return false;
	}
}
