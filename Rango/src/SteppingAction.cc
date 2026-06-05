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
  
SteppingAction::SteppingAction(EventAction* eventAction) : fEventAction(eventAction) {}
  
void SteppingAction::UserSteppingAction(const G4Step* step)
{
  if (!fScoringVolume) {
    const auto detConstruction = static_cast<const DetectorConstruction*>(
      G4RunManager::GetRunManager()->GetUserDetectorConstruction());
    fScoringVolume = detConstruction->GetScoringVolume();
  }

  // get volume of the current step
  const G4LogicalVolume* volume =
    step->GetPreStepPoint()->GetTouchableHandle()->GetVolume()->GetLogicalVolume();

  // check if we are in scoring volume
  if (volume != fScoringVolume) return;

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
      // if (G4StrUtil::contains(volumeName, "physiFaceRefl")) eventAction->nRefl = 1;
      // if (G4StrUtil::contains(volumeName, "physiCdTe")) eventAction->nCdTe = 1;
   } // END if (isPrimary)
   else{
      G4cout << "\n   Secondary Track ID: "<<trackId << " ";
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

  // if (!isPrimary && (particleName != "opticalphoton")) {
  //   if ((processName == "eIoni")) {
  //       if (G4StrUtil::contains(volumeName, "Detector"))
  //           EventAction->fEdep += step->GetTotalEnergyDeposit() / keV;
  //     }
  //  }
}
