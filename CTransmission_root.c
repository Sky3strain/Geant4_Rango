//C code to compute transmission
//Include packages
#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>

void CTransmission_root(){
    //Import data as a TChain
    TChain *data = new TChain("transTree");
    data->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/build/transmissionBe1MM.root");

    //Create variables
    Double_t energy;
    Int_t counter;

    //Create energy and counter branches for data 
    data->SetBranchAddress("Energy", &energy);
    data->SetBranchAddress("Counter", &counter);

    //Create transmission TTree where there is only data where counter==2
    TTree* transmission = data->CopyTree("Counter==2");

    //Set branch addresses for transmission
    transmission->SetBranchAddress("Energy", &energy);
    transmission->SetBranchAddress("Counter", &counter);

    //Create histograms
    TH1D *hTrans = new TH1D("hTrans", "Transmission; Energy; Transmitted Count", 10001, -0.5, 10000.5);
    TH1D *hTotal = new TH1D("hTotal", "Total Energy; Energy; Count", 10001, -0.5, 10000.5);

    //Filter out if counter==0
    for(int all = 0; all < data->GetEntries(); all++){
        data->GetEntry(all);
        if(counter == 1 || counter == 2){
            hTotal->Fill(energy);
        }
    }

    //Only add when the particle is transmitted
    for(int trans = 0; trans < transmission->GetEntries(); trans++){
        transmission->GetEntry(trans);
        hTrans->Fill(energy);
    }

    //Divide histograms 
    hTrans->Divide(hTotal);
    hTrans->Draw("HIST L");

    //Write data to a file
    std::ofstream TransmissionFile("Transmission_1-10000keV_Al2MM.txt");
    for(int i=1; i<=hTrans->GetNbinsX(); ++i) {
        for(int j=1; j<=hTrans->GetNbinsY(); ++j) {
            if(hTrans->GetBinContent(i,j) > 0){
                cout << hTrans->GetXaxis()->GetBinCenter(i) << " " << hTrans->GetBinContent(i,j) << endl;
                TransmissionFile <<  hTrans->GetXaxis()->GetBinCenter(i) << "," << hTrans->GetBinContent(i,j)<<"\n";
            }
        }
    }
    //Close the file
    TransmissionFile.close();
}

