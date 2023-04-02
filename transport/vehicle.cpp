#include"vehicle.h"
#include"auto.h"
#include"fly.h"
#include<fstream>
using std::cout;

namespace transport {
	Vehicle::~Vehicle() {}

	std::istream& operator>>(std::istream& in, Vehicle& v) {
		v.ReadFrom(in);
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const Vehicle& v) {
		v.WriteTo(out);
		return out;
	}

	bool Vehicle::operator< (const Vehicle& v) const {
		return Cost() < v.Cost();
	}

	unsigned ReadFromFile(Vehicle**& arr, int& size, const std::string& file_name) {
		std::ifstream fin(file_name);
		fin >> size;
		arr = new Vehicle * [size];
		unsigned count = 0;
		for (int i = 0; i < size; ++i) {
			char type; fin >> type;
			if (type == 'a') {
				arr[count] = new Auto();
				fin >> *arr[count];
				++count;
			}
			else if (type == 'f') {
				arr[count] = new Fly();
				fin >> *arr[count];
				++count;
			}
			else
			{
				char temp[256];
				fin.getline(temp, 256);
			}
		}
		fin.close();
		return count;
	}

	void Sort(Vehicle**& arr, int size) {
			for (int i = 0; i < size - 1; ++i) {
				if (arr[i + 1]->Cost() < arr[i]->Cost()) {
					Vehicle* temp = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = temp;
				}
			}
	}
}
