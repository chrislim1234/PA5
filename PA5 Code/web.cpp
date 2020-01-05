#include "web.h"
#include "page.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib> 
#include "math.h"
using namespace std;
using std::vector;
using std::string;

Web::Web() 
{
    vector<Page>List1;
}

Web::~Web() 
{ 

}

bool Web::read_graph(const char *filename) 
{ /*
     reads in and parse graph from a file.
     @filename: is the name of the file describing the webgraph.
     @return: true in success , and false in failure.
    */
    //open file
    ifstream ifile (filename); 
    
    //check if file can open
        if( ifile.fail() ){ 
            // able to open file?
            cout << "Couldn't open file" << endl;
            return false;
        }
    
        //declare variables
        int id;
        string url;
        double rank;
        string myLine;
        string temp;
        vector<int> Link1;
        stringstream ss;
        ss.clear();
    
        //get numPage and check if its an int
        ifile>>numPage;
        if ( ifile.fail() ){
            cout << "Didn't enter an int";
            return false;
        }
    
        //repeated but also using getline, gets garbage value
        getline(ifile,temp);
        ss<<temp;
        ss>>numPage;
        ss.clear();
        ss.str("");
        temp = "";
    
        //for loop to get the info for each page
        for (int i=0; i<numPage; i++) {
                getline(ifile,temp);
                ss<<temp;
                ss>>id;
                //check if its the right type
                if ( ifile.fail() ){
                cout << "Didn't enter an int";
                return false;
                } 
                //clear temp and clear stringstream when complete
                temp = "";
                ss.clear();
                ss.str("");
  
                getline(ifile,temp);
                ss<<temp;
                ss>>url;
                if ( ifile.fail() ){
                cout << "Didn't enter an string";
                return false;
                 } 
                temp = "";
                ss.clear();
                ss.str("");
            
                getline(ifile,temp);
                ss<<temp;
                ss>>rank;
                if ( ifile.fail() ){
                cout << "Didn't enter a double";
                return false;
                 }  
                temp = "";
                ss.clear();
                ss.str("");
            
                //getlink for each page, which is multiple int on 
                //same line
            
                getline(ifile,myLine);
                ss<<myLine;
                int num;
                while (ss>>num) {
                    Link1.push_back(num);
                }
            ss.clear();
            ss.str("");
            List1.push_back(Page(id, url, rank, Link1));
            Link1.clear();
            

       }
    
   //close file
   ifile.close();
   return true;

}

bool Web::write_graph(const char *filename)
{ 
    //open ofstream to print out in new file
    ofstream ofile(filename);
    
    //check if could be opened 
    if (ofile.fail() ){
            cout << "couldnt open";
            return false;
    }
    
    //print info from pages
    else {
        ofile <<numPage<<"\n";
        vector<int> Link1;
        for (int i=0;i<numPage; i++) {
            ofile <<List1[i].getID()<<"\n";
            ofile<<"\t"<<List1[i].getURL()<<"\n";
            ofile<<"\t"<<List1[i].getRank()<<"\n";
            ofile<<"\t";
            Link1 = List1[i].getLink();
            for (unsigned int i=0; i<(unsigned int)(Link1.size()); i++) {
                ofile<<Link1[i]<<" ";
            }
            ofile<<"\n";
        }
   }   
    
    
        /*
     writes out webgraph to a file.
     @filename: is the name of the file to write to.
     @return: true in success , and false in failure
    */
    
    //close ofile
    ofile.close();
    return true;
}

void Web::calculate_rank(int S,int N)
{
    //declare variables
    int simulationNumber = S;
    int surferNum = N;
    int nodeNum = List1.size();
    int startingWalker = surferNum/nodeNum;
    int remainder = surferNum%nodeNum;
    srand(time(NULL));
    int size=0;
    int ran=0;
    int link;
    int walker;
    vector<int> Link;
    vector<int> Node;
    vector<int> temp;
    double a;
    
    //add startingwalker to all nodes
    for(int i=0; i<nodeNum; i++) {
        Node.push_back(startingWalker);
        temp.push_back(startingWalker);
    }
    
    //add remainder walkers to nodes
   
    for(int i=0; i<remainder; i++) {
        Node[i]=Node[i]+1;
        temp[i]=Node[i]+1;
    }
    
    //for each simulation, for each node, find
    //random link it goes to for each walker at
    //node and change until for loop ends
    
    for (int i=0; i<simulationNumber; i++) {
        for (int j=0; j<nodeNum; j++)       {
                walker = temp[j];
            for (int k=0; k<walker; k++) {
                Link = List1[j].getLink();
                size = Link.size();
                    ran = random()%size;
                    link=Link[ran];
                    Node[link]++;
                    Node[j]--;
                              
            }
            Link.clear();
        }
        temp = Node;
       
    }
    
    //find proportion of walkers on node
    //clamp values
    //change rank for all pages
    
    for (int i=0; i<nodeNum; i++) {
        double x = (double)(Node[i])/surferNum;
        a = fabs(x);
       List1[i].setRank(a); 
    }
    
}
    
    

