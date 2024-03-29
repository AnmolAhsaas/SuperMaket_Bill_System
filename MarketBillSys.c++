#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class Bill {
private:
    string Item;
    int Rate, Quantity;

public:
    Bill() {
        this->Item = "";
        this->Rate = 0;
        this->Quantity = 0;
    }
    void setItem(string item) {
        Item = item;
    }
    void setRate(int rate) {
        Rate = rate;
    }
    void setQuantity(int quantity) {
        Quantity = quantity;
    }
    string getItem() {
        return Item;
    }
    int getRate() {
        return Rate;
    }
    int getQuantity() {
        return Quantity;
    }
};

void addItem(Bill b) {
    bool close = false;
    while (!close) {
        system("cls");
        int choice;
        cout << "\t1.Add" << endl;
        cout << "\t2.Close" << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int rate, quant;

            cout << "\tEnter Item Name: ";
            cin >> item;
            b.setItem(item);

            cout << "\tEnter Rate of Item: ";
            cin >> rate;
            b.setRate(rate);

            cout << "\tEnter Quantity of Item: ";
            cin >> quant;
            b.setQuantity(quant);

            ofstream out("C:\\Users\\anmol\\OneDrive\\Documents\\ManagementSystemC++\\Bill.txt", ios::app);
            if (!out) {
                cout << "\tError: File Can't Open!" << endl;
            }
            else {
                out << "\t" << b.getItem() << " : " << b.getRate() << " : " << b.getQuantity() << endl << endl;
            }

            out.close();
            cout << "\tItem Added Successfully" << endl;
            Sleep(3000);
        }
        else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\tBack to Main Menu!" << endl;
            Sleep(3000);
        }
        else {
            system("cls");
            cout << "\n\n\tInvalid choice -- Re-enter" << endl;
            Sleep(2000);
        }
    }
}

void printBill() {
    system("cls");
    int cnt = 0;
    bool close = false;
    while (!close) {
        system("cls");
        int choice;
        cout << "\t1.Add Bill" << endl;
        cout << "\t2.Close Session" << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("cls");
            string item;
            int quant;
            cout << "\tEnter Item: ";
            cin >> item;
            cout << "\tEnter Quantity: ";
            cin >> quant;

            ifstream in("C:\\Users\\anmol\\OneDrive\\Documents\\ManagementSystemC++\\Bill.txt");
            ofstream out("C:\\Users\\anmol\\OneDrive\\Documents\\ManagementSystemC++\\Bill_Temp.txt");

            string line;
            bool found = false;

            while (getline(in, line)) {
                stringstream ss;
                ss << line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter;
                ss >> itemName >> delimiter >> itemRate >> delimiter >> itemQuant;

                if (item == itemName) {
                    found = true;
                    if (quant <= itemQuant) {
                        int amount = itemRate * quant;

                        int newQuant = itemQuant - quant;
                        itemQuant = newQuant;
                        cnt += amount;

                        cout << "\t Item | Rate | Quantity | Amount" << endl;
                        cout << "\t " << itemName << "\t " << itemRate << "\t " << itemQuant << "\t " << amount << endl;

                        out << "\t" << itemName << " : " << itemRate << " : " << itemQuant << endl;
                    }
                    else {
                        cout << "\tSorry, " << item << " Ended" << endl;
                        out << line << endl;
                    }
                }
                else {
                    out << line << endl;
                }
            }
            if (!found) {
                cout << "\tItem Not Available!" << endl;
            }
            out.close();
            in.close();
            remove("C:\\Users\\anmol\\OneDrive\\Documents\\ManagementSystemC++\\Bill.txt");
            rename("C:\\Users\\anmol\\OneDrive\\Documents\\ManagementSystemC++\\Bill_Temp.txt", "C:\\Users\\anmol\\OneDrive\\Documents\\ManagementSystemC++\\Bill.txt");
        }
        else if (choice == 2) {
            system("cls");
            close = true;
            cout << "\n\n\tCounting Total Bill" << endl;
        }
        else {
            system("cls");
            cout << "\n\n\tInvalid choice -- Re-enter" << endl;
        }
        Sleep(2000);
    }
    system("cls");
    cout << endl << endl;
    cout << "\t total Bill -------------- : " << cnt << endl << endl;
    cout << "\tThanks For Shopping!" << endl;
    Sleep(5000);
}

int main() {
    Bill b;

    bool exit = false;
    while (!exit) {
        system("cls");
        int val;
        cout << "\tWelcome to Super Market Billing System" << endl;
        cout << "\t***************************************" << endl;
        cout << "\t\t1.Add Item." << endl;
        cout << "\t\t2.Print Bill." << endl;
        cout << "\t\t3.Exit." << endl;
        cout << "\t\t.Enter Choice: ";
        cin >> val;

        if (val == 1) {
            system("cls");
            addItem(b);
            Sleep(3000);
        }
        else if (val == 2) {
            printBill();
        }
        else if (val == 3) {
            system("cls");
            exit = true;
            cout << "\tGood Luck!" << endl;
            Sleep(3000);
        }
        else {
            system("cls");
            cout << "\n\n\tInvalid choice -- Re-enter" << endl;
            Sleep(2000);
        }
    }
    return 0;
}
