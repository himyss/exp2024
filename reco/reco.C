void reco() {
  //---------------------Files-----------------------------------------------
  TString geoFile = "/home/ivan/work/data/exp2024/sim/setup.root";
  // -----   Timer   --------------------------------------------------------
  TStopwatch timer;
  timer.Start();
  TString inFile = "/home/ivan/work/data/exp2024/sim/sim_digi.root";
  TFile *f_in = new TFile(inFile.Data());
  if (f_in->IsZombie()) {
    cerr << "File " << inFile.Data() << " does not exist" << endl;
    exit(1);
  }
  TTree *in_tree = (TTree*)f_in->Get("er");
  if (in_tree->IsZombie()) {
    cerr << "Tree er in file" << inFile.Data() << " does not exist" << endl;
    exit(1);   
  }
  Int_t nEvents = in_tree->GetEntries();
  cout << nEvents << " will be processed" <<  endl;

  // -----   Digitization run   ---------------------------------------------
  ERRunAna *run = ERRunAna::Instance();
  //run->HoldEventsCount(); //forbid different entry number in the input and output file
  run->SetGeomFile(geoFile);
  run->SetInputFile(inFile);
  TString outFile = "/home/ivan/work/data/exp2024/reco/reco.root";
  run->SetOutputFile(outFile);
  // ------------------------------------------------------------------------
  //-------- Set MC event header --------------------------------------------
  EREventHeader* header = new EREventHeader();
  run->SetEventHeader(header);
  // ------------------------BeamDetTrackFinger--------------------------------
  Int_t verbose = 1; // 1 - only standard log print, 2 - print digi information 
  ERBeamDetTrackFinder* trackFinder = new ERBeamDetTrackFinder(verbose);
  trackFinder->SetTargetVolume("shapeD2");
  run->AddTask(trackFinder);
  // ------- QTelescope TrackFinder -------------------------------------------
  ERTelescopeTrackFinder* qtelescopeTrackFinder = new ERTelescopeTrackFinder(verbose);
  qtelescopeTrackFinder->SetHitStation("Telescope_1", "Telescope_1_DoubleSi_DSD1_XY");
  qtelescopeTrackFinder->SetHitStation("Telescope_2", "Telescope_2_DoubleSi_DSD2_YX");
  qtelescopeTrackFinder->SetHitStation("Telescope_3", "Telescope_3_DoubleSi_DSD3_XY");
  qtelescopeTrackFinder->SetHitStation("Telescope_4", "Telescope_4_DoubleSi_DSD4_YX");
  qtelescopeTrackFinder->SetHitStation("Central_telescope", "Central_telescope_DoubleSi_DSD_CT2_XY");
  run->AddTask(qtelescopeTrackFinder);
  // -----------------------BeamDetTrackPID------------------------------------
  Int_t Z = 2, A = 8, Q = 2;
  TString ionName = "8He";
  ERBeamDetPID* beamdetPid = new ERBeamDetPID(verbose);
  beamdetPid->SetBoxPID(0., 1000., 0., 1000.);
  beamdetPid->SetOffsetToF(68.275);
  beamdetPid->SetProbabilityThreshold(0);
  beamdetPid->SetIonMass(7482.5396);
  beamdetPid->SetPID(1000020080);
  run->AddTask(beamdetPid);
  // ------   QTelescope TrackPID -----------------------------------------
  ERTelescopePID* qtelescopePID = new ERTelescopePID(verbose);
  qtelescopePID->SetParticle("Telescope_1_DoubleSi_DSD1_XY", 1000020030, "SSD20_1", "SSD50_1", 0.002, {}, {"SSD20_1"});
  qtelescopePID->SetParticle("Telescope_1_DoubleSi_DSD1_XY", 1000010030, "SSD20_1", "SSD50_1", 0.002, {}, {"SSD20_1"});
  qtelescopePID->SetParticle("Telescope_1_DoubleSi_DSD1_XY", 1000020040, "SSD20_1", "SSD50_1", 0.002, {}, {"SSD20_1"});
  qtelescopePID->SetParticle("Telescope_1_DoubleSi_DSD1_XY", 1000030060, "SSD20_1", "SSD50_1", 0.002, {}, {"SSD20_1"});

  qtelescopePID->SetParticle("Telescope_2_DoubleSi_DSD2_YX", 1000020030, "SSD20_2", "SSD50_2", 0.002, {}, {"SSD20_2"});
  qtelescopePID->SetParticle("Telescope_2_DoubleSi_DSD2_YX", 1000010030, "SSD20_2", "SSD50_2", 0.002, {}, {"SSD20_2"});
  qtelescopePID->SetParticle("Telescope_2_DoubleSi_DSD2_YX", 1000020040, "SSD20_2", "SSD50_2", 0.002, {}, {"SSD20_2"});
  qtelescopePID->SetParticle("Telescope_2_DoubleSi_DSD2_YX", 1000030060, "SSD20_2", "SSD50_2", 0.002, {}, {"SSD20_2"});
    
  qtelescopePID->SetParticle("Telescope_3_DoubleSi_DSD3_XY", 1000020030, "SSD20_3", "SSD50_3", 0.002, {}, {"SSD20_3"});
  qtelescopePID->SetParticle("Telescope_3_DoubleSi_DSD3_XY", 1000010030, "SSD20_3", "SSD50_3", 0.002, {}, {"SSD20_3"});
  qtelescopePID->SetParticle("Telescope_3_DoubleSi_DSD3_XY", 1000020040, "SSD20_3", "SSD50_3", 0.002, {}, {"SSD20_3"});
  qtelescopePID->SetParticle("Telescope_3_DoubleSi_DSD3_XY", 1000030060, "SSD20_3", "SSD50_3", 0.002, {}, {"SSD20_3"});

  qtelescopePID->SetParticle("Telescope_4_DoubleSi_DSD4_YX", 1000020030, "SSD20_4", "SSD50_4", 0.002, {}, {"SSD20_4"});
  qtelescopePID->SetParticle("Telescope_4_DoubleSi_DSD4_YX", 1000010030, "SSD20_4", "SSD50_4", 0.002, {}, {"SSD20_4"});
  qtelescopePID->SetParticle("Telescope_4_DoubleSi_DSD4_YX", 1000020040, "SSD20_4", "SSD50_4", 0.002, {}, {"SSD20_4"});
  qtelescopePID->SetParticle("Telescope_4_DoubleSi_DSD4_YX", 1000030060, "SSD20_4", "SSD50_4", 0.002, {}, {"SSD20_4"});

  qtelescopePID->SetEdepAccountingStrategy("DSD1", ERTelescopePID::EdepAccountingStrategy::EdepFromXChannel);
  qtelescopePID->SetEdepAccountingStrategy("DSD2", ERTelescopePID::EdepAccountingStrategy::EdepFromYChannel);
  qtelescopePID->SetEdepAccountingStrategy("DSD3", ERTelescopePID::EdepAccountingStrategy::EdepFromXChannel);
  qtelescopePID->SetEdepAccountingStrategy("DSD4", ERTelescopePID::EdepAccountingStrategy::EdepFromYChannel);

  // qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_YX", 1000020030, "DSD_CT1", "DSD_CT2", 0.03);
  // qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_YX", 1000020030, "DSD_CT1", "DSD_CT2", 0.03);
  // qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_YX", 1000020030, "DSD_CT1", "DSD_CT2", 0.03);
  // qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_YX", 1000020030, "DSD_CT1", "DSD_CT2", 0.03);
  // qtelescopePID->SetEdepAccountingStrategy("DSD_CT1", ERTelescopePID::EdepAccountingStrategy::EdepFromXChannel);

  qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_XY", 1000020030, "DSD_CT2", "CsI", 0.15);
  qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_XY", 1000010030, "DSD_CT2", "CsI", 0.15);
  qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_XY", 1000020040, "DSD_CT2", "CsI", 0.15);
  qtelescopePID->SetParticle("Central_telescope_DoubleSi_DSD_CT2_XY", 1000030060, "DSD_CT2", "CsI", 0.15);
  // qtelescopePID->SetEdepAccountingStrategy("DSD_CT1", ERTelescopePID::EdepAccountingStrategy::EdepFromXChannel);
  qtelescopePID->SetEdepAccountingStrategy("DSD_CT2", ERTelescopePID::EdepAccountingStrategy::EdepFromXChannel);
  run->AddTask(qtelescopePID);
  // ------------------------------------------------------------------------;
  ERNDTrackFinder* nd_track_finder = new ERNDTrackFinder();
  run->AddTask(nd_track_finder);
  ERNDPID* nd_pid = new ERNDPID();
  run->AddTask(nd_pid);
  // -----------Runtime DataBase info ---------------------------------------
  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  // -----   Intialise and run   --------------------------------------------
  FairLogger::GetLogger()->SetLogScreenLevel("FATAL");
  run->Init();
  run->Run(0, nEvents);
  // ------------------------------------------------------------------------;
  //rtdb->setOutput(parIO);
  //rtdb->saveOutput();
  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t Central_telescopeime = timer.CpuTime();
  cout << endl << endl;
  cout << "Macro finished succesfully." << endl;
  cout << "Output file writen:  "    << outFile << endl;
  cout << "Real time " << rtime << " s, CPU time " << Central_telescopeime << " s" << endl;
  cout << endl;
  // ------------------------------------------------------------------------branchName TelescopeDigi_Telescope_2
}
