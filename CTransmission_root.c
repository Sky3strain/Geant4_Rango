#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>

void CTransmission_root(){
    TChain *data = new TChain("transTree");
    data->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/build/transmissionBe1MM.root");

    Double_t energy;
    Int_t counter;

    data->SetBranchAddress("Energy", &energy);
    data->SetBranchAddress("Counter", &counter);

    // TFile* filteredEvents = new TFile("filtered.root", "RECREATE"); 
    TTree* transmission = data->CopyTree("Counter==2");
    // filteredTree->Write();
    // filteredEvents->Close();

    // TChain *transmission = new TChain("tree");
    // transmission->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/filtered.root");

    transmission->SetBranchAddress("Energy", &energy);
    transmission->SetBranchAddress("Counter", &counter);

    TH1D *hTrans = new TH1D("hTrans", "Transmission; Energy; Transmitted Count", 10001, -0.5, 10000.5);
    TH1D *hTotal = new TH1D("hTotal", "Total Energy; Energy; Count", 10001, -0.5, 10000.5);
    for(int all = 0; all < data->GetEntries(); all++){
        data->GetEntry(all);
        if(counter == 1 || counter == 2){
            hTotal->Fill(energy);
        }
    }
    for(int trans = 0; trans < transmission->GetEntries(); trans++){
        transmission->GetEntry(trans);
        hTrans->Fill(energy);
    }
    hTrans->Divide(hTotal);
    hTrans->Draw("HIST L");

    std::ofstream TransmissionFile("Transmission_1-10000keV_Tef0.2MM.txt");
    for(int i=1; i<=hTrans->GetNbinsX(); ++i) {
        for(int j=1; j<=hTrans->GetNbinsY(); ++j) {
            if(hTrans->GetBinContent(i,j) > 0){
                cout << hTrans->GetXaxis()->GetBinCenter(i) << " " << hTrans->GetBinContent(i,j) << endl;
                TransmissionFile <<  hTrans->GetXaxis()->GetBinCenter(i) << "," << hTrans->GetBinContent(i,j)<<"\n";
            }
        }
    }
    TransmissionFile.close();
}

