# Exercises for Inheritance, Abstract Classes and Polymorhpism
At this point, I should not have to remind you, that all classes should be encapsulated and validate data. It does make the exercises more complex, but also gives great practice.

# Inheritance

## 1. Vehicle Fleet
Create a base Vehicle class with common properties (e.g., brand, maxSpeed) and methods (e.g., start(), stop()), and derive Car, Bicycle, and Bus classes.
Give each derived class its own additional behavior (e.g., openTrunk() for Car).

Create some objects and call their methods to see inheritance in action.

## 2. Digital Library
Model a simple media library with a base Media class (title, duration).
Derive Song, Podcast, and Audiobook. Each has unique extra data (e.g., artist for songs, host for podcasts).

Write a function that prints out a short summary for each type.

## 3. Game Characters
Create a base Character with health and name. Derive Warrior, Mage, and Archer.
Give each a unique attack() implementation.

Use inheritance to avoid repeating shared stats but allow specialization of actions.

# Abstract Classes
Remember that all abstract classes also need virtual destructors.

## 1. Notification Interface
Create an abstract class Notifier with a pure virtual send(std::string message).
Implement EmailNotifier, SMSNotifier, and PushNotifier.

Write a simple function that takes a Notifier& and sends a "Hello" message.

## 2. Command Interface
Create an abstract class Command with a single method execute(). Now implement commands like ReadFileCommand, SaveFileCommand and ExitCommand. These should perform said commands.

Create a txt file with a famous quote you like.

Create a list and run the commands in sequence.

## 3. Payment interface
Create an abstract class ProcessPayment with the methods processPayment, savePayment, seeTransactionHistory. The transaction should contain the date and amount and be saved in CSV format.

Implement the classes:
* FoodPayment - the result fluctuates randomly between 90 - 110% of the passed amount
* RenovationPayment - add 100% as an installation fee
* AirplanePayment - there's a 50% risk the payment doesn't go through

## 4. Build a vehicle
Create several abstract classes that can build a vehicle. For example Engine, Housable, Movable, Radio, Loadable and a base class called vehicle.

Now implement these in:
* Bicycle
* Car
* RV
* Truck

# Polymorphism

## 1. Logger
Loggers are used in system to provide feedback to us developers. These can debug messages, exceptions throwed in a live application or security breaches.

Define an abstract class called Logger with the member function log(std::string message). Then implement ConsoleLogger, FileLogger and SilentLogger. Add all the loggers to a `std::vector<Logger*> loggers`.

Create a function runApp(Logger& logger) that logs several different messages. The function should use logger.log("a string") and log several different messages. 

Loop through `loggers` and call runApp().

## 2. Travel Calculator
Map apps like Google Maps use polymorphism for different type of travle modes. Define an abstract base class called TransportMode with the member function `travel(float distanceInKM)` which returns the time it takes travel.

Implement `CarMode`, `BikeMode` and `WalkMode` with different speeds. Then write a function which takes a TransportMode reference and return the value.

Create a console program which prompts the user to enter how long they want to travel and then write out the result of each suggestion.

## 3. NPC Dialogue System
Games rely heavily on polymorphism. Define an abstract NPC class with a `speak()` method. It should also include private attributes name, faction and level.

Implement Knight, Innkeeper and Blacksmith - each with unique dialogues. Store these in a `std::vector<NPC*>`.

Create a program that lists their name and faction. Give the user the option to speak to one of them and call their speak() function. Remember that this should be called throught polymorphism and not by the instantiated object itself.

## 4. Data Saver
Define an abstract function called Serializer with the pure virtual member function `save(map<string, string>& data, string& filePath)`. We haven't used maps yet, but this will be a good introduction for when we dive into data structures. Short explanation is that they consist of key-value pairs, in this exercise the keys can be viewed as headlines that define what the data is about and values are the data. Look up more information online!

Implement CsvSerializer, JsonSerializer and XmlSerializer. These should parse the map into the correct format into the filePath.

Create a program that prompts the user to:
1. Enter a file name
1. While user hasn't entered `exit`
    1. Enter key name
    1. Enter value for key
1. When done, ask which format to save in
1. Save in that format to the entered file name

# Pointers

