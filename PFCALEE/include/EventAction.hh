#ifndef EventAction_h
#define EventAction_h 1

#include "SamplingSection.hh"

#include "G4ThreeVector.hh"
#include "G4UserEventAction.hh"
#include "globals.hh"

#include "TFile.h"
#include "TTree.h"
#include "SamplingSection.hh"
#include "G4SiHit.hh"
#include "HGCSSEvent.hh"
#include "HGCSSSamplingSection.hh"
#include "HGCSSSimHit.hh"
#include "HGCSSGenParticle.hh"
#include "HGCSSGeometryConversion.hh"

#include <vector>
#include <map>
#include "fstream"

class EventActionMessenger;

class EventAction: public G4UserEventAction {
public:
	EventAction();
	virtual ~EventAction();
	void BeginOfEventAction(const G4Event*);
	void EndOfEventAction(const G4Event*);

	void Detect(G4double eRawDep,G4int trackID,G4double kinEng,G4VPhysicalVolume *volume);

	void SetPrintModulo(G4int val) {
		printModulo = val;
	}
	;
	void Add(std::vector<SamplingSection> *newDetector) {
		detector_ = newDetector;
	}
	HGCSSGenParticleVec genvec_,hadvec_;
	G4int hadronicInts;
	std::vector<int> novelTrackIds;
private:
	std::vector<SamplingSection> *detector_;
	G4int evtNb_, printModulo,initLayer;
	int nSteps,nMainSteps;
	G4double depCut;
	G4double summedDep;
	HGCSSGeometryConversion* geomConv_;
	Int_t step[1000000],stepMain[1000000];
	Float_t stepDep[1000000],mainKinEng[1000000];

	TFile *outF_;
	TTree *tree_;
	HGCSSEvent event_;

	EventActionMessenger* eventMessenger;

	//std::ofstream fout_;

};

#endif

