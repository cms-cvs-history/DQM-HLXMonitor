// -*- C++ -*-
//
// Package:    HLXMonitor
// Class:      HLXMonitor
// 
/**\class HLXMonitor HLXMonitor.cc DQM/HLXMonitor/src/HLXMonitor.cc

Description: DQM Source for HLX histograms

Implementation:
<Notes on implementation>
*/
//
// Original Author:  Adam Hunt - Princeton University
//           email:  ahunt@princeton.edu
//         Created:  Thu Jul 19 02:29:59 EDT 2007
// $Id: HLXMonitor.h,v 1.8 2008/03/11 14:41:06 ahunt Exp $
//
//

#ifndef _HLXMONITOR_H_
#define _HLXMONITOR_H_

// system include files
#include <iostream>
#include <string>
#include <memory>
#include <iomanip>
#include <cstdlib>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h" // Not included in example

#include "FWCore/Framework/interface/Event.h" // Not included in example
#include "FWCore/Framework/interface/MakerMacros.h" // Not included in example

#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

//#include "DQMServices/Core/interface/DaqMonitorBEInterface.h"  // Obsolete as of version 3. 
//#include "DQMServices/Daemon/interface/MonitorDaemon.h"
#include "DQMServices/Core/interface/DQMStore.h"
#include "DQMServices/Core/interface/MonitorElement.h"

#include "FWCore/ServiceRegistry/interface/Service.h"

#include "/opt/TriDAS/RecoLuminosity/HLXReadOut/CoreUtils/include/ICTypeDefs.hh"
#include "/opt/TriDAS/RecoLuminosity/HLXReadOut/HLXCoreLibs/include/LumiStructures.hh"
#include "RecoLuminosity/TCPReceiver/interface/TCPReceiver.h"

using namespace HCAL_HLX;

//
// class decleration
//

class HLXMonitor : public edm::EDAnalyzer 
{

   public:
      explicit HLXMonitor(const edm::ParameterSet&);
      ~HLXMonitor();
      
   private:
      virtual void beginJob(const edm::EventSetup&) ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob();

      void SetupHists();
      void FillHistoBX(const LUMI_SECTION&);
      void FillHistoDist(const LUMI_SECTION&);
      void FillHistoHFCompare(const LUMI_SECTION&);
      void FillHistoAvg(const LUMI_SECTION&);

      //  void FillHistoHistory(const LUMI_SECTION&);

      // ----------member data ---------------------------
      TCPReceiver HT;      

      MonitorElement * Set1Below[36];
      MonitorElement * Set1Between[36];
      MonitorElement * Set1Above[36];
      MonitorElement * Set2Below[36];
      MonitorElement * Set2Between[36];
      MonitorElement * Set2Above[36];
      MonitorElement * ETSum[36];

      MonitorElement * HFCompareEtSum;
      MonitorElement * HFCompareOccBelowSet1;
      MonitorElement * HFCompareOccBetweenSet1;
      MonitorElement * HFCompareOccAboveSet1;
      MonitorElement * HFCompareOccBelowSet2;
      MonitorElement * HFCompareOccBetweenSet2;
      MonitorElement * HFCompareOccAboveSet2;

      MonitorElement * AvgEtSum;
      MonitorElement * AvgOccBelowSet1;
      MonitorElement * AvgOccBetweenSet1;
      MonitorElement * AvgOccAboveSet1;
      MonitorElement * AvgOccBelowSet2;
      MonitorElement * AvgOccBetweenSet2;
      MonitorElement * AvgOccAboveSet2;

      DQMStore* dbe_;

      unsigned int numActiveTowersSet1;
      unsigned int numActiveTowersSet2;

      unsigned int counter;
      unsigned char *rData;
      short int SectionComplete;
  
      // Parameters
      int listenPort;
      double XMIN,  XMAX;
      unsigned int NBINS;
      bool Accumulate;  
      std::string OutputFile;
      std::string OutputDir;
      std::string Style;   // BX, History, Distribution
      int SavePeriod;
      unsigned int NUM_HLX;
      unsigned int NUM_BUNCHES;
      unsigned int AquireMode;
      unsigned int TriggerBX;

      std::string monitorName_;
      int prescaleEvt_;

      unsigned int reconnTime;
      std::string DistribIP;

      unsigned int set1BelowIndex;
      unsigned int set1BetweenIndex;
      unsigned int set1AboveIndex;
      unsigned int set2BelowIndex;
      unsigned int set2BetweenIndex;
      unsigned int set2AboveIndex;

      unsigned int runNumLength;
      unsigned int secNumLength;

      std::string OccXAxisTitle;
      std::string OccYAxisTitle;
      std::string EtXAxisTitle;
      std::string EtYAxisTitle;

      HCAL_HLX::LUMI_SECTION lumiSection;

};

#endif
