#ifndef SCREEN_H
#define SCREEN_H

#include <string>
#include <iostream>
using namespace std;

// The unsigned integral type which is used to store the number of
// characters in a string is nested within the string class, so it
// is accessed using "string::size_type".
// The range of string::size_type is guaranteed to be large enough to store the maximum
// *size* of any string that can be held by the string class as well as any index into
// the string.

class Screen {
public:
	// Screen's constructor
	Screen(string::size_type height, string::size_type width, char bkground = '#');

	// get the Screen's height
	string::size_type height() const { return height_; }
	// get the Screen's width
	string::size_type width() const { return width_; }
    /* The 'const' keyword after the function signature indicates that this member function does not modify any member variables of the class.
	 It guarantees that calling this function will not change the state of the object.*/
	// place the cursor at the top-left corner of the screen
	void home() { cursor_ = 0;  return; }
	// place the cursor at the bottom-right corner of the screen
	void end() { cursor_ = width_ * height_ - 1; return; }
	// move the cursor one position to the right
	void forward();
	// move the cursor one position to the left
	void back();
	// move the cursor up one row
	void up();
	// move the cursor down one row
	void down();
	// move the cursor to the specified row and column
	void move(string::size_type row, string::size_type col);

	// New overloaded move function to move in a specified direction
    void move(Direction dir);
	/*The move member function is not strictly necessary for clients of Screen, 
	but it provides a convenient way to navigate the screen in a more intuitive and direction-based manner.*/


	// get the character at the cursor's current position
	char get() const { return _screen[cursor_]; }
	/*The 'const' keyword here indicates that the function will not modify the state of the object.
	This is particularly useful when the function is used to access data members without altering them.*/

	// get the character at the specified row and column
	char get(string::size_type row, string::size_type col);
	// write a character on the screen at the current cursor position
	void set( char ch );
	// write a string of characters on the screen starting at the current cursor position
	void set( const string& s );
	// overwrite the entire screen with the specified character
	void clear( char bkground = '#');

	// resize the screen
	void reSize( string::size_type height, string::size_type width, char bkground = '#');/*The reSize function adjusts the dimensions of the screen to the specified height and width.
 	It uses the string class's at function to safely access and modify characters in the _screen string, ensuring out-of-bounds errors are handled properly.*/
	// display the screen
	void display() const;
	// check whether the specified co-ordinates lie within the screen
	bool checkRange(string::size_type row, string::size_type col) const;
	/*The 'const' keyword at the end of this function declaration means that the function will not modify the state of the object. 
	It ensures that these functions can be safely called on const instances of the class.*/
	// New function 
    void drawSquare(string::size_type topLeftRow, string::size_type topLeftCol, string::size_type sideLength);

private:
	// constants
	// 0 represents the top-left screen element
	const string::size_type TOP_LEFT = 0;

	// private member functions
	string::size_type remainingSpace() const;
	string::size_type row() const;

	 // Private helper functions
    bool isValidPosition(string::size_type row, string::size_type col) const;
    void drawLine(string::size_type startRow, string::size_type endRow, string::size_type col, char ch);

	// private data members
	// (using a trailing underscore is a naming convention for private data - not a requirement)

	// number of Screen rows
	string::size_type height_;
	// number of Screen columns
	string::size_type width_;
	// default position of the Screen's cursor, use in-class initilisation
	string::size_type cursor_ = TOP_LEFT;
	// the Screen's data is stored as a string
	string _screen;
}
/*You can use the existing interface to implement the drawSquare function by utilizing public methods like set to modify the screen's content. However, having direct access to the internal representation could simplify implementation and error checking.
A function like drawSquare can be considered part of the responsibilities of a Screen object if the Screen class is meant to handle complex drawing operations. Otherwise, drawing might be better suited for a separate class or utility, depending on the design goals.*/
/*A more intuitive internal representation could be a 2D array or vector of vectors of characters, which would align more closely with the screen's row and column structure. This would make operations like drawing shapes more straightforward.
It's important to avoid changing the class’s interface to ensure existing code that uses the `Screen` class continues to function without modification. Changing the implementation is allowed because it improves the internal workings of the class without affecting how users interact with it.*/
;#endif

