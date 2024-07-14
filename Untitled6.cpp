#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SportsEquipment {
private:
    vector<int> EquipmentId;
    vector<string> EquipmentName;
    vector<string> Type;
    vector<string> Brand;
    vector<int> NumberofCopies;
    int lastId;

public:
    SportsEquipment() {
        loadFile("equipment.txt");
        lastId = EquipmentId.empty() ? 0 : EquipmentId.back();
    }

    void insertEquipment() {
        system("cls");
        cout << "[1] New Sports Equipment\n\n";
        lastId++;
        int copy;
        string name, type, brand;
        cout << "Equipment ID: " << lastId << endl;
        cout << "Equipment Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Type: ";
        getline(cin, type);
        cout << "Brand: ";
        getline(cin, brand);
        cout << "Number of copies: ";
        cin >> copy;
        EquipmentId.push_back(lastId);
        EquipmentName.push_back(name);
        Type.push_back(type);
        Brand.push_back(brand);
        NumberofCopies.push_back(copy);
        saveFile("equipment.txt");
        cout<<"Successfuly Added Sports Equipment "<<lastId;
    }

    void RentEquipment(int customerId) {
        system("cls");
        cout << "[2] Rent a Sports Equipment\n\n";
        int rentId;
        cout << "Sports Equipment ID: ";
        cin >> rentId;
        bool found = false;

        for (size_t i = 0; i < EquipmentId.size(); i++) {
            if (rentId == EquipmentId[i]) {
                found = true;
                if (NumberofCopies[i] == 0) {
                    cout << "No more copies for this Sport Equipment." << endl;
                } else {
                    cout << "Equipment Name: " << EquipmentName[i] << endl;
                    NumberofCopies[i]--;
                    cout << "Number of Copies: " << NumberofCopies[i] << endl;
                    saveFile("equipment.txt");
                }
                break;
            }
        }
        if (!found) {
            cout << "Not found." << endl;
        }
    }

    void showEquipmentDetails() {
            int searchID;
			bool found = false;
			cout << "Sports Equipment ID: ";
			cin >> searchID;
			for (size_t i = 0; i < EquipmentId.size(); ++i) {
				if (searchID == EquipmentId[i]) {
					cout << "\nSports Equipment Detail\n\n";
					cout << "Equipment ID: "<<EquipmentId[i]<<endl;
					cout<<"Equipment Name: "<<EquipmentName[i]<<endl;
					cout<<"Type: "<< Type[i]<<endl;
					cout<<"Brand: "<<Brand[i]<<endl;
					cout<<"Copies: "<<NumberofCopies[i]<<endl;
					found = true;
					break;
				}
			}
			if (found == false) {
				cout << "Sports Equipment ID: " << searchID << " not found\n\n";
			}
	}

	void displayAllEquipment() {
		cout<<"All Sports Equipment\n";
	  for (size_t i = 0; i < EquipmentId.size(); ++i) {
					cout << "Equipment ID: "<<EquipmentId[i]<<endl;
					cout<<"Equipment Name: "<<EquipmentName[i]<<endl;
					cout<<"Type: "<< Type[i]<<endl;
					cout<<"Brand: "<<Brand[i]<<endl;
					cout<<"Copies: "<<NumberofCopies[i]<<endl<<endl;
    }
}

    void CheckAvailability() {
        int searchID;
			bool found = false;
			cout << "Sports Equipment ID: ";
			cin >> searchID;
			for (size_t i = 0; i < EquipmentId.size(); ++i) {
				if (searchID == EquipmentId[i]) {
					cout << "\nCheck Availability of Sports Equipment\n\n";
					cout << "Equipment ID: "<<EquipmentId[i]<<endl;
					cout<<"Equipment Name: "<<EquipmentName[i]<<endl;
					cout<<"Type: "<< Type[i]<<endl;
					cout<<"Brand: "<<Brand[i]<<endl;
					cout<<"Copies: "<<NumberofCopies[i]<<endl;
					if (NumberofCopies[i] == 0) {
						cout << "Availability: Unavailable\n\n";
					}
					else {
						cout << "Availability: Available\n\n";
					}
					found = true;
					break;
				}

			}
			if (found == false) {
				cout << "Sports Equipment ID: " << searchID << " not found\n\n";
	}
    }

    void saveFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (size_t i = 0; i < EquipmentId.size(); ++i) {
                outFile << EquipmentId[i] << endl
                        << EquipmentName[i] << endl
                        << Type[i] << endl
                        << Brand[i] << endl
                        << NumberofCopies[i] << endl << endl;
            }
            outFile.close();
        } else {
            cout << "File might not be existing or cannot be accessed." << endl;
        }
    }

    void loadFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            EquipmentId.clear();
            EquipmentName.clear();
            Type.clear();
            Brand.clear();
            NumberofCopies.clear();

            int id, copy;
            string name, type, brand;

            while (inFile >> id) {
                inFile.ignore();
                getline(inFile, name);
                getline(inFile, type);
                getline(inFile, brand);
                inFile >> copy;

                EquipmentId.push_back(id);
                EquipmentName.push_back(name);
                Type.push_back(type);
                Brand.push_back(brand);
                NumberofCopies.push_back(copy);
            }
            inFile.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    vector<int> getEquipmentId() const { return EquipmentId; }
    vector<int>& getNumberOfCopies() { return NumberofCopies; }
};

