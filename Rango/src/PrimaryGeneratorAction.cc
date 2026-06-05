#include "PrimaryGeneratorAction.hh"

#include "G4GeneralParticleSource.hh"
#include "G4ParticleGun.hh"
#include "G4ParticleTable.hh"
#include "G4SystemOfUnits.hh"
#include "Randomize.hh"

  
PrimaryGeneratorAction::PrimaryGeneratorAction()
{
  fParticleGun = new G4GeneralParticleSource();

  // default particle kinematic
  fParticleGun->SetCurrentSourceIntensity(1);
  fParticleGun->SetParticlePosition(G4ThreeVector());
}

  
PrimaryGeneratorAction::~PrimaryGeneratorAction()
{
  delete fParticleGun;
}
  
void PrimaryGeneratorAction::GeneratePrimaries(G4Event* event)
{

     fParticleGun->GeneratePrimaryVertex(event);
}
