void draw() {
	
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
	Bool_t sideID_single = 0;
	Bool_t cent_ID_single = 1;

	if (beam) {
		TCanvas *c1 = new TCanvas("c1","title",1000,1000);
		c1->Divide(2,2);

		c1->cd(1);
		ch->Draw("F5+F3:tF5-tF3","lv_he8.T()-lv_he8.Mag()>0","colz");
		c1->Update();

		c1->cd(2);
		ch->Draw("fYt:fXt","fYt>-100","colz");
		c1->Update();

		c1->cd(3);
		ch->Draw("lv_he8.Theta()*TMath::RadToDeg()","lv_he8.T()-lv_he8.Mag()>0","");
		c1->Update();	

		c1->cd(4);
		ch->Draw("lv_he8.T()-lv_he8.Mag() >> beamE(100,165,225)","","");
		c1->Update();
	}

	if (sideID) {
		// TCanvas *c2 = new TCanvas("c2","title",1800,1000);
		// c2->Divide(4,3);

		// c2->cd(1);
		// ch->Draw("a20_1:a50_1","a20_1>0 && a50_1>0 && multX_1==0 && multY_1==0 && multv_1==0","");
		// c2->Update();

		// c2->cd(5);
		// ch->Draw("a20_1+a50_1:aX1_1","a20_1>0 && a50_1>0 && aX1_1>0 && multv_1==0","");
		// c2->Update();

		// c2->cd(9);
		// ch->Draw("a20_1+a50_1+aX1_1:av_1","a20_1>0 && a50_1>0 && aX1_1>0 && av_1>0","");
		// c2->Update();

		// c2->cd(2);
		// ch->Draw("a20_2:a50_2","a20_2>0 && a50_2>0 && multX_2==0 && multY_2==0 && multv_2==0","");
		// c2->Update();

		// c2->cd(6);
		// ch->Draw("a20_2+a50_2:aX1_2","a20_2>0 && a50_2>0 && aX1_2>0 && multv_2==0","");
		// c2->Update();

		// c2->cd(10);
		// ch->Draw("a20_2+a50_2+aX1_2:av_2","a20_2>0 && a50_2>0 && aX1_2>0 && av_2>0","");
		// c2->Update();

		// c2->cd(3);
		// ch->Draw("a20_3:a50_3","a20_3>0 && a50_3>0 && multX_3==0 && multY_3==0 && multv_3==0","");
		// c2->Update();

		// c2->cd(7);
		// ch->Draw("a20_3+a50_3:aX1_3","a20_3>0 && a50_3>0 && aX1_3>0 && multv_3==0","");
		// c2->Update();

		// c2->cd(11);
		// ch->Draw("a20_3+a50_3+aX1_3:av_3","a20_3>0 && a50_3>0 && aX1_3>0 && av_3>0","");
		// c2->Update();

		// c2->cd(4);
		// ch->Draw("a20_4:a50_4","a20_4>0 && a50_4>0 && multX_4==0 && multY_4==0 && multv_4==0","");
		// c2->Update();

		// c2->cd(8);
		// ch->Draw("a20_4+a50_4:aX1_4","a20_4>0 && a50_4>0 && aX1_4>0 && multv_3==0","");
		// c2->Update();

		// c2->cd(12);
		// ch->Draw("a20_4+a50_4+aX1_4:av_4","a20_4>0 && a50_4>0 && aX1_4>0 && av_4>0","");
		// c2->Update();


		TCanvas *c3 = new TCanvas("c3","title",1800,1000);
		c3->Divide(3,1);

		// c3->cd(1);
		// // ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss >> id1(500,0,50,500,0,10)","mult20_1>0 && mult50_1>0 && multX_1==0 && multY_1==0 && multv_1==0","col");
		// ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss","mult20_1==1 && mult50_1==1 && multX_1==0 && multY_1==0 && multv_1==0","");
		// c3->Update();

		// c3->cd(5);
		// // ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss:TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss >> id1_2(500,0,100,500,0,15)","mult20_1>0 && mult50_1>0 && multX_1>0 && multY_1>0 && multv_1==0","col");
		// ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss:TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss","mult20_1==1 && mult50_1==1 && multX_1==1 && multY_1==1 && multv_1==0","");
		// c3->Update();

		// c3->cd(9);
		// // ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss+TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD_V_1_Y.fELoss >> id1_3(500,0,100,500,0,100)","mult20_1>0 && mult50_1>0 && multX_1>0 && multY_1>0 && multv_1>0","col");
		// ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss+TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD_V_1_Y.fELoss","mult20_1==1 && mult50_1==1 && multX_1==1 && multY_1==1 && multv_1==1","");
		// c3->Update();

		// c3->cd(2);
		// ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss","mult20_1==2 && mult50_1==2 && multX_1==0 && multY_1==0 && multv_1==0","");
		// c3->Update();

		// c3->cd(6);
		// ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss:TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss","mult20_1==2 && mult50_1==2 && multX_1==2 && multY_1==2 && multv_1==0","");
		// c3->Update();

		// c3->cd(10);
		// ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss+TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD_V_1_Y.fELoss","mult20_1==2 && mult50_1==2 && multX_1==2 && multY_1==2 && multv_1>0","");
		// c3->Update();

		c3->cd(1);
		ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss >> id1(500,0,50,500,0,10)","","col");
		c3->Update();

		c3->cd(2);
		ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss:TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss >> id1_2(500,0,100,500,0,15)","","col");
		c3->Update();

		c3->cd(3);
		ch->Draw("TelescopePoint_Telescope_1_SingleSi_SSD20_1_X.fELoss+TelescopePoint_Telescope_1_SingleSi_SSD50_1_Y.fELoss+TelescopePoint_Telescope_1_DoubleSi_DSD1_XY_X.fELoss:TelescopePoint_Telescope_1_SingleSi_SSD_V_1_Y.fELoss >> id1_3(500,0,100,500,0,100)","","col");
		c3->Update();
	}

	if (sideID_single) {

		TCanvas *c4 = new TCanvas("c4","title",1800,1000);
		c4->Divide(4,2);

		ch->SetMarkerColor(kBlack);
		c4->cd(1);
		ch->Draw("a20_1+a50_1:aX1_1","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_1+a50_1:aX1_1","nh3_1","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_1+a50_1:aX1_1","nhe3_1","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_1+a50_1:aX1_1","nli6_1","same");  
	    c4->Update();



		c4->cd(5);
		ch->SetMarkerColor(kBlack);
		ch->Draw("a20_1+a50_1+aX1_1:av_1","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_1+a50_1+aX1_1:av_1","nh3_1","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_1+a50_1+aX1_1:av_1","nhe3_1","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_1+a50_1+aX1_1:av_1","nli6_1","same");  
	    c4->Update();

		ch->SetMarkerColor(kBlack);
		c4->cd(2);
		ch->Draw("a20_2+a50_2:aX1_2","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_2+a50_2:aX1_2","nh3_2","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_2+a50_2:aX1_2","nhe3_2","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_2+a50_2:aX1_2","nli6_2","same");  
	    c4->Update();


		c4->cd(6);
		ch->SetMarkerColor(kBlack);
		ch->Draw("a20_2+a50_2+aX1_2:av_2","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_2+a50_2+aX1_2:av_2","nh3_2","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_2+a50_2+aX1_2:av_2","nhe3_2","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_2+a50_2+aX1_2:av_2","nli6_2","same");  
	    c4->Update();

		ch->SetMarkerColor(kBlack);
		c4->cd(3);
		ch->Draw("a20_3+a50_3:aX1_3","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_3+a50_3:aX1_3","nh3_3","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_3+a50_3:aX1_3","nhe3_3","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_3+a50_3:aX1_3","nli6_3","same");  
	    c4->Update();


		c4->cd(7);
		ch->SetMarkerColor(kBlack);
		ch->Draw("a20_3+a50_3+aX1_3:av_3","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_3+a50_3+aX1_3:av_3","nh3_3","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_3+a50_3+aX1_3:av_3","nhe3_3","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_3+a50_3+aX1_3:av_3","nli6_3","same");  
	    c4->Update();

		ch->SetMarkerColor(kBlack);
		c4->cd(4);
		ch->Draw("a20_4+a50_4:aX1_4","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_4+a50_4:aX1_4","nh3_4","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_4+a50_4:aX1_4","nhe3_4","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_4+a50_4:aX1_4","nli6_4","same");  
	    c4->Update();


		c4->cd(8);
		ch->SetMarkerColor(kBlack);
		ch->Draw("a20_4+a50_4+aX1_4:av_4","","");
		c4->Update();
	    ch->SetMarkerColor(kRed);
	    ch->Draw("a20_4+a50_4+aX1_4:av_4","nh3_4","same"); 
	    ch->SetMarkerColor(kBlue);
	    ch->Draw("a20_4+a50_4+aX1_4:av_4","nhe3_4","same");   
	    ch->SetMarkerColor(kGreen);
	    ch->Draw("a20_4+a50_4+aX1_4:av_4","nli6_4","same");  
	    c4->Update();


	}

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

  }

}