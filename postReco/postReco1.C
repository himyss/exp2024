void zeroVars();
void fillDigi();
void centID();
void sideID_1();
void sideID_2();
void sideID_3();
void sideID_4();
void centID();

#include "data_out.h"

#include "/home/muzalevskii/work/macro/exp2024/postReco/cuts/create_ID.C"

void postReco1() {

  create_ID();

  TString inFileReco = "/mnt/data/exp2024/reco/reco1.root";
  TChain *chReco = new TChain("er");
  chReco->Add(inFileReco.Data());
  cout << chReco->GetEntries() << endl;

  TString inFileCleaned = "/mnt/data/exp2024/sim/sim_digi1.root";
  TChain *chCleaned = new TChain("er");
  chCleaned->Add(inFileCleaned.Data());
  cout << chCleaned->GetEntries() << endl;  

  chReco->AddFriend(chCleaned);

  TClonesArray *v_track_beam = new TClonesArray("ERBeamDetTrack");
  TClonesArray* v_par_beam = new TClonesArray("ERBeamDetParticle");

  TClonesArray *v_track_cent = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_h3_cent = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he3_cent = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_cent = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_he4_cent = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray* v_track_t1 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_he4_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t1 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_t1 = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray *v_track_t2 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t2 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he4_t2 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t2 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_t2 = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray *v_track_t3 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t3 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he4_t3 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t3 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_li6_t3 = new TClonesArray("ERTelescopeParticle");

  TClonesArray *v_track_t4 = new TClonesArray("ERTelescopeTrack");
  TClonesArray* v_par_he3_t4 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_he4_t4 = new TClonesArray("ERTelescopeParticle"); 
  TClonesArray* v_par_h3_t4 = new TClonesArray("ERTelescopeParticle");
  TClonesArray* v_par_li6_t4 = new TClonesArray("ERTelescopeParticle"); 

  TClonesArray *v_track_nd = new TClonesArray("ERNDTrack");
  TClonesArray* v_par_nd = new TClonesArray("ERNDParticle");

  TClonesArray *v_digi_nd = new TClonesArray("ERNDDigi");

  TClonesArray *v_SSD_V_1 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_1 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD50_1 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_X1 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_Y1 = new TClonesArray("ERDigi");

  TClonesArray *v_SSD_V_2 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_2 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD50_2 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_X2 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_Y2 = new TClonesArray("ERDigi");

  TClonesArray *v_SSD_V_3 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_3 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD50_3 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_X3 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_Y3 = new TClonesArray("ERDigi");

  TClonesArray *v_SSD_V_4 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD20_4 = new TClonesArray("ERDigi");
  TClonesArray *v_SSD50_4 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_X4 = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_Y4 = new TClonesArray("ERDigi");

  TClonesArray *v_DSD_CT1_X = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_CT1_Y = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_CT2_X = new TClonesArray("ERDigi");
  TClonesArray *v_DSD_CT2_Y = new TClonesArray("ERDigi");
  TClonesArray *v_CsI = new TClonesArray("ERDigi");
  TClonesArray *v_ND = new TClonesArray("ERDigi");

  TClonesArray *v_F5 = new TClonesArray("ERDigi");
  TClonesArray *v_F3 = new TClonesArray("ERDigi");

  // digi
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD20_1_X",&v_SSD20_1);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD50_1_Y",&v_SSD50_1);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD_V_1_Y",&v_SSD_V_1);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_DoubleSi_DSD1_XY_X",&v_DSD_X1);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_1_DoubleSi_DSD1_XY_Y",&v_DSD_Y1);  
 
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD20_2_Y",&v_SSD20_2);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD50_2_X",&v_SSD50_2);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD_V_2_X",&v_SSD_V_2);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_DoubleSi_DSD2_YX_X",&v_DSD_X2);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_2_DoubleSi_DSD2_YX_Y",&v_DSD_Y2); 

  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD20_3_X",&v_SSD20_3);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD50_3_Y",&v_SSD50_3);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD_V_3_Y",&v_SSD_V_3);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_DoubleSi_DSD3_XY_X",&v_DSD_X3);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_3_DoubleSi_DSD3_XY_Y",&v_DSD_Y3); 

  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD20_4_Y",&v_SSD20_4);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD50_4_X",&v_SSD50_4);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD_V_4_X",&v_SSD_V_4);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_DoubleSi_DSD4_YX_X",&v_DSD_X4);
  chReco->SetBranchAddress("TelescopeDigi_Telescope_4_DoubleSi_DSD4_YX_Y",&v_DSD_Y4);  

  chReco->SetBranchAddress("TelescopeDigi_Central_telescope_DoubleSi_DSD_CT1_YX_X",&v_DSD_CT1_X);  
  chReco->SetBranchAddress("TelescopeDigi_Central_telescope_DoubleSi_DSD_CT1_YX_Y",&v_DSD_CT1_Y);
  chReco->SetBranchAddress("TelescopeDigi_Central_telescope_DoubleSi_DSD_CT2_XY_X",&v_DSD_CT2_X);  
  chReco->SetBranchAddress("TelescopeDigi_Central_telescope_DoubleSi_DSD_CT2_XY_Y",&v_DSD_CT2_Y); 
  chReco->SetBranchAddress("TelescopeDigi_Central_telescope_CsI",&v_CsI);  

  chReco->SetBranchAddress("BeamDetToFDigi2",&v_F5); 
  chReco->SetBranchAddress("BeamDetToFDigi1",&v_F3); 

  // central telescope

  chReco->SetBranchAddress("BeamDetTrack",&v_track_beam);
  chReco->SetBranchAddress("BeamDetParticle.",&v_par_beam);

  chReco->SetBranchAddress("TelescopeTrack_Central_telescope_DoubleSi_DSD_CT2_XY",&v_track_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_CT2_XY_1000020030",&v_par_he3_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_CT2_XY_1000010030",&v_par_h3_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_CT2_XY_1000020040",&v_par_he4_cent);
  chReco->SetBranchAddress("TelescopeParticle_Central_telescope_DoubleSi_DSD_CT2_XY_1000030060",&v_par_li6_cent);

  // 1 telescope
  chReco->SetBranchAddress("TelescopeTrack_Telescope_1_DoubleSi_DSD1_XY",&v_track_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_DoubleSi_DSD1_XY_1000020030",&v_par_he3_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_DoubleSi_DSD1_XY_1000020040",&v_par_he4_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_DoubleSi_DSD1_XY_1000010030",&v_par_h3_t1);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_1_DoubleSi_DSD1_XY_1000030060",&v_par_li6_t1);

  // 2 telescope
  chReco->SetBranchAddress("TelescopeTrack_Telescope_2_DoubleSi_DSD2_YX",&v_track_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_DoubleSi_DSD2_YX_1000020030",&v_par_he3_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_DoubleSi_DSD2_YX_1000020040",&v_par_he4_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_DoubleSi_DSD2_YX_1000010030",&v_par_h3_t2);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_2_DoubleSi_DSD2_YX_1000030060",&v_par_li6_t2);

  // 3 telescope
  chReco->SetBranchAddress("TelescopeTrack_Telescope_3_DoubleSi_DSD3_XY",&v_track_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_DoubleSi_DSD3_XY_1000020030",&v_par_he3_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_DoubleSi_DSD3_XY_1000020040",&v_par_he4_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_DoubleSi_DSD3_XY_1000010030",&v_par_h3_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_3_DoubleSi_DSD3_XY_1000030060",&v_par_li6_t3);

  // 4 telescope
  chReco->SetBranchAddress("TelescopeTrack_Telescope_4_DoubleSi_DSD4_YX",&v_track_t4);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_DoubleSi_DSD4_YX_1000020030",&v_par_he3_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_DoubleSi_DSD4_YX_1000020040",&v_par_he4_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_DoubleSi_DSD4_YX_1000010030",&v_par_h3_t3);
  chReco->SetBranchAddress("TelescopeParticle_Telescope_4_DoubleSi_DSD4_YX_1000030060",&v_par_li6_t3);

  TString outFile = "/mnt/data/exp2024/postReco/data1.root";
  TFile *fw = new TFile(outFile.Data(), "RECREATE");
  TTree *tw = new TTree("tree", "data");

  tw->Branch("a20_1.",&a20_1,"a20_1/F");
  tw->Branch("n20_1.",&n20_1,"n20_1/I");

  tw->Branch("a50_1.",&a50_1,"a50_1/F");
  tw->Branch("n50_1.",&n50_1,"n50_1/I");

  tw->Branch("aX1_1.",&aX1_1,"aX1_1/F");
  tw->Branch("nX1_1.",&nX1_1,"nX1_1/I");
  tw->Branch("aY1_1.",&aY1_1,"aY1_1/F");
  tw->Branch("nY1_1.",&nY1_1,"nY1_1/I");

  tw->Branch("av_1.",&av_1,"av_1/F");
  tw->Branch("nv_1.",&nv_1,"nv_1/I");

  tw->Branch("a20_2.",&a20_2,"a20_2/F");
  tw->Branch("n20_2.",&n20_2,"n20_2/I");

  tw->Branch("a50_2.",&a50_2,"a50_2/F");
  tw->Branch("n50_2.",&n50_2,"n50_2/I");

  tw->Branch("aX1_2.",&aX1_2,"aX1_2/F");
  tw->Branch("nX1_2.",&nX1_2,"nX1_2/I");
  tw->Branch("aY1_2.",&aY1_2,"aY1_2/F");
  tw->Branch("nY1_2.",&nY1_2,"nY1_2/I");

  tw->Branch("av_2.",&av_2,"av_2/F");
  tw->Branch("nv_2.",&nv_2,"nv_2/I");

  tw->Branch("a20_3.",&a20_3,"a20_3/F");
  tw->Branch("n20_3.",&n20_3,"n20_3/I");

  tw->Branch("a50_3.",&a50_3,"a50_3/F");
  tw->Branch("n50_3.",&n50_3,"n50_3/I");

  tw->Branch("aX1_3.",&aX1_3,"aX1_3/F");
  tw->Branch("nX1_3.",&nX1_3,"nX1_3/I");
  tw->Branch("aY1_3.",&aY1_3,"aY1_3/F");
  tw->Branch("nY1_3.",&nY1_3,"nY1_3/I");

  tw->Branch("av_3.",&av_3,"av_3/F");
  tw->Branch("nv_3.",&nv_3,"nv_3/I");

  tw->Branch("a20_4.",&a20_4,"a20_4/F");
  tw->Branch("n20_4.",&n20_4,"n20_4/I");

  tw->Branch("a50_4.",&a50_4,"a50_4/F");
  tw->Branch("n50_4.",&n50_4,"n50_4/I");

  tw->Branch("aX1_4.",&aX1_4,"aX1_4/F");
  tw->Branch("nX1_4.",&nX1_4,"nX1_4/I");
  tw->Branch("aY1_4.",&aY1_4,"aY1_4/F");
  tw->Branch("nY1_4.",&nY1_4,"nY1_4/I");

  tw->Branch("av_4.",&av_4,"av_4/F");
  tw->Branch("nv_4.",&nv_4,"nv_4/I");

  tw->Branch("aCsI.",&aCsI,"aCsI/F");
  tw->Branch("nCsI.",&nCsI,"nCsI/I");

  tw->Branch("X_C1.",&X_C1,"X_C1/F");
  tw->Branch("nX_C1.",&nX_C1,"nX_C1/I");
  tw->Branch("Y_C1.",&Y_C1,"Y_C1/F");
  tw->Branch("nY_C1.",&nY_C1,"nY_C1/I");
 
  tw->Branch("X_C2.",&X_C2,"X_C2/F");
  tw->Branch("nX_C2.",&nX_C2,"nX_C2/I");
  tw->Branch("Y_C2.",&Y_C2,"Y_C2/F");
  tw->Branch("nY_C2.",&nY_C2,"nY_C2/I");

  tw->Branch("fXt.",&fXt,"fXt/F");
  tw->Branch("fYt.",&fYt,"fYt/F"); 
  tw->Branch("tF5.",&tF5,"tF5/F");
  tw->Branch("tF3.",&tF3,"tF3/F");
  tw->Branch("F3.",&F3,"F3/F");
  tw->Branch("F5.",&F5,"F5/F");

  tw->Branch("SSD_20_1",&SSD_20_1,"SSD_20_1[16]/F");
  tw->Branch("SSD_50_1",&SSD_50_1,"SSD_50_1[16]/F");
  tw->Branch("DSD_X_1",&DSD_X_1,"DSD_X_1[16]/F");
  tw->Branch("DSD_Y_1",&DSD_Y_1,"DSD_Y_1[16]/F");
  tw->Branch("SSD_V1",&SSD_V1,"SSD_V1[16]/F");

  tw->Branch("multv_1.",&multv_1,"multv_1/I");
  tw->Branch("multv_2.",&multv_2,"multv_2/I");
  tw->Branch("multv_3.",&multv_3,"multv_3/I");
  tw->Branch("multv_4.",&multv_4,"multv_4/I");
  tw->Branch("mult_nd.",&mult_nd,"mult_nd/I");

  tw->Branch("mult20_1.",&mult20_1,"mult20_1/I");
  tw->Branch("mult20_2.",&mult20_2,"mult20_2/I");
  tw->Branch("mult20_3.",&mult20_3,"mult20_3/I");
  tw->Branch("mult20_4.",&mult20_4,"mult20_4/I");
  tw->Branch("mult50_1.",&mult50_1,"mult50_1/I");
  tw->Branch("mult50_2.",&mult50_2,"mult50_2/I");
  tw->Branch("mult50_3.",&mult50_3,"mult50_3/I");
  tw->Branch("mult50_4.",&mult50_4,"mult50_4/I"); 
  tw->Branch("multX_1.",&multX_1,"multX_1/I");
  tw->Branch("multY_1.",&multY_1,"multY_1/I");  
  tw->Branch("multX_2.",&multX_2,"multX_2/I");
  tw->Branch("multY_2.",&multY_2,"multY_2/I"); 
  tw->Branch("multX_3.",&multX_3,"multX_3/I");
  tw->Branch("multY_3.",&multY_3,"multY_3/I"); 
  tw->Branch("multX_4.",&multX_4,"multX_4/I");
  tw->Branch("multY_4.",&multY_4,"multY_4/I"); 
  tw->Branch("mult_xc1.",&mult_xc1,"mult_xc1/I"); 
  tw->Branch("mult_yc1.",&mult_yc1,"mult_yc1/I"); 
  tw->Branch("mult_xc2.",&mult_xc2,"mult_xc2/I"); 
  tw->Branch("mult_yc2.",&mult_yc2,"mult_yc2/I");
  tw->Branch("multCsI.",&multCsI,"multCsI/I"); 

  tw->Branch("lv_he8","TLorentzVector",&lv_he8);
  tw->Branch("lv_n","TLorentzVector",&lv_n);
  tw->Branch("lv_h7","TLorentzVector",&lv_h7);
  tw->Branch("lv_h6","TLorentzVector",&lv_h6);
  tw->Branch("lv_4n","TLorentzVector",&lv_4n);
  
  tw->Branch("lv_he3_side","TLorentzVector",&lv_he3_side);
  tw->Branch("lv_h3_side","TLorentzVector",&lv_h3_side);
  tw->Branch("lv_he4_side","TLorentzVector",&lv_he4_side);
  tw->Branch("lv_6li_side","TLorentzVector",&lv_6li_side);

  tw->Branch("lv_h3_cent","TLorentzVector",&lv_h3_cent);
  tw->Branch("lv_he3_cent","TLorentzVector",&lv_he3_cent);
  tw->Branch("lv_he4_cent","TLorentzVector",&lv_he4_cent);
  tw->Branch("lv_6li_cent","TLorentzVector",&lv_6li_cent);

  tw->Branch("lv_h3_CMH7","TLorentzVector",&lv_h3_CMH7);
  tw->Branch("lv_h7_CMR","TLorentzVector",&lv_h7_CMR);
  tw->Branch("lv_h3_CMH6","TLorentzVector",&lv_h3_CMH6);
  tw->Branch("lv_h6_CMR","TLorentzVector",&lv_h6_CMR);
  tw->Branch("lv_n_CMH7","TLorentzVector",&lv_n_CMH7);
  tw->Branch("lv_n_CMH6","TLorentzVector",&lv_n_CMH6);
  tw->Branch("lv_4n_CMR","TLorentzVector",&lv_4n_CMR);
  tw->Branch("lv_n_CM4n","TLorentzVector",&lv_n_CM4n);

  tw->Branch("nh3.",&nh3,"nh3/I");
  tw->Branch("nhe3.",&nhe3,"nhe3/I");
  tw->Branch("nli6.",&nli6,"nli6/I");
  tw->Branch("nhe3_ct.",&nhe3_ct,"nhe3_ct/I");
  tw->Branch("nh3_ct.",&nh3_ct,"nh3_ct/I");
  tw->Branch("nli6_ct.",&nli6_ct,"nli6_ct/I");
  tw->Branch("nhe3_1.",&nhe3_1,"nhe3_1/I");
  tw->Branch("nh3_1.",&nh3_1,"nh3_1/I");
  tw->Branch("nli6_1.",&nli6_1,"nli6_1/I");
  tw->Branch("nhe3_2.",&nhe3_2,"nhe3_2/I");
  tw->Branch("nh3_2.",&nh3_2,"nh3_2/I");
  tw->Branch("nli6_2.",&nli6_2,"nli6_2/I");
  tw->Branch("nhe3_3.",&nhe3_3,"nhe3_3/I");
  tw->Branch("nh3_3.",&nh3_3,"nh3_3/I");
  tw->Branch("nli6_3.",&nli6_3,"nli6_3/I");
  tw->Branch("nhe3_4.",&nhe3_4,"nhe3_4/I");
  tw->Branch("nh3_4.",&nh3_4,"nh3_4/I");
  tw->Branch("nli6_4.",&nli6_4,"nli6_4/I");

//------------------------------------------------------------------------------------------------

  for (Int_t nentry=0;nentry<chReco->GetEntries();nentry++) {
  // for (Int_t nentry=0;nentry<10;nentry++) {
    if (nentry%100000==0) cout << nentry << endl;

    zeroVars();
    chReco->GetEntry(nentry);


    if (v_F5->GetEntries()!=1 || v_F3->GetEntries()!=1) {
      tw->Fill();
      continue;
    }
    if (v_track_beam->GetEntries()==0 || v_par_beam->GetEntries()==0) {
      tw->Fill();
      continue;
    } 
    lv_he8 = ((ERBeamDetParticle*)v_par_beam->At(0))->GetLVTarget();

    fXt = ((ERBeamDetTrack*)v_track_beam->At(0))->GetTargetX();
    fYt = ((ERBeamDetTrack*)v_track_beam->At(0))->GetTargetY();

    tF5 = ((ERDigi*)v_F5->At(0))->Time();
    tF3 = ((ERDigi*)v_F3->At(0))->Time();
    F5 = ((ERDigi*)v_F5->At(0))->Edep();
    F3 = ((ERDigi*)v_F3->At(0))->Edep();

    mult20_1 = v_SSD20_1->GetEntries(); 
    mult20_2 = v_SSD20_2->GetEntries(); 
    mult20_3 = v_SSD20_3->GetEntries(); 
    mult20_4 = v_SSD20_4->GetEntries(); 
    mult50_1 = v_SSD50_1->GetEntries(); 
    mult50_2 = v_SSD50_2->GetEntries(); 
    mult50_3 = v_SSD50_3->GetEntries(); 
    mult50_4 = v_SSD50_4->GetEntries(); 
    multX_1 = v_DSD_X1->GetEntries(); 
    multY_1 = v_DSD_Y1->GetEntries(); 
    multX_2 = v_DSD_X2->GetEntries();
    multY_2 = v_DSD_Y2->GetEntries(); 
    multX_3 = v_DSD_X3->GetEntries();
    multY_3 = v_DSD_Y3->GetEntries();     
    multX_4 = v_DSD_X4->GetEntries();
    multY_4 = v_DSD_Y4->GetEntries();
    multv_1 = v_SSD_V_1->GetEntries();
    multv_2 = v_SSD_V_2->GetEntries();
    multv_3 = v_SSD_V_3->GetEntries();
    multv_4 = v_SSD_V_4->GetEntries();
    mult_xc1 = v_DSD_CT1_X->GetEntries();
    mult_yc1 = v_DSD_CT1_Y->GetEntries();
    mult_xc2 = v_DSD_CT2_X->GetEntries();
    mult_yc2 = v_DSD_CT2_Y->GetEntries();    
    multCsI = v_CsI->GetEntries(); 


    if (v_SSD20_1->GetEntries()==1) {
      n20_1 = ((ERDigi*)v_SSD20_1->At(0))->Channel();
      a20_1 = ((ERDigi*)v_SSD20_1->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD20_1->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD20_1->At(i))->Channel();
      SSD_20_1[tmpCh] = ((ERDigi*)v_SSD20_1->At(i))->Edep();     
    }
    if (v_SSD50_1->GetEntries()==1) {
      n50_1 = ((ERDigi*)v_SSD50_1->At(0))->Channel();
      a50_1 = ((ERDigi*)v_SSD50_1->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD50_1->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD50_1->At(i))->Channel();
      SSD_50_1[tmpCh] = ((ERDigi*)v_SSD50_1->At(i))->Edep();     
    }    
    if (v_DSD_X1->GetEntries()==1) {
      nX1_1 = ((ERDigi*)v_DSD_X1->At(0))->Channel();
      aX1_1 = ((ERDigi*)v_DSD_X1->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_DSD_X1->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_X1->At(i))->Channel();
      DSD_X_1[tmpCh] = ((ERDigi*)v_DSD_X1->At(i))->Edep();     
    }           
    if (v_DSD_Y1->GetEntries()==1) {
      nY1_1 = ((ERDigi*)v_DSD_Y1->At(0))->Channel();
      aY1_1 = ((ERDigi*)v_DSD_Y1->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_DSD_Y1->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_Y1->At(i))->Channel();
      DSD_Y_1[tmpCh] = ((ERDigi*)v_DSD_Y1->At(i))->Edep();     
    }       
    if (v_SSD_V_1->GetEntries()==1) {
      nv_1 = ((ERDigi*)v_SSD_V_1->At(0))->Channel();
      av_1 = ((ERDigi*)v_SSD_V_1->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_SSD_V_1->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD_V_1->At(i))->Channel();
      SSD_V1[tmpCh] = ((ERDigi*)v_SSD_V_1->At(i))->Edep();     
    }

    if (v_SSD20_2->GetEntries()==1) {
      n20_2 = ((ERDigi*)v_SSD20_2->At(0))->Channel();
      a20_2 = ((ERDigi*)v_SSD20_2->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD20_2->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD20_2->At(i))->Channel();
      SSD_20_2[tmpCh] = ((ERDigi*)v_SSD20_2->At(i))->Edep();     
    }    
    if (v_SSD50_2->GetEntries()==1) {
      n50_2 = ((ERDigi*)v_SSD50_2->At(0))->Channel();
      a50_2 = ((ERDigi*)v_SSD50_2->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD50_2->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD50_2->At(i))->Channel();
      SSD_50_2[tmpCh] = ((ERDigi*)v_SSD50_2->At(i))->Edep();     
    }     
    if (v_DSD_X2->GetEntries()==1) {
      nX1_2 = ((ERDigi*)v_DSD_X2->At(0))->Channel();
      aX1_2 = ((ERDigi*)v_DSD_X2->At(0))->Edep();
    }   
    for (Int_t i=0;i<v_DSD_X2->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_X2->At(i))->Channel();
      DSD_X_2[tmpCh] = ((ERDigi*)v_DSD_X2->At(i))->Edep();     
    }     
    if (v_DSD_Y2->GetEntries()==1) {
      nY1_2 = ((ERDigi*)v_DSD_Y2->At(0))->Channel();
      aY1_2 = ((ERDigi*)v_DSD_Y2->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_DSD_Y2->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_Y2->At(i))->Channel();
      DSD_Y_2[tmpCh] = ((ERDigi*)v_DSD_Y2->At(i))->Edep();     
    }     
    if (v_SSD_V_2->GetEntries()==1) {
      nv_2 = ((ERDigi*)v_SSD_V_2->At(0))->Channel();
      av_2 = ((ERDigi*)v_SSD_V_2->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_SSD_V_2->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD_V_2->At(i))->Channel();
      SSD_V2[tmpCh] = ((ERDigi*)v_SSD_V_2->At(i))->Edep();     
    }    

    if (v_SSD20_3->GetEntries()==1) {
      n20_3 = ((ERDigi*)v_SSD20_3->At(0))->Channel();
      a20_3 = ((ERDigi*)v_SSD20_3->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD20_3->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD20_3->At(i))->Channel();
      SSD_20_3[tmpCh] = ((ERDigi*)v_SSD20_3->At(i))->Edep();     
    }    
    if (v_SSD50_3->GetEntries()==1) {
      n50_3 = ((ERDigi*)v_SSD50_3->At(0))->Channel();
      a50_3 = ((ERDigi*)v_SSD50_3->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD50_3->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD50_3->At(i))->Channel();
      SSD_50_3[tmpCh] = ((ERDigi*)v_SSD50_3->At(i))->Edep();     
    }    
    if (v_DSD_X3->GetEntries()==1) {
      nX1_3 = ((ERDigi*)v_DSD_X3->At(0))->Channel();
      aX1_3 = ((ERDigi*)v_DSD_X3->At(0))->Edep();
    }  
    for (Int_t i=0;i<v_DSD_X3->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_X3->At(i))->Channel();
      DSD_X_3[tmpCh] = ((ERDigi*)v_DSD_X3->At(i))->Edep();     
    }      
    for (Int_t i=0;i<v_DSD_X3->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_X3->At(i))->Channel();
      DSD_X_3[tmpCh] = ((ERDigi*)v_DSD_X3->At(i))->Edep();     
    }      
    if (v_DSD_Y3->GetEntries()==1) {
      nY1_3 = ((ERDigi*)v_DSD_Y3->At(0))->Channel();
      aY1_3 = ((ERDigi*)v_DSD_Y3->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_DSD_Y3->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_Y3->At(i))->Channel();
      DSD_Y_3[tmpCh] = ((ERDigi*)v_DSD_Y3->At(i))->Edep();     
    }      
    if (v_SSD_V_3->GetEntries()==1) {
      nv_3 = ((ERDigi*)v_SSD_V_3->At(0))->Channel();
      av_3 = ((ERDigi*)v_SSD_V_3->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_SSD_V_3->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD_V_3->At(i))->Channel();
      SSD_V3[tmpCh] = ((ERDigi*)v_SSD_V_3->At(i))->Edep();     
    } 

    if (v_SSD20_4->GetEntries()==1) {
      n20_4 = ((ERDigi*)v_SSD20_4->At(0))->Channel();
      a20_4 = ((ERDigi*)v_SSD20_4->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD20_4->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD20_4->At(i))->Channel();
      SSD_20_4[tmpCh] = ((ERDigi*)v_SSD20_4->At(i))->Edep();     
    }    
    if (v_SSD50_4->GetEntries()==1) {
      n50_4 = ((ERDigi*)v_SSD50_4->At(0))->Channel();
      a50_4 = ((ERDigi*)v_SSD50_4->At(0))->Edep();
    }
    for (Int_t i=0;i<v_SSD50_4->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD50_4->At(i))->Channel();
      SSD_50_4[tmpCh] = ((ERDigi*)v_SSD50_4->At(i))->Edep();     
    }     
    if (v_DSD_X4->GetEntries()==1) {
      nX1_4 = ((ERDigi*)v_DSD_X4->At(0))->Channel();
      aX1_4 = ((ERDigi*)v_DSD_X4->At(0))->Edep();
    }    
    for (Int_t i=0;i<v_DSD_X4->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_X4->At(i))->Channel();
      DSD_X_4[tmpCh] = ((ERDigi*)v_DSD_X4->At(i))->Edep();     
    }    
    if (v_DSD_Y4->GetEntries()==1) {
      nY1_4 = ((ERDigi*)v_DSD_Y4->At(0))->Channel();
      aY1_4 = ((ERDigi*)v_DSD_Y4->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_DSD_Y4->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_Y4->At(i))->Channel();
      DSD_Y_4[tmpCh] = ((ERDigi*)v_DSD_Y4->At(i))->Edep();     
    }    
    if (v_SSD_V_4->GetEntries()==1) {
      nv_4 = ((ERDigi*)v_SSD_V_4->At(0))->Channel();
      av_4 = ((ERDigi*)v_SSD_V_4->At(0))->Edep();
    } 
    for (Int_t i=0;i<v_SSD_V_4->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_SSD_V_4->At(i))->Channel();
      SSD_V4[tmpCh] = ((ERDigi*)v_SSD_V_4->At(i))->Edep();     
    } 

    if (v_DSD_CT1_X->GetEntries()==1) {
      nX_C1 = ((ERDigi*)v_DSD_CT1_X->At(0))->Channel();
      X_C1 = ((ERDigi*)v_DSD_CT1_X->At(0))->Edep();
    }    
    for (Int_t i=0;i<v_DSD_CT1_X->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_CT1_X->At(i))->Channel();
      DSD1_X_C[tmpCh] = ((ERDigi*)v_DSD_CT1_X->At(i))->Edep();     
    }  
    if (v_DSD_CT1_Y->GetEntries()==1) {
      nY_C1 = ((ERDigi*)v_DSD_CT1_Y->At(0))->Channel();
      Y_C1 = ((ERDigi*)v_DSD_CT1_Y->At(0))->Edep();
    }    
    for (Int_t i=0;i<v_DSD_CT1_Y->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_CT1_Y->At(i))->Channel();
      DSD1_Y_C[tmpCh] = ((ERDigi*)v_DSD_CT1_Y->At(i))->Edep();     
    }  
    if (v_DSD_CT2_X->GetEntries()==1) {
      nX_C2 = ((ERDigi*)v_DSD_CT2_X->At(0))->Channel();
      X_C2 = ((ERDigi*)v_DSD_CT2_X->At(0))->Edep();
    }    
    for (Int_t i=0;i<v_DSD_CT2_X->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_CT2_X->At(i))->Channel();
      DSD2_X_C[tmpCh] = ((ERDigi*)v_DSD_CT2_X->At(i))->Edep();     
    }  
    if (v_DSD_CT2_Y->GetEntries()==1) {
      nY_C2 = ((ERDigi*)v_DSD_CT2_Y->At(0))->Channel();
      Y_C2 = ((ERDigi*)v_DSD_CT2_Y->At(0))->Edep();
    }    
    for (Int_t i=0;i<v_DSD_CT2_Y->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_DSD_CT2_Y->At(i))->Channel();
      DSD2_Y_C[tmpCh] = ((ERDigi*)v_DSD_CT2_Y->At(i))->Edep();     
    }
    if (v_CsI->GetEntries()==1) {
      nCsI = ((ERDigi*)v_CsI->At(0))->Channel();
      aCsI = ((ERDigi*)v_CsI->At(0))->Edep();
    }    
    for (Int_t i=0;i<v_CsI->GetEntries();i++) {
      Int_t tmpCh = ((ERDigi*)v_CsI->At(i))->Channel();
      ampCsI[tmpCh] = ((ERDigi*)v_CsI->At(i))->Edep();     
    }    

    sideID_1();
    sideID_2();
    sideID_3();
    sideID_4();
    centID();

    tw->Fill();
  }
  fw->cd();
  tw->Write();
  fw->Close();

}

