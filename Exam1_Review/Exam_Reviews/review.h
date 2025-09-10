/*
 * File: review.h
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Fall 2025
 * Assignment: Exam 1 Review
 * Created: September 10, 2025
 */

#ifndef REVIEW_H
#define REVIEW_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// node definition
typedef struct node {
	int data;
	struct node* pNext;
}Node;

// creates and initializes a new dynamic node.
Node* make_node(int data);

// inserts data at the front of a list.
void insert_front(Node** pHead, int data);

// inserts data at the end of a list.
void insert_back(Node** pHead, int data);

// inserts data in order.
void insert_in_order(Node** pHead, int data);

// deletes the node at the back of a list.
void delete_back(Node** pHead);

// deletes the node at the front of a list.
void delete_front(Node** pHead);

// deletes a node at a certain index.
void delete_index(Node* pHead, int idx);

// deletes all nodes with a certain value.
void delete_all(Node** pHead, int data);

// reverses a list in a single pass.
Node* reverse_list(Node** pHead);

// recursively prints a list in linked order.
void rec_print_linked_order(Node* pHead);

// recursively prints a list in reverse linked order.
void rec_print_reverse_order(Node* pHead);

// prints a list in linked order.
void print_list(Node* pHead);

#endif
