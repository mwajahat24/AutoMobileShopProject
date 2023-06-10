#include <iostream>
#include <vector>
#include <string>
using namespace std;

// User Account Class
class UserAccount
{
public:
    string username = "", password = "", role = "";
    vector<string> inbox;

    UserAccount(string username, string password, string role)
    {
        this->username = username;
        this->password = password;
        this->role = role;
    }
};

//
class Car
{
public:
    string make;
    string model;
    double price;

    Car(string make, string model, double price)
    {
        this->make = make;
        this->model = model;
        this->price = price;
    }
};

// Car Manager Class
class CarManager
{
public:
    vector<Car> cars;

    CarManager()
    {
        cars.push_back(Car("Toyota", "Camry", 25000.0));
        cars.push_back(Car("Honda", "Civic", 22000.0));
        cars.push_back(Car("Ford", "Mustang", 40000.0));
        cars.push_back(Car("Chevrolet", "Malibu", 23000.0));
        cars.push_back(Car("Nissan", "Altima", 24000.0));
        cars.push_back(Car("BMW", "3 Series", 38000.0));
        cars.push_back(Car("Audi", "A4", 35000.0));
        cars.push_back(Car("Mercedes-Benz", "C-Class", 40000.0));
        cars.push_back(Car("Volkswagen", "Golf", 27000.0));
        cars.push_back(Car("Lexus", "ES", 42000.0));
        cars.push_back(Car("Subaru", "Impreza", 26000.0));
        cars.push_back(Car("Mazda", "Mazda3", 25000.0));
        cars.push_back(Car("Hyundai", "Elantra", 22000.0));
        cars.push_back(Car("Kia", "Optima", 23000.0));
        cars.push_back(Car("Jeep", "Wrangler", 35000.0));
        cars.push_back(Car("GMC", "Sierra", 40000.0));
        cars.push_back(Car("Ram", "1500", 38000.0));
        cars.push_back(Car("Chevrolet", "Equinox", 27000.0));
        cars.push_back(Car("Ford", "Escape", 28000.0));
        cars.push_back(Car("Toyota", "RAV4", 30000.0));
    }

    void displayAllCars()
    {
        cout << "Available Cars:" << endl;
        for (int i = 0; i < cars.size(); i++)
        {
            cout << "Make: " << cars[i].make << endl;
            cout << "Model: " << cars[i].model << endl;
            cout << "Price: $" << cars[i].price << endl;
            cout << "-------------------------" << endl;
        }
    }

    bool addCar(string make, string model, double price)
    {
        cars.push_back(Car(make, model, price));
        cout << "Car Added Successfully\n";
        return true;
    }

    bool updateCar(int index, string make, string model, double price)
    {
        if (index >= 0 && index < cars.size())
        {
            cars[index].make = make;
            cars[index].model = model;
            cars[index].price = price;
            cout << "Car Updated Successfully\n";
            return true;
        }
        cout << "Invalid Car Index\n";
        return false;
    }

    bool deleteCar(int index)
    {
        if (index >= 0 && index < cars.size())
        {
            cars.erase(cars.begin() + index);
            cout << "Car Deleted Successfully\n";
            return true;
        }
        cout << "Invalid Car Index\n";
        return false;
    }
};

// Accounts Manager Class
class AccountsManager
{
public:
    vector<UserAccount> userAccounts;

    AccountsManager()
    {
        userAccounts.push_back(UserAccount("wajahat", "1234", "buyer"));
        userAccounts.push_back(UserAccount("ahmad", "1234", "seller"));
    }
    bool noAccountAdded()
    {
        return userAccounts.empty();
    }

    bool usernameExists(string username)
    {
        for (int i = 0; i < userAccounts.size(); i++)
            if (userAccounts[i].username == username)
                return true;
        return false;
    }

    bool passwordExists(string password)
    {
        for (int i = 0; i < userAccounts.size(); i++)
            if (userAccounts[i].password == password)
                return true;
        return false;
    }

    bool accountExists(string username, string password)
    {
        if (usernameExists(username) && passwordExists(password))
            return true;
        return false;
    }

    int getAccountIndex(string username, string password)
    {
        for (int i = 0; i < userAccounts.size(); i++)
            if (userAccounts[i].username == username && userAccounts[i].password == password)
                return i;
        return -1;
    }
    int getAccountIndexByUsername(string username)
    {
        for (int i = 0; i < userAccounts.size(); i++)
            if (userAccounts[i].username == username)
                return i;
        return -1;
    }
    UserAccount* getAccountByUsername(string username)
    {
        return &userAccounts[getAccountIndexByUsername(username)];
        return NULL;
    }