class Customer {
protected:
    vector<int> CustomerId;
    vector<string> Name;
    vector<string> Address;
    int lastId;

public:
    Customer() {
        loadFile("customer.txt");
        lastId = CustomerId.empty() ? 0 : CustomerId.back();
    }

    void addCustomer() {
    system("cls");
    cout << "[7-1] Add New Customer\n\n";
    lastId++;
    string name, address;
    cout << "Customer ID: " << lastId << endl;
    cout << "Customer Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Customer Address: ";
    getline(cin, address);
    cout << endl;

    CustomerId.push_back(lastId);
    Name.push_back(name);
    Address.push_back(address);
    saveFile("customer.txt");

    cout << "Successfully added Customer " << lastId << endl;
}

    void showDetails() {
        system("cls");
        cout << "[7-2] Show the Customer details\n\n";
        int search;
        cout << "Customer ID: ";
        cin >> search;
        bool found = false;

        for (int i = 0; i < CustomerId.size(); i++) {
            if (search == CustomerId[i]) {
                found = true;
                cout << "Name: " << Name[i];
                cout << "\nAddress: " << Address[i];
                cout << endl << endl;
                break;
            }
        }

        if (!found) {
            cout << "Customer ID: " << search << " is not found.\n\n";
        }
    }

    void saveFile(const string& filename) {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (size_t i = 0; i < CustomerId.size(); ++i) {
                outFile << CustomerId[i] << endl
                        << Name[i] << endl
                        << Address[i] << endl
                        << endl;
            }
            outFile.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    void loadFile(const string& filename) {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            CustomerId.clear();
            Name.clear();
            Address.clear();

            int id;
            string name, address;
            while (inFile >> id) {
                inFile.ignore();
                getline(inFile, name);
                getline(inFile, address);

                CustomerId.push_back(id);
                Name.push_back(name);
                Address.push_back(address);

                string line;
                getline(inFile, line); // Skip blank line
            }
            inFile.close();
        } else {
            cout << "Unable to open file: " << filename << endl;
        }
    }

    vector<int> getCustomerId() const { return CustomerId; }
};

class CustomerRent : public Customer {
private:
    vector<int>Customer_id;
    vector<int>Equipment_id;

public:
	
