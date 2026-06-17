#include <iostream>
#include <cstring> 
using namespace std;

class MemoryBlock {
private:
    char* data;
    size_t size;

public:
    MemoryBlock(size_t s = 0) : size(s) {
        if (size > 0) {
            data = new char[size];
            memset(data, 0, size);
            cout << "Allocated " << size / (1024.0 * 1024.0) << " MB\n";
        } else {
            data = nullptr;
        }
    }

    MemoryBlock(const MemoryBlock& other) : size(other.size) {
        if (size > 0) {
            data = new char[size];
            memcpy(data, other.data, size);
            cout << "MemoryBlock deep-copied (" << size / (1024.0 * 1024.0) << " MB)\n";
        } else {
            data = nullptr;
        }
    }

    ~MemoryBlock() {
        if (data) {
            delete[] data;
            cout << "Freed " << size / (1024.0 * 1024.0) << " MB\n";
        }
    }

    void setByte(size_t index, char value) {
        if (index < size && data) data[index] = value;
    }
    char getByte(size_t index) const {
        if (index < size && data) return data[index];
        return 0;
    }

    size_t getSize() const { return size; }
};

int main() {
    cout << "Creating 3 MemoryBlock objects inside scope...\n";
    for (int i = 0; i < 3; ++i) {
        MemoryBlock m(1024 * 1024);
    }
    cout << "Exited loop — local MemoryBlock objects were destroyed automatically.\n\n";

    MemoryBlock* p = new MemoryBlock(2 * 1024 * 1024); 
    delete p; 

    MemoryBlock a(512 * 1024); 
    a.setByte(0, 42);
    MemoryBlock b = a;
    cout << "First byte of copy: " << (int)b.getByte(0) << "\n";

    return 0;
}



// #include <iostream>
// using namespace std;

// class MemoryBlock {
//     char* data;
//     size_t size;
// public:
//     MemoryBlock(size_t s) {
//         size = s;
//         data = new char[size];
//         cout << "Allocated " << size / (1024.0 * 1024.0) << " MB\n";
//     }
//     ~MemoryBlock() {
//         delete[] data;
//         cout << "Freed " << size / (1024.0 * 1024.0) << " MB\n";
//     }
// };

// int main() {
//     for (int i = 0; i < 3; i++) {
//         MemoryBlock m(1024 * 1024);
//     }
//     cout << "All objects destroyed safely.\n";
// }
