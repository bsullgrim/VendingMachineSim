#include <iostream>
#include <vector>
using namespace std;

class Drink{
  private:
    string name; 
    double price;
    
  public:
  //Constructor
    Drink(const string& drinkName, double drinkPrice): 
    name(drinkName), price(drinkPrice){}
  
  // Getters
  string const getDrinkName(){
    return name;
  }
  double const getPrice(){
    return price;
  }
  // Setters 
  void setName (string n){
    name = n;
  }
  void setPrice(double p){
    price = p;
  }
};
class SelectionButton {
  private:
    Drink drink; 
    bool status; 
public:
  //Constructor
  SelectionButton (const string& drinkName, double drinkPrice, bool status) : drink(drinkName, drinkPrice), status(false) {};

//Getters
bool const getButtonStatus (){
    return status;
}

//Setters 
void setStatus(bool stat){
    status = stat;
}

void displayDrink() {
    cout << drink.getDrinkName() << ": $" << drink.getPrice() << endl;
}
string const getDrinkName(){
    return drink.getDrinkName();
  }
double const getDrinkPrice(){
return drink.getPrice();
}
};
class Dispenser {
  private:
    Drink drink;
    int capacity;
    int quantity;
    
  public:
  //Constructor
Dispenser(const string& drinkName, double drinkPrice, int capacity) : drink(drinkName, drinkPrice), capacity(capacity), quantity(0) {};

// Getters 
int const getQuantity (){
    return quantity;
}

int const getCapacity (){
    return capacity;
}
string const getDrinkName(){
    return drink.getDrinkName();
}
// Setters
void setQuantity (int q){
    quantity = q;
}
};
class Currency {
  private:
    string name;
    double value;
  public:
    Currency(const string& currencyName, double currencyValue) : name(currencyName), value(currencyValue) {}

    // Getters
    string getName() const {
      return name;
    }

    double getValue() const {
      return value;
    }
};
class Bill : public Currency {
  private:
    int quantity; // Number of bills of this type
  public:
    Bill(const Currency& billCurrency) : Currency(billCurrency), quantity(0) {}

    // Getters and setters for quantity
    int const getQuantity () {
        return quantity;
    }
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }

};
class Coin : public Currency {
  private:
    int quantity; // Number of coins of this type
  public:
    Coin(const Currency& coinCurrency) : Currency(coinCurrency), quantity(0) {}

    // Getters and setters for quantity
    int getQuantity() const {
        return quantity;
    }
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }
};
class BillSlot {
  private:
    vector<Bill> bills; // Collection of bills in the slot
  public:
    // Update the quantity of a bill
    void updateBillQuantity(const string& billName, int quantity) {
        for (auto& bill : bills) {
            if (bill.getName() == billName) {
                bill.setQuantity(bill.getQuantity() + quantity);
                break;
            }
        }
    }
    // Add a bill type to the slot
    void addBill(const Bill& bill) {
      bills.push_back(bill);
    }

    // Remove a bill type from the slot
    void removeBill(const Currency& billCurrency) {
      for (auto it = bills.begin(); it != bills.end(); ++it) {
        if (it->getName() == billCurrency.getName()) {
          bills.erase(it);
          break;
        }
      }
    }
    // Add total value of bills
    double getTotalValue () {
        double totalValue = 0.0;
        for (auto& bill : bills){
            totalValue += bill.getValue() * bill.getQuantity();
        }
        return totalValue;
    }
    void clearBills (){
        for (auto& bill : bills) {
            bill.setQuantity(0);
        }
    }

          

    
};
class CoinSlot {
  private:
    vector<Coin> coins; // Collection of coins supported by the slot
public:
// Update the quantity of coins in the slot 
      void updateCoinQuantity(const string& coinName, int quantity) {
        for (auto& coin : coins) {
            if (coin.getName() == coinName) {
                coin.setQuantity(coin.getQuantity() + quantity);
                break;
            }
        }
    }
    // Add a coin type to the slot
    void addCoin(const Coin& coin) {
      coins.push_back(coin);
    }

    // Remove a coin type from the slot
    void removeCoin(const Currency& coinCurrency) {
      for (auto it = coins.begin(); it != coins.end(); ++it) {
        if (it->getName() == coinCurrency.getName()) {
          coins.erase(it);
          break;
        }
      }
    }

    // Add total value of coins
    double getTotalValue () const {
        double totalValue = 0.0;
        for (auto& coin: coins){
            totalValue += coin.getValue() * coin.getQuantity();
        }
        return totalValue;
    }
    
