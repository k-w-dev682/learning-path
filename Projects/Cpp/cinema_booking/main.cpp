#include <iostream>
#include <iomanip>

int main() {
    int seats[15][10] = {0};
    double ticketPrice = 25.00;
    double earnings = 0;
    int sold = 0;
    int choice = 0;

    std::cout << std::fixed << std::setprecision(2);

    while(choice != 4) {
        std::cout << "Choose number: \n";
        std::cout << "1. Dispaly room \n";
        std::cout << "2. Book seat \n";
        std::cout << "3. Stats \n";
        std::cout << "4. Quit \n";

        std::cout << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                std::cout << "\n     1   2   3   4   5   6   7   8   9  10\n\n";

                for(int i = 0; i < 15; i++) {
                    std::cout << std::left << std::setw(2) << i + 1 << "   "; 
                    
                    for(int j = 0; j < 10; j++) {
                        if(seats[i][j] == 0) {
                            std::cout << "[0] "; 
                        } else {
                            std::cout << "[X] "; 
                        }
                    }
                    std::cout << '\n';
                }
                std::cout << '\n';
                break;
            }

            case 2: {
                int row = 0;
                int seat = 0;

                std::cout << "Choose seat \n";
                std::cout << "Enter row number (1-15): ";
                std::cin >> row;
                std::cout << "Enter seat number (1-10): ";
                std::cin >> seat;

                if(row < 1 || row > 15 || seat < 1 || seat > 10) {
                    std::cout << "Invalid row or seat number!\n\n";
                    break;
                }

                if(seats[row - 1][seat - 1] == 1) {
                    std::cout << "This seat is already taken! Choose another one\n\n";
                    break;
                } else {
                    seats[row - 1][seat - 1] = 1;
                    earnings += ticketPrice;
                    sold++;
                    std::cout << "Seat in row " << row << ", place " << seat << " has been booked.\n\n";
                }
                break;
            }

            case 3: {
                std::cout << "Total earnings: " << earnings << '\n';
                std::cout << "Number of tickets sold: " << sold << '\n';
                std::cout << "Empty seats: " << 150 - sold << "\n\n";

                break;
            }

            case 4: {
                std::cout << "Quiting...";
                break;
            }
        }
    }
    

    return 0;
}