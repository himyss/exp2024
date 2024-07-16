void zeroVars();

void centID();
void sideID_1();
void sideID_2();
void sideID_3();
void sideID_4();

void neutronID(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco7H(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco6H(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco7He_cent(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco7He_side(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco7He(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco6Li(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco6Lid(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco6Li_exc(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco7Li(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco5He(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco4H_cent(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void reco4H_6He_cent(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);
void recoTetraQFS(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi);

#include "/home/ivan/work/macro/h7_1904/cuts/scripts/create_cuts.C"
#include "/home/ivan/work/macro/h7_1904/cuts/scripts/create_IDs.C"
#include "/home/ivan/work/macro/h7_1904/parallel/postReco/myCuts.C"

#include "/home/ivan/work/macro/exp2024/postReco/data_in.h"
#include "/home/ivan/work/macro/exp2024/postReco/data_out.h"

void post(TString inFileReco,TString inFileCleaned,TString outFile) {
  
  create_IDs();

  // TString inputRecoFile; 
  // inputRecoFile.Form("/mnt/data/exp1904/ERanalysis/reco/h7/h7_ct_%d*.root",nRun);
  
  TChain *chReco = new TChain("er");
  chReco->Add(inFileReco.Data());
  cout << chReco->GetEntries() << endl;

  // TString inputCleanedFile;
  // inputCleanedFile.Form("/mnt/data/exp1904/ERanalysis/cleaned/h7/h7_ct_%d*.root",nRun);
  TChain *chCleaned = new TChain("er");
  chCleaned->Add(inFileCleaned.Data());
  cout << chCleaned->GetEntries() << endl;

  chReco->AddFriend(chCleaned);
  
  TClonesArray *v_track_beam = new TClonesArray("ERBeamDetTrack");
  TClonesArray* v_par_beam = new TClonesArray("ERBeamDetParticle");

  TClonesArray *v_track_cent = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_h3_cent = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_h2_cent = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_he6_cent = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_he4_cent = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray* v_track_t1 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_he4_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h2_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li7_t1 = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray *v_track_t2 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t2 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he4_t2 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t2 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h2_t2 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_t2 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li7_t2 = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray *v_track_t3 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t3 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he4_t3 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t3 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h2_t3 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_t3 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_li7_t3 = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray *v_track_t4 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t4 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he4_t4 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t4 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_h2_t4 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_li6_t4 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_li7_t4 = new TClonesArray("ERTelescopeParticle");  

  TClonesArray *v_track_nd = new TClonesArray("ERNDTrack");
  TClonesArray* v_par_nd = new TClonesArray("ERNDParticle");

  TClonesArray *v_digi_nd = new TClonesArray("ERNDDigi");

  TClonesArray *v_SSD_V_1 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_1 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD_1 = new TClonesArray("ERDigi");

  TClonesArray *v_SSD_V_2 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_2 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD_2 = new TClonesArray("ERDigi");

  TClonesArray *v_SSD_V_3 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_3 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD_3 = new TClonesArray("ERDigi");

  TClonesArray *v_SSD_V_4 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_4 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD_4 = new TClonesArray("ERDigi");

  TClonesArray *v_F5 = new TClonesArray("ERDigi");

  chReco->SetBranchAddress("BeamDetTrack",&v_track_beam);
  chReco->SetBranchAddress("BeamDetParticle.",&v_par_beam);

  // PARTICLE = tritons
  chReco->SetBranchAddress("TelescopeTrack_Central_telescope_DoubleSi_DSD_XY",&v_track_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_XY_1000010020",&v_par_h2_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_XY_1000010030",&v_par_h3_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_XY_1000020040",&v_par_he4_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_XY_1000020060",&v_par_he6_cent);

  // PARTICLE = 3,4He
  chReco->SetBranchAddress("TelescopeTrack_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y",&v_track_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y_1000020030",&v_par_he3_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y_1000020040",&v_par_he4_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y_1000010030",&v_par_h3_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y_1000010020",&v_par_h2_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y_1000030060",&v_par_li6_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_SingleSi_SSD20_1_XTelescope_1_SingleSi_SSD_1_Y_1000030070",&v_par_li7_t1);

  chReco->SetBranchAddress("TelescopeTrack_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y",&v_track_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y_1000020030",&v_par_he3_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y_1000020040",&v_par_he4_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y_1000010030",&v_par_h3_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y_1000010020",&v_par_h2_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y_1000030060",&v_par_li6_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_SingleSi_SSD_2_XTelescope_2_SingleSi_SSD20_2_Y_1000030070",&v_par_li7_t2);

  chReco->SetBranchAddress("TelescopeTrack_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y",&v_track_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y_1000020030",&v_par_he3_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y_1000020040",&v_par_he4_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y_1000010030",&v_par_h3_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y_1000010020",&v_par_h2_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y_1000030060",&v_par_li6_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_SingleSi_SSD20_3_XTelescope_3_SingleSi_SSD_3_Y_1000030070",&v_par_li7_t3);

  chReco->SetBranchAddress("TelescopeTrack_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y",&v_track_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y_1000020030",&v_par_he3_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y_1000020040",&v_par_he4_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y_1000010030",&v_par_h3_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y_1000010020",&v_par_h2_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y_1000030060",&v_par_li6_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_SingleSi_SSD_4_XTelescope_4_SingleSi_SSD20_4_Y_1000030070",&v_par_li7_t4);

  // neutrons
  chReco->SetBranchAddress("NDTrack",&v_track_nd);
  chReco->SetBranchAddress("NDParticle",&v_par_nd);

  chReco->SetBranchAddress("NDDigi",&v_digi_nd);

  // digi
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD20_1_X",&v_SSD20_1);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD_1_Y",&v_SSD_1);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD_V_1_Y",&v_SSD_V_1);  
 
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD20_2_Y",&v_SSD20_2);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD_2_X",&v_SSD_2);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD_V_2_X",&v_SSD_V_2);  

  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD20_3_X",&v_SSD20_3);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD_3_Y",&v_SSD_3);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD_V_3_Y",&v_SSD_V_3);  

  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD20_4_Y",&v_SSD20_4);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD_4_X",&v_SSD_4);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD_V_4_X",&v_SSD_V_4);  

  chReco->SetBranchAddress("BeamDetToFDigi2",&v_F5);  

//------------------------------------------------------------------------------------------------
  // TString outPutFileName;
  // outPutFileName.Form("/mnt/data/exp1904/ERanalysis/postReco/h7/h7_ct_%d_mm.root",nRun);

  TFile *fw = new TFile(outFile.Data(), "RECREATE");
  TTree *tw = new TTree("tree", "data");
 
  tw->Branch("angle_h7_beam.",&angle_h7_beam,"angle_h7_beam/F");
  tw->Branch("angle_he5_beam.",&angle_he5_beam,"angle_he5_beam/F");

  tw->Branch("targetTime.",&targetTime,"targetTime/F");
  tw->Branch("tF5.",&tF5,"tF5/F");

  tw->Branch("aCsI.",&aCsI,"aCsI/F");
  tw->Branch("nCsI.",&nCsI,"nCsI/I");

  tw->Branch("X_C.",&X_C,"X_C/F");
  tw->Branch("nX_C.",&nX_C,"nX_C/I");
  tw->Branch("Y_C.",&Y_C,"Y_C/F");
  tw->Branch("nY_C.",&nY_C,"nY_C/I");
 
  tw->Branch("fXt.",&fXt,"fXt/F");
  tw->Branch("fYt.",&fYt,"fYt/F"); 

  tw->Branch("a20_1.",&a20_1,"a20_1/F");
  tw->Branch("a20_1_un.",&a20_1_un,"a20_1_un/F");
  tw->Branch("n20_1.",&n20_1,"n20_1/I");

  tw->Branch("a1_1_un.",&a1_1_un,"a1_1_un/F");
  tw->Branch("a1_1.",&a1_1,"a1_1/F");
  tw->Branch("n1_1.",&n1_1,"n1_1/I");

  tw->Branch("av_1.",&av_1,"av_1/F");
  tw->Branch("nv_1.",&nv_1,"nv_1/I");

  tw->Branch("a20_2.",&a20_2,"a20_2/F");
  tw->Branch("a20_2_un.",&a20_2_un,"a20_2_un/F");
  tw->Branch("n20_2.",&n20_2,"n20_2/I");

  tw->Branch("a1_2_un.",&a1_2_un,"a1_2_un/F");
  tw->Branch("a1_2.",&a1_2,"a1_2/F");
  tw->Branch("n1_2.",&n1_2,"n1_2/I");

  tw->Branch("av_2.",&av_2,"av_2/F");
  tw->Branch("nv_2.",&nv_2,"nv_2/I");

  tw->Branch("a20_3.",&a20_3,"a20_3/F");
  tw->Branch("a20_3_un.",&a20_3_un,"a20_3_un/F");
  tw->Branch("n20_3.",&n20_3,"n20_3/I");

  tw->Branch("a1_3_un.",&a1_3_un,"a1_3_un/F");
  tw->Branch("a1_3.",&a1_3,"a1_3/F");
  tw->Branch("n1_3.",&n1_3,"n1_3/I");

  tw->Branch("av_3.",&av_3,"av_3/F");
  tw->Branch("nv_3.",&nv_3,"nv_3/I");

  tw->Branch("a20_4.",&a20_4,"a20_4/F");
  tw->Branch("a20_4_un.",&a20_4_un,"a20_4_un/F");
  tw->Branch("n20_4.",&n20_4,"n20_4/I");

  tw->Branch("a1_4_un.",&a1_4_un,"a1_4_un/F");
  tw->Branch("a1_4.",&a1_4,"a1_4/F");
  tw->Branch("n1_4.",&n1_4,"n1_4/I");

  tw->Branch("av_4.",&av_4,"av_4/F");
  tw->Branch("nv_4.",&nv_4,"nv_4/I");

  tw->Branch("SSD_V1",&SSD_V1,"SSD_V1[16]/F");
  tw->Branch("tSSD_V1",&tSSD_V1,"tSSD_V1[16]/F");
  tw->Branch("SSD_V2",&SSD_V2,"SSD_V2[16]/F");
  tw->Branch("tSSD_V2",&tSSD_V2,"tSSD_V2[16]/F");
  tw->Branch("SSD_V3",&SSD_V3,"SSD_V3[16]/F");
  tw->Branch("tSSD_V3",&tSSD_V3,"tSSD_V3[16]/F");
  tw->Branch("SSD_V4",&SSD_V4,"SSD_V4[16]/F");
  tw->Branch("tSSD_V4",&tSSD_V4,"tSSD_V4[16]/F");

  tw->Branch("multv_1.",&multv_1,"multv_1/I");
  tw->Branch("multv_2.",&multv_2,"multv_2/I");
  tw->Branch("multv_3.",&multv_3,"multv_3/I");
  tw->Branch("multv_4.",&multv_4,"multv_4/I");
  tw->Branch("mult_nd.",&mult_nd,"mult_nd/I");

  tw->Branch("flag1.",&flag1,"flag1/I");
  tw->Branch("flag2.",&flag2,"flag2/I");
  tw->Branch("flag3.",&flag3,"flag3/I");
  tw->Branch("flag4.",&flag4,"flag4/I");
  tw->Branch("flagCent.",&flagCent,"flagCent/I");

  tw->Branch("neutron.",&neutron,"neutron/I");
  tw->Branch("gammma.",&gammma,"gammma/I");
  tw->Branch("neutrons.",&neutrons,"neutrons/I");

  tw->Branch("ND_amp",&ND_amp,"ND_amp[32]/F");
  tw->Branch("ND_time",&ND_time,"ND_time[32]/F");
  tw->Branch("ND_tac",&ND_tac,"ND_tac[32]/F");

  tw->Branch("nh3.",&nh3,"nh3/I");
  tw->Branch("nh2.",&nh2,"nh2/I");
  tw->Branch("nhe6.",&nhe6,"nhe6/I");
  tw->Branch("nhe4_cent.",&nhe4_cent,"nhe4_cent/I");

  tw->Branch("nhe3_1.",&nhe3_1,"nhe3_1/I");
  tw->Branch("nhe3_2.",&nhe3_2,"nhe3_2/I");
  tw->Branch("nhe3_3.",&nhe3_3,"nhe3_3/I");
  tw->Branch("nhe3_4.",&nhe3_4,"nhe3_4/I");

  tw->Branch("nhe4_1.",&nhe4_1,"nhe4_1/I");
  tw->Branch("nhe4_2.",&nhe4_2,"nhe4_2/I");
  tw->Branch("nhe4_3.",&nhe4_3,"nhe4_3/I");
  tw->Branch("nhe4_4.",&nhe4_4,"nhe4_4/I"); 

  tw->Branch("nh3_1.",&nh3_1,"nh3_1/I");
  tw->Branch("nh3_2.",&nh3_2,"nh3_2/I");
  tw->Branch("nh3_3.",&nh3_3,"nh3_3/I");
  tw->Branch("nh3_4.",&nh3_4,"nh3_4/I");

  tw->Branch("nh2_1.",&nh2_1,"nh2_1/I");
  tw->Branch("nh2_2.",&nh2_2,"nh2_2/I");
  tw->Branch("nh2_3.",&nh2_3,"nh2_3/I");
  tw->Branch("nh2_4.",&nh2_4,"nh2_4/I");

  tw->Branch("nli6_1.",&nli6_1,"nli6_1/I");
  tw->Branch("nli6_2.",&nli6_2,"nli6_2/I");
  tw->Branch("nli6_3.",&nli6_3,"nli6_3/I");
  tw->Branch("nli6_4.",&nli6_4,"nli6_4/I");

// Lorentz Vectors

  tw->Branch("lv_he8","TLorentzVector",&lv_he8);
  
  tw->Branch("lv_h7","TLorentzVector",&lv_h7);
  tw->Branch("lv_he3","TLorentzVector",&lv_he3);
  tw->Branch("lv_h3","TLorentzVector",&lv_h3);
  tw->Branch("lv_h2","TLorentzVector",&lv_h2);
  tw->Branch("lv_h3_CMH7","TLorentzVector",&lv_h3_CMH7);
  tw->Branch("lv_h7_CMR","TLorentzVector",&lv_h7_CMR);

  tw->Branch("lv_he4","TLorentzVector",&lv_he4);
  tw->Branch("lv_h3_CMH6","TLorentzVector",&lv_h3_CMH6);
  tw->Branch("lv_h6","TLorentzVector",&lv_h6);
  tw->Branch("lv_h6_CMR","TLorentzVector",&lv_h6_CMR);

  tw->Branch("lv_he6","TLorentzVector",&lv_he6);
  tw->Branch("lv_h3_side","TLorentzVector",&lv_h3_side);
  tw->Branch("lv_h2_side","TLorentzVector",&lv_h2_side);

  tw->Branch("lv_n","TLorentzVector",&lv_n);
  tw->Branch("lv_n_CMH7","TLorentzVector",&lv_n_CMH7);
  tw->Branch("lv_n_CMH6","TLorentzVector",&lv_n_CMH6);

  tw->Branch("lv_he7_inv","TLorentzVector",&lv_he7_inv);
  tw->Branch("lv_he7_inv_CMR","TLorentzVector",&lv_he7_inv_CMR);
  tw->Branch("lv_n_CMHe7","TLorentzVector",&lv_n_CMHe7);
  tw->Branch("lv_h3_side_mm","TLorentzVector",&lv_h3_side_mm);

  tw->Branch("lv_he7_mm","TLorentzVector",&lv_he7_mm);
  tw->Branch("lv_he7_mm_CMR","TLorentzVector",&lv_he7_mm_CMR);
  tw->Branch("lv_he6_CMHe7","TLorentzVector",&lv_he6_CMHe7);

  tw->Branch("lv_6li_side","TLorentzVector",&lv_6li_side);
  tw->Branch("lv_4n_mm","TLorentzVector",&lv_4n_mm);
  tw->Branch("lv_4n_mm_CMR","TLorentzVector",&lv_4n_mm_CMR);
  tw->Branch("lv_4n_mm_CM4n","TLorentzVector",&lv_4n_mm_CM4n);
  tw->Branch("lv_4n_mm_CM7H","TLorentzVector",&lv_4n_mm_CM7H);
  tw->Branch("lv_4n_al","TLorentzVector",&lv_4n_al);
  tw->Branch("v_q_4n","TVector3",&v_q_4n);

  tw->Branch("lv_7li_side","TLorentzVector",&lv_7li_side);
  tw->Branch("lv_3n_mm","TLorentzVector",&lv_3n_mm);
  tw->Branch("lv_3n_mm_CMR","TLorentzVector",&lv_3n_mm_CMR);
  tw->Branch("lv_3n_mm_CM6H","TLorentzVector",&lv_3n_mm_CM6H);
 // tw->Branch("lv_3n_mm_CMR","TLorentzVector",&lv_3n_mm_CMR);


  tw->Branch("lv_he5_inv","TLorentzVector",&lv_he5_inv);
  tw->Branch("lv_he5_inv_CMR","TLorentzVector",&lv_he5_inv_CMR);
  tw->Branch("lv_h5_cent_mm","TLorentzVector",&lv_h5_cent_mm);
  tw->Branch("lv_h3_CMH5_cent","TLorentzVector",&lv_h3_CMH5_cent);

  tw->Branch("lv_he7_side","TLorentzVector",&lv_he7_side);
  tw->Branch("lv_he7_side_CMR","TLorentzVector",&lv_he7_side_CMR);
  tw->Branch("lv_he4_CMHe7_side","TLorentzVector",&lv_he4_CMHe7_side);

  tw->Branch("lv_h4_cent","TLorentzVector",&lv_h4_cent);
  tw->Branch("lv_h4_cent_CMR","TLorentzVector",&lv_h4_cent_CMR);
  tw->Branch("lv_h3_CMH4","TLorentzVector",&lv_h3_CMH4);
  
  tw->Branch("lv_h4_inv_cent_CMR","TLorentzVector",&lv_h4_inv_cent_CMR);
  tw->Branch("lv_h4_inv_cent","TLorentzVector",&lv_h4_inv_cent);
  tw->Branch("lv_he6_side_mm","TLorentzVector",&lv_he6_side_mm);
  tw->Branch("lv_6li_inv","TLorentzVector",&lv_6li_inv);
  tw->Branch("lv_6li_inv_CMR","TLorentzVector",&lv_6li_inv_CMR);
  tw->Branch("lv_7li_inv","TLorentzVector",&lv_7li_inv);
  tw->Branch("lv_7li_inv_CMR","TLorentzVector",&lv_7li_inv_CMR);
  tw->Branch("lv_h2_CMH6","TLorentzVector",&lv_h2_CMH6);

  tw->Branch("lv_he3_h3","TLorentzVector",&lv_he3_h3);
  tw->Branch("lv_delta4n","TLorentzVector",&lv_delta4n);
  tw->Branch("lv_he4_cent","TLorentzVector",&lv_he4_cent);

  tw->Branch("v1_1","TVector3",&v1_1);
  tw->Branch("v2_1","TVector3",&v2_1);
  tw->Branch("v1_2","TVector3",&v1_2);
  tw->Branch("v2_2","TVector3",&v2_2);
  tw->Branch("v1_3","TVector3",&v1_3);
  tw->Branch("v2_3","TVector3",&v2_3);
  tw->Branch("v1_4","TVector3",&v1_4);
  tw->Branch("v2_4","TVector3",&v2_4);

// arrays 
  tw->Branch("ND_time",&ND_time,"ND_time[32]/F");
  tw->Branch("ND_amp",&ND_amp,"ND_amp[32]/F");
  tw->Branch("ND_tac",&ND_tac,"ND_tac[32]/F");
  tw->Branch("ND_energy",&ND_energy,"ND_energy[32]/F");
  tw->Branch("ND_energy_CMH7",&ND_energy_CMH7,"ND_energy_CMH7[32]/F");
  tw->Branch("ND_energy_CMH6",&ND_energy_CMH6,"ND_energy_CMH6[32]/F");
  tw->Branch("ND_energy_CMH5",&ND_energy_CMH5,"ND_energy_CMH5[32]/F");
  tw->Branch("ND_energy_CMHe7",&ND_energy_CMHe7,"ND_energy_CMHe7[32]/F");
  tw->Branch("ND_energy_CM4n",&ND_energy_CM4n,"ND_energy_CM4n[32]/F");
  tw->Branch("ND_energy_CM3n",&ND_energy_CM3n,"ND_energy_CM3n[32]/F");
  tw->Branch("ND_energy_CMHe7_side",&ND_energy_CMHe7_side,"ND_energy_CMHe7_side[32]/F");
  tw->Branch("ND_energy_CMH4_cent",&ND_energy_CMH4_cent,"ND_energy_CMH4_cent[32]/F");


//------------------------------------------------------------------------------------------------

  lv_d2.SetXYZT(0.,0.,0.,1875.612);

  for (Int_t nentry=0;nentry<chReco->GetEntries();nentry++) {
  // for (Int_t nentry=0;nentry<10000;nentry++) {
    if (nentry%100000==0) cout << nentry << endl;

    zeroVars();

    chReco->GetEntry(nentry);

    if (v_track_beam->GetEntries()==0 || v_par_beam->GetEntries()==0) continue;
    if (v_F5->GetEntries()==0) continue;

    //------------------------------------------------------------------------------------------------
    lv_he8 = ((ERBeamDetParticle*)v_par_beam->At(0))->GetLVTarget();

    Float_t tmp_energy = lv_he8.T()-lv_he8.Mag();
    tmp_energy = tmp_energy*1.02;
    Float_t tmp_momenrum = sqrt(tmp_energy*tmp_energy + 2*tmp_energy*lv_he8.Mag());
    tmp_momenrum = TMath::Abs(tmp_momenrum);
    lv_he8.SetXYZM(tmp_momenrum*TMath::Sin(lv_he8.Theta())*TMath::Cos(lv_he8.Phi()), tmp_momenrum*TMath::Sin(lv_he8.Theta())*TMath::Sin(lv_he8.Phi()),tmp_momenrum*TMath::Cos(lv_he8.Theta()) ,lv_he8.Mag());

    fXt = ((ERBeamDetTrack*)v_track_beam->At(0))->GetTargetX();
    fYt = ((ERBeamDetTrack*)v_track_beam->At(0))->GetTargetY();
    if ( ((fXt-0.0467)*(fXt-0.0467) + (fYt-0.0026)*(fYt-0.0026))>0.85*0.85 ) continue;
    targetTime = ((ERBeamDetParticle*)v_par_beam->At(0))->time_on_target();
    tF5 = ((ERDigi*)v_F5->At(0))->Time();

    lv_R = lv_he8 + lv_d2;
    //------------------------------------------------------------------------------------------------
    if (v_track_cent->GetEntries()==1 && v_par_h3_cent->GetEntries()==1) {

      X_C = ((ERTelescopeTrack*)v_track_cent->At(0))->GetXEdep();
      Y_C = ((ERTelescopeTrack*)v_track_cent->At(0))->GetYEdep();

      nX_C = ((ERTelescopeTrack*)v_track_cent->At(0))->GetXChannel(); 
      nY_C = ((ERTelescopeTrack*)v_track_cent->At(0))->GetYChannel(); 
      
      aCsI = ((ERTelescopeParticle*)v_par_h3_cent->At(0))->GetCorrectedEdepInThickStation();
      nCsI = ((ERTelescopeParticle*)v_par_h3_cent->At(0))->ChannelOfThickStation();

      if (nCsI>-1 && nCsI<16 && nX_C>-1 && nX_C<32 && nY_C>-1 && nY_C<32) flagCent=1;
      else flagCent=0;

      if (flagCent) centID();
      if (nh3) lv_h3 = ((ERTelescopeParticle*)v_par_h3_cent->At(0))->GetLVInteraction();
      if (nh2) lv_h2 = ((ERTelescopeParticle*)v_par_h2_cent->At(0))->GetLVInteraction();
      if (nhe6) lv_he6 = ((ERTelescopeParticle*)v_par_he6_cent->At(0))->GetLVInteraction();
      if (nhe4_cent && v_par_he4_cent->GetEntries()>0) lv_he4_cent = ((ERTelescopeParticle*)v_par_he4_cent->At(0))->GetLVInteraction();
    }
    //------------------------------------------------------------------------------------------------
    for(Int_t i=0;i<v_SSD_V_1->GetEntries();i++) {
      Int_t numCh_tmp = ((ERDigi*)v_SSD_V_1->At(i))->Channel();
      SSD_V1[numCh_tmp] = ((ERDigi*)v_SSD_V_1->At(i))->Edep();
      tSSD_V1[numCh_tmp] = ((ERDigi*)v_SSD_V_1->At(i))->Time();
      if (SSD_V1[numCh_tmp]>0) multv_1++;
      av_1 = SSD_V1[numCh_tmp];
    }

    if (v_track_t1->GetEntries()==1 && v_par_he3_t1->GetEntries()==1) {

      a20_1 = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->GetCorrectedEdepInThinStation();
      a1_1 = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->GetCorrectedEdepInThickStation();
      a20_1_un = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->GetEdepInThinStation();
      a1_1_un = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->GetEdepInThickStation();

      n20_1 = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->ChannelOfThinStation();
      n1_1 = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->ChannelOfThickStation();

      if (n20_1>-1 && n20_1<16 && n1_1>-1 && n1_1<16) flag1=1;
      else flag1=0;

      v1_1 = ((ERTelescopeTrack*)v_track_t1->At(0))->GetXStationLocalVertex();
      Double_t vertex1 = ((ERTelescopeTrack*)v_track_t1->At(0))->GetXStationLocalVertex().Y();

      if (flag1) sideID_1();
      if (nh2_1 && v_par_h2_t1->GetEntries()>0) lv_h2_side = ((ERTelescopeParticle*)v_par_h2_t1->At(0))->GetLVInteraction();
      if (nh3_1) lv_h3_side = ((ERTelescopeParticle*)v_par_h3_t1->At(0))->GetLVInteraction();
      if (nhe3_1) lv_he3 = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->GetLVInteraction();
      if (nhe4_1) lv_he4 = ((ERTelescopeParticle*)v_par_he4_t1->At(0))->GetLVInteraction();
      if (nli6_1) lv_6li_side = ((ERTelescopeParticle*)v_par_li6_t1->At(0))->GetLVInteraction();
      if (nli7_1 && v_par_li7_t1->GetEntries()>0) lv_7li_side = ((ERTelescopeParticle*)v_par_li7_t1->At(0))->GetLVInteraction();
    }

    for(Int_t i=0;i<v_SSD_V_2->GetEntries();i++) {
      Int_t numCh_tmp = ((ERDigi*)v_SSD_V_2->At(i))->Channel();
      SSD_V2[numCh_tmp] = ((ERDigi*)v_SSD_V_2->At(i))->Edep();
      tSSD_V2[numCh_tmp] = ((ERDigi*)v_SSD_V_2->At(i))->Time();
      if (SSD_V2[numCh_tmp]>0) multv_2++;
      av_2 = SSD_V2[numCh_tmp];
    }
    if (v_track_t2->GetEntries()==1 && v_par_he3_t2->GetEntries()==1) {

      a20_2 = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->GetCorrectedEdepInThinStation();
      a1_2 = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->GetCorrectedEdepInThickStation();
      a20_2_un = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->GetEdepInThinStation();
      a1_2_un = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->GetEdepInThickStation();

      n20_2 = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->ChannelOfThinStation();
      n1_2 = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->ChannelOfThickStation();

      if (n20_2>-1 && n20_2<16 && n1_2>-1 && n1_2<16) flag2=1;
      else flag2=0;

      v1_2 = ((ERTelescopeTrack*)v_track_t2->At(0))->GetYStationLocalVertex();
      Double_t vertex2 = ((ERTelescopeTrack*)v_track_t2->At(0))->GetYStationLocalVertex().Y(); 

      if (flag2) sideID_2();
      if (nh2_2) lv_h2_side = ((ERTelescopeParticle*)v_par_h2_t2->At(0))->GetLVInteraction();
      if (nh3_2) lv_h3_side = ((ERTelescopeParticle*)v_par_h3_t2->At(0))->GetLVInteraction();
      if (nhe3_2) lv_he3 = ((ERTelescopeParticle*)v_par_he3_t2->At(0))->GetLVInteraction();
      if (nhe4_2) lv_he4 = ((ERTelescopeParticle*)v_par_he4_t2->At(0))->GetLVInteraction();
      if (nli6_2) lv_6li_side = ((ERTelescopeParticle*)v_par_li6_t2->At(0))->GetLVInteraction();
      if (nli7_2) lv_7li_side = ((ERTelescopeParticle*)v_par_li7_t2->At(0))->GetLVInteraction();
    }

    for(Int_t i=0;i<v_SSD_V_3->GetEntries();i++) {
      Int_t numCh_tmp = ((ERDigi*)v_SSD_V_3->At(i))->Channel();
      SSD_V3[numCh_tmp] = ((ERDigi*)v_SSD_V_3->At(i))->Edep();
      tSSD_V3[numCh_tmp] = ((ERDigi*)v_SSD_V_3->At(i))->Time();
      if (SSD_V3[numCh_tmp]>0) multv_3++;
      av_3 = SSD_V3[numCh_tmp];
    }
    if (v_track_t3->GetEntries()==1 && v_par_he3_t3->GetEntries()==1) {

      a20_3 = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->GetCorrectedEdepInThinStation();
      a1_3 = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->GetCorrectedEdepInThickStation();
      a20_3_un = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->GetEdepInThinStation();
      a1_3_un = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->GetEdepInThickStation();

      n20_3 = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->ChannelOfThinStation();
      n1_3 = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->ChannelOfThickStation();

      if (n20_3>-1 && n20_3<16 && n1_3>-1 && n1_3<16) flag3=1;
      else flag3=0;

      v1_3 = ((ERTelescopeTrack*)v_track_t3->At(0))->GetXStationLocalVertex();
      Double_t vertex3 = ((ERTelescopeTrack*)v_track_t3->At(0))->GetXStationLocalVertex().Y();

      if (flag3) sideID_3();
      if (nh2_3) lv_h2_side = ((ERTelescopeParticle*)v_par_h2_t3->At(0))->GetLVInteraction();
      if (nh3_3) lv_h3_side = ((ERTelescopeParticle*)v_par_h3_t3->At(0))->GetLVInteraction();
      if (nhe3_3) lv_he3 = ((ERTelescopeParticle*)v_par_he3_t3->At(0))->GetLVInteraction();
      if (nhe4_3) lv_he4 = ((ERTelescopeParticle*)v_par_he4_t3->At(0))->GetLVInteraction();
      if (nli6_3) lv_6li_side = ((ERTelescopeParticle*)v_par_li6_t3->At(0))->GetLVInteraction();
      if (nli7_3) lv_7li_side = ((ERTelescopeParticle*)v_par_li7_t3->At(0))->GetLVInteraction();
    }    

    for(Int_t i=0;i<v_SSD_V_4->GetEntries();i++) {
      Int_t numCh_tmp = ((ERDigi*)v_SSD_V_4->At(i))->Channel();
      SSD_V4[numCh_tmp] = ((ERDigi*)v_SSD_V_4->At(i))->Edep();
      tSSD_V4[numCh_tmp] = ((ERDigi*)v_SSD_V_4->At(i))->Time();
      if (SSD_V4[numCh_tmp]>0) multv_4++;
      av_4 = SSD_V4[numCh_tmp];
    }    
    if (v_track_t4->GetEntries()==1 && v_par_he3_t4->GetEntries()==1) {

      a20_4 = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->GetCorrectedEdepInThinStation();
      a1_4 = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->GetCorrectedEdepInThickStation();
      a20_4_un = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->GetEdepInThinStation();
      a1_4_un = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->GetEdepInThickStation();

      n20_4 = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->ChannelOfThinStation();
      n1_4 = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->ChannelOfThickStation();

      if (n20_4>-1 && n20_4<16 && n1_4>-1 && n1_4<16) flag4=1;
      else flag4=0;

      v1_4 = ((ERTelescopeTrack*)v_track_t4->At(0))->GetYStationLocalVertex();
      Double_t vertex4 = ((ERTelescopeTrack*)v_track_t4->At(0))->GetYStationLocalVertex().Y();

      if (flag4) sideID_4();
      if (nh2_4) lv_h2_side = ((ERTelescopeParticle*)v_par_h2_t4->At(0))->GetLVInteraction();
      if (nh3_4) lv_h3_side = ((ERTelescopeParticle*)v_par_h3_t4->At(0))->GetLVInteraction();
      if (nhe3_4) lv_he3 = ((ERTelescopeParticle*)v_par_he3_t4->At(0))->GetLVInteraction();
      if (nhe4_4) lv_he4 = ((ERTelescopeParticle*)v_par_he4_t4->At(0))->GetLVInteraction();
      if (nli6_4) lv_6li_side = ((ERTelescopeParticle*)v_par_li6_t4->At(0))->GetLVInteraction();
      if (nli7_4) lv_7li_side = ((ERTelescopeParticle*)v_par_li7_t4->At(0))->GetLVInteraction();
    }    
    //------------------------------------------------------------------------------------------------
    if (v_track_nd->GetEntries()>0 && v_track_nd->GetEntries()==v_digi_nd->GetEntries()) {
      mult_nd = v_digi_nd->GetEntries();
      for (Int_t i=0;i<v_digi_nd->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi_nd->At(i))->Channel();
        ND_time[tmp_chNum] = ((ERNDDigi*)v_digi_nd->At(i))->Time();
        ND_amp[tmp_chNum] = ((ERNDDigi*)v_digi_nd->At(i))->Edep();
        ND_tac[tmp_chNum] = ((ERNDDigi*)v_digi_nd->At(i))->TAC();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par_nd->At(i))->LV();
        ND_energy[tmp_chNum] = lv_tmp.T()-lv_tmp.Mag();        
      }
      neutronID(v_track_nd,v_par_nd,v_digi_nd);
    }
    //------------------------------------------------------------------------------------------------

    if (nh3 && ( nhe3_1 || nhe3_2 || nhe3_3 || nhe3_4) ) { // reco 7H
      reco7H(v_track_nd,v_par_nd,v_digi_nd);
      angle_h7_beam = lv_h7.Angle(lv_he8.Vect())*TMath::RadToDeg();
    }

    if (nh3 && ( nhe4_1 || nhe4_2 || nhe4_3 || nhe4_4) ) { // reco 7H
      reco6H(v_track_nd,v_par_nd,v_digi_nd);
      reco5He(v_track_nd,v_par_nd,v_digi_nd);
      reco7He_side(v_track_nd, v_par_nd, v_digi_nd);
      angle_he5_beam = lv_he5_inv.Angle(lv_he8.Vect())*TMath::RadToDeg();
    }

    if (nh2 && ( nhe4_1 || nhe4_2 || nhe4_3 || nhe4_4) ) { // reco 7H
      reco6Lid(v_track_nd,v_par_nd,v_digi_nd);
    }

    if (nhe6 && neutrons==1) {
      reco7He_cent(v_track_nd, v_par_nd, v_digi_nd);
    }

    if (nhe6) {
      reco4H_cent(v_track_nd, v_par_nd, v_digi_nd);
    }

    if (nh3) {
      reco4H_6He_cent(v_track_nd, v_par_nd, v_digi_nd);
    }

    if ( nh3_1 || nh3_2 || nh3_3 || nh3_4 ) { // reco 7H
      reco7He(v_track_nd,v_par_nd,v_digi_nd);
    }

    if ( nli6_1 || nli6_2 || nli6_3 || nli6_4 ) { // reco 7H
      reco6Li(v_track_nd,v_par_nd,v_digi_nd);
    }

    if ( (nh2_1 || nh2_2 || nh2_3 || nh2_4) && (nhe4_1 || nhe4_2 || nhe4_3 || nhe4_4) ) { 
      reco6Li_exc(v_track_nd,v_par_nd,v_digi_nd);
    }

    if ( nli7_1 || nli7_2 || nli7_3 || nli7_4 ) { 
      reco7Li(v_track_nd,v_par_nd,v_digi_nd);
    }

    if (nhe4_cent && (nh2_1 || nh2_2 || nh2_3 || nh2_4)) {
      recoTetraQFS(v_track_nd,v_par_nd,v_digi_nd);
    }

    tw->Fill();
  }
  fw->cd();
  tw->Write();
  fw->Close();

  return;

}

void centID() {

  std::map<ushort, ushort> csiMapping = {
      {0, 15},
      {1, 11},
      {2, 7},
      {3, 3},
      {4, 14},
      {5, 10},
      {6, 6},
      {7, 2},
      {8, 13},
      {9, 9},
      {10, 5},
      {11, 1},
      {12, 12},
      {13, 8},
      {14, 4},
      {15, 0}
  };

  const ushort numCh_tmp = csiMapping[nCsI];

  if(cut2h[numCh_tmp]->IsInside(aCsI, X_C)) {
    nh2 = 1;
  }
  else {
    nh2 = 0;
  }

  if(cut3h[numCh_tmp]->IsInside(aCsI, X_C)) {
    nh3 = 1;
  }
  else {
    nh3 = 0;
  }

  if(cut6he[nCsI]->IsInside(aCsI, X_C)) {
    nhe6 = 1;
  }
  else {
    nhe6 = 0;
  }

  if(cut4he_cent[nCsI]->IsInside(aCsI, X_C)) {
    nhe4_cent = 1;
  }
  else {
    nhe4_cent = 0;
  }

  return;
}

void sideID_1() {

    std::map<ushort, ushort> inverse16Mapping = {
        {0, 15},
        {1, 14},
        {2, 13},
        {3, 12},
        {4, 11},
        {5, 10},
        {6, 9},
        {7, 8},
        {8, 7},
        {9, 6},
        {10, 5},
        {11, 4},
        {12, 3},
        {13, 2},
        {14, 1},
        {15, 0}
    };

  const ushort numCh_tmp = inverse16Mapping[n20_1];
  if(cuthe3_1_er_new[n20_1]->IsInside(a1_1_un+a20_1_un, a20_1)) {
    nhe3_1 = 1;
    return;
  }
  if(cuthe4_1_er_new[n20_1]->IsInside(a1_1_un+a20_1_un, a20_1)) {
    nhe4_1 = 1;
    return;     
  }
  if(cut3h_er_side_1[n20_1]->IsInside(a1_1_un+a20_1_un, a20_1)) {
    nh3_1 = 1;
    return;     
  }

  if(li_6Li_side1->IsInside(a1_1_un+a20_1_un, a20_1)) {
    nli6_1 = 1;
    return;     
  }

  if(li_7Li_side1[n20_1]->IsInside(a1_1_un+a20_1_un, a20_1)) {
    nli7_1 = 1;
    return;     
  }

  if (cut2h_er_side_1[n20_1]->IsInside(a1_1_un+a20_1_un, a20_1)) {
    nh2_1 = 1;
    return;  
  }

  // if (nh2_1) lv_h2_side = ((ERTelescopeParticle*)v_par_h2_t1->At(0))->GetLVInteraction();
  // if (nh3_1) lv_h3_side = ((ERTelescopeParticle*)v_par_h3_t1->At(0))->GetLVInteraction();
  // if (nhe3_1) lv_he3 = ((ERTelescopeParticle*)v_par_he3_t1->At(0))->GetLVInteraction();
  // if (nhe4_1) lv_he4 = ((ERTelescopeParticle*)v_par_he4_t1->At(0))->GetLVInteraction();
  // if (nli6_1) lv_6li_side = ((ERTelescopeParticle*)v_par_li6_t1->At(0))->GetLVInteraction();
  // if (nli7_1) lv_7li_side = ((ERTelescopeParticle*)v_par_li7_t1->At(0))->GetLVInteraction();

  return; 
}

void sideID_2() {

  std::map<ushort, ushort> inverse16Mapping = {
      {0, 15},
      {1, 14},
      {2, 13},
      {3, 12},
      {4, 11},
      {5, 10},
      {6, 9},
      {7, 8},
      {8, 7},
      {9, 6},
      {10, 5},
      {11, 4},
      {12, 3},
      {13, 2},
      {14, 1},
      {15, 0}
  };

  const ushort numCh_tmp = inverse16Mapping[n20_2];
  if(cuthe3_2_er_new[n20_2]->IsInside(a1_2_un+a20_2_un, a20_2)) {
    nhe3_2 = 1;
    return;
  }
  if(cuthe4_2_er_new[n20_2]->IsInside(a1_2_un+a20_2_un, a20_2)) {
    nhe4_2 = 1;
    return;
  }
  if(cut3h_er_side_2[n20_2]->IsInside(a1_2_un+a20_2_un, a20_2)) {
    nh3_2 = 1;
    return;
  }
  if(li_6Li_side2->IsInside(a1_2_un+a20_2_un, a20_2)) {
    nli6_2 = 1;
    return;
  }  
  if(li_7Li_side2[n20_2]->IsInside(a1_2_un+a20_2_un, a20_2)) {
    nli7_2 = 1;
    return;
  }
  if (cut2h_er_side_2[n20_2]->IsInside(a1_2_un+a20_2_un, a20_2)) {
    nh2_2 = 1;
    return;  
  }

  return;
}

void sideID_3() {
  if(cuthe3_3_er_new[n20_3]->IsInside(a1_3_un+a20_3_un, a20_3)) {
    nhe3_3 = 1;
    return;
  }
  if(cuthe4_3_er_new[n20_3]->IsInside(a1_3_un+a20_3_un, a20_3)) {
    nhe4_3 = 1;
    return;
  }
  if(cut3h_er_side_3[n20_3]->IsInside(a1_3_un+a20_3_un, a20_3)) {
    nh3_3 = 1;
    return;
  } 
  if(li_6Li_side3->IsInside(a1_3_un+a20_3_un, a20_3)) {
    nli6_3 = 1;
    return;
  } 
  if(li_7Li_side3[n20_3]->IsInside(a1_3_un+a20_3_un, a20_3)) {
    nli7_3 = 1;
    return;
  }   
  if (cut2h_er_side_3[n20_3]->IsInside(a1_3_un+a20_3_un, a20_3)) {
    nh2_3 = 1;
    return;  
  }

  return;
}

void sideID_4() {

  if(cuthe3_4_er_new[n20_4]->IsInside(a1_4_un+a20_4_un, a20_4)) {
    nhe3_4 = 1;
    return;
  }
  if(cuthe4_4_er_new[n20_4]->IsInside(a1_4_un+a20_4_un, a20_4)) {
    nhe4_4 = 1;
    return;
  }
  if(cut3h_er_side_4[n20_4]->IsInside(a1_4_un+a20_4_un, a20_4)) {
    nh3_4 = 1;
    return;
  }  
  if(li_6Li_side4->IsInside(a1_4_un+a20_4_un, a20_4)) {
    nli6_4 = 1;
    return;
  }  
  if(li_7Li_side4[n20_4]->IsInside(a1_4_un+a20_4_un, a20_4)) {
    nli7_4 = 1;
    return;
  }   
  if (cut2h_er_side_4[n20_4]->IsInside(a1_4_un+a20_4_un, a20_4)) {
    nh2_4 = 1;
    return;  
  }  

  return;  
}

void neutronID(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  for (Int_t i=0;i<32;i++) {
    if(cutNeutron->IsInside(ND_amp[i], ND_tac[i])) {
      neutron++;
    } 
    if(cutNeutrons[i]->IsInside(ND_amp[i], ND_tac[i])) {
      neutrons++;
    }     
    if(cutGamma->IsInside(ND_amp[i], ND_tac[i])) {
      gammma++;
    }         
  }

}

void reco7H(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_he3_h3 = lv_he3-lv_h3;

  lv_h7 = lv_he8 + lv_d2 + (-lv_he3);

  lv_h7_CMR = lv_h7;
  TVector3 bVect_R = lv_R.BoostVector();
  lv_h7_CMR.Boost(-bVect_R);

  TVector3 bVect_7H = lv_h7.BoostVector();

  lv_h3_CMH7 = lv_h3;
  lv_h3_CMH7.Boost(-bVect_7H);

  lv_4n_mm = lv_he8 + lv_d2 + (-lv_he3) + (-lv_h3);
  lv_4n_mm_CM7H = lv_4n_mm;
  lv_4n_mm_CM7H.Boost(-bVect_7H);
  TVector3 bVect_4n = lv_4n_mm.BoostVector();
 
  lv_4n_al = lv_4n_mm;
  TVector3 bVect_beam = lv_he8.BoostVector();
  lv_4n_al.Boost(-bVect_beam);

  lv_6li_inv = lv_h3 + lv_he3;
  lv_6li_inv_CMR = lv_6li_inv;
  lv_6li_inv_CMR.Boost(-bVect_R);

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CMH7 = lv_tmp;
        TLorentzVector lv_tmp_CM4n = lv_tmp;
        lv_tmp_CMH7.Boost(-bVect_7H);
        lv_tmp_CM4n.Boost(-bVect_4n);
        ND_energy_CMH7[tmp_chNum] = lv_tmp_CMH7.T()-lv_tmp_CMH7.Mag();
        ND_energy_CM4n[tmp_chNum] = lv_tmp_CM4n.T()-lv_tmp_CM4n.Mag();
    }
  }

  TLorentzVector lv_beam4n;
  Float_t mass = lv_4n_mm.Mag();
  Float_t phi = lv_he8.Phi();
  Float_t theta = lv_he8.Theta();
  Float_t ratioM = lv_4n_mm.Mag()/lv_he8.Mag();
  lv_beam4n.SetXYZM(ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Cos(phi), ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Sin(phi), ratioM*lv_he8.P()*TMath::Cos(theta) ,mass);

  lv_delta4n = lv_4n_mm - lv_beam4n;

}

void reco6H(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {
//here
  
  TVector3 bVect_R = lv_R.BoostVector();
  lv_7li_inv = lv_h3 + lv_he4;
  lv_7li_inv_CMR = lv_7li_inv;
  lv_7li_inv_CMR.Boost(-bVect_R);

  lv_h6 = lv_he8 + lv_d2 + (-lv_he4);

  lv_h6_CMR = lv_h6; 
  lv_h6_CMR.Boost(-bVect_R);

  TVector3 bVect_6H = lv_h6.BoostVector();
  lv_h3_CMH6 = lv_h3;
  lv_h3_CMH6.Boost(-bVect_6H);

  lv_3n_mm = lv_he8 + lv_d2 + (-lv_he4) + (-lv_h3);
  lv_3n_mm_CM6H = lv_3n_mm;
  lv_3n_mm_CM6H.Boost(-bVect_6H);

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CMH6 = lv_tmp;
        lv_tmp_CMH6.Boost(-bVect_6H);
        ND_energy_CMH6[tmp_chNum] = lv_tmp_CMH6.T()-lv_tmp_CMH6.Mag();
    }
  }

}

void reco5He(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  for (Int_t i=0;i<v_digi->GetEntries();i++) {
    Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();
    if(v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
      TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
      lv_he5_inv = lv_he4 + lv_tmp;

      lv_he5_inv_CMR = lv_he5_inv;
      TVector3 bVect_R = lv_R.BoostVector();
      lv_he5_inv_CMR.Boost(-bVect_R);

      lv_h5_cent_mm = lv_he8 + lv_d2 + (-lv_he5_inv);

      TVector3 bVect_5H_cent = lv_h5_cent_mm.BoostVector();
      lv_h3_CMH5_cent = lv_h3;
      lv_h3_CMH5_cent.Boost(-bVect_5H_cent); 

      for (Int_t i=0;i<v_track->GetEntries();i++) {
          Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

          TLorentzVector lv_tmp1 = ((ERNDParticle*)v_par->At(i))->LV();
          TLorentzVector lv_tmp_CMH5 = lv_tmp1;
          lv_tmp_CMH5.Boost(-bVect_5H_cent);
          ND_energy_CMH5[tmp_chNum] = lv_tmp_CMH5.T()-lv_tmp_CMH5.Mag();
      }

    }
  }

}

void reco4H_cent(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

   lv_h4_cent = lv_he8 + lv_d2 + (-lv_he6);

   lv_h4_cent_CMR = lv_h4_cent;
   TVector3 bVect_R = lv_R.BoostVector();
   lv_h4_cent_CMR.Boost(-bVect_R);

   TVector3 bVect_4H = lv_h4_cent.BoostVector();

   if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CMH4_cent = lv_tmp;
        lv_tmp_CMH4_cent.Boost(-bVect_4H);
        ND_energy_CMH4_cent[tmp_chNum] = lv_tmp_CMH4_cent.T()-lv_tmp_CMH4_cent.Mag();
    }
   }

   if ( (nh3_1 && flag1) || (nh3_2 && flag2) || (nh3_3 && flag3) || (nh3_4 && flag4)) {
      lv_h3_CMH4 = lv_h3_side;
      lv_h3_CMH4.Boost(-bVect_4H);
   }

}

void reco4H_6He_cent(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  for (Int_t i=0;i<v_digi->GetEntries();i++) {
      Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();
      if(v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        lv_h4_inv_cent = lv_h3 + lv_tmp;

        lv_he6_side_mm = lv_he8 + lv_d2 + (-lv_h4_inv_cent);

        lv_h4_inv_cent_CMR = lv_h4_inv_cent;
        TVector3 bVect_R = lv_R.BoostVector();
        lv_h4_inv_cent_CMR.Boost(-bVect_R);          
      }
  }

}

void reco7He_side(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_he7_side = lv_he8 + lv_d2 + (-lv_h3);

  lv_he7_side_CMR = lv_he7_side;
  TVector3 bVect_R = lv_R.BoostVector();
  lv_he7_side_CMR.Boost(-bVect_R);

  TVector3 bVect_7He_side = lv_he7_side.BoostVector();
  lv_he4_CMHe7_side = lv_he4;
  lv_he4_CMHe7_side.Boost(-bVect_7He_side);          

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CMHe7_side = lv_tmp;
        lv_tmp_CMHe7_side.Boost(-bVect_7He_side);
        ND_energy_CMHe7_side[tmp_chNum] = lv_tmp_CMHe7_side.T()-lv_tmp_CMHe7_side.Mag();
    }
  }

}

