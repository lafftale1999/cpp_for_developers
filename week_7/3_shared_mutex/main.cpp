#include <iostream>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <shared_mutex>
#include <initializer_list>
#include <algorithm>
#include <ranges>

enum TransactionResult {
    TRANSACTION_SUCCESS,
    INSUFFICIENT_FUNDS,
    ACCOUNT_NOT_FOUND,
    NEGATIVE_AMOUNT_ENTERED,
    TRANSACTION_FAILED
};

std::string toString(TransactionResult tr) {
    switch (tr) {
        case TRANSACTION_SUCCESS: return "SUCCESS";
        case INSUFFICIENT_FUNDS: return "Insufficient funds";
        case ACCOUNT_NOT_FOUND: return "Account not found";
        case NEGATIVE_AMOUNT_ENTERED: return "Negative amount entered";
        case TRANSACTION_FAILED: return "Transaction failed unexpectedly";
    }
}

class Account {
public:
    std::string account_number;
    std::string account_holder;
    double balance;

    Account(std::string _account_number, std::string _account_holder, double _balance)
    : account_number(_account_number), account_holder(_account_holder), balance(_balance) {
        if (account_holder.empty() || account_number.empty()) {
            throw std::invalid_argument("Need to enter an account holder and account number!");
        }
    }

    TransactionResult withdraw(double amount) {
        if (amount > balance) return INSUFFICIENT_FUNDS;
        
        balance -= amount;
        return TRANSACTION_SUCCESS;
    }

    TransactionResult insert(double amount) {
        balance += amount;
        return TRANSACTION_SUCCESS;
    }
};

/* 
    In this example we are making use of the shared_mutex. This allows us to explicitly
    take sole ownership or share ownership over the lock. Down below you can see that we
    use two different locking mechanisms.

    1. std::unique_lock
    This requires sole ownership over the lock. Used when we are manipulating data.

    2. std::shared_lock
    This allows other shared_locks to access the critical section as well.

    The std::unique_lock will always wait for sole ownership before executing the section
    and not let any other (no matter shared or unique) access it before it release the lock.
*/

class Accounts {
private:
    std::vector<Account> accounts;
    std::shared_mutex mtx;

public:
    Accounts() = default;
    Accounts(std::initializer_list<Account> _accounts)
    : accounts(_accounts) {}

    void addAccount(Account&& _account) {
        std::unique_lock lock(mtx);
        accounts.emplace_back(std::move(_account));
    }

    TransactionResult withdrawFromCustomer(double amount, std::string account_number) {
        if (amount < 0) return NEGATIVE_AMOUNT_ENTERED;

        std::unique_lock lock(mtx);

        auto it = std::ranges::find_if(accounts, [&account_number](const auto& a){
            return account_number == a.account_number;
        });

        if (it != accounts.end()) {
            
            return it->withdraw(amount);
        }

        return ACCOUNT_NOT_FOUND;
    }

    TransactionResult insertToCustomerAccount(double amount, std::string account_number) {
        if (amount < 0) return NEGATIVE_AMOUNT_ENTERED;

        std::unique_lock lock(mtx);

        auto it = std::ranges::find_if(accounts, [&account_number](const auto& a){
            return account_number == a.account_number;
        });

        if (it != accounts.end()) {
            
            return it->insert(amount);
        }

        return ACCOUNT_NOT_FOUND;
    }

    void printAllAccounts() {
        std::shared_lock<std::shared_mutex> lock(mtx);

        for (const auto& a : accounts) {
            std::cout << a.account_number << " | " << a.account_holder << " | " << a.balance << " SEK \n";
        }
    }
};

int main(void) {
    
    Accounts bank{
        { "ACC1001", "Alice Andersson",   32000 },
        { "ACC1002", "Bob Bergström",     45000 },
        { "ACC1003", "Charlie Carlsson",  28000 },
        { "ACC1004", "Diana Dahl",        51000 },
        { "ACC1005", "Erik Ekström",      19000 },
        { "ACC1006", "Fiona Forsberg",    36000 },
        { "ACC1007", "Gustav Gran",       41000 },
        { "ACC1008", "Hanna Holm",        34000 },
        { "ACC1009", "Isak Isaksson",     22500 },
        { "ACC1010", "Jenny Johansson",   47000 }
    };

    std::vector<std::thread> threads;

    int userInput = 0;
    TransactionResult res = TRANSACTION_FAILED;

    switch (userInput) {
        case 0:
            threads.emplace_back(std::thread([&bank, &res](){
                res = bank.insertToCustomerAccount(1337, "ACC1001");
            }));
            break;

        case 1:
            threads.emplace_back(std::thread(&Accounts::insertToCustomerAccount, &bank, 3500, "ACC1005"));
            break;

        case 2:
            threads.emplace_back(std::thread(&Accounts::printAllAccounts, &bank));
            break;

        default:
            std::cout << "Invalid argument!" << std::endl;
    }

    for(auto& t : threads) {
        if (t.joinable()) {
            t.join();
        }
    }

    if (userInput == 0 || userInput == 1) {
        std::cout << "Transaction " << toString(res) << std::endl;
    }

    return 0;
}