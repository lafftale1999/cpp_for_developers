# Control Statements
## 1. Compare a Number with 10
Ask the user to enter a number.
* If the number is greater than 10, print: “The number is greater than 10.”
* If the number is less than 10, print: “The number is less than 10.”

## 2. Got milk?
Ask the user how many milk cartons are left.
* If the number is less than 10, print: "Order 30 cartons.”
* If the number is between 10 and 20 (inclusive), print: “Order 20 cartons.”
* Otherwise, print: “You don’t need to order any milk.”

## 3. Fever Check
Ask the user to enter their temperature from a thermometer.
* If the temperature is above 39.5, print: “You should see a doctor.”
* Else if it is above 37.8, print: “You have a fever.”
* If the temperature is below or equal to 37.8, print: “You do not have a fever.”

## 4. Age Check
Ask the user to enter their age.
* If the age is less than 18, print: “You are not an adult.”
* If the age is over 65, print: “You are a pensioner.”
* Otherwise, print: “You are an adult but not a pensioner.”

Bonus Task: Check that the input is a valid number.
If the user enters anything other than digits, print:
*“Invalid input. Please enter a valid age.”*

## 5. Tickets please!
Ask the user to enter their category: adult, pensioner, or student.
* If the user is a pensioner or student, print: “The ticket costs 20 SEK.”
* If the user is an adult, print: “The ticket costs 30 SEK.”
* Otherwise, print: “Invalid category entered.”

## 6. Scandinavia Check
Ask the user to enter the name of the country they live in.
* If it is Sweden, Denmark, or Norway, print: “You live in Scandinavia.”
* Otherwise, print: “You do not live in Scandinavia.”

## 7. Fast food choices
Ask the user how much money they have and then ask if they have a discount.

Decide what they can buy:
* If they have 15–25 (no discount) → “You can buy a small hamburger.”
* If they have 15–25 (with discount) → “You can buy a small hamburger and fries.”
* If they have 26–50 (no discount) → “You can buy a large hamburger.”
* If they have 26–50 (with discount) → “You can buy a large hamburger and fries.”
* If they have more than 60, or between 50–60 with discount → “You can buy a meal with a drink.”

---

# Loops
## 1. Print Numbers 0 to 10
Write a program that prints the numbers 0 to 10 on the screen.
Solve this using a for-loop

## 2. Numbers Between Two Values
Ask the user to enter two numbers.
Print all the numbers between those two values on the screen.
Solve this using a for-loop.

## 3. Repeat Until User Quits
Ask the user to enter two numbers.

Print the sum of the two numbers.

Then ask: “Do you want to continue (Y/N)?”
* If the user enters Y, repeat the steps.
* If the user enters N, stop the program.

## 4. Sum of 10 Inputs
Ask the user to enter a number. Repeat this 10 times, adding each input to a total.

After all inputs, print:
“The sum of the numbers you entered is: [total].”

## 5. Temperature Alarm

Continuously ask the user to enter temperature values.

Calculate the average of the last three values entered.

If the average is greater than 25, print: “Alarm!”

## 6. Numbers Less Than Input

Ask the user to enter a number.

Print all the numbers that are greater than 0 but less than the entered number.

Solve this using a loop.

## 7. Rolling Dice

Simulate rolling two dice and display the result.

After each roll, ask the user: “Roll again (y/yes)?”

Keep rolling until the user enters something other than “y” or “yes”.

---

# Harder exercises
These are made to touch on all subjects we've learned this week. Make sure that all I/O operations are protected with try/catch.
## 1. Make it secret
We are trying to send a secret message but we need to make it more secretive. Create an application that takes in a sentence and then replace every vowel with *.

## 2. The Bandit Language
In Sweden we have a secret language called "the bandit language". This is made of extending every consonante with 'o' and itself. For example, my name would be Cocarorlol.

Write a program that takes in a name and translates it into the bandit language. Make sure that you handle exceptions.

## 3. Finally a good Calculator
Create a program that works like a simple calculator with the following rules:

**Input format**

The user enters numbers and operators (+, -, *, /) one at a time.
* Example: 5, then +, then 3.

**Performing calculations**

If the user enters number → operator → number, the program performs the calculation and shows the result.

* Example: 5 + 3 = 8.

**Replacing inputs**

If the user enters a number directly after another number, the new number replaces the previous one.

* Example: 5 then 7 → the calculator keeps 7.

If the user enters an operator directly after another operator, the new operator replaces the previous one.

* Example: + then - → the calculator keeps -.

**Exit condition**

If the user enters X, the program should stop.

## 4. Caesar Cipher
This cipher-method was used by Julius Caeser for his private correspondence, therefore name the Caeser Cipher. This works by shifting the characters N times to the right in the alphabet. So for example if the key is 4, 'A' would be 'E'.

Write a program that:
* Asks the user for a number to encrypt the message.
* Encrypt the message by the Caeser method and print out the result
* Decrypt the message and print out the result

## 5. The Guessing Game
Generate a random number between 0 and 100 and then let the user guess until they give the correct answer.
* Add hints to the user
* If the user enters 'X' - end the game
* After a round is finished, give the user the option to play another round or finish the game
* Save their highscore of amount of tries
* When they decide to stop playing, print out their best round