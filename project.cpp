#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


    class clients{
        private:
            string name;
            int ID;

        public:
        //User-defined Constructors for creating clients with id and name
            clients(){
                name = " ";
                ID = 0;
            }

            clients(string name_val, int ID_val){
                name = name_val;
                ID = ID_val;
                
            }

            void setName(string name_val){
                name = name_val;
            }

            void setID(int ID_val){
                ID = ID_val;
            }

            string getName() const {
                return name;
            }

            int getID() const {
                return ID;
            }

    };


    //reads clients.txt file and stores the data in a vector. text file does not deleting after program ends so when we run the program again, it reads the old. 
    void readFile(string fileName, vector<clients> *client_list){
        ifstream inputFile(fileName);
        clients old_file;
        string name;
        int ID;
        while(inputFile>>name>>ID){
            old_file.setName(name);
            old_file.setID(ID);
            client_list->push_back(old_file);
        }

    inputFile.close();
    }

    //writes the new client data to the clients.txt file
    void writeFile(string fileName, vector<clients> client_list){
        ofstream outputFile(fileName);
        for(int i=0; i<client_list.size(); i++){
            outputFile<<client_list[i].getName()<<" "<<client_list[i].getID()<<endl;
        }
        outputFile.close();

    }
void changeprice(double& industry, double& farming, double& home) {
    cout << "New industry multiplier : ";
    cin >> industry;
    cout << "New Farming multiplier : ";
    cin >> farming;
    cout << "New Home multiplier : ";
    cin >> home;
}

void viewprice(double industry, double farm, double home) {
    cout << "industry multiplier : " << industry << "\n";
    cout << "Farming multiplier : " << farm << "\n";
    cout << "Home multiplier : " << home << "\n";
}

int main() {
    double industryM = 0.11;
    double farmingM = 0.10;
    double homeM = 0.15;
    string new_name, myText;
    int new_ID, choice = 1;
    vector<clients> client_list;
    const string clientsFile = "clients.txt";
    readFile(clientsFile, &client_list);
    while (choice != 0) {
        cout << "Menu:\n";
        cout << "1. Add new client\n";
        cout << "2. Delete client by ID\n";
        cout << "3. Show All clients\n";
        cout << "4. Price Changing\n";
        cout << "5. View Price Multipliers\n";
        cout << "6. Paying Bill\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            cout << "enter new client name: ";
            cin >> new_name;
            cout << "enter new client ID: ";
            cin >> new_ID;
            clients new_client(new_name, new_ID);
            client_list.push_back(new_client);
            writeFile(clientsFile, client_list);

            for (int i = 0; i < client_list.size(); i++) {
                cout << client_list[i].getName() << " " << client_list[i].getID() << endl;
            }
            cout << "enter 1 to add new client, 0 to exit: ";
            cin >> choice;
        } else if (choice == 2) {
            int del_ID;
            cout << "enter delete for ID :";
            cin >> del_ID;
        } else if (choice == 3) {

        } else if (choice == 4) {
            changeprice(industryM, farmingM, homeM);
        } else if (choice == 5) {
            viewprice(industryM, farmingM, homeM);
        } else if (choice == 0) {
            cout << "Exiting the program.\n";

        }
    }
}