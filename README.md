# Vending Machine C++ Project

## Overview

This project implements a basic vending machine simulation. The vending machine allows users to select drinks, insert bills and coins as payment, and receive their chosen drink along with any necessary change. The program supports multiple drink options, payment methods (bills and coins), and displays the remaining drink quantities.

## Features

- **Drink Selection**: Users can choose from a set of drinks, each with a name and price.
- **Payment Handling**: The vending machine accepts bills and coins for payment, checking if the inserted amount is enough to purchase the selected drink.
- **Drink Dispensing**: Once the payment is complete, the selected drink is dispensed, and change (if any) is returned to the user.
- **Stock Management**: The vending machine keeps track of the available quantity for each drink and notifies the user if a drink is out of stock.

## Classes and Structure

The project is organized into the following classes:

### `Drink`
Represents a drink with its name and price.

- **Constructor**: 
    - `Drink(const string& drinkName, double drinkPrice)`
- **Getters**:
    - `getDrinkName()`: Returns the name of the drink.
    - `getPrice()`: Returns the price of the drink.
- **Setters**:
    - `setName(string n)`: Sets the name of the drink.
    - `setPrice(double p)`: Sets the price of the drink.

### `SelectionButton`
Represents a button in the vending machine for selecting a drink.

- **Constructor**: 
    - `SelectionButton(const string& drinkName, double drinkPrice, bool status)`
- **Methods**:
    - `getButtonStatus()`: Returns the current status of the button (whether it is selected).
    - `setStatus(bool stat)`: Sets the status of the button.
    - `displayDrink()`: Displays the drink's name and price.
    - `getDrinkName()`: Returns the name of the drink.
    - `getDrinkPrice()`: Returns the price of the drink.

### `Dispenser`
Represents a dispenser for a specific drink in the vending machine.

- **Constructor**: 
    - `Dispenser(const string& drinkName, double drinkPrice, int capacity)`
- **Getters**:
    - `getQuantity()`: Returns the current quantity of the drink in the dispenser.
    - `getCapacity()`: Returns the capacity of the dispenser.
    - `getDrinkName()`: Returns the name of the drink.
- **Setters**:
    - `setQuantity(int q)`: Sets the quantity of the drink in the dispenser.

### `Currency`
Represents a currency type (either a bill or a coin).

- **Constructor**: 
    - `Currency(const string& currencyName, double currencyValue)`
- **Getters**:
    - `getName()`: Returns the name of the currency.
    - `getValue()`: Returns the value of the currency.

### `Bill` and `Coin`
These classes inherit from `Currency` and represent bills and coins, respectively.

- **Constructor**:
    - `Bill(const Currency& billCurrency)`
    - `Coin(const Currency& coinCurrency)`
- **Getters/Setters**:
    - `getQuantity()`: Returns the quantity of the specific bill or coin.
    - `setQuantity(int newQuantity)`: Sets the quantity of the specific bill or coin.

### `BillSlot` and `CoinSlot`
These classes represent the slots where bills and coins are inserted.

- **Methods**:
    - `addBill(const Bill& bill)`: Adds a bill type to the slot.
    - `addCoin(const Coin& coin)`: Adds a coin type to the slot.
    - `removeBill(const Currency& billCurrency)`: Removes a bill type from the slot.
    - `removeCoin(const Currency& coinCurrency)`: Removes a coin type from the slot.
    - `getTotalValue()`: Returns the total value of bills or coins in the slot.
    - `clearBills()` and `clearCoins()`: Clears all bills or coins in the slot.

### `VendingMachine`
The main vending machine class that integrates the bill slot, coin slot, selection buttons, and dispensers.

- **Constructor**:
    - `VendingMachine(const BillSlot& billSlot, const CoinSlot& coinSlot)`
- **Methods**:
    - `addBill(const Bill& bill)`: Adds a bill to the vending machine.
    - `addCoin(const Coin& coin)`: Adds a coin to the vending machine.
    - `addSelectionButton(const SelectionButton& button)`: Adds a drink selection button.
    - `addDispenser(const Dispenser& dispenser)`: Adds a drink dispenser.
    - `getAllValue()`: Returns the total value of inserted bills and coins.
    - `displayOptions()`: Displays the available drink options.
    - `updateButtonStatus(int buttonIndex, bool status)`: Updates the selection button's status.
    - `getSelectedDrink()`: Returns the name of the selected drink.
    - `getSelectedDrinkPrice()`: Returns the price of the selected drink.
    - `checkPayment()`: Checks if the inserted currency is sufficient to make the purchase.
    - `displayCurrentQuantities()`: Displays the current stock quantities of each drink.
    - `dispenseSelectedDrink()`: Dispenses the selected drink and returns any change.

## Compilation and Execution

1. **Compile the program**:
    ```bash
    g++ -o vending_machine vending_machine.cpp
    ```

2. **Run the program**:
    ```bash
    ./vending_machine
    ```

## Usage

- **Select a drink**: Enter the number corresponding to the drink you want to purchase.
- **Insert payment**: Select from the available bills and coins.
- **Cancel transaction**: Press `0` to cancel the transaction and exit.
- **Receive drink and change**: If the payment is sufficient, the drink will be dispensed along with any change.

## Example Interaction

