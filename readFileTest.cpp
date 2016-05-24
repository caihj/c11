#include <thread>
#include "BlockQuqueue.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <jsoncpp/json/json.h>
#include <fstream>
#include <vector>
#include <iostream>
#include <stdio.h>

class Task{
public:
	string saveDir;
	string taskUrl;
};

void workFunc(blocking_queue<Task> *queue){

	while(true){
		Task task;
		std::chrono::seconds s(1);
		bool ret = queue->take(task,s);
		if( !ret )
			break;

		if( access(task.saveDir.c_str(),F_OK) == ENOENT){
			mkdir(task.saveDir.c_str(),0777);
		}

		size_t pos = task.taskUrl.find_last_of("/");
		string filename = task.saveDir  + task.taskUrl.substr(pos);

		if( access(filename.c_str(),F_OK) == 0){
			continue;
		}
	}

	printf("thread end \n");
}

int main(){


	blocking_queue<Task> queue(10);

	std::vector<std::thread>  threads;
	for(int i=0;i<1;i++){
		threads.push_back(std::thread(workFunc,&queue));
	}


	Json::Reader reader;
	Json::Value root;

	std::ifstream in("albums.json", std::ifstream::in);

	reader.parse(in,root,false);

	int total = 0;
	int complete = 0;
	for(Json::Value & v: root){
		total +=v["imgurls"].size()+1;
	}

	printf("total %d\n",total);

	Json::Value album;
	for(Json::Value & album: root){
		string saveDir= string("/media/fighter/u_data/pic/")+ album["title"].asString();
		Task task;
		task.saveDir=saveDir;
		task.taskUrl=album["faceUrl"].asString();
		queue.put(task);
		complete++;
		//printf("complete %.02f\n",(double)complete/total*100.0);
		Json::Value urls = album["imgurls"];
		for(Json::Value &url:urls){
			task.saveDir=saveDir;
			task.taskUrl=url.asString();
			queue.put(task);
			complete++;
			//printf("complete %.02f\n",(double)complete/total*100.0);
		}
	}

	for(std::thread & t:threads){
		t.join();
	}

}