## 1. Pointer fundamentals
Create a program that declares the variable `age`, then declares a pointer to the variable. Then:
* Print out the addresse of the variable using `&`
* Print out the stored value in the pointer
* Print out the dereferenced value from the pointer
* Finally, modify the variable through the pointer and

## 2. What happened?
Create a program with two doubles `x` and `y`. Create a function that takes in the address of two doubles and perform a random operation (`+`, `-`, `*`, `/`) on their dereferenced values. Return an enumerated value that informs the caller which operation was performed and then print a message.

Example of print out if a division was performed: `<x> / <y> = <result>`

## 3. Copy function
Create a C string `name` - which is an array[] of characters that is `'\0'`-terminated, that holds your name. Create another empty C string `copiedString` that is ensured to fit the `sizeof(name)`.

Create a function `copy()` that takes a pointer to the string to copy and another pointer to the string which should hold the copy. Loop through the string and copy its value to the other string.

> **IMPORTANT:** Remember to make sure the function can't move the pointer outside of the char array[]!

## 4. Dynamic Allocation
Create a program that asks the user for their age and then dynamically allocates this on the heap. Then ask to confirm their age again and control if it's the same age, if not - modify the value.

Print out the pointer value and then the dereferenced value.

Remember to delete the variable!

## 5. Transaction Ledger
Create a program that asks the user for how many transactions they want to store `int amountOfTransactions` and then heap-allocate an `int array[]` of size `amountOfTransactions`.

Using pointer arithmetic (not indexing), get the user input and write the values into the array.

Create 3 functions that prints out the:
1. Total sum of all transactions
1. Largest transaction
1. Average of all transactions

If you want to learn more about pointers:
* Try implementing the function `int* findAmount(amount)` that returns a pointer to the first matching transaction or `nullptr`. Write out either the amount or that it couldn't be found.

Remember to `delete[]` your allocated array[].

## 6. Shipping Cost Calculator
Create a program that uses polymorphic behaviour to suggest shipping methods.

1. Create a base class `Transport`
    * A pure virtual function that takes in a package weight in `kg` and and the distance to be shipped in `km` and then returns the calculated cost as a `double`.
    * A virtual ~destructor
    * Private fields:
        * transportMethodName
        * startCost
        * costPerKM
        * costPerKG

2. Create three simple classes:
    * `Ground` (cheap per km, cheap per kg, small startUpCost)
    * `Air` (expensive per km, expensive per kg, large startUpCost)
    * `Train` (cheap per km, cheap per kg, medium startUpCost)
    * `ExpressGround` (cheap per km, cheap per kg, extremely high startUpCost)

3. User logic:
    * Ask the user to enter their package's weight (kg) and the distance to be shipped (km)
    * Instantiate all objects on the heap with pointers *
    * Store them as `Transport*` pointers in an array[]
    * Loop through the array of `Transport*` and display the result.
        > Tip: `[i] == *(ptr + i)`

### Stretch
Ask the user if they want to choose the cheapest alternative and implement a way to automatically choose the cheapest alternative and print it out.

# References

## 1. Basic reference
Create a program where you initialize an `int` with value and create a reference to it.

Print out the value stored in the `int` and then print out the value of the reference.

## 2. Reference Calculator
Create a program that ask the user for a number, then a valid operator and then another number. Create a function that takes references to these numbers and an enumerated value for which operation should be performed.

Print out the result like this:

`<number1> <operator (+, -, /, *)> <number2> = <result>`

## 3. Packaging Manager
Create a program that helps the user manage their logistics for shipping. Create a base class called `PackageInformation` which contains weight in grams and value in SEK, aswell as a virtual function printCost(). Then create three interfaces called:
* **Flammable** - shipping cost matches 50% of the package value
* **Fragile** - shipping cost is equal to 100 SEK + 10% of the package weight in grams
* **Liquid** - shipping cost is equal to value / 10 + 50 SEK
* **Normal** - 50 SEK

Store these objects in a vector<PackageInformation*> and create a function that takes a reference to this vector. The function should print out the package information and the cost for it.
The program should:
1. Ask the user how many packages they want to ship.
1. Enter the package weight, value and type
1. When they have entered the information for all packages - print out the information

## 4. 