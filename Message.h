//
// Created by Osama  Mohammed on 4/16/2022.
//
#include<bits/stdc++.h>
using namespace std;
#pragma once

class Message {
private:
    string Content;
    int Time;

public:
    Message();
    Message(string tx, int t);

    string GetContent();
    int GetTime();
};