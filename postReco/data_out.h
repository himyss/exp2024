// BEAM
//------------------------------------------------------------------------------------------------
Float_t fXt,fYt;
TLorentzVector lv_he8;
Float_t targetTime, tF5;
//------------------------------------------------------------------------------------------------
// CT
TLorentzVector lv_CT;
TLorentzVector lv_h3,lv_he6,lv_he4_cent,lv_h2;

Int_t flagCent;
Int_t nh3,nh2;
Int_t nhe6,nhe4_cent;

Float_t X_C,tX_C,Y_C,tY_C;
Int_t nX_C,nY_C; 

Float_t aCsI;
Int_t nCsI;
//------------------------------------------------------------------------------------------------
// Side telescopes

TLorentzVector lv_side;
TLorentzVector lv_he3,lv_he4,lv_h3_side,lv_6li_side,lv_7li_side,lv_6li_inv,lv_7li_inv;
TLorentzVector lv_h2_side;

Float_t mom_6li,q_4n;
TVector3 v_q_4n;

Int_t flag1,flag2,flag3,flag4;
Int_t nh3_1,nh3_2,nh3_3,nh3_4;
Int_t nh2_1,nh2_2,nh2_3,nh2_4;
Int_t nhe3_1,nhe3_2,nhe3_3,nhe3_4;
Int_t nhe4_1,nhe4_2,nhe4_3,nhe4_4;
Int_t nli6_1,nli6_2,nli6_3,nli6_4;
Int_t nli7_1,nli7_2,nli7_3,nli7_4;

Float_t a20_1,a20_1_un;
Int_t n20_1;
TVector3 v1_1,v2_1;

Float_t a1_1, a1_1_un;
Int_t n1_1;

Float_t av_1, av_1_un;
Int_t nv_1;

Float_t a20_2,a20_2_un;
Int_t n20_2;
TVector3 v1_2,v2_2;

Float_t a1_2, a1_2_un;
Int_t n1_2;

Float_t av_2, av_2_un;
Int_t nv_2;

Float_t a20_3,a20_3_un;
Int_t n20_3;
TVector3 v1_3,v2_3;

Float_t a1_3, a1_3_un;
Int_t n1_3;

Float_t av_3, av_3_un;
Int_t nv_3;

Float_t a20_4,a20_4_un;
Int_t n20_4;
TVector3 v1_4,v2_4;

Float_t a1_4, a1_4_un;
Int_t n1_4;

Float_t av_4, av_4_un;
Int_t nv_4;

Int_t multv_1,multv_2,multv_3,multv_4;
Int_t mult_nd;

//------------------------------------------------------------------------------------------------
// Neutron
Float_t ND_time[32],ND_amp[32],ND_tac[32];
Float_t ND_energy[32],ND_energy_CMH6[32],ND_energy_CMH7[32],ND_energy_CMHe7[32],ND_energy_CM4n[32],ND_energy_CMHe7_side[32],ND_energy_CM3n[32],ND_energy_CMH5[32],ND_energy_CMH4_cent[32];

Int_t neutron,gammma;
Int_t neutrons;
//------------------------------------------------------------------------------------------------
// out TLorentzVector's
TLorentzVector lv_h7,lv_h6;
TLorentzVector lv_h3_CMH7,lv_h3_CMH6;
TLorentzVector lv_h7_CMR, lv_h6_CMR;
TLorentzVector lv_n, lv_n_CMH7, lv_n_CMH6, lv_n_CMHe7;
TLorentzVector lv_he6_CMHe7;
TLorentzVector lv_6li_inv_CMR;
TLorentzVector lv_7li_inv_CMR;

TLorentzVector lv_he3_h3,lv_h2_CMH6;
TLorentzVector lv_he7_inv,lv_he7_inv_CMR;
TLorentzVector lv_he7_mm,lv_he7_mm_CMR;
TLorentzVector lv_h3_side_mm;
TLorentzVector lv_4n_mm,lv_4n_mm_CMR,lv_4n_mm_CM4n,lv_4n_mm_CM7H,lv_4n_al,lv_delta4n;
TLorentzVector lv_3n_mm,lv_3n_mm_CMR,lv_3n_mm_CM6H;

TLorentzVector lv_he3_li6;
TLorentzVector lv_he7_side,lv_he7_side_CMR,lv_he4_CMHe7_side;
TLorentzVector lv_he5_inv,lv_he5_inv_CMR,lv_h5_cent_mm,lv_h3_CMH5_cent;

TLorentzVector lv_h4_cent,lv_h4_cent_CMR,lv_h3_CMH4;
TLorentzVector lv_h4_inv_cent_CMR,lv_he6_side_mm,lv_h4_inv_cent;

//------------------------------------------------------------------------------------------------
// out Angles
Float_t angle_h7_beam,angle_he5_beam;

//------------------------------------------------------------------------------------------------

//Float_t targetTime,diafTime;

// out TLorentzVector's
// TLorentzVector lv_h7,lv_he3;
// TLorentzVector lv_h3_CMH7,lv_h7_CMR,lv_he8_CMR;

// TLorentzVector lv_he4,lv_h6;
// TLorentzVector lv_h3_CMH6,lv_h6_CMR,lv_he4_CMH6,lv_he8_CMH6;
// TLorentzVector lv_h3_CMH6_rot,lv_h3_CMH7_rot;

// TLorentzVector lv_he7,lv_he7_CMR,lv_he4_CMHe7,lv_neutron_CMHe7,lv_neutron_CMHe5,lv_neutron_CMH5,lv_neutron_CMR;

// TLorentzVector lv_neutron,lv_neutron_CMH6;

// TLorentzVector lv_h6qFrame, lv_h3qFrame;

// TLorentzVector lv_he5,lv_he5_CMR,lv_he4_rot,lv_he5_rot,lv_he4_CMHe5_rot;
// TLorentzVector lv_h5, lv_h3_CMH5, lv_h3qFrame_5h,lv_h3_CMH5_rot;

// TLorentzVector lv_h4, lv_he6_side, lv_neutron_CMHe6, lv_h4_CMR, lv_he4_CMHe6;
// //------------------------------------------------------------------------------------------------
// // Neutron
// // Float_t aND,tacND,tND,tND_cal,ND_time_cal[32],ND_energy[32],eNeutron;
// // Int_t neutron,gammma;

// //------------------------------------------------------------------------------------------------
// // h7
// Float_t angle_he3_h7,angle_h3_h7,angle_he3_he8,angle_h7_he8;

// //h6
// Float_t angle_he4_h6,angle_he4_he8,angle_h3_he8,angle_h3_he8_CMH6;
// Float_t angle_h3_h6;
// Float_t angle_h3_beam_CMH6,angle_h3_q_CMH6;
// Float_t angle_h7_beam_CMR, angle_h6_beam_CMR;


