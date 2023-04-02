#ifndef TRANSPORT_VEHICLE_H_
#define TRANSPORT_VEHICLE_H_

#include<iostream>

namespace transport {
	class Vehicle {
	public:
		virtual ~Vehicle();
		virtual void Print() const abstract;
		virtual double Cost() const abstract;
		virtual void ReadFrom(std::istream& in) abstract;
		virtual void WriteTo(std::ostream& out) const abstract;
		bool operator< (const Vehicle& v) const;
		};
	std::istream& operator>>(std::istream& in, Vehicle& v);
	std::ostream& operator<<(std::ostream& out, const Vehicle& v);
	unsigned ReadFromFile(Vehicle**& arr, int &size, const std::string& file_name);
	void Sort(Vehicle**& arr, int size);
}

#endif TRANSPORT_VEHICLE_H_