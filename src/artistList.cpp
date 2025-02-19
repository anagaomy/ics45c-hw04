// artistList.cpp: function definitions for prototypes for artistList.h header file
// place header includes here
#include "artistList.hpp"
#include <iostream>


ArtistList::ArtistEntry::ArtistEntry(ArtistList* list, const Artist& a)
  : list(list), next(nullptr), prev(nullptr), artist(a) {}

// Allocate a new artist list
ArtistList::ArtistList() : length(0), first(nullptr), last(nullptr) {}

std::size_t ArtistList::size() const {
  return length;
}

bool ArtistList::is_empty() const {
  return length == 0;
}

ArtistList::ArtistList(const ArtistList & list) : length(0), first(nullptr), last(nullptr) {
  if (list.first == nullptr) {
    this->first = nullptr;
  }
  for (ArtistEntry* current = list.first; current != nullptr; current = current->next) {
    appendArtist(current->artist);
  }
}

// Delete a artist list (and all entries)
ArtistList::~ArtistList() noexcept {
  while (!is_empty()) {
    removeFirstArtist();
  }
}

// prepend an artist at the beginning of list
void ArtistList::prependArtist(const Artist& a) {
  ArtistEntry* new_entry = new ArtistEntry(this, a);
  if (is_empty()) {
    first = last = new_entry;
  } else {
    new_entry->next = first;
    first->prev = new_entry;
    first = new_entry;
  }
  length++;
}

// append an artist to the end of the list
void ArtistList::appendArtist(const Artist& a) {
  ArtistEntry* new_entry = new ArtistEntry(this, a);
  if (is_empty()) {
    first = last = new_entry;
  } else {
    new_entry->prev = last;
    last->next = new_entry;
    last = new_entry;
  }
  length++;
}

// remove the first artist from the list
void ArtistList::removeFirstArtist() {
  if (is_empty()) return;
  ArtistEntry* to_delete = first;
  first = first->next;
  if (first) {
    first->prev = nullptr;
  } else {
    last = nullptr;
  }
  delete to_delete;
  length--;
}

// remove last artist from the list
void ArtistList::removeLastArtist() {
  if (is_empty()) return;
  ArtistEntry* to_delete = last;
  last = last->prev;
  if (last) {
    last->next = nullptr;
  } else {
    first = nullptr;
  }
  delete to_delete;
  length--;
}

// print an artist list
void ArtistList::printArtistList() const {
  ArtistEntry* current = first;
  while (current) {
    current->artist.printArtist();
    std::cout << std::endl;
    current = current->next;
  }
}

// find an artist by name in an unsorted list
Artist *ArtistList::findArtistName(const std::string& name) const {
  ArtistEntry* current = first;
  while (current) {
    if (current->artist.name() == name) {
      return &current->artist;
    }
    current = current->next;
  }
  return nullptr;
}

// remove artist by name in an unsorted list
void ArtistList::removeArtistbyName(const std::string & name) {
  ArtistEntry* current = first;

  while (current != nullptr) {
    if (current->artist.name() == name) {
      if (current == first) {
        removeFirstArtist();
        return;
      }

      if (current == last) {
        removeLastArtist();
        return;
      }

      current->prev->next = current->next;
      current->next->prev = current->prev;
      delete current;
      length--;
      return;
    }
    current = current->next;
  }
}

void ArtistList::insertArtistAt(std::size_t index, const Artist& artist) {
  if (index > length) return;

  if (index == 0) {
    prependArtist(artist);
    return;
  }
  if (index == length) {
    appendArtist(artist);
    return;
  }

  ArtistEntry* new_entry = new ArtistEntry(this, artist);
  ArtistEntry* current = first;

  for (size_t i = 0; i < index; ++i) {
    current = current->next;
  }

  new_entry->prev = current->prev;
  new_entry->next = current;
  current->prev->next = new_entry;
  current->prev = new_entry;

  length++;
}

Artist * ArtistList::at(size_t index) {
  if (index >= size()) return nullptr;

  ArtistEntry* current = first;
  for (size_t i = 0; i < index; ++i) {
    current = current->next;
  }

  return &current->artist;
}

const Artist * ArtistList::at(size_t index) const {
  if (index >= size()) return nullptr;

  ArtistEntry* current = first;
  for (size_t i = 0; i < index; ++i) {
    current = current->next;
  }
  
  return &current->artist;
}

Artist* ArtistList::firstArtist() {
  return (first != nullptr) ? &first->artist : nullptr;
}

const Artist* ArtistList::firstArtist() const {
  return (first != nullptr) ? &first->artist : nullptr;
}

Artist* ArtistList:: lastArtist() {
  return (last != nullptr) ? &last->artist : nullptr;
}

const Artist* ArtistList:: lastArtist() const {
  return (last != nullptr) ? &last->artist : nullptr;
}
