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

#ifndef H_CNewToDoTiming
#define H_CNewToDoTiming

#include "CNewTimingPanel.h"

class CDateTimeZoneSelect;
class CDurationSelect;

class JXRadioGroup;
class JXTextCheckbox;
class JXTextRadioButton;

// ===========================================================================
//	CNewToDoTiming

class CNewToDoTiming : public CNewTimingPanel
{
public:
	CNewToDoTiming(JXContainer* enclosure,
						const HSizingOption hSizing, const VSizingOption vSizing,
						const JCoordinate x, const JCoordinate y,
						const JCoordinate w, const JCoordinate h)
		: CNewTimingPanel(enclosure, hSizing, vSizing, x, y, w, h) {}
	virtual				~CNewToDoTiming() {}

	virtual void	OnCreate();

	virtual bool	GetAllDay() const;
	virtual void	GetTimezone(iCal::CICalendarTimezone& tz) const;

	virtual void	SetToDo(const iCal::CICalendarVToDo& vtodo, const iCal::CICalendarComponentExpanded* expanded);
	virtual void	GetToDo(iCal::CICalendarVToDo& vtodo);

	virtual void	SetReadOnly(bool read_only);

protected:
	enum
	{
		eDue_NoDue = 1,
		eDue_DueBy,
		eDue_Start
	};

	// UI Objects
// begin JXLayout1

    JXTextCheckbox*      mAllDay;
    JXRadioGroup*        mDueGroup;
    JXTextRadioButton*   mNoDue;
    JXTextRadioButton*   mDueBy;
    CDateTimeZoneSelect* mDueDateTimeZone;
    JXTextRadioButton*   mStarts;
    CDateTimeZoneSelect* mStartDateTimeZone;
    CDurationSelect*     mDuration;

// end JXLayout1

	virtual void Receive(JBroadcaster* sender, const Message& message);
	
			void	DoAllDay(bool set);
			void	DoDueGroup(JIndex group);
};

#endif
