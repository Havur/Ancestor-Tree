# _Ancestral tree project_
Kandidatnr: **10024**

## The application
This is an application written in c++, that gives the user the possibility to create their own ancestral diagram. 
The application prompts the user to plot in information about themselves and their family(ancestors).
While the user plots in information, the app stores it and creates persons as objects.
The app then gives the user a main menu where they get to decide if they would like to
add a new ancestor, print out, edit or delete information of a created person and print the complete ancestral diagram in the application.

##Development
The code does have CI and does compile to the latest windows, mac and ubuntu

###Instructions for use
Note that the application is sensitive to incorrect misspelling of names, characters and numbers. For example adding an
ancestor that does not exist in the tree. The user will get a message saying: "The name does not exist, try again" or "Unknown answer" etc.
It is only possible to add two parents to each person in the tree, more than two parents are therefor not possible to include to a single person. The application does take into account
of people that don`t have a specified gender and parents that share the same gender. For this reason the family tree does NOT need to be biological, but it can be if user wishes to.


USER INSTRUCTIONS:
1. The app starts by asking the user to create the root node in the tree. This can be themselves or the person they want the tree to revolve around.
2. The "Main Menu" shows up, giving the user an option to type one of the alternatives given in the menu.
3. When typing "3" to add an ancestor to the family tree. The application prompts user questions to get data to store in a person. The app then asks who the child of the ancestor created is to locate the ancestor correctly in the tree.
4. When typing "2" the application asks the user to type the name of the person they want information about. The app then gives the information stored in the person searched for. 
5. When typing "1" the application will print out a 2D-Ancestral Diagram structured like folders.
6. When typing "4" a "Person Editor Menu" will show up. In the person editor, the user gets the choice to pick a preferred option which they would like to edit.
7. When typing "0" the application exits and program shuts down, note the progress plotted in program will not be saved.