void reco7He_cent(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  for (Int_t i=0;i<v_digi->GetEntries();i++) {
      Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();
      if(v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        lv_he7_inv = lv_he6 + lv_tmp;

        lv_h3_side_mm = lv_he8 + lv_d2 + (-lv_he7_inv);

        TVector3 bVect_7He = lv_he7_inv.BoostVector();
        lv_n_CMHe7 = lv_tmp; 
        lv_n_CMHe7.Boost(-bVect_7He);    

        lv_he7_inv_CMR = lv_he7_inv;
        TVector3 bVect_R = lv_R.BoostVector();
        lv_he7_inv_CMR.Boost(-bVect_R);          
      }
  }

}

void reco7He(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_he7_mm = lv_he8 + lv_d2 + (-lv_h3_side);

  lv_he7_mm_CMR = lv_he7_mm;
  TVector3 bVect_R = lv_R.BoostVector();  
  lv_he7_mm_CMR.Boost(-bVect_R);

  TVector3 bVect_7He = lv_he7_mm.BoostVector();
  if (nhe6) {
    lv_he6_CMHe7 = lv_he6;
    lv_he6_CMHe7.Boost(-bVect_7He);
  }

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CMHe7 = lv_tmp;
        lv_tmp_CMHe7.Boost(-bVect_7He);
        ND_energy_CMHe7[tmp_chNum] = lv_tmp_CMHe7.T()-lv_tmp_CMHe7.Mag();
    }
  }

}