void zeroVars() { 

  a20_1 = 0;
  n20_1 = -1;
  a50_1 = 0;
  n50_1 = -1;
  aX1_1 = 0;
  nX1_1 = -1;
  aY1_1 = 0;
  nY1_1 = -1;
  av_1 = 0;
  nv_1 = -1;

  a20_2 = 0;
  n20_2 = -1;
  a50_2 = 0;
  n50_2 = -1;
  aX1_2 = 0;
  nX1_2 = -1;
  aY1_2 = 0;
  nY1_2 = -1;
  av_2 = 0;
  nv_2 = -1;

  a20_3 = 0;
  n20_3 = -1;
  a50_3 = 0;
  n50_3 = -1;
  aX1_3 = 0;
  nX1_3 = -1;
  aY1_3 = 0;
  nY1_3 = -1;
  av_3 = 0;
  nv_3 = -1;

  a20_4 = 0;
  n20_4 = -1;
  a50_4 = 0;
  n50_4 = -1;
  aX1_4 = 0;
  nX1_4 = -1;
  aY1_4 = 0;
  nY1_4 = -1;
  av_4 = 0;
  nv_4 = -1;

  aCsI = 0;
  nCsI = -1;
  X_C1 = 0;
  nX_C1 = -1;
  Y_C1 = 0;
  nY_C1 = -1;
  X_C2 = 0;
  nX_C2 = -1;
  Y_C2 = 0;
  nY_C2 = -1;

  fXt = -1000;
  fYt = -1000;
  tF5 = -10000;
  tF3 = -10000;
  F3 = 0;
  F5 = 0;

  for (Int_t i=0;i<16;i++) {

    SSD_20_1[i] = 0;
    SSD_50_1[i] = 0;
    DSD_X_1[i] = 0;
    DSD_Y_1[i] = 0;

    SSD_20_2[i] = 0;
    SSD_50_2[i] = 0;
    DSD_X_2[i] = 0;
    DSD_Y_2[i] = 0;

    SSD_20_3[i] = 0;
    SSD_50_3[i] = 0;
    DSD_X_3[i] = 0;
    DSD_Y_3[i] = 0;

    SSD_20_4[i] = 0;
    SSD_50_4[i] = 0;
    DSD_X_4[i] = 0;
    DSD_Y_4[i] = 0;

    SSD_V1[i] = 0;
    SSD_V2[i] = 0;
    SSD_V3[i] = 0;
    SSD_V4[i] = 0; 

    ampCsI[i] = 0;  
  }

  for (Int_t i=0;i<32;i++) {
    DSD1_X_C[i] = 0;
    DSD1_Y_C[i] = 0;
    DSD2_X_C[i] = 0;
    DSD2_Y_C[i] = 0;
  }

  mult20_1 = 0;
  mult20_2 = 0;
  mult20_3 = 0;
  mult20_4 = 0;
  mult50_1 = 0;
  mult50_2 = 0;
  mult50_3 = 0;
  mult50_4 = 0;
  multX_1 = 0;
  multY_1 = 0;
  multX_2 = 0;
  multY_2 = 0;
  multX_3 = 0;
  multY_3 = 0;     
  multX_4 = 0;
  multY_4 = 0;   
  multv_1 = 0;
  multv_2 = 0;
  multv_3 = 0;
  multv_4 = 0;
  mult_nd = 0;
  mult_xc1 = 0;
  mult_yc1 = 0;
  mult_xc2 = 0;
  mult_yc2 = 0;
  multCsI = 0;

  lv_he8.SetXYZM(0,0,0,0);
  lv_n.SetXYZM(0,0,0,0);
  lv_h7.SetXYZM(0,0,0,0);
  lv_h6.SetXYZM(0,0,0,0);
  lv_4n.SetXYZM(0,0,0,0);
  lv_he3_side.SetXYZM(0,0,0,0);
  lv_h3_side.SetXYZM(0,0,0,0);
  lv_6li_side.SetXYZM(0,0,0,0);
  lv_h3_cent.SetXYZM(0,0,0,0);
  lv_he3_cent.SetXYZM(0,0,0,0);
  lv_he4_cent.SetXYZM(0,0,0,0);
  lv_6li_cent.SetXYZM(0,0,0,0);
  lv_h3_CMH7.SetXYZM(0,0,0,0);
  lv_h7_CMR.SetXYZM(0,0,0,0);
  lv_h3_CMH6.SetXYZM(0,0,0,0);
  lv_h6_CMR.SetXYZM(0,0,0,0);  
  lv_n_CMH7.SetXYZM(0,0,0,0);
  lv_n_CMH6.SetXYZM(0,0,0,0);
  lv_4n_CMR.SetXYZM(0,0,0,0);
  lv_n_CM4n.SetXYZM(0,0,0,0);    

  nhe3_1 = 0;
  nh3_1 = 0;
  nli6_1 = 0;
  nhe4_1 = 0;
  nhe3_2 = 0;
  nh3_2 = 0;
  nli6_2 = 0;
  nhe4_2 = 0;
  nhe3_3 = 0;
  nh3_3 = 0;
  nli6_3 = 0;
  nhe4_3 = 0;
  nhe3_4 = 0;
  nh3_4 = 0;
  nli6_4 = 0;
  nhe4_4 = 0;
  nhe3_ct = 0;
  nh3_ct = 0;
  nli6_ct = 0;
  nhe4_ct = 0;
  nhe3 = 0;
  nh3 = 0;
  nli6 = 0;

}