        void clearCoins (){
        for (auto& coin: coins) {
            coin.setQuantity(0);
        }
    }


};
class VendingMachine {
private: 
    BillSlot billslot;
    CoinSlot coinslot;
    vector<SelectionButton> selectionButtons;
    vector<Dispenser> dispensers;
public:
VendingMachine(const BillSlot& billSlot, const CoinSlot& coinSlot)
        : billslot(billSlot), coinslot(coinSlot) {}
    void addBill(const Bill& bill) {
        billslot.addBill(bill);
    }

    void addCoin(const Coin& coin) {
        coinslot.addCoin(coin);
    }

    void addSelectionButton(const SelectionButton& button) {
        selectionButtons.push_back(button);
    }
    
    void addDispenser(const Dispenser& dispenser) {
        dispensers.push_back(dispenser);
    }
   
    double getAllValue(BillSlot billslot , CoinSlot coinslot) {
        double totalValue = billslot.getTotalValue() + coinslot.getTotalValue();
        return totalValue;        
    }
  
    void const displayOptions(){
        int index = 1;
        for( auto& button : selectionButtons) {
        cout<< index << ": "; button.displayDrink();
        index++;
        }
    }
    
    void updateButtonStatus(int buttonIndex, bool status) {
        if (buttonIndex >= 0 && buttonIndex < static_cast<int>(selectionButtons.size())) {
            selectionButtons[buttonIndex].setStatus(status);
        }
    }
    
    string getSelectedDrink(){
    for(auto& button : selectionButtons){
        if(button.getButtonStatus()){
            string selectedDrinkName = button.getDrinkName();
                return selectedDrinkName;
            } 
        } return "";
    }
    
    double getSelectedDrinkPrice(){
    for(auto& button : selectionButtons){
        if(button.getButtonStatus()){
            double selectedDrinkPrice = button.getDrinkPrice();
                return selectedDrinkPrice;
            } 
        } return 0.0;
    }
    bool checkPayment(BillSlot& billslot, CoinSlot& coinslot) {
        return (billslot.getTotalValue() + coinslot.getTotalValue() >= getSelectedDrinkPrice());
    }
    void displayCurrentQuantities() {
        cout << "Current Quantities:" << endl;
        for (auto& dispenser : dispensers) {
            cout << dispenser.getDrinkName() << ": " << dispenser.getQuantity() << endl;
        }
    }

    void dispenseSelectedDrink(BillSlot& billslot, CoinSlot& coinslot) {
        string selectedDrinkName = getSelectedDrink();
        double selectedDrinkPrice = getSelectedDrinkPrice();

        for (auto& dispenser : dispensers) {
            if (dispenser.getDrinkName() == selectedDrinkName) {
                if (dispenser.getQuantity() > 0) {
                    cout << "Dispensing " << selectedDrinkName << "..." << endl;
                    dispenser.setQuantity(dispenser.getQuantity() - 1);
                    double change = getAllValue(billslot, coinslot) - selectedDrinkPrice;
                    cout << "Change: $" << change << endl;
                } else {
                    cout << "Out of stock: " << selectedDrinkName << endl;
                }
                break;
            }
        }
    }

};



