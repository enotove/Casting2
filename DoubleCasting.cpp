
#include <iostream>
#include <string>
#include <format>
#include <numeric>


class Fraction
{
private:
	int numerator_;
	int denominator_;

	
public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	std::string Print() {
		if (numerator_ == denominator_) return "1";
		else
		{
			auto gcd = std::gcd(numerator_, denominator_);

			return std::format("{}/{}", numerator_/gcd, denominator_/gcd);
		}
		
	}
	Fraction operator + (const Fraction& other) {
		if (denominator_ != other.denominator_)
		{
			int temp_numerator1 = numerator_ * other.denominator_;
			int temp_numerator2 = denominator_ * other.numerator_;
			int temp_denominator = denominator_ * other.denominator_;
			return Fraction(temp_numerator1 + temp_numerator2, temp_denominator);
		}
		else return Fraction(numerator_ + other.numerator_, denominator_);
		
		
	}
	Fraction operator - (const Fraction& other)
	{
		if (denominator_ != other.denominator_)
		{
			int temp_numerator1 = numerator_ * other.denominator_;
			int temp_numerator2 = denominator_ * other.numerator_;
			int temp_denominator = denominator_ * other.denominator_;
			return Fraction(temp_numerator1 - temp_numerator2, temp_denominator);
		}
		else return Fraction(numerator_ - other.numerator_, denominator_);
	}
	Fraction operator * (const Fraction &other)
	{
		if (denominator_ != other.denominator_)
		{
			
			return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
		}
		else return Fraction(numerator_ * other.numerator_, denominator_);
	}
	Fraction operator / (const Fraction& other)
	{
	
			int temp_numerator = numerator_ * other.denominator_;
			int temp_denominator = denominator_ * other.numerator_;
			return Fraction(temp_numerator, temp_denominator);
	
	}
	
	Fraction operator - () 
	{
		
		return Fraction{ -numerator_, denominator_ };
	}
	Fraction& operator -- ()
	{
	    numerator_-= 1;
		return *this;
	}
	Fraction& operator ++ ()
	{
		
		numerator_+= 1;
		return *this;
	}
	Fraction operator -- (int)
	{
		Fraction temp = *this;
		--(*this);
		return temp;
	}
	Fraction operator ++ (int)
	{
		Fraction temp = *this;
		++(*this);
		return temp;
	}
};

int main()
{
	int flag = 1;
	while (flag != 0)
	{
		int numerator_1, denominator_1, numerator_2, denominator_2 = 0;
		std::cout << "Enter numerator first number: ";
		std::cin >> numerator_1;
		std::cout << "Enter denominator first number: ";
		std::cin >> denominator_1;
		std::cout << "Enter numerator second number: ";
		std::cin >> numerator_2;
		std::cout << "Enter denominator second number: ";
		std::cin >> denominator_2;

		Fraction f1(numerator_1, denominator_1);
		Fraction f2(numerator_2, denominator_2);
		std::cout << f1.Print() << " + " << f2.Print() << " = " << (f1 + f2).Print() << '\n';
		std::cout << f1.Print() << " - " << f2.Print() << " = " << (f1-f2).Print()<< '\n';
		std::cout << f1.Print() << " * " << f2.Print() << " = " << (f1 * f2).Print() << '\n';
		std::cout << f1.Print() << " / " << f2.Print() << " = " << (f1 / f2).Print() << '\n';
		std::cout << "-" << f2.Print() << " = " << (-f2).Print() << '\n';
		std::cout << "-" << f1.Print() << " = " << (-f1).Print() << '\n';
		std::cout << "++" << f1.Print() << " = " << (f1++).Print() << '\n';
		std::cout << "++" << f1.Print() << " = " << (++f1).Print() << '\n';
		std::cout << "--" << f2.Print() << " = " << (f2--).Print() << '\n';
		std::cout << "--" << f2.Print() << " = " << (--f2).Print() << '\n';
		std::cout << "If you want continue to press another number or press 0 for exit: ";
		std::cin >> flag;
		
	}
	
}

