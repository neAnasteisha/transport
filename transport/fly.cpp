#include "fly.h"
using std::cout;

namespace transport {
	Fly::Fly()
		:name_(""), price_for_person_(0.0), number_of_seats_(0)
	{}

	Fly::Fly(std::string name, double price_for_person, unsigned number_of_seats)
		:name_(name), price_for_person_(price_for_person), number_of_seats_(number_of_seats)
	{}

	Fly::Fly(const Fly& f)
		: name_(f.name_), price_for_person_(f.price_for_person_), number_of_seats_(f.number_of_seats_)
	{}

	Fly::~Fly()
	{}

	void Fly::Print() const {
		cout << "Name: " << name_ << "\nPrice for person: " << price_for_person_ << " dol "
			<< "\nNumber of seats: " << number_of_seats_ << "\nCost: " << Cost() << " dol \n\n";
	}
	double Fly::Cost() const {
		return (price_for_person_ + price_for_person_ / 100 * 0.1) * number_of_seats_;
	}
	void Fly::ReadFrom(std::istream& in) {
		in >> name_ >> price_for_person_ >> number_of_seats_;
	}

	void Fly::WriteTo(std::ostream& out) const {
		out << name_ << ' ' << price_for_person_ << ' ' << number_of_seats_;
	}
}
