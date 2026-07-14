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
/// \file RunAction.hh
/// \brief Definition of the Rango::RunAction class

//Edits from Skye Strain 2026
//Orginally from example B1
//Changed name to Rango 

#ifndef RunAction_h
#define RunAction_h 1

#include "G4UserRunAction.hh"

#include "G4Accumulable.hh"
#include "globals.hh"

class G4Run;
//ROOT Stuff
class TFile;
class TTree;

/// Run action class
///
/// In EndOfRunAction(), it calculates the dose in the selected volume
/// from the energy deposit accumulated via stepping and event actions.
/// The computed dose is then printed on the screen.
namespace Rango
{
class RunAction : public G4UserRunAction
{
  public:
    RunAction();
    ~RunAction();

    void BeginOfRunAction(const G4Run*) override; //Begin of run
    void EndOfRunAction(const G4Run*) override; //End of run

    void AddEdep(G4double edep); //To calculate energy deposited

    TTree* GetTransTree() {return transTree;} //Return the tree containing transmission data
    TTree* GetEdepTree() {return edepTree;} //Return the tree containing energy deposition data
    TTree* GetThickTree() {return thickTree;} //Return the tree containing thickness data
    TTree* GetPhotonTree() {return photonTree;} //Return the tree with optical photon data
    void SetEnergy(G4double val) {fEnergy = val;} //Function to set energy
    void SetCounter(G4int val) {fCounter = val;} //Function to set transmission counter
    void SetEdep(G4double val) {Edep = val;} //Function to set energy deposited
    void SetThickness(G4double val) {fThick = val;} //Function to set thickness
    void SetPhotonCounter(G4int val) {fPhotonCounter = val;} //Function to set transmission counter

  private:
    //Energy deposition variables
    G4Accumulable<G4double> fEdep = 0.; 
    G4Accumulable<G4double> fEdep2 = 0.;

    //ROOT Stuff
    TFile* fRootFileTrans = nullptr; //Transmission file
    TFile* fRootFileEdep = nullptr; //Energy deposition file
    TFile* fRootFileThick = nullptr; //Thickness file
    TFile* fRootFilePhoton = nullptr; //Optical photon data file
    TTree* transTree = nullptr; //Transmission tree
    TTree* edepTree = nullptr; //Energy deposition tree
    TTree* thickTree = nullptr; //Thickness tree 
    TTree* photonTree = nullptr; //Optical photon data tree

    //Create variables
    G4double fEnergy; 
    G4int fCounter;
    G4int fPhotonCounter;
    G4double Edep;
    G4double fThick;
};
}
#endif
