#include <iostream>
#include <iomanip>

int main() {
    std::string products[5] = {"milk", "bread", "coffee", "tea", "tomato"};
    double price[5] = {4.50, 2.99, 7.49, 5.00, 1.39};
    int amount[5] = {10, 30, 5, 13, 9};

    double earnings = 0;

    int option = 0;

    std::cout << std::fixed << std::setprecision(2);

    while(option != 5) {
        std::cout << "Choose: \n";
        std::cout << "1. Stock status \n";
        std::cout << "2. Sell product \n";
        std::cout << "3. Take delivery \n";
        std::cout << "4. See the store's earnings \n";
        std::cout << "5. Quit \n";
        std::cout << "Your choice: ";
        std::cin >> option;

        switch(option) {
            case 1: {     
                std::cout << "\n" << std::left << std::setw(8)  << "Index" << std::setw(15) << "Name" << std::setw(10) << "Price" << std::setw(8)  << "Amount" << '\n';
                        
                std::cout << "-------------------------------------------\n";

                for(int i = 0; i < 5; i++) {
                    std::cout << std::left  << std::setw(8)  << i << std::setw(15) << products[i] << std::setw(10) << price[i] << std::setw(8)  << amount[i] << '\n';
                }
                std::cout << "-------------------------------------------\n";
                break;
            }
            case 2: {
                int index = 0;
                int amountOfProduct = 0;
                std::cout << "Type index of the product you would like to buy (1-5): ";
                std::cin >> index;

                if(index < 1 || index > 5) {
                    std::cout << "You typed wrong index!\n";
                    break;
                } else {
                    std::cout << "Type amount of product you would like to buy: ";
                    std::cin >> amountOfProduct;
                    
                    if(amountOfProduct <= amount[index - 1]) {
                        double cost = price[index - 1] * amountOfProduct;
                        amount[index - 1] -= amountOfProduct;
                        earnings += cost;
                        std::cout << "You have to pay: " << cost << "\n\n";
                    } else {
                        std::cout << "There are not that many pieces of this product in the store!\n";
                        break;
                    }

                }
                break;
            }

            case 3: {
                int index = 0;
                int amountOfProduct = 0;

                std::cout << "Type index of the product (1-5): ";
                std::cin >> index;

                if(index < 1 || index > 5) {
                    std::cout << "You typed wrong index!\n";
                    break;
                } else {
                    std::cout << "Type amount of product: ";
                    std::cin >> amountOfProduct; }

                if(amountOfProduct <= 0) {
                    std::cout << "Wrong amount of product!";
                    break;
                } else {
                    amount[index - 1] += amountOfProduct;
                }
                break;
            }

            case 4: {
                std::cout << "\nStore's earnings: " << earnings << "\n\n"; 
            }

            case 5: {
                break;
            }
        }
    }

    return 0;
}