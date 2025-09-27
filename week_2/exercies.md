# Index
Links to the different exercises for this week.
- [Functions](#functions)
- [File I/O operations](#file-io-operations)

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

## 8. By later calculations
Create a program that takes in two numbers and one operator (make sure to use error handling for I/O).
* Create a function that takes the two numbers, operator and a callback function.
* The operator should decide which operation to be performed and the callback function shall print out the result.

## 9. Overloading everywhere
Create an overloaded function that adds two arguments together. It should be able to take the following:
* String
* Float
* Int
* Char

## 10. What happened?
Create a program that takes in two numbers from the user and then passes it to a function, together with a result variable. The function should do the following:
* Randomly perform these operations once `+, -, /, *`
* Return which operation was performed
* Change the result variable outside of the functions scope

After the function, you should print out something like `<input1> <operator> <input2> = <result>`

## 11. Get your numbers in order
Create a program that generates 10 numbers between 1 and 100 and adds it to a list. Then sort it by descending order.

Print out the result after the sort.

## 12. Save it for later
Create a program that takes in the user full name, phone, address and age. Then create three function variables and assign these with different lambdas. They should do the following:
* Write out the user first name and age.
* Write out the users full name and address.
* Write out the users phone number.

Then call these functions one after another.

# File I/O operations
## 1. Save your highscore
Create a program that where the user is prompted with either (Y) generate a random number or (N) end the program. The program should continue until the user enters (N), then it should save the highest number generated during the execution. If there is a higher number already saved, you should discard the number to be written.

When the program starts, it should look into the file and see if there's a saved highscore, if thats the case - write out the highscore in the console.

## 2. File transfer
Create a program that reads the contents from one file, deletes it and writes it to a new file.

## 3. Sourdough Starter Hotel (yes it's a thing)
Create a program for the sourdough starter hotel staff. The program should present the following options:
* Register new starter
* Show all starters
* Check out a starter
* Exit program

The starters have an id, nickname, age and owner. The id should be automatically generated when registering a new starter.

The information about the sourdough starters should be persistent and saved in CSV format.

