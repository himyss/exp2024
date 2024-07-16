#include "/home/ivan/work/macro/exp2024/postReco/data_in.h"
#include "/home/ivan/work/macro/exp2024/postReco/data_out.h"

#include "/home/ivan/work/macro/exp2024/postReco/cuts/create_cuts.C"
#include "/home/ivan/work/macro/exp2024/postReco/cuts/create_IDs.C"
#include "/home/ivan/work/macro/exp2024/postReco/cuts/myCuts.C"


void post() {

	create_IDs();

	TString inFileReco = "";
	TChain *chReco = new TChain("er");
	chReco->Add(inFileReco.Data());
	cout << chReco->GetEntries() << endl;

	TString chCleaned = "";
	TChain *chCleaned = new TChain("er");
	chCleaned->Add(inFileCleaned.Data());
	cout << chCleaned->GetEntries() << endl;

	chReco->AddFriend(chCleaned);

	TClonesArray *v_SSD_V_1 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD20_1 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD50_1 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDX_1 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDY_1 = new TClonesArray("ERDigi");

	TClonesArray *v_SSD_V_2 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD20_2 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD50_2 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDX_2 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDY_2 = new TClonesArray("ERDigi");

	TClonesArray *v_SSD_V_3 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD20_3 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD50_3 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDX_3 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDY_3 = new TClonesArray("ERDigi");

	TClonesArray *v_SSD_V_4 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD20_4 = new TClonesArray("ERDigi");
	TClonesArray *v_SSD50_4 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDX_4 = new TClonesArray("ERDigi");
	TClonesArray *v_SSDY_4 = new TClonesArray("ERDigi");

	TClonesArray *v_F5 = new TClonesArray("ERDigi");
	TClonesArray *v_F3 = new TClonesArray("ERDigi");

	TClonesArray *v_track_nd = new TClonesArray("ERNDTrack");
	TClonesArray* v_par_nd = new TClonesArray("ERNDParticle");
	TClonesArray *v_digi_nd = new TClonesArray("ERNDDigi");

	TClonesArray *v_track_beam = new TClonesArray("ERBeamDetTrack");
	TClonesArray* v_par_beam = new TClonesArray("ERBeamDetParticle");

	TClonesArray *v_track_cent = new TClonesArray("ERTelescopeTrack");
	TClonesArray *v_track_t1 = new TClonesArray("ERTelescopeTrack");
	TClonesArray *v_track_t2 = new TClonesArray("ERTelescopeTrack");
	TClonesArray *v_track_t3 = new TClonesArray("ERTelescopeTrack");
	TClonesArray *v_track_t4 = new TClonesArray("ERTelescopeTrack");

	TClonesArray* v_par_h3_cent = new TClonesArray("ERTelescopeParticle");
	TClonesArray* v_par_he3_cent = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_li6_cent = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_he4_cent = new TClonesArray("ERTelescopeParticle"); 

	TClonesArray* v_par_h3_t1 = new TClonesArray("ERTelescopeParticle");
	TClonesArray* v_par_he3_t1 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_li6_t1 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_he4_t1 = new TClonesArray("ERTelescopeParticle"); 

	TClonesArray* v_par_h3_t2 = new TClonesArray("ERTelescopeParticle");
	TClonesArray* v_par_he3_t2 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_li6_t2 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_he4_t2 = new TClonesArray("ERTelescopeParticle"); 

	TClonesArray* v_par_h3_t3 = new TClonesArray("ERTelescopeParticle");
	TClonesArray* v_par_he3_t3 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_li6_t3 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_he4_t3 = new TClonesArray("ERTelescopeParticle"); 

	TClonesArray* v_par_h3_t4 = new TClonesArray("ERTelescopeParticle");
	TClonesArray* v_par_he3_t4 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_li6_t4 = new TClonesArray("ERTelescopeParticle"); 
	TClonesArray* v_par_he4_t4 = new TClonesArray("ERTelescopeParticle"); 

	chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD20_1_X",&v_SSD20_1);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD50_1_Y",&v_SSD50_1);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_1_DoubleSi_DSD1_XY_X",&v_SSDX_1);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_1_DoubleSi_DSD1_XY_Y",&v_SSDY_1);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_1_SingleSi_SSD_V_1_Y",&v_SSD_V_1);  

	chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD20_2_Y",&v_SSD20_2);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD50_2_X",&v_SSD50_2);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_2_DoubleSi_DSD2_YX_X",&v_SSDX_2);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_2_DoubleSi_DSD2_YX_Y",&v_SSDY_2);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_2_SingleSi_SSD_V_2_X",&v_SSD_V_2);  

	chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD20_3_X",&v_SSD20_3);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD50_3_Y",&v_SSD50_3);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_3_DoubleSi_DSD3_XY_X",&v_SSDX_3);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_3_DoubleSi_DSD3_XY_Y",&v_SSDY_3);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_3_SingleSi_SSD_V_3_Y",&v_SSD_V_3); 

	chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD20_4_Y",&v_SSD20_4);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD50_4_X",&v_SSD50_4);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_4_DoubleSi_DSD4_YX_X",&v_SSDX_4);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_4_DoubleSi_DSD4_YX_Y",&v_SSDY_4);
	chReco->SetBranchAddress("TelescopeDigi_Telescope_4_SingleSi_SSD_V_4_X",&v_SSD_V_4);

	chReco->SetBranchAddress("BeamDetToFDigi2",&v_F5);  
	chReco->SetBranchAddress("BeamDetToFDigi1",&v_F3);  

}