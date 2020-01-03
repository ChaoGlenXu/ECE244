///*
// * To change this license header, choose License Headers in Project Properties.
// * To change this template file, choose Tools | Templates
// * and open the template in the editor.
// */
    #include <iostream>
    #include <string>
    using namespace std;
    #include "TreeDB.h"
//#include "TreeNode.h"

   TreeDB::TreeDB(){
       root = NULL;//not sure if it should create a create node with nothing in it or just null
       probesCount = 0;
   }

   // the destructor, deletes all the entries in the database.
   TreeDB::~TreeDB(){
       clear();
   }

   // inserts the entry pointed to by newEntry into the database. 
   // If an entry with the same key as newEntry's exists 
   // in the database, it returns false. Otherwise, it returns true.
   bool TreeDB::insert(DBentry* newEntry){
       //if(newEntry == NULL){ return } //since bool, then assume not true or false
       if(find(newEntry->getName()) != NULL){
           delete newEntry;
           return false; 
       }
       else{
           probesCount = 0;
           if (root == NULL){
               root = new TreeNode(newEntry);
           return true;
           }
           else{          
               TreeNode* newNode = new TreeNode(newEntry);                   
               insert_bst(newNode , root);
               return true;
           }
           
       }
   }
   //helper function for insert
   void TreeDB::insert_bst(TreeNode* newNode, TreeNode* root ){//, TreeNode* current
       if(newNode->getEntry()->getName() < root->getEntry()->getName()){
           if(root->getLeft() == NULL){
               root->setLeft(newNode);
           }else insert_bst(newNode, root->getLeft());
       }else if(newNode->getEntry()->getName() > root->getEntry()->getName()){
           if(root->getRight() == NULL){
               root->setRight(newNode);
           }else insert_bst(newNode, root->getRight());
       }
   }
   
   // searches the database for an entry with a key equal to name.
   // If the entry is found, a pointer to it is returned.
   // If the entry is not found, the NULL pointer is returned.
   // Also sets probesCount
   DBentry* TreeDB::find(string name){
       
       if( root == NULL ){ return NULL; }
       else{
//           TreeNode* current = root;
//           if(find_bst(name,current) != NULL){
//               probesCount = 0; 
//           return find_bst( name, current)->getEntry();
//           }else{return NULL;}
           TreeNode* local = find_bst(name,root);
           if(local != NULL){
               probesCount = 0;
               return local->getEntry();
           }else{return NULL;}
       }
   }
   
  TreeNode* TreeDB::find_bst( string name, TreeNode* current){
       //TreeNode* current = root;
      probesCount = probesCount +1;
       if((current!= NULL)&&(current->getEntry()!= NULL)&&(name == current->getEntry()->getName())){
           return current;
       }
      else if((current!= NULL)&&(current->getEntry()!= NULL)&&( name < current->getEntry()->getName() )){
           if(current->getLeft() == NULL){
               return NULL;//NULL;
           }else
               return find_bst(name, current->getLeft());
       }else if ((current!= NULL)&&(current->getEntry()!= NULL)&&( name > current->getEntry()->getName() )){
           if(current->getRight() == NULL){
               return NULL;//NULL;
           }else
               return find_bst(name, current->getRight());//always need to remember to add return 
       }
   }
  
   // deletes the entry with the specified name (key)  from the database.
   // If the entry was indeed in the database, it returns true.
   // Returns false otherwise.
   // See section 6 of the lab handout for the *required* removal method.
   // If you do not use that removal method (replace deleted node by
   // maximum node in the left subtree when the deleted node has two children)
   // you will not match exercise's output.
   bool TreeDB::remove(string name){
        if(find(name) == NULL){
             return false;
        }else{
             root = remove_bst(root, name);//root =
             return true;
        }  
   }
    TreeNode* TreeDB::remove_bst(TreeNode*  root, string name){
    if (root->getEntry()->getName() == name){//now found the node needed to be deleted
        //if root has no children
        if((root->getLeft() == NULL)&&(root->getRight()== NULL)){
            delete root;
            root = NULL;
           // return;
            return NULL;
        //if only left child
        }else if((root->getLeft() != NULL)&&(root->getRight()== NULL)){
            TreeNode* temp = root->getLeft();
            delete root;
            root = NULL;
          //  return;
            return temp;
        //if only right child
        }else if((root->getLeft() == NULL)&&(root->getRight()!= NULL)){
            TreeNode* temp = root->getRight();
            delete root;
            root = NULL;
           // return;
            return temp;
        //if root has two children    
        }else if((root->getLeft() != NULL)&&(root->getRight()!= NULL)){
            cout<< root<<endl;
            TreeNode* tempL = root->getLeft();
            TreeNode* tempR = root->getRight();
            //case1 : tempL has not right child
            if(tempL->getRight() == NULL){
                
                root->getEntry()->setName(tempL->getEntry()->getName());
                root->getEntry()->setIPaddress(tempL->getEntry()->getIPaddress());
                root->getEntry()->setActive(tempL->getEntry()->getActive());
                root->setLeft(NULL);
                delete tempL;
                return root;
                cout<<"b"<<endl;
            //case2: tempL has right child
            }else{
                TreeNode* tempL_right_most = tempL;
                TreeNode* before_tempL_right_most = tempL;
                while(tempL_right_most->getRight() != NULL){
                    before_tempL_right_most = tempL_right_most;
                    tempL_right_most == tempL_right_most->getRight();
                }
                tempL_right_most->setRight(tempR);
                tempL_right_most->setLeft(tempL);
                before_tempL_right_most->setRight(NULL);
                delete root;
                return tempL_right_most;            
            }

            

           // root->getEntry()->setName(tempL_right_most->getEntry()->getName());
           // root->getEntry()->setIPaddress(tempL_right_most->getEntry()->getIPaddress());
           // root->getEntry()->setActive(tempL_right_most->getEntry()->getActive());
           // delete tempL_right_most;
          //  before_tempL_right_most->setRight(NULL) ;
           // return;

        }

    }else if(name < root->getEntry()->getName()){
        root->setLeft(remove_bst(root->getLeft(), name));
        cout<<root<<endl;
        return root;//->getLeft();
    }else if(name > root->getEntry()->getName()){
        root->setRight(remove_bst(root->getRight(), name));
        return root;//->getRight();
    }

}
   // deletes all the entries in the database.
   void TreeDB::clear(){
       clear_bst(root);

       root = NULL;  
   }
   void TreeDB::clear_bst(TreeNode* root){
       if (root == NULL) return;
           clear_bst(root->getLeft());
           clear_bst(root->getRight());
           delete root;

   } 
   
   // prints the number of probes stored in probesCount
   void TreeDB::printProbes() const{cout << probesCount <<endl;}
   
   // computes and prints out the total number of active entries
   // in the database (i.e. entries with active==true).
   void TreeDB::countActive () const{
       int count_active = 0;
       if(root == NULL){return;}
         
       else
           countActive_bst(count_active, root);
       cout << count_active <<endl; 
   }
   void TreeDB::countActive_bst(int& count_active, TreeNode* root) const {
        if(root->getLeft()!= NULL){
           countActive_bst(count_active, root->getLeft());
       }
        if(root->getEntry()->getActive() == true){
            count_active = count_active + 1;
        }
        
        if(root->getRight()!= NULL){
           countActive_bst(count_active,root->getRight());
       }
   }
   // Prints the entire tree, in ascending order of key/name
   ostream& operator<< (ostream& out, const TreeDB& rhs){
     return rhs.printAll_helper(out, rhs.root);
   }
   // void TreeDB::cout_helper(TreeNode* root){
   ostream& TreeDB::printAll_helper(ostream& out, TreeNode* p)const{
        if(p->getLeft()!= NULL){
           printAll_helper(out, p->getLeft());
       }
        string activity;
        if(p->getEntry()->getActive() == true){activity = "active";}
        else {activity = "inactive";}
        out<<p->getEntry()->getName()<<" : "<< p->getEntry()->getIPaddress()<<" : "<< activity << endl;
        
        if(p->getRight()!= NULL){
            printAll_helper(out, p->getRight());
       }  
   }
   
   bool TreeDB::get_bool(string activity){
            bool active;
            if(activity == "active"){ active = true;}
            else if(activity == "inactive") {active = false;}
             return active;
   }
     
   string TreeDB::get_string(bool acti){
            string active;
            if(acti== true){ active = "active";}
            else if(acti == false) {active = "inactive";}
             return active;
   }
 //  }

// You *may* choose to implement the function below to help print the 
// tree.  You do not have to implement this function if you do not wish to.
ostream& operator<< (ostream& out, TreeNode* rhs){}