void sim_digi1(Int_t events_count = 50000) {

  Double_t CentTelzOffset = 0.;
//----------------------------------
  Double_t BeamDetLToF = 1232.0;     // [cm] 12348
  Double_t BeamDetPosZToF = -95.3;  // [cm] 
  Double_t BeamDetPosZ1MWPC = -81.;     // [cm]
  Double_t BeamDetPosZ2MWPC = -27.5;  // [cm]  
  // --------------- Beam start position ------------------------------------
  Double_t beamStartPosition = -1600.;  // [cm]
  // --------------- Target -------------------------------------------------
  Double_t targetD2Thickness = 0.6;  // [cm] this parameter should coincide with target H2 thickness in /macro/geo/create_target_D2_geo.C
  //---------------------Files-----------------------------------------------

  TString outFile = "/mnt/data/exp2024/sim/sim_digi1.root";
  TString parFile = "/mnt/data/exp2024/sim/par1.root";
  TString workDirPath = gSystem->Getenv("VMCWORKDIR");
  TString paramFileQTelescope = "/home/muzalevskii/work/macro/exp2024/sim/xml/QTelescopeParts.xml";
  TString paramFileBeamDet = "/home/muzalevskii/work/macro/exp2024/sim/xml/BeamDetParts.xml";
  TString targetGeoFileName = "/home/muzalevskii/work/macro/exp2024/sim/geo/target_exp1904.root";
  TString frameGeoFileName = "/home/muzalevskii/work/macro/exp2024/sim/geo/housingFrames.root";  
  TString ndGeoFileName = "/home/muzalevskii/work/macro/exp2024/sim/geo/ND.geo.exp1904.root";

  
  // -----   Timer   --------------------------------------------------------
  TStopwatch timer; 
  timer.Start();
  //-------Set LOG verbosity  ----------------------------------------------- 
  FairLogger::GetLogger()->SetLogScreenLevel("FATAL");
  // -----   Create simulation run   ----------------------------------------
  ERRunSim* run = new ERRunSim();
  /** Select transport engine
  * TGeant3
  * TGeant4exp1904_sim_digi.C
  **/
  run->SetName("TGeant4");              // Transport engine
  run->SetOutputFile(outFile.Data());          // Output file
  // ------------------------------------------------------------------------
  // -----   Runtime database   ---------------------------------------------
  FairRuntimeDb* rtdb = run->GetRuntimeDb();
  //-------- Set MC event header --------------------------------------------
  ER2H_3He3HEventHeader* decayMCheader = new ER2H_3He3HEventHeader();
  run->SetMCEventHeader(decayMCheader);
  // -----   Create media   -------------------------------------------------
  run->SetMaterials("media.geo");       // Materials
  // -----   Create detectors  ----------------------------------------------   
  FairModule* cave= new ERCave("CAVE");
  cave->SetGeometryFileName("cave.geo");
  run->AddModule(cave);
   
  Int_t verbose = 0;
  // -----  BeamDet Setup ---------------------------------------------------
  ERBeamDetSetup* setupBeamDet = ERBeamDetSetup::Instance();
  setupBeamDet->SetXmlParametersFile(paramFileBeamDet);

  // -----  BeamDet parameters ----------------------------------------------
  setupBeamDet->AddToF("ToF1", BeamDetPosZToF - BeamDetLToF);     
  setupBeamDet->AddToF("ToF2", BeamDetPosZToF);    //  BeamDet parts should be added in ascending order   
  setupBeamDet->AddMWPC("MWPC1", BeamDetPosZ1MWPC);   //  of Z-coordinate of part.
  setupBeamDet->SetMWPCnumberingInvOrderX(); 

  setupBeamDet->AddMWPC("MWPC2", BeamDetPosZ2MWPC);    
  setupBeamDet->SetMWPCnumberingInvOrderX(); 

  //setupBeamDet->SetSensitiveTarget();

  // -----   Create housing frames  -------------------------------------------------
  FairModule* frames = new ERTarget("frames", kTRUE, 1);
  frames->SetGeometryFileName(frameGeoFileName);
  run->AddModule(frames);

  // -----   Create target  -------------------------------------------------
  FairModule* target = new ERTarget("target", kTRUE, 1);
  target->SetGeometryFileName(targetGeoFileName);
  run->AddModule(target);

  // -----  QTelescope Setup ------------------------------------------------
  ERTelescopeSetup* setupQTelescope = ERTelescopeSetup::Instance();
  setupQTelescope->SetXMLParametersFile(paramFileQTelescope);
  setupQTelescope->SetGeoName("QTelescopeTmp");

 // ----- 1 parameters ----------------------------------------------------
  Double_t x, y, z;
  x = 4.85;
  y = 2.35;
  //x = 4.625; //20 mcm
  //y = 2.075;
  z = 17.3+1.5;
  TVector3 fZeroRotation(0., 0., 0.);
  TVector3 fMyRotation(0., 0., 0.);

  ERGeoSubAssembly* assembly_1 = new ERGeoSubAssembly("Telescope_1", TVector3(-x, y, z), fMyRotation);
  ERQTelescopeGeoComponentSingleSi* thin1 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD20_1",
                                                                                   TVector3(0.22, -0.27, -1.5), TVector3(), "X"); 
  ERQTelescopeGeoComponentSingleSi* thin1_1 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD50_1",
                                                                                   TVector3(0.22, -0.27, -0.5), TVector3(), "Y");   
  ERQTelescopeGeoComponentDoubleSi* thick1 = new ERQTelescopeGeoComponentDoubleSi("DoubleSi", "DoubleSi_DSD1", 
                                                                                  TVector3(0., 0., 1.), TVector3(), "X");
  ERQTelescopeGeoComponentSingleSi* veto1 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD_V_1", 
                                                                                  TVector3(0., 0., 2.0), TVector3(), "Y");
  assembly_1->AddComponent(thin1);
  assembly_1->AddComponent(thin1_1);  
  assembly_1->AddComponent(thick1);
  assembly_1->AddComponent(veto1);

  setupQTelescope->AddSubAssembly(assembly_1);
  
  // ----- 2 parameters ----------------------------------------------------
  ERGeoSubAssembly* assembly_2 = new ERGeoSubAssembly("Telescope_2", TVector3(-y, -x, z), fMyRotation);
  ERQTelescopeGeoComponentSingleSi* thin2 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD20_2",
                                                                                   TVector3(0.27, 0.22, -1.5), TVector3(), "Y");
  ERQTelescopeGeoComponentSingleSi* thin2_2 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD50_2",
                                                                                   TVector3(0.22, -0.27, -0.5), TVector3(), "X");    
  ERQTelescopeGeoComponentDoubleSi* thick2 = new ERQTelescopeGeoComponentDoubleSi("DoubleSi", "DoubleSi_DSD2", 
                                                                                  TVector3(0., 0., 1.), TVector3(), "Y");
  ERQTelescopeGeoComponentSingleSi* veto2 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD_V_2", 
                                                                                  TVector3(0., 0., 2.0), TVector3(), "X");

  assembly_2->AddComponent(thin2);
  assembly_2->AddComponent(thin2_2);
  assembly_2->AddComponent(thick2);
  assembly_2->AddComponent(veto2);

  setupQTelescope->AddSubAssembly(assembly_2);

  // ----- CENTRAL parameters ----------------------------------------------------
  Double_t xPos, yPos, zPos;
  Double_t radius = 32.3+2.9;
  TVector3 rotationC(0., 0., 0.);
  xPos = radius * TMath::Sin(rotationC.Y() * TMath::DegToRad());
  yPos = 0.;
  zPos = radius * TMath::Cos(rotationC.Y() * TMath::DegToRad());
  ERGeoSubAssembly* assembly_Central= new ERGeoSubAssembly("Central_telescope", TVector3(xPos, yPos, zPos), rotationC);
  
  ERQTelescopeGeoComponentDoubleSi* thin_Central = new ERQTelescopeGeoComponentDoubleSi("DoubleSi", "DoubleSi_DSD_CT1", 
                                                                                  TVector3(0., 0., -5.), TVector3(), "Y");
  ERQTelescopeGeoComponentDoubleSi* thick_Central = new ERQTelescopeGeoComponentDoubleSi("DoubleSi", "DoubleSi_DSD_CT2", 
                                                                                  TVector3(0., 0., -2.9), TVector3(), "X");
  ERQTelescopeGeoComponentCsI* csi = new ERQTelescopeGeoComponentCsI("CsI", "CsI", TVector3(0., 0., 0.), TVector3());

  assembly_Central->AddComponent(thin_Central);
  assembly_Central->AddComponent(thick_Central);
  assembly_Central->AddComponent(csi);

  setupQTelescope->AddSubAssembly(assembly_Central);

  // ----- 3 parameters ----------------------------------------------------
  ERGeoSubAssembly* assembly_3 = new ERGeoSubAssembly("Telescope_3", TVector3(x, -y, z), fMyRotation);
  ERQTelescopeGeoComponentSingleSi* thin3 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD20_3",
                                                                                   TVector3(-0.22, 0.27, -1.5), TVector3(), "X"); 
  ERQTelescopeGeoComponentSingleSi* thin3_3 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD50_3",
                                                                                   TVector3(-0.22, 0.27, -0.5), TVector3(), "Y");   
  ERQTelescopeGeoComponentDoubleSi* thick3 = new ERQTelescopeGeoComponentDoubleSi("DoubleSi", "DoubleSi_DSD3", 
                                                                                  TVector3(0., 0., 1.), TVector3(), "X");
  ERQTelescopeGeoComponentSingleSi* veto3 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD_V_3", 
                                                                                  TVector3(0., 0., 2.0), TVector3(), "Y");

  assembly_3->AddComponent(thin3);
  assembly_3->AddComponent(thin3_3);  
  assembly_3->AddComponent(thick3);
  assembly_3->AddComponent(veto3);

  setupQTelescope->AddSubAssembly(assembly_3);

  // ----- 4 parameters ----------------------------------------------------
  ERGeoSubAssembly* assembly_4 = new ERGeoSubAssembly("Telescope_4", TVector3(y, x, z), fMyRotation);
  ERQTelescopeGeoComponentSingleSi* thin4 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD20_4",
                                                                                   TVector3(-0.27, -0.22, -1.5), TVector3(), "Y"); 
  ERQTelescopeGeoComponentSingleSi* thin4_4 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD50_4",
                                                                                   TVector3(-0.27, -0.22, -0.5), TVector3(), "X");   
  ERQTelescopeGeoComponentDoubleSi* thick4 = new ERQTelescopeGeoComponentDoubleSi("DoubleSi", "DoubleSi_DSD4", 
                                                                                  TVector3(0., 0., 1.), TVector3(), "Y");
  ERQTelescopeGeoComponentSingleSi* veto4 = new ERQTelescopeGeoComponentSingleSi("SingleSi", "SingleSi_SSD_V_4", 
                                                                                  TVector3(0., 0., 2.0), TVector3(), "X");

  assembly_4->AddComponent(thin4);
  assembly_4->AddComponent(thin4_4);  
  assembly_4->AddComponent(thick4);
  assembly_4->AddComponent(veto4);

  setupQTelescope->AddSubAssembly(assembly_4);
  // ------QTelescope -------------------------------------------------------
  ERTelescope* qtelescope= new ERTelescope("ERQTelescope", kTRUE,verbose);
  run->AddModule(qtelescope);
  // ------BeamDet ----------------------------------------------------------
  ERBeamDet* beamdet= new ERBeamDet("ERBeamDet", kTRUE,verbose);
  run->AddModule(beamdet);
  // ------ND ---------------------------------------------------------------
  ERND* nd= new ERND("ERND", kTRUE,verbose);
  nd->SetGeometryFileName(ndGeoFileName);
  run->AddModule(nd);
  //-------------------------------------------------------------------------
  FairPrimaryGenerator* primGen = new FairPrimaryGenerator();

  Double_t  kinE_MevPerNucleon = 25.7;
  
  Int_t Z = 2, A = 8, Q = 2;
  TString ionName = "8He";
  ERIonMixGenerator* generator = new ERIonMixGenerator(ionName, Z, A, Q, 1);
  Double32_t kin_energy = kinE_MevPerNucleon * 1e-3 * A; //GeV
 generator->SetKinE(kin_energy);
  // generator->SetKinESigma(0.2015, 0.00405);
  // generator->SetKinESigma(0.205, 0.0605);
  generator->SetPSigmaOverP(0.017);
  // generator->SetPSigmaOverP(0.);

  // generator->SetThetaSigma(0., 0.);
  generator->SetThetaSigma(0.75, 0.4);
  generator->SetPhiRange(0, 360);
  //generator->SetBoxXYZ(0, 0, 0., 0., beamStartPosition);
  // generator->SetSigmaXYZ(0., 0., beamStartPosition, 0., 0.);
  generator->SetSigmaXYZ(0.033, -0.072, beamStartPosition, 0.5, 0.4);
  generator->SpreadingOnTarget(); 

  primGen->AddGenerator(generator);
  run->SetGenerator(primGen);

