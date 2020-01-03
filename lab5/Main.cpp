/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: xuchao9
 *
 * Created on November 23, 2019, 8:09 PM
 */

#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>


#include "DBentry.h"
#include "TreeNode.h"
#include "TreeDB.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    
    TreeDB tree;
    
   
    
    while(!cin.eof()){
            string line;
    string command;
    string name;
    int address;
    string activity;
    
    cout << "> ";
    getline(cin, line);
    
        stringstream lineStream (line);
        lineStream >> command;
        if(command == "insert"){
            lineStream >> name;
            lineStream >> address;
            lineStream >> activity;
            if(tree.find(name) != NULL){cout<<"Error: entry already exists"<<endl;}
            else{
                DBentry* new_entry = new DBentry(name, address, tree.get_bool(activity));
                tree.insert(new_entry);
                cout<<"Success"<<endl;
            }
        }else if(command == "find"){
            lineStream >> name;
            if(tree.find(name) == NULL){cout<< "Error: entry does not exist"<<endl;}
            else{cout<< tree.find(name)->getName() <<" : "<<tree.find(name)->getIPaddress()<<" : "<<tree.get_string(tree.find(name)->getActive())<<endl;}
        }else if(command == "updatestatus"){
            lineStream >> name;
            lineStream >> activity;
            if(tree.find(name) != NULL){
                tree.find(name)->setActive(tree.get_bool(activity));
                cout<<"Success"<<endl;
            }else{
                cout<<"Error: entry does not exist"<<endl;
            }
                
        }else if(command == "printall"){
            cout << tree;// or operator<<(cout, tree)
        }else if(command == "printprobes"){
            lineStream >> name;
            if(tree.find(name)== NULL){cout<< "Error: entry does not exist" <<endl;}
            else{tree.printProbes();}
            
        }else if(command == "remove"){
            lineStream >> name;
            if(tree.remove(name) == true){
                cout<< "Success"<<endl;
            }else
                cout<<"Error: entry does not exist"<<endl;
        }else if(command == "countactive"){
            tree.countActive();
        }else if(command == "removeall"){
            tree.clear();
            cout<< "Success"<<endl;
        }

    }
    return 0;
}
