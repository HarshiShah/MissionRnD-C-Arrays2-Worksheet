/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

int date_to_num(char* date);
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int date_to_num(char* date){
	int num;
	int year = (date[6] - '0') * 1000 + (date[7] - '0') * 100 + (date[8] - '0') * 10 + (date[9] - '0');
	int month = (date[3] - '0') * 10 + (date[4] - '0');
	int day = (date[0] - '0') * 10 + (date[1] - '0');
	num = year * 10000 + month * 100 + day;
	return num;
}

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	if (len <= 0 || date == '\0')
		return -1;
	int first = 0, last = len - 1, mid = 0, mid_date;
	int req_date = date_to_num(date);
	int first_date = date_to_num(Arr[first].date);
	int last_date = date_to_num(Arr[last].date);
	if (first_date > req_date)
		return len;
	else if (last_date <= req_date)
		return 0;
	else{
		mid = (first + last) / 2;
		mid_date = date_to_num(Arr[mid].date);
		while (mid >= first && mid <= last){
			if (req_date>mid_date)
				first = mid + 1;
			else if (req_date < mid_date)
				last = mid - 1;
			else{
				int next_date = date_to_num(Arr[mid + 1].date);
				if (next_date == mid_date)
					first = mid + 1;
				else
					return (len - (mid + 1));
			}
			mid = (first + last) / 2;
			mid_date = date_to_num(Arr[mid].date);
		}
	}
	return 0;
}

