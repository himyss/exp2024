TCutG *cuthe3_1,*cuth3_1,*cutli6_1,*cuthe4_1;  
TCutG *cutVetohe3_1,*cutVetoh3_1,*cutVetoli6_1,*cutVetohe4_1;  

TCutG *cuthe3_2,*cuth3_2,*cutli6_2;  
TCutG *cutVetohe3_2,*cutVetoh3_2,*cutVetoli6_2;  

TCutG *cuthe3_3,*cuth3_3,*cutli6_3;  
TCutG *cutVetohe3_3,*cutVetoh3_3,*cutVetoli6_3;

TCutG *cuthe3_4,*cuth3_4,*cutli6_4;  
TCutG *cutVetohe3_4,*cutVetoh3_4,*cutVetoli6_4;

TCutG *cuthe3_ct,*cuth3_ct,*cutli6_ct;  
TCutG *cutCsIhe3_ct,*cutCsIh3_ct,*cutCsIli6_ct;

void create_T1_cuts() {
   
   cuth3_1 = new TCutG("cuth3_1",10);
   cuth3_1->SetVarX("aX1_1 ");
   cuth3_1->SetVarY("a20_1+a50_1");
   cuth3_1->SetTitle("Graph");
   cuth3_1->SetFillColor(1);
   cuth3_1->SetPoint(0,3.16721,1.19626);
   cuth3_1->SetPoint(1,7.62426,0.870255);
   cuth3_1->SetPoint(2,13.3644,0.607639);
   cuth3_1->SetPoint(3,18.2942,0.508026);
   cuth3_1->SetPoint(4,21.2655,0.462748);
   cuth3_1->SetPoint(5,21.6032,0.580472);
   cuth3_1->SetPoint(6,16.3358,0.725364);
   cuth3_1->SetPoint(7,9.71772,1.0242);
   cuth3_1->SetPoint(8,4.38277,1.3321);
   cuth3_1->SetPoint(9,3.16721,1.19626);

   cuthe3_1 = new TCutG("cuthe3_1",27);
   cuthe3_1->SetVarX("aX1_1 ");
   cuthe3_1->SetVarY("a20_1+a50_1");
   cuthe3_1->SetTitle("Graph");
   cuthe3_1->SetFillColor(1);
   cuthe3_1->SetPoint(0,0.87115,8.45782);
   cuthe3_1->SetPoint(1,5.12561,6.42608);
   cuthe3_1->SetPoint(2,8.70475,5.26509);
   cuthe3_1->SetPoint(3,12.9592,4.3363);
   cuthe3_1->SetPoint(4,19.1721,3.40751);
   cuthe3_1->SetPoint(5,23.359,2.94311);
   cuthe3_1->SetPoint(6,29.5043,2.55611);
   cuthe3_1->SetPoint(7,33.4887,2.36262);
   cuthe3_1->SetPoint(8,39.2963,2.11107);
   cuthe3_1->SetPoint(9,43.8884,1.95627);
   cuthe3_1->SetPoint(10,44.4962,1.74342);
   cuthe3_1->SetPoint(11,44.2261,1.41447);
   cuthe3_1->SetPoint(12,40.3768,1.51122);
   cuthe3_1->SetPoint(13,32.6783,1.80147);
   cuthe3_1->SetPoint(14,26.3304,2.16912);
   cuthe3_1->SetPoint(15,21.6032,2.51741);
   cuthe3_1->SetPoint(16,17.2812,2.96246);
   cuthe3_1->SetPoint(17,13.1618,3.54296);
   cuthe3_1->SetPoint(18,9.92031,4.2202);
   cuthe3_1->SetPoint(19,6.81388,5.01354);
   cuthe3_1->SetPoint(20,4.78795,5.71014);
   cuthe3_1->SetPoint(21,2.4919,6.83243);
   cuthe3_1->SetPoint(22,0.533495,7.85797);
   cuthe3_1->SetPoint(23,0.195839,8.39977);
   cuthe3_1->SetPoint(24,0.533495,8.59327);
   cuthe3_1->SetPoint(25,0.87115,8.55457);
   cuthe3_1->SetPoint(26,0.87115,8.45782);

   cutli6_1 = new TCutG("cutli6_1",24);
   cutli6_1->SetVarX("aX1_1 ");
   cutli6_1->SetVarY("a20_1+a50_1");
   cutli6_1->SetTitle("Graph");
   cutli6_1->SetFillColor(1);
   cutli6_1->SetPoint(0,16.1332,10.1993);
   cutli6_1->SetPoint(1,23.8992,8.51587);
   cutli6_1->SetPoint(2,29.5043,7.58707);
   cutli6_1->SetPoint(3,34.0964,6.90983);
   cutli6_1->SetPoint(4,39.7015,6.36803);
   cutli6_1->SetPoint(5,45.5767,5.78754);
   cutli6_1->SetPoint(6,50.1688,5.41989);
   cutli6_1->SetPoint(7,55.8414,5.07159);
   cutli6_1->SetPoint(8,62.2569,4.74265);
   cutli6_1->SetPoint(9,67.6594,4.43305);
   cutli6_1->SetPoint(10,72.7242,4.12345);
   cutli6_1->SetPoint(11,77.9916,3.9106);
   cutli6_1->SetPoint(12,83.5967,3.71711);
   cutli6_1->SetPoint(13,94.6718,3.34946);
   cutli6_1->SetPoint(14,94.6718,3.85255);
   cutli6_1->SetPoint(15,87.446,4.1428);
   cutli6_1->SetPoint(16,72.5216,4.8007);
   cutli6_1->SetPoint(17,62.6621,5.32314);
   cutli6_1->SetPoint(18,54.4233,5.82624);
   cutli6_1->SetPoint(19,45.6442,6.44543);
   cutli6_1->SetPoint(20,37.3379,7.33553);
   cutli6_1->SetPoint(21,28.6939,8.45782);
   cutli6_1->SetPoint(22,18.2266,10.4122);
   cutli6_1->SetPoint(23,16.1332,10.1993);

   cutVetoh3_1 = new TCutG("cutVetoh3_1",12);
   cutVetoh3_1->SetVarX("av_1 ");
   cutVetoh3_1->SetVarY("a20_1+a50_1+aX1_1");
   cutVetoh3_1->SetTitle("Graph");
   cutVetoh3_1->SetFillColor(1);
   cutVetoh3_1->SetPoint(0,0.26337,18.5888);
   cutVetoh3_1->SetPoint(1,3.91005,15.2348);
   cutVetoh3_1->SetPoint(2,8.02944,12.9128);
   cutVetoh3_1->SetPoint(3,12.554,11.3648);
   cutVetoh3_1->SetPoint(4,19.9824,9.17183);
   cutVetoh3_1->SetPoint(5,20.2526,10.8488);
   cutVetoh3_1->SetPoint(6,15.7955,12.1388);
   cutVetoh3_1->SetPoint(7,10.5956,14.0738);
   cutVetoh3_1->SetPoint(8,6.47623,16.2668);
   cutVetoh3_1->SetPoint(9,3.03214,18.0728);
   cutVetoh3_1->SetPoint(10,0.533495,20.5237);
   cutVetoh3_1->SetPoint(11,0.26337,18.5888);

   cutVetohe3_1 = new TCutG("cutVetohe3_1",16);
   cutVetohe3_1->SetVarX("av_1 ");
   cutVetohe3_1->SetVarY("a20_1+a50_1+aX1_1");
   cutVetohe3_1->SetTitle("Graph");
   cutVetohe3_1->SetFillColor(1);
   cutVetohe3_1->SetPoint(0,0.533495,42.7116);
   cutVetohe3_1->SetPoint(1,6.81388,36.9066);
   cutVetohe3_1->SetPoint(2,15.7955,31.7466);
   cutVetohe3_1->SetPoint(3,21.3331,28.6507);
   cutVetohe3_1->SetPoint(4,27.0732,25.6837);
   cutVetohe3_1->SetPoint(5,33.2185,23.7487);
   cutVetohe3_1->SetPoint(6,37.608,22.3297);
   cutVetohe3_1->SetPoint(7,43.3482,20.3947);
   cutVetohe3_1->SetPoint(8,44.0235,23.2327);
   cutVetohe3_1->SetPoint(9,40.5794,24.5227);
   cutVetohe3_1->SetPoint(10,31.5303,27.4897);
   cutVetohe3_1->SetPoint(11,24.7771,29.9407);
   cutVetohe3_1->SetPoint(12,15.9306,34.3266);
   cutVetohe3_1->SetPoint(13,8.97488,38.8416);
   cutVetohe3_1->SetPoint(14,0.87115,44.7755);
   cutVetohe3_1->SetPoint(15,0.533495,42.7116);

   cutVetoli6_1 = new TCutG("cutVetoli6_1",29);
   cutVetoli6_1->SetVarX("av_1 ");
   cutVetoli6_1->SetVarY("a20_1+a50_1+aX1_1");
   cutVetoli6_1->SetTitle("Graph");
   cutVetoli6_1->SetFillColor(1);
   cutVetoli6_1->SetPoint(0,1.34387,94.3111);
   cutVetoli6_1->SetPoint(1,8.09697,88.1192);
   cutVetoli6_1->SetPoint(2,16.5384,81.9272);
   cutVetoli6_1->SetPoint(3,23.0213,77.6703);
   cutVetoli6_1->SetPoint(4,28.9641,73.8003);
   cutVetoli6_1->SetPoint(5,36.0548,68.8983);
   cutVetoli6_1->SetPoint(6,42.6729,65.6734);
   cutVetoli6_1->SetPoint(7,50.7091,61.4164);
   cutVetoli6_1->SetPoint(8,59.6232,57.2884);
   cutVetoli6_1->SetPoint(9,67.6594,54.0635);
   cutVetoli6_1->SetPoint(10,73.6021,51.9995);
   cutVetoli6_1->SetPoint(11,78.2618,50.3225);
   cutVetoli6_1->SetPoint(12,83.124,48.3875);
   cutVetoli6_1->SetPoint(13,93.3887,45.6785);
   cutVetoli6_1->SetPoint(14,93.9965,46.4525);
   cutVetoli6_1->SetPoint(15,93.7939,47.6135);
   cutVetoli6_1->SetPoint(16,89.8771,48.9035);
   cutVetoli6_1->SetPoint(17,79.3422,52.5155);
   cutVetoli6_1->SetPoint(18,72.184,55.0955);
   cutVetoli6_1->SetPoint(19,65.0932,57.9334);
   cutVetoli6_1->SetPoint(20,55.909,61.9324);
   cutVetoli6_1->SetPoint(21,47.4001,66.0604);
   cutVetoli6_1->SetPoint(22,39.0937,70.5753);
   cutVetoli6_1->SetPoint(23,30.3822,75.9933);
   cutVetoli6_1->SetPoint(24,22.4136,81.2823);
   cutVetoli6_1->SetPoint(25,13.9722,86.9582);
   cutVetoli6_1->SetPoint(26,3.09968,95.2141);
   cutVetoli6_1->SetPoint(27,1.95165,95.8591);
   cutVetoli6_1->SetPoint(28,1.34387,94.3111);

}

