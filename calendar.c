/*
In this project, I made my own mini-calendar with some cool functionalities! 

The functions I created answer simple questions like:

- Is the given year a leap year?
- What is the new date 500 days from today?
*/

#include <stdio.h>
#include <stdbool.h>


int days_in_month[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
char *months[]=
{
	" ",
	"\n\n\nJanuary",
	"\n\n\nFebruary",
	"\n\n\nMarch",
	"\n\n\nApril",
  "\n\n\nMay",
	"\n\n\nJune",
	"\n\n\nJuly",
	"\n\n\nAugust",
	"\n\n\nSeptember",
	"\n\n\nOctober",
	"\n\n\nNovember",
	"\n\n\nDecember"
};

// ......................................................................................................

bool is_leap_year(int year) {
    
    return (year % 4 == 0 && (year % 100 || year % 400 == 0));
      
}

//.......................................................................................................

void add_days_to_date(int *mm, int *dd, int *yy, int days_left_to_add) {

  int days_left_in_month;
  
  while (days_left_to_add > 0) {

    // Part 1 of while loop
    days_left_in_month = days_in_month[*mm] - *dd;

    // Part 2 of while loop
    if (*mm = 2 && is_leap_year(*yy) == true) {
      days_left_in_month++;
      *mm = *mm + 1;
    }

    
    // Part 3 of while loop
    if (days_left_to_add > days_left_in_month) {
      
      days_left_to_add -= days_left_in_month + 1; 
      *dd = 1; 

      if (*mm == 12) { 
        *mm = 1; 
        *yy = *yy + 1; 
      }
      else *mm = *mm + 1; 
    } 
    else { 
      *dd = *dd + days_left_to_add; 
      days_left_to_add = 0; 
    }
  }
}

// ......................................................................................................

int main() {

  // Uncomment code below to determine Leap Year
  //int year;

  //printf("Please input a year between 1800 and 10000: \n");
  //scanf("%d", &year);
  //if (is_leap_year(year) == true) {
    //printf("Leap Year!\n");
  //} else {
    //printf("Not Leap Year!\n");
  //}  

  int mm, dd, yy, days_left_to_add;
  printf("Please enter a date and provide the number of days to add to this date (ex. 2 28 2020 2): \n");
  scanf("%d%d%d%d", &mm, &dd, &yy, &days_left_to_add);

  add_days_to_date(&mm, &dd, &yy, days_left_to_add);
  
  printf("%d%d%d", mm, dd, yy);
  
}

// Output
// 3 1 2020

