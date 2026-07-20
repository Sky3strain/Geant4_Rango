//C code to calculate effective area
//Include packages
#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>

void CEffectiveAreaOP_root(){
    //Import data file
    TChain *data = new TChain("outTree");
    data->Add("/home/skyes/Geant4_MSFC/GRango_Data/100000Runs_Log_OP/output.root");

    //Create variables
    Int_t photonCount;
    Double_t energy;
    Double_t r_throw = 3.5;
    Double_t pi = M_PI;
    Double_t A_throw = (pi)*(pow(r_throw,2));

    //Set branch for energy deposition for data TChain
    data->SetBranchAddress("PhotonCounter", &photonCount);

    //Create histograms for energy deposition and data
    TH1D *hPhoton = new TH1D("hPhoton", "Effective Area vs Energy; Energy; Effective Area (cm^2)", 10001, 0.5, 10000.5);
    TH1D *hTotal = new TH1D("hTotal", "Total; Energy; Count", 10001, 0.5, 10000.5);

    //Use histograms to compute effective area
    data->Project("hPhoton", "Energy", "PhotonCounter>500");
    data->Project("hTotal", "Energy");
    hPhoton->Divide(hTotal);
    hPhoton->Scale(A_throw);
    hPhoton->Draw("HIST L");

    //Write effective area data to file
    std::ofstream EffectiveAreaFile("EffectiveArea_NaI_Tl_OP_100000.txt");
    for(int i=1; i<=hPhoton->GetNbinsX(); ++i) {
        for(int j=1; j<=hPhoton->GetNbinsY(); ++j) {
            if(hPhoton->GetBinContent(i,j) > 0){
                cout << hPhoton->GetXaxis()->GetBinCenter(i) << " " << hPhoton->GetBinContent(i,j) << endl;
                EffectiveAreaFile <<  hPhoton->GetXaxis()->GetBinCenter(i) << "," << hPhoton->GetBinContent(i,j)<<"\n";
            }
        }
    }
    //Close file
    EffectiveAreaFile.close();
}