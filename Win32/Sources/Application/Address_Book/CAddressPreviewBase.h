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


// Header for CAddressPreviewBase class

#ifndef __CADDRESSPREVIEWBASE__MULBERRY__
#define __CADDRESSPREVIEWBASE__MULBERRY__

#include "CGrayBackground.h"

// Classes
class CAddressBook;

class CAddressPreviewBase : public CGrayBackground
{
public:
				CAddressPreviewBase()
					{ mAdbk = NULL; }
	virtual 	~CAddressPreviewBase() {}

	virtual void	Close() = 0;
	virtual void	Focus() = 0;

			void	SetAddressBook(CAddressBook* adbk)
				{ mAdbk = adbk; }

protected:
	CAddressBook*	mAdbk;
};

#endif
