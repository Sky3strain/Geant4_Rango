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
/// \file DetectorMessenger.hh
/// \brief Definition of the Rango::DetectorMessenger class

//Edits from Skye Strain 2026
//Orginally from example B2a
//Changed name to Rango 
//Code to set commands
//Include header files
#include "DetectorMessenger.hh"
#include "DetectorConstruction.hh"

//Include packages 
#include "G4UIcmdWithADoubleAndUnit.hh"
#include "G4UIcmdWithAString.hh"
#include "G4UIdirectory.hh"

namespace Rango
{
DetectorMessenger::DetectorMessenger(DetectorConstruction* det) : fDetectorConstruction(det)
{
  fDirectory = new G4UIdirectory("/Detector/"); //Create new command directory
  fDirectory->SetGuidance("UI commands specific to this example."); //Description of command

  fDetDirectory = new G4UIdirectory("/Detector/det/"); //Create det directory
  fDetDirectory->SetGuidance("Detector construction control"); //Description of command

  fDetMatCmd = new G4UIcmdWithAString("/Detector/det/setDetMaterial", this); //Create the directory to set material
  fDetMatCmd->SetGuidance("Select Material of the Detector."); //Description of command
  fDetMatCmd->SetParameterName("choice", false); //Parameter name is choice, false means the user must do this to use command
  fDetMatCmd->AvailableForStates(G4State_PreInit, G4State_Idle); //Can be used before the initialization or when simulation is idle

  fDetThickCmd = new G4UIcmdWithADoubleAndUnit("/Detector/det/setDetThickness", this); //Create the directory to set thickness
  fDetThickCmd->SetGuidance("Select Thickness of the Detector."); //Description of command
  fDetThickCmd->SetParameterName("choice", false); //Parameter name is choice, false means the user must do this to use command
  fDetThickCmd->AvailableForStates(G4State_PreInit, G4State_Idle); //Can be used before the initialization or when simulation is idle

  fWinMatCmd = new G4UIcmdWithAString("/Window/setWinMaterial", this); //Create the directory to set material
  fWinMatCmd->SetGuidance("Select Material of the Window."); //Description of command
  fWinMatCmd->SetParameterName("choice", false); //Parameter name is choice, false means the user must do this to use command
  fWinMatCmd->AvailableForStates(G4State_PreInit, G4State_Idle); //Can be used before the initialization or when simulation is idle

  fWorldMatCmd = new G4UIcmdWithAString("/World/SetWorldMaterial", this); //Create the directory to set material
  fWorldMatCmd->SetGuidance("Select Material of the World."); //Description of command
  fWorldMatCmd->SetParameterName("choice", false); //Parameter name is choice, false means the user must do this to use command
  fWorldMatCmd->AvailableForStates(G4State_PreInit, G4State_Idle); //Can be used before the initialization or when simulation is idle

  fColourCmd = new G4UIcmdWithAString("/Detector/det/setDetColour", this); //Create the directory to set the Colour
  fColourCmd->SetGuidance("Select Colour of the Detector."); //Description of command
  fColourCmd->SetParameterName("colour", false); //Parameter name is Colour, false means the user must do this to use command
  fColourCmd->AvailableForStates(G4State_PreInit, G4State_Idle); //Can be used before the initialization or when simulation is idle

  fStepMaxCmd = new G4UIcmdWithADoubleAndUnit("/Detector/det/stepMax", this); //Create directory to set mac step
  fStepMaxCmd->SetGuidance("Define a step max"); //Description of command
  fStepMaxCmd->SetParameterName("stepMax", false); //Parameter name is stepMax, false means the user must do this to use command
  fStepMaxCmd->SetUnitCategory("Length"); //Tells Geant that this is a length 
  fStepMaxCmd->AvailableForStates(G4State_Idle); //Can only be used when simulation is idle
}

DetectorMessenger::~DetectorMessenger()
{
  //All new pointers so they must always include a delete in the destructor
  delete fDetMatCmd;
  delete fStepMaxCmd;
  delete fDirectory;
  delete fDetDirectory;
  delete fColourCmd;
  delete fWorldMatCmd;
  delete fWinMatCmd;
  delete fDetThickCmd;
}
  
void DetectorMessenger::SetNewValue(G4UIcommand* command, G4String newValue)
{
  if (command == fWinMatCmd) {
    fDetectorConstruction->SetWinMaterial(newValue); //Set new window material value if commmand is used
  }

  if (command == fDetMatCmd) {
    fDetectorConstruction->SetDetMaterial(newValue); //Set new detector material value if commmand is used
  }

  if (command == fDetThickCmd){
    fDetectorConstruction->SetDetectorThickness(fStepMaxCmd->GetNewDoubleValue(newValue)); //Set new detector thickness if command is used
  }

  if (command == fWorldMatCmd){
    fDetectorConstruction->SetWorldMaterial(newValue); //Set world with new material
  }

  if (command == fStepMaxCmd) {
    fDetectorConstruction->SetMaxStep(fStepMaxCmd->GetNewDoubleValue(newValue)); //Set new max step value if commmand is used
  }

  if (command == fColourCmd){
    fDetectorConstruction->SetDetColour(newValue); //Set new Colour for detector if command is used
  }
}
}
