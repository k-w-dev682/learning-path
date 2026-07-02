#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class Sensor {
    public:
        int id;
        std::string type;
        std::string room;
        double value;
        bool isTriggered;

        Sensor(int id, std::string type, std::string room, double value) {
            this -> id = id;
            this -> type = type;
            this -> room = room;
            this -> value = value;
            isTriggered = false;
        }

};

class SmartHome {
    private:
        std::vector<Sensor> sensors;

    public:
        void addSensor(std::string type, std::string room, double startValue) {
            int nextId = sensors.size() + 1;

            Sensor newSensor(nextId, type, room, startValue);

            sensors.push_back(newSensor);

            logEvent("Added new sensor.");
        }

        void logEvent(std::string message) {
            std::ofstream file("home_logs.txt", std::ios::app);

            if(file.is_open()) {
                file << "[LOG] " << message << "\n";
            }
            
            file.close();

        }

        void showStatus() {
            if(sensors.empty()) {
                std::cout << "There aren't any devices.\n";
                return;
            }

            for(const auto& s : sensors) {
                if(s.isTriggered == true) {
                    std::cout << s.id << ", " << s.type << ", " << s.room << ", " << s.value << '\n';
                    std::cout << "[!!! ALARM !!!]\n";
                } else {
                    std::cout << s.id << ", " << s.type << ", " << s.room << ", " << s.value << "\n";
                }
            }
        }

        void triggerAlert(int SensorId) {
            for(auto& s : sensors) {
                if(s.id == SensorId) {
                    s.isTriggered = true;
                    s.value = 99.0;
                    logEvent("Detected alert in room: " + s.room);
                    break;
                }
            }
        }

        void readLogs() {
            std::ifstream file("home_logs.txt");
            
            if(!file.is_open()) {
                std::cout << "File don't exist!\n";
                return;
            }

            std::string line = "";

            while(std::getline(file, line)) {
                std::cout << line << "\n";
            }
            file.close();

        }

};

int main() {
    SmartHome myHome;
    int choice = 0;

    while(choice != 5) {
        std::cout << '\n';
        std::cout << "1. View Status\n";
        std::cout << "2. Add Sensors\n";
        std::cout << "3. Trigger Alert\n";
        std::cout << "4. View logs\n";
        std::cout << "5. Quit\n";
        std::cout << "Your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch(choice) {
            case 1: {
                myHome.showStatus();

                break;
            }
             
            case 2: {
                std::string type;
                std::string room;
                double val;

                std::cout << "Enter type: ";
                std::getline(std::cin, type);

                std::cout << "Enter room: ";
                std::getline(std::cin, room);
                
                std::cout << "Enter value: ";
                std::cin >> val;

                myHome.addSensor(type, room, val);

                break;
            }

            case 3: {
                int searchId;

                std::cout << "Enter device id: ";
                std::cin >> searchId;

                myHome.triggerAlert(searchId);

                break;
            }

            case 4: {
                myHome.readLogs();

                break;
            }

            case 5: {
                std::cout << "Exiting system...";

                break;
            }
        }
    }

    return 0;
}