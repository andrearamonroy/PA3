#include <iostream>
#include <fstream>

using namespace std;

int main() {
	
	int devices = 100;
	
	ofstream linearLatency;
	linearLatency.open("linearLatency.txt");
	
	for(int number_of_devices = 100; number_of_devices < 6001; number_of_devices += 100) {
		for(int trial = 0; trial < 10; trial++) {
			
			//Implement Linear Backoff Here
			
			
			
			
			
			
			
			
			
			
		}
	}
	linearLatency.close();
	
	
	
	devices = 100;
	
	ofstream binaryLatency;
	binaryLatency.open("binaryLatency.txt");
	
	for(int number_of_devices = 100; number_of_devices < 6001; number_of_devices += 100) {
		for(int trial = 0; trial < 10; trial++) {
			
			//Implement Binary Backoff Here 
			
			
			
			
			
			
			
			
			
			
			
			
		}
	}
	binaryLatency.close();
	
	
	
	
	
	devices = 100;
	
	ofstream logLatency;
	logLatency.open("logLatency.txt");
	
	for(int number_of_devices = 100; number_of_devices < 6001; number_of_devices += 100) {
		for(int trial = 0; trial < 10; trial++) {
			
			//Implement Logarithmic Backoff Here
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
			
		}
	}
	logLatency.close();
	
	
}