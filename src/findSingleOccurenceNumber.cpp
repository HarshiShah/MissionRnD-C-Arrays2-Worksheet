/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
*/

#include <stdio.h>
void qSort(int *x, int start, int end);
void swap(int* a, int* b);

int findSingleOccurenceNumber(int *A, int len){
	if (A == NULL)
		return -1;
	if (len == 1)
		return A[0];
	if (len <= 3)
		return -1;
	qSort(A, 0, len - 1);
	int index = 0, sum = A[0] + A[1] + A[2];
	while (sum / A[index] == 3){
		index += 3;
		sum = A[index] + A[index + 1] + A[index + 2];
	}
	return A[index];
}

void qSort(int *x, int start, int end){
	int pivot, j, i;
	if (start<end){
		pivot = start;
		i = start;
		j = end;

		while (i<j){
			while (x[i] <= x[pivot] && i<end)
				i++;
			while (x[j]>x[pivot])
				j--;
			if (i<j){
				swap(&x[i], &x[j]);
			}
		}

		swap(&x[pivot], &x[j]);
		qSort(x, start, j - 1);
		qSort(x, j + 1, end);

	}
}
void swap(int* a, int* b){
	int temp = *a;
	*a = *b;
	*b = temp;
}