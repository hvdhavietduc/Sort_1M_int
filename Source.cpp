
#include <iostream>
#include<string>
#include <fstream>
#include<Windows.h>

using namespace std;
int partition(int* arr, int low, int high);
void quickSort(int* arr, int low, int high);
void quickSort(int *arr,int low,int high)
{
	if (low < high)
	{
		int pivot_index = partition(arr, low, high);
		quickSort(arr, low, pivot_index - 1);  
		quickSort(arr, pivot_index + 1, high); 
	}
}
int partition(int *arr,int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);  
	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++; 
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}
int main() {
	
	fstream output1;
	fstream output2;
	output1.open("output1.txt", ios::out | ios::in);
	
	int n = 500000;
	int* arr = new int[n];
	string tmp = "";
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) output1 << to_string(arr[i]) << endl << "END";
		else output1 << to_string(arr[i]) << endl;
	}
	
	output1.close();
	output2.open("output2.txt", ios::out | ios::in);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		if (i == n - 1) output2 << to_string(arr[i]) << endl << "END";
		else output2 << to_string(arr[i]) << endl;
	}
	delete[] arr;
	output2.close();
	output1.open("output1.txt", ios::in);
	output2.open("output2.txt", ios::in);
	fstream finalOutput;
	finalOutput.open("finalOutput.txt", ios::in |ios::out);
	string tmp1, tmp2;
	getline(output1, tmp1);
	getline(output2, tmp2);
	int integer1 = stoi(tmp1);
	int integer2 = stoi(tmp2);
	while (tmp1!="END" || tmp2!="END") {
		
		if (tmp1=="END") {
			if (tmp2 != "END") finalOutput << tmp2 << endl;
			while (tmp2!="END") {
				getline(output2, tmp2);
				if(tmp2!="END") finalOutput << tmp2 << endl;
			}
		}
		else if (tmp2=="END") {
			if (tmp1 != "END") finalOutput << tmp1 << endl;
			while (tmp1!="END") {
				getline(output1, tmp1);
				if (tmp1 != "END") finalOutput << tmp1 << endl;
			}
		}
		if (tmp1 == "END" && tmp2 == "END") {
			break;
		}
		if (integer1 < integer2) {
			finalOutput << tmp1 << endl;
			getline(output1, tmp1);
			if (tmp1!="END") {
				integer1 = stoi(tmp1);
			}
		}
		else {
			finalOutput << tmp2 << endl;
			getline(output2, tmp2);
			if (tmp2!="END") {
				integer2 = stoi(tmp2);
			}
		}
	}
	finalOutput.close();
	finalOutput.open("finalOutput.txt", ios::in);
	cout << "Sort 1 milion integer :"<<endl;
	while (!finalOutput.eof()) {
		 getline(finalOutput, tmp);
		 cout << tmp << " ";
	}
	finalOutput.close();
	output1.close();
	output2.close();
}
