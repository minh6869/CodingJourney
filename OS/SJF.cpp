#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <stack>
#include <math.h>
using namespace std;

struct Process{
    string name;
    string status = "";
    double timeAppear;
    double timeUse;
    double timeEnd = 0;
};
struct compare {
    bool operator()(const Process& p1, const Process& p2) {
        return p1.timeUse > p2.timeUse;
    }
};

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
            else{
                (*(list+i)).timeUse = stod(data);
            }
         
        }
    }
    read.close();
    
}
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

double calcul_total_usage_time(Process *list,  int num_process){
    double total_usage_time = list[0].timeAppear + list[0].timeUse;

    for(int i = 1; i < num_process; i++){
        if(list[i].timeAppear > total_usage_time)
            total_usage_time = list[i].timeAppear;
        total_usage_time += list[i].timeUse;
    }

    return total_usage_time;
}
void find_timeApear_add_queue(Process * &list, priority_queue<Process, vector<Process>, compare> &hang_doi, int num_process, double timing)
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
void find_min_and_pop_queue_to_run(Process *&list, priority_queue<Process, vector<Process>, compare> &hang_doi, int num_process)
{
    Process temp = hang_doi.top();
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
void SJF(Process *list, int num_process, int total_usage_time){

    priority_queue<Process, vector<Process>, compare> hang_doi;
    int time_end = 0;
    int index = 0;
    double step = 0.5;
    for(double i = 0; i <= total_usage_time; i += step)
    {
        find_timeApear_add_queue(list, hang_doi, num_process, i);
        index = find_process_running(list, num_process);
        if(index != -1 && i == list[index].timeEnd){
            list[index].status = "end";
        }
       
       
        if(find_process_running(list, num_process) == -1 && hang_doi.size() != 0)
        {
            find_min_and_pop_queue_to_run(list, hang_doi, num_process);
            index = find_process_running(list, num_process);
            list[index].timeEnd = list[index].timeUse + i;
            cout << "Tai thoi diem " << i << " tien trinh " << list[index].name << " bat dau chay!" << endl;
            cout << "Time end cua " << list[index].name << " la: " << list[index].timeEnd << endl << endl;
        }

    }

}

int main(){
    Process *list;
    int num_process = count_process();
    read_data(list, num_process);
    int total_usage_time = calcul_total_usage_time(list, num_process);
    SJF(list, num_process, total_usage_time);
    double totalWaitTime = 0;
    for(int i = 0; i < num_process; i++){
        totalWaitTime += list[i].timeEnd - list[i].timeAppear - list[i].timeUse;
        cout << list[i].name << " " << list[i].timeAppear << " " << list[i].timeUse << " " << list[i].timeEnd << " " << list[i].status <<  endl;
    }

    cout << "Time cho trung binh la: " << totalWaitTime / num_process;
}