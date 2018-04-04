#include "stdafx.h"
#include "Fraction.h"

using namespace std;

Fraction::Fraction(int a, int b):molecular(a),denominator(b)
{
	if (denominator == 0)
	{
		throwError("·ÖÄ¸Îª0.");
	}
	update();
}


Fraction::~Fraction()
{
}

void Fraction::update()
{
	if (denominator < 0)
	{
		denominator = -denominator;
		molecular = -molecular;
	}

	if (molecular == 0)
	{
		denominator = 1;
	}
	else
	{
		int tmp = gcd(molecular, denominator);
		molecular = molecular / tmp;
		denominator = denominator / tmp;
	}

}

void Fraction::throwError(string str) const
{
	cout << "ERROR: " << str << endl;
	exit(-1);
}

Fraction Fraction::operator+ (const Fraction& b) const
{
	Fraction ans;
	ans.denominator = denominator * b.denominator;
	ans.molecular = molecular * b.denominator + denominator * b.molecular;
	ans.update();
	return ans;
}

Fraction Fraction::operator- (const Fraction& b) const
{
	return *this + (-b);
}

Fraction Fraction::operator- () const
{
	Fraction ans = *this;
	ans.molecular = -ans.molecular;
	return ans;
}

Fraction Fraction::operator* (const Fraction& b) const
{
	Fraction ans;
	ans.denominator = denominator * b.denominator;
	ans.molecular = molecular * b.molecular;
	ans.update();
	return ans;
}

Fraction Fraction::operator/ (const Fraction& b) const
{
	if (b.molecular == 0)
	{
		throwError("³ýÒÔ0.");
	}

	Fraction ans;
	ans.denominator = denominator * b.molecular;
	ans.molecular = molecular * b.denominator;
	ans.update();
	return ans;
}

Fraction& Fraction::operator+= (const Fraction& b)
{
	return *this = *this + b;
}

Fraction& Fraction::operator/= (const Fraction& b)
{
	return *this = *this / b;
}

bool Fraction::operator< (const Fraction& b) const
{
	return (*this - b).molecular < 0;
}

bool Fraction::operator> (const Fraction& b) const
{
	return b < *this;
}

bool Fraction::operator== (const Fraction& b) const
{
	return !(*this < b) && !(b < *this);
}


bool Fraction::operator<= (const Fraction& b) const
{
	return *this < b || *this == b;
}

bool Fraction::operator>= (const Fraction& b) const
{
	return *this > b || *this == b;
}

bool Fraction::operator!= (const Fraction& b) const
{
	return !(*this == b);
}

ostream& operator<< (ostream& a, const Fraction& b)
{
	if (b.denominator == 1)
	{
		a << b.molecular;
	}
	else
	{
		a << to_string(b.molecular) + '/' + to_string(b.denominator);
	}
	return a;
}

istream& operator>> (istream& a, Fraction& b)
{
	string str;
	a >> str;

	string::size_type pos;
	if ((pos = str.find("/")) == string::npos)
	{
		b = stoi(str);
	}
	else
	{
		string strmol = str.substr(0, pos);
		string strden = str.substr(pos + 1);
		b = Fraction(stoi(strmol), stoi(strden));
	}
	return a;
}
