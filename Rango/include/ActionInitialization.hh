//Sets up the users action classes
#ifndef ActionInitialization_h
#define ActionInitialization_h 1

//Within the G4VUserActionInitialization class the user initiates
//and registers concrete G4VUserActionInitialization subclass
//this generates the primary particles for each event
#include "G4VUserActionInitialization.hh"

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
#endif
