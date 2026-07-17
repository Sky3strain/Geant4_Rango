//C code to look at 662 keV line 
//Include packages
#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>
#include <TGraph.h>

void C662Kev_OP(){
    //Import file
    TChain *data = new TChain("outTree");
    data->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/build/output.root");

    //Variables
    Int_t photonCount;

    data->SetBranchAddress("PhotonCounter", &photonCount);
    TH1D *hSpectrum = new TH1D("hSpectrum", "34.305 keV Spectrum for optical photon count; Detected Photon; Counts", 100, 0, 2500);
    data->Project("hSpectrum", "PhotonCounter");
    hSpectrum->Draw();
}