    void displayAllMessages(string username)
    {
        UserAccount* userAccount = getAccountByUsername(username);
        for (int i = 0; i < userAccount->inbox.size(); i++)
        {
            cout << "Message : " << i + 1 << "\n";
            cout << userAccount->inbox[i]<<endl;
        }
    }

    bool addAccount(string username, string password, string role)
    {
        if (!accountExists(username, password))
        {
            userAccounts.push_back(UserAccount(username, password, role));
            cout << "Addition Successful \n";
            return true;
        }
        cout << "Addition Unsuccessful \n";
        return false;
    }

    bool deleteAccount(string username, string password)
    {
        if (accountExists(username, password))
        {
            userAccounts.erase(userAccounts.begin() + getAccountIndex(username, password));
            return true;
        }
        return false;
    }

    string displayAllBuyersOrSellers(string roleName)
    {
        cout << endl << endl;
        for (int i = 0; i < userAccounts.size(); i++)
        {
            if (userAccounts[i].role == roleName)
            {
                string credentialsText = "Username: " + userAccounts[i].username + "\n"
                    "Password: " + userAccounts[i].password + "\n"
                    "Role: " + userAccounts[i].role + "\n";
                cout << "Index: "<< i <<"\n" << credentialsText<<"\n";
                return credentialsText;
            }
        }
        return "";
    }

    string displayAccount(string username, string password)
    {
        string credentialsText = "Account Not Found";
        if (accountExists(username, password))
        {
            int accountIndex = getAccountIndex(username, password);
            credentialsText = "Your Credentials: \n"
                "Username: " + userAccounts[accountIndex].username + "\n"
                "Password: " + userAccounts[accountIndex].password + "\n"
                "Role: " + userAccounts[accountIndex].role + "\n";
            cout << credentialsText;
            return credentialsText;
        }
        return credentialsText;
    }

    void displayAllAccounts()
    {
        if (noAccountAdded())
        {
            for (int i = 0; i < userAccounts.size(); i++)
            {
                cout << "Username: " << userAccounts[i].username << endl;
                cout << "Password: " << userAccounts[i].password << endl;
            }
        }
        cout << "No Accounts Added Currently" << endl;
    }
};

// Utilities Class
class BasicUtilities
{
public:
    void clearScreen()
    {
        system("cls");
    }

    template <typename T>
    T getUserInput(string inputText, string clearScreenOrNot)
    {
        T userInput;
        if (clearScreenOrNot == "clear")
            clearScreen();
        cout << inputText << endl;
        cout << "Enter : ";
        cin >> userInput;
        cin.ignore();
        return userInput;
    }

    template <typename T>
    bool checkInputValidity(vector<T> validInputValues, T userInput)
    {
        for (int i = 0; i < validInputValues.size(); i++)
            if (validInputValues[i] == userInput)
                return true;
        return false;
    }

    template <typename T>
    T getValidInput(string inputText, vector<T> validInputValues, string invalidValueText)
    {
        T userInput;
        string result = "";
        while (true)
        {
            clearScreen();
            userInput = getUserInput<T>(inputText + result, "");
            if (!checkInputValidity<T>(validInputValues, userInput))
                result = "\n" + invalidValueText;
            else
                break;
        }
        return userInput;
    }

    string getUserMessage(string inputText)
    {
        string message = "";
        cout << inputText << endl;
        getline(cin, message);
        return message;
    }
};

// Auto Mobile Shop Class
class AutoMobileShop
{
public:
    AccountsManager accountsManager;
    CarManager carManager;
    BasicUtilities basicUtilities;

    string getLoginMenuText()
    {
        return "Login Menu \n"
            "Enter 1 to sign up \n"
            "Enter 2 to sign in \n"
            "Enter -1 to exit";
    }

