#include <galaxy-explorer/AsteroidList.hpp>


AsteroidListItem::AsteroidListItem() {
	this->next = nullptr;
	this->data = nullptr;
}

AsteroidListItem::AsteroidListItem(Asteroid a) {
    this->next = nullptr; 
    this->data = new Asteroid(a.getID(),a.getMass(),a.getHealth(),
            a.getCurrentHitbox(),a.getVelocity());
}

AsteroidListItem::~AsteroidListItem() {
}

AsteroidList::AsteroidList(){
    head.setNext(nullptr);
}

AsteroidList::AsteroidList(const AsteroidList& src){
    this->clear();  
    insertAfter(&head, src );//a copy of src right after head
}

AsteroidList::~AsteroidList() {
    this->clear();  
}
//Add an asteroid at the beginning of this list
void AsteroidList::pushFront(Asteroid e) {
    AsteroidListItem* tempE =new AsteroidListItem(e);
    tempE->setNext(head.getNext());
    head.setNext(tempE);
}
// Return a reference to the first asteroid
//This function may have ANY BEHAVIOUR if this list is empty
Asteroid& AsteroidList::front() {
    if(head.getNext() == nullptr){return *(Asteroid*)nullptr;}//casting nullptr
    return (head.getNext())->getData();
}

const Asteroid& AsteroidList::front() const {

    if(head.getNext() == nullptr){return *(Asteroid*)nullptr;}
    return (head.getNext())->getData();// i used const getdata here
}
//Are there no entities in this list?
bool AsteroidList::isEmpty() const {
    if(head.getNext() == nullptr){ return true; }
    else{ return false; }
}
//* The number of entities in this list
int AsteroidList::size() const {
    int count = 0;
    const AsteroidListItem* track = head.getNext();

    while(track != nullptr){
         count++;
         track = track->getNext();
    }
    return count;
}
//Return an item corresponding to the position immediately before the first asteroid.
//If this list is empty, a value equal to `beforeEnd()` must be returned.
//If this list is in a valid state, this function must always succeed.
AsteroidListItem* AsteroidList::beforeBegin() {
    AsteroidListItem* temp = &head;
   if (head.getNext() == nullptr){return beforeEnd();}
   else
       return temp;
}

const AsteroidListItem* AsteroidList::beforeBegin() const {
    const AsteroidListItem* temp = &head;
   if (head.getNext() == nullptr){return beforeEnd();}
   else
       return temp;
}
// Return an item corresponding to the first asteroid.
// If this list is empty, a value equal to `end()` must be returned.
// If this list is in a valid state, this function must always succeed.
AsteroidListItem* AsteroidList::begin() {
    if(head.getNext() == nullptr){return end();}
    else return head.getNext();
}

const AsteroidListItem* AsteroidList::begin() const {
    if(head.getNext() == nullptr){return end();}
    else return head.getNext();
}
// Return an item corresponding to the position of the last asteroid.
//If this list is empty, a value equal to `beforeBegin()` must be returned.
//If this list is in a valid state, this function must always succeed.
AsteroidListItem* AsteroidList::beforeEnd() {
    if(head.getNext() == nullptr){return beforeBegin();}
    else{
        AsteroidListItem* temp = head.getNext();
        while(temp->getNext() != nullptr){temp = temp->getNext();}
        return temp;
    }
}

const AsteroidListItem* AsteroidList::beforeEnd() const {
    if(head.getNext() == nullptr){return beforeBegin();}
    else{
        const AsteroidListItem* temp = head.getNext();
        while(temp->getNext() != nullptr){temp = temp->getNext();}
        return temp;
    }
}
// Return an item corresponding to the position immediately after the last asteroid.
//If this list is empty, a value equal to `begin()` must be returned.
//If this list is in a valid state, this function must always succeed.
AsteroidListItem* AsteroidList::end() {
    if(head.getNext() == nullptr){return nullptr;}
    else{
        AsteroidListItem* temp = head.getNext();
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        return temp->getNext();
    }
}

const AsteroidListItem* AsteroidList::end() const {
    if(head.getNext() == nullptr){return nullptr;}
    else{
        const AsteroidListItem* temp = head.getNext();
        while(temp->getNext() != nullptr){
            temp = temp->getNext();
        }
        return temp->getNext();
    }
}
//Add a single asteroid to this list, in the position immediately after `prev`.
//returns the item that was inserted
AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, Asteroid e) {
    AsteroidListItem* addNew = new AsteroidListItem( e );
    addNew->setNext(prev->getNext());
    prev->setNext(addNew);
    return addNew;
}
//Add independent copies of the entities in `others` to this list, placed immediately after `insertion_point`,
//in the same order as `others`.
//Returns the last item that was inserted, or `insertion_point' if `others' is empty.
AsteroidListItem* AsteroidList::insertAfter(AsteroidListItem* prev, const AsteroidList& others) {
    if(others.head.getNext() == nullptr){return prev;}
    else{
        const AsteroidListItem* current = others.head.getNext(); 
        AsteroidListItem* copy = new AsteroidListItem((current->getData()));
        AsteroidListItem* headCopy = copy;
        while((current != nullptr)&&(current->getNext() != nullptr)){        
                AsteroidListItem* temp = new AsteroidListItem((current->getNext()->getData()));
                copy->setNext(temp);
                copy = copy->getNext();
                current = current->getNext();
        }//now copy is the last asteroidListItem
        copy->setNext(prev->getNext());
        prev->setNext(headCopy);
        return copy;
    }
}
//Given a position in this list, delete the following asteroid.
//Returns the list item that followed the erased item, or end() if there wasn't one.
//This function may have ANY BEHAVIOUR if there is no asteroid after `prev`.
AsteroidListItem* AsteroidList::eraseAfter(AsteroidListItem* prev) {
    AsteroidListItem* needDeleted = prev->getNext();
    prev->setNext(needDeleted->getNext());
    delete &(needDeleted->getData());
    delete needDeleted;
    if(prev->getNext() == nullptr){return end();}
    else return prev->getNext();
}
//Make this list empty, free all nodes.
void AsteroidList::clear() {
    AsteroidListItem* current = head.getNext();
    AsteroidListItem* deleteNode = current;
    while(current != nullptr){
        current = current->getNext();
        delete deleteNode; 
        deleteNode = current;     
    }
    head.setNext(nullptr);//after delete the node, the pointer become dangling
    //that's why we need to set head point to null explicitly
}
//Makes this list an independent copy of `src`.Means that there is NO shared data or pointers
AsteroidList& AsteroidList::operator=(const AsteroidList& src) {
    this->clear();    
    insertAfter(&head, src );
    return *this;
}
