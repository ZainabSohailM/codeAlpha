#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // For setw
#include <limits>  // For numeric_limits
#include <memory>  // For unique_ptr

using namespace std;

// Transaction class
class Transaction {
public:
    enum Type { DEPOSIT, WITHDRAWAL, TRANSFER };

    Transaction(Type type, double amount, const string& details)
        : type(type), amount(amount), details(details) {}

    void print() const {
        string typeStr = (type == DEPOSIT) ? "Deposit" : (type == WITHDRAWAL) ? "Withdrawal" : "Transfer";
        cout << setw(10) << typeStr << setw(15) << amount << setw(30) << details << endl;
    }

private:
    Type type;
    double amount;
    string details;
};

// Account class
class Account {
public:
    Account(int id, const string& holderName)
        : id(id), holderName(holderName), balance(0.0) {}

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction(Transaction::DEPOSIT, amount, "Deposited into account"));
    }

    bool withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            transactions.push_back(Transaction(Transaction::WITHDRAWAL, amount, "Withdrawn from account"));
            return true;
        }
        return false;
    }

    bool transfer(Account& toAccount, double amount) {
        if (amount <= balance) {
            balance -= amount;
            toAccount.deposit(amount);
            transactions.push_back(Transaction(Transaction::TRANSFER, amount, "Transferred to account ID " + to_string(toAccount.getId())));
            return true;
        }
        return false;
    }

    void printAccountInfo() const {
        cout << "Account ID: " << id << "\n";
        cout << "Account Holder: " << holderName << "\n";
        cout << "Balance: $" << fixed << setprecision(2) << balance << "\n";
        cout << "Recent Transactions:\n";
        cout << setw(10) << "Type" << setw(15) << "Amount" << setw(30) << "Details" << "\n";
        for (const auto& transaction : transactions) {
            transaction.print();
        }
        cout << "------------------------\n";
    }

    int getId() const { return id; }
    string getHolderName() const { return holderName; }

private:
    int id;
    string holderName;
    double balance;
    vector<Transaction> transactions;
};

// Customer class
class Customer {
public:
    Customer(const string& name) : name(name) {}

    void addAccount(unique_ptr<Account> account) {
        accounts.push_back(move(account));
    }

    void viewAccounts() const {
        cout << "Customer: " << name << "\n";
        for (const auto& account : accounts) {
            account->printAccountInfo();
        }
    }

    string getName() const { return name; }
    vector<unique_ptr<Account>>& getAccounts() { return accounts; }
    const vector<unique_ptr<Account>>& getAccounts() const { return accounts; }

private:
    string name;
    vector<unique_ptr<Account>> accounts;
};

// BankingService class
class BankingService {
public:
    ~BankingService() = default;

    void createCustomer(const string& name) {
        customers.push_back(make_unique<Customer>(name));
    }

    Customer* getCustomer(const string& name) {
        for (auto& customer : customers) {
            if (customer->getName() == name) {
                return customer.get();
            }
        }
        return nullptr;
    }

    void createAccount(const string& customerName, int accountId) {
        Customer* customer = getCustomer(customerName);
        if (customer) {
            auto newAccount = make_unique<Account>(accountId, customerName);
            customer->addAccount(move(newAccount));
            accounts.push_back(newAccount.get()); // keep track of raw pointers for easy access
        }
    }

    Account* getAccount(int accountId) {
        for (auto& account : accounts) {
            if (account->getId() == accountId) {
                return account;
            }
        }
        return nullptr;
    }

    void deposit(int accountId, double amount) {
        Account* account = getAccount(accountId);
        if (account) {
            account->deposit(amount);
        }
    }

    void withdraw(int accountId, double amount) {
        Account* account = getAccount(accountId);
        if (account) {
            account->withdraw(amount);
        }
    }

    void transfer(int fromAccountId, int toAccountId, double amount) {
        Account* fromAccount = getAccount(fromAccountId);
        Account* toAccount = getAccount(toAccountId);
        if (fromAccount && toAccount) {
            fromAccount->transfer(*toAccount, amount);
        }
    }

private:
    vector<unique_ptr<Customer>> customers;
    vector<Account*> accounts; // keep raw pointers for easy access
};

void handleUserInput(BankingService& bankService) {
    int choice = 0;
    string name;
    int accountId = 0;
    double amount = 0.0;
    string customerName;
    int toAccountId = 0;

    while (true) {
        cout << "Banking System Menu:\n";
        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit\n";
        cout << "4. Withdraw\n";
        cout << "5. Transfer\n";
        cout << "6. View Account Info\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle newline left in the buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            cout << "Enter customer name: ";
            getline(cin, name);
            bankService.createCustomer(name);
            cout << "Customer created successfully.\n";
        }
        else if (choice == 2) {
            cout << "Enter customer name: ";
            getline(cin, customerName);
            cout << "Enter account ID: ";
            cin >> accountId;
            bankService.createAccount(customerName, accountId);
            cout << "Account created successfully.\n";
        }
        else if (choice == 3) {
            cout << "Enter account ID: ";
            cin >> accountId;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            bankService.deposit(accountId, amount);
            cout << "Deposit successful.\n";
        }
        else if (choice == 4) {
            cout << "Enter account ID: ";
            cin >> accountId;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            bankService.withdraw(accountId, amount);
            cout << "Withdrawal successful.\n";
        }
        else if (choice == 5) {
            cout << "Enter from account ID: ";
            cin >> accountId;
            cout << "Enter to account ID: ";
            cin >> toAccountId;
            cout << "Enter amount to transfer: ";
            cin >> amount;
            bankService.transfer(accountId, toAccountId, amount);
            cout << "Transfer successful.\n";
        }
        else if (choice == 6) {
            cout << "Enter customer name: ";
            getline(cin, customerName);
            Customer* customer = bankService.getCustomer(customerName);
            if (customer) {
                customer->viewAccounts();
            }
            else {
                cout << "Customer not found.\n";
            }
        }
        else if (choice == 7) {
            cout << "Exiting...\n";
            return;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}

int main() {
    BankingService bankService;
    handleUserInput(bankService);
    return 0;
}