void sideID_1() {

  if(cuthe3_1->IsInside(aX1_1, a20_1+a50_1) && multv_1==0){
    nhe3_1++;
    nhe3++;
  }

  if(cuth3_1->IsInside(aX1_1, a20_1+a50_1) && multv_1==0){
    nh3_1++;
    nh3++;
  } 
    
  if(cutli6_1->IsInside(aX1_1, a20_1+a50_1) && multv_1==0){
    nli6_1++;
    nli6++;
  } 

  if(cutVetohe3_1->IsInside(av_1, a20_1+a50_1+aX1_1)){
    nhe3_1++;
    nhe3++;
  } 

  if(cutVetoh3_1->IsInside(av_1, a20_1+a50_1+aX1_1)){
    nh3_1++;
    nh3++;
  } 

  if(cutVetoli6_1->IsInside(av_1, a20_1+a50_1+aX1_1)){
    nli6_1++;
    nli6++;
  } 

  return; 
}

void sideID_2() {

  if(cuthe3_2->IsInside(aX1_2, a20_2+a50_2) && multv_2==0){
    nhe3_2++;
    nhe3++;
  } 

  if(cuth3_2->IsInside(aX1_2, a20_2+a50_2) && multv_2==0) {
    nh3_2++;
    nh3++;
  }

  if(cutli6_2->IsInside(aX1_2, a20_2+a50_2) && multv_2==0) {
    nli6_2++;
    nli6++;
  }

  if(cutVetohe3_2->IsInside(av_2, a20_2+a50_2+aX1_2)) {
    nhe3_2++;
    nhe3++;
  }

  if(cutVetoh3_2->IsInside(av_2, a20_2+a50_2+aX1_2)) {
    nh3_2++;
    nh3++;
  }

  if(cutVetoli6_2->IsInside(av_2, a20_2+a50_2+aX1_2)) {
    nli6_2++;
    nli6++;
  }

  return; 
}

