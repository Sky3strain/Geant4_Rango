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
//This code defines the detector geometry
//Always include header files that the code is dependent on
#include "DetectorConstruction.hh"
#include "DetectorMessenger.hh"

//Packages for the detector
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4Trd.hh"
#include "G4Tubs.hh"
#include "G4VisAttributes.hh"
#include "G4Colour.hh"
#include "G4Material.hh"
#include "G4UserLimits.hh"
#include "G4ThreeVector.hh"
#include "G4UImanager.hh"
#include "G4RunManager.hh"
#include <cmath>

namespace Rango
{
//Constructor 
DetectorConstruction::DetectorConstruction() 
{
  fMessenger = new DetectorMessenger(this); //Creates a new messanger pointer
  fCheckOverlaps = true;
}

//Destructor
DetectorConstruction::~DetectorConstruction()
{
  delete fMessenger; //deletes messanger pointer
  delete materialsList; //delete materials list pointer to prevent leak
  //Note: if you ever make a p = new Pointer and new is involved you must delete the pointer.
}

//Define physical volume
G4VPhysicalVolume* DetectorConstruction::Construct()
{
  // Define materials
  DefineMaterials();

  //Define Colours
  GetColours();

  // Define volumes
  return DefineVolumes();
}

//Define Materials
void DetectorConstruction::DefineMaterials()
{
  materialsList = new MaterialsList(); // Initialize materials list
  materialsList->PrintMaterialTable(); // Print material table
}

//Define Colours
void DetectorConstruction::GetColours()
{
  colourList = ColourList::GetInstance(); // Initialize colour list
}

//Create the volumes
G4VPhysicalVolume* DetectorConstruction::DefineVolumes()
{
  //
  // World
  //
  G4double world_size = 1.0*m; //World size
  worldMaterial = G4Material::GetMaterial("Air");

  //Construt a cube world
  auto solidWorld =
    new G4Box("World",  // its name
              world_size*0.5, world_size*0.5, world_size*0.5);  // its size

  //The worlds logical volume
  logicWorld = new G4LogicalVolume(solidWorld,  // its solid
                                        worldMaterial, // its material
                                        "World");  // its name
  
  //The worlds physical placement
  auto physWorld = new G4PVPlacement(nullptr,  // no rotation
                                     G4ThreeVector(),  // at (0,0,0)
                                     logicWorld,  // its logical volume
                                     "World",  // its name
                                     nullptr,  // its mother  volume
                                     false,  // no boolean operation
                                     0,  // copy number
                                     fCheckOverlaps);  // overlaps checking
  
  //
  // Detector
  //
  // Define size of detector
  innerRadius = 0 *cm;
  outerRadius = 6.35 *cm;
  detHz = 1.27 * cm;
  detPhimin = 0. * deg;
  detPhimax = 360. * deg;

  // //Define detector material
  detMaterial = G4Material::GetMaterial("NaI");

  //Make the Detector a cylinder
  auto detector = new G4Tubs("Detector", //its name
                                innerRadius, outerRadius,
                                detHz*0.5, detPhimin, detPhimax);//its size

  //Detector logical volume
  detLogic = new G4LogicalVolume(detector,  // its solid
                                         detMaterial,  // its material
                                         "Detector");  // its name

  //Detector Colour
  detLogic->SetVisAttributes(ColourList::GetInstance()->GetColour("grey"));

  //Detector placement
  new G4PVPlacement(nullptr,  // no rotation
                    G4ThreeVector(),  // at position
                    detLogic,  // its logical volume
                    "Detector",  // its name
                    logicWorld,  // its mother  volume
                    false,  // no boolean operation
                    0,  // copy number
                    fCheckOverlaps);  // overlaps checking

  G4cout << "Target has a diameter of: " << 2 * outerRadius / cm << " cm, and is made of " << detMaterial->GetName()
         << G4endl;

  // Set the detector as scoring volume
  fScoringVolume = detLogic;

  //
  //Beryllium Window
  //
  
  //Thickness of beryllium window
  beWinHz = 0.2*mm;

  //Window material
  winMaterial = G4Material::GetMaterial("Be");

  //offset of beryllium window
  offset = -1*((beWinHz/2)+(detHz/2));

  //Make the window a cylinder
  auto beWin = new G4Tubs("Beryllium Window", //its name
                                innerRadius, outerRadius,
                                beWinHz*0.5, detPhimin, detPhimax);//its size
  
  //Window logical volume
  beWinLogic = new G4LogicalVolume(beWin,  // its solid
                                         winMaterial,  // its material
                                         "Beryllium Window");  // its name
  
 
  //Window placement
  new G4PVPlacement(nullptr,  // no rotation
                    G4ThreeVector(0.0, 0.0, offset), // at position
                    beWinLogic,  // its logical volume
                    "Beryllium Window",  // its name
                    logicWorld,  // its mother  volume
                    false,  // no boolean operation
                    0,  // copy number
                    fCheckOverlaps);  // overlaps checking
 
  G4VisAttributes* beWinColor= new G4VisAttributes(G4Colour(0.6, 0.2, 0.0, 0.8)); //Create the color, transparency is 50%
  beWinColor->SetVisibility(true); //Set the visibility
  beWinLogic->SetVisAttributes(beWinColor); //Give the window the color

  //always return the physical World
  return physWorld;
}

//Set Target Materials
void DetectorConstruction::SetDetMaterial(G4String materialName)
{
  //Material Definition
  G4NistManager* nistManager = G4NistManager::Instance();

  //Find or build the material input
  G4Material* pttoMaterial = nistManager->FindOrBuildMaterial(materialName);

  //See if it is already the material
  if (detMaterial != pttoMaterial) {
    if (pttoMaterial) {
      detMaterial = pttoMaterial; //If its is not then set them equal
      if (detLogic) detLogic->SetMaterial(detMaterial); //Make the detector material whatever materialName is
      G4cout << G4endl << "----> The target is made of " << materialName << G4endl; //print material
    }
    else {
      G4cout << G4endl << "-->  WARNING from SetDetMaterial : " << materialName << " not found" //Printed if material cannot be found
             << G4endl;
    }
  }
}

void DetectorConstruction::SetWinMaterial(G4String materialName)
{
  //Material definition
  G4NistManager* nistManager = G4NistManager::Instance();
  
  //Find or build the material 
  G4Material* pttoMaterial = nistManager->FindOrBuildMaterial(materialName);

  //See if it is already that material
  if (winMaterial != pttoMaterial){
    if(pttoMaterial){
      winMaterial = pttoMaterial; //If its not set them equal 
      if(beWinLogic) beWinLogic->SetMaterial(winMaterial);//Make the window material whatever materialName is
      G4cout << G4endl << "----> The target is made of " << materialName << G4endl; //print material
    }
    else {
      G4cout << G4endl << "-->  WARNING from SetDetMaterial : " << materialName << " not found" //Printed if material cannot be found
             << G4endl;
    }
  }
}


//Set world material
void DetectorConstruction::SetWorldMaterial(G4String materialName)
{
  //Material Definition
  G4NistManager* nistManager = G4NistManager::Instance();

  //Find or build material input
  G4Material* inMaterial = nistManager->FindOrBuildMaterial(materialName);

  //See if it is already that material
  if (worldMaterial != inMaterial) {
    if (inMaterial) {
      worldMaterial = inMaterial; //If its is not then set them equal
      if (logicWorld) logicWorld->SetMaterial(worldMaterial); //Make the detector material whatever materialName is
      G4cout << G4endl << "----> The world is made of " << materialName << G4endl; //print material
    }
    else {
      G4cout << G4endl << "-->  WARNING from SetWorldMaterial : " << materialName << " not found" //Printed if material cannot be found
             << G4endl;
    }
  }
}

//Set detector color
void DetectorConstruction::SetDetColour(G4String colour)
{
  //Find the colour
  G4VisAttributes* vis = ColourList::GetInstance()->GetColour(colour);

  //See if it is already that colour
  if(vis){
    detColour = vis; //If its is not then set them equal
    if(detLogic) {
      vis->SetVisibility(true);
      vis->SetForceSolid(true);
      detLogic->SetVisAttributes(vis); //Set the detector to that colour
    }
    }
  G4UImanager::GetUIpointer()->ApplyCommand("/vis/viewer/rebuild");
}

//Set maximum step 
void DetectorConstruction::SetMaxStep(G4double maxStep)
{
  if ((fStepLimit) && (maxStep > 0.)) fStepLimit->SetMaxAllowedStep(maxStep); //Allows you to define the maximum step in the terminal
}

//Overlaps
void DetectorConstruction::SetCheckOverlaps(G4bool checkOverlaps)
{
  fCheckOverlaps = checkOverlaps; //Checks to see if volumes are overlapping
}
}
