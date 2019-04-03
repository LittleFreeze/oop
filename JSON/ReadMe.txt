Evan Von Duhn

I modified main.cpp, json.hpp, and json.cpp to display and store, author and title from JSON.

I added in two classes (author and title) that inherited from the Value class.

The code generates a list of pointers to the value classes.  It stores the author and title classes into the list as it parses the json.  It then outputs the author and title values.