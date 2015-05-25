#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_NUM	26

enum NODE_TYPE 
{
	TYPE_COMPLETED,
	TYPE_UNCOMPLETED
};

struct WordDictionary {
	enum NODE_TYPE	type;
	char ch;
	int count;	//这个字段利于单词的删除
	struct WordDictionary * child[MAX_CHAR_NUM];
};

int trie_index(char ch)
{
	return ch - 'a';
}

struct WordDictionary *trieCreateNode(char ch)
{
	struct WordDictionary *node = (struct WordDictionary *)malloc(sizeof(struct WordDictionary));
	node->type = TYPE_UNCOMPLETED;
	node->ch = ch;
	node->count = 1;
	int i = 0;
	for (i = 0; i < MAX_CHAR_NUM; ++i)
	{
		node->child[i] = NULL;
	}

	return node;
}

/** Initialize your data structure here. */
struct WordDictionary* wordDictionaryCreate() {
    return trieCreateNode(' ');
}

/** Inserts a word into the data structure. */
void addWord(struct WordDictionary* wordDictionary, char* word) {
    if(wordDictionary == NULL)
		return;
	struct WordDictionary * pNode = wordDictionary;
	char ch;
	while(*word != '\0')
	{
		if(pNode->child[trie_index(*word)] == NULL)
		{
			pNode->child[trie_index(*word)] = trieCreateNode(*word);
			printf("%d %p\n", trie_index(*word), pNode->child[trie_index(*word)]);
		}
		else
		{
			pNode->child[trie_index(*word)]->count++;
		}
		pNode = pNode->child[trie_index(*word)];
		word++;
	}
	pNode->type = TYPE_COMPLETED;

	return;
}

/** Returns if the word is in the data structure. A word could
    contain the dot character '.' to represent any one letter. */

int search(struct WordDictionary*wordDictionary, char *word)
{
	if(*word == '\0')
		return (wordDictionary->type == TYPE_COMPLETED)?1:0;
	if(*word != '.')
	{
		//printf("%d %s\n", trie_index(*word), word);
		if(wordDictionary->child[trie_index(*word)] != NULL)
		{
			//printf("It enter here %p\n", wordDictionary->child[trie_index(*word)]);
			return search(wordDictionary->child[trie_index(*word)],  word + 1);
		}

		return 0;
	}
	else
	{
		int i = 0;
		for (i = 0; i < MAX_CHAR_NUM; ++i)
		{
			if(wordDictionary->child[i] != NULL)
			{
				if(search(wordDictionary->child[i], word + 1) == 1)
				{
					return 1;
				}
			}
		}
		return 0;
	}
}

/*
int search(struct WordDictionary* wordDictionary, char* word) {
    struct WordDictionary *pNode = wordDictionary;
    struct WordDictionary *pTemp = NULL;
    int i = 0, j = 0;
    char *ptr = NULL;
	while(*word != '\0')
	{
		if(*word == '.')
		{

			for(i = j; i < MAX_CHAR_NUM; i++)
			{
				if(pNode->child[i] != NULL)
				{
					break;
				} 
			}
			if(i == MAX_CHAR_NUM)
			{
				return 0;
			}
			else
			{
				j = i + 1;
				ptr = word;
				pTemp = pNode;
				pNode = pNode->child[i];
			}
		}
		else
		{
			if(pNode->child[trie_index(*word)] == NULL)
			{
				if(j < MAX_CHAR_NUM && j > 0)
				{
					word = ptr;
					pNode = pTemp;
					printf("%d %s\n", j, word);
					continue;
				}
				break;
			}
			pNode = pNode->child[trie_index(*word)];
		}
		word++;
	}

	return (*word == '\0' && pNode->type == TYPE_COMPLETED)?1:0;
}
*/

/** Deallocates memory previously allocated for the data structure. */
void wordDictionaryFree(struct WordDictionary* wordDictionary) {
    int i = 0;
	for (i = 0; i < MAX_CHAR_NUM; ++i)
	{
		if(wordDictionary->child[i] != NULL)
		{
			wordDictionaryFree(wordDictionary->child[i]);
		}
	}
	free(wordDictionary);
}

// Your WordDictionary object will be instantiated and called as such:
// struct WordDictionary* wordDictionary = wordDictionaryCreate();
// addWord(wordDictionary, "word");
// search(wordDictionary, "pattern");
// wordDictionaryFree(wordDictionary);


int main(int argc, char const *argv[])
{
	struct WordDictionary * root  = wordDictionaryCreate();
	//addWord(root, "at");
	//addWord(root, "and");
	//addWord(root, "add");
	addWord(root, "a");
	//addWord(root, "bat");
	int a = search(root, "."); 
	printf("%d\n", a);
	return 0;
}