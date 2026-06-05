#ifndef PrimaryGeneratorAction_h
#define PrimaryGeneratorAction_h 1

#include "G4VUserPrimaryGeneratorAction.hh"
#include "G4Event.hh"
#include "G4GeneralParticleSource.hh"

/// The primary generator action class with particle gun.
///
/// The default kinematic is a 6 MeV gamma, randomly distribued
/// in front of the phantom across 80% of the (X,Y) phantom size.

class PrimaryGeneratorAction : public G4VUserPrimaryGeneratorAction
{
  public:
    PrimaryGeneratorAction();
    ~PrimaryGeneratorAction() override;

    // method to access particle gun
    void GeneratePrimaries(G4Event*);
    G4GeneralParticleSource* GetParticleGun() const { return fParticleGun; }

  private:
    G4GeneralParticleSource* fParticleGun = nullptr;  // pointer a to G4 gun class
};

#endif
