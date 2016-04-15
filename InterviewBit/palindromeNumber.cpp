// Palindrome Integer
// 
// Determine whether an integer is a palindrome. Do this without extra space.
// 
// A palindrome integer is an integer x for which reverse(x) = x where reverse(x) is x with its digit reversed.
// Negative numbers are not palindromic.
// 
// Example :
// 
// Input : 12121
// Output : True
// 
// Input : 123
// Output : False
// 

#include <math.h>
bool Solution::isPalindrome(int A) {
    if (A<0) return false;
    int digits = 0;
    long long number = A, value = 0;
    while(number){
       value *= 10;
       value += (number%10);
       number /=10;
    }
    return (value==A);
}
