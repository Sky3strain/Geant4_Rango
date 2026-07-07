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
/// \file SteppingAction.hh
/// \brief Definition of the Rango::SteppingAction class

//Edits from Skye Strain 2026
//Orginally from example B1
//Changed name to Rango 
#include "SteppingAction.hh"
#include "DetectorConstruction.hh"
#include "EventAction.hh"

#include "G4Event.hh"
#include "G4LogicalVolume.hh"
#include "G4RunManager.hh"
#include "G4Step.hh"
#include "G4Track.hh"
#include "G4ParticleDefinition.hh"
#include "G4SystemOfUnits.hh"
#include "G4SteppingManager.hh"
#include "G4OpticalPhoton.hh"
#include "G4AnalysisManager.hh"
#include "RunAction.hh"
  
namespace Rango
{
//Link stepping action and event action through the constructor
SteppingAction::SteppingAction(EventAction* eventAction) : fEventAction(eventAction) {}
  
void SteppingAction::UserSteppingAction(const G4Step* step)
{
  //Set scoring volume
  if (!fScoringVolume) {
    const auto detConstruction = static_cast<const DetectorConstruction*>(
      G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detConstruction->GetScoringVolume();
  }

  //Track the particle
  const G4String currentPhysicalName = step->GetPreStepPoint()->GetPhysicalVolume()->GetName();
  const G4String particleName = step->GetTrack()->GetDefinition()->GetParticleName();
  const G4int trackId = step->GetTrack()->GetTrackID();
  const G4int parentId = step->GetTrack()->GetParentID();
  const G4String processName = step->GetPostStepPoint()->GetProcessDefinedStep()->GetProcessName();
  
  if (step->GetTrack()->GetNextVolume() != 0)
      volumeName = step->GetTrack()->GetNextVolume()->GetName();
   else // particle left world volume, use track volume name
      volumeName = step->GetTrack()->GetVolume()->GetName();

  //Flag if particle goes into the world
  if (volumeName == "World"){
    G4cout<< "Uh oh that beam is in the world! :("<<G4endl;
    return;
  }
  
  G4bool isPrimary = (trackId == 1) && (parentId == 0);
  
  if (isPrimary) {
        G4cout << "\n   Track ID: "<<trackId << " ";
        G4cout << "\n   Particle Name: "<<particleName << " ";
        G4cout << "\n   Time: "<<step->GetPreStepPoint()->GetGlobalTime() * ns<< " ";
        G4cout << "\n   Position: "<<step->GetTrack()->GetPosition()<< " ";
        G4cout << "\n   Etot: " << step->GetTrack()->GetKineticEnergy() / keV << " ";
        G4cout << "\n   Edep: " << step->GetTotalEnergyDeposit() / keV << " ";
        G4cout << "\n   Step Length: "<<step->GetStepLength() << " ";
        G4cout << "\n   Track Length: "<<step->GetTrack()->GetTrackLength() << " ";
        G4cout << "\n   Volume Name: "<<volumeName << " ";
        G4cout << "\n   Process Name: "<<processName << G4endl;
    } // END if (isPrimary)
    else{
        G4cout << "\n   Daugter Track ID: "<<trackId << " ";
        G4cout << "\n   Particle Name: "<<particleName << " ";
        G4cout << "\n   Time: "<<step->GetPreStepPoint()->GetGlobalTime() * ns<< " ";
        G4cout << "\n   Position: "<<step->GetTrack()->GetPosition()<< " ";
        G4cout << "\n   Etot: " << step->GetTrack()->GetKineticEnergy() / keV << " ";
        G4cout << "\n   Edep: " << step->GetTotalEnergyDeposit() / keV << " ";
        G4cout << "\n   Step Length: "<<step->GetStepLength() << " ";
        G4cout << "\n   Track Length: "<<step->GetTrack()->GetTrackLength() << " ";
        G4cout << "\n   Volume Name: "<<volumeName << " ";
        G4cout << "\n   Process Name: "<<processName << G4endl;
    }

    if (G4StrUtil::contains(volumeName, "Detector"))
    {
      // collect energy deposited in this step
      const G4double edepStep = step->GetTotalEnergyDeposit();
      fEventAction->AddEdep(edepStep);
      // eventAction->nFace = 1;
    } 
  
    //Counter for transmission through window
    G4int beCounter = 0.;
    if (G4StrUtil::contains(volumeName, "Beryllium Window"))
    {
      beCounter = 1;
    }

    //Counter for transmission through detector
    G4int detCounter = 0.;
    if (G4StrUtil::contains(volumeName, "Detector"))
    {
      detCounter = 1;
      beCounter = 1;
    } 

    //Give the counter information to event action
    fEventAction->DetCount(detCounter);
    fEventAction->BeCount(beCounter);   
}
}