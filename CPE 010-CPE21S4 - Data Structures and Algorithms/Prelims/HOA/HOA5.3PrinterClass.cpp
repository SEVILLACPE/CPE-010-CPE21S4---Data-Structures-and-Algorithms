#include <iostream>
#include <string>

using namespace std;

struct Job {
    int jobID;
    string userName;
    int numPages;
    Job* next;

    Job(int id, const char* name, int pages)
        : jobID(id), userName(name), numPages(pages), next(nullptr) {}
};

class Printer {
private:
    Job* front;
    Job* rear;

public:
    Printer() {
        front = rear = nullptr;
    }

    void addJob(int id, const char* name, int pages) {
        Job* newJob = new Job(id, name, pages);
        if (rear == nullptr) {
            front = rear = newJob;
        } else {
            rear->next = newJob;
            rear = newJob;
        }
        cout << "Job added: " << name << " (" << pages << " pages)\n";
    }

    void processJob() {
        if (front == nullptr) {
            cout << "No jobs to process.\n";
            return;
        }
        cout << "Processing job: " << front->userName << " (" << front->numPages << " pages)\n";
        Job* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void showQueue() {
        Job* temp = front;
        cout << "\nPending Jobs:\n";
        while (temp != nullptr) {
            cout << temp->jobID << " - " << temp->userName << " (" << temp->numPages << " pages)\n";
            temp = temp->next;
        }
    }
};
