# Index
Links to the different exercises for this week.
- [Functions](#functions)
- [File I/O operations](#file-io-operations)
- [OOP Introduction](#oop-introduction)

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

# OOP introduction

## 1. Person Class

We want to model a Person in C++. Each person should store the following information:
* BirthDate (mandatory)
* FirstName
* LastName
* StreetAddress
* PostalCode
* City

**Step 1:** Create the class

* Make a class called Person. 
* Add instance variables (private data members) for all the attributes above.

**Step 2:** Constructor
* A Person must always have a BirthDate (this is mandatory).
* All other attributes (name, address, etc.) can be set later.

  > Can you design the constructor so the other parameters are optional?

**Step 3:** Member functions
* Implement at least these functions:

    * GiveName()

        Returns the full name of the person (first + last name).

    * ChangeAddress(...)

        Updates the address (street, postal code, city).

    * MoveInto(const Person& other)

        Makes the person “move into” another person’s address (copies the address from other).

**Step 4:** Main program
* Create two Person objects.

* Set names and addresses for both.

* Then, make one of them move into the other’s address using your function.

## 2. Hero of Ciplus
Create a simple role-playing game where the player can first enter their name.

Then choose to:
```
Hero of Ciplus
------------------------
1. Battle the next enemy
2. Exit game
Enter option:
```

**Battle the next enemy**

A battle should render the following screen:
```
<player name>                   <enemy name>
HP: <player hp>                 HP: <enemy HP>

----------------------------------------------
Choose action:
1. Attack
2. Admit defeat
Enter option:
```

Then enemy will automatically attack after the player have attacked. Show information about the attack and then re-render the screen with the updated HP-values.

**Instructions**

**Character**

Create a class that represents a character. The character should have these attributes:
* Name
* Health Points (HP for short)

Methods:
* Attack()
* Defend() - for when the oppenent attacks

**Graphics**

Create a class that represents the graphics, that holds logic for showing the menu options and rendering the screen.

**BONUS**

Try applying experience points, level up logic, different attacks and/or health bars. Try saving the process in a file.

## 3. Administration System
Create a program where the first time it's started the user needs to enter a username and password. After the credentials are created and everytime the program runs after - the user needs to enter the credentials to enter the program.

This system will handle the following:
* Add staff members
* List staff members
* Remove staff member
* Exit

**Staff member**

A staff member should include:
* Name
* Age
* Email
* Position
* Monthly Salary

Make sure to validate all data. Email addresses must be validated by a standard format of name@domain.country. Position should be an enum and people below age of 30 can't be assigned SUPERVISOR. People over 30 can't make below 30000.

All data for this program must be persistent.

## 4. Dog Kennel Register
Write a program that manages a small registry of dogs in a kennel. For each registered dog, the following information should be stored: name, breed, age and weight. A dog also has a tail length which is calculated with this formula:

```
length = age * weight / 10
```

The program should be command-driven, supporting four commands:

1. **Register**
    
    The user is asked for the dog's name, breed, age and weight. Add the dog to the kennel registry.

2. **List**

    The user is asked for a minimum tail length. The program then prints all dogs whose tail length is greater than or equal to the given minimum.

    When listing the dogs it should be in this format:
    ```
    Dog name: <dogName> | Breed: <dogBreed> | Age: <dogAge> | Weight: <dogWeight> | Tail: <dogTailLength> cm
    ```

3. **Remove**

    The user is asked for the name of the dog to remove. Write out the result of the operations to the console.

4. **Exit**

    Program ends.

**IMPORTANT**

The dogs in the registry should be persistent and saved in a CSV format. This means that when starting the program, you should load all existing dogs into memory and also save them when exiting.