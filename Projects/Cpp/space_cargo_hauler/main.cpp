#include <iostream>
#include <iomanip>

class SpaceShip {
    public:
        double credits;
        int fuel;
        int maxFuel;
        int hull;
        int maxHull;
        int cargoCapacity;
        int ironOwned;
        int uraniumOwned;

        int getFreeCargoSpace() {
            int usedSpace = ironOwned + uraniumOwned;
            return cargoCapacity - usedSpace;
        }

        void repair() {
            hull = maxHull;
        }

        void refuel() {
            fuel = maxFuel;
        }
};

class Planet {
    public:
        std::string name;
        double ironPrice;
        double uraniumPrice;
};

int main() {
    system("cls");
    
    SpaceShip spaceShip;
    spaceShip.credits = 1000.0;
    spaceShip.fuel = 100;
    spaceShip.maxFuel = 100;
    spaceShip.hull = 100;
    spaceShip.maxHull = 100;
    spaceShip.cargoCapacity = 10;
    spaceShip.ironOwned = 0;
    spaceShip.uraniumOwned = 0;

    Planet planets[3] = {
        {"Earth", 100.20, 1800.00},
        {"Mars", 120.99, 1200.00},
        {"Venus", 60.50, 2000.00}
    };

    int currentPlanetIdx = 0;

    std::cout << std::fixed << std::setprecision(2);

    int choice = 0;

    while(choice != 5) {
        std::cout << "1. Status & Cargo\n";
        std::cout << "2. Marketplace\n";
        std::cout << "3. Travel to another planet\n";
        std::cout << "4. Space Station Services\n";
        std::cout << "5. Quit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << std::left;
                std::cout << std::setw(25) << "CREDITS" 
                          << std::setw(25) << "FUEL" 
                          << std::setw(25) << "HULL" 
                          << std::setw(25) << "CARGO CAPACITY" 
                          << std::setw(25) << "IRON OWNED" 
                          << std::setw(25) << "URANIUM OWNED" 
                          << "\n";
                
                std::string fuelStr = std::to_string(spaceShip.fuel) + "/" + std::to_string(spaceShip.maxFuel);
                std::string hullStr = std::to_string(spaceShip.hull) + "/" + std::to_string(spaceShip.maxHull);
                std::string cargoStr = std::to_string(spaceShip.ironOwned + spaceShip.uraniumOwned) + "/" + std::to_string(spaceShip.cargoCapacity);

                std::cout << std::setw(25) << spaceShip.credits 
                          << std::setw(25) << fuelStr 
                          << std::setw(25) << hullStr 
                          << std::setw(25) << cargoStr 
                          << std::setw(25) << spaceShip.ironOwned 
                          << std::setw(25) << spaceShip.uraniumOwned 
                          << "\n\n"; 
                break;
            }

            case 2: {
                int marketChoice = 0;
                std::cout << "\n MARKETPLACE - " << planets[currentPlanetIdx].name << '\n';
                std::cout << "1. Buy Resources\n";
                std::cout << "2. Sell Resources\n";
                std::cout << "Your choice: ";
                std::cin >> marketChoice;

                if(marketChoice == 1) {
                    int resChoice = 0;
                    std::cout << "\nBUY ITEMS\n";
                    std::cout << "1. Iron ($" << planets[currentPlanetIdx].ironPrice << "\n";
                    std::cout << "2. Uranium ($" << planets[currentPlanetIdx].uraniumPrice << "\n";
                    std::cout << "Choose resource (1-2): ";
                    std::cin >> resChoice;

                    if(resChoice < 1 || resChoice > 2) {
                        std::cout << "Invalid choice!\n\n";
                        break;
                    }

                    int amountToBuy = 0;
                    std::cout << "Free cargo space: " << spaceShip.getFreeCargoSpace() << " units.\n";
                    std::cout << "How many units do you want to buy?: ";
                    std::cin >> amountToBuy;

                    if(amountToBuy <= 0 || amountToBuy > spaceShip.getFreeCargoSpace()) {
                        std::cout << "Invalid amount or not enough cargo space!\n\n";
                        break;
                    }
                    
                    if (resChoice == 1) {
                        double totalCost = amountToBuy * planets[currentPlanetIdx].ironPrice;
                        if (totalCost > spaceShip.credits) { std::cout << "Not enough credits!\n\n"; break; }
                        
                        spaceShip.credits -= totalCost;
                        spaceShip.ironOwned += amountToBuy;
                        std::cout << "Success! Bought " << amountToBuy << " units of Iron.\n\n";
                    } 
                    else if (resChoice == 2) {
                        double totalCost = amountToBuy * planets[currentPlanetIdx].uraniumPrice;
                        if (totalCost > spaceShip.credits) { std::cout << "Not enough credits!\n\n"; break; }
                        
                        spaceShip.credits -= totalCost;
                        spaceShip.uraniumOwned += amountToBuy;
                        std::cout << "Success! Bought " << amountToBuy << " units of Uranium.\n\n";
                    }
                }
                else if(marketChoice == 2) {
                    int resChoice = 0;
                    std::cout << "\nSELL ITEMS\n";
                    std::cout << "1. Iron (You have: " << spaceShip.ironOwned << ") - Price: $" << planets[currentPlanetIdx].ironPrice << '\n';
                    std::cout << "2. Uranium (You have: " << spaceShip.uraniumOwned << ") - Price: $" << planets[currentPlanetIdx].uraniumPrice << '\n';
                    std::cout << "Choose resource (1-2): ";
                    std::cin >> resChoice;

                    if(resChoice < 1 || resChoice > 2) {
                        std::cout << "Invalid choice!\n\n";
                        break;
                    }

                    int amountTosell = 0;
                    std::cout << "How many units do you want to sell? ";
                    std::cin >> amountTosell;

                    if(amountTosell <= 0) {
                        std::cout << "Invalid amount!\n\n";
                        break;
                    }

                    if(resChoice == 1) {
                        if(amountTosell > spaceShip.ironOwned) {
                            std::cout << "You don't have that much Iron!\n\n";
                            break;
                        }

                        double payout = amountTosell * planets[currentPlanetIdx].ironPrice;
                        spaceShip.credits += payout;
                        spaceShip.ironOwned -= amountTosell;
                        std::cout << "Success! Sold " << amountTosell << " units of Iron for $" << payout << "\n\n";
                    }
                    else if(resChoice == 2) {
                        if(amountTosell > spaceShip.uraniumOwned) {
                            std::cout << "You don't have that much Uranium!\n\n";
                            break;
                        }

                        double payout = amountTosell * planets[currentPlanetIdx].uraniumPrice;
                        spaceShip.credits += payout;
                        spaceShip.uraniumOwned -= amountTosell;
                        std::cout << "Success! Sold " << amountTosell << " units of Uranium for $" << payout << "\n\n";
                    }
                }
                else {
                    std::cout << "Invalid choice!\n\n";
                }
                break;
            }

            case 3: {
                int planetChoice = 0;
                std::cout << "CURRENT PLANET: " << planets[currentPlanetIdx].name << '\n';
                std::cout << "Choose your next planet: \n";
                std::cout << "1. Earth\n";
                std::cout << "2. Mars\n";
                std::cout << "3. Venus\n";
                std::cout << "Your choice: ";
                std::cin >> planetChoice;

                if(planetChoice < 1 || planetChoice > 3) {
                    std::cout << "Invalid planet choice!\n\n";
                    break;
                }

                if(planetChoice - 1 == currentPlanetIdx) {
                    std::cout << "You are already on this planet!\n\n";
                    break;
                } 
                else if(spaceShip.fuel < 20) {
                    std::cout << "You don't have enough fuel!\n\n";
                    break;
                } else {
                    currentPlanetIdx = planetChoice - 1;
                    std::cout << "Success! You traveled to " << planets[currentPlanetIdx].name << "\n\n";
                    spaceShip.fuel -= 20;
                }

                break;
            }

            case 4: {
                int serviceChoice = 0;
                std::cout << "\nSPACE STATION SERVICES\n";
                std::cout << "1. Repair Spaceship ($5.00 per 1% Hull damage)\n";
                std::cout << "2. Refuel Spaceship ($2.00 per 1 unit of Fuel)\n";
                std::cout << "Your choice: ";
                std::cin >> serviceChoice;

                if(serviceChoice < 1 || serviceChoice > 2) {
                    std::cout << "Invalid choice!\n\n";
                    break;
                }

                if(serviceChoice == 1) {
                    int damage = spaceShip.maxHull - spaceShip.hull;
                    
                    if(damage == 0) {
                        std::cout << "Your hull is already pristine! No repairs needed.\n\n";
                        break;
                    }

                    double repairCost = damage * 5.0;
                    std::cout << "Repairing " << damage << "% of hull will cost $" << repairCost << ".\n";

                    if(spaceShip.credits < repairCost) {
                        std::cout << "You don't have enough credits for a full repair!\n\n";
                        break;
                    }

                    spaceShip.repair();
                    spaceShip.credits -= repairCost;
                    std::cout << "Success! Hull restored to 100%.\n\n";
                }

                if(serviceChoice == 2) {
                    int missingFuel = spaceShip.maxFuel - spaceShip.fuel;

                    if(missingFuel == 0) {
                        std::cout << "Your fuel tank is already full!\n\n";
                        break;
                    }

                    double refuelCost = missingFuel * 2.0;
                    std::cout << "Topping up " << missingFuel << " units of fuel will cost $" << refuelCost << ".\n";

                    if(spaceShip.credits < refuelCost) {
                        std::cout << "You don't have enough credits for this much fuel!\n\n";
                        break;
                    }

                    spaceShip.refuel();
                    spaceShip.credits -= refuelCost;
                    std::cout << "Success! Tank is now full.\n\n";
                }
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