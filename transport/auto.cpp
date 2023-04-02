#include"auto.h"
using std::cout;

namespace transport {
	Auto::Auto() 
		: brand_(""), price_(0.0), exploitation_(0.0)
	{}

	Auto::Auto(std::string brand, double price, double exploitation)
		: brand_(brand), price_(price), exploitation_(exploitation)
	{}

	Auto::Auto(const Auto& a) 
		: brand_(a.brand_), price_(a.price_), exploitation_(a.exploitation_)
	{}

	Auto::~Auto()
	{}

	void Auto::Print() const {
		cout << "Brand: " << brand_ << "\nPrice:\t" << price_ << " dol "
			<< "\nYears of exploitation: " << exploitation_ << " years " << "\nCost: " << Cost() << " dol \n\n";
	}

	double Auto::Cost() const {
		return price_ - (price_ / 100 * exploitation_);
	}
	void Auto::ReadFrom(std::istream& in) {
		in >> brand_ >> price_ >> exploitation_;
	}
	void Auto::WriteTo(std::ostream& out) const {
		out << brand_ << ' ' << price_ << ' ' << exploitation_;
	}
}