void create_T2_cuts() {

   cuth3_2 = new TCutG("cuth3_2",9);
   cuth3_2->SetVarX("aX1_2 ");
   cuth3_2->SetVarY("a20_2+a50_2");
   cuth3_2->SetTitle("Graph");
   cuth3_2->SetFillColor(1);
   cuth3_2->SetPoint(0,5.12561,1.84017);
   cuth3_2->SetPoint(1,9.31253,1.31772);
   cuth3_2->SetPoint(2,14.58,0.853328);
   cuth3_2->SetPoint(3,17.6189,0.679179);
   cuth3_2->SetPoint(4,17.5513,0.872678);
   cuth3_2->SetPoint(5,13.7696,1.20163);
   cuth3_2->SetPoint(6,9.51513,1.68537);
   cuth3_2->SetPoint(7,6.00351,2.11107);
   cuth3_2->SetPoint(8,5.12561,1.84017);

   cuthe3_2 = new TCutG("cuthe3_2",24);
   cuthe3_2->SetVarX("aX1_2 ");
   cuthe3_2->SetVarY("a20_2+a50_2");
   cuthe3_2->SetTitle("Graph");
   cuthe3_2->SetFillColor(1);
   cuthe3_2->SetPoint(0,0.465964,9.28986);
   cuthe3_2->SetPoint(1,2.69449,7.70317);
   cuthe3_2->SetPoint(2,5.66586,6.30998);
   cuthe3_2->SetPoint(3,9.17747,5.22639);
   cuthe3_2->SetPoint(4,12.8241,4.43305);
   cuthe3_2->SetPoint(5,16.876,3.69776);
   cuthe3_2->SetPoint(6,21.0629,3.07856);
   cuthe3_2->SetPoint(7,26.2628,2.59481);
   cuthe3_2->SetPoint(8,32.003,2.30457);
   cuthe3_2->SetPoint(9,36.8652,2.05302);
   cuthe3_2->SetPoint(10,43.8209,1.85952);
   cuthe3_2->SetPoint(11,45.3066,1.82082);
   cuthe3_2->SetPoint(12,45.3066,2.32392);
   cuthe3_2->SetPoint(13,38.7561,2.49806);
   cuthe3_2->SetPoint(14,30.7874,2.86571);
   cuthe3_2->SetPoint(15,24.9122,3.33011);
   cuthe3_2->SetPoint(16,20.4552,3.73646);
   cuthe3_2->SetPoint(17,15.6605,4.51045);
   cuthe3_2->SetPoint(18,12.419,5.14899);
   cuthe3_2->SetPoint(19,9.4476,5.92299);
   cuthe3_2->SetPoint(20,6.54376,6.90983);
   cuthe3_2->SetPoint(21,4.11264,8.07082);
   cuthe3_2->SetPoint(22,1.27634,9.54141);
   cuthe3_2->SetPoint(23,0.465964,9.28986);

   cutli6_2 = new TCutG("cutli6_2",27);
   cutli6_2->SetVarX("aX1_2 ");
   cutli6_2->SetVarY("a20_2+a50_2");
   cutli6_2->SetTitle("Graph");
   cutli6_2->SetFillColor(1);
   cutli6_2->SetPoint(0,12.2164,13.6823);
   cutli6_2->SetPoint(1,17.9565,11.8827);
   cutli6_2->SetPoint(2,23.7642,10.3735);
   cutli6_2->SetPoint(3,30.7874,9.01896);
   cutli6_2->SetPoint(4,36.7301,8.10952);
   cutli6_2->SetPoint(5,43.2131,7.27748);
   cutli6_2->SetPoint(6,51.722,6.46478);
   cutli6_2->SetPoint(7,59.7582,5.82624);
   cutli6_2->SetPoint(8,68.6723,5.28444);
   cutli6_2->SetPoint(9,76.7085,4.8394);
   cutli6_2->SetPoint(10,84.6772,4.4911);
   cutli6_2->SetPoint(11,90.4173,4.2202);
   cutli6_2->SetPoint(12,95.1445,4.04605);
   cutli6_2->SetPoint(13,95.212,4.6459);
   cutli6_2->SetPoint(14,91.6329,4.8007);
   cutli6_2->SetPoint(15,83.1915,5.18769);
   cutli6_2->SetPoint(16,73.8722,5.65209);
   cutli6_2->SetPoint(17,64.8231,6.21324);
   cutli6_2->SetPoint(18,56.1116,6.85178);
   cutli6_2->SetPoint(19,48.5481,7.52902);
   cutli6_2->SetPoint(20,40.9171,8.38042);
   cutli6_2->SetPoint(21,35.1094,9.11571);
   cutli6_2->SetPoint(22,27.9511,10.3928);
   cutli6_2->SetPoint(23,23.7642,11.2055);
   cutli6_2->SetPoint(24,18.9695,12.5406);
   cutli6_2->SetPoint(25,13.6345,13.9725);
   cutli6_2->SetPoint(26,12.2164,13.6823);

   cutVetoli6_2 = new TCutG("cutVetoli6_2",24);
   cutVetoli6_2->SetVarX("av_2 ");
   cutVetoli6_2->SetVarY("a20_2+a50_2+aX1_2");
   cutVetoli6_2->SetTitle("Graph");
   cutVetoli6_2->SetFillColor(1);
   cutVetoli6_2->SetPoint(0,2.01918,93.6662);
   cutVetoli6_2->SetPoint(1,10.3255,87.0872);
   cutVetoli6_2->SetPoint(2,18.6994,81.1533);
   cutVetoli6_2->SetPoint(3,26.0602,76.2513);
   cutVetoli6_2->SetPoint(4,33.0159,71.7363);
   cutVetoli6_2->SetPoint(5,39.5665,67.6084);
   cutVetoli6_2->SetPoint(6,48.6831,62.9644);
   cutVetoli6_2->SetPoint(7,57.7998,58.8364);
   cutVetoli6_2->SetPoint(8,67.862,54.5795);
   cutVetoli6_2->SetPoint(9,76.1008,51.6125);
   cutVetoli6_2->SetPoint(10,82.3811,48.9035);
   cutVetoli6_2->SetPoint(11,90.2147,46.9685);
   cutVetoli6_2->SetPoint(12,94.064,45.6785);
   cutVetoli6_2->SetPoint(13,93.929,48.9035);
   cutVetoli6_2->SetPoint(14,82.3136,52.5155);
   cutVetoli6_2->SetPoint(15,69.7528,57.0304);
   cutVetoli6_2->SetPoint(16,58.4076,61.2874);
   cutVetoli6_2->SetPoint(17,43.1456,69.1563);
   cutVetoli6_2->SetPoint(18,29.4368,77.2833);
   cutVetoli6_2->SetPoint(19,17.2812,85.7972);
   cutVetoli6_2->SetPoint(20,8.70475,91.8602);
   cutVetoli6_2->SetPoint(21,3.03214,96.1171);
   cutVetoli6_2->SetPoint(22,2.15424,95.8591);
   cutVetoli6_2->SetPoint(23,2.01918,93.6662);

   cutVetoh3_2 = new TCutG("cutVetoh3_2",11);
   cutVetoh3_2->SetVarX("av_2 ");
   cutVetoh3_2->SetVarY("a20_2+a50_2+aX1_2");
   cutVetoh3_2->SetTitle("Graph");
   cutVetoh3_2->SetFillColor(1);
   cutVetoh3_2->SetPoint(0,0.87115,19.8787);
   cutVetoh3_2->SetPoint(1,6.07104,16.5248);
   cutVetoh3_2->SetPoint(2,12.6891,13.1708);
   cutVetoh3_2->SetPoint(3,20.2526,10.8488);
   cutVetoh3_2->SetPoint(4,20.1175,9.17183);
   cutVetoh3_2->SetPoint(5,18.2942,9.17183);
   cutVetoh3_2->SetPoint(6,13.6345,10.8488);
   cutVetoh3_2->SetPoint(7,8.90735,12.6548);
   cutVetoh3_2->SetPoint(8,2.96461,15.8798);
   cutVetoh3_2->SetPoint(9,0.736088,17.5568);
   cutVetoh3_2->SetPoint(10,0.87115,19.8787);

   cutVetohe3_2 = new TCutG("cutVetohe3_2",15);
   cutVetohe3_2->SetVarX("av_2 ");
   cutVetohe3_2->SetVarY("a20_2+a50_2+aX1_2");
   cutVetohe3_2->SetTitle("Graph");
   cutVetohe3_2->SetFillColor(1);
   cutVetohe3_2->SetPoint(0,1.54646,45.0335);
   cutVetohe3_2->SetPoint(1,7.96191,39.6156);
   cutVetohe3_2->SetPoint(2,14.58,35.7456);
   cutVetohe3_2->SetPoint(3,23.0213,31.2306);
   cutVetohe3_2->SetPoint(4,33.0159,27.3607);
   cutVetohe3_2->SetPoint(5,43.6183,23.7487);
   cutVetohe3_2->SetPoint(6,43.4833,20.9107);
   cutVetohe3_2->SetPoint(7,40.782,21.8137);
   cutVetohe3_2->SetPoint(8,31.8679,24.7807);
   cutVetohe3_2->SetPoint(9,21.8733,28.7797);
   cutVetohe3_2->SetPoint(10,14.4449,32.6496);
   cutVetohe3_2->SetPoint(11,7.08401,37.2936);
   cutVetohe3_2->SetPoint(12,1.88412,41.6796);
   cutVetohe3_2->SetPoint(13,1.27634,43.0986);
   cutVetohe3_2->SetPoint(14,1.54646,45.0335);

}

