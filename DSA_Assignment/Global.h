/*
* Name: Hervin Sie(S10262115C), Charlotte Lee(s10258027k)
* Group: 6
*/

#pragma once

#include "HashTable.h"
#include "Actor.h"
#include "Movie.h"

extern HashTable<Actor*> actorTable;
extern HashTable<Movie*> movieTable;
template <typename T>
extern HashTable<T>* hashTable;
