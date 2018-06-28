/********************************
 ** File: driver.cpp
 ** Project: CMSC 202 Project 5, Fall 2017
 ** Author: Enzo Walker
 ** Date: 11/27/2017
 ** Section: 1093, Discussion: 1095
 ** Email: enzow1@umbc.edu
 **
 ** This class is responsible for running the program by calling
 ** main menu. Then the Dynamically Allocated Musc Player is deleted
 ** which frees all blocks in the heap.
 **
 **
 ********************************/
#include <iostream>
#include "MusicPlayer.h"
#include "Song.h"

int main (int argc, char* argv[]) {
  string musicFile;
  cout << "\nWelcome to UMBC Music Player" <<endl;
  if(argc > 1){
    musicFile = argv[1];
  } else{
    cout << "One music files required - try again" << endl;
    cout << "./proj5 p5_music1.txt" << endl << endl;
    return 0;
  }

  MusicPlayer* myMusic = new MusicPlayer(musicFile);
  myMusic->MainMenu();
  delete myMusic;

  return 0;
}
