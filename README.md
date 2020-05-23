Introduction:
	1)An intal is a nonnegative integer of arbitrary length where every digit is put as a character stored in continuous blocks in the system.
	2)The memory for an intal is given in the form of character arrays however for integers it is allocated in the form of variables in the form of bytes.
	3)Major uses of intal are:
		i)Large numbers operation can be managed without a problem.
		ii)Memory utilization is done perfectly
		iii)It can be used in highly complex mathematical and linear algebra operations.	
				
Approach				
Most of the functions have been implemented using brute force techniques. Some functions use other functions calls in them so as to make the implementation easier, such as the sort and factorial function.				
1.char* intal_add(const char* intal1, const char* intal2):
I have implemented addition function by using brute force algorithm for adding two array of integers. The last two integers in the arrays (or chars) are added and sum is stored in a temporary variable. The value of the variable shouldn’t be more than 10, and if it is the carry should be included in the addition for the next two integers of both the arrays 
2.int intal_compare(const char* intal1, const char* intal2):
I have implemented addition function by using brute force algorithm.The methodology we are utilizing here is, first analyze string lengths if even they are same they check singular digits.

3.char* intal_diff(const char* intal1, const char* intal2):
Have implemented the subtract_intal function such that the larger number is always the one being subtracted from, and the signs of the subtraction are also handled appropriately. The same brute force algorithm is used for subtraction too, but here we are calculating the difference between the last element of the first array and the second array, and checking whether that value is greater than 0. If lesser, then we are borrowing one from the previous element, and adding 10 to the current difference. The subtracted result is stored in the array and the result array is reversed. 

4.char* intal_multiply(const char* intal1, const char* intal2):				I have implemented using brute force multiplication algorithm for this function. the last digit of the multiplier array is multiplied once with the multiplicand and the value is stored in an array. Then, the product of the next multiplier digit is calculated and stored from i’th to the nth digit in the array, and if some value is already present in the array at that position, add that to the existing value. Finally converted the integer array to a character array, keeping in mind that no digit can exceed value more than 10. 
5.char* intal_mod(const char* intal1, const char* intal2):	
The methodology we are utilizing here is, to bring the estimation of intal2 as close as to intal1 then recursively subtract the equivalent and later return the necessary exhibit
				
6.char* intal_pow(const char* intal1, unsigned int n):
The approach we are using here is, to create an array filled with values 1 and later until the whole n is finished in while loop multiplies again and again with the intal1 and later return the required array.

7.char* intal_gcd(const char* intal1, const char* intal2):
I have used Euclid’s algorithm to implement the gcd function. Until one of the numbers become 0 we do mod repeatedly by the above approach.

8.char* intal_fibonacci(unsigned int n):
I have implemented using brute force multiplication algorithm for this function.I have created arrays with values 0 and 1 initially and all the numbers are filled later after computation and the required array is returned.
9.char* intal_factorial(unsigned int n):
I have implemented this using an iterative approach. The multiply function is repeatedly to compute the value of factorial and the value is returned.


10.char* intal_bincoeff(unsigned int n,unsigned int k):
I have implemented this using a dynamic approach.I have used the Pascal's identity C(n,k) = C(n-1,k) + C(n-1,k-1).I have created an array to store corresponding values and the result is returned.

11.int intal_max(char **arr, int n):
I have implemented using brute force multiplication algorithm for this function.Iterating through the intal and finding the greatest element and the index and returning the required offset in the array.

12.int intal_max(char **arr, int n):
I have implemented using brute force multiplication algorithm for this function.Iterating through the intal and finding the smallest element and the index and returning the required offset in the array.

13.int intal_search(char **arr, int n, char* key):
The approach I am using here is a simple linear search algorithm that has a time complexity O(n) where the key is compared with every large array if the key is found that index is returned.

14.int intal_binsearch(char **arr, int n, char* key):
The approach I am using here is a simple binary linear search algorithm that has a time complexity O(n) where the key is compared with every large array if the key is found that index is returned.

15.void intal_sort(char **arr, int n):
Here I am using quick sort algorithm. QuickSort is a Divide and Conquer algorithm. There are partition functions that help in quick sort in linear time.

16.char* coin_row_problem(char **arr, int n):
The approach we are using here is, to use Dynamic programming where every index is updated to as max of(sum of present index value + sum of (present index-2) value,value of present index -1) later the last index value is returned. Time complexity is o(n).
