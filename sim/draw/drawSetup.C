void drawSetup() {
	
	TFile *ft = new TFile("/home/ivan/work/data/exp2024/sim/setupTel.root");
	TGeoManager* geoM = (TGeoManager*)ft->Get("FAIRGeom");  
  	geoM->GetTopVolume()->Draw("x3d");


}