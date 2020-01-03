//
//  main.cpp skeleton
//  lab3
//
//  Created by Tarek Abdelrahman on 2018-08-25.
//  Copyright © 2018 Tarek Abdelrahman. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#include "globals.h"
#include "shape.h"

bool checkPositivity(int a);
bool checkAngle(int angle);

// This is the shape array, to be dynamically allocated
shape** shapesArray;

// The number of shapes in the database, to be incremented 
// everytime a shape is successfully created
int shapeCount = 0;

// The value of the argument to the maxShapes command
int max_shapes;

// ECE244 Student: you may want to add the prototype of
// helper functions you write here

int main() {

    string line;
    string command;
    
    cout << "> ";         // Prompt for input
    getline(cin, line);   // Get a line from standard input
       
    while (!cin.eof()) {
        // Put the line in a linestream for parsing
        // Making a new sstream for each line so the flags are cleared
        stringstream lineStream (line);

        // Read from string stream into the command
        // The only way this can fail is if the eof is encountered
        lineStream >> command;

        // Check for the command and act accordingly
        // ECE244 Student: Insert your code here

        if(command == "maxShapes"){
            //max_shapes = 0;
            if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;} 
            else{          
                lineStream >> max_shapes;
                if(lineStream.fail()){cout << "Error: invalid argument" << endl;
                   lineStream.clear();    
                }
                else{            
                    if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}        
                    else{                
                        shapesArray = new shape*[max_shapes]; 
                        for(int i = 0 ; i < max_shapes ;i++ ){shapesArray[i] = NULL;} 
                        cout << "New database: max shapes is " << max_shapes << endl;
                    }
                }
            }
  

        }else if(command == "create"){
            
            //if(lineStream.eof()){cout<< "too few argument" <<endl; cout<<"kk"<<endl;}
            string input_name;
            
            //lineStream >> input_name;
            if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
            else{  
//                for(int i = 0; i < max_shapes ; i++){    
//                    if(shapesArray[i] != NULL){
//                                if(input_name == shapesArray[i]->getName()){
//                                    // not working
//                                   cout << "shape name exists" <<endl; 
//                                   break;
//                                }   
//                            }
//                        }
                //string input_name;
                lineStream >> input_name;
                if(lineStream.fail()){cout << "Error: invalid argument" << endl; lineStream.clear(); }
                else{            
                    if((input_name == "maxShapes")||(input_name == "create")||(input_name == "move")||(input_name == "rotate")||(input_name == "draw")||(input_name == "delete")){
                    cout << "Error: invalid shape name" <<endl; // not workng
                    }else{               
                        for(int i = 0; i < max_shapes ; i++){    
                            if(shapesArray[i] != NULL){
                                if(input_name == shapesArray[i]->getName()){
                                    // not working
                                   cout << "shape name exists" <<endl; 
                                   break;
                                }   
                            }
                        }
                        
                       
                            
                        if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
                        else{                    
                            string input_type;
                            lineStream >> input_type;
                            if(lineStream.fail()){cout << "Error: invalid argument" << endl; lineStream.clear(); lineStream.ignore();}
                            else{                
                                if(!((input_type == "ellipse") || (input_type == "rectangle") || (input_type == "triangle"))){// think about this afterwards, for now move on
                                    cout << "Error: invalid shape type"<< endl; 
                                }else{
                                    
                                    
                                    if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;} 
                                    else{                            
                                        int input_xLoc;
                                        lineStream >> input_xLoc;
                                        if(lineStream.fail()){cout << "Error: invalid argument" << endl;  lineStream.clear(); lineStream.ignore();}// could be a potential misdate
                                        else{ 
                                            if(checkPositivity(input_xLoc)){                                
                                                
                                                
                                                if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;lineStream.clear();} 
                                                else{                                    
                                                    int input_yLoc;
                                                    lineStream >> input_yLoc;
                                                    if(lineStream.fail()){ cout << "Error: invalid argument" << endl;   lineStream.clear(); lineStream.ignore();}
                                                    else{
                                                        if(checkPositivity(input_yLoc)){                                    
                                                            
                                                            
                                                            if(lineStream.eof()){
                                                                cout<< "Error: too few arguments" <<endl;lineStream.clear();
                                                            } 
                                                            else{                                            
                                                                int input_xSize;
                                                                lineStream >> input_xSize;
                                                                if(lineStream.fail()){ cout << "Error: invalid argument" << endl;  lineStream.clear();lineStream.ignore(); } 
                                                                else{
                                                                    if(checkPositivity(input_xSize)){                                        
                                                                        
                                                                        
                                                                        if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;} 
                                                                        else{                                                    
                                                                            int input_ySize;
                                                                            lineStream >> input_ySize;
                                                                            if(lineStream.fail()){ cout << "Error: invalid argument" << endl;  lineStream.clear(); lineStream.ignore();}
                                                                            else { 
                                                                                if(checkPositivity(input_ySize)){                                            
                                                                                    if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}
                                                                                    else{                                                            
                                                                                        for(int i = 0 ; i < max_shapes ; i++){//assign the name to the object              
                                                                                            if(shapesArray[i] == NULL){//ha ha ha, it helps filling as well!! for delete and insert part, after delete, set to null, then create will form here                   
                                                                                                shapesArray[i] = new shape(input_name, input_type, input_xLoc,
                                                                                                input_yLoc, input_xSize, input_ySize);
                                                                                                cout << "Created " << shapesArray[i]->getName() << ": " << 
                                                                                                shapesArray[i]->getType() << " " << 
                                                                                                shapesArray[i]->getXlocation() << 
                                                                                                " "<< shapesArray[i]->getYlocation() <<
                                                                                                " " <<shapesArray[i]->getXsize() <<
                                                                                                " "<<shapesArray[i]->getYsize()<<endl;
                                                                                                break;
                                                                                            }
                                                                                        }
                                                                                        //cout<< "Error: shape array is full" <<endl;
                                                                                    }       

                                                                                }else{cout << "Error: invalid value" <<endl;}
                                                                            }
                                                                        }
                                                                    }else{cout << "Error: invalid value" <<endl;}                                      
                                                                }
                                                            }

                                                        }else{cout << "Error: invalid value" <<endl;}
                                                    }
                                                }

                                            }else{cout << "Error: invalid value" <<endl;}
                                        }
                                    }

                                }
                            }// copy to here
                        }

                    } //for if else(error checking)  
                }  
            }

        }else if(command == "move"){
            string name;
            int xLoc;
            int yLoc;
            if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
            else{            
                lineStream >> name;
                if(lineStream.fail()){cout << "Error: invalid argument" << endl;}
                else{
                    bool notFound = true;
                    for(int i = 0 ; i < max_shapes ; i++){
                        if(shapesArray[i] != NULL){
                            if(shapesArray[i]->getName() == name){
                                notFound = false;
                            }
                        }
                    }
                    if(notFound == true){cout<<"Error: shape "<< name <<" not found"<<endl;}
                    
                    
                    else if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
                    else{ 
                        lineStream >> xLoc;
                        if(lineStream.fail()){cout << "Error: invalid argument" << endl;}
                        else{            
                             if(checkPositivity(xLoc)){                    

                                 if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
                                 else{                        
                                    lineStream >> yLoc;
                                    if(lineStream.fail()){cout << "Error: invalid argument" << endl;} 
                                    else{            
                                        if(checkPositivity(yLoc)){                        
                                            if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}
                                            else{                                
                                                bool notFound = true;
                                                for(int i = 0 ; i < max_shapes ; i++){
                                                    if(shapesArray[i] != NULL){
                                                        if(shapesArray[i]->getName() == name){
                                                            shapesArray[i]->setXlocation(xLoc);
                                                            shapesArray[i]->setYlocation(yLoc);
                                                            cout <<"Moved "<< shapesArray[i]->getName() <<" to "<< 
                                                            shapesArray[i]->getXlocation()<<
                                                            " "<< shapesArray[i]->getYlocation() << endl;
                                                            notFound = false;
                                                        }
                                                    }
                                                }
                                                if(notFound == true){cout<<"Error: shape name not found"<<endl;}
                                            }

                                        }else{cout << "Error: invalid value" <<endl;}
                                    }
                                 }

                             }else{cout << "Error: invalid value" <<endl;}

                        }
                    }

                }
            }

                           

        }else if(command == "rotate"){
            string name;
            int angle;
            //lineStream >> name;
            if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
            else{            
                lineStream >> name;
                if(lineStream.fail()){cout << "Error: invalid argument" << endl;}   
                else{            
                    
                    if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
                    else{                
                        lineStream >> angle;
                        if(lineStream.fail()){cout << "Error: invalid argument" << endl;}
                        else{            
                            if(checkAngle(angle)){                    
                                if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}
                                else{                        
                                    bool notfound_for_rotate = true;
                                    for(int i = 0 ; i < max_shapes ; i++){
                                        if(shapesArray[i] != NULL){
                                            if(shapesArray[i]->getName() == name){
                                                shapesArray[i]->setRotate(angle);
                                                cout <<"Rotated "<< shapesArray[i]->getName() <<" by "<<
                                                        angle << " degrees"<< endl; //we can't get angle
                                                notfound_for_rotate = false;
                                            }//break;
                                        }
                                    } 
                                    if(notfound_for_rotate == true){ cout<< "Error: shape name not found"<<endl;}
                                }

                            }else{cout << "Error: invalid value" <<endl;}

                        }
                    }

                }
            }


               

        }else if(command == "draw"){
            string name;
            
            if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
            else{            
                lineStream >> name;
                if(lineStream.fail()){cout << "Error: invalid argument" << endl;}
                else{
//                    bool notFound = true;
//                    for(int i = 0 ; i < max_shapes ; i++){
//                        if(shapesArray[i] != NULL){
//                            if(shapesArray[i]->getName() == name){
//                                notFound = false;
//                            }
//                        }
//                    }
//                    if(notFound == true){cout<<"Error: shape "<< name <<" not found"<<endl;}
//                    else{} 
                    if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}
                    else{                
                        if(name == "all"){      
                        cout << "Drew all shapes" <<endl;
                            for(int i = 0 ; i < max_shapes ; i++){
                              if(shapesArray[i] != NULL){
                                    shapesArray[i]->draw();
                               }
                            }

                        }else{//draw shape with name
                            bool notFound = true;
                            for(int i = 0 ; i < max_shapes ; i++){
                              if(shapesArray[i] != NULL){
                                   if(shapesArray[i]->getName() == name){
                                       cout << "Drew " << name << endl;
                                       shapesArray[i]->draw();  
                                       notFound = false;
                                   }
                               }
                            }
                            if(notFound == true){
                                cout<< "Error: shape "<<name<<" not found"<<endl;
                            }                  
                        } 
                    }

                }
            }

               
          
        }else if(command == "delete"){
            string name;
            
            if(lineStream.eof()){cout<< "Error: too few arguments" <<endl;}
            else{            
                lineStream >> name;
                if(lineStream.fail()){cout << "Error: invalid argument" << endl;}
                else{            
                    if(lineStream.peek() != EOF){cout << "Error: too many arguments"<<endl;}
                    else{                
                        if(name == "all"){
                        for(int i = 0 ; i < max_shapes ; i++){
                          if(shapesArray[i] != NULL){
                                delete shapesArray[i];
                                shapesArray[i] = NULL;                       
                           }
                        } 
                        cout << "Deleted: all shapes" <<endl;
                        }else{//delete shape with name
                            bool notFound = true;
                            for(int i = 0 ; i < max_shapes ; i++){
                              if(shapesArray[i] != NULL){
                                   if(shapesArray[i]->getName() == name){ 
                                       delete shapesArray[i];
                                       shapesArray[i] = NULL;
                                       cout<< "Deleted shape " << name <<endl;
                                       notFound = false;
                                   }
                               }
                            }
                            if(notFound == true){cout<< "Error: shape name not found"<<endl;}              
                        }
                    }

                }
            }


            
        }else{
            cout<< "Error: invalid command"<<endl;
        }



        // Once the command has been processed, prompt for the
        // next command
        cout << "> ";          // Prompt for input
        getline(cin, line);   // Get the command line
        
    }  // End input loop until EOF.
    
    return 0;
}

