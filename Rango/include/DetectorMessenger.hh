#ifndef DetectorMessenger_h
#define DetectorMessenger_h 1

//Include messanger package
#include "G4UImessenger.hh"

//Identify classes used in header
class G4UIdirectory;
class G4UIcmdWithAString;
class G4UIcmdWithADoubleAndUnit;
class G4UIcommand;
class DetectorConstruction; //Links to detector construction

/// Messenger class that defines commands for DetectorConstruction.
///
/// It implements commands:
/// - /Detector/det/setDetMaterial name
/// - /Detector/det/stepMax value unit

class DetectorMessenger : public G4UImessenger
{
  public:
    DetectorMessenger(DetectorConstruction*); //Constructor
    ~DetectorMessenger() override; //Destructor

    void SetNewValue(G4UIcommand*, G4String) override; //Definition to create commands

  private:
    DetectorConstruction* fDetectorConstruction = nullptr; //Pointer for detector construction

    G4UIdirectory* fDirectory = nullptr; //Pointer for directory
    G4UIdirectory* fDetDirectory = nullptr; //Pointer for detector directory 
    G4UIcmdWithAString* fDetMatCmd = nullptr; //Command to change detector material
    G4UIcmdWithAString* fWorldMatCmd = nullptr; //Command to change world material
    G4UIcmdWithADoubleAndUnit* fStepMaxCmd = nullptr; //Command to change maximum step
    G4UIcmdWithAString* fColourCmd = nullptr; //Command to change the color of the detector
};
//Always Include!!
#endif