void sideID_3() {

  if(cuthe3_3->IsInside(aX1_3, a20_3+a50_3) && multv_3==0) {
    nhe3_3++;
    nhe3++;
  }

  if(cuth3_3->IsInside(aX1_3, a20_3+a50_3) && multv_3==0) {
    nh3_3++;
    nh3++;
  }

  if(cutli6_3->IsInside(aX1_3, a20_3+a50_3) && multv_3==0) {
    nli6_3++;
    nli6++;
  }

  if(cutVetohe3_3->IsInside(av_3, a20_3+a50_3+aX1_3)) {
    nhe3_3++;
    nhe3++;
  }

  if(cutVetoh3_3->IsInside(av_3, a20_3+a50_3+aX1_3)) {
    nh3_3++;
    nh3++;
  }

  if(cutVetoli6_3->IsInside(av_3, a20_3+a50_3+aX1_3)) {
    nli6++;
    nli6_3++;
  }

  return; 
}

void sideID_4() {

  if(cuthe3_4->IsInside(aX1_4, a20_4+a50_4) && multv_4==0) {
    nhe3++;
    nhe3_4++;
  }

  if(cuth3_4->IsInside(aX1_4, a20_4+a50_4) && multv_4==0) {
    nh3++;
    nh3_4++;
  }

  if(cutli6_4->IsInside(aX1_4, a20_4+a50_4) && multv_4==0) {
    nli6++;
    nli6_4++;
  }

  if(cutVetohe3_4->IsInside(av_4, a20_4+a50_4+aX1_4)) {
    nhe3++;
    nhe3_4++;
  }

  if(cutVetoh3_4->IsInside(av_4, a20_4+a50_4+aX1_4)) {
    nh3++;
    nh3_4++;
  }

  if(cutVetoli6_4->IsInside(av_4, a20_4+a50_4+aX1_4)) {
    nli6++;
    nli6_4++;
  }

  return; 
}
void centID() {

  if(cuthe3_ct->IsInside(X_C2, X_C1) && multCsI==0) {
    nhe3++;
    nhe3_ct++;  
  }

  if(cuth3_ct->IsInside(X_C2, X_C1) && multCsI==0) {
    nh3++;
    nh3_ct++;  
  }

  if(cutli6_ct->IsInside(X_C2, X_C1) && multCsI==0) {
    nli6++;
    nli6_ct++;  
  }

  if(cutCsIhe3_ct->IsInside(aCsI, X_C1+X_C2)) {
    nhe3++;
    nhe3_ct++;  
  }

  if(cutCsIh3_ct->IsInside(aCsI, X_C1+X_C2)) {
    nh3++;
    nh3_ct++;  
  }

  if(cutCsIli6_ct->IsInside(aCsI, X_C1+X_C2)) {
    nli6++;
    nli6_ct++;  
  }

  return;
}
