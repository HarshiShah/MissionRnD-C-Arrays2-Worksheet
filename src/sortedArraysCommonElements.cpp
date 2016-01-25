/*
OVERVIEW: You are given 2 bank statements that are ordered by date. Write a function that returns dates common to both statements
(ie both statements have transactions in these dates).
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[3] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" }, { 320, "27-08-2015", "Seventh" } };
Output: { { 10, "09-10-2003", "First" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Transactions having same dates.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/


#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};
int search_B(char* date, struct transaction *B, int len);
int date_to_num2(char* date);

struct transaction * sortedArraysCommonElements(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || ALen <= 0 || B == NULL || BLen <= 0)
		return NULL;
	int A_last = date_to_num2(A[ALen - 1].date);
	int B_first = date_to_num2(B[0].date);
	if (A_last < B_first)
		return NULL;
	int index = 0, count = 0, result, last = ALen - 1;
	while (count < ALen){
		result = search_B(A[index].date, B, BLen);
		if (result == -1)
			A[index] = A[last];
		else
			index++;
		count++;
	}
	return A;
}


int search_B(char* date, struct transaction *B, int len){
	int first = 0, last = len - 1, mid, mid_date;
	int req_date = date_to_num2(date);
	mid = (first + last) / 2;
	mid_date = date_to_num2(B[mid].date);
	while (mid >= first && mid <= last){
		if (req_date>mid_date)
			first = mid + 1;
		else if (req_date < mid_date)
			last = mid - 1;
		else
			return 1;
		mid = (first + last) / 2;
		mid_date = date_to_num2(B[mid].date);

	}
	return -1;
}


int date_to_num2(char* date){
	int num;
	int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	num = year * 10000 + month * 100 + day;
	return num;
}