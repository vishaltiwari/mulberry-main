/*
    Copyright (c) 2007 Cyrus Daboo. All rights reserved.
    
    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at
    
        http://www.apache.org/licenses/LICENSE-2.0
    
    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
*/


// Header for CForwardActionDialog class

#ifndef __CFORWARDACTIONDIALOG__MULBERRY__
#define __CFORWARDACTIONDIALOG__MULBERRY__

#include <LDialogBox.h>

#include "CActionItem.h"

// Constants

// Panes
const	PaneIDT		paneid_ForwardActionDialog = 1221;
const	PaneIDT		paneid_ForwardActionTo = 'ADTO';
const	PaneIDT		paneid_ForwardActionCC = 'ADCC';
const	PaneIDT		paneid_ForwardActionBcc = 'ADBC';
const	PaneIDT		paneid_ForwardActionQuote = 'QUOT';
const	PaneIDT		paneid_ForwardActionAttach = 'ATCH';
const	PaneIDT		paneid_ForwardActionText = 'TEXT';
const	PaneIDT		paneid_ForwardActionUseTied = 'TIED';
const	PaneIDT		paneid_ForwardActionUseIdentity = 'UIDN';
const	PaneIDT		paneid_ForwardActionIdentity = 'IDEN';
const	PaneIDT		paneid_ForwardActionCreateDraft = 'DRFT';

// Mesages
const	MessageT	msg_ForwardActionText = 'TEXT';
const	MessageT	msg_ForwardActionUseTied = 'TIED';
const	MessageT	msg_ForwardActionUseIdentity = 'UIDN';
const	MessageT	msg_ForwardActionIdentity = 'IDEN';

// Resources
const	ResIDT		RidL_CForwardActionDialogBtns = 1221;

// Type
class CIdentityPopup;
class CTextFieldX;
class LCheckBox;
class LRadioButton;

class CForwardActionDialog : public LDialogBox
{
private:
	CTextFieldX*		mTo;
	CTextFieldX*		mCC;
	CTextFieldX*		mBcc;
	LCheckBox*			mQuote;
	LCheckBox*			mAttach;
	LRadioButton*		mUseTied;
	LRadioButton*		mUseIdentity;
	CIdentityPopup*		mIdentityPopup;
	LCheckBox*			mCreateDraft;

	cdstring			mText;
	cdstring			mCurrentIdentity;

public:
	enum { class_ID = 'Fact' };

					CForwardActionDialog();
					CForwardActionDialog(LStream *inStream);
	virtual 		~CForwardActionDialog();

	static bool PoseDialog(CActionItem::CActionForward& details);

protected:
	virtual void	FinishCreateSelf(void);					// Do odds & ends

	virtual void	ListenToMessage(MessageT inMessage, void *ioParam);
			void	SetDetails(CActionItem::CActionForward& details);		// Set the dialogs info
			void	GetDetails(CActionItem::CActionForward& details);		// Get the dialogs return info

			void	SetText();
};

#endif