bool checkPositivity(int a){
    if( a >= 0) {
        return true;
    }else {
        
        return false;
    }
}

bool checkAngle(int angle){
    if(( angle >= 0) &&( angle <=360)) {
        return true;
    }else {
        
        return false;
    }
}
//bool checkTooMany(){
//    
//}

//                ///////////////////////////////////////////////////////////////
//                int peeked = lineStream.peek();
//                char hold;
//                while(peeked == 32){
//                    lineStream >> hold;
//                    peeked = lineStream.peek();
//                    if(peeked == -1){
//                        break;
//                    }else if((peeked != 32)&&( peeked != -1)){
//                        cout<< "too many arguments" << endl;
//                    }
//                }///////////////////////////////////////////////////////////////

//|| (lineStream.peek() == ' ')
//                                                                char peeking;
//                                                                peeking = lineStream.peek();
//                                                                while(peeking == ' '){
//                                                                    peeking = lineStream.peek();
//                                                                    if(peeking == EOF)
//                                                                    cout<< "Error: too few arguments" <<endl;lineStream.clear();  
//                                                                    break;
//                                                                }


//|| (lineStream.peek() == ' ')
//                                                                char peeking;
//                                                                peeking = lineStream.peek();
//                                                                while(peeking == ' '){
//                                                                    peeking = lineStream.peek();
//                                                                    if(peeking == EOF)
//                                                                    cout<< "Error: too few arguments" <<endl;lineStream.clear();  
//                                                                    break;
//                                                                }