    void rentEquipment(SportsEquipment& sport) {
        cout << "Enter your Customer ID: ";
        int customerId;
        cin >> customerId;
        auto it = find(CustomerId.begin(), CustomerId.end(), customerId);
        if (it == CustomerId.end()) {
            cout << "Invalid Customer ID." << endl;
            return;
        }
        int equipmentId;
        cout << "Enter Equipment ID to rent: ";
        cin >> equipmentId;

        

        for (size_t i = 0; i < sport.getEquipmentId().size(); i++) {
            if (equipmentId == sport.getEquipmentId()[i]) {
                if (sport.getNumberOfCopies()[i] > 0) {
                    rentedEquipments.emplace_back(customerId, equipmentId);
                    sport.getNumberOfCopies()[i]--;
                    sport.saveFile("equipment.txt");
                    cout << "Equipment ID " << equipmentId << " has been rented." << endl;
                } else {
                    cout << "No more copies available." << endl;
                }
                return;
            }
        }
        cout << "Equipment ID not found." << endl;
    }

    void returnEquipment(SportsEquipment& sport) {
        int equipmentId;
        cout << "Enter your Customer ID: ";
        int customerId;
        cin >> customerId;

        cout << "Enter Equipment ID to return: ";
        cin >> equipmentId;

        auto it = find_if(rentedEquipments.begin(), rentedEquipments.end(),
            [customerId, equipmentId](const pair<int, int>& rental) {
                return rental.first == customerId && rental.second == equipmentId;
            });

        if (it != rentedEquipments.end()) {
            rentedEquipments.erase(it);
            cout << "Equipment ID " << equipmentId << " has been returned." << endl;

            for (size_t i = 0; i < sport.getEquipmentId().size(); i++) {
                if (sport.getEquipmentId()[i] == equipmentId) {
                    sport.getNumberOfCopies()[i]++;
                    sport.saveFile("equipment.txt");
                    break;
                }
            }
        } else {
            cout << "Equipment ID " << equipmentId << " was not rented by you." << endl;
        }
    }

    void displayRentedEquipments() const {
        if (rentedEquipments.empty()) {
            cout << "No equipment rented." << endl;
        } else {
            cout << "Rented Equipments:\n";
            for (const auto& rental : rentedEquipments) {
                cout << "Customer ID: " << rental.first << ", Equipment ID: " << rental.second << endl;
            }
        }
    }
};

int main() {
    system("cls");
    SportsEquipment sport;
    Customer customer;
    CustomerRent customerrent;
    int choice;

    do {
        cout
            << "\nSports Equipment Rental System\n"
            << "[1] New Sports Equipment\n"
            << "[2] Rent a Sports Equipment\n"
            << "[3] Return a Sports Equipment\n"
            << "[4] Show Sports Equipment Details\n"
            << "[5] Display All Sports Equipment\n"
            << "[6] Check Sports Equipment Availability\n"
            << "[7] Customer Maintenance\n"
            << "[8] Exit Program\n"
            << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            sport.insertEquipment();
            break;
        case 2:
            customerrent.rentEquipment(sport);
            break;
        case 3:
            customerrent.returnEquipment(sport);
            break;
        case 4:
            sport.showEquipmentDetails();
            break;
        case 5:
            sport.displayAllEquipment();
            break;
        case 6:
            sport.CheckAvailability();
            break;
        case 7: {
            int subChoice;
            cout
                << "\nCustomer Maintenance Menu:\n"
                << "1. Add New Customer\n"
                << "2. Show Customer Details\n"
                << "3. List All Equipment Rented by a Customer\n"
                << "Enter your choice: ";
            cin >> subChoice;

            switch (subChoice) {
            case 1:
                customer.addCustomer();
                break;
            case 2:
                customer.showDetails();
                break;
            case 3:
                customerrent.displayRentedEquipments();
                break;
            default:
                cout << "Invalid option." << endl;
                break;
            }
            break;
        }
        case 8:
            break;
        default:
            cout << "Invalid option." << endl;
            break;
        }
    } while (choice != 8);

    return 0;
}
