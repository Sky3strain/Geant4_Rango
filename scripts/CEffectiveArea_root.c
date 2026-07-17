//C code to calculate effective area
//Include packages
#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>

void CEffectiveArea_root(){
    //Import data file
    TChain *data = new TChain("outTree");
    data->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/build/output.root");

    //Create variables
    Double_t edep;
    Double_t energy;
    Double_t r_throw = 7;
    Double_t pi = M_PI;
    Double_t A_throw = (pi)*(pow(r_throw,2));

    //Set branch for energy deposition for data TChain
    data->SetBranchAddress("Edep", &edep);

    //Create histograms for energy deposition and data
    TH1D *hEdep = new TH1D("hEdep", "Effective Area vs Energy; Energy; Effective Area (cm^2)", 10001, -0.5, 10000.5);
    TH1D *hTotal = new TH1D("hTotal", "Total; Energy; Count", 10001, -0.5, 10000.5);

    //Use histograms to compute effective area
    data->Project("hEdep", "Energy", "Edep>0");
    data->Project("hTotal", "Energy");
    hEdep->Divide(hTotal);
    hEdep->Scale(A_throw);
    hEdep->Draw("HIST L");

    //Write effective area data to file
    std::ofstream EffectiveAreaFile("EffectiveArea_NaI_Tl_O4.txt");
    for(int i=1; i<=hEdep->GetNbinsX(); ++i) {
        for(int j=1; j<=hEdep->GetNbinsY(); ++j) {
            if(hEdep->GetBinContent(i,j) > 0){
                cout << hEdep->GetXaxis()->GetBinCenter(i) << " " << hEdep->GetBinContent(i,j) << endl;
                EffectiveAreaFile <<  hEdep->GetXaxis()->GetBinCenter(i) << "," << hEdep->GetBinContent(i,j)<<"\n";
            }
        }
    }
    //Close file
    EffectiveAreaFile.close();
}