int main() {
    
  // Create drinks
  Drink coke("Coke", 1.50);
  Drink sprite("Sprite", 1.25);
  Drink drpepper("Dr. Pepper", 1.75);
  
  // Create selection buttons
  SelectionButton button1("Coke", coke.getPrice(), false);
  SelectionButton button2("Sprite", sprite.getPrice(), false);
  SelectionButton button3("Dr Pepper", drpepper.getPrice(), false);

  // Create dispenser
  Dispenser dispenserCoke("Coke", coke.getPrice(), 10);
  Dispenser dispenserSprite("Sprite", sprite.getPrice(), 20);
  Dispenser dispenserDrPepper("Dr Pepper", drpepper.getPrice(), 20);
  
  dispenserCoke.setQuantity(20);
  dispenserSprite.setQuantity(20);
  dispenserDrPepper.setQuantity(20);
  
  //Create Bills and Coins 
  Bill dollar(Currency("Dollar", 1.0));
  Bill fiver(Currency("Five", 5.0));
  Bill ten(Currency("Ten", 10.0));
  Coin quarter(Currency("Quarter", 0.25));
  Coin fifty(Currency("Fifty Piece", 0.50));
  Coin saca(Currency("Dollar Coin", 1.0));
  
  // Create bill and coin slots
  BillSlot billSlot;
  CoinSlot coinSlot;
  billSlot.addBill(dollar);
  billSlot.addBill(fiver);
  billSlot.addBill(ten);
  coinSlot.addCoin(quarter);
  coinSlot.addCoin(fifty);
  coinSlot.addCoin(saca);

  // Create vending machine
  VendingMachine vendingMachine(billSlot, coinSlot);
  vendingMachine.addSelectionButton(button1);
  vendingMachine.addSelectionButton(button2);
  vendingMachine.addSelectionButton(button3);
  vendingMachine.addDispenser(dispenserCoke);
  vendingMachine.addDispenser(dispenserSprite);
  vendingMachine.addDispenser(dispenserDrPepper);
bool exitVendingMachine = false;
while (!exitVendingMachine){
bool validSelection = false;
    while (!validSelection) {
        cout << "Welcome to the Vending Machine!" << endl;
        cout << "Select a drink:" << endl;
        vendingMachine.displayOptions();
        cout<< endl;
        vendingMachine.displayCurrentQuantities();
        cout << "Enter '0' to cancel the transaction." << endl;

        int selection;
        cin >> selection;

        // Validate the selection
        if (selection < 0 || selection > 3) {
        cout << "Invalid selection. Please try again." << endl;
        } else validSelection = true; 

        // Press the corresponding selection button
        switch(selection){
            case 0:{ 
            cout << "Transaction canceled" << endl;
            return 0; 
            }
            case 1: {
            vendingMachine.updateButtonStatus(0, true);
            break;
            }
            case 2: {
            vendingMachine.updateButtonStatus(1, true);
            break;
            }
            case 3: {
            vendingMachine.updateButtonStatus(2,true);
            break;
            }
            default: {
            cout << "Invalid choice. Please select a valid option." << endl;
            continue;
            } 
            }


        // Check payment and handle the payment process
        bool paymentComplete = false;
        static double totalPayment = 0.0;  // Track the total value of inserted currency
        while (!paymentComplete) {
            cout << "Total Payment: $" << totalPayment << "     Please select a bill or coin from the menu (enter '0' to finish payment):" << endl;
            cout << "1. $1 Bill\n";
            cout << "2. $5 Bill\n";
            cout << "3. $10 Bill\n";
            cout << "4. $0.25 Coin\n";
            cout << "5. $0.50 Coin\n";
            cout << "6. $1 Coin\n";

            int choice;
            cin >> choice;


            switch (choice) {
            case 0:{
                if (vendingMachine.checkPayment(billSlot, coinSlot)) {
                vendingMachine.dispenseSelectedDrink(billSlot, coinSlot); // Dispense the selected drink
                // Clear the bill slot quantities
                billSlot.clearBills();

                // Clear the coin slot quantities
                coinSlot.clearCoins();

                totalPayment = 0;    
                cout << "Would you like to make another transaction? (Y/N): ";
                char choice;
                cin >> choice;

                if (toupper(choice) == 'N') {
                  exitVendingMachine = true; // Set exit flag to true if user chooses not to make another transaction
                }
                paymentComplete = true;
                break;
                } else {
                    cout << "Not enough money, please enter more bills and coins" << endl;
                    continue;
                }
            }
            case 1: {
                int billQuantity;
                cout << "Enter the quantity of $1 bills: ";
                cin >> billQuantity;
                billSlot.updateBillQuantity("Dollar", billQuantity);
                totalPayment = (billSlot.getTotalValue() + coinSlot.getTotalValue());
                break;
            }
            case 2: {
                int billQuantity;
                cout << "Enter the quantity of $5 bills: ";
                cin >> billQuantity;
                billSlot.updateBillQuantity("Five", billQuantity);
                totalPayment = (billSlot.getTotalValue() + coinSlot.getTotalValue());
                break;
            }
            case 3: {
                int billQuantity;
                cout << "Enter the quantity of $10 bills: ";
                cin >> billQuantity;
                billSlot.updateBillQuantity("Ten", billQuantity);
                totalPayment = (billSlot.getTotalValue() + coinSlot.getTotalValue());
                break;
            }
            case 4: {
                int coinQuantity;
                cout << "Enter the quantity of $0.25 coins: ";
                cin >> coinQuantity;
                coinSlot.updateCoinQuantity("Quarter",coinQuantity);
                totalPayment = (billSlot.getTotalValue() + coinSlot.getTotalValue());
                break;
            }
            case 5: {
                int coinQuantity;
                cout << "Enter the quantity of $0.50 coins: ";
                cin >> coinQuantity;
                coinSlot.updateCoinQuantity("Fifty Piece",coinQuantity);
                totalPayment = (billSlot.getTotalValue() + coinSlot.getTotalValue());
                break;
            }
            case 6: {
                int coinQuantity;
                cout << "Enter the quantity of $1 coins: ";
                cin >> coinQuantity;
                coinSlot.updateCoinQuantity("Dollar Coin",coinQuantity);
                totalPayment = (billSlot.getTotalValue() + coinSlot.getTotalValue());
                break;
            }
            default: {
                cout << "Invalid choice. Please select a valid option." << endl;
                continue;
            }
            }
        }
    }
}
return 0;
}