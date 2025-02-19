// must complete parse_csv function for code to work properly with .csv files
#include <artistList.hpp>
#include <istream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>

// helper function provided to parse genres WITH square brackets
static void parse_genres(std::istream & file, std::string genres[Artist::max_genres]) {
    std::string temp;

    std::getline(file, temp, '[');
    std::getline(file, temp, ']');

    auto genre_idx = 0u;
    for(auto start = 0u; start < temp.size() and genre_idx < Artist::max_genres; ){
        auto start_quote = temp.find_first_of('\'', start) + 1;
        auto end_quote = temp.find_first_of('\'', start_quote);
        
        genres[genre_idx] = temp.substr(start_quote, end_quote - start_quote);
        ++genre_idx;

        start = end_quote + 1;
    }
    
    while(genre_idx < Artist::max_genres){
        genres[genre_idx] = "";
        ++genre_idx;
    }
}

// parse_csv needs to be written by the students
ArtistList parse_csv(std::istream& file) {
    ArtistList list;
    std::string line;
    std::getline(file, line); // Skip the header row

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string artist_id, artist_name, followers, genres_str, popularity_str;

        // Handle quoted fields properly
        std::getline(ss, artist_id, ',');
        std::getline(ss, artist_name, ',');
        std::getline(ss, followers, ',');
        
        // Use getline with quotes for genres field
        if (line.find("\"[") != std::string::npos) {
            std::getline(ss, genres_str, '\"'); // Skip the first quote
            std::getline(ss, genres_str, '\"'); // Extract content inside quotes
        } else {
            std::getline(ss, genres_str, ',');
        }

        std::getline(ss, popularity_str, ',');

        int total_followers = 0;
        int popularity = 0;

        std::istringstream followers_stream(followers);
        followers_stream >> total_followers;

        std::istringstream popularity_stream(popularity_str);
        popularity_stream >> popularity;

        // Parse genres
        std::string genres[Artist::max_genres];
        std::stringstream genres_stream(genres_str);
        parse_genres(genres_stream, genres);

        // Create Artist object and add to the list
        Artist artist(artist_id, artist_name, total_followers, genres, popularity);
        list.appendArtist(artist);
    }

    return list;
}