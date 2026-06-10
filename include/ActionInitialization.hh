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
/// \file ActionInitialization.hh
/// \brief Definition of the Rango::ActionInitialization class

//Edits from Skye Strain 2026
//Orginally from example B1
//Changed name to Rango 
//Defines the detector properties
#ifndef ActionInitialization_h
#define ActionInitialization_h 1

//Within the G4VUserActionInitialization class the user initiates
//and registers concrete G4VUserActionInitialization subclass
//this generates the primary particles for each event
#include "G4VUserActionInitialization.hh"

namespace Rango
{
// Action initialization class.
class ActionInitialization : public G4VUserActionInitialization
{
  public:
    ActionInitialization() = default; //Constructor
    ~ActionInitialization() override = default; //Destructor
    //Override allows this destructor to override the base's virtual destructor

    //Called only once by the master thread, to instigate and register master-specific
    //user action objects.
    void BuildForMaster() const override;
    //Method called by all worker threads
    void Build() const override;
};
//Always include #endif at the end of a header file.
}
#endif
