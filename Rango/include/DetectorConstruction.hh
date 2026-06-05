//Defines the detector properties
#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Threading.hh"
#include "globals.hh"
#include "MaterialsList.hh"
#include "ColourList.hh"

//Define classes used to make functions
class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class G4UserLimits;
class G4GlobalMagFieldMessenger;
class DetectorMessenger;
class G4VisAttributes;
class ColourList;

/// Detector construction class to define materials and geometry.
class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction(); //Constructor
    ~DetectorConstruction() override; //Destructor

  public:
    //Mandatory to implement, define and return world physical volume
    G4VPhysicalVolume* Construct() override;

    // Set functions
    void SetDetMaterial(G4String); //Set detector Materials
    void SetMaxStep(G4double); //Max Step, distance a particle can move before its interaction is processed
    void SetDetColour(G4String); //Set detector color
    void SetCheckOverlaps(G4bool); //Check for volumes overlaps
    void SetWorldMaterial(G4String); //Set world material

    //retrieve the pointer to the logical volume where you want simulation results
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }

  private:
    //Function to define materials
    void DefineMaterials();

    //Function to define colors
    void GetColours();

    //Placement of logical volume in detector geometry
    G4VPhysicalVolume* DefineVolumes();

    G4LogicalVolume* detLogic = nullptr;  // Pointer to the logical Detector

    G4LogicalVolume* logicWorld = nullptr; //Pointer to logical world

    G4LogicalVolume* beWinLogic = nullptr; //Pointer to beryllium window

    G4Material* detMaterial = nullptr;  // Pointer to the detector  material

    G4Material* worldMaterial = nullptr; //Pointer to world material

    MaterialsList* materialsList = nullptr; //Pointer for materials list

    G4VisAttributes* detColour; // Pointer to detector color

    ColourList* colourList = nullptr; //Dointer for colour list
  
    G4UserLimits* fStepLimit = nullptr;  // Pointer to user step limits

    DetectorMessenger* fMessenger = nullptr;  //Pointer to messenger

    G4bool fCheckOverlaps = true;  // Option to activate checking of volumes overlaps

    G4LogicalVolume* fScoringVolume = nullptr; //Pointer to the logical volume we want data from 

    //Parameters for detector geometry
    G4double innerRadius;
    G4double outerRadius;
    G4double detHz;
    G4double detPhimin;
    G4double detPhimax;
    G4double beWinHz;
    G4double offset;
};
//Always include!!
#endif
