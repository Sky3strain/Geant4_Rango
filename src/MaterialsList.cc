//Define your materials here :)
//include header files
#include "MaterialsList.hh"

namespace Rango
{
//Set MaterialsList pointer to 0 
//Set instance to 0
MaterialsList* MaterialsList::instance = 0;

//Declare get instance class return the pointer instance
MaterialsList* MaterialsList::GetInstance()
{
   return instance;
}

//MaterialsList constrcutor
MaterialsList::MaterialsList() 
//Define the materials
: NaI(0), CsI(0), Air(0), Vaccum(0), Be(0), Mg(0), Al(0), Teflon(0), CdTe(0), CsI_Na(0), CsI_Tl(0), CeBr3(0), NaI_Tl(0), BGO(0)
{
  if( instance == 0 ){
      instance = this; // give the constructor a pointer to itself
      nist = G4NistManager::Instance(); // also save pointer to NIST materials
   }
   else {
      //Set error 
      G4cout << "\n[!] ERROR: More than one MaterialsList object. [!]" << G4endl << G4endl;
   }
   //Define all materials 
   DefineMaterial("NaI");
   DefineMaterial("CsI");
   DefineMaterial("Air");
   DefineMaterial("Vaccum");
   DefineMaterial("Be");
   DefineMaterial("Mg");
   DefineMaterial("Al");
   DefineMaterial("Teflon");
   DefineMaterial("CdTe");
   DefineMaterial("CsI_Na");
   DefineMaterial("CsI_Tl");
   DefineMaterial("CeBr3");
   DefineMaterial("NaI_Tl");
   DefineMaterial("BGO");
}

//Destructor
MaterialsList::~MaterialsList() 
{
  //delete all materials created 
  delete NaI;
  delete CsI;
  delete Air;
  delete Vaccum;
  delete Be;
  delete Mg;
  delete Al;
  delete Teflon;

  delete CdTe;
  delete CsI_Na;
  delete CsI_Tl;
  delete CeBr3;
  delete NaI_Tl;
  delete BGO;
}

//See if the material exists
G4bool MaterialsList::MaterialExists( G4String sMaterialNameIn )
{
   //See size of material table
   G4int nmat = G4Material::GetMaterialTable()->size();
   //See if pur material matches anything in the table
   for (G4int i=0; i<nmat; ++i) {
      if (sMaterialNameIn == ((*G4Material::GetMaterialTable())[i])->GetName())
         return true;
   }
   //If not return false
   return false;
}

//Define all materials
G4bool MaterialsList::DefineMaterial( G4String sMaterialNameIn )
{
   //Define Sodium Iodide
   G4cout << "Defining " << sMaterialNameIn << " ... ";
   if( sMaterialNameIn == "NaI" ) {
      NaI = nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
      NaI->SetName(sMaterialNameIn);
   }
   //Define Cesium Iodide
   else if( sMaterialNameIn == "CsI" ) {
      CsI = nist->FindOrBuildMaterial("G4_CESIUM_IODIDE");
      CsI->SetName(sMaterialNameIn);
   }
   //Define Air
   else if( sMaterialNameIn == "Air"){
      Air = nist->FindOrBuildMaterial("G4_AIR");
      Air->SetName( sMaterialNameIn);
   }
   //Define space vaccum
   else if( sMaterialNameIn == "Vaccum"){
      Vaccum = nist->FindOrBuildMaterial("G4_Galactic");
      Vaccum->SetName( sMaterialNameIn);
   }
   //Define beryllium
   else if( sMaterialNameIn == "Be"){
      Be = nist->FindOrBuildMaterial("G4_Be");
      Be->SetName( sMaterialNameIn);
   }
   //Define Magnesium 
   else if( sMaterialNameIn == "Mg"){
      Mg = nist->FindOrBuildMaterial("G4_Mg");
      Mg->SetName( sMaterialNameIn);
   }
   //Define Aluminum 
   else if( sMaterialNameIn == "Al"){
      Al = nist->FindOrBuildMaterial("G4_Al");
      Al->SetName( sMaterialNameIn);
   }
   else if( sMaterialNameIn == "Teflon"){
      Teflon = nist->FindOrBuildMaterial("G4_TEFLON");
      Teflon->SetName( sMaterialNameIn);
   }
   else if (sMaterialNameIn == "CdTe") {
      CdTe = new G4Material("CdTe", density=5.85 * g / cm3, numberOfComponents=2);
      CdTe->AddElement(nist->FindOrBuildElement("Cd"), 1);
      CdTe->AddElement(nist->FindOrBuildElement("Te"), 1);
   }
   else if (sMaterialNameIn == "CeBr3") {
      CeBr3 = new G4Material("CeBr3", density=5.10 * g / cm3, numberOfComponents=2);
      CeBr3->AddElement(nist->FindOrBuildElement("Ce"), 1);
      CeBr3->AddElement(nist->FindOrBuildElement("Br"), 3);
   }
   else if (sMaterialNameIn == "NaI_Tl") {
      NaI_Tl = new G4Material("NaI_Tl", density=3.67 * g / cm3, numberOfComponents=2);
      NaI_Tl->AddMaterial(nist->FindOrBuildMaterial("G4_SODIUM_IODIDE"), 99.5 * perCent);
      NaI_Tl->AddMaterial(nist->FindOrBuildMaterial("G4_Tl"), 0.5 * perCent);
   }
   else if (sMaterialNameIn == "CsI_Na") {
      CsI_Na = new G4Material("CsI_Na", density=4.51 * g / cm3, numberOfComponents=2);
      CsI_Na->AddMaterial(nist->FindOrBuildMaterial("G4_CESIUM_IODIDE"), 99.6 * perCent);
      CsI_Na->AddMaterial(nist->FindOrBuildMaterial("G4_Na"), 0.4 * perCent);
   }
   else if (sMaterialNameIn == "CsI_Tl") {
      CsI_Tl = new G4Material("CsI_Tl", density=4.51 * g / cm3, numberOfComponents=2);
      CsI_Tl->AddMaterial(nist->FindOrBuildMaterial("G4_CESIUM_IODIDE"), 99.6 * perCent);
      CsI_Tl->AddMaterial(nist->FindOrBuildMaterial("G4_Tl"), 0.4 * perCent);
   }
   else if (sMaterialNameIn == "BGO") {
      BGO = nist->FindOrBuildMaterial("G4_BGO");
      BGO->SetName(sMaterialNameIn);
   }
  G4cout << "completed" << G4endl;
  return true;
}

G4bool MaterialsList::PrintMaterialTable()
{
   // Print all the materials defined.
   G4cout << G4endl << "The materials defined are : " << G4endl << G4endl;
   G4cout << *(G4Material::GetMaterialTable()) << G4endl;
   return true;
}
}