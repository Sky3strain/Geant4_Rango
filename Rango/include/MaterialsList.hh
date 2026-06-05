//Header file to define materials.
#ifndef MaterialsList_h
#define MaterialsList_h 1

//Include packages
#include "G4Material.hh"
#include "G4NistManager.hh"

//Create the class
class MaterialsList
{
    public:
        MaterialsList(); //Constructor
        ~MaterialsList(); //Destructor
        G4bool MaterialExists( G4String sMaterialNumIn );  // Function to see if material exists
        G4bool DefineMaterial( G4String sMaterialNumIn );  // Function to define material
        G4bool PrintMaterialTable();                       // Function to print table of all defined materials
        static MaterialsList* GetInstance(); // Returns pointer to the current materials list instance
    private:
        G4Material* NaI; //Define Sodium Iodide as a material
        G4Material* CsI; //Define Cesium Iodide as a material
        G4Material* Air; //Define Air as a material
        G4Material* Vaccum; //Define a vaccum
        G4Material* Be; //Define Beryllium as a material
        G4NistManager *nist; //Define the nist manager
        static MaterialsList* instance; //Pointer for materials list
};

#endif