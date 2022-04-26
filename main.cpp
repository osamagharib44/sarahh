#include<bits/stdc++.h>
#include "User.h"
#include "Message.h"
using namespace std;

int curid = 0;
int amount = 0;
User users[100];

void print(const string& x){
    cout << x << endl;
}

int getinput(int mx){
    int in;
    while (true){
        cout <<"Enter input:";
        cin >> in;
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

int main(){

    //for debug
    users[1] = User("osama","ok",1);
    amount++;
    users[2] = User("mr underwear","ok",2);
    amount++;
    users[3] = User("3shmawy elguard elshrs","ok",3);
    users[3].sendMessage(1,"please work", users);
    amount++;
    //

    print("Welcome to curious!"); printseparator();
    print("1 - Register");
    print("2 - Login"); printseparator();
    string name;
    string pass;

    /*----------------------------*/

    switch (getinput(2)) {
        case 1:
            printseparator();
            while (true){
                cout <<"Enter your username:";
                cin >> name;
                bool taken = false;
                for (int i = 1; i<=amount; i++){
                    if (users[i].GetUsername() == name){
                        taken = true;
                    }
                }
                if (taken){
                    print("Username is taken!!");
                }
                else{
                    break;
                }
            }
            cout << "Enter your password:";
            cin >> pass;
            curid = amount + 1;
            users[curid] = User(name,pass,curid);
            break;
        case 2:
            while (true){
                printseparator();
                cout <<"Enter your username:";
                cin >> name;
                bool taken = false;
                for (int i = 1; i<=amount; i++){
                    if (users[i].GetUsername() == name){
                        taken = true;
                        curid = i;
                    }
                }
                if (!taken){
                    print("Account doesn't exist");
                }
                else{
                    cout << "Enter your password:";
                    cin >> pass;
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
    printseparator();
    cout << "Welcome back, "<<users[curid].GetUsername()<<"!" << endl;
    printseparator();
    /*----------------------------*/

    bool endprogram = false;
    while (!endprogram) {
        print("1 - Add a contact");
        print("2 - Search for a contact");
        print("3 - Display all your contacts");
        print("4 - Send a message");
        print("5 - Undo last sent message");
        print("6 - View all messages from a specific contact");
        print("7 - Favourite last received message from specific contact");
        print("8 - Display all favourite messages");
        print("9 - Remove oldest favourite message");
        print("10 - Logout");

        printseparator();
        int in = getinput(10);

        int targid = 0;
        string x;
        string msg;
        switch (in) {
            case 1:
                while (true){
                    cout << "Contact's ID:";
                    cin >> targid;
                    if (targid<1 || targid>amount || targid==curid){
                        print("Invalid ID");
                    }
                    else {
                        break;
                    }
                }
                users[curid].addContact(targid);
                break;
            case 2:
                cout << "Name:";
                cin >> x;
                users[curid].searchForContact(x, users);
                break;
            case 3:
                User::displayContacts(curid, users);
                break;
            case 4:
                while (true){
                    cout << "Contact's ID:";
                    cin >> targid;
                    if (targid<1 || targid>amount || targid==curid){
                        print("Invalid ID");
                    }
                    else {
                        break;
                    }
                }
                cout <<"Enter message:" << endl;
                getline(cin,x);getline(cin,x);
                users[curid].sendMessage(targid, x, users);
                break;
            case 5:
                users[curid].undoLastMessage(users);
                break;
            case 6:
                while (true){
                    cout << "Contact's ID:";
                    cin >> targid;
                    if (targid<1 || targid>amount || targid==curid){
                        print("Invalid ID");
                    }
                    else {
                        break;
                    }
                }
                users[curid].getMessagesFrom(targid);
                break;
            case 7:
                while (true){
                    cout << "Contact's ID:";
                    cin >> targid;
                    if (targid<1 || targid>amount || targid==curid){
                        print("Invalid ID");
                    }
                    else {
                        break;
                    }
                }
                users[curid].addRecentMsgToFav(targid);
                break;
            case 8:
                users[curid].viewAllFavMsgs();
                break;
            case 9:
                users[curid].removeOldestFavMsg();
                break;
            case 10:
                endprogram = true;
                break;
        }
        printseparator();
        if (!endprogram) {
            print("Enter any key to continue.");
            getinput(0);
            printseparator();
        }
    }
    cout <<"Goodbye, "<< users[curid].GetUsername() <<"!"<<endl;
}
