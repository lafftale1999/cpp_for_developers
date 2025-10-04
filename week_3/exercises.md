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