void reco6Li(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  Float_t tmp_energy = lv_6li_side.T()-lv_6li_side.Mag();
  mom_6li = sqrt(tmp_energy*tmp_energy + 2*tmp_energy*lv_6li_side.Mag());

  lv_4n_mm = lv_he8 + lv_d2 + (-lv_6li_side);

  // transfered momentum to 4n
  TVector3 tmp_v_in = lv_he8.Vect();
  tmp_v_in = tmp_v_in*(lv_4n_mm.Mag()/lv_he8.Mag());
  TVector3 tmp_v_out = lv_4n_mm.Vect();
  v_q_4n = tmp_v_out-tmp_v_in;

  TVector3 bVect_4n = lv_4n_mm.BoostVector();

  lv_4n_mm_CM4n = lv_4n_mm;
  lv_4n_mm_CM4n.Boost(-bVect_4n);

  lv_4n_mm_CMR = lv_4n_mm;
  TVector3 bVect_R = lv_R.BoostVector();  
  lv_4n_mm_CMR.Boost(-bVect_R);

  lv_4n_al = lv_4n_mm;
  TVector3 bVect_beam = lv_he8.BoostVector();
  lv_4n_al.Boost(-bVect_beam);

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CM4n = lv_tmp;
        lv_tmp_CM4n.Boost(-bVect_4n);
        ND_energy_CM4n[tmp_chNum] = lv_tmp_CM4n.T()-lv_tmp_CM4n.Mag();

    }
  }


  Float_t theta,phi;
  theta = lv_6li_side.Theta();
  phi = lv_6li_side.Phi();
  Float_t tmp_mom = mom_6li*lv_he3.Mag()/lv_6li_side.Mag();
  lv_he3_li6.SetXYZM(tmp_mom*TMath::Sin(theta)*TMath::Cos(phi), tmp_mom*TMath::Sin(theta)*TMath::Sin(phi), tmp_mom*TMath::Cos(theta) ,lv_he3.Mag());
  lv_h7 = lv_d2 + lv_he8 + (-lv_he3_li6);

  TLorentzVector lv_beam4n;
  Float_t mass = lv_4n_mm.Mag();
  phi = lv_he8.Phi();
  theta = lv_he8.Theta();
  Float_t ratioM = lv_4n_mm.Mag()/lv_he8.Mag();
  lv_beam4n.SetXYZM(ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Cos(phi), ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Sin(phi), ratioM*lv_he8.P()*TMath::Cos(theta) ,mass);

  lv_delta4n = lv_4n_mm - lv_beam4n;

}

