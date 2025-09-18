/*
 * File: lab3.c
 * Author: Martin Hundrup
 * Professor: Andy O'Fallon
 * Class: CPT_S 122, Fall 2025
 * Assignment: Lab 3
 * Created: January 25, 2025
 */

#include "lab3.h"

int fib(int n) {
	if (n <= 1) {
		return n;
	}
	return fib(n - 1) + fib(n - 2);
}

long long int fib2(int n) {

	long long int x = 0;
	long long int y = 1;
	long long int sum = 0;

	for (int i = 0; i < n; i++) {
		sum = x + y;
		y = x;
		x = sum;
	}

	return sum;
}

int main() {

	for (int i = 0; i < 100; i++) {
		printf("fib(%d): %lld\n", i, fib2(i));
	}

	//task_1();
	return 0;
}