#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


    class clients{
        private:
            string name;
            string usage_type; //industry, farming, home
            int ID;
            double water_usage;
            double water_bill;
            double electricity_usage;
            double electricity_bill;     

        public:
        //User-defined Constructors for creating clients with id and name
            clients(){
                name = " ";
                ID = 0;
            }

            clients(string name_val, int ID_val , string usage){
                name = name_val;
                ID = ID_val;
                usage_type = usage;
                
            }

            void setName(string name_val){
                name = name_val;
            }

            void setID(int ID_val){
                ID = ID_val;
            }

            void setWaterUsage(double water_usage_val){
                water_usage = water_usage_val;

            }

            void setElectricityUsage(double electricity_usage_val){
                electricity_usage = electricity_usage_val;
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

    //deletes the client from the vector and file.
    void deleteClient(vector<clients> *client_list, int del_ID){
        bool isDeleted = false;
        for(int i=0; i<client_list->size(); i++){
            if(client_list->at(i).getID() == del_ID){
                client_list->erase(client_list->begin()+i);
                cout<<endl<<"Client deleted."<<endl;
                isDeleted = true;
            }
            writeFile("clients.txt", *client_list);
        }
        if(!isDeleted){
            cout<<endl<<"Client not found."<<endl;
        }
        
    }

//we use this function to view the price multipliers for electricity and water
    void viewprice(double industry, double farm, double home) {
    cout <<endl<<endl<< "industry multiplier : " << industry << endl;
    cout << "Farming multiplier : " << farm << endl;
    cout << "Home multiplier : " << home << endl;
}


//we use this function to change the water price multipliers
void changeWaterPrice(double& industry, double& farming, double& home) {
    int choice, isOver=1;
    while(isOver){
        viewprice(industry, farming, home);
        cout<<endl<<endl<<"1. industry multiplier"<<endl<<"2. Farming multiplier"<<endl<<"3. Home multiplier"<<endl<<endl<<"choose which one to change: ";
        cin>>choice;
        if(choice == 1){
        cout <<endl<< "New industry multiplier : ";
        cin >> industry;
        cout<<"industry multiplier changed."<<endl;
        }
        else if(choice == 2){
        cout <<endl<< "New Farming multiplier : ";
        cin >> farming;
        cout<<"Farming multiplier changed."<<endl;
        }   
        else if(choice == 3){
        cout <<endl<< "New Home multiplier : ";
        cin >> home;
        cout<<"Home multiplier changed."<<endl;
        }
        cout<<endl<<endl<<"1. Change another multiplier"<<endl<<"0. Exit"<<endl<<endl<<"choose: ";
        cin>>isOver;
    }

}


//we use this function to change the electricity price multipliers
void changeElectricityPrice(double& industry, double& farming, double& home) {
    int choice, isOver=1;
    while(isOver){
        viewprice(industry, farming, home);
        cout<<endl<<endl<<"1. industry multiplier"<<endl<<"2. Farming multiplier"<<endl<<"3. Home multiplier"<<endl<<endl<<"choose which one to change: ";
        cin>>choice;
        if(choice == 1){
        cout <<endl<< "New industry multiplier : ";
        cin >> industry;
        cout<<"industry multiplier changed."<<endl;
        }
        else if(choice == 2){
        cout <<endl<< "New Farming multiplier : ";
        cin >> farming;
        cout<<"Farming multiplier changed."<<endl;
        }   
        else if(choice == 3){
        cout <<endl<< "New Home multiplier : ";
        cin >> home;
        cout<<"Home multiplier changed."<<endl;
        }
        cout<<endl<<endl<<"1. Change another multiplier"<<endl<<"0. Exit"<<endl<<endl<<"choose: ";
        cin>>isOver;
    }

}


void menu(){
    cout << endl<<endl<<"---------------MENU---------------\n";
        cout << "1. Add new client"<<endl;
        cout << "2. Delete client by ID"<<endl;
        cout << "3. Show All clients"<<endl;
        //change usage
        cout << "4. Show client bills"<<endl;
        //change price
        cout << "5. Change water price"<<endl;
        cout << "6. Change electricity price"<<endl;
        cout << "0. Exit\n"<<endl;
        cout << "Enter your choice: ";
}

int main() {
    double w_industry = 0.11, w_farming = 0.10, w_home = 0.15;//per liter
    double e_industry = 0.50, e_farming = 0.48, e_home = 0.56;//per kw
    string new_name, usage;
    int new_ID, choice = 1, usage_type;
    vector<clients> client_list;
    const string clientsFile = "clients.txt";
    const string detailsFile = "details.txt";
    readFile(clientsFile, &client_list);
    while (choice != 0) {
        menu();
        cin >> choice;
        if (choice == 1) {
            bool checkID = false;
            cout << "enter new client name: ";
            cin >> new_name;
            do{
                cout << "enter new client ID: ";
                cin >> new_ID;
                for(int i=0; i<client_list.size(); i++){
                    if(client_list[i].getID() == new_ID){
                        cout<<endl<<"This ID is already taken. Please enter a new one.."<<endl;
                        checkID = true;
                        break;
                    }
                    else{
                        checkID = false;
                    
                    }
                }
            }while(checkID);
            while(usage_type != 1 && usage_type != 2 && usage_type != 3){     
                cout << "\n1. industry/n2. farming/n3. home/nenter usage type: ";
                cin >>usage_type;
                if(usage_type == 1){
                    usage = "industry";
                }
                else if(usage_type == 2){
                    usage = "farming";
                }
                else if(usage_type == 3){
                    usage = "home";
                }
                else{
                    cout<<"wrong input"<<endl;
                }
            }
            clients new_client(new_name, new_ID, usage);
            client_list.push_back(new_client);
            writeFile(clientsFile, client_list);
            cout<<endl<<"New client added."<<endl;
        } else if (choice == 2) {
            int del_ID;
            cout <<endl<< "enter delete for ID :";
            cin >> del_ID;
            deleteClient(&client_list, del_ID);
        } else if (choice == 3) {
            cout <<endl<<endl<<"---------------CLIENTS---------------\n"<<endl;
            for (int i = 0; i < client_list.size(); i++) {
                cout << client_list[i].getName() << " " << client_list[i].getID() << endl;
            }
            cout<< endl;
        } else if (choice == 4) {

        } else if (choice == 5) {   
            changeWaterPrice(w_industry, w_farming, w_home);
        } else if (choice == 6) {
            changeElectricityPrice(e_industry, e_farming, e_home);
        } else if (choice == 0) {
            cout << "Exiting the program.\n";

        }
    }
}