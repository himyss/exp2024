#include "/home/muzalevskii/work/macro/exp2024/postReco/cuts/create_ID.C"

void create_cuts() {
  
  create_ID();

  TChain *ch = new TChain("tree");
  ch->Add("/mnt/data/exp2024/postReco/data.root");
  ch->Add("/mnt/data/exp2024/postReco/data1.root");
  ch->Add("/mnt/data/exp2024/postReco/data2.root");

  TChain *chSim = new TChain("er");
  chSim->Add("/mnt/data/exp2024/sim/sim_digi.root");
  chSim->Add("/mnt/data/exp2024/sim/sim_digi1.root");
  chSim->Add("/mnt/data/exp2024/sim/sim_digi2.root");

  ch->AddFriend(chSim);

  ch->SetMarkerStyle(6);

  Bool_t beam = 0;
  Bool_t sideID = 0;
  Bool_t cent_ID_single = 1;
  // Bool_t sideID_single = 0;

  if (cent_ID_single) {

    TCanvas *c4 = new TCanvas("c4","title",1800,1000);
    c4->Divide(2,1);

    c4->cd(1);
    ch->Draw("X_C1:X_C2 >> idC_1","",""); 
    ch->SetMarkerColor(kRed);
    ch->Draw("X_C1:X_C2","nh3_ct","same"); 
    ch->SetMarkerColor(kBlue);
    ch->Draw("X_C1:X_C2","nhe3_ct","same");   
    ch->SetMarkerColor(kGreen);
    ch->Draw("X_C1:X_C2","nli6_ct","same");  
    c4->Update();

    c4->cd(2);
    ch->SetMarkerColor(kBlack);
    ch->Draw("X_C1+X_C2:aCsI >> idC_2","",""); 
    ch->SetMarkerColor(kRed);
    ch->Draw("X_C1+X_C2:aCsI","nh3_ct","same"); 
    ch->SetMarkerColor(kBlue);
    ch->Draw("X_C1+X_C2:aCsI","nhe3_ct","same");   
    ch->SetMarkerColor(kGreen);
    ch->Draw("X_C1+X_C2:aCsI","nli6_ct","same");  
    c4->Update();
    cutCsIhe3_ct->Draw("same");
    cutCsIh3_ct->Draw("same");
    cutCsIli6_ct->Draw("same");

  }



}