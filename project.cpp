#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

    class clients{
        public:
            void addClient(string name_val, int ID_val){
                name = name_val;
                ID = ID_val;
            }

            string getName() const {
                return name;
            }

            int getID() const {
                return ID;
            }

        private:
            string name;
            int ID;
    };

    vector<clients> client_list;

    void file_management(){
        ofstream file("clients.txt");

        if(!file.is_open()){
            cerr<<"File could not be opened."<<endl;
            return;
        }

        for(int i=0; i<client_list.size(); i++){
            file<<client_list[i].getName()<<endl;
            file<<client_list[i].getID()<<endl;
        }
        file.close();

    }


int main(){
    string new_name;
    int new_ID, choice=1;
    while(choice==1){
        cout<<"enter new client name: ";
        cin>>new_name;
        cout<<"enter new client ID: ";
        cin>>new_ID;
        clients new_client;
        new_client.addClient(new_name, new_ID);
        client_list.push_back(new_client);
                for(int i=0; i<client_list.size(); i++){
                cout<<client_list[i].getName()<<" "<<client_list[i].getID()<<endl;
            }
        cout<<"enter 1 to add new client, 0 to exit: ";
        cin>>choice;
    }
}