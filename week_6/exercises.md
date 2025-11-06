# EXERCISES WEEK 6 STANDARD TEMPLATE LIBRARY
These exercises will make use of the .csv files in [resources/*](resources/). You will find the following files in this folder:

**bank_accounts.csv**
```
customer_number,account_number,full_name,balance
```

**employees.csv**
```
id,first_name,last_name,email
```

**movies.csv**
```
movieId,title,year,genres
```

**temperature_readings.csv**
```
id,serial_number,timestamp,temperature
```

The exercises down below will make use of the data in these files, which means that you have to create ways of reading the files, relevant classes and ways to parse them into classes.

# STL introduction
In this part you find the exercises for the begginer concepts of the Standard Template Library.


## 1. Bank Accounts

### 1.1. Load into memory
Load 50 customers into `std::vector<Customer>` using the `bank_accounts.csv` file

---

### 1.2. Iterating Through a customer list
Loop through all of them using `std::for_each` and print the account_number.

---

### 1.3. Iterator loop
Declare a variable to store the sum of all accounts in. Use the above 50 customers and loop through the list using an iterator for-loop.

```cpp
type var_name = 0;

for (auto it = /* beginning of container */ ;  it != /* end of container */ ; it++) {
    /* Block of code */
}
```

---

### 1.4. Copy if
Use the `std::copy_if` algorithm to copy customers into a new `std::vector<Customer>` if their balance is over 200 000.

---

### 1.5. Map the customers
Copy 50 customers from your initial customer vector to an `std::map<int, Customer>` and assign `customer_number` as key in the map. Iterate through the container and print each customer information like this:

```
1 | WFBIUS6S | Millisent Medforth | 234080
```

---

### 1.6 Search in map
Search the `std::map<int, Customer>` by value, trying to find the account owned by: `Sarina McDavitt`.

Print out the account information like this:

```
29 | RZOOAT2L110 | Sarina McDavitt | 102772
```

---

## 2. Movies

### 2.1. Load into memory
Load all the movies into memory, some of these might be formated wrong and you need to handle these exceptions to avoid unexpected behaviour. Load them into an `std::deque<Movie>`.

---

### 2.2. Count genres
Create a `std::unordered_map<Genre, int>` and copy all the genres into this map. Use this container to count how many movies there are in every genre. This is achieved by handling exceptions when the key (Genre name) already exists within the *map*. 

Print out the result of the operation by looping through the map and print the Genre name and count.

**You need to overload the following in your class**
```cpp
#include <functional>
#include <string>

class Genre {
private:
    std::string name;
    /* Attributes and private methods */

public:
    /* Constructors, getters, setters, public methods */

    // Equality operator
    bool operator==(const Genre& other) const noexcept {
        return name == other.name;
    }

