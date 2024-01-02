#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
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
                electricity_usage = 0;
                water_usage = 0;
                water_bill = 0.0;
                electricity_bill = 0.0;
            }

            void setUsage_type(string usage_val){
                usage_type = usage_val;
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

            string getUsage_type(){
                return usage_type;
            }
            double getWaterUsage(){
                return water_usage;
            }
            double getElectricityUsage(){
                return electricity_usage;
            }

    };


    //reads clients.txt file and stores the data in a vector. text file does not deleting after program ends so when we run the program again, it reads the old. 
    void readFile(string fileName, vector<clients> *client_list){
        ifstream inputFile(fileName);
        clients old_file;
        string name, usage_type;
        int ID;
        double water_usage, electricity_usage;
        while(inputFile>>quoted(name)>>ID>>usage_type>>water_usage>>electricity_usage){//quoted function reads the string with spaces. in some versions syntax is __quoted . 
            old_file.setName(name);
            old_file.setID(ID);
            old_file.setUsage_type(usage_type);
            old_file.setWaterUsage(water_usage);
            old_file.setElectricityUsage(electricity_usage);
            client_list->push_back(old_file);
        }

    inputFile.close();
    }

    //writes the new client data to the clients.txt file
    void writeFile(string fileName, vector<clients> client_list){
        ofstream outputFile(fileName);
        for(int i=0; i<client_list.size(); i++){
            outputFile<<"\""<<client_list[i].getName()<<"\""<<" "<<client_list[i].getID()<<" "<<client_list[i].getUsage_type()<<" "<<client_list[i].getWaterUsage()<<" "<<client_list[i].getElectricityUsage()<<endl;
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

// menu that shows the options
void menu(){
    cout << endl<<endl<<"---------------MENU---------------\n";
        cout << "1. Add new client"<<endl;
        cout << "2. Delete client by ID"<<endl;
        cout << "3. Show All clients"<<endl;
        cout << "4. Change client usage"<<endl;
        cout << "5. Show client bills"<<endl;
        cout << "6. Change price multiplier"<<endl;
        cout << "0. Exit\n"<<endl;
        cout << "Enter your choice: ";
}

int main() {
    double w_industry = 1.40, w_farming = 1.35, w_home = 1.50; //per liter
    double e_industry = 2.45, e_farming = 2.15, e_home = 2.70; //per kw
    string new_name, usage;
    int new_ID, choice = 1, usage_type;

    //vector for storing clients
    vector<clients> client_list; 


    const string clientsFile = "clients.txt";


    //we use this function when program starts to read the clients.txt file and store the data in a client_list vector
    readFile(clientsFile, &client_list);


    while (choice != 0) {
        //menu function shows the options
        menu();
        cin >> choice;

        //add new client
        if (choice == 1) {
            bool checkID = false;
            cin.ignore();
            cout << "enter new client's full name: ";
            getline(cin, new_name); //we use getline to get the full name

            //we check if the ID is already taken
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

            //we get the usage type
            do{     
                cout << "\n1. industry\n2. farming\n3. home\nenter usage type: ";
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
            }while(usage_type != 1 && usage_type != 2 && usage_type != 3);

            //we create a new client with the given data and push it to the client_list vector
            clients new_client(new_name, new_ID, usage);
            client_list.push_back(new_client);

            //we write the new client data to the clients.txt file
            writeFile(clientsFile, client_list);
            cout<<endl<<"New client added."<<endl;

        //delete client
        } else if (choice == 2) {
            int del_ID;
            cout <<endl<< "enter ID for delete the client :";
            cin >> del_ID;
            deleteClient(&client_list, del_ID);

        //show all clients
        } else if (choice == 3) {
            cout <<endl<<endl<<"---------------CLIENTS---------------\n"<<endl;
            for (int i = 0; i < client_list.size(); i++) {
                 cout <<"client: "<< client_list[i].getName() << "   ID: " << client_list[i].getID()<< endl;
            }
            cout<< endl;
        }


        //change client usage
        else if(choice == 4){
            int client_ID, usage_type;
            double usage;
            bool isFound = false;


            cout <<endl<< "enter client ID: ";
            cin >> client_ID;

            //we check if the client is in the vector
            for(int i=0; i<client_list.size(); i++){
                if(client_list[i].getID() == client_ID){
                    isFound = true;
                    do{
                        //we get the usage type to change
                        cout << "\n1. water\n2. electricity\nenter usage type: ";
                        cin >>usage_type;
                        if(usage_type == 1){
                            cout << "enter water usage (L): ";
                            cin >> usage;
                            client_list[i].setWaterUsage(usage);
                            cout<<"water usage changed."<<endl;
                            writeFile(clientsFile, client_list);
                        }
                        else if(usage_type == 2){
                            cout << "enter electricity usage (KW): ";
                            cin >> usage;
                            client_list[i].setElectricityUsage(usage);
                            cout<<"electricity usage changed."<<endl;
                            writeFile(clientsFile, client_list);
                        }
                        else{
                            cout<<"wrong input"<<endl;
                        }
                    }while(usage_type != 1 && usage_type != 2);
                }
            }
            if(!isFound){
                cout<<endl<<"Client not found."<<endl;
            }
        

        //show client bills
        } else if (choice == 5) {
            int client_ID;
            bool isFound = false;


            cout <<endl<< "enter client ID: ";
            cin >> client_ID;

            //we check if the client is in the vector
            for(int i=0; i<client_list.size(); i++){
                if(client_list[i].getID() == client_ID){
                    isFound = true;

                    //we calculate the bills according to the usage type and price multipliers
                    cout<<endl<<endl<<"---------------BILLS---------------\n"<<endl;
                    cout << "Water bill (L): " << client_list[i].getWaterUsage() * (client_list[i].getUsage_type() == "industry" ? w_industry : client_list[i].getUsage_type() == "farming" ? w_farming : w_home) << endl;
                    cout << "Electricity bill (KW): " << client_list[i].getElectricityUsage() * (client_list[i].getUsage_type() == "industry" ? e_industry : client_list[i].getUsage_type() == "farming" ? e_farming : e_home) << endl;
                }
            }
            if(!isFound){
                cout<<endl<<"Client not found."<<endl;
            }

        //change price multiplier
        } else if (choice == 6) {   
            int choice;
            do{
                cout <<endl<<endl<<"1. Water price multiplier"<<endl<<"2. Electricity price multiplier"<<endl<<endl<<"choose: ";
                cin>>choice;
                if(choice != 1 && choice != 2){
                    cout<<"wrong input"<<endl;
                }
            }while(choice != 1 && choice != 2);
            if (choice == 1) {
                changeWaterPrice(w_industry, w_farming, w_home);
            } else if (choice == 2) {
                changeElectricityPrice(e_industry, e_farming, e_home);
            }
        } else if (choice == 0) {
            cout << "Exiting the program.\n";

        }
    }
}