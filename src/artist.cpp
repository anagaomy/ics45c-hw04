// artist.cpp: function definitions file for artist.h

// place header file includes here
#include "artistList.hpp"
#include <iostream>
#include <iomanip>

// Allocate a new artist record
Artist::Artist(const std::string & artist_id, const std::string & artist_name, int total_followers, std::string genres[Artist::max_genres], int popularity)
  : artist_id{artist_id}, artist_name{artist_name}, total_followers{total_followers}, popularity{popularity} {
    for (size_t i = 0; i < Artist::max_genres; ++i) {
      this->genres[i] = genres[i];
    }
}

// Print an artist record
void Artist::printArtist() const{
  std::cout << "Artist ID: " << artist_id << std::endl;
  std::cout << "Artist Name: " << artist_name << std::endl;
  std::cout << "Total Followers: " << total_followers << std::endl;
  std::cout << "Genres: " ;

  bool first = true;
  for (const auto& genre : genres) {
    if (!genre.empty()) {
      if (!first) {
        std::cout << ", ";
      }
      std::cout << genre;
      first = false;
    }
  }  
  std::cout << std::endl << "Popularity: " << popularity << std::endl;
}

const std::string& Artist::name() const {
  return artist_name;
}

const std::string& Artist::id() const {
  return artist_id;
}