void reco6Lid(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_h6 = lv_he8 + lv_d2 + (-lv_he4);

  TVector3 bVect_6H = lv_h6.BoostVector();
  lv_h2_CMH6 = lv_h2;
  lv_h2_CMH6.Boost(-bVect_6H);


  lv_4n_mm = lv_he8 + lv_d2 + (-lv_he4) + (-lv_h2);
  TVector3 bVect_4n = lv_4n_mm.BoostVector();

  lv_6li_inv = lv_h2 + lv_he4;

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CM4n = lv_tmp;
        lv_tmp_CM4n.Boost(-bVect_4n);
        ND_energy_CM4n[tmp_chNum] = lv_tmp_CM4n.T()-lv_tmp_CM4n.Mag();
    }
  }

  TLorentzVector lv_beam4n;
  Float_t mass = lv_4n_mm.Mag();
  Float_t phi = lv_he8.Phi();
  Float_t theta = lv_he8.Theta();
  Float_t ratioM = lv_4n_mm.Mag()/lv_he8.Mag();
  lv_beam4n.SetXYZM(ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Cos(phi), ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Sin(phi), ratioM*lv_he8.P()*TMath::Cos(theta) ,mass);

  lv_delta4n = lv_4n_mm - lv_beam4n;

}

void reco6Li_exc(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_6li_side = lv_h2_side + lv_he4;

  lv_4n_mm = lv_he8 + lv_d2 + (-lv_6li_side);

  // transfered momentum to 4n
  TVector3 tmp_v_in = lv_he8.Vect();
  tmp_v_in = tmp_v_in*(lv_4n_mm.Mag()/lv_he8.Mag());
  TVector3 tmp_v_out = lv_4n_mm.Vect();
  v_q_4n = tmp_v_out-tmp_v_in;

  TVector3 bVect_4n = lv_4n_mm.BoostVector();

  lv_4n_mm_CMR = lv_4n_mm;
  TVector3 bVect_R = lv_R.BoostVector();  
  lv_4n_mm_CMR.Boost(-bVect_R);

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CM4n = lv_tmp;
        lv_tmp_CM4n.Boost(-bVect_4n);
        ND_energy_CM4n[tmp_chNum] = lv_tmp_CM4n.T()-lv_tmp_CM4n.Mag();
    }
  }

}

