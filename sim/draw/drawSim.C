void drawSim() {
	
	TChain *ch = new TChain("er");
	ch->Add("/mnt/data/exp2024/sim/sim_digi1.root");
	ch->Add("/mnt/data/exp2024/sim/sim_digi.root");
	ch->Add("/mnt/data/exp2024/sim/sim_digi2.root");


	TCanvas *c1 = new TCanvas("c1","title",1800,1000);
	c1->Divide(4,3);

	c1->cd(1);
	ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss >> id1(500,0,50,500,0,10)","","col",100000,0);
	c1->Update();

	c1->cd(5);
	ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss:TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss >> id1_2(500,0,100,500,0,15)","","col",100000,0);
	c1->Update();

	c1->cd(9);
	ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss+TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD_V_1_Y.fELoss >> id1_3(500,0,100,500,0,100)","","col",100000,0);
	c1->Update();

	c1->cd(2);
	ch->Draw("TelescopePoint_Telescope_2_SingleSi_SSD20_2_Y.fELoss:TelescopePoint_Telescope_2_SingleSi_SSD50_2_X.fELoss >> id2(500,0,50,500,0,10)","","col",100000,0);
	c1->Update();

	c1->cd(6);
	ch->Draw("TelescopePoint_Telescope_2_SingleSi_SSD20_2_Y.fELoss+TelescopePoint_Telescope_2_SingleSi_SSD50_2_X.fELoss:TelescopePoint_Telescope_2_DoubleSi_DSD2_YX_X.fELoss >> id2_2(500,0,100,500,0,20)","","col",100000,0);
	c1->Update();

	c1->cd(10);
	ch->Draw("TelescopePoint_Telescope_2_SingleSi_SSD20_2_Y.fELoss+TelescopePoint_Telescope_2_SingleSi_SSD50_2_X.fELoss+TelescopePoint_Telescope_2_DoubleSi_DSD2_YX_X.fELoss:TelescopePoint_Telescope_2_SingleSi_SSD_V_2_X.fELoss >> id2_3(500,0,100,500,0,100)","","col",100000,0);
	c1->Update();

	c1->cd(3);
	ch->Draw("TelescopePoint_Telescope_3_SingleSi_SSD20_3_X.fELoss:TelescopePoint_Telescope_3_SingleSi_SSD50_3_Y.fELoss >> id3(500,0,50,500,0,10)","","col",100000,0);
	c1->Update();

	c1->cd(7);
	ch->Draw("TelescopePoint_Telescope_3_SingleSi_SSD20_3_X.fELoss+TelescopePoint_Telescope_3_SingleSi_SSD50_3_Y.fELoss:TelescopePoint_Telescope_3_DoubleSi_DSD3_XY_X.fELoss >> id3_2(500,0,100,500,0,20)","","col",100000,0);
	c1->Update();

	c1->cd(11);
	ch->Draw("TelescopePoint_Telescope_3_SingleSi_SSD20_3_X.fELoss+TelescopePoint_Telescope_3_SingleSi_SSD50_3_Y.fELoss+TelescopePoint_Telescope_3_DoubleSi_DSD3_XY_X.fELoss:TelescopePoint_Telescope_3_SingleSi_SSD_V_3_Y.fELoss >> id3_3(500,0,100,500,0,100)","","col",100000,0);
	c1->Update();

	c1->cd(4);
	ch->Draw("TelescopePoint_Telescope_4_SingleSi_SSD20_4_Y.fELoss:TelescopePoint_Telescope_4_SingleSi_SSD50_4_X.fELoss >> id4(500,0,50,500,0,10)","","col",100000,0);
	c1->Update();

	c1->cd(8);
	ch->Draw("TelescopePoint_Telescope_4_SingleSi_SSD20_4_Y.fELoss+TelescopePoint_Telescope_4_SingleSi_SSD50_4_X.fELoss:TelescopePoint_Telescope_4_DoubleSi_DSD4_YX_Y.fELoss >> id4_2(500,0,100,500,0,30)","","col",100000,0);
	c1->Update();	

	c1->cd(12);
	ch->Draw("TelescopePoint_Telescope_4_SingleSi_SSD20_4_Y.fELoss+TelescopePoint_Telescope_4_SingleSi_SSD50_4_X.fELoss+TelescopePoint_Telescope_4_DoubleSi_DSD4_YX_Y.fELoss:TelescopePoint_Telescope_4_SingleSi_SSD_V_4_X.fELoss >> id4_3(500,0,100,500,0,100)","","col",100000,0);
	c1->Update();	

	TCanvas *c2 = new TCanvas("c2","title",1800,1000);
	c2->Divide(2,1);
	c2->cd(1);
	ch->Draw("TelescopeDigi_Central_telescope_DoubleSi_DSD_CT1_YX_X.fEdep:TelescopeDigi_Central_telescope_DoubleSi_DSD_CT2_XY_X.fEdep >> idct1(500,0,150,500,0,60)","","col",100000,0);
	c2->Update();

	c2->cd(2);
	ch->Draw("TelescopeDigi_Central_telescope_DoubleSi_DSD_CT1_YX_X.fEdep+TelescopeDigi_Central_telescope_DoubleSi_DSD_CT2_XY_X.fEdep:TelescopeDigi_Central_telescope_CsI.fEdep >> idct2(500,0,220,500,0,150)","","col",100000,0);
	c2->Update();


}