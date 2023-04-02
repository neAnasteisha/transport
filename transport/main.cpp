#include<iostream>
#include"vehicle.h"
#include"auto.h"
#include"fly.h"
using std::cout;

using transport::Vehicle;
using transport::Auto;
using transport::Fly;

int main() {
	Vehicle** transport = nullptr;
	int size = 0;
	ReadFromFile(transport, size, "transport.txt");
	for (int i = 0; i < size; ++i) {
		transport[i]->Print();
	}
	cout << "\n\n";

	cout << "After sort: \n\n";

	double sum = 0.0;
	Sort(transport, size);
	for (int i = 0; i < size; ++i) {
		transport[i]->Print();
		sum += transport[i]->Cost();
	}
	cout << "Total sum: " << sum << "\n\n";

	return 0;
}