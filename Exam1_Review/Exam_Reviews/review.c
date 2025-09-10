/*
 * File: review.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Fall 2025
 * Assignment: Exam 1 Review
 * Created: September 10, 2025
 */

#include "review.h"

Node* make_node(int data) {
	Node* pNew = (Node*)malloc(sizeof(Node));
	if (!pNew) {
		printf("ERR: make_node() failed to allocate space!\n");
	}
	else {
		pNew->pNext = NULL;
		pNew->data = data;
	}

	return pNew;
}

void insert_front(Node** pHead, int data) {

	Node* pNew = make_node(data);
	pNew->pNext = *pHead;
	*pHead = pNew;
}

void insert_back(Node** pHead, int data) {

	Node* pTemp = *pHead;

	if (!pTemp) { // case 1: empty list -> insert front
		insert_front(pHead, data);
		return;
	}

	while (pTemp->pNext) { // iterate until end of list
		pTemp = pTemp->pNext;
	}

	pTemp->pNext = make_node(data); // link to back
}

void insert_in_order(Node** pHead, int data) {

	Node* pTemp = *pHead;
	
	if (!pTemp || pTemp->data >= data) { // case 1: empty list or new least data
		insert_front(pHead, data);
		return;
	}

	Node* pNew = make_node(data);
	while (pTemp->pNext) {
		if (pTemp->pNext->data > data) { // case 3: somewhere in middle
			pNew->pNext = pTemp->pNext;
			pTemp->pNext = pNew;
			return;
		}

		pTemp = pTemp->pNext;
	}

	pTemp->pNext = pNew; // case 4: insert back
}

void delete_back(Node** pHead) {
	Node* pTemp = *pHead;
	if (!pTemp) {
		return; // empty list
	}

	if (!pTemp->pNext) { // only one element in list
		free(pTemp);
		*pHead = 0;
		return;
	}

	Node* pPrev = pTemp;
	while (pTemp->pNext) { // loop until end
		pPrev = pTemp;
		pTemp = pTemp->pNext;
	}

	// delete end
	free(pTemp);
	pPrev->pNext = 0; // relink end to NULL
}

void delete_front(Node** pHead) {
	Node* pTemp = *pHead;
	if (!pTemp) {
		return; // empty list
	}
	Node* pDelete = pTemp;
	(*pHead) = pTemp->pNext; // relink
	free(pDelete); // delete
}

void delete_index(Node** pHead, int idx) {

	Node* pTemp = *pHead;

	// special case - delete at front
	if (!idx) {
		delete_front(pHead);
		return;
	}

	int count = 1;
	while (pTemp->pNext) {
		if (count++ == idx) { // found idx to delete

			Node* pDelete = pTemp->pNext;
			pTemp->pNext = pDelete->pNext;
			free(pDelete);
			return;
		}

		pTemp = pTemp->pNext;
	}

	// if we get here, idx was not found
}

void delete_all(Node** pHead, int data) {
	Node* pTemp = *pHead;
	if (!pTemp)
		return; // empty list
	int marker = 0;

	// special case - delete at front
	while ((*pHead)->data == data) {
		delete_front(pHead);
		marker = 1;
	}
	if (marker)
		return;

	while (pTemp && pTemp->pNext) {

		while (pTemp->pNext && pTemp->pNext->data == data) { // found data to delete

			Node* pDelete = pTemp->pNext;
			pTemp->pNext = pDelete->pNext;
			free(pDelete);
		}

		pTemp = pTemp->pNext;
	}

	// if we get here, data was not found
}

Node* reverse_list(Node* pHead) {

	Node* pPrev = NULL;
	Node* pCur = pHead;
	Node* pNext = NULL;

	while (pCur != NULL) {
		pNext = pCur->pNext;  
		pCur->pNext = pPrev;
		pPrev = pCur;        
		pCur = pNext;         
	}

	return pPrev; // new head
}

void rec_print_linked_order(Node* pHead) {

	if (!pHead) { // base case
		return;
	}

	printf("%d\n", pHead->data);
	rec_print_linked_order(pHead->pNext);
}

void rec_print_reverse_order(Node* pHead) {
	if (!pHead) {
		return;
	}

	rec_print_reverse_order(pHead->pNext);
	printf("%d\n", pHead->data);
}

void print_list(Node* pHead) {

	while (pHead) {
		printf("%d\n", pHead->data);
		pHead = pHead->pNext;
	}
}