#include <iostream>
#include <string>

using namespace std;


//File manager class
class FileManager {
protected:
    string currentPath;

public:
    FileManager(const string& path = "./") : currentPath(path) {} // constructor


    //virtual functions that will be realized
    virtual void displayContents() = 0;
    virtual void create(const string& name) = 0;
    virtual void remove(const string& name) = 0;
    virtual void rename(const string& oldName, const string& newName) = 0;
    virtual void copy(const string& source, const string& destination) = 0;
    virtual void move(const string& source, const string& destination) = 0;
    virtual size_t calculateSize(const string& name) = 0;
    virtual void search(const string& mask) = 0;

    virtual ~FileManager() {}
};

//Directory sub-class
class Directory : public FileManager {
public:
    Directory(const string& path = "./") : FileManager(path) {}


    //methods

    // Content display
    void displayContents() override {
        cout << "Contents of directory: " << currentPath << endl;
        system(("dir " + currentPath).c_str()); //by using windows dir command
    }

    //create folder
    void create(const string& name) override {
        string command = "mkdir " + currentPath + name; // by using windows mkdir command
        system(command.c_str());
    }
    // remove folder
    void remove(const string& name) override {
        string command = "rmdir /S /Q " + currentPath + name;  // by using windows rmdir on folder with /S content without confirmation /Q
        system(command.c_str());
    }

    // rename a folder
    void rename(const string& oldName, const string& newName) override {
        string command = "rename " + currentPath + oldName + " " + newName;
        system(command.c_str());
    }

    // copy folder with all contents
    void copy(const string& source, const string& destination) override {
        string command = "xcopy /E /I " + currentPath + source + " " + currentPath + destination;
        system(command.c_str());
    }

    // move a folder
    void move(const string& source, const string& destination) override {
        string command = "move " + currentPath + source + " " + currentPath + destination;
        system(command.c_str());
    }

    size_t calculateSize(const string& name) override {
        cout << "Calculating size for: " << name << endl;
        system(("dir /a/s " + currentPath).c_str());

    }
    // search files by their mask
    void search(const string& mask) override {
        string command = "dir /S /B " + currentPath + mask;
        system(command.c_str());
    }
};

int main() {

    // manager object working with temp folder
    Directory manager("C:\\temp\\");

    // programm menu
    int choice;
    string name, newName, destination;

    do {
        cout << "\nFile Manager Options:\n";
        cout << "1. Display Contents\n";
        cout << "2. Create Folder\n";
        cout << "3. Delete Folder\n";
        cout << "4. Rename Folder\n";
        cout << "5. Copy Folder\n";
        cout << "6. Move Folder\n";
        cout << "7. Search Files\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            manager.displayContents();
            break;
        case 2:
            cout << "Enter folder  to create: ";
            cin >> name;
            manager.create(name);
            break;
        case 3:
            cout << "Enter folder  to delete: ";
            cin >> name;
            manager.remove(name);
            break;
        case 4:
            cout << "Enter current folder name: ";
            cin >> name;
            cout << "Enter new folder name: ";
            cin >> newName;
            manager.rename(name, newName);
            break;
        case 5:
            cout << "Enter source name: ";
            cin >> name;
            cout << "Enter destination name: ";
            cin >> destination;
            manager.copy(name, destination);
            break;
        case 6:
            cout << "Enter source  name: ";
            cin >> name;
            cout << "Enter destination name: ";
            cin >> destination;
            manager.move(name, destination);
            break;
        case 7:
            cout << "Enter search mask (e.g., *.txt): ";
            cin >> name;
            manager.search(name);
            break;
        case 8:
            cout << "Exiting...\n";
            break;
        default:
            cout << "you are Invalid\n";
        }

    } while (choice != 8);

}
