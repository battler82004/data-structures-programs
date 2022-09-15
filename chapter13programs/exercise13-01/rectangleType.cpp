#include <iostream>
#include "rectangleType.h" 
using namespace std;

rectangleType rectangleType::operator++() {
  length++;
  width++;

  return *this;
}

rectangleType rectangleType::operator++(int u ) {
  rectangleType temp = *this;

  length++;
  width++;

  return temp;
}

rectangleType rectangleType::operator--() {
  // Checks that neither the length or width will be negative
  if (length > 0) { length--; }
  if (width > 0) { width--; }

  return *this;
}

rectangleType rectangleType::operator--(int u ) {
  rectangleType temp = *this;

  // Checks that neither the length or width will be negative
  if (length > 0) { length--; }
  if (width > 0) { width--; }

  return temp;
}

rectangleType rectangleType::operator+(const rectangleType&
  otherRect) {
  
  length += otherRect.length;
  width += otherRect.width;

  return *this;
}

rectangleType rectangleType::operator-(const rectangleType&
  otherRect) {
  
  int potLength = length - otherRect.length;
  int potWidth = width - otherRect.width;

  // Makes sure that the length and width won't be negative
  if ((potLength >= 0) && (potWidth >= 0)) {
    length = potLength;
    width = potWidth;
  }
  else {
    cout << "Error, subtractant is too big." << endl;
  }

  return *this;
}

bool rectangleType::operator==(const rectangleType&
  otherRect) const {
  
  return (length * width) == (otherRect.length * otherRect.width);
}

bool rectangleType::operator!=(const rectangleType&
  otherRect) const {
  
  return (length * width) != (otherRect.length * otherRect.width);
}

bool rectangleType::operator>(const rectangleType&
  otherRect) const {
  
  return (length * width) > (otherRect.length * otherRect.width);
}

bool rectangleType::operator>=(const rectangleType&
  otherRect) const {
  
  return (length * width) >= (otherRect.length * otherRect.width);
}

bool rectangleType::operator<(const rectangleType&
  otherRect) const {
  
  return (length * width) < (otherRect.length * otherRect.width);
}

bool rectangleType::operator<=(const rectangleType&
  otherRect) const {
  
  return (length * width) <= (otherRect.length * otherRect.width);
}

rectangleType rectangleType::doubleDimensions()
{
    length = 2 * length;
    width = 2 * width;

    return *this;
}

void rectangleType::setDimension(double l, double w)
{
    if (l >= 0)
        length = l;
    else
        length = 0;

    if (w >= 0)
        width = w;
    else
        width = 0;
}

double rectangleType::getLength() const
{
    return length;
}

double rectangleType::getWidth()const
{
    return width;
}

double rectangleType::area() const
{
    return length * width;
}

double rectangleType::perimeter() const
{
     return 2 * (length + width);
}

void rectangleType::print() const
{
    cout << "Length = "  << length
         << "; Width = " << width;
}

rectangleType::rectangleType(double l, double w)
{
    setDimension(l, w);
}

rectangleType::rectangleType()
{
    length = 0;
    width = 0;
}
