/*
 * This file was developed for the Fall 2018 instance of ECE244 at the University of Toronto.
 * Creator: Matthew J. P. Walker
 */


#include <galaxy-explorer/AsteroidsObserver.hpp>

//Called whenever a new asteroid appears on the field
void AsteroidsObserver::onAsteroidInRange(Asteroid asteroid) {
    asteroid_list.pushFront(asteroid);
}
 //Called when an asteroid has moved.
 //Use the ID of the asteroid to determine what asteroid to replace
void AsteroidsObserver::onAsteroidUpdate(Asteroid asteroid) {
    AsteroidListItem* current = asteroid_list.begin();
    AsteroidListItem* beforeCurrent = asteroid_list.beforeBegin();
    while(current != asteroid_list.end()){
        if(current->getData().getID() == asteroid.getID()){//current need to be replaced
            asteroid_list.insertAfter(current, asteroid);
            asteroid_list.eraseAfter(beforeCurrent);
            break;
        }else{
            beforeCurrent = current;
            current = current->getNext();
        }
    }
}
//Called when an asteroid leaves the field without being destroyed
void AsteroidsObserver::onAsteroidOutOfRange(Asteroid asteroid) {
    AsteroidListItem* current = asteroid_list.begin();
    AsteroidListItem* beforeCurrent = asteroid_list.beforeBegin();
    while(current != asteroid_list.end()){
        if(current->getData().getID() == asteroid.getID()){//current need to be replaced
            asteroid_list.eraseAfter(beforeCurrent);
            break;
        }else{
            beforeCurrent = current;
            current = current->getNext();
        }
    }
}
// Called when an asteroid is destroyed by a phaser shot
void AsteroidsObserver::onAsteroidDestroy(Asteroid asteroid) {
    AsteroidListItem* current = asteroid_list.begin();
    AsteroidListItem* beforeCurrent = asteroid_list.beforeBegin();
    while(current != asteroid_list.end()){
        if(current->getData().getID() == asteroid.getID()){//current need to be replaced
            asteroid_list.eraseAfter(beforeCurrent);
            break;
        }else{
            beforeCurrent = current;
            current = current->getNext();
        }
    }
}
