/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include<stdlib.h>
int date_to_num3(char* date);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction* result = (struct transaction*)malloc(sizeof(struct transaction)*(ALen + BLen));
	int index = 0, ptr1 = 0, ptr2 = 0;
	int A_last = date_to_num3(A[ALen - 1].date);
	while (ptr1<ALen && ptr2<BLen){
		int B_date = date_to_num3(B[ptr2].date);
		if (A_last <= B_date)
			break;
		int A_date = date_to_num3(A[ptr1].date);
		if (A_date <= B_date)
			result[index++] = A[ptr1++];
		else
			result[index++] = B[ptr2++];
	}
	while (ptr1 < ALen){
		result[index++] = A[ptr1++];
	}
	while (ptr2 < BLen){
		result[index++] = B[ptr2++];
	}
	return result;
}

int date_to_num3(char* date){
	int num;
	int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	num = year * 10000 + month * 100 + day;
	return num;
}