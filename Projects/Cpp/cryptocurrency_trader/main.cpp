#include <iostream>
#include <ctime>
#include <iomanip>
#include <cmath>

class Asset {
    public:
        std::string name;
        double price;
        double owned;

        void updatePrice() {
            int percentChange = (rand() % 31) - 15;

            double changeFactor  = percentChange / 100.0;

            price = price * (1.0 + changeFactor);

            if (price < 0.01) {
                price = 0.01;
            }
        }
};

int main() {
    srand(time(0));
    system("cls");

    double cash = 1000.0;
    int day = 1;
    Asset market[3] = {
        {"Bitcoin", 59000.0, 0.0},
        {"Ethereum", 1582.58, 0.0},
        {"Litecoin", 42.38, 0.0}
    };
    int choice = 0;

    std::cout << std::fixed << std::setprecision(2);

    while(choice != 5) {
        if(day > 15) {
            double totalAssetValue = 0;
            for(int i = 0; i < 3; i++) {
                totalAssetValue += market[i].owned * market[i].price;
            }
            double totalNetWorth = cash + totalAssetValue;

            std::cout << "Game over!\n";
            std::cout << "Final cash: $" << cash << '\n';
            std::cout << "Value of Assets: $" << totalAssetValue << '\n';
            std::cout << "Total Net Worth: $" << totalNetWorth << '\n';
            break;
        }

        std::cout << "1. Show Market & Portfolio\n";
        std::cout << "2. Buy Asset\n";
        std::cout << "3. Sell Asset\n";
        std::cout << "4. Next Day\n";
        std::cout << "5. Quit\n";
        std::cout << "Your Choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << std::left;
                std::cout << std::setw(15) << "ASSET" << std::setw(15) << "PRICE (USD)" << std::setw(15) << "YOUR WALLET" << '\n';

                for(int i = 0; i < 3; i++) {
                    std::cout << std::setw(15) << market[i].name << std::setw(15) << market[i].price << std::setw(15) << market[i].owned << "\n";
                }
                std::cout << "Available Cash: $" << cash << " USD | Day: " << day << "/15\n\n";
                break;
            }
        
            case 2: {
                int assetChoice = 0;
                std::cout << "Buy Asset\n";

                for(int i = 0; i < 3; i++) {
                    std::cout << i + 1 << ". " << market[i].name << " ($ " << market[i].price << ")\n";
                }
                std::cout << "Choose asset to buy (1-3): ";
                std::cin >> assetChoice;

                if(assetChoice < 1 || assetChoice > 3) {
                    std::cout << "Invalid choice!\n\n";
                    break;
                }

                int idx = assetChoice - 1;
                double spendAmount = 0;

                std::cout << "Available cash: $" << cash << ". How much USD do you want to spend? ";
                std::cin >> spendAmount;

                if(spendAmount <= 0 || spendAmount > cash) {
                    std::cout << "Invalid amount or not enough cash!\n\n";
                    break;
                }

                double boughtShares = spendAmount / market[idx].price;

                cash -= spendAmount;
                market[idx].owned += boughtShares;
                
                std::cout << "Success! Bought " << boughtShares << " of " << market[idx].name << "\n\n";

                break;
            }

            case 3: {
                int assetChoice = 0;

                std::cout << std::left;
                std::cout << std::setw(15) << "INDEX" << std::setw(15) << "ASSET" << std::setw(15) << "PRICE (USD)" << std::setw(15) << "YOUR WALLET" << '\n';

                for(int i = 0; i < 3; i++) {
                    std::cout << std::setw(15) << i + 1 << std::setw(15) << market[i].name << std::setw(15) << market[i].price << std::setw(15) << market[i].owned << "\n";
                }

                std::cout << "Choose which Asset you want to sell (1-3): ";
                std::cin >> assetChoice;

                if(assetChoice < 1 || assetChoice > 3) {
                    std::cout << "Invalid choice!\n\n";
                    break;
                }

                int idx = assetChoice - 1;

                if(market[idx].owned <= 0.0001) {
                    std::cout << "You do not have this Asset!\n\n";
                    break;
                }

                double amount = 0;
                std::cout << "Choose amount of Assets that you want to sell: ";
                std::cin >> amount;

                if(amount > market[idx].owned) {
                    std::cout << "You do not have this much Assets!\n\n";
                    break;
                }

                double revenue = amount * market[idx].price;
                cash += revenue;
                market[idx].owned -= amount;
                
                std::cout << "Success! Sold " << amount << " of " << market[idx].name << "\n\n";
                break;
            }
        
            case 4: {
                std::cout << "Advancing to the next day...\n";
                for(int i = 0; i < 3; i++) {
                    market[i].updatePrice();
                }
                day++;
                std::cout << "Welcome to Day " << day <<"!\n\n";
                break;
            }

            case 5: {
                std::cout << "Thanks for playing!\n";
                break;
            }
        }
    }

    return 0;
}