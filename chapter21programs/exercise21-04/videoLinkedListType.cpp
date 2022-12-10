#include <string>
#include "videoLinkedListType.h"
using namespace std;

// Searches the video list to see if a title is in the store
bool videoListType::videoSearch(string title) {
  bool found;
  list<videoType>::iterator location;

  // Finds the location of the video in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

	return found;
}

// Returns true if at least one copy of a video is in the stor
bool videoListType::isVideoAvailable(string title) {
  bool found;
  list<videoType>::iterator location;

  // Finds the location of the video in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

  if (found)
    return (location->getNoOfCopiesInStock() > 0);
  return false;
}

// Checks in a returned video
void videoListType::videoCheckIn(string title) {
  bool found;
  list<videoType>::iterator location;

  // Finds the location of the video in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

  if (found) {
    location->checkIn();
    videoList.remove(title);
  }
  else
    cout << "The store does not carry " << title << endl;
}

// Checks out a video
void videoListType::videoCheckOut(string title) {
  bool found;
  list<videoType>::iterator location;

  // Finds the location of the video in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

  if (found)
    location->checkOut();
  else
    cout << "The store does not carry " << title << endl;
}

// Returns true if there is a particular video in the store
bool videoListType::videoCheckTitle(string title) {
  bool found;
  list<videoType>::iterator location;

  // Finds if the video is in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

  return found;
}

// Updates the number of copies of a video by added 'num'
// (copiesInStock += num)
void videoListType::videoUpdateInStock(string title, int num) {
  bool found;
  list<videoType>::iterator location;

  // Finds the location of the video in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

  if (found)
    location->updateInStock(num);
  else
    cout << "The store does not carry " << title << endl;
}

// Resets the number of copies of a video, 'tite', to 'num'
void videoListType::videoSetCopiesInStock(string title, int num) {
  bool found;
  list<videoType>::iterator location;

  // Finds the location of the video in the list
  location = videoList.begin();
  searchVideoList(title, found, location);

  if (found)
    location->setCopiesInStock(num);
  else
    cout << "The store does not carry " << title << endl;
}

// Prints the titles of all of the videos in the store
void videoListType::videoPrintTitle() {
  for (auto vid : videoList)
    vid.printTitle();
}

// Prints out the info of all of the videos in the list
void videoListType::print() {
  for (auto vid : videoList)
    vid.printInfo();
}

// Appends a video to the list
void videoListType::insert(const videoType& vid) {
  videoList.push_front(vid);
}

// Searches the video list for the specified video. If found, 'found'
// is set to true and the element can be accessed via the iterator
// 'location'
void videoListType::searchVideoList(string title, bool &found,
  list<videoType>::iterator &location) {

  found = false;
  // Uses the iterator 'location' to go throuhg each video and see if
  // their title matches the inputted one. If it does, the function
  // stops with location still set to that element.
  for (; location != videoList.end(); location++) {
    if (location->getTitle() == title) {
      found = true;
      return;
    }
  }
}
