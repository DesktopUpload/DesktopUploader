/*---------------------------------------------------------------------------
$Id: TProgressPanel.cpp 465 2010-04-03 20:44:16Z anton $
---------------------------------------------------------------------------*/
#include <vcl.h>
#include <StrUtils.hpp>
#include <Math.hpp>

#include "Utils.h"
#include "SrvAdapter.h"

#pragma hdrstop

#include "TProgressPanel.h"

extern TSrvAdapterModule* SrvAdapterModule;

//Value for ProgressBar Max property. Cannot use real work amount because it could be over 2GB
#define PROGRESSBAR_GRADATION 		1000000
//Maximum ETA for display. Greater values are assumed infinity
#define MAX_ETA 					864000

//Counts of samples for transfer speed & progress advance averaging:
//(If not defined then all samples recorded will be used in averaging)
#define AVG_SPEED				30
#define AVG_ETA					30

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
// Progress display template
#define TXT_COMPLETED "%s: %s of %s"
//---------------------------------------------------------------------------

__fastcall TProgressPanel::TProgressPanel(TComponent* Owner)
	: TFrame(Owner)
{
	this->pbCurrent->Max = PROGRESSBAR_GRADATION;
	this->pbOverall->Max = PROGRESSBAR_GRADATION;

	this->FCompletedText = L"Completed";

	#ifdef AVG_SPEED
		this->AveragerSpeed = new TSpeedAverager(AVG_SPEED);
	#else
		this->AveragerSpeed = NULL;
	#endif

	#ifdef AVG_ETA
		this->AveragerETA = new TSpeedAverager(AVG_ETA);
	#else
		this->AveragerETA = NULL;
	#endif

	this->setActive(false);
}
//---------------------------------------------------------------------------

