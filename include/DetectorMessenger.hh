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
#ifndef DetectorMessenger_h
#define DetectorMessenger_h 1

//Include messanger package
#include "G4UImessenger.hh"

//Identify classes used in header
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcommand;

/// Messenger class that defines commands for DetectorConstruction.
///
/// It implements commands:
/// - /Detector/det/setDetMaterial name
/// - /Detector/det/stepMax value unit

namespace Rango
{
class DetectorConstruction; //Links to detector construction
class DetectorMessenger : public G4UImessenger
{
  public:
    DetectorMessenger(DetectorConstruction*); //Constructor
    ~DetectorMessenger() override; //Destructor

    void SetNewValue(G4UIcommand*, G4String) override; //Definition to create commands

  private:
    DetectorConstruction* fDetectorConstruction = nullptr; //Pointer for detector construction

    G4UIdirectory* fDirectory = nullptr; //Pointer for directory
    G4UIdirectory* fDetDirectory = nullptr; //Pointer for detector directory 
    G4UIcmdWithAString* fDetMatCmd = nullptr; //Command to change detector material
    G4UIcmdWithAString* fWinMatCmd = nullptr; //Command to change window material
    G4UIcmdWithAString* fWorldMatCmd = nullptr; //Command to change world material
    G4UIcmdWithADoubleAndUnit* fStepMaxCmd = nullptr; //Command to change maximum step
    G4UIcmdWithAString* fColourCmd = nullptr; //Command to change the color of the detector
};
}
//Always Include!!
#endif