void reco7Li(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_3n_mm = lv_he8 + lv_d2 + (-lv_7li_side);

  TVector3 bVect_3n = lv_3n_mm.BoostVector();

  lv_3n_mm_CMR = lv_3n_mm;
  TVector3 bVect_R = lv_R.BoostVector();  
  lv_3n_mm_CMR.Boost(-bVect_R);

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CM3n = lv_tmp;
        lv_tmp_CM3n.Boost(-bVect_3n);
        ND_energy_CM3n[tmp_chNum] = lv_tmp_CM3n.T()-lv_tmp_CM3n.Mag();
    }
  }

}

void recoTetraQFS(TClonesArray *v_track, TClonesArray *v_par, TClonesArray *v_digi) {

  lv_4n_mm = lv_he8 + lv_d2 + (-lv_h2_side-lv_he4_cent);

  TVector3 bVect_4n = lv_4n_mm.BoostVector();

  lv_4n_mm_CMR = lv_4n_mm;
  TVector3 bVect_R = lv_R.BoostVector();  
  lv_4n_mm_CMR.Boost(-bVect_R);

  if (v_track->GetEntries()>0 && v_track->GetEntries()==v_digi->GetEntries()) {
    for (Int_t i=0;i<v_track->GetEntries();i++) {
        Int_t tmp_chNum = ((ERNDDigi*)v_digi->At(i))->Channel();

        TLorentzVector lv_tmp = ((ERNDParticle*)v_par->At(i))->LV();
        TLorentzVector lv_tmp_CM4n = lv_tmp;
        lv_tmp_CM4n.Boost(-bVect_4n);
        ND_energy_CM4n[tmp_chNum] = lv_tmp_CM4n.T()-lv_tmp_CM4n.Mag();

    }
  }

  Float_t theta,phi;
  TLorentzVector lv_beam4n;
  Float_t mass = lv_4n_mm.Mag();
  phi = lv_he8.Phi();
  theta = lv_he8.Theta();
  Float_t ratioM = lv_4n_mm.Mag()/lv_he8.Mag();
  lv_beam4n.SetXYZM(ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Cos(phi), ratioM*lv_he8.P()*TMath::Sin(theta)*TMath::Sin(phi), ratioM*lv_he8.P()*TMath::Cos(theta) ,mass);

  lv_delta4n = lv_4n_mm - lv_beam4n;
  
  lv_6li_inv = lv_h2_side + lv_he4_cent;
  
}

