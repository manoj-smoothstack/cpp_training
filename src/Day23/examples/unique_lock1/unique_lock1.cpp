#include <mutex>
#include <memory>
#include <map>
#include <iostream>
#include <thread>
#include <vector>
#include <cassert>
#define NUM_RECS 1000
#define NUM_THREADS 5

struct Record {
    //Constructors...
    int id;    
    //More data...    
    std::mutex mutex;
};

//Container of Records. It is loaded once when the application starts.
std::map<int, std::shared_ptr<Record>> records; 

class LockedRecord {
    std::shared_ptr<Record> ptr;
    std::unique_lock<std::mutex> lock;
public:
    LockedRecord() = default;
    //Initializes Record pointer and the unique_lock
    LockedRecord(const std::shared_ptr<Record>& p): ptr(p), lock(p->mutex) {} 
    bool ownsRecord() const { return ptr != nullptr; }
    Record& record() const { 
        //throw an exception here if 'ptr' is null
        return *ptr; 
    }
};

LockedRecord getAndPreprocess(int id) {
    //Find Record
    auto it = records.find(id);
    if (it != records.end()) { // Found record
        //Found record
        LockedRecord lr{it->second}; //Create a LockedRecord, it acquires a lock
        // Process Record and Return LockedRecord. It transfers the lock's ownership
        return lr;
     }
     //Record not found. Return an empty LockedRecord
     return {}; 
}

void process(int id) {
     //std::cout << "thread_id = " << std::this_thread::get_id() << std::endl;
     //Fetch a preprocessed locked Record
     auto lr = getAndPreprocess(id);
     //Check if the LockedRecord owns a Record
     if (lr.ownsRecord()) {
         //Record is found, preprocessed, and locked.
         // std::cout << lr.record().id << "\n";
     } else assert(false);
     //Record is unlocked here on return
}

void myfunc(void) {
    for (int ii = 0; ii < NUM_RECS; ii++) {
        process(ii); 
    }
}

int main(void) {
    for (int ii = 0; ii < NUM_RECS; ii++) {
        Record* record = new Record{ii, std::mutex()};
        std::shared_ptr<Record> sp{record};
        records.insert(std::pair(ii, sp));
    }

    std::vector<std::thread> threads;
    for (int ii = 0; ii < NUM_THREADS; ii++) {
        std::thread id(myfunc);
        threads.push_back(std::move(id));
    }
    for (auto& t: threads)
        t.join();
}

