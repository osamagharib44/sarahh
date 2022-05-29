//
// Created by Osama  Mohammed on 4/16/2022.
//
#include<bits/stdc++.h>
using namespace std;
#pragma once

class Message {
private:
    string Content;
    string Time;

public:
    Message();
    Message(string tx);
    Message(string tx, string t);

    string GetContent();
    string GetTime();
};