#include<bits/stdc++.h>
#include<fstream>
#include "User.h"
#include "Message.h"
using namespace std;

int curid = 0;
int amount = 0;
string name,pass;
User users[100];
map<string, int> MapNameToId;
bool EndProgram = false;

void print(const string& x){
    cout << x << endl;
}

int getinput(int mx){
    int in;
    while (true){
        cout <<"Enter input:";
        cin >> in;
        cin.ignore();
        if (!mx){
            return in;
        }
        if (in<1 || in>mx){
            print("Invalid input!!");
        }
        else {
            return in;
        }
    }
}

void printseparator(){
    print("----------------------------");
}

int CheckName(string str){
    transform(str.begin(), str.end(), str.begin(),::tolower);
    return MapNameToId[str];
}

bool ValidPass(string &Pass){
    regex Upper_Case{"[A-Z]+"};
    regex Lower_Case{"[a-z]+"};
    regex Number{"[0-9]+"};
    regex Special_Char{"[!@#$%^&*()=+]+"};

    int upperCase = regex_search(Pass, Upper_Case);
    int lowerCase = regex_search(Pass, Lower_Case);
    int number = regex_search(Pass, Number);
    int specialChar = regex_search(Pass, Special_Char);

    if (Pass.length()<8){
        return false;
    }
    if (upperCase&lowerCase&specialChar&number){
        return true;
    }
    return false;
}

bool Validator(string str){
    for (auto c : str){
        if (c<33 || c>126 || isspace(c)) {
            return false;
        }
    }
    return true;
}

void DoLoginRegister(){

    switch (getinput(2)) {
        case 1:
            while (true){
                printseparator();
                print("Enter your username:");
                getline(cin,name);
                bool valid = Validator(name);
                if (!valid){
                    print("Username must contain only letters, numbers and special characters.");
                    continue;
                }
                transform(name.begin(), name.end(), name.begin(),::tolower);
                bool taken = CheckName(name);
                if (taken){
                    print("Username is taken.");
                    continue;
                }
                break;
            }
            while (true){
                print("Enter your Password:");
                cin >> pass;
                bool good = ValidPass(pass);
                if (good){
                    break;
                }
                else {
                    print("Password must be atleast 8 characters, and must contain uppercase letters, lowercase letters and numbers.");
                }
            }

            amount++;
            curid = amount;
            users[curid] = User(name,pass,curid);
            MapNameToId[name] = curid;
            break;
        case 2:
            while (true){
                printseparator();
                print("Enter your username:");
                getline(cin,name);
                bool valid = Validator(name);
                if (!valid){
                    print("Username must contain only letters, numbers and special characters.");
                    continue;
                }
                transform(name.begin(), name.end(), name.begin(),::tolower);
                bool taken = CheckName(name);
                if (!taken){
                    print("Account doesn't exist.");
                }
                else{
                    curid = CheckName(name);
                    print("Enter your password:");
                    getline(cin,pass);
                    if (users[curid].GetPassword()==pass){
                        break;
                    }
                    else {
                        print("Wrong password");
                    }
                }
            }
            break;
    }
}

void GetDataFromFile(){
    ifstream data("data.txt");
    string line;
    string user;
    string pass;
    int id = 0;
    while (getline(data,line)){
        //read user and pass
        id++;
        amount++;
        getline(data,user);
        getline(data,pass);
        users[id] = User(user, pass, id);
        MapNameToId[user] = id;

        //read rest of data
        users[id].ReadDataFromFile(data);
    }
    data.close();

}

void SaveDataToFile(){
    ofstream data;
    data.open("data.txt", ofstream::out | ofstream::trunc);
    for (int i = 1; i<=amount;i++){
       users[i].SaveDataToFile(data);
    }
    data.close();
}

int GetTargetId(){
    string targname;
    int targid;
    while (true){
        cout << "Contact's name:";
        cin >> targname;
        transform(targname.begin(), targname.end(), targname.begin(),::tolower);
        targid = MapNameToId[targname];
        if (targid<1 || targid>amount || targid==curid){
            print("Invalid Username");
        }
        else {
            break;
        }
    }
    return targid;
}

void DoOperations(){
    printseparator();
    int in = getinput(11);

    string x;
    int targid;
    switch (in) {
        case 1:
            users[curid].addContact(GetTargetId());
            break;
        case 2:
            print("Username to search for");
            getline(cin,x);
            users[curid].searchForContact(x, users);
            break;
        case 3:
            User::displayContacts(curid, users);
            break;
        case 4:
            targid = GetTargetId();
            cout <<"Enter message:" << endl;
            getline(cin,x);getline(cin,x);
            users[curid].sendMessage(targid, x, users);
            break;
        case 5:
            users[curid].undoLastMessage(users);
            print("Last sent message deleted");
            break;
        case 6:
            users[curid].viewSentMessages(users);
            break;
        case 7:
            targid = GetTargetId();
            users[curid].getMessagesFrom(targid);
            break;
        case 8:
            targid = GetTargetId();
            users[curid].addRecentMsgToFav(targid);
            break;
        case 9:
            users[curid].viewAllFavMsgs();
            break;
        case 10:
            users[curid].removeOldestFavMsg();
            break;
        case 11:
            EndProgram = true;
            break;
    }
    printseparator();
    if (!EndProgram) {
        print("Enter any key to continue.");
        getinput(0);
        printseparator();
    }
}

int main(){
    MapNameToId["test"] = 3;
    GetDataFromFile();
    print("Welcome to curious!"); printseparator();
    print("1 - Register");
    print("2 - Login"); printseparator();
    string name;
    string pass;

    /*----------------------------*/

    DoLoginRegister();
    printseparator();
    cout << "Welcome back, "<<users[curid].GetUsername()<<"!" << endl;
    printseparator();
    /*----------------------------*/

    while (!EndProgram) {
        print("1 - Add a contact");
        print("2 - Search for a contact");
        print("3 - Display all your contacts");
        print("4 - Send a message");
        print("5 - Undo last sent message");
        print("6 - View all sent messages");
        print("7 - View all messages from a specific contact");
        print("8 - Favourite last received message from specific contact");
        print("9 - Display all favourite messages");
        print("10 - Remove oldest favourite message");
        print("11 - Logout");

        DoOperations();
    }
    cout <<"Goodbye, "<< users[curid].GetUsername() <<"!"<<endl;
    SaveDataToFile();
}