#include <iostream>
#include <string>
#include <queue>

// Minimal Printer implementation to replace missing "Printer.h"
class Printer {
    struct Job { int id; std::string owner; int pages; };
    std::queue<Job> q;
public:
    void addJob(int id, const std::string &owner, int pages) {
        q.push(Job{id, owner, pages});
    }
    void showQueue() const {
        if (q.empty()) {
            std::cout << "Queue is empty\n";
            return;
        }
        // Make a copy to iterate without modifying the real queue
        std::queue<Job> copy = q;
        std::cout << "Current print queue:\n";
        while (!copy.empty()) {
            const Job &j = copy.front();
            std::cout << "Job " << j.id << ": " << j.owner << " (" << j.pages << " pages)\n";
            copy.pop();
        }
    }
    void processJob() {
        if (q.empty()) {
            std::cout << "No jobs to process\n";
            return;
        }
        Job j = q.front(); q.pop();
        std::cout << "Processing job " << j.id << " for " << j.owner << " (" << j.pages << " pages)\n";
    }
};

int main() {
    Printer printer;
    printer.addJob(1, "Alice", 5);
    printer.addJob(2, "Bob", 3);
    printer.addJob(3, "Charlie", 10);

    printer.showQueue();

    printer.processJob();
    printer.processJob();
    printer.showQueue();

    return 0;
}
