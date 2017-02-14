// DataStructures.cpp : Defines the entry point for the console application.

#include <stdio.h>
#include <stdbool.h>

// BINARY SEARCH TREE

struct BinNode {
	int data;
	struct BinNode *left;
	struct BinNode *right;
}; typedef struct BinNode bnode;


bnode *new_bnode(int data) {
	bnode *newNode = (bnode *)malloc(sizeof(bnode));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

void insert(bnode **myTree, int data) {
	if (!(*myTree)) {
		*myTree = new_bnode(data);
		return;
	}
	if (data > (*myTree)->data) insert(&((*myTree)->right), data);
	else insert(&((*myTree)->left), data);
}

void pr_preorder(bnode *myTree) {
	printf("%d,", myTree->data);
	if (myTree->left) pr_preorder(myTree->left);
	if (myTree->right) pr_preorder(myTree->right);
}

void search(bnode *myTree, int data) {

}

void del_tree(bnode *myTree) {
	if (myTree) {
		del_tree((myTree->left));
		del_tree((myTree->right));
		free(myTree);
	}
}

// HASH MAP


typedef struct hashnode {
	char *key;
	int val;
	int *next;
} hashnode;

hashnode **new_hashmap() {
	hashnode *hashmap[10000];
	for (int i = 0; i < 10000; i++) {
		hashmap[i] = NULL;
	}
	return hashmap;
}


int get_hashcode(void *key) {
	return (int)key % 10000;
}

void add_hashval(hashnode **map, void *key, int val) {
	int index = get_hashcode(key);
	hashnode **myMap = *map;
	if (!myMap) {
		myMap = new_hashmap();
	}
	if (!myMap[index]) {
		myMap[index] = (hashnode*)malloc(sizeof(hashnode));
		myMap[index]->key = key;
		myMap[index]->val = val;
		myMap[index]->next = NULL;
	}
	else {
		hashnode *currNode = myMap[index];
		if (currNode->key == key) {
			currNode->val = val;
			return;
		}
		while (currNode->next) {
			currNode = currNode->next;
			if (currNode->key == key) {
				currNode->val = val;
				return;
			}
		}
		currNode->next = (hashnode *)malloc(sizeof(hashnode));
		currNode = currNode->next;
		currNode->key = key;
		currNode->val = val;
		currNode->next = NULL;
	}
}

int get_hashval(hashnode **map, void *key) {
	if (!map) {
		return;
	}
	int index = get_hashcode(key);
	hashnode **myMap = *map;
	hashnode *currNode = myMap[index];
	while (!currNode) {
		if (currNode->key == key) {
			return currNode->val;
		} currNode = currNode->next;
	}
	return;
}

// Qeue
typedef struct Q {
	int arr[10000];
	int headIdx;
	int tailIdx;
	int isEmpty;
} Q;

Q * new_Q(int data) {
	Q *newq = (Q*)malloc(sizeof(Q));
	newq->headIdx = 0;
	newq->tailIdx = 0;
	newq->isEmpty = 0;
	(newq->arr)[newq->tailIdx] = data;
	return newq;
}

void que(Q **q, int data) {
	Q *myQ = *q;
	if (!myQ | (myQ->isEmpty)) {
		*q = new_Q(data);
		return;
	}

	(myQ->arr)[++(myQ->tailIdx)] = data;
	myQ->isEmpty = 0;
	return;
}

int deque(Q **q) {
	Q *myQ = *q;
	if (myQ->isEmpty) return NULL;
	int retVal = (myQ->arr)[myQ->headIdx];
	if (myQ->headIdx == myQ->tailIdx) {
		myQ->isEmpty = 1;
		myQ->tailIdx = myQ->headIdx = 0;
	}
	else (myQ->headIdx)++;
	printf("%d\n", retVal);
	return retVal;
}

int main()
{
	return 0;
}