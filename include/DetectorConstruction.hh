//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
/// \file DetectorConstruction.hh
/// \brief Definition of the Rango::DetectorConstruction class

//Edits from Skye Strain 2026
//Orginally from example B1
//Changed name to Rango 
//Defines the detector properties
#ifndef DetectorConstruction_h
#define DetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "G4Threading.hh"
#include "globals.hh"
#include "MaterialsList.hh"
#include "ColourList.hh"
#include "EventAction.hh"
#include "G4Tubs.hh"

//Define classes used to make functions
class G4VPhysicalVolume;
class G4LogicalVolume;
class G4Material;
class G4UserLimits;
class G4GlobalMagFieldMessenger;
class G4VisAttributes;
class ColourList;
class G4Tubs;
class G4PVPlacement;

namespace Rango
{

class DetectorMessenger;//So DetectorContruction can talk to DetectorMessanger
/// Detector construction class to define materials and geometry.
class EventAction;
class DetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DetectorConstruction(); //Constructor
    ~DetectorConstruction() override; //Destructor

  public:
    //Mandatory to implement, define and return world physical volume
    G4VPhysicalVolume* Construct() override;

    // Set functions
    void SetDetMaterial(G4String); //Set detector materials
    void SetWinMaterial(G4String); //Set window materials
    void SetMaxStep(G4double); //Max Step, distance a particle can move before its interaction is processed
    void SetDetColour(G4String); //Set detector color
    void SetCheckOverlaps(G4bool); //Check for volumes overlaps
    void SetWorldMaterial(G4String); //Set world material
    void SetDetectorThickness(G4double); //Set the Detector thickness
    void SetDetectorPosition(G4ThreeVector); //Set detector position

    //retrieve the pointer to the logical volume where you want simulation results
    G4LogicalVolume* GetScoringVolume() const { return fScoringVolume; }
    G4Tubs* GetDet() const {return detector;}

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

    G4Material* winMaterial = nullptr; //Pointer to window material

    G4Material* worldMaterial = nullptr; //Pointer to world material

    MaterialsList* materialsList = nullptr; //Pointer for materials list

    G4VisAttributes* detColour; // Pointer to detector color

    ColourList* colourList = nullptr; //Dointer for colour list
  
    G4UserLimits* fStepLimit = nullptr;  // Pointer to user step limits

    DetectorMessenger* fMessenger = nullptr;  //Pointer to messenger

    G4bool fCheckOverlaps = true;  // Option to activate checking of volumes overlaps

    G4LogicalVolume* fScoringVolume = nullptr; //Pointer to the logical volume of detector

    G4Tubs* detector = nullptr;

    G4PVPlacement* physWorld = nullptr;

    G4PVPlacement* beWinPv = nullptr;

    G4PVPlacement* detPv = nullptr;

    //Parameters for detector geometry
    G4double innerRadius;
    G4double outerRadius;
    G4double detHz;
    G4double detPhimin;
    G4double detPhimax;
    G4double beWinHz;
    G4double offset;
    G4double detHzReal;
    G4double posOffset;
};
}
//Always include!!
#endif
