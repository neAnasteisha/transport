#ifndef TRANSPORT_AUTO_H_
#define TRANSPORT_AUTO_H_

#include"vehicle.h"
#include<string>
using std::cout;

namespace transport {
	class Auto : public Vehicle {
	public:
		Auto();
		Auto(std::string brand, double price, double exploitation);
		Auto(const Auto& a);
		~Auto();

		virtual void Print() const override;
		virtual double Cost() const override;
		virtual void ReadFrom(std::istream& in) override;
		virtual void WriteTo(std::ostream& out) const override;
	private:
		std::string brand_;
		double price_;
		double exploitation_;
	};
}

#endif TRANSPORT_AUTO_H_
