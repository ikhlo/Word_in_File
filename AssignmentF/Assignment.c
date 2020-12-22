#include <stdlib.h>
#include <stdio.h>
#include "Boolfunction.h"
#include <stdbool.h>
#include <string.h>
#define N 100

void Game(struct node *NODE, char *findword[], char *word);
struct node *newNode(char *newword);
struct node *Insertnode(struct node *NODE, char *newword);
struct node *Reading();

struct node
{
	char word[30];
	struct node *left, *right;
};

int main(void)
{

	puts("Hello !\nWelcome in dictionnary function.");

		
		int freq = 0;
		struct node *Joue = NULL;
		Joue = Reading(Joue);
		char word[30] = { 0 };
		char mode;
		char *findword[50] = { 0 };
		
		puts("\nWhat do you want to do ? :");
		puts("\t-Search a word in the dictionnary? Then write 'S'.\n\t-Count the number of a defined word? Then write 'C'.");
		puts("\t-If you want search and count, then write 'B'.");
		do {
			scanf(" %c", &mode);
			if (mode != 'S' && mode != 'C' && mode != 'B')
			{
				puts("Make sure to write 'S', 'C', or 'B' in uppercase. Try again.");
			}
		} while (mode != 'S' && mode != 'C' && mode != 'B');

		puts("Now, write the word with which the function will works :");
		scanf("%s", word);
		puts("");
		if (word[0] >= 'a'&&word[0] <= 'z') word[0] -= 32;

		Game(Joue, findword, word);
		for (int i = 0;i < 50; i++)
		{
			if (findword[i] == 0) break;
			else
			{
				if (mode == 'S' || mode == 'B') printf("    %s", findword[i]);
				freq++;
			}
		}
		if (mode == 'C' || mode == 'B') printf("\nThe frequency of the word %s is %d.", word, freq);
		if (freq == 0) printf("\nThe word %s is not in the dictionnary.", word);
		puts("");
	puts(" Thanks for playing ! Have a nice day and come back when you want :)");

	system("pause");
	return 0;
}

//This recursive function will traverse the BST in pre-order stock the word find with the compare function.
void Game(struct node *NODE, char *findword[], char *word)
{

	if (NODE->left != NULL || NODE->right != NULL)
	{
		if (NODE->left != NULL) Game(NODE->left, findword, word);
		if (NODE->right != NULL) Game(NODE->right, findword, word);
	}
	if (Compare(NODE->word, word))
	{
		int i = 0;
		while (findword[i] != 0)
		{
			i++;
		}
		findword[i] = NODE->word;
	}

}

//This function read a text file and return the BST with the word. The word of the text file have to be on newline.
struct node *Reading()
{
	int lastchar;
	struct node *temp = NULL;
	FILE *file = fopen("Word.txt", "r");

	if (file != NULL)
	{
		char str[100];
		char* sPtr = str;
		
		while (fgets(str, N, file) != NULL) {
			lastchar = strlen(sPtr);
			if (str[lastchar - 1] == '\n') str[lastchar - 1] = '\0';
			temp = Insertnode(temp, sPtr);
		}
	}
	else
	{
		// Open failed
		printf("Error for open the file test.txt");
	}

	fclose(file); // Close the opened file
	return temp;
}



struct node *newNode(char *newword)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	strcpy(temp->word, newword);
	temp->left = temp->right = NULL;
	return temp;
}

//This function insert node according to letters superiority.
struct node *Insertnode(struct node *NODE, char *newword)
{
	if (NODE == NULL)
	{
		NODE = newNode(newword);
	}
	else
	{
		if (stricmp(NODE->word, newword) < 0) NODE->right = Insertnode(NODE->right, newword);
		else if (stricmp(NODE->word, newword) > 0) NODE->left = Insertnode(NODE->left, newword);
	}
	return NODE;
}

