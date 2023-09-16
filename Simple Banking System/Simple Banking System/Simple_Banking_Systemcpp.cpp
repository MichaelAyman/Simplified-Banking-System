
#include <iostream>
#include <ctime>

using namespace std;

class queue{
public:

queue(){   // initializing the rear and the front with 0 and all the times with 0
front = -1;
rear = -1;
time1=0;
time2=0;
time3=0;
r=0;
}

~queue() {

}

void enqueue(int element){
if ( size() == 300 - 1 ){
	cout << "Queue is full" << endl;      // if the queue is full no entry is done
	return;
}
d[rear] = element;        // the element is entered to queue then rear is incremented
timet[rear] = time(NULL);
rear = ++rear % 300;
cout << "Customer " << element << " entered the queue at time " << time(NULL) << endl;
}

void increar() {
	rear = ++rear % 300;   // function used to increment the rear
}

void dequeue(queue& p){
	if (empty()){         //if the queue is empty the function will return
		cout << "Queue is empty" << endl;
		return;
	}
	p.increar();             // if a dequeue occures the element that is about to be dequeued is entered to another queue to later print out details
	dt[front] = time(NULL);
	p.d[p.rear] = d[front];
	p.timet[p.rear] = timet[front];
	p.dt[p.rear] = dt[front];
	int wt = time(NULL) - timet[front];       // waiting time is calculated to then be printed out
	cout << "Customer number "<<d[front]<<" is being helped at "<< dt[front] << " Wait time = " << wt << " seconds" << endl;
	time3 = time2;
	time2 = time1;
	time1 = wt;
	front = ++front % 300;
	r++;          
	if(front==rear){
		cout << "Queue is empty" << endl;
	}
	else{
		int avgt = (time1+time2+time3)/3.0;     // average waiting time of the last 3 customers is calculated to be printed out
		if(r==1){
			avgt = time1;
		}
		else if(r==2){
			avgt = (time1+time2)/2.0;
		}
		cout << "The wait time for the next customer is "<<avgt<<" seconds" << endl;
	}
}

int size() {     // returns the size of the queue
	return rear - front;
}

bool empty(){    // checks whether the queue is empty or not
	if (front == rear) {
		return true;
	}
	else 
		return false;
}

void printlogsheet() {    // prints the queue so that the details of the customers who have already been served can be printed out
	cout << "log sheet: " << endl;
	for (int i = 0; i <= rear; i++) {
		cout << "ticket number: " << d[i] << "   arrival time: " << timet[i] << "   departure time " << dt[i] << endl;
	}
}

private:
	int d[300];
	int timet[300], dt[300];
	int time1, time2, time3;
	int r, front, rear;
};

int main() {
	queue q;    // 2 queues are created, one to store those waiting and the other to print out the details of the customers that have already been served
	queue p;
	int x, c = 1;
	bool y = true;
	while (y == true) {
		cout << "Enter '1' for a customer's arrival, '2' to help the next customer, or '3' to quit." << endl;   // if 1 is entered a customer enters the queue
			cin >> x;

			if (x == 1) {
				q.enqueue(c);     
				c++;
			}

			else if (x == 2) {   // if 2 is enetered a customer is served
				q.dequeue(p);
			}

			else if (x == 3) {     // the details of the customers that have been served is printed out and the program ends
				p.printlogsheet();
				y = false;
			}
	}
	return 0;
}