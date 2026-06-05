#ifndef SteppingAction_h
#define SteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "EventAction.hh"

class G4LogicalVolume;
class G4Step;
class EventAction;

/// Stepping action class

class SteppingAction : public G4UserSteppingAction
{
  public:
    SteppingAction(EventAction* eventAction);
    ~SteppingAction() override = default;

    // method from the base class
    void UserSteppingAction(const G4Step*) override;

  private:
    EventAction* fEventAction = nullptr;
    G4LogicalVolume* fScoringVolume = nullptr;
    G4String volumeName;
};

#endif
