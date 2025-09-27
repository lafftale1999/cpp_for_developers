# Functions

## 1. Hello World
Create a program with a new function. Name the method PrintMessage().

It should return the text: "Hello World!".

## 2. The string joiner
The function should take two input parameters of type string, join them into a single string, and return the new value.

Call the new function from main and print the result to the screen.

## 3. Tax calculation
Create a function that calculates how much the VAT (sales tax) is for a given amount. The amount should be an input parameter of type float and the VAT percentage should be controlled by an Enum.

The function should return the VAT value.

## 4. Doorman
Create a program where the user gets to enter their age.

Create a function that takes the entered value and checks if they are over 18. The function should return true or false;

## 5. Professional yapper
Create a function named findLongestWord() that takes an input of array of strings. The function should return and print the longest word.

## 6. Are we Even, Steven?
Create a program where the user first enters how many numbers they want to enter, then take these and store them in a vector. Create a function that checks if the number is even or odd and then returns the amount of even numbers.

## 7. But that's so random?
Create a program where the user enters a number between 1 and 10. Then create a **recursive** function that:
* Inhabits *at least* one static variable of the type `int total = 0`.
* Check if `total` is higher or lower than the user input
* Generates a random integer between 1 and the users input.
* If `total` is lower than user input, add to `total`
* If `total` is higher than user input, remove from `total`
* If `total` equals the user input - return the amount of tries.
* Write out the amount of tries it took.

To begin with, limit the recursion to a 100 tries. If it does not succeed, return -1. Print out the result in the console.

If you want to spice it up - Try creating iterations where the program runs this calculation continuosly 10 times in a row and write out the results after each iteration.