/********************************
 ** File: MusicPlayer.cpp
 ** Project: CMSC 202 Project 5, Fall 2017
 ** Author: Enzo Walker
 ** Date: 11/27/2017
 ** Section: 1093, Discussion: 1095
 ** Email: enzow1@umbc.edu
 **
 ** This class is responsible for how the Music Player runs.
 ** The main menu creates options for the user to choose
 ** which then calls the appropriate function such as
 ** "AddSong" or "DisplayPlaylist"
 **
 ********************************/
#include "MusicPlayer.h"
#include <sstream>

//MusicPlayer()
//Default constructor that creates a new MusicPlayer
MusicPlayer::MusicPlayer(){
  
}

//MusicPlayer(string fileName)
//Overloaded Constructor that creates a MusicPlayer through a file
MusicPlayer::MusicPlayer(string fileName){
  LoadCatalog(fileName);
}

//~MusicPlayer
//Destructor to delete a MusicPlayer
MusicPlayer::~MusicPlayer(){
  for(unsigned int i = 0; i < m_songCatalog.size(); i++){
    delete m_songCatalog[i];
    m_songCatalog[i] = NULL;
  }
}

//LoadCatalog(string fileName)
//Loads a list of songs into a Vector from a .txt file
void MusicPlayer::LoadCatalog(string filename){
  int rank,year;
  string songInfo, artist, temp, title;
  ifstream fileStream;
  Song *tempSong;
  stringstream tokenizer;
  vector<string> tokenInfo;

  fileStream.open(filename.c_str());

  //Reads in all songs one by one from a text file and stores them in song objects
  while(getline(fileStream, songInfo)){

    tokenizer << songInfo;
    
    while(getline(tokenizer, temp, ',')){
	tokenInfo.push_back(temp);
    } 
    
    //Extracts the tokens into their respective variables
    rank = atoi(tokenInfo[0].c_str());
    year = atoi(tokenInfo[3].c_str());
    title = tokenInfo[1];
    artist = tokenInfo[2];
    
    //Passes the tokens to a new Song object
    tempSong = new Song(title,artist,year,rank);
    m_songCatalog.push_back(tempSong);

    //Clears for next iteration
    tokenizer.clear();
    tokenInfo.clear();

  }
  fileStream.close();
}

//MainMenu()
//Manages the application's main menu
void MusicPlayer::MainMenu(){
  int choice;
  
  do{
    do{
      cout << "\nWhat would you like to do?" << endl;
      cout << "1. Display Songs by Year\n" << "2. Add Song\n" << "3. Display Playlist\n"
	   << "4. Quit" << endl;
      
      cin >> choice;
    }while(choice < 1 || choice > 4);
    
    switch(choice){
    case 1:
      DisplaySongs();
      DisplayPlaylist();
      break;
    case 2:
      AddSong();
      DisplayPlaylist();
      break;
    case 3:
      DisplayPlaylist();
      break;
    case 4:
      cout << "Thank you for using the UMBC Music Player" << endl;
      break;
    }//End Switch
  }while(choice <= 3); 

}

//DisplaySongs()
//Displays a list of all songs for that year
void MusicPlayer::DisplaySongs(){
  int year;
  do{
    cout << "Which year would you like to display? (1983-2013)" << endl;
    cin >> year;
  }while(year < 1983 || year > 2013);

  cout << "******" << year << "******" << endl;

  for(unsigned int i = 0; i < m_songCatalog.size(); i++){

    //If the user entered year matches the year of the song
    if(m_songCatalog.at(i)->getYear() == year){
      //Print out the song's position, title, and Author 
      cout << i+1 << ". " << m_songCatalog.at(i)->getTitle()
	   << " by " << m_songCatalog.at(i)->getArtist() << endl;
    }//End if

  }//End for

}

//AddSong()
//Adds a song to the playlist
void MusicPlayer::AddSong(){
  int selection;
  DisplayPlaylist();
  cout << "\nChoose the songs you would like to add to the playlist." << endl;
  DisplaySongs();
  
  //Fix to enterable set year bounds using do-while loop
  cout << "\nEnter the number of the song you would like to add: " << endl;
  cin >> selection;
  //Enqueue selected song from the cataloge
  m_playList.enqueue(*m_songCatalog[selection-1]);
}

//DisplayPlaylist()
//Displays the song playlist
void MusicPlayer::DisplayPlaylist(){

  if(m_playList.isEmpty()){
    cout << "\n***Current Playlist is Empty***" << endl;
  }else{
    cout << "\n***Current Playlist***" << endl;
    for(int i = 0; i < m_playList.size(); i++){
      cout << i+1 << ". " << m_playList[i].getTitle()
	   << " from " << m_playList[i].getYear() << endl; 
    }//End for
  }//End else

}

