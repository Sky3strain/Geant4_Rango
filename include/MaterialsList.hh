//Header file to define materials.
#ifndef MaterialsList_h
#define MaterialsList_h 1

//Include packages
#include "G4Material.hh"
#include "G4NistManager.hh"
#include "G4ios.hh"
#include <iostream>
#include <string>
#include <vector>

using namespace CLHEP;

namespace Rango
{
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
        G4Material* Mg;//Define Magnesium as a material
        G4Material* Al;//Define Aluminum as a material
        G4Material* Teflon;//Teflon

        //New Detectors
        G4Material* CdTe;            // CdTe
        G4Material* CsI_Na;          // Cesium Iodide scintillator (doped w/sodium)
        G4Material* CsI_Tl;          // Cesium Iodide scintillator (doped w/thallium)
        G4Material* CeBr3;           // Cerium Bromide
        G4Material* NaI_Tl;          // Sodium Iodide scintillator (doped w/thallium)

        //To define Materials
        G4int numberOfComponents;  // number of atoms of each element
        G4State state;             // physical state
        G4int Z;                   // integer atomic number
        G4int A;                   // integer number of nucleons
        G4double z;                // atomic number
        G4double a;                // number of nucleons
        G4double density;          // density
        G4double abundance;        // abundance
        G4double pressure;         // pressure
        G4double temperature;      // temperature
        G4double weight_ratio;     // % weight ratio
        G4double numberOfAtoms;    // number of atoms (for specifying atomic ratios)

        G4NistManager *nist; //Define the nist manager
        static MaterialsList* instance; //Pointer for materials list
};
}
#endif