    string getCredentialsMenuText(string menuName, string attributeName)
    {
        return menuName + "\n"
            "Enter " + attributeName + ": \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getDisplayAllCarsMenuText()
    {
        return "Currently Added Cars:  \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getAddCarMenuText()
    {
        return "Add Car Menu \n"
            "Enter 1 to add again \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getUpdateCarMenuText()
    {
        return "Update Car Menu \n"
            "Enter the index of the car to update: \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getUpdateCarDetailsText()
    {
        return "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getUpdateAgainText()
    {
        return "Enter 1 to update again \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getDeleteCarAgainText()
    {
        return "Enter 1 to delete again \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getCarDeletedSuccessfullyText()
    {
        return "Car Deleted Successfully\n"
            "Enter 1 to delete again \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getDeleteCarMenuText()
    {
        return "Delete Car Menu \n"
            "Enter the index of the car to delete: \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }
    string getUserMessageMenuText()
    {
        return "Enter Message: \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    string getViewInboxText()
    {
        return "Inbox \n"
            "Enter 0 to return \n"
            "Enter -1 to exit";
    }

    void loginMenu(string signedUpText)
    {
        int command = basicUtilities.getValidInput<int>(getLoginMenuText() + "\n" + signedUpText, { 1, 2, -1 }, "Invalid Command: Enter again");
        if (command == 1)
            signUpMenu();
        else if (command == 2)
            signInMenu();
        else
            exit(0);
    }

    string performSignUpUserNameValidation()
    {
        string result = "", username = "";
        while (true)
        {
            username = basicUtilities.getUserInput<string>(getCredentialsMenuText("Sign Up Menu", "Username") + result, "clear");
            if (accountsManager.usernameExists(username) && username != "-1" && username != "0")
            {
                result = "\nUsername Already Exists";
                continue;
            }
            else
                break;
        }
        return username;
    }

    string performSignInUserNameValidation()
    {
        string result = "", username = "";
        while (true)
        {
            username = basicUtilities.getUserInput<string>(getCredentialsMenuText("Sign In Menu", "Username") + result, "clear");
            if (!accountsManager.usernameExists(username) && username != "-1" && username != "0")
            {
                result = "\nUsername Does Not Exist";
                continue;
            }
            else
                break;
        }
        return username;
    }

    string performSignInPasswordValidation(string username)
    {
        string result = "", password = "";
        while (true)
        {
            password = basicUtilities.getUserInput<string>(getCredentialsMenuText("Sign In", "Password") + result, "clear");
            if (!accountsManager.accountExists(username, password) && password != "-1" && password != "0")
            {
                result = "\nIncorrect Password";
                continue;
            }
            else
                break;
        }
        return password;
    }

    string performSignUpRoleValidation()
    {
        string result = "", role = "";
        while (true)
        {
            role = basicUtilities.getUserInput<string>(getCredentialsMenuText("Sign In", "Role") + result, "clear");
            if (role != "buyer" && role != "seller")
            {
                result = "\nInvalid Role: (Enter either buyer or seller)\n";
            }
            else break;
        }
        return role;
    }

    void exitOrReturn(string command, string menuName, string loggedInAs)
    {
        if (command == "-1")
            exit(0);
        else if (command == "0" && menuName == "login")
            loginMenu("");
        else if (command == "0" && menuName == "mainmenu")
            mainMenu(loggedInAs);
        else if (command == "0" && menuName == "displayallcars")
            displayAllCarsMenu(loggedInAs);
        else if (command == "0" && menuName == "updatecar")
            updateCarMenu(loggedInAs, false);
        else if (command == "0" && menuName == "deletecar")
            deleteCarMenu(loggedInAs, false);
    }

    void signUpMenu()
    {
        string username = performSignUpUserNameValidation();
        exitOrReturn(username, "login", "");

        string password = basicUtilities.getUserInput<string>(getCredentialsMenuText("Sign Up", "Password"), "clear");
        exitOrReturn(password, "login", "");

        string role = performSignUpRoleValidation();
        exitOrReturn(password, "login", "");

        accountsManager.addAccount(username, password, role);
        loginMenu("\nSign Up Successful\n" + accountsManager.displayAccount(username, password));
    }

    void signInMenu()
    {
        string username = performSignInUserNameValidation();
        exitOrReturn(username, "login", "");

        string password = performSignInPasswordValidation(username);
        exitOrReturn(password, "login", "");

        mainMenu(username);
    }

    void displayAllCarsMenu(string username)
    {
        basicUtilities.clearScreen();
        cout << getDisplayAllCarsMenuText() << endl;
        carManager.displayAllCars();
        string option = basicUtilities.getUserInput<string>("", "");
        exitOrReturn(option, "mainmenu", username);
    }

    void addCarMenu(string username)
    {
        string make = basicUtilities.getUserInput<string>(getAddCarMenuText() + "\nEnter the make of the car: ", "clear");
        exitOrReturn(make, "mainmenu", username);
        string model = basicUtilities.getUserInput<string>(getAddCarMenuText() + "\nEnter the model of the car: ", "clear");
        exitOrReturn(model, "mainmenu", username);
        double price = basicUtilities.getUserInput<double>(getAddCarMenuText() + "\nEnter the price of the car: ", "clear");
        exitOrReturn(to_string(price), "mainmenu", username);
        carManager.addCar(make, model, price);
        string option = basicUtilities.getUserInput<string>("", "");
        if (option == "1")
            addCarMenu(username);
        exitOrReturn(option, "mainmenu", username);
    }

    void updateCarMenu(string username, bool wrongIndexEntered)
    {
        string result = "";
        if (wrongIndexEntered)
        {
            result = "Invalid Index \n";
            wrongIndexEntered = false;
        }
        int index = basicUtilities.getUserInput<int>(getUpdateCarMenuText() + "\n" + result, "clear");
        exitOrReturn(to_string(index), "mainmenu", username);
        if (index >= 0 && index < carManager.cars.size())
        {
            string make = basicUtilities.getUserInput<string>(getUpdateCarDetailsText() + "\n" + "Enter the new make of the car: ", "clear");
            exitOrReturn(make, "mainmenu", username);
            string model = basicUtilities.getUserInput<string>(getUpdateCarDetailsText() + "\n" + "Enter the new model of the car: ", "clear");
            exitOrReturn(model, "mainmenu", username);
            double price = basicUtilities.getUserInput<double>(getUpdateCarDetailsText() + "\n" + "Enter the new price of the car: ", "clear");
            exitOrReturn(to_string(price), "mainmenu", username);
            carManager.updateCar(index, make, model, price);
            int index = basicUtilities.getUserInput<int>(getUpdateAgainText(), "clear");
            exitOrReturn(to_string(index), "mainmenu", username);
            if (index == 1) updateCarMenu(username, true);
        }
        else
        {
            updateCarMenu(username, true);
        }
    }

    void deleteCarMenu(string username, bool wrongIndexEntered)
    {
        string result = "";
        if (wrongIndexEntered)
        {
            result = "Invalid Index \n";
            wrongIndexEntered = false;
        }
        int index = basicUtilities.getUserInput<int>(getDeleteCarMenuText() + "\n" + result, "clear");
        exitOrReturn(to_string(index), "mainmenu", username);
        if (index - 1 >= 0 && index - 1 < carManager.cars.size())
        {
            carManager.deleteCar(index - 1);
            int index = basicUtilities.getUserInput<int>(getCarDeletedSuccessfullyText(), "clear");
            exitOrReturn(to_string(index), "mainmenu", username);
            if (index == 1) deleteCarMenu(username, true);
        }
        else
        {
            deleteCarMenu(username, true);
        }
    }

    void sendMessageToUser(string username, string role, string result)
    {
        basicUtilities.clearScreen();
        accountsManager.displayAllBuyersOrSellers(role);
        string buyerOrSeller = basicUtilities.getUserMessage("Enter " + role + "name: \n" + result);
        exitOrReturn(buyerOrSeller, "mainmenu", username);
        if (accountsManager.usernameExists(buyerOrSeller))
        {
            cout << endl;
            UserAccount* userAccount = accountsManager.getAccountByUsername(username);
            string message = basicUtilities.getUserMessage(getUserMessageMenuText());
            exitOrReturn(message, "mainmenu", username);
            accountsManager.getAccountByUsername(buyerOrSeller)->inbox.push_back(message);
            result = "Message Sent \n";
            sendMessageToUser(username, role, result);
        }
        else
        {
            result = "The User doesn't exist \n";
            sendMessageToUser(username, role, result);
        }
    }

    void viewInbox(string username)
    {
        accountsManager.displayAllMessages(username);
        string option = basicUtilities.getUserInput<string>(getViewInboxText(), "");
        if (option == "1")
            addCarMenu(username);
        exitOrReturn(option, "mainmenu", username);
    }

    void mainMenu(string username)
    {
        int command = 0;
        UserAccount* userAccount = accountsManager.getAccountByUsername(username);
        string role = accountsManager.getAccountByUsername(username)->role;
        string outputRequired = "";
        string loggedInAsText = "Logged In As: " + username + "\n\n"
                                "Role : " + role + "\n\n";

        command = basicUtilities.getValidInput<int>(
            loggedInAsText +
            "Enter:\n"
            "1. Display Available Cars\n"
            "2. Add a Car\n"
            "3. Update a Car\n"
            "4. Delete a Car\n"
            "5. Chat With Buyer\n"
            "6. Chat With Seller\n"
            "7. View Inbox\n"
            "0. Logout\n"
            "-1. Exit\n",
            { 1, 2, 3, 4, 5, 6, 7, 0, -1 },
            "Invalid Command: Enter again" + outputRequired);

        if (command == 1)
        {
            displayAllCarsMenu(username);
        }
        else if (command == 2)
        {
            addCarMenu(username);
        }
        else if (command == 3)
        {
            updateCarMenu(username, false);
        }
        else if (command == 4)
        {
            deleteCarMenu(username, false);
        }
        else if (command == 5)
        {
            sendMessageToUser(username, "buyer", "");
        }
        else if (command == 6)
        {
            sendMessageToUser(username, "seller", "");
        }
        else if (command == 7)
        {
            viewInbox(username);
        }
        else if (command == 0)
        {
            loginMenu("");
        }
        else if (command == -1)
        {
            exit(0);
        }
    }
};

int main()
{
    AutoMobileShop autoMobileShop;
    autoMobileShop.mainMenu("ahmad");
    return 0;
}
