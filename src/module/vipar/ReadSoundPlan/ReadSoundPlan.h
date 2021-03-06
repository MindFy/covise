/* This file is part of COVISE.

   You can use it under the terms of the GNU Lesser General Public License
   version 2.1 or later, see lgpl-2.1.txt.

 * License: LGPL 2+ */

#ifndef _READ_SOUNDPLAN_H
#define _READ_SOUNDPLAN_H
/**************************************************************************\
**                                                           (C)1998 RUS  **
**                                                                        **
** Description: Read module Elmer data format         	                  **
**                                                                        **
**                                                                        **
**                                                                        **
**                                                                        **
**                                                                        **
**                                                                        **
** History:                                                               **
** May   98	    U. Woessner	    V1.0                                      **
** March 99	    D. Rainer	    added comments                            **
** September 99 D. Rainer       new api                                   **
*\**************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#ifndef _WIN32
#include <unistd.h>
#endif

#include <api/coModule.h>
using namespace covise;

class ReadSoundPlan : public coModule
{

private:
    //  member functions
    virtual int compute(const char *port);

    coOutputPort *meshOutPort;
    //   coOutputPort *velOutPort;
    coOutputPort *daySoundOutPort;
    coOutputPort *nightSoundOutPort;

    coFileBrowserParam *filenameParam;

public:
    ReadSoundPlan(int argc, char **argv);
    virtual ~ReadSoundPlan();
};

#endif
