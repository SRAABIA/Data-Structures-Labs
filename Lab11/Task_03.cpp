/*
Task 3. Job scheduling helps the device to run the most important programs first. Those jobs are
stored in either a high-priority queue or a low-priority queue, depending on how
important the program is.
For example, processes that are fundamental to how the device operates (e.g. displaying
things to the screen, dealing with system input and output) have a higher priority than
user-installed applications (e.g. web browsers, music playing app, calculator app). At any
given time, jobs waiting in the high-priority queue will be executed first, in the order that
they were requested in. If there are no high-priority jobs waiting to be executed, then the
jobs in the low-priority queue can be executed.

Implement the following:
● Add code to the main() function so that every time a new job is created (i.e. every
time get_job is called), that job object is enqueued to the appropriate queue:
high_priority_queue or low priority_queue.
● Create a high_priority method to check if a job is high-priority (True) or lowpriority (False). Notice that get_job may also return no job (None) which will
NOT go into either queue, so that must be checked for as well.
● Complete the main() function so that whenever a process has finished indicated
(when process_complete returns True), a new process is started by dequeuing a
job from the appropriate queue. i.e. If there is at least one job in the high-priority
queue, it should be dequeued and assigned to the current_job variable. However,
if the high-priority queue is empty and there is at least one job in the low-priority
11 | Page
queue, then it should be dequeued and assigned to the current_job variable. If a
job has been successfully dequeued from either queue, the process running
variable should be set to True.
*/
#include<iostream>
#include<windows.h>
using namespace std;

class Job{
    public:
    int data,priority;
    Job *next;
    Job(){
        data=0; priority = 0;
        next = NULL;
    }
    Job(int d,int p){
        data=d; priority = p;
        next = NULL;
    }
};

Job*High_priority_queue = NULL;
Job*Low_priority_queue = NULL;

void Highenqueue(int d, int p){
    Job*temp = new Job();
    Job*current = NULL;
    Job*prev = NULL;
    temp->data = d;
    temp->priority = p;
    //if queue is empty
    if(High_priority_queue==NULL || p >= High_priority_queue->priority){
        temp->next = High_priority_queue;
        High_priority_queue = temp;
    }
    else{
        current = High_priority_queue;
        while(current!=NULL && p<=current->priority){
            prev = current;
            current = current->next;
        }
        temp->next = prev->next;
        prev->next = temp;
    }       
}

void Lowenqueue(int d, int p){
    Job*temp = new Job();
    Job*current = NULL;
    Job*prev = NULL;
    temp->data = d;
    temp->priority = p;
    //if queue is empty

    if(Low_priority_queue==NULL || p >= Low_priority_queue->priority){
        temp->next = Low_priority_queue;
        Low_priority_queue = temp;
           
    }
    else{
        current = Low_priority_queue;
        while(current!=NULL && p<=current->priority){
            prev = current;
            current = current->next;
        }
        temp->next = prev->next;
        prev->next = temp;
    }       
}

int get_job(){
    int id;
    int p;
    cout<<endl<<"\t============================================";
        cout<<endl<<"\tGet Job - ID & Priority";
        cout<<endl<<"\tCriteria for Low and High :";
        cout<<endl<<"\tHigh priority jobs are with priority >= 150";
        cout<<endl<<"\tLow priority jobs are with priority < 150";
        cout<<endl<<"\tJobs with priority < 0 are rejected.";
    cout<<endl<<"\t============================================";
    cout<<endl
    <<endl<<endl<<"\tEnter your ID: ";cin>>id;
    cout<<endl<<"\tEnter Priority: ";cin>>p;
    if(p<0){
        cout<<"\tSorry You Do Not Qualify For The Criteria.";
        return 0;
    }
    else if(p>=150){
        Highenqueue(id,p);
        return 2;
    }
    else{
        Lowenqueue(id,p);
        return 1;
    }
}

bool isexist(Job*obj){
    Job* temp = High_priority_queue;
    Job* temp2 = Low_priority_queue;
    while(temp!=NULL ){
        if(temp==obj){
            return true;
        }
        else {
            temp = temp->next;
        }
    }
    while(temp2!=NULL){
        if(temp2==obj){
            return true;
        }
        else {
            temp2 = temp2->next;
        }
    }
}

bool Check_Priority(Job* obj){
    bool condition = isexist(obj);
    if(condition){
        if(obj->priority<0){
            return NULL;
        }
        if(obj->priority >= 150){
            return true;
        }
        else if(obj->priority < 150){
            return false;
        }
    }
    else{
        cout<<endl<<"\tJob Application not found.";
    }
}

bool process_completes(){
    int g = 0;
    cout<<endl<<"\tEnter How Many Job Applications Are There: ";
    cin>>g;
    do{
        get_job();
        g--;
    }while(g!=0);
    return true;
}

Job* HighDequeu(){
    if(High_priority_queue == NULL){
        return NULL;
    }
    else{
        Job*temp=High_priority_queue;
        High_priority_queue = temp->next;
        // free(temp);
        return temp;
    }
}

Job* LowDequeu(){
    if(Low_priority_queue == NULL){
        return NULL;
    }
    else{
        Job*temp=Low_priority_queue;
        Low_priority_queue = temp->next;
        // free(temp);
        
        return temp;
    }
}

bool Interview_processing(){
    cout<<endl<<endl<<"\t------------------------------";
    cout<<endl<<"\tHigh Priority Jobs: ";
    Job*temp = HighDequeu();
    while(temp!=NULL){
        Sleep(160);
        cout<<endl<<endl<<"\t   ID: "<<temp->data<<"|| Priority: "<<temp->priority;
        temp = HighDequeu();
    }
    
    cout<<endl<<endl<<"\t------------------------------";
    cout<<endl<<"\tLow Priority Jobs: ";
    Job*temp2 = LowDequeu();
    while(temp2!=NULL){
        Sleep(160);
        cout<<endl<<endl<<"\t   ID: "<<temp2->data<<"|| Priority: "<<temp2->priority;
        temp2 = LowDequeu();
    }
    
    cout<<endl<<endl<<"\t============================================";
    cout<<endl<<endl<<"\tJobs Dequing Process Has Been Completed.";
    cout<<endl<<"\t============================================";
    return true;
}

int main(){
    if(process_completes() == true){
        cout<<endl<<"\t=====================================================================";
        cout<<endl<<"\tStarting Interview Processing For Job Applicants with Priority Order: ";
        cout<<endl<<"\t=====================================================================";
        Interview_processing();
    }
}
