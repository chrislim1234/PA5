#ifndef PAGE_H
#define PAGE_H
#include <string>
using std::string;
#include<vector>
using std::vector;
class Page { 
public:
  Page(int id0, string url0, double rank0, vector<int> link0);
  //setters and getters
  int getID();
  void setID(int);
  string getURL();
  void setURL(string);
  double getRank();
  void setRank(double);
  vector<int> getLink();
  void setLink(vector<int>);
private:
  //Data members: id, url, pagerank, links , .. etc
    int id;
    string url;
    double rank;
    vector<int> link;
};  
#endif

//(a) An integer to represent the pageid. 
// (b) A string to represent the page URL.
//(c) An array or vector to model the outbound links of the page. 
//(d) Methods to access and modify internal data.