    // Hash function for hashing the Genre objects
    struct Hasher {
        size_t operator()(const Genre& g) const noexcept {
            return std::hash<std::string>{}(g.name);
        }
    };
};
```

---

### 2.3. Sort all the movies by title
Use the `std::deque<Movie>` again. Sort all the movies by their title from A to Z and then print out the first 50 movies.

---

### 2.4. Remove movies by Title
Delete all the movies with the word "Big" in them. When you delete the movie you should print out its information like this:

```
Removed: Steal Big, Steal Little
```

Use `std::any_of` search function to make sure it worked.

---

### 2.5. Print movies by title
Create a program that asks the user for a genre (not case-sensitive). This should either show an error message if the genre doesnt exists or print out *all* the movies in that genre like this:

```
98 | Shopping | 1994
100 | City Hall | 1996
...
```

---

## 3. Temperature Readings

### 3.1. Load all readings
Load all temperature readings into a `std::vector<TemperatureReadings>`.

> **Note:** The timestamps are sent in Unix timestamp format, meaning it's the count of seconds since 1970.

---

### 3.2. Clean up temperature readings
Remove all readings above 40 degrees celsius.

---

### 3.3. Sort the readings
Sort the temperature readings from the oldest to newest reading using their timestamps.

Print out the first 50 readings like this:

2025-01-29 10:03:40

```
// id - serial number - parsed timestamp - temperature
19 - 8709dcry47875 - 2025-03-02 02:58:27 - 34.19
21 - 6932iycr12793 - 2025-03-13 18:26:48 - 4.37
18 - 5901pojd48789 - 2025-04-22 07:34:00 - 35.35
...
```

---

### 3.4. Count readings
Count all readings above 30 degrees and then post the result.

`Readings above 30 degrees celsius: X`

---

### 3.5. Find the extremes
Find the hottest and the coldest temperature reading. Print out the result.

```
Coldest temperature: X degrees celsius
Hottest temperature: Y degrees celsius
```

---

# STL Continuation
In these exercises we will make use of the data in `employees.csv` found in [resources/employees.csv](resources/employees.csv)

Start by loading in all employees into a `std::vector<Employee>`.

## 1. Ranges

### 1.1. Loop through
Loop through the vector using `for_each_n` and print out the first 20 employees like this:

`first_name last_name email`

---

### 1.2. Count first initials
Count the employees whose **last_name** starts with S (case-sensitive) using the `count_if` algorithm for ranges.

Print out the result:

```
Employees whose last name starts with S: X
```

---

### 1.3. Sort by name
Sort the employees by their last name. If they have the same last name, sort by their first name. Print out the first 50 employees.

---

### 1.4. Print out all employees with @google.com
Print out all the employees with the email domain @google.com.

---

## 2. Views

### 2.1. Filter the employees
Print out all the employees who's first name starts with a 'T' in the following format:

```
103 | Trix Ranken | tranken2u@nifty.com
```

---

### 2.2. Filter the employees by email
Print out all the employees with an email domain `@google.com` - Print it out in the same format as in [2.1. Filter the employees](#21-filter-the-employees).

---

### 2.3. Transform the Employee object
Use `std::views::transformation()` to transform the `Employee` into an `std::string` and print out the string using the same filter and format as in [2.2. Filter the employees by email](#22-filter-the-employees-by-email).

---

### 2.4. Find the correct people
Create a program that will:
* Take two `int` inputs from the user between 1 and 1000.
* Loops through a view pipeline based on:
    * Filter predicate: Employee ID is between `input1` and `input2`.
    * Transformation: Employee information -> std::string
    * Print out the string

---

### 2.5. Only long names!
Create a program that:
* Loops through a view pipeline based on:
    * Transforming their first and last name into one variable.
    * Filter by the length of their full name is longer than 15 characters.
    * Print out their full name and the length of it!

```
Vaughan Petrakov | Length: 15 Characters
```

---

### 2.6. The first 10
Use the previous solution from [2.5. Only long names!](#25-only-long-names) and apply `std::views::take()` to limit how many elements you want to loop through by **10**.

---

### 2.7. Reverse
Use the previous solution from [2.6. The first 10](#26-the-first-10) and reverse the result.

---

### 2.8. Reusable pipelines
Define one variable `std::string emailDomainTarget` and enter an email domain known in the .csv file. Declare two lambdas that:
* Lambda 1: Captures `&emailDomainTarget` and uses this to find `Employees` who's email adress contains the targeted domain.
* Lambda 2: Transforms this elements into `std::string` that returns their full name and Company they are working for.

Use these variables to compose a pipeline you can iterate through - like this:

```cpp
for (auto&& employee : employeeList | std::views::filter(lambda1) | std::views::transform(lambda2)) {
    std::cout << employee << std::endl;
}
```

---

### 2.9. Reverse after and before take()
Use the previous exercises solution in [2.8. Reusable pipelines](#28-reusable-pipelines) and try the following:

```cpp
// Reverse before take(5)
auto employee_view1 = employeeList
    | std::views::filter(lambda1)
    | std::views::transform([](const auto& e){ return e.lastName()})
    | std::views::reverse
    | std::views::take(5);

// Reverse after take(5)
auto employee_view2 = employeeList
    | std::views::filter(lambda1)
    | std::views::transform([](const auto& e){ return e.lastName()})
    | std::views::take(5)
    | std::views::reverse;
```

What is causing this behaviour?

---

## 3. Coroutines
