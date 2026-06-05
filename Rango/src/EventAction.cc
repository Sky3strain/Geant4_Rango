//Code to run an event
//Header files
#include "EventAction.hh"
#include "RunAction.hh"

//Packages
#include "G4SystemOfUnits.hh"
#include "G4Event.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

//Include things required for txt file
// static std::ofstream dataFile("output.root");
// static bool first = true;
  
//Create 
EventAction::EventAction(RunAction* runAction) : fRunAction(runAction) {} //Allows EventAction to communicate with RunAction

void EventAction::BeginOfEventAction(const G4Event* event)
{
  fEdep = 0.; //Initial energy deposition
  G4int eventID =event->GetEventID(); //Get the event ID and add 1 so we start from 1 not 0
  G4cout<< "\nEvent#: "<<eventID<<G4endl; //Print the event ID

}

  
void EventAction::EndOfEventAction(const G4Event* event)
{
  fRunAction->AddEdep(fEdep); //From run action get the energy deposited
  G4int eventID =event->GetEventID(); //Get the event ID

  //ste up run manager
  G4RunManager *runManager = G4RunManager::GetRunManager();
  // G4int totalEvent = runManager->GetNumberOfEventsToBeProcessed();

  //Print event data
  if(fEdep == 0)
  {
    G4cout <<"\nEvent"<<eventID<<" Summary: Total deposited energy = "
      <<fEdep / keV <<"keV"<<G4endl;
    G4cout <<"Uh oh that beam missed! :("<< G4endl;
    G4cout << "\n" << G4endl;
  }
  else
  {
    G4cout <<"\nEvent"<<eventID<<" Summary: Total deposited energy = "
      <<fEdep / keV <<"keV"<<G4endl;
    G4cout << "\n" << G4endl;
    //AnalysisManager instance
    auto analysisManager = G4AnalysisManager::Instance();

    //Fill ntuples
    analysisManager->FillH1(0, fEdep);
    analysisManager->FillNtupleDColumn(0, fEdep);
    //To save to text file
    // if (first) {
    //     dataFile << "#,fEdep(keV),x(mm)" << std::endl;
    //     first = false;
    // }
    // dataFile << fEdep/keV << std::endl;
  }
}
