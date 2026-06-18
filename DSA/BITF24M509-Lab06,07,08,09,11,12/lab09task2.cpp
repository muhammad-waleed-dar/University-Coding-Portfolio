#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Job
{
    int id;
    string customer;
    string service;
    int timeRequired;
};

void showServices()
{
    cout << "Available Services:" << endl;
    cout << "  1. Sole Replacement" << endl;
    cout << "  2. Polishing" << endl;
    cout << "  3. Stitching" << endl;
    cout << "  4. Glue Work" << endl;
    cout << "  5. Heel Repair" << endl;
    cout << endl;
}

void addJob(queue<Job>& cobblerQueue, int id, string name, string service, int time)
{
    Job j;
    j.id = id;
    j.customer = name;
    j.service = service;
    j.timeRequired = time;

    cobblerQueue.push(j);

    cout << "Job Added -> ID: " << id
         << ", Customer: " << name
         << ", Service: " << service
         << ", Time: " << time << " mins" << endl;
}

void processJob(queue<Job>& cobblerQueue)
{
    if (cobblerQueue.empty())
    {
        cout << "No jobs to process\n";
        return;
    }

    Job j = cobblerQueue.front();
    cobblerQueue.pop();

    cout << "\nProcessing Job..." << endl;
    cout << "  ID: " << j.id << endl;
    cout << "  Customer: " << j.customer << endl;
    cout << "  Service: " << j.service << endl;
    cout << "  Time Required: " << j.timeRequired << " mins" << endl;
}

int main()
{
    queue<Job> cobblerQueue;

    showServices();

    addJob(cobblerQueue, 1, "Ali",   "Sole Replacement", 10);
    addJob(cobblerQueue, 2, "Sara",  "Polishing",         5);
    addJob(cobblerQueue, 3, "Ahmed", "Stitching",         7);
    addJob(cobblerQueue, 4, "Zara",  "Glue Work",         6);
    addJob(cobblerQueue, 5, "Usman", "Heel Repair",       8);

    cout << "\n--- Processing Jobs (FIFO) ---\n";

    while (!cobblerQueue.empty())
    {
        processJob(cobblerQueue);
    }

    cout << "\nAll jobs completed!" << endl;

    return 0;
}