__fastcall TProgressPanel::~TProgressPanel()
{
	delete this->AveragerSpeed;
	delete this->AveragerETA;

	this->setActive(false);
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::setActive(bool Val)
{
	this->FActive = Val;
	this->FTerminated = pptNone;
	this->lblTitle->Visible = Val;

	this->btnStop->Enabled = Val;
	this->btnSkip->Enabled = Val? this->FEnableSkip : false;

	if (Val) {
		this->ResetProgress();
	}
	else {
		this->pbCurrent->Position = 0;
		this->pbOverall->Position = 0;

		this->lblCurPercent->Caption = L"";
		this->lblOvrPercent->Caption = L"";

		this->lblOperation->Caption = L"";

		this->lblCurCompleted->Caption = L"";
		this->lblCurTimeleft->Caption = L"";
		this->lblCurElapsed->Caption = L"";
		this->lblOvrCompleted->Caption = L"";
		this->lblOvrTimeleft->Caption = L"";
		this->lblOvrElapsed->Caption = L"";
	}
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::UpdateProgress(bool Regular)
{
	float interval = 0.0;
	if (Regular) {
		DWORD ticks = GetTickCount();
		if (ticks > this->FLastTicks) {
			interval = ((float)(ticks - this->FLastTicks))/1000.0;
			this->FCurElapsed += interval;
			this->FOvrElapsed += interval;
		}
		this->FLastTicks = ticks;
	}

	UnicodeString oper = this->FOperation;

	float cur, ovr;
	long double cur_completed, ovr_completed;
	if (this->FTotalWork > 0.00) {
		cur = this->FCompleteRatio;
		cur_completed = this->FCurrentWork*(long double)cur;
		ovr_completed = this->FCommittedWork + cur_completed;
		if (this->FTotalWork > 0.0) {
			ovr = ovr_completed/this->FTotalWork;
		}
		else {
			ovr = 0.0;
        }
	}
	else {
		cur = 0.00;
		ovr = 0.00;
		cur_completed = 0.0;
		ovr_completed = 0.0;
	}

	UnicodeString cur_bytes, ovr_bytes, cur_eta, ovr_eta;
	if (this->FCurrentBytes > 0) {
		cur_bytes = Format(TXT_COMPLETED,
			ARRAYOFCONST((this->FCompletedText, FormatDataSize(this->FCompletedBytes),
			FormatDataSize(this->FCurrentBytes))));
	}
	if (this->FTotalBytes > 0) {
		ovr_bytes = Format(TXT_COMPLETED,
			ARRAYOFCONST((this->FCompletedText, FormatDataSize(this->FCommittedBytes + this->FCompletedBytes),
			FormatDataSize(this->FTotalBytes))));
	}
	if (!this->FSubOperation.IsEmpty()) {
		if (cur_bytes.IsEmpty()) cur_bytes = this->FSubOperation + L"...";
		else cur_bytes += L" - " + this->FSubOperation;
	}

	if (Regular && (this->FEnableSpeed || this->FEnableETA!=ETA_NONE)) {
		if (interval > 0.0) {
			if (this->FEnableSpeed && this->FLastBytes >= 0) {
				float speed = ((float)(this->FCompletedBytes - this->FLastBytes))/interval;
				if (this->AveragerSpeed) {
					this->AveragerSpeed->Add(speed);
					speed = this->AveragerSpeed->GetAverage();
				}
				if (speed > 0) {
					ovr_bytes += L" at " + FormatDataSize(speed, true);
				}
			}

			if (this->FEnableETA!=ETA_NONE && this->FLastWork >= 0) {
				float speed = ((float)(ovr_completed - this->FLastWork))/interval;
				if (this->AveragerETA) {
					this->AveragerETA->Add(speed);
					speed = this->AveragerETA->GetAverage();
				}

				if (speed > 0.0) {
					long secs_current = Round((this->FCurrentWork - cur_completed)/speed);
					long secs_overall = Round((this->FTotalWork - ovr_completed)/speed);

					if (this->FEnableETA&ETA_CURRENT && secs_current > 0 && secs_current < MAX_ETA) {
						cur_eta = L"Time Left: " + FormatDuration(secs_current);
					}
					if (this->FEnableETA&ETA_OVERALL && secs_overall > 0 && secs_overall < MAX_ETA) {
						ovr_eta = L"Time Left: " + FormatDuration(secs_overall);
					}
				}
			}
		}

		if (this->EnableETA!=ETA_NONE) this->FLastWork = ovr_completed;
		if (this->EnableSpeed) this->FLastBytes = this->FCompletedBytes;
	}

	//Assign UI values
	this->lblOperation->Caption = ReplaceStr(oper, L"&", L"&&");

	this->pbCurrent->Position = cur * (float)PROGRESSBAR_GRADATION;
	this->lblCurPercent->Caption = IntToStr(Round(cur*100)) + L"%";
	this->pbOverall->Position = ovr * (float)PROGRESSBAR_GRADATION;
	this->lblOvrPercent->Caption = IntToStr(Round(ovr*100)) + L"%";

	this->lblCurCompleted->Caption = cur_bytes;
	this->lblOvrCompleted->Caption = ovr_bytes;

	if (Regular) {
		this->lblOvrTimeleft->Caption = ovr_eta;
		this->lblCurTimeleft->Caption = cur_eta;
	}

	this->lblCurElapsed->Caption = L"Elapsed: " + FormatDuration(this->FCurElapsed);
	this->lblOvrElapsed->Caption = L"Elapsed: " + FormatDuration(this->FOvrElapsed);

	this->Update();
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::ResetProgress()
{
	this->FOperation = L"";
	this->FSubOperation = L"";
	this->FCompleteRatio = 0;
	this->FTotalWork = 0.0;
	this->FCommittedWork = 0.0;
	this->FCurrentWork = 0.0;
	this->FTotalBytes = 0;
	this->FCommittedBytes = 0;
	this->FCurrentBytes = 0;
	this->FCompletedBytes = 0;

	if (this->AveragerETA) this->AveragerETA->Clear();
	if (this->AveragerSpeed) this->AveragerSpeed->Clear();
	this->FLastWork = -1;
	this->FLastBytes = -1;

	this->FCurElapsed = 0;
	this->FOvrElapsed = 0;

	this->UpdateProgress(false);

	this->FLastTicks = GetTickCount();
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::StartOperation(UnicodeString Operation,
	long double CurrentWork)
{
	this->FOperation = Operation;
	this->FSubOperation = SubOperation;
	this->FCompleteRatio = 0;
	this->FCompletedBytes = 0;

	this->FCurrentWork = CurrentWork;

	this->FCurrentBytes = 0;

	this->FCurElapsed = 0;

	this->UpdateProgress(false);
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::setEnableSpeed(bool Val)
{
	if (!Val) {
		if (this->AveragerSpeed) this->AveragerSpeed->Clear();
		this->FLastBytes = -1;
	}
	this->FEnableSpeed = Val;
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::setEnableETA(unsigned char Val)
{
	if (Val==ETA_NONE) {
		if (this->AveragerETA) this->AveragerETA->Clear();
		this->FLastWork = -1;
	}
	else if (!(Val|ETA_CURRENT))
		this->lblCurTimeleft->Caption = L"";
	else if (!(Val|ETA_OVERALL))
		this->lblOvrTimeleft->Caption = L"";

	this->FEnableETA = Val;
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::setEnableSkip(bool Val)
{
    this->FEnableSkip = Val;
	this->btnSkip->Enabled = Val;
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::btnSkipClick(TObject *Sender)
{
	this->Terminated = pptSkip;
	SrvAdapterModule->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TProgressPanel::btnStopClick(TObject *Sender)
{
	this->Terminated = pptStop;
	SrvAdapterModule->Terminate();
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
// TSpeedAverager
//---------------------------------------------------------------------------
__fastcall TSpeedAverager::TSpeedAverager(unsigned int Capacity)
{
	this->FCapacity = Capacity;
	this->FBuffer = new float[Capacity];
	this->Clear();
}
//---------------------------------------------------------------------------

__fastcall TSpeedAverager::~TSpeedAverager()
{
	delete [] this->FBuffer;
}
//---------------------------------------------------------------------------

void __fastcall TSpeedAverager::Clear()
{
	this->FSize = 0;
	this->FMostOld = 0;
}
//---------------------------------------------------------------------------

void __fastcall TSpeedAverager::Add(float Val)
{
	if (this->FSize < this->FCapacity) {
		this->FBuffer[this->FSize] = Val;
		this->FSize++;
	}
	else {
		this->FBuffer[this->FMostOld] = Val;
		this->FMostOld++;
		if (this->FMostOld > this->FCapacity-1) {
			this->FMostOld = 0;
		}
	}
}
//---------------------------------------------------------------------------

float __fastcall TSpeedAverager::GetAverage()
{
	float divider = (float)this->FSize;

	float result = 0.0;
	for (unsigned int i = 0; i < ((this->FSize < this->FCapacity)? this->FSize : this->FCapacity); i++)
	{
		result += this->FBuffer[i]/divider;
	}
	return result;
}
//---------------------------------------------------------------------------

