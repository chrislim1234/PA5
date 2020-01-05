#include "page.h"
#include <string>
using std::string;
#include<vector>
using std::vector;
#include <cstdlib>
#include <iostream>
#include<cmath>
using namespace std;

//constructor
Page::Page(int id0, string url0, double rank0, vector<int> link0) 
{
    id = id0;
    url = url0;
    rank = rank0;
    link = link0;
}

//setters
void Page::setID(int newID)
{
       id = newID;
} 

void Page::setURL(string newURL)
{
       url = newURL;
}   


void Page::setRank(double newRank)
{
       rank = newRank;
}   

void Page::setLink(vector<int> newLink)
{
       link = newLink;
}   

//getters
int Page::getID()
{
       return id;
} 

string Page::getURL()
{
       return url;
} 

double Page::getRank()
{
       return rank;
} 

vector<int> Page::getLink()
{
       return link;
} 
