#include <cstring>

class Job {
public:
    int jobID;
    char userName[50];
    int numPages;
    Job* next; // for linked list implementation

    Job(int id, const char* name, int pages) {
        jobID = id;
        std::strncpy(userName, name, sizeof(userName) - 1);
        userName[sizeof(userName) - 1] = '\0';
        numPages = pages;
        next = nullptr;
    }
};
