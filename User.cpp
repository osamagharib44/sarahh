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


User::~User() {


}




