#include <TFile.h>
#include <TTree.h>
#include <cmath>
#include <math.h>
#include <iostream>

void CEffectiveArea_root_Thick(){
    TChain *data = new TChain("thickTree");
    data->Add("/home/skyes/Geant4_MSFC/Geant4_Rango/build/thicknessAeff.root");

    Double_t edep;
    Double_t thickness;
    Double_t e_max = 10000;
    Double_t n_total;
    Double_t n_edep;
    Double_t Area;
    Double_t r_throw = 7;
    Double_t pi = M_PI;
    Double_t A_throw = (pi)*(pow(r_throw,2));

    data->SetBranchAddress("Edep", &edep);

    TTree* effectiveArea = data->CopyTree("Edep > 0");

    effectiveArea->SetBranchAddress("Thickness", &thickness);
    effectiveArea->SetBranchAddress("Edep", &edep);

    TH1D *hEdep = new TH1D("hEdep", "Effective Area vs Thickness; Thickness; Effective Area (cm^2)", 21, -0.5, 20.5);
    TH1D *hTotal = new TH1D("hTotal", "Total; Thickness; Count", 21, -0.5, 20.5);

    data->Project("hEdep", "Thickness", "Edep>0");
    data->Project("hTotal", "Thickness");
    hEdep->Divide(hTotal);
    hEdep->Scale(A_throw);
    hEdep->Draw("HIST L");

    std::ofstream EffectiveAreaFile("EffectiveArea_NaI_10000keV_Thick.txt");
    for(int i=1; i<=hEdep->GetNbinsX(); ++i) {
        for(int j=1; j<=hEdep->GetNbinsY(); ++j) {
            if(hEdep->GetBinContent(i,j) > 0){
                cout << hEdep->GetXaxis()->GetBinCenter(i) << " " << hEdep->GetBinContent(i,j) << endl;
                EffectiveAreaFile <<  hEdep->GetXaxis()->GetBinCenter(i) << "," << hEdep->GetBinContent(i,j)<<"\n";
            }
        }
    }
    EffectiveAreaFile.close();
    // for(double j =0; j < e_max; j++){
    //     n_edep=0;
    //     for(int i = 0; i < effectiveArea->GetEntries(); i++){
    //         effectiveArea->GetEntry(i);
    //         if(Thickness == j){
    //             n_edep++;
    //         }
    //         printf("Thickness: %f EDep: %f\n", Thickness, n_edep);
    //         hEdep->Fill(Thickness);
    //     }
    // }
    // auto effA = new TGraph();
    // effA->SetTitle("Effective Area Plot; Thickness; Effective Area");

    // int p = 0;
    // for(Double_t i = 1; i< e_max; i++){
    //     n_edep = 0;
    //     n_total = 0;
    //     for(int j = 0; j< effectiveArea->GetEntries(); j++){
    //         effectiveArea->GetEntry(j);
    //         if(Thickness == i){
    //             n_edep++;
    //         }
    //     }
    //     for(int o= 0; o <data->GetEntries(); o++){
    //         data->GetEntry(o);
    //         if(Thickness == i){
    //             n_total++;
    //         }
    //     }
    //     Area = A_throw*(n_edep/n_total);
    //     printf("Thickness: %f Area: %f\n", i, Area);
    //     effA->SetPoint(p, i, Area);
    //     p++;
    // }
    // effA->Draw();
}