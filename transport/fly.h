#ifndef TRANSPORT_FLY_H_
#define TRANSPORT_FLY_H_

#include"vehicle.h"
#include<string>
using std::cout;

namespace transport {
	class Fly : public Vehicle {
	public:
		Fly();
		Fly(std:: string name, double price_for_person, unsigned number_of_seats);
		Fly(const Fly& f);
		~Fly();

		virtual void Print() const override;
		virtual double Cost() const override;
		virtual void ReadFrom(std::istream& in) override;
		virtual void WriteTo(std::ostream& out) const override;

	private:
		std::string name_;
		double price_for_person_;
		unsigned number_of_seats_;
	};
}

#endif TRANSPORT_FLY_H_
