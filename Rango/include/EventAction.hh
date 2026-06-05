#ifndef EventAction_h
#define EventAction_h 1

//Packages used
#include "G4UserEventAction.hh"
#include "globals.hh"

//Create classes
class G4Event;
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

  private:
    RunAction* fRunAction = nullptr; //Pointer for run action
    G4double fEdep = 0.; //Energy deposition variable 
    G4Event* event = nullptr; //Event veriable
};
//Always include
#endif
