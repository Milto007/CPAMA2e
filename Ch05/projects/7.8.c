/* project 7.8
 * modify promgramming project 8 from chapter 5 so that the user
 * enters a time using the 12-hour clock. the input will have the
 * form hours:minutes followed by either A, P, AM, or PM (either
 * lower-case or upper-case). White space is allowed (but not 
 * required) between numerical time and the AM/PM indicator. Examples
 * of valid input:
 * 1:15P
 * 1:15PM
 * 1:15p
 * 1:15pm
 * 1:15 P
 * 1:15 PM
 * 1:15 p
 * 1:15 pm
 * you may assume that the input has one of these forms; there is no
 * need to test for errors.
 */

/* project 5.8
 * the following table shows the daily flights from one city to another:
 * departure time       arrival time
 * 8:00 a.m.            10:16 a.m.
 * 9:43 a.m.            11:52 a.m.
 * 11:19 a.m.           1:31 p.m.
 * 12:47 p.m.           3:00 p.m.
 * 2:00 p.m             4:08 p.m.
 * 3:45 p.m             5:55 p.m.
 * 7:00 p.m.            9:20 p.m.
 * 9:45 p.m.            11:58 p.m.
 * write a program that asks user to enter a time (expressed in hours
 * and mintues, using the 24-hour clock). the program then displays
 * the departure and arrive times for the flight whose departure time
 * is closest to that entered by the user:
 * > Enter a 24-hour time: 13:15
 * > Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
 * Hint: convert the input into a time expressed in minutes since
 * midnight and compare it to the departure times, also expressed
 * in minutes since midnight. For example, 13:15 is 13x60 + 15 = 795
 * minutes since midnight since mignight, which is closer to 12:47 (767
 * minutes since midnight) than to any other departure times.
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char ch_dep, ch_arr;
    int hour, minute, result, ans_dep, ans_arr;
    int dep1 = 8 * 60 + 0;
    int dep2 = 9 * 60 + 43;
    int dep3 = 11 * 60 + 19;
    int dep4 = 12 * 60 + 47;
    int dep5 = 14 * 60 + 0;
    int dep6 = 15 * 60 + 45;
    int dep7 = 19 * 60 + 0;
    int dep8 = 21 * 60 + 45;
    int arr1 = 10 * 60 + 16;
    int arr2 = 11 * 60 + 52;
    int arr3 = 13 * 60 + 31;
    int arr4 = 15 * 60 + 0;
    int arr5 = 16 * 60 + 8;
    int arr6 = 17 * 60 + 55;
    int arr7 = 21 * 60 + 20;
    int arr8 = 23 * 60 + 58;

    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &minute);

    result = hour * 60 + minute;
    if (result <= dep1) {
        ans_dep = dep1;
        ch_dep = 'a';
    } else if (result <= (dep2 + dep1) / 2) {
        ans_dep = dep1;
        ch_dep = 'a';
    } else if (result <= (dep3 + dep2) / 2) {
        ans_dep = dep2;
        ch_dep = 'a';
    } else if (result <= (dep4 + dep3) / 2) {
        ans_dep = dep3;
        ch_dep = 'p';
    } else if (result <= (dep5 + dep4) / 2) {
        ans_dep = dep4;
        ch_dep = 'p';
    } else if (result <= (dep6 + dep5) / 2) {
        ans_dep = dep5;
        ch_dep = 'p';
    } else if (result <= (dep7 + dep6) / 2) {
        ans_dep = dep6;
        ch_dep = 'p';
    } else if (result <= (dep8 + dep7) / 2) {
        ans_dep = dep7;
        ch_dep = 'p';
    } else {
        ans_dep = dep8;
        ch_dep = 'p';
    }

    if (ans_dep == dep1) {
        ans_arr = arr1;
        ch_arr = 'a';
    } else if (ans_dep == dep2) {
        ans_arr = arr2;
        ch_arr = 'a';
    } else if (ans_dep == dep3) {
        ans_arr = arr3;
        ch_arr = 'p';
    } else if (ans_dep == dep4) {
        ans_arr = arr4;
        ch_arr = 'p';
    } else if (ans_dep == dep5) {
        ans_arr = arr5;
        ch_arr = 'p';
    } else if (ans_dep == dep6) {
        ans_arr = arr6;
        ch_arr = 'p';
    } else if (ans_dep == dep7) {
        ans_arr = arr7;
        ch_arr = 'p';
    } else if (ans_dep == dep8) {
        ans_arr = arr8;
        ch_arr = 'p';
    }


    printf("Closest departure time is %d:%d ", ans_dep / 60, ans_dep % 60);
    printf("%c.m., arriving at ", ch_dep);
    printf("%d:%.2d ", (ans_arr / 60) % 12, ans_arr % 60);
    printf("%c.m.\n", ch_arr);
    
    return 0;
}