/////////////////////////////////////////////////////////////////////////////
  // ------- Decayer --------------------------------------------------------
  
  Double_t massn4 = 4*0.939565;//7.5061760;  // [GeV]
  ERDecayer* decayer = new ERDecayer();
  ERDecay2H_3He3H* targetDecay = new ERDecay2H_3He3H();
  targetDecay->SetInteractionVolumeName("shapeD2");
  targetDecay->SetNuclearInteractionLength(63.);
  targetDecay->Set4nMass(massn4);
  targetDecay->Set4nExitation(0.00237, 0.00412, 1);
  targetDecay->Set6LiExitation(0.017985, 0.003012, 1);
  targetDecay->SetMinStep(1e-4);
  targetDecay->SetMaxPathLength(0.63/*2e-4 * 10 * 1.1*/);

  decayer->AddDecay(targetDecay);
  run->SetDecayer(decayer);

  // ------- QTelescope Digitizer -------------------------------------------
  ERTelescopeDigitizer* qtelescopeDigitizer = new ERTelescopeDigitizer(verbose);
  qtelescopeDigitizer->SetSiElossThreshold(0.2);
  qtelescopeDigitizer->SetSiElossSigma(0.025);
  qtelescopeDigitizer->SetSiTimeSigma(0);
  qtelescopeDigitizer->SetCsIElossThreshold(1);
  qtelescopeDigitizer->SetCsIElossSigma(0.35);
  qtelescopeDigitizer->SetCsITimeSigma(0);
  run->AddTask(qtelescopeDigitizer);

  // -----  BeamDet Digitizer ----------------------------------------------
  ERBeamDetDigitizer* beamDetDigitizer = new ERBeamDetDigitizer(verbose);
  // beamDetDigitizer->SetMWPCElossThreshold(0.000006);
  // beamDetDigitizer->SetToFElossThreshold(0.000006);
  beamDetDigitizer->SetMWPCElossThreshold(0.);
  beamDetDigitizer->SetToFElossThreshold(0.);  
  beamDetDigitizer->SetToFElossSigmaOverEloss(0);
  beamDetDigitizer->SetToFTimeSigma(0.148);
  run->AddTask(beamDetDigitizer);
  // ------------------------------------------------------------------------
  ERNDDigitizer* ndDigitizer = new ERNDDigitizer(1);
  ndDigitizer->SetEdepError(0.0,0.04,0.02);
  ndDigitizer->SetLYError(0.0,0.04,0.02);
  ndDigitizer->SetTimeError(0.001);
  // ndDigitizer->SetQuenchThreshold(0.005);
  // ndDigitizer->SetLYThreshold(0.004);
  // ndDigitizer->SetProbabilityB(0.1);
  // ndDigitizer->SetProbabilityC(0.3);
  run->AddTask(ndDigitizer);
  //-------Set visualisation flag to true------------------------------------
  //run->SetStoreTraj(kTRUE);
  // -----   Initialize simulation run   ------------------------------------

  run->Init();
  Int_t nSteps = -15000;

  // -----   Runtime database   ---------------------------------------------
  Bool_t kParameterMerged = kTRUE;
  FairParRootFileIo* parOut = new FairParRootFileIo(kParameterMerged);
  parOut->open(parFile.Data());
  rtdb->setOutput(parOut);
  rtdb->saveOutput();
  rtdb->print();

  TString geometryName = "/mnt/data/exp2024/sim/setup1.root";

  run->CreateGeometryFile(geometryName.Data());

  // -----   Run simulation  ------------------------------------------------
  // events_count = 1;
  run->Run(events_count);

  // -----   Finish   -------------------------------------------------------
  timer.Stop();
  Double_t rtime = timer.RealTime();
  Double_t ctime = timer.CpuTime();
  cout << endl << endl;
  cout << "Macro finished succesfully." << endl;
  cout << "Output file is " << outFile << endl;
  cout << "Parameter file is " << parFile << endl;
  cout << "Real time " << rtime << " s, CPU time " << ctime
          << "s" << endl << endl;

}

 

