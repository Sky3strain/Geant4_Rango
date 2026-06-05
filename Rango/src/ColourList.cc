//Code for colors of detector 
//include header
#include "ColourList.hh"

//Packages
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4UIcommand.hh"

ColourList* ColourList::instance = nullptr;

ColourList* ColourList::GetInstance()
{
    if (!instance) instance = new ColourList();
    return instance;
}

ColourList::ColourList()
:red(0), orange(0), yellow(0), green(0), blue(0), purple(0), pink(0), 
white(0), grey(0), invisibility(0) 
{
    if(instance == 0){
        instance = this;
    }
    DefineColour("red");
    DefineColour("orange");
    DefineColour("yellow");
    DefineColour("green");
    DefineColour("blue");
    DefineColour("purple");
    DefineColour("pink");
    DefineColour("white");
    DefineColour("grey");
    DefineColour("invisibility");
}

ColourList::~ColourList()
{
    delete red;
    delete orange;
    delete yellow;
    delete green;
    delete blue;
    delete purple;
    delete pink;
    delete white;
    delete grey;
    delete invisibility;
}

G4bool ColourList::DefineColour(G4String sColorNameIn)
{
    G4cout<< "Defining "<< sColorNameIn << "....."<<G4endl;
    if(sColorNameIn == "red")
    {
        red= new G4VisAttributes(G4Colour(1.0, 0.0, 0.0, 0.5)); //Create the color, transparency is 50%
        red->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "orange")
    {
        orange= new G4VisAttributes(G4Colour(1.0, 0.6, 0.0, 0.5)); //Create the color, transparency is 50%
        orange->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "yellow")
    {
        yellow= new G4VisAttributes(G4Colour(1.0, 1.0, 0.6, 0.5)); //Create the color, transparency is 50%
        yellow->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "green")
    {
        green= new G4VisAttributes(G4Colour(0.0, 1.0, 0.0, 0.5)); //Create the color, transparency is 50%
        green->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "blue")
    {
        blue= new G4VisAttributes(G4Colour(0.0, 0.8, 1.0, 0.5)); //Create the color, transparency is 50%
        blue->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "purple")
    {
        purple= new G4VisAttributes(G4Colour(0.5, 0.0, 0.5, 0.5)); //Create the color, transparency is 50%
        purple->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "pink")
    {
        pink= new G4VisAttributes(G4Colour(1.0, 0.6, 0.8, 0.5)); //Create the color, transparency is 50%
        pink->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "white")
    {
        white= new G4VisAttributes(G4Colour(1.0, 1.0, 1.0, 0.5)); //Create the color, transparency is 50%
        white->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "grey")
    {
        grey= new G4VisAttributes(G4Colour(0.75, 0.75, 0.75, 0.5)); //Create the color, transparency is 50%
        grey->SetVisibility(true); //Set the visibility
    }
    else if(sColorNameIn == "invisibility")
    {
        invisibility= new G4VisAttributes(G4Colour(0.0, 0.0, 0.0, 0.0)); //Create the color, transparency is 50%
        invisibility->SetVisibility(false); //Set the visibility
    }
    G4cout<<sColorNameIn<<"Defined... "<<G4endl;
    return true;
}

G4VisAttributes* ColourList::GetColour(G4String colourName)
{
    if(colourName == "red"){
        return red;
    }
    else if(colourName == "orange"){
        return orange;
    }
    else if(colourName == "yellow"){
        return yellow;
    }
    else if(colourName == "green"){
        return green;
    }
    else if(colourName == "blue"){
        return blue;
    }
    else if(colourName == "purple"){
        return purple;
    }
    else if(colourName == "pink"){
        return pink;
    }
    else if(colourName == "white"){
        return white;
    }
    else if(colourName == "grey"){
        return grey;
    }
    else if(colourName == "invisibility"){
        return invisibility;
    }
    else{
        G4cout<<colourName<<" is an invalid colour option."<<G4endl;
        return nullptr;
    }
    
}
