/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

    #include <iostream>
    #include <string>
    using namespace std;
    #include "DBentry.h"
	// the default constructor
	DBentry::DBentry(){
        }
        DBentry::DBentry (string _name, unsigned int _IPaddress, bool _active){
            name = _name;
            IPaddress = _IPaddress;
            active = _active;
        }
	// the destructor
 	DBentry::~DBentry(){
            ;
        }	

	// sets the domain name, which we will use as a key.
	void DBentry::setName(string _name){
            name = _name;
        }

	// sets the IPaddress data.
	void DBentry::setIPaddress(unsigned int _IPaddress){
            IPaddress = _IPaddress;
        }
    
        // sets whether or not this entry is active.
        void DBentry::setActive (bool _active){
            active = _active;
        }

        // returns the name.
	string DBentry::getName() const{
            return name;
        }

	// returns the IPaddress data.
	unsigned int DBentry::getIPaddress() const{
            return IPaddress;
        }

        // returns whether or not this entry is active.
        bool DBentry::getActive() const{
            return active;
        }

	// prints the entry in the format 
        // name : IPaddress : active  followed by newline
        // active is printed as a string (active or inactive)
         ostream& operator<< (ostream& out, const DBentry& rhs){
             string active;
             if (rhs.active) active = "active";
             else active = "inactive";
            cout<< rhs.name << " : " << rhs.IPaddress << " : " << active  << endl ;
        }