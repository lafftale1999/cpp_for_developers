# EXERCISES WEEK 6 STANDARD TEMPLATE LIBRARY
For all of these exercises you will have to create your own classes and ways of reading the values into memory. You can find the CSV files used in cpp_for_developers/week_6/resources.

# STL introduction

# 1. Bank Accounts
Load 50 customers into `std::vector<Customer>` using the `bank_accounts.csv` file
## 1.1. Iterating Through a customer list
Loop through all of them using `std::for_each` and print their account_number.

## 1.2. Iterator loop
Declare a variable to store the sum of all accounts in. Use the above 50 customers and loop through the list using an iterator for-loop.

```cpp
for (auto it = /* beginning of container */ ;  it != /* end of container */ ; it++) {
    /* Block of code */
}
```

## 1.3. Copy if
Use the `std::copy_if` algorithm to copy customers into a new `std::vector<Customer>` if their balance is over 200 000.

## 1.4. Map the customers
Load in 50 customers into `std::map<int, Customer` and assign the `customer_number` as key in the map. Iterate through the map and print each customer information like this:

```
1 | WFBIUS6S | Millisent Medforth | 234080
```

# 2. Movies
## 2.1. Count movies in a genre
Load in all the movies into memory (Some of them might be formated wrong and you need to handle this exception!). Load them into an `std::deque<Movie>` then create a map `std::map<Genre, int>` and count how many there are for each genre.

Print out the result.

## 2.2. Sort all the movies by year
Sort all the movies by year and then print out the 50 first movies in the container.

## 2.3. Remove movies by Title
Remove all the movies with the word "Big" in them. After you've implemented it, check using the `std::any_of` search function to make sure it worked.

## 2.4. Print movies by title
Create a program that takes in a genre from the user and then print out all movies within that genre.

# 3. Temperature Readings
Load all temperature readings into a `std::vector<TemperatureReadings>`. 

## 3.1. Clean up temperature readings
Remove all readings between 50 and 100 celsius.

## 3.2. Sort the readings
Sort the temperature readings from the oldest to newest reading.

## 3.3. Count readings
Count all readings above 30 degrees and then post the result.