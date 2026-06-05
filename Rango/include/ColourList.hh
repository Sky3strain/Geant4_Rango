//Create all Colours for the detector
#ifndef ColourList_h
#define ColourList_h 1

//Packages
#include "G4VisAttributes.hh"
#include "G4Colour.hh"

//create the class
class ColourList
{
    public:
        ColourList(); //Constructor
        ~ColourList(); //Detsructor
        G4bool DefineColour(G4String sColourNumIn); //To define Colour
        G4VisAttributes* GetColour(G4String colourName); //To get the colour
        static ColourList* GetInstance(); // Returns pointer to the current colour list instance
    private:
        //Colours
        G4VisAttributes* red;
        G4VisAttributes* orange;
        G4VisAttributes* yellow;
        G4VisAttributes* green;
        G4VisAttributes* blue;
        G4VisAttributes* purple;
        G4VisAttributes* pink;
        G4VisAttributes* white;
        G4VisAttributes* grey;
        G4VisAttributes* invisibility;
        static ColourList* instance; //Pointer for Colour list
};

#endif