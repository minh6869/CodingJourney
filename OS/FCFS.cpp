#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <math.h>
using namespace std;

struct Process{
    string name;
    string status = "";
    double timeAppear;
    double timeUse;
    double timeEnd = 0;
};


int count_process(){
    int num_process = 0;
    ifstream read;
    read.open("data.txt");
    char c;
    while(read){
        while(read && c != '\n'){
            read.get(c);
        }
        num_process += 1;
        read.get(c);
    }
    read.close();

    return num_process;
}

void read_data(Process *&list, int num_process){
    ifstream read;
    read.open("data.txt");
    string data;
    char c;
    list = new Process[num_process];

    for(int i=0; i < num_process; i++)
    {
        for(int j = 1; j <= 3; j++)
        {
            read >> data;
            if(j == 1)
                (*(list+i)).name = data;
            else if(j == 2)
                (*(list+i)).timeAppear = stod(data);
            else
                (*(list+i)).timeUse = stod(data);
         
        }
    }
    read.close();
    
}

double calcul_total_usage_time(Process *list,  int num_process){
    double total_usage_time = list[0].timeAppear + list[0].timeUse;

    for(int i = 1; i < num_process; i++){
        if(list[i].timeAppear > total_usage_time)
            total_usage_time = list[i].timeAppear;
        total_usage_time += list[i].timeUse;
    }

    return total_usage_time;
}

void find_timeApear_add_queue(Process * &list, queue<Process> &hang_doi, int num_process, double timing)
{
    
    for(int j = 0; j < num_process; j++){
        if(list[j].timeAppear == timing && list[j].status != "queue")
        {
            hang_doi.push(list[j]);
            list[j].status = "queue";
        }
    }
}
int find_process_running(Process *list, int num_process)
{
    for(int i = 0; i < num_process; i++)
    {
        if(list[i].status == "running")
            return i;
    }
    return -1;
}


void pop_queue_to_run(Process *&list, queue<Process> &hang_doi, int num_process, int timing)
{
    Process temp = hang_doi.front();
    int index = stoi(temp.name.substr(1));
    hang_doi.pop();
    list[index-1].status = "running";
}
void print_Queue(queue<Process> hang_doi, double timing){
    int size = hang_doi.size();
    cout << "Hang doi tai thoi diem " << timing << " la: ";
    for(int i = 0; i < size; i++)
    {
        cout << hang_doi.front().name << " ";
        hang_doi.pop();
    }
    cout << endl;
}
void FCFS(Process *list, int num_process, double total_usage_time){
    queue<Process> hang_doi;
    cout << total_usage_time;
    // hang_doi.push(list[0]);
    // list[0].status = "queue";
    int index = 0;
    
    for(double i = 0; i <= total_usage_time; i+=0.5){
        find_timeApear_add_queue(list, hang_doi, num_process, i);
        print_Queue(hang_doi, i);
        index = find_process_running(list, num_process);
        if(i == list[index].timeEnd && i != -1)
        {
            list[index].status = "end";
            cout << "Time end cua " << list[index].name << " la: " <<  list[index].timeEnd << endl; 
        }

        if(find_process_running(list, num_process) == -1 && hang_doi.size() != 0){
            pop_queue_to_run(list, hang_doi, num_process, i);
            index = find_process_running(list, num_process);
            cout << "Tai thoi diem " << i << " tien trinh " << list[index].name << " bat dau chay! " << endl << endl;
            list[index].timeEnd = list[index].timeUse + i;
        }
    }
}
int main(){

    Process* list;
    int num_process = count_process();
    read_data(list, num_process);
    double total_usage_time = calcul_total_usage_time(list, num_process);

    FCFS(list,num_process, total_usage_time);
    double totalWaitTime = 0;
    for(int i = 0; i < num_process; i++){
        totalWaitTime += list[i].timeEnd - list[i].timeAppear - list[i].timeUse;
        cout << list[i].name << " " << list[i].timeAppear << " " << list[i].timeUse << " " << list[i].timeEnd << " " << list[i].status <<  endl;
    }

    cout << "Time cho trung binh la: " << totalWaitTime / num_process;

    
}