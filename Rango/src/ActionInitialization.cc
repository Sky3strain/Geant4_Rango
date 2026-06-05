//This is where everything from the .hh file is used
//Must always include #include "YourHeader.hh"
#include "ActionInitialization.hh"

//Include other header files that are dependent of Action Initialization
#include "EventAction.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "SteppingAction.hh"

void ActionInitialization::BuildForMaster() const
{
  auto runAction = new RunAction; //Sets up default states required to use RunAction
  SetUserAction(runAction); //Registers a user defined action
}

 
void ActionInitialization::Build() const
{
  SetUserAction(new PrimaryGeneratorAction); //New PGA created a lot so I believe this is why this line is the way it is

  auto runAction = new RunAction; //Sets up default states
  SetUserAction(runAction); //Registers a user defined action

  auto eventAction = new EventAction(runAction); //Sets up default states
  SetUserAction(eventAction); //Registers a user defined action

  SetUserAction(new SteppingAction(eventAction)); //Event logic and stepping logic can now communicate
}
