//C code to calculate effective area as a function of thickness
//Include packages
#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>

void CEffectiveArea_root_Thick(){
    //Import file
    TChain *data = new TChain("outTree");
    data->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/build/output.root");

    //Create variables
    Double_t edep;
    Double_t thickness;
    Double_t r_throw = 7;
    Double_t pi = M_PI;
    Double_t A_throw = (pi)*(pow(r_throw,2));

    //Set Edep branch for data TChain
    data->SetBranchAddress("Edep", &edep);

    //Create Energy deposition histogram and data histogram
    TH1D *hEdep = new TH1D("hEdep", "Effective Area vs Thickness; Thickness; Effective Area (cm^2)", 21, -0.5, 20.5);
    TH1D *hTotal = new TH1D("hTotal", "Total; Thickness; Count", 21, -0.5, 20.5);

    //Divide histograms to get effective area data
    data->Project("hEdep", "Thickness", "Edep>0");
    data->Project("hTotal", "Thickness");
    hEdep->Divide(hTotal);
    hEdep->Scale(A_throw);
    hEdep->Draw("HIST L");

    //Write data to a text file
    std::ofstream EffectiveAreaFile("EffectiveArea_NaI_10000keV_Thick.txt");
    for(int i=1; i<=hEdep->GetNbinsX(); ++i) {
        for(int j=1; j<=hEdep->GetNbinsY(); ++j) {
            if(hEdep->GetBinContent(i,j) > 0){
                cout << hEdep->GetXaxis()->GetBinCenter(i) << " " << hEdep->GetBinContent(i,j) << endl;
                EffectiveAreaFile <<  hEdep->GetXaxis()->GetBinCenter(i) << "," << hEdep->GetBinContent(i,j)<<"\n";
            }
        }
    }
    //Close file once done writing
    EffectiveAreaFile.close();
}