void create_T3_cuts() {

   cutli6_3 = new TCutG("cutli6_3",27);
   cutli6_3->SetVarX("aX1_3 ");
   cutli6_3->SetVarY("a20_3+a50_3");
   cutli6_3->SetTitle("Graph");
   cutli6_3->SetFillColor(1);
   cutli6_3->SetPoint(0,13.0943,14.166);
   cutli6_3->SetPoint(1,18.2266,12.2504);
   cutli6_3->SetPoint(2,23.0213,10.8765);
   cutli6_3->SetPoint(3,29.9095,9.50271);
   cutli6_3->SetPoint(4,36.9327,8.53522);
   cutli6_3->SetPoint(5,43.8209,7.62577);
   cutli6_3->SetPoint(6,50.5065,6.98723);
   cutli6_3->SetPoint(7,57.3271,6.36803);
   cutli6_3->SetPoint(8,63.4049,5.92299);
   cutli6_3->SetPoint(9,71.3736,5.47794);
   cutli6_3->SetPoint(10,79.2747,4.9942);
   cutli6_3->SetPoint(11,88.594,4.58785);
   cutli6_3->SetPoint(12,95.6848,4.27825);
   cutli6_3->SetPoint(13,95.7523,4.9555);
   cutli6_3->SetPoint(14,88.8641,5.18769);
   cutli6_3->SetPoint(15,79.2072,5.69079);
   cutli6_3->SetPoint(16,71.5086,6.17454);
   cutli6_3->SetPoint(17,62.9997,6.71633);
   cutli6_3->SetPoint(18,53.1402,7.52902);
   cutli6_3->SetPoint(19,45.0365,8.38042);
   cutli6_3->SetPoint(20,37.473,9.30921);
   cutli6_3->SetPoint(21,30.99,10.3154);
   cutli6_3->SetPoint(22,26.8706,11.0894);
   cutli6_3->SetPoint(23,23.2915,11.9214);
   cutli6_3->SetPoint(24,19.3747,12.9663);
   cutli6_3->SetPoint(25,14.6475,14.4176);
   cutli6_3->SetPoint(26,13.0943,14.166);   

   cuthe3_3 = new TCutG("cuthe3_3",23);
   cuthe3_3->SetVarX("aX1_3 ");
   cuthe3_3->SetVarY("a20_3+a50_3");
   cuthe3_3->SetTitle("Graph");
   cuthe3_3->SetFillColor(1);
   cuthe3_3->SetPoint(0,1.4114,9.96711);
   cuthe3_3->SetPoint(1,4.18017,8.26432);
   cuthe3_3->SetPoint(2,6.27364,7.43228);
   cuthe3_3->SetPoint(3,8.83982,6.44543);
   cuthe3_3->SetPoint(4,13.1618,5.34249);
   cuthe3_3->SetPoint(5,17.5513,4.47175);
   cuthe3_3->SetPoint(6,20.8603,4.0267);
   cuthe3_3->SetPoint(7,25.9927,3.48491);
   cuthe3_3->SetPoint(8,31.0575,3.13661);
   cuthe3_3->SetPoint(9,37.0678,2.76896);
   cuthe3_3->SetPoint(10,43.8209,2.45937);
   cuthe3_3->SetPoint(11,44.6988,2.26587);
   cuthe3_3->SetPoint(12,44.3612,1.93692);
   cuthe3_3->SetPoint(13,41.1197,1.97562);
   cuthe3_3->SetPoint(14,34.0964,2.32392);
   cuthe3_3->SetPoint(15,28.1537,2.69156);
   cuthe3_3->SetPoint(16,21.1305,3.29141);
   cuthe3_3->SetPoint(17,15.4579,4.08475);
   cuthe3_3->SetPoint(18,10.7982,5.07159);
   cuthe3_3->SetPoint(19,6.88141,6.30998);
   cuthe3_3->SetPoint(20,2.82955,7.91602);
   cuthe3_3->SetPoint(21,0.26337,9.77361);
   cuthe3_3->SetPoint(22,1.4114,9.96711);

   cuth3_3 = new TCutG("cuth3_3",11);
   cuth3_3->SetVarX("aX1_3 ");
   cuth3_3->SetVarY("a20_3+a50_3");
   cuth3_3->SetTitle("Graph");
   cuth3_3->SetFillColor(1);
   cuth3_3->SetPoint(0,3.97758,1.87887);
   cuth3_3->SetPoint(1,7.42166,1.35642);
   cuth3_3->SetPoint(2,10.5956,1.06618);
   cuth3_3->SetPoint(3,14.2423,0.814628);
   cuth3_3->SetPoint(4,16.4708,0.756579);
   cuth3_3->SetPoint(5,16.2007,0.988777);
   cuth3_3->SetPoint(6,12.2839,1.22098);
   cuth3_3->SetPoint(7,9.4476,1.45317);
   cuth3_3->SetPoint(8,7.01648,1.76277);
   cuth3_3->SetPoint(9,4.4503,2.13042);
   cuth3_3->SetPoint(10,3.97758,1.87887);

   cutVetoli6_3 = new TCutG("cutVetoli6_3",24);
   cutVetoli6_3->SetVarX("av_3 ");
   cutVetoli6_3->SetVarY("a20_3+a50_3+aX1_3");
   cutVetoli6_3->SetTitle("Graph");
   cutVetoli6_3->SetFillColor(1);
   cutVetoli6_3->SetPoint(0,0.601026,95.7301);
   cutVetoli6_3->SetPoint(1,5.53079,90.5702);
   cutVetoli6_3->SetPoint(2,20.185,79.9923);
   cutVetoli6_3->SetPoint(3,29.5043,73.9293);
   cutVetoli6_3->SetPoint(4,39.9716,68.1244);
   cutVetoli6_3->SetPoint(5,52.2623,61.8034);
   cutVetoli6_3->SetPoint(6,60.5011,57.4174);
   cutVetoli6_3->SetPoint(7,66.7815,54.8375);
   cutVetoli6_3->SetPoint(8,73.332,52.5155);
   cutVetoli6_3->SetPoint(9,81.4357,49.8065);
   cutVetoli6_3->SetPoint(10,91.3628,46.8395);
   cutVetoli6_3->SetPoint(11,93.3212,46.5815);
   cutVetoli6_3->SetPoint(12,93.2536,49.2905);
   cutVetoli6_3->SetPoint(13,84.6097,51.6125);
   cutVetoli6_3->SetPoint(14,69.2126,57.1594);
   cutVetoli6_3->SetPoint(15,58.2726,61.8034);
   cutVetoli6_3->SetPoint(16,47.7377,67.0924);
   cutVetoli6_3->SetPoint(17,36.9327,72.5103);
   cutVetoli6_3->SetPoint(18,29.6394,77.0253);
   cutVetoli6_3->SetPoint(19,22.0759,82.3142);
   cutVetoli6_3->SetPoint(20,13.9722,87.8612);
   cutVetoli6_3->SetPoint(21,4.4503,95.0851);
   cutVetoli6_3->SetPoint(22,0.938681,97.4071);
   cutVetoli6_3->SetPoint(23,0.601026,95.7301);

   cutVetohe3_3 = new TCutG("cutVetohe3_3",18);
   cutVetohe3_3->SetVarX("av_3 ");
   cutVetohe3_3->SetVarY("a20_3+a50_3+aX1_3");
   cutVetohe3_3->SetTitle("Graph");
   cutVetohe3_3->SetFillColor(1);
   cutVetohe3_3->SetPoint(0,0.398433,42.9696);
   cutVetohe3_3->SetPoint(1,4.99054,39.3576);
   cutVetohe3_3->SetPoint(2,11.6086,34.9716);
   cutVetohe3_3->SetPoint(3,15.5254,32.3916);
   cutVetohe3_3->SetPoint(4,19.9824,29.9407);
   cutVetohe3_3->SetPoint(5,25.0473,27.4897);
   cutVetohe3_3->SetPoint(6,28.5589,26.1997);
   cutVetohe3_3->SetPoint(7,35.312,23.6197);
   cutVetohe3_3->SetPoint(8,42.7404,21.4267);
   cutVetohe3_3->SetPoint(9,45.3741,21.0397);
   cutVetohe3_3->SetPoint(10,45.1715,23.6197);
   cutVetohe3_3->SetPoint(11,36.7977,25.8127);
   cutVetohe3_3->SetPoint(12,25.7901,29.6827);
   cutVetohe3_3->SetPoint(13,18.2942,33.1656);
   cutVetohe3_3->SetPoint(14,11.2034,37.9386);
   cutVetohe3_3->SetPoint(15,5.66586,41.6796);
   cutVetohe3_3->SetPoint(16,0.803619,45.1625);
   cutVetohe3_3->SetPoint(17,0.398433,42.9696);

   cutVetoh3_3 = new TCutG("cutVetoh3_3",11);
   cutVetoh3_3->SetVarX("av_3 ");
   cutVetoh3_3->SetVarY("a20_3+a50_3+aX1_3");
   cutVetoh3_3->SetTitle("Graph");
   cutVetoh3_3->SetFillColor(1);
   cutVetoh3_3->SetPoint(0,0.398433,18.2018);
   cutVetoh3_3->SetPoint(1,5.3282,14.4608);
   cutVetoh3_3->SetPoint(2,11.3385,11.4938);
   cutVetoh3_3->SetPoint(3,19.5097,9.04283);
   cutVetoh3_3->SetPoint(4,20.6578,9.42982);
   cutVetoh3_3->SetPoint(5,20.3201,10.9778);
   cutVetoh3_3->SetPoint(6,15.5254,12.1388);
   cutVetoh3_3->SetPoint(7,11.0683,14.0738);
   cutVetoh3_3->SetPoint(8,5.05808,17.2988);
   cutVetoh3_3->SetPoint(9,0.601026,20.6527);
   cutVetoh3_3->SetPoint(10,0.398433,18.2018);

}

