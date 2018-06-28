/********************************
 ** File: Song.cpp
 ** Project: CMSC 202 Project 5, Fall 2017
 ** Author: Enzo Walker
 ** Date: 11/27/2017
 ** Section: 1093, Discussion: 1095
 ** Email: enzow1@umbc.edu
 **
 ** 
 ** This class is responsible for holding information about a Song.
 ** The member variables of this class are the Song's Author, Title,
 ** Ranking, and Year which can all be accessed through getters and setters
 **
 ********************************/
#include "Song.h"

//Song()
//The defult song constructor that creates a default song
Song::Song(){
  //Initializes the song information to a default
  m_title = "N/A";
  m_artist = "N/A";
  m_year = 1;
  m_rank = 100;
}

//Song(string title, string artist, int year, int rank)
//Overloaded song constructor that passes information about the song
Song::Song(string title, string artist, int year, int rank){
  m_title = title;
  m_artist = artist;
  m_year = year;
  m_rank = rank;
}

//getTitle()const
//Returns the title of the current song
string Song::getTitle()const{
  return m_title;
}

//getArtist()const
//Returns the artist of the current song
string Song::getArtist()const{
  return m_artist;
}

//getYear()const
//Returns the year of the current song
int Song::getYear()const{
  return m_year;
}

//getRank()const
//Returns the rank of the current song between (1-100 from that year)
int Song::getRank()const{
  return m_rank;
}

//setTitle(string title)
//Sets the title of a song
void Song::setTitle(string title){
  m_title = title;
}

//setArtist(string artist)
//Sets the artist of a song
void Song::setArtist(string artist){
  m_artist = artist;
}

//setYear(int year)
//Sets the year of a song
void Song::setYear(int year){
  m_year = year;
}

//setRank(int rank)
//Sets the rank of a song
void Song::setRank(int rank){
  m_rank = rank;
}
