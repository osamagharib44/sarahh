//
// Created by Osama  Mohammed on 4/16/2022.
//

#include "User.h"
#include<bits/stdc++.h>

using namespace std;
User::User() {
}
User::User(string User, string Pass, int id) {
    this->Username = User;
    this->Password = Pass;
    this->ID = id;
}

string User::GetPassword() {
    return this->Password;
}

string User::GetUsername() {
    return this->Username;
}

void User::ReadDataFromFile(ifstream &data){
    int s;
    int idx;
    string ms,t;

    //read contacts
    data >> s;
    while (s--){
        int cont;
        data >> cont;
        this->Contacts.push_back(cont);
    }
    data.ignore();

    //read fav messages
    data >> s;
    data.ignore();
    while (s--){
        getline(data,ms);
        getline(data,t);
        this->FavMsgs.push(Message(ms,t));
    }

    //read all received messages
    data >> s;
    data.ignore();
    while (s--){
        data >> idx; data.ignore();
        getline(data,ms);
        getline(data,t);
        this->RecMessages[idx].push_back(Message(ms,t));
    }

    //read all sent messages;
    data >> s;
    data.ignore();
    stack<pair<int,Message>> sta;
    while (s--){
        data >> idx; data.ignore();
        getline(data,ms);
        getline(data,t);
        sta.push({idx,Message(ms,t)});
    }
    while (sta.size()){
        this->SentMessages.push(sta.top());
        sta.pop();
    }
}

void User::SaveDataToFile(ofstream &data) {
    data << endl;
    data << this->GetUsername()<< endl;
    data << this->GetPassword() << endl;

    //contacts
    data << this->Contacts.size();
    for (auto c : this->Contacts){
        data << ' ' << c;
    }
    data << endl;

    //fav messages
    data << this->FavMsgs.size() << endl;
    while (this->FavMsgs.size()){
        data << this->FavMsgs.front().GetContent() << endl;
        data << this->FavMsgs.front().GetTime() << endl;
        this->FavMsgs.pop();
    }

    //rec messages
    vector<pair<int,Message>> vec;
    for (int i = 1; i<101;i++){
        for (auto m : this->RecMessages[i]){
            vec.push_back({i,m});
        }
    }
    data<<vec.size()<<endl;
    for (auto m : vec){
        data << m.first << endl;
        data << m.second.GetContent() << endl;
        data << m.second.GetTime() << endl;
    }

    //sent messages
    data<< this->SentMessages.size() << endl;
    while (this->SentMessages.size()){
        data << this->SentMessages.top().first << endl;
        data << this->SentMessages.top().second.GetContent() << endl;
        data << this->SentMessages.top().second.GetTime() << endl;
        this->SentMessages.pop();
    }

}

/*----------------------------*/
void User::addContact(int userID)
{
    for (auto i : Contacts){
        if (i==userID) {
            cout << "Contact you're trying to add already exists!!" << endl;
            return;
        }
    }
    cout <<"Contact Added successfully" << endl;
    Contacts.push_back(userID);
}
void User::displayContacts(int userID, User data[])
{
    User user = data[userID];

    if (user.Contacts.empty())
        cout << "Contact List is Empty !! " << endl;
    else {
        cout << "---------------------\n";
        cout << "You have " << user.Contacts.size() << " Contacts." << endl;
        for (int i = 0; i < user.Contacts.size(); i++)
        {
            cout <<data[user.Contacts.at(i)].GetUsername() << endl;
        }
    }
}
void User::searchForContact(string name, User data[]) {
    transform(name.begin(), name.end(), name.begin(),::tolower);
    User user;
    bool bad = true;

    string pattern = "(.)*";
    for (auto c : name) {
        pattern.push_back('[');
        pattern.push_back(c);
        pattern.push_back(']');
    }//(.)*[s](.)*
    int userID;
    pattern += "(.)*";
    regex e(pattern);

    for (int i = 0; i < this->Contacts.size(); i++)
    {
        userID = this->Contacts.at(i);
        user = data[userID];
        bool match = regex_match(user.GetUsername(), e);
        if (match)
        {
            cout << "---------------------\n";
            cout <<"Contact name : "<< user.GetUsername() << endl;
            bad = false;
        }
    }
    if (bad) {
        cout << "Contact not Found!!" << endl;
    }
   cout << endl;
}

/*----------------------------*/

void User::sendMessage(int Id, const string&txt, User data[]){
    Message msg = Message(txt);
    data[Id].RecMessages[this->ID].push_back(msg);
    this->SentMessages.push({Id, msg});
    cout <<"Message sent." << endl;
}
void User::undoLastMessage(User data[]){
    int Id = this->SentMessages.top().first;
    this->SentMessages.pop();
    data[Id].RecMessages[this->ID].pop_back();
}
void User::getMessagesFrom(int Id){
    cout << RecMessages[Id].size() << " Message(s)" << endl;
    for (auto ms : RecMessages[Id]){
        cout << ms.GetContent() << endl << " Time: " << ms.GetTime() << endl;
    }
    cout << endl;
}
void User::viewSentMessages(User data[]){
    if (this->SentMessages.empty()){
        cout << "You haven't sent any messages yet!" << endl;
    }
    else {
        auto temp = this->SentMessages;
        while (temp.size()){
            auto pa = temp.top();
            cout <<endl << "Sent to: "<<data[pa.first].GetUsername()<<endl;
            auto ms = pa.second;
            cout <<" "<< ms.GetContent() << endl << " Time: " << ms.GetTime() << endl;
            temp.pop();
        }
    }
}
/*----------------------------*/

void User::addRecentMsgToFav(int id)
{
    if (this->RecMessages[id].empty()){
        cout << "You didn't receive any message from that contact!!" << endl;
        return;
    }
    FavMsgs.push(this->RecMessages[id].front());
    cout <<"Message favourited successfully!" << endl;
}
void User::viewAllFavMsgs()
{
    if (this->FavMsgs.empty())
        cout <<"You haven't favourited any message yet." << endl;
    else {
        cout << " Your Favourite messages:" << endl;
        int S = this->FavMsgs.size();
        for (int i = 1; i<=S;i++){
            auto ms = this->FavMsgs.front();
            this->FavMsgs.pop();
            cout <<endl<< " "<< ms.GetContent() << endl << " Time: " << ms.GetTime() << endl;
            this->FavMsgs.push(ms);
        }
    }
}
void User::removeOldestFavMsg()
{
    if (!FavMsgs.empty()) {
        FavMsgs.pop();
        cout <<"Removed oldest favourite message.";
    }
    else {
        cout <<"You haven't favourited any message yet.";
    }
    cout << endl;
}


/*----------------------------*/

User::~User() = default;