void create_T4_cuts() {

   cutli6_4 = new TCutG("cutli6_4",31);
   cutli6_4->SetVarX("aX1_4 ");
   cutli6_4->SetVarY("a20_4+a50_4");
   cutli6_4->SetTitle("Graph");
   cutli6_4->SetFillColor(1);
   cutli6_4->SetPoint(0,0.26337,30.2096);
   cutli6_4->SetPoint(1,4.38277,27.0943);
   cutli6_4->SetPoint(2,9.65019,23.9338);
   cutli6_4->SetPoint(3,15.1877,21.2248);
   cutli6_4->SetPoint(4,20.6578,19.1028);
   cutli6_4->SetPoint(5,25.6551,17.3871);
   cutli6_4->SetPoint(6,30.9225,15.9875);
   cutli6_4->SetPoint(7,36.5276,14.633);
   cutli6_4->SetPoint(8,42.3352,13.414);
   cutli6_4->SetPoint(9,51.9246,11.8789);
   cutli6_4->SetPoint(10,56.7193,11.2468);
   cutli6_4->SetPoint(11,66.1737,10.0277);
   cutli6_4->SetPoint(12,73.467,9.35049);
   cutli6_4->SetPoint(13,78.7345,8.89899);
   cutli6_4->SetPoint(14,88.7291,8.1766);
   cutli6_4->SetPoint(15,95.1445,7.8154);
   cutli6_4->SetPoint(16,94.8744,8.67325);
   cutli6_4->SetPoint(17,88.4589,9.26019);
   cutli6_4->SetPoint(18,81.5032,9.71169);
   cutli6_4->SetPoint(19,73.8722,10.3889);
   cutli6_4->SetPoint(20,64.688,11.4725);
   cutli6_4->SetPoint(21,53.2077,12.827);
   cutli6_4->SetPoint(22,43.8884,14.4975);
   cutli6_4->SetPoint(23,37.5405,15.7166);
   cutli6_4->SetPoint(24,29.7744,17.7483);
   cutli6_4->SetPoint(25,22.8187,19.8252);
   cutli6_4->SetPoint(26,15.1202,22.8502);
   cutli6_4->SetPoint(27,9.51513,25.6495);
   cutli6_4->SetPoint(28,4.2477,28.81);
   cutli6_4->SetPoint(29,0.938681,30.7966);
   cutli6_4->SetPoint(30,0.26337,30.2096);

   cuthe3_4 = new TCutG("cuthe3_4",16);
   cuthe3_4->SetVarX("aX1_4 ");
   cuthe3_4->SetVarY("a20_4+a50_4");
   cuthe3_4->SetTitle("Graph");
   cuthe3_4->SetFillColor(1);
   cuthe3_4->SetPoint(0,1.07374,14.4524);
   cuthe3_4->SetPoint(1,5.53079,12.0143);
   cuthe3_4->SetPoint(2,9.98784,9.89229);
   cuthe3_4->SetPoint(3,14.3774,8.40235);
   cuthe3_4->SetPoint(4,19.3071,7.09301);
   cuthe3_4->SetPoint(5,26.3304,5.96427);
   cuthe3_4->SetPoint(6,32.7458,5.15157);
   cuthe3_4->SetPoint(7,43.8884,4.29373);
   cuthe3_4->SetPoint(8,43.8209,3.21014);
   cuthe3_4->SetPoint(9,37.5405,3.66164);
   cuthe3_4->SetPoint(10,26.0602,4.92583);
   cuthe3_4->SetPoint(11,17.9565,6.19002);
   cuthe3_4->SetPoint(12,11.1359,7.996);
   cuthe3_4->SetPoint(13,5.93598,10.1632);
   cuthe3_4->SetPoint(14,0.668557,13.4591);
   cuthe3_4->SetPoint(15,1.07374,14.4524);

   cuth3_4 = new TCutG("cuth3_4",12);
   cuth3_4->SetVarX("aX1_4 ");
   cuth3_4->SetVarY("a20_4+a50_4");
   cuth3_4->SetTitle("Graph");
   cuth3_4->SetFillColor(1);
   cuth3_4->SetPoint(0,2.96461,3.84223);
   cuth3_4->SetPoint(1,4.18017,3.25529);
   cuth3_4->SetPoint(2,7.08401,2.4426);
   cuth3_4->SetPoint(3,11.0683,1.8105);
   cuth3_4->SetPoint(4,16.5384,1.4493);
   cuth3_4->SetPoint(5,20.3876,1.2687);
   cuth3_4->SetPoint(6,20.2526,2.0814);
   cuth3_4->SetPoint(7,16.0656,2.262);
   cuth3_4->SetPoint(8,11.4735,2.48774);
   cuth3_4->SetPoint(9,7.2866,3.11984);
   cuth3_4->SetPoint(10,3.63992,4.15828);
   cuth3_4->SetPoint(11,2.96461,3.84223);

   cutVetoli6_4 = new TCutG("cutVetoli6_4",21);
   cutVetoli6_4->SetVarX("av_4 ");
   cutVetoli6_4->SetVarY("a20_4+a50_4+aX1_4");
   cutVetoli6_4->SetTitle("Graph");
   cutVetoli6_4->SetFillColor(1);
   cutVetoli6_4->SetPoint(0,0.736088,98.4391);
   cutVetoli6_4->SetPoint(1,10.1904,90.8282);
   cutVetoli6_4->SetPoint(2,25.3849,79.9923);
   cutVetoli6_4->SetPoint(3,36.1899,73.6713);
   cutVetoli6_4->SetPoint(4,43.6858,68.8983);
   cutVetoli6_4->SetPoint(5,52.0597,64.6414);
   cutVetoli6_4->SetPoint(6,60.0284,60.9004);
   cutVetoli6_4->SetPoint(7,71.3736,56.1275);
   cutVetoli6_4->SetPoint(8,78.1942,53.6765);
   cutVetoli6_4->SetPoint(9,87.581,50.3225);
   cutVetoli6_4->SetPoint(10,93.9965,48.5165);
   cutVetoli6_4->SetPoint(11,93.8614,51.8705);
   cutVetoli6_4->SetPoint(12,80.8955,55.7405);
   cutVetoli6_4->SetPoint(13,61.9868,63.2224);
   cutVetoli6_4->SetPoint(14,44.7663,71.6073);
   cutVetoli6_4->SetPoint(15,35.3795,77.1543);
   cutVetoli6_4->SetPoint(16,26.8031,82.5722);
   cutVetoli6_4->SetPoint(17,16.6059,89.0222);
   cutVetoli6_4->SetPoint(18,6.47623,96.5041);
   cutVetoli6_4->SetPoint(19,1.88412,99.6001);
   cutVetoli6_4->SetPoint(20,0.736088,98.4391);

   cutVetohe3_4 = new TCutG("cutVetohe3_4",16);
   cutVetohe3_4->SetVarX("av_4 ");
   cutVetohe3_4->SetVarY("a20_4+a50_4+aX1_4");
   cutVetohe3_4->SetTitle("Graph");
   cutVetohe3_4->SetFillColor(1);
   cutVetohe3_4->SetPoint(0,0.465964,44.3885);
   cutVetohe3_4->SetPoint(1,6.81388,39.3576);
   cutVetohe3_4->SetPoint(2,12.6891,35.3586);
   cutVetohe3_4->SetPoint(3,18.9019,32.0046);
   cutVetohe3_4->SetPoint(4,25.5875,28.3927);
   cutVetohe3_4->SetPoint(5,30.8549,26.3287);
   cutVetohe3_4->SetPoint(6,37.9457,24.0067);
   cutVetohe3_4->SetPoint(7,44.0235,22.3297);
   cutVetohe3_4->SetPoint(8,44.9689,22.8457);
   cutVetohe3_4->SetPoint(9,44.6313,25.1677);
   cutVetohe3_4->SetPoint(10,38.621,27.1027);
   cutVetohe3_4->SetPoint(11,24.4395,32.0046);
   cutVetohe3_4->SetPoint(12,16.5384,36.2616);
   cutVetohe3_4->SetPoint(13,8.23204,41.2926);
   cutVetohe3_4->SetPoint(14,0.601026,47.2265);
   cutVetohe3_4->SetPoint(15,0.465964,44.3885);

   cutVetoh3_4 = new TCutG("cutVetoh3_4",11);
   cutVetoh3_4->SetVarX("av_4 ");
   cutVetoh3_4->SetVarY("a20_4+a50_4+aX1_4");
   cutVetoh3_4->SetTitle("Graph");
   cutVetoh3_4->SetFillColor(1);
   cutVetoh3_4->SetPoint(0,0.736088,19.8787);
   cutVetoh3_4->SetPoint(1,5.80092,15.7508);
   cutVetoh3_4->SetPoint(2,9.245,13.9448);
   cutVetoh3_4->SetPoint(3,16.5384,10.9778);
   cutVetoh3_4->SetPoint(4,20.185,9.94582);
   cutVetoh3_4->SetPoint(5,20.05,11.6228);
   cutVetoh3_4->SetPoint(6,15.6605,12.9128);
   cutVetoh3_4->SetPoint(7,11.0683,14.5898);
   cutVetoh3_4->SetPoint(8,6.13857,17.4278);
   cutVetoh3_4->SetPoint(9,0.87115,20.9107);
   cutVetoh3_4->SetPoint(10,0.736088,19.8787);

}

