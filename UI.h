#include <CtrlLib/CtrlLib.h>
using namespace Upp;

class IVFileManagerUI : public TopWindow {
    FileList fileList;
    ImageCtrl thumbnail;
    Label info;

    void LoadDirectory(const String& path);
    void OnFileSelect();

public:
    IVFileManagerUI();
};