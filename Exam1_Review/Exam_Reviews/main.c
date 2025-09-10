/*
 * File: main.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Fall 2025
 * Assignment: Exam 1 Review
 * Created: September 10, 2025
 */

#include "review.h"

int main() {

	srand(time(NULL));
	Node* pHead = NULL;

	for (int i = 0; i < 10; i++) {
		insert_in_order(&pHead, i);
	}


	printf("START OF LIST\n");
	print_list(pHead);

	printf("DELETE FRONT IDX\n");
	delete_index(&pHead, 0);
	print_list(pHead);
	
	printf("DELETE BACK IDX\n");
	delete_index(&pHead, 8);
	print_list(pHead);

	printf("DELETE MIDDLE\n");
	delete_index(&pHead, 4);
	print_list(pHead);

	printf("DELETE BACK\n");
	delete_back(&pHead);
	print_list(pHead);

	printf("DELETE FRONT\n");
	delete_front(&pHead);
	print_list(pHead);

	printf("DELETE ALL\n");
	while (pHead) {
		delete_index(&pHead, 0);
	}
	print_list(pHead);

	return 0;
}