void create_ct_cuts() {

   cutli6_ct = new TCutG("cutli6_ct",25);
   cutli6_ct->SetVarX("X_C2 ");
   cutli6_ct->SetVarY("X_C1");
   cutli6_ct->SetTitle("Graph");
   cutli6_ct->SetFillColor(1);
   cutli6_ct->SetPoint(0,8.74749,37.3092);
   cutli6_ct->SetPoint(1,14.1583,33.5863);
   cutli6_ct->SetPoint(2,22.5751,28.8087);
   cutli6_ct->SetPoint(3,33.3968,24.5274);
   cutli6_ct->SetPoint(4,49.1784,19.8738);
   cutli6_ct->SetPoint(5,63.1563,17.2678);
   cutli6_ct->SetPoint(6,76.3828,14.9721);
   cutli6_ct->SetPoint(7,87.2044,13.8552);
   cutli6_ct->SetPoint(8,99.6794,12.6143);
   cutli6_ct->SetPoint(9,113.808,11.7456);
   cutli6_ct->SetPoint(10,117.565,11.5595);
   cutli6_ct->SetPoint(11,118.016,12.9866);
   cutli6_ct->SetPoint(12,107.345,13.6691);
   cutli6_ct->SetPoint(13,92.7655,15.0962);
   cutli6_ct->SetPoint(14,77.1343,17.0817);
   cutli6_ct->SetPoint(15,63.3066,19.3775);
   cutli6_ct->SetPoint(16,47.8257,22.5419);
   cutli6_ct->SetPoint(17,33.0962,27.1334);
   cutli6_ct->SetPoint(18,23.3267,31.6629);
   cutli6_ct->SetPoint(19,15.6613,35.6339);
   cutli6_ct->SetPoint(20,3.18637,44.4447);
   cutli6_ct->SetPoint(21,1.08216,44.0724);
   cutli6_ct->SetPoint(22,2.28457,42.1489);
   cutli6_ct->SetPoint(23,7.09419,38.302);
   cutli6_ct->SetPoint(24,8.74749,37.3092);   

   cuthe3_ct = new TCutG("cuthe3_ct",21);
   cuthe3_ct->SetVarX("X_C2 ");
   cuthe3_ct->SetVarY("X_C1");
   cuthe3_ct->SetTitle("Graph");
   cuthe3_ct->SetFillColor(1);
   cuthe3_ct->SetPoint(0,1.23246,21.1148);
   cuthe3_ct->SetPoint(1,5.44088,18.1986);
   cuthe3_ct->SetPoint(2,9.1984,16.0269);
   cuthe3_ct->SetPoint(3,13.8577,13.9173);
   cuthe3_ct->SetPoint(4,17.9158,12.4902);
   cuthe3_ct->SetPoint(5,24.98,10.5047);
   cuthe3_ct->SetPoint(6,29.7896,9.51189);
   cuthe3_ct->SetPoint(7,37.1543,8.27094);
   cuthe3_ct->SetPoint(8,46.022,7.34023);
   cuthe3_ct->SetPoint(9,55.491,6.22337);
   cuthe3_ct->SetPoint(10,55.491,4.92037);
   cuthe3_ct->SetPoint(11,47.2244,5.6029);
   cuthe3_ct->SetPoint(12,37.004,6.7818);
   cuthe3_ct->SetPoint(13,27.6854,8.39504);
   cuthe3_ct->SetPoint(14,21.523,9.63599);
   cuthe3_ct->SetPoint(15,13.1062,12.242);
   cuthe3_ct->SetPoint(16,7.99599,14.5998);
   cuthe3_ct->SetPoint(17,2.73547,17.9504);
   cuthe3_ct->SetPoint(18,0.18036,20.122);
   cuthe3_ct->SetPoint(19,0.480961,21.6112);
   cuthe3_ct->SetPoint(20,1.23246,21.1148);

   cuth3_ct = new TCutG("cuth3_ct",16);
   cuth3_ct->SetVarX("X_C2 ");
   cuth3_ct->SetVarY("X_C1");
   cuth3_ct->SetTitle("Graph");
   cuth3_ct->SetFillColor(1);
   cuth3_ct->SetPoint(0,1.08216,9.20165);
   cuth3_ct->SetPoint(1,2.58517,8.14685);
   cuth3_ct->SetPoint(2,4.08818,7.34023);
   cuth3_ct->SetPoint(3,7.24449,6.16132);
   cuth3_ct->SetPoint(4,11.9038,4.85832);
   cuth3_ct->SetPoint(5,18.3667,3.86556);
   cuth3_ct->SetPoint(6,25.7315,3.05894);
   cuth3_ct->SetPoint(7,25.4309,2.19028);
   cuth3_ct->SetPoint(8,20.9218,2.56256);
   cuth3_ct->SetPoint(9,14.6092,3.30714);
   cuth3_ct->SetPoint(10,9.0481,4.36194);
   cuth3_ct->SetPoint(11,4.83968,5.91313);
   cuth3_ct->SetPoint(12,1.83367,7.02999);
   cuth3_ct->SetPoint(13,0.480961,8.33299);
   cuth3_ct->SetPoint(14,0.781562,9.63599);
   cuth3_ct->SetPoint(15,1.08216,9.20165);

   cutCsIli6_ct = new TCutG("cutCsIli6_ct",15);
   cutCsIli6_ct->SetVarX("aCsI ");
   cutCsIli6_ct->SetVarY("X_C1+X_C2");
   cutCsIli6_ct->SetTitle("Graph");
   cutCsIli6_ct->SetFillColor(1);
   cutCsIli6_ct->SetPoint(0,42.9558,91.1107);
   cutCsIli6_ct->SetPoint(1,69.1917,77.568);
   cutCsIli6_ct->SetPoint(2,87.9113,70.0838);
   cutCsIli6_ct->SetPoint(3,103.227,65.2726);
   cutCsIli6_ct->SetPoint(4,121.805,59.3922);
   cutCsIli6_ct->SetPoint(5,151.87,52.2644);
   cutCsIli6_ct->SetPoint(6,165.626,49.7697);
   cutCsIli6_ct->SetPoint(7,165.768,53.3336);
   cutCsIli6_ct->SetPoint(8,143.503,58.1448);
   cutCsIli6_ct->SetPoint(9,116.7,65.4508);
   cutCsIli6_ct->SetPoint(10,87.2022,74.8951);
   cutCsIli6_ct->SetPoint(11,75.857,79.7063);
   cutCsIli6_ct->SetPoint(12,58.981,87.1905);
   cutCsIli6_ct->SetPoint(13,43.9485,94.6746);
   cutCsIli6_ct->SetPoint(14,42.9558,91.1107);

   cutCsIhe3_ct = new TCutG("cutCsIhe3_ct",19);
   cutCsIhe3_ct->SetVarX("aCsI ");
   cutCsIhe3_ct->SetVarY("X_C1+X_C2");
   cutCsIhe3_ct->SetTitle("Graph");
   cutCsIhe3_ct->SetFillColor(1);
   cutCsIhe3_ct->SetPoint(0,0.269447,54.7119);
   cutCsIhe3_ct->SetPoint(1,11.331,47.3346);
   cutCsIhe3_ct->SetPoint(2,23.8108,40.1178);
   cutCsIhe3_ct->SetPoint(3,35.7233,34.665);
   cutCsIhe3_ct->SetPoint(4,45.6503,30.8962);
   cutCsIhe3_ct->SetPoint(5,61.5336,26.4057);
   cutCsIhe3_ct->SetPoint(6,75.1479,23.4388);
   cutCsIhe3_ct->SetPoint(7,95.5693,19.9907);
   cutCsIhe3_ct->SetPoint(8,113.58,17.8257);
   cutCsIhe3_ct->SetPoint(9,114.714,20.2313);
   cutCsIhe3_ct->SetPoint(10,99.6819,22.1558);
   cutCsIhe3_ct->SetPoint(11,70.3262,27.2878);
   cutCsIhe3_ct->SetPoint(12,47.6357,33.5424);
   cutCsIhe3_ct->SetPoint(13,35.5814,37.8725);
   cutCsIhe3_ct->SetPoint(14,23.2435,43.9668);
   cutCsIhe3_ct->SetPoint(15,10.3383,51.745);
   cutCsIhe3_ct->SetPoint(16,2.11305,56.7166);
   cutCsIhe3_ct->SetPoint(17,0.978524,56.9571);
   cutCsIhe3_ct->SetPoint(18,0.269447,54.7119);

   cutCsIh3_ct = new TCutG("cutCsIh3_ct",19);
   cutCsIh3_ct->SetVarX("aCsI ");
   cutCsIh3_ct->SetVarY("X_C1+X_C2");
   cutCsIh3_ct->SetTitle("Graph");
   cutCsIh3_ct->SetFillColor(1);
   cutCsIh3_ct->SetPoint(0,1.54578,24.2407);
   cutCsIh3_ct->SetPoint(1,6.08387,20.7926);
   cutCsIh3_ct->SetPoint(2,14.3092,16.3823);
   cutCsIh3_ct->SetPoint(3,23.3853,13.0946);
   cutCsIh3_ct->SetPoint(4,35.8651,10.2079);
   cutCsIh3_ct->SetPoint(5,47.3521,8.36355);
   cutCsIh3_ct->SetPoint(6,59.5482,7.00036);
   cutCsIh3_ct->SetPoint(7,78.126,5.87774);
   cutCsIh3_ct->SetPoint(8,103.085,4.91549);
   cutCsIh3_ct->SetPoint(9,103.227,6.35886);
   cutCsIh3_ct->SetPoint(10,86.6349,7.08055);
   cutCsIh3_ct->SetPoint(11,60.3991,9.16542);
   cutCsIh3_ct->SetPoint(12,43.5231,10.8494);
   cutCsIh3_ct->SetPoint(13,30.9015,13.5757);
   cutCsIh3_ct->SetPoint(14,18.4218,17.2644);
   cutCsIh3_ct->SetPoint(15,6.79295,23.1982);
   cutCsIh3_ct->SetPoint(16,0.553078,26.6463);
   cutCsIh3_ct->SetPoint(17,0.411263,24.1605);
   cutCsIh3_ct->SetPoint(18,1.54578,24.2407);

}

void create_ID(){

   create_T1_cuts();
   create_T2_cuts();
   create_T3_cuts();
   create_T4_cuts();
   create_ct_cuts();

}