void zeroVars() {

  v1_1.SetXYZ(0,0,0);
  v2_1.SetXYZ(0,0,0);
  v1_2.SetXYZ(0,0,0);
  v2_2.SetXYZ(0,0,0);
  v1_3.SetXYZ(0,0,0);
  v2_3.SetXYZ(0,0,0);
  v1_4.SetXYZ(0,0,0);
  v2_4.SetXYZ(0,0,0);  

  flagCent = 0;
  flag1 = 0;
  flag2 = 0;
  flag3 = 0;
  flag4 = 0;

  nhe4_cent = 0;
  nh3 = 0;
  nh2 = 0;
  nhe6 = 0;
  nh3_1 = 0;
  nh3_2 = 0;
  nh3_3 = 0;
  nh3_4 = 0;  
  nh2_1 = 0;
  nh2_2 = 0;
  nh2_3 = 0;
  nh2_4 = 0;   
  nhe3_1 = 0;
  nhe3_2 = 0;
  nhe3_3 = 0;
  nhe3_4 = 0;
  nhe4_1 = 0;
  nhe4_2 = 0;
  nhe4_3 = 0;
  nhe4_4 = 0;
  neutron = 0;
  gammma = 0;
  neutrons = 0;
  nli6_1 = 0;
  nli6_2 = 0;
  nli6_3 = 0;
  nli6_4 = 0;
  nli7_1 = 0;
  nli7_2 = 0;
  nli7_3 = 0;
  nli7_4 = 0;

  fXt = -1000;
  fYt = -1000;
  tF5 = 0;
  targetTime = 0;

  lv_he8.SetXYZM(0,0,0,0);
  lv_CT.SetXYZM(0,0,0,0);
  lv_h3.SetXYZM(0,0,0,0);
  lv_side.SetXYZM(0,0,0,0);
  lv_he3.SetXYZM(0,0,0,0);
  lv_he4.SetXYZM(0,0,0,0);
  lv_h7.SetXYZM(0,0,0,0);
  lv_h6.SetXYZM(0,0,0,0);
  lv_h3_CMH7.SetXYZM(0,0,0,0);
  lv_h3_CMH6.SetXYZM(0,0,0,0);
  lv_h2_CMH6.SetXYZM(0,0,0,0);
  lv_h7_CMR.SetXYZM(0,0,0,0);
  lv_h6_CMR.SetXYZM(0,0,0,0);
  lv_n.SetXYZM(0,0,0,0);
  lv_n_CMH6.SetXYZM(0,0,0,0);
  lv_n_CMH7.SetXYZM(0,0,0,0);
  lv_he7_inv.SetXYZM(0,0,0,0);
  lv_he7_inv_CMR.SetXYZM(0,0,0,0);
  lv_he7_mm.SetXYZM(0,0,0,0);
  lv_he7_mm_CMR.SetXYZM(0,0,0,0);  
  lv_he6.SetXYZM(0,0,0,0);  
  lv_h3_side.SetXYZM(0,0,0,0);
  lv_h2_side.SetXYZM(0,0,0,0);  
  lv_he6_CMHe7.SetXYZM(0,0,0,0);
  lv_n_CMHe7.SetXYZM(0,0,0,0);
  lv_he4_cent.SetXYZM(0,0,0,0);
  lv_h3_side_mm.SetXYZM(0,0,0,0);
  lv_4n_mm.SetXYZM(0,0,0,0);
  lv_3n_mm.SetXYZM(0,0,0,0);
  lv_4n_mm_CMR.SetXYZM(0,0,0,0);
  lv_4n_mm_CM4n.SetXYZM(0,0,0,0);
  lv_4n_mm_CM7H.SetXYZM(0,0,0,0);
  lv_3n_mm_CM6H.SetXYZM(0,0,0,0);
  lv_3n_mm_CMR.SetXYZM(0,0,0,0);  
  lv_6li_side.SetXYZM(0,0,0,0);
  lv_7li_side.SetXYZM(0,0,0,0);
  lv_he5_inv.SetXYZM(0,0,0,0);
  lv_he5_inv_CMR.SetXYZM(0,0,0,0);
  lv_h5_cent_mm.SetXYZM(0,0,0,0);
  lv_h3_CMH5_cent.SetXYZM(0,0,0,0);
  lv_he7_side.SetXYZM(0,0,0,0);
  lv_he7_side_CMR.SetXYZM(0,0,0,0);
  lv_he4_CMHe7_side.SetXYZM(0,0,0,0);
  lv_h4_cent.SetXYZM(0,0,0,0);
  lv_h4_cent_CMR.SetXYZM(0,0,0,0);
  lv_h3_CMH4.SetXYZM(0,0,0,0);
  lv_h4_inv_cent_CMR.SetXYZM(0,0,0,0);
  lv_he6_side_mm.SetXYZM(0,0,0,0);
  lv_h4_inv_cent.SetXYZM(0,0,0,0);
  lv_4n_al.SetXYZM(0,0,0,0);
  lv_6li_inv.SetXYZM(0,0,0,0);
  lv_6li_inv_CMR.SetXYZM(0,0,0,0);
  lv_7li_inv.SetXYZM(0,0,0,0);
  lv_7li_inv_CMR.SetXYZM(0,0,0,0);
  lv_he3_h3.SetXYZM(0,0,0,0);
  lv_he3_li6.SetXYZM(0,0,0,0);
  lv_delta4n.SetXYZM(0,0,0,0);

  X_C = 0;
  Y_C = 0;
  nX_C = -1;
  nY_C = -1;
  aCsI = 0;
  nCsI = -1;

  a20_1 = 0;
  a20_1_un = 0;
  n20_1 = -1;

  a1_1 = 0;
  a1_1_un = 0;
  n1_1 = -1;

  av_1 = 0;
  nv_1 = -1;

  a20_2 = 0;
  a20_2_un = 0;
  n20_2 = -1;

  a1_2 = 0;
  a1_2_un = 0;
  n1_2 = -1;

  av_2 = 0;
  nv_2 = -1;

  a20_3 = 0;
  a20_3_un = 0;
  n20_3 = -1;

  a1_3 = 0;
  a1_3_un = 0;
  n1_3 = -1;

  av_3 = 0;
  nv_3 = -1;

  a20_4 = 0;
  a20_4_un = 0;
  n20_4 = -1;

  a1_4 = 0;
  a1_4_un = 0;
  n1_4 = -1;

  av_4 = 0;
  nv_4 = -1;

  for (Int_t i=0;i<32;i++) {
    ND_time[i] = 0;
    ND_amp[i] = 0;
    ND_tac[i] = 0;
    ND_energy[i] = 0;
    ND_energy_CMH6[i] = 0;
    ND_energy_CMH5[i] = 0;
    ND_energy_CMH7[i] = 0;
    ND_energy_CMHe7[i] = 0;
    ND_energy_CM4n[i] = 0;
    ND_energy_CM3n[i] = 0;
    ND_energy_CMHe7_side[i] = 0;
    ND_energy_CMH4_cent[i] = 0;
  }


  for (Int_t i=0;i<16;i++) {
    SSD_V1[i] = 0;
    tSSD_V1[i] = 0;
    SSD_V2[i] = 0;
    tSSD_V2[i] = 0;
    SSD_V3[i] = 0;
    tSSD_V3[i] = 0;
    SSD_V4[i] = 0;
    tSSD_V4[i] = 0;     
  }

  multv_1 = 0;
  multv_2 = 0;
  multv_3 = 0;
  multv_4 = 0;

  mult_nd = 0;

  mom_6li = 0;
  v_q_4n.SetXYZ(0,0,0);

  angle_h7_beam = -180;
  angle_he5_beam = -180;

}
