#include <stdio.h>
#include <stdlib.h>

#define MAX_CHAR_NUM	26

enum NODE_TYPE 
{
	TYPE_COMPLETED,
	TYPE_UNCOMPLETED
};


struct TrieNode {
	enum NODE_TYPE	type;
	char ch;
	int count;	//这个字段利于单词的删除
	struct TrieNode * child[MAX_CHAR_NUM];
};

int trie_index(char ch)
{
	return ch - 'a';
}

struct TrieNode *trieCreateNode(char ch)
{
	struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
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
struct TrieNode* trieCreate() {
	return trieCreateNode(' ');
}

/** Inserts a word into the trie. */
void insert(struct TrieNode* root, char* word) {
	if(root == NULL)
		return;
	struct TrieNode * pNode = root;
	char ch;
	while(*word != '\0')
	{
		if(pNode->child[trie_index(*word)] == NULL)
		{
			pNode->child[trie_index(*word)] = trieCreateNode(*word);
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

/** Returns if the word is in the trie. */
int search(struct TrieNode* root, char* word) {
	struct TrieNode *pNode = root;
	while(*word != '\0')
	{
		if(pNode->child[trie_index(*word)] == NULL)
		{
			break;
		}
		pNode = pNode->child[trie_index(*word)];

		word++;
	}

	return (*word == '\0' && pNode->type == TYPE_COMPLETED)?1:0;
}

/** Returns if there is any word in the trie 
    that starts with the given prefix. */

int  startsWith(struct TrieNode* root, char* prefix) {
	struct TrieNode *pNode = root;
	while(*prefix != '\0')
	{
		if(pNode->child[trie_index(*prefix)] == NULL)
		{
			break;
		}
		pNode = pNode->child[trie_index(*prefix)];
		prefix++;
	}

	return (*prefix == '\0')?1:0;    
}

/** Deallocates memory previously allocated for the TrieNode. */
void trieFree(struct TrieNode* root) {
	int i = 0;
	for (i = 0; i < MAX_CHAR_NUM; ++i)
	{
		if(root->child[i] != NULL)
		{
			trieFree(root->child[i]);
		}
	}
	free(root);
}

// Your Trie object will be instantiated and called as such:
// struct TrieNode* node = trieCreate();
// insert(node, "somestring");
// search(node, "key");
// trieFree(node);


int main(int argc, char const *argv[])
{
	struct TrieNode* node = trieCreate();
	insert(node, "somestring");
	search(node, "key");
	trieFree(node);
	return 0;
}
