#include <iostream>
#include <fstream>
#include <math.h>
#include <bits/stdc++.h> 
using namespace std;

int main() {
	
	ofstream linearLatency;
	linearLatency.open("linearLatency.txt");
	for(int number_of_devices = 100; number_of_devices < 6001; number_of_devices += 100) {	
		for(int trial = 0; trial < 1; trial++) {

			int devices = number_of_devices;
			int windows_size=2;
			
			while (devices > 0) {
				int Device_Choices[windows_size];
				for(int i = 0; i < windows_size; i++){
					Device_Choices[i] = 0;
				}
				for(int i = 0; i < number_of_devices; i++){
					int random_var = rand()%windows_size;
					Device_Choices[random_var] = Device_Choices[random_var]+1;
				}
				for (int i = 0; i < windows_size; i++){
					if (Device_Choices[i]==1){
						devices--;
					}
				
				}
				windows_size++;

			}
			
		}
		
	}
	

	linearLatency.close();
	
	
	/*
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
	*/
	return 0;
	
}