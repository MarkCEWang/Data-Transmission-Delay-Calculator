#include <cstdlib>
#include <cstring>
#include "ece150-proj3-provided.h"
#include <iostream>

using namespace std;

void simplify(timestamp &t){
	if(t.ss>59){
		t.mm+=t.ss/60;
		t.ss=t.ss%60;
	}
	if(t.mm>59){
		t.hh+=t.mm/60;
		t.mm=t.mm%60;
	}
}

int earlierThan(timestamp a,timestamp b){
	
	int c=a.hh*3600+a.mm*60+a.ss;
	int d=b.hh*3600+b.mm*60+b.ss;
	if(c>d){return 0;}
	else {return 1;}
}

int size(request* req,uri* server){
	while(server){
		if(strcmp(req->name,server->name)==0){
			return server->size;
		}
		server=server->next;
	}
	return 0;
}

int priority(request* req,uri* server){
	while(server){
		if(strcmp(req->name,server->name)==0){
			return server->priority;
		}
		server=server->next;
	}
	return 0;
}

int maxPriority(request* req,uri* server){
	int prio=0;
	while(req){
		if(priority(req,server)>prio){
			prio=priority(req,server);
		}
		req=req->next;
	}
	return prio;
}
void deleteNext(request* & req){
		request* tmp=req->next;
		req->next=req->next->next;
		delete tmp;
		
}

timestamp operator-(timestamp a,timestamp b){
		int c=a.hh*3600+a.mm*60+a.ss;
		int d=b.hh*3600+b.mm*60+b.ss;
		
		timestamp time;
		time.ss=c-d;
		time.hh=0;
		time.mm=0;
		simplify(time);
		return time;
}

timestamp maxClientDelay(uri *u, request *req){

timestamp time;
request *pending=0;
request *pendingCount;

request *l=new request;
request *lbackup=l;
l->next=req;
request *pendingHead=new request;
pendingHead->next=pending;
time.hh=0;
time.mm=0;
time.ss=0;
timestamp max;
max.hh=0;
max.mm=0;
max.ss=0;



do{
	while(l->next){
		if(earlierThan(l->next->t,time)){
			
			request* tmp;
			tmp=l->next;
			l->next=l->next->next;
			tmp->next=pendingHead->next;
			pendingHead->next=tmp;
		}
		else {l=l->next;}
	}		
	
	l=lbackup;
	
	pendingCount=pendingHead;
	
	
	if(pendingHead->next){
		
		while(pendingCount->next){
			
			if(priority(pendingCount->next,u)==maxPriority(pendingHead->next,u)){
				int a=size(pendingCount->next,u)*4/5;
				timestamp delay=time-pendingCount->next->t;
				if(earlierThan(max,delay)){
					max=delay;
				}
				deleteNext(pendingCount);
				
				time.ss+=a;
				simplify(time);
				pendingCount=pendingCount->next;
				break;
					
				
			}
			pendingCount=pendingCount->next;
		}
	}
	else {
		
		timestamp nextt= l->next->t;
		
		
		while(l->next){
			
			if(earlierThan(l->next->t,nextt)){
				nextt=l->next->t;
			}
			l=l->next;		
		}
		
		time=nextt;
		
	}
	
	l=lbackup;
	
	if(pendingHead!=NULL){
	if(pendingHead->next==NULL&&l->next==NULL){
		
		return max;
	}
	}
}while(pendingHead->next!=NULL||l->next!=NULL);

return max;

}