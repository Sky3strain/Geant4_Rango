//For optical properties 
//Uses Josh Wood's optical propery code optical_2021-05-05
/////////////////////////////////////////////////////////
//
// Apr/2015  E. Nacher -> PhysicsList.cc
//
// Physics List is a simplification of the LXePhysicsList 
// ($G4INSTALL/examples/extended/optical/LXe). EM physics 
// just registering G4EmStandardPhysics and no Decay Physics.
//
////////////////////////////////////////////////////////
#include "PhysicsList.hh"
#include "G4ParticleTypes.hh"
#include "G4SystemOfUnits.hh"
#include "G4OpticalPhysics.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4EmStandardPhysics.hh"

PhysicsList::PhysicsList() : G4VModularPhysicsList()
{
   defaultCutValue = 0.1 * mm;

   // RegisterPhysics(new G4EmStandardPhysics());
   RegisterPhysics(new G4EmStandardPhysics_option4);

   //Register optical properties
   auto opticalPhysics = new G4OpticalPhysics();
   RegisterPhysics(opticalPhysics);
}

PhysicsList::~PhysicsList() {}

void PhysicsList::SetCuts(){
   SetCutsWithDefault();
}
