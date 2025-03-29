#include <gtkmm.h>
#include <iostream>
#include <glibmm/fileutils.h>
#include <gtkmm/treeview.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/liststore.h>
#include <gtkmm/treemodel.h>
#include <gtkmm/treemodelcolumn.h>

class FileManagerWindow : public Gtk::Window {
public:
    FileManagerWindow() {
        set_title("IV File Manager");
        set_default_size(800, 600);
        
        m_VBox.set_orientation(Gtk::ORIENTATION_VERTICAL);
        add(m_VBox);

        m_RefTreeModel = Gtk::ListStore::create(m_Columns);
        m_TreeView.set_model(m_RefTreeModel);

        m_ScrolledWindow.add(m_TreeView);
        m_VBox.pack_start(m_ScrolledWindow);

        load_file_data("/path/to/your/directory");

        show_all_children();
    }

    virtual ~FileManagerWindow() {}

protected:
    // Columns for TreeView
    class ModelColumns : public Gtk::TreeModelColumnRecord {
    public:
        ModelColumns() {
            add(m_col_name);
            add(m_col_path);
        }
        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
        Gtk::TreeModelColumn<Glib::ustring> m_col_path;
    };
    ModelColumns m_Columns;

    Gtk::Box m_VBox{Gtk::ORIENTATION_VERTICAL};
    Gtk::ScrolledWindow m_ScrolledWindow;
    Gtk::TreeView m_TreeView;
    Glib::RefPtr<Gtk::ListStore> m_RefTreeModel;

    void load_file_data(const std::string& dir_path) {

        Glib::Dir dir(dir_path);
        std::string file;
        while ((file = dir.read_name())) {
            Gtk::TreeModel::Row row = *(m_RefTreeModel->append());
            row[m_Columns.m_col_name] = file;
            row[m_Columns.m_col_path] = dir_path + "/" + file;
        }
    }
};

int main(int argc, char* argv[]) {
    auto app = Gtk::Application::create(argc, argv, "com.example.filemanager");
    FileManagerWindow window;
    return app->run(window);
}
