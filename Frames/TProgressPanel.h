/*---------------------------------------------------------------------------
$Id: TProgressPanel.h 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#ifndef TProgressPanelH
#define TProgressPanelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TSpeedAverager
{
public:
	__fastcall TSpeedAverager(unsigned int Capacity);
	__fastcall ~TSpeedAverager();

	void __fastcall Clear();
	void __fastcall Add(float Val);
	float __fastcall GetAverage();
protected:
	float* FBuffer;
	unsigned int FSize;
	unsigned int FMostOld;

	unsigned int FCapacity;
};

enum TProgressPanelTermination {pptNone=0, pptStop=1, pptSkip=2};

#define ETA_NONE	0
#define ETA_CURRENT 1
#define ETA_OVERALL 2
#define ETA_ALL 	ETA_CURRENT|ETA_OVERALL

class TProgressPanel : public TFrame
{
__published:	// IDE-managed Components
	TLabel *lblTitle;
	TBevel *bvlTitle;
	TProgressBar *pbOverall;
	TLabel *lblOverallProgress;
	TLabel *lblOvrPercent;
	TProgressBar *pbCurrent;
	TLabel *lblOperation;
	TLabel *lblCurPercent;
	TLabel *lblOvrCompleted;
	TLabel *lblOvrTimeleft;
	TLabel *lblCurCompleted;
	TLabel *lblCurTimeleft;
	TButton *btnSkip;
	TButton *btnStop;
	TLabel *lblOvrElapsed;
	TLabel *lblCurElapsed;
	void __fastcall btnSkipClick(TObject *Sender);
	void __fastcall btnStopClick(TObject *Sender);

protected:	// User declarations
	UnicodeString FOperation;

	bool FActive;
	void __fastcall setActive(bool Val);

	UnicodeString __fastcall getTitle() 			{return this->lblTitle->Caption;};
	void __fastcall setTitle(UnicodeString Val)		{this->lblTitle->Caption = Val + L": ";};

	TProgressPanelTermination FTerminated;

	UnicodeString FSubOperation;
	float FCompleteRatio;
	long double FTotalWork, FCommittedWork, FCurrentWork;
	__int64 FTotalBytes, FCommittedBytes, FCurrentBytes, FCompletedBytes;

	bool FEnableSpeed;
	unsigned char FEnableETA;
	TSpeedAverager* AveragerSpeed;
	TSpeedAverager* AveragerETA;
	DWORD FLastTicks;
	__int64 FLastBytes;
	long double FLastWork;

	bool FEnableSkip;
	void __fastcall setEnableSkip(bool Val);
	UnicodeString FCompletedText;

	float FCurElapsed, FOvrElapsed;

public:		// User declarations
	__fastcall TProgressPanel(TComponent* Owner);
	__fastcall ~TProgressPanel();

    __property bool Active = {read=FActive, write=setActive};
	__property UnicodeString Title = {read=getTitle, write=setTitle};

	__property TProgressPanelTermination Terminated = {read=FTerminated, write=FTerminated};

	__property UnicodeString SubOperation = {read=FSubOperation, write=FSubOperation};
	__property float CompleteRatio = {read=FCompleteRatio, write=FCompleteRatio};
	__property long double TotalWork = {read=FTotalWork, write=FTotalWork};
	__property long double CommittedWork = {read=FCommittedWork, write=FCommittedWork};
	__property long double CurrentWork = {read=FCurrentWork, write=FCurrentWork};
	__property __int64 TotalBytes = {read=FTotalBytes, write=FTotalBytes};
	__property __int64 CommittedBytes = {read=FCommittedBytes, write=FCommittedBytes};
	__property __int64 CurrentBytes = {read=FCurrentBytes, write=FCurrentBytes};
	__property __int64 CompletedBytes = {read=FCompletedBytes, write=FCompletedBytes};
	__property bool EnableSpeed = {read=FEnableSpeed, write=setEnableSpeed};
	__property unsigned char EnableETA = {read=FEnableETA, write=setEnableETA};
	__property bool EnableSkip = {read=FEnableSkip, write=setEnableSkip};
	__property UnicodeString CompletedText = {read = FCompletedText, write=FCompletedText};

	void __fastcall UpdateProgress(bool Regular=true);
	void __fastcall ResetProgress();
	void __fastcall StartOperation(UnicodeString Operation=L"", long double CurrentWork = 0.0);

	void __fastcall setEnableSpeed(bool Val);
	void __fastcall setEnableETA(unsigned char Val);
};
//---------------------------------------------------------------------------
extern PACKAGE TProgressPanel *ProgressPanel;
//---------------------------------------------------------------------------
#endif
