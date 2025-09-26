# Exercises Data Types
These are all the exercises for data types and basic I/O operations. Remember to try and solve the problem first in your own way, your most important skill is problem-solving!

If you want to check your answer, you can have a look at the exercise examples located in this directory.

## 1. Hello World
This is an ode to the original release of the K&R C book from the 70s. Create a program that prints out the universal greeting: "Hello, World".

## 2. Year Calculator
Create a program that asks the user which year they were born and then tells them how old they are today.

## 3. Present yourself
The Intergalactic Council requires you to register your identity before entering the system.
Write a program that asks for your name, age, address, phone number, and email, then prints them back in a tidy format—your digital passport!

## 4. Calculator: Addition
You’ve found two treasure chests with gold coins inside.
Write a program that asks how many coins are in each chest, then calculates the total treasure by adding them together.

## 5. Calculator: Division
Two bottles of mysterious liquid must be divided between two adventurers.
Create a program that takes in two numbers (representing volumes) and divides one by the other, showing the result. Be careful: division is trickier than addition!

## 6. Time Calculator
A wise old Timekeeper gives you a certain number of minutes (at least 60) and asks you to convert them into hours and minutes.
Write a program that performs this magical conversion.

## 7. No Loose Change
You’re helping a merchant at the market. A customer hands over a pile of SEK, and you need to give them change using the fewest bills and coins possible.
Write a program that takes an amount of SEK and breaks it down into the largest possible denominations first.

Example:

346 SEK:

1000-note: 0 pcs

500-note: 0 pcs

200-note: 1 pcs

100-note: 1 pcs

50-note: 0 pcs

20-note: 2 pcs 

10-coin: 2pcs         

5-coin: 1 pcs

2-coin: 0 pcs

1-coin: 1 pcs

## 8. I am very loud
The sound is very loud on your computer, forcing you to change all your input to caps lock. Create a program that takes in a lower case string and turns it into uppercase.

## 9. Wordfeud this!
You are about to loose in a wordfeud game, luckily your programming skills comes in handy. Write a program that takes in two words and the combines the first half of the first word with the second half of the second word.

## 10. Initials maker
Everything is in such a hurry, we need you to be named after your initials from now on. Make a program that takes in your full name and then prints out your initials.

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