#ifndef _IVFileManager_IVFileManager_h
#define _IVFileManager_IVFileManager_h

#include <CtrlLib/CtrlLib.h>

using namespace Upp;

#define LAYOUTFILE <IVFileManager/IVFileManager.lay>
#include <CtrlCore/lay.h>

class IVFileManager : public WithIVFileManagerLayout<TopWindow> {
public:
	IVFileManager();
};

#endif
