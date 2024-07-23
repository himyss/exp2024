// BEAM
//------------------------------------------------------------------------------------------------
Float_t fXt,fYt;
Float_t targetTime;
Float_t tF5,tF3,F3,F5;

//------------------------------------------------------------------------------------------------

Int_t flag1,flag2,flag3,flag4;
Int_t nh3_1,nh3_2,nh3_3,nh3_4;
Int_t nh2_1,nh2_2,nh2_3,nh2_4;
Int_t nhe3_1,nhe3_2,nhe3_3,nhe3_4;
Int_t nhe4_1,nhe4_2,nhe4_3,nhe4_4;
Int_t nli6_1,nli6_2,nli6_3,nli6_4;
Int_t nli7_1,nli7_2,nli7_3,nli7_4;
Int_t nhe3_ct,nh3_ct,nli6_ct,nhe4_ct;
Int_t nhe3,nh3,nli6;

Float_t a20_1,a50_1,aX1_1,aY1_1,av_1;
Int_t n20_1,n50_1,nX1_1,nY1_1,nv_1;
Float_t SSD_20_1[16],SSD_50_1[16],DSD_X_1[16],DSD_Y_1[16],SSD_V1[16];

Float_t a20_2,a50_2,aX1_2,aY1_2,av_2;
Int_t n20_2,n50_2,nX1_2,nY1_2,nv_2;
Float_t SSD_20_2[16],SSD_50_2[16],DSD_X_2[16],DSD_Y_2[16],SSD_V2[16];

Float_t a20_3,a50_3,aX1_3,aY1_3,av_3;
Int_t n20_3,n50_3,nX1_3,nY1_3,nv_3;
Float_t SSD_20_3[16],SSD_50_3[16],DSD_X_3[16],DSD_Y_3[16],SSD_V3[16];

Float_t a20_4,a50_4,aX1_4,aY1_4,av_4;
Int_t n20_4,n50_4,nX1_4,nY1_4,nv_4;
Float_t SSD_20_4[16],SSD_50_4[16],DSD_X_4[16],DSD_Y_4[16],SSD_V4[16];

Float_t X_C1,Y_C1,X_C2,Y_C2;
Int_t nX_C1,nY_C1,nX_C2,nY_C2;
Float_t DSD1_X_C[32],DSD1_Y_C[32],DSD2_X_C[32],DSD2_Y_C[32];
Float_t ampCsI[16];

Float_t aCsI;
Int_t nCsI;

Int_t mult20_1,mult20_2,mult20_3,mult20_4;
Int_t mult50_1,mult50_2,mult50_3,mult50_4;
Int_t multX_1,multY_1,multX_2,multY_2,multX_3,multY_3,multX_4,multY_4;
Int_t multv_1,multv_2,multv_3,multv_4,mult_nd;
Int_t mult_xc1,mult_yc1,mult_xc2,mult_yc2;
Int_t multCsI;

//------------------------------------------------------------------------------------------------
// Neutron



Float_t ND_time[32],ND_amp[32],ND_tac[32];
Float_t ND_energy[32],ND_energy_CMH6[32],ND_energy_CMH7[32],ND_energy_CMHe7[32],ND_energy_CM4n[32],ND_energy_CMHe7_side[32],ND_energy_CM3n[32],ND_energy_CMH5[32],ND_energy_CMH4_cent[32];

Int_t neutron,gammma;
Int_t neutrons;
//------------------------------------------------------------------------------------------------
// out TLorentzVector's

TLorentzVector lv_he8, lv_n, lv_h7, lv_h6, lv_4n;
TLorentzVector lv_he3_side, lv_h3_side, lv_he4_side, lv_6li_side;
TLorentzVector lv_h3_cent, lv_he3_cent, lv_he4_cent, lv_6li_cent;
TLorentzVector lv_h3_CMH7, lv_h7_CMR, lv_h3_CMH6, lv_h6_CMR, lv_n_CMH7, lv_n_CMH6, lv_4n_CMR, lv_n_CM4n;

