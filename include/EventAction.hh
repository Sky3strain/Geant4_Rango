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
/// \file EventAction.hh
/// \brief Definition of the Rango::EventAction class

//Edits from Skye Strain 2026
//Orginally from example B1
//Changed name to Rango 

#ifndef EventAction_h
#define EventAction_h 1

//Packages used
#include "G4UserEventAction.hh"
#include "globals.hh"

//Create classes
class G4Event;

namespace Rango
{
class RunAction; //Used so that RunAction can be linked to EventAction
/// Event action class
class EventAction : public G4UserEventAction
{
  public:
    EventAction(RunAction* runAction); //Constructor, linked to RunAction
    ~EventAction() override = default; //Destructor

    void BeginOfEventAction(const G4Event* event) override; //Beginning of event class
    void EndOfEventAction(const G4Event* event) override; //End of event class

    void AddEdep(G4double edep) { fEdep += edep; } //Energy deposition class

    void BeCount(G4int beCounter) {fBeCounter = beCounter;}
    G4int GetTransmissionCount() {return fBeCounter;}

    void DetCount(G4int detCounter) {fDetCounter = detCounter;}
    G4int GetDetectorCount() {return fDetCounter;}

    void GetEnergy(G4int particleEnergy) {fParticleEnergy = particleEnergy;}
    G4int GetParticleEnergy() {return fParticleEnergy;}

    
  private:
    RunAction* fRunAction = nullptr; //Pointer for run action
    G4double fEdep = 0.; //Energy deposition variable 
    G4Event* event = nullptr; //Event variable
    G4int fBeCounter = 0.;
    G4int fDetCounter = 0.;
    G4double fParticleEnergy = 0.;
};
}
//Always include
#endif
