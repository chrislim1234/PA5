CSCI 103 Programming Assignment 4, Pagerank , Fall 2018

Name: <Your name here>

Email Address: <username>@usc.edu

NOTE: You can delete the questions, we only need your responses.

=============================== Prelab =======================================
Calcuate the pagerank of the pages in the graph you generated.
PR(id=0) = 0
PR(id=1) = 0
PR(id=2) = PR(id=3) + PR(id=0)/2
PR(id=3) = PR(id=1) + PR(id=0)/2 + PR(id=2)
    
PR(id=0)+PR(id=1)+PR(id=2)+PR(id=3)=1

PR(id=0)+PR(id=1)+PR(id=3)+ PR(id=0)/2+PR(id=3)=1
0+0+PR(id=3)+ 0 + PR(id=3) = 1 
    2PR(id=3) =1
    PR(id=3) =0.5
    
PR(id=2) = PR(id=3) + PR(id=0)/2
PR(id=2) = 0.5      + 0 
    PR(id=2) = 0.5   
    
PR(id=0) = 0
PR(id=1) = 0
PR(id=2) = 0.5
PR(id=3) = 0.5
    
