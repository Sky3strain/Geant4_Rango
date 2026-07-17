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
//Code to run an event
//Header files
#include "EventAction.hh"
#include "RunAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "DetectorConstruction.hh"

//Packages
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "G4SteppingManager.hh"

#include <TFile.h>
// #include <TH1D.h>
#include <TTree.h>

//Include things required for txt file
// static std::ofstream dataFile("output.root");
// static bool first = true;
static std::ofstream dataFile("Tef200MIC.txt");
static bool first = true;

namespace Rango
{
//Create 
EventAction::EventAction(RunAction* runAction) : fRunAction(runAction) {} 
//Allows EventAction to communicate with RunAction

void EventAction::BeginOfEventAction(const G4Event* event)
{
  fEdep = 0.; //Initial energy deposition
  G4int eventID =event->GetEventID(); //Get the event ID
  G4cout<< "\nEvent#: "<<eventID<<G4endl; //Print the event ID
  fBeCounter = 0.;
  fDetCounter = 0.;
  fPhotonCount = 0.;
}
  
void EventAction::EndOfEventAction(const G4Event* event)
{
  fRunAction->AddEdep(fEdep); 
  G4int eventID =event->GetEventID(); //Get the event ID

  //ste up run manager
  G4RunManager *runManager = G4RunManager::GetRunManager();

  //Print event data
  G4cout <<"\nEvent"<<eventID<<" Summary: Total deposited energy = "
     <<fEdep / keV <<"keV"<<G4endl;

  //Get Particle Energy
  const auto generatorAction = static_cast<const PrimaryGeneratorAction*>(G4RunManager::GetRunManager()->GetUserPrimaryGeneratorAction());
  const G4GeneralParticleSource* particleGun = generatorAction->GetParticleGun();
  G4double particleEnergy = particleGun->GetParticleEnergy();

  //Get detector thickness
  const auto detConstruction = static_cast<const DetectorConstruction*>(G4RunManager::GetRunManager()->GetUserDetectorConstruction());
  const G4Tubs* detector = detConstruction->GetDet();
  G4double detThick = 2.0*detector->GetZHalfLength();
  
  G4int transmissionCount = GetTransmissionCount();
  G4int detectorCount = GetDetectorCount();
  G4int photonCount = GetPhotonCount();
  G4int totalCount = detectorCount+transmissionCount;

  //Fill optical photon data
  fRunAction->SetPhotonCounter(photonCount);
  fRunAction->SetCounter(totalCount);
  fRunAction->SetThickness(detThick/ cm);
  fRunAction->SetEdep(fEdep / keV);
  fRunAction->SetEnergy(particleEnergy / keV);
  TTree* outTree = fRunAction->GetOutTree();
  outTree->Fill();
}

}
