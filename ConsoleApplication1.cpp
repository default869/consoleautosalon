#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Car
{
private:
	string name;
	int year;
	float volume;
	int price;
public:
	Car(string name, int year, float volume, int price)
	{
		this->name = name;
		this->year = year;
		this->volume = volume;
		this->price = price;
	}

	void Print()
	{
		cout << "Name: " << name << endl;
		cout << "Year: " << year << endl;
		cout << "Volume of engine: " << volume << endl;
		cout << "Price: " << price << endl << endl;
	}

	int getYear()
	{
		return year;
	}

	float getVolume()
	{
		return volume;
	}

	int getPrice()
	{
		return price;
	}

	string getName()
	{
		return name;
	}

	~Car() {}
};

class AutoSalon
{
private:
	vector<Car>cars;
	int num = 0;
public:
	void addCar(Car car)
	{
		cars.push_back(car);
		num++;
		cout << "added!" << endl;
	}

	void deleteCar(int num)
	{
		for (int i = 0; i < cars.size(); i++)
		{
			if (i == num)
			{
				cars.erase(cars.begin() + i);
				cout << "deleted!" << endl;
			}
		}
	}

	void showCars()
	{
		for (int i = 0; i < cars.size(); i++)
		{
			cars[i].Print();
		}
	}

	void sortByYear()
	{
		sort(cars.begin(), cars.end());
		cout << "sorted by year!" << endl;
	}

	void searchByYear(int year)
	{
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].getYear() == year)
			{
				cars[i].Print();
			}
		}
	}
	void searchByPrice(int price)
	{
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].getPrice() == price)
			{
				cars[i].Print();
			}
		}
	}
	void searchByVolume(float volume)
	{
		for (int i = 0; i < cars.size(); i++)
		{
			if (cars[i].getVolume() == volume)
			{
				cars[i].Print();
			}
		}
	}
};

bool operator <(Car& lhs, Car& rhs)
{
	return lhs.getYear() < rhs.getYear();
}

Car add()
{
	string name;
	int year;
	float volume;
	int price;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter year: ";
	cin >> year;
	cout << "Enter volume: ";
	cin >> volume;
	cout << "Enter price: ";
	cin >> price;

	Car a(name, year, volume, price);

	return a;
}

int main()
{
	AutoSalon cars;
	int x = 1;
	cout << "1) Add car" << endl;
	cout << "2) Delete car" << endl;
	cout << "3) Show cars" << endl;
	cout << "4) Find car" << endl;
	cout << "5) Sort cars by year" << endl;
	cout << "6) Exit" << endl;
	while (x)
	{
		system("cls");
		cout << "1) Add car" << endl;
		cout << "2) Delete car" << endl;
		cout << "3) Show cars" << endl;
		cout << "4) Find car" << endl;
		cout << "5) Sort cars by year" << endl;
		cout << "6) Exit" << endl;
		cin >> x;
		if (x == 1)
		{
			Car a = add();
			cars.addCar(a);
			system("pause");
		}
		else if (x == 2)
		{
			int num;
			cout << "Enter number of car(from 0): ";
			cin >> num;
			cars.deleteCar(num);
			system("pause");
		}
		else if (x == 3)
		{
			cars.showCars();
			system("pause");
		}
		else if (x == 4)
		{
			int num;
			cout << "1) Find by year: " << endl;
			cout << "2) Find by price: " << endl;
			cout << "3) Find by volume: " << endl;
			cin >> num;
			if (num == 1)
			{
				int year;
				cout << "Enter year: ";
				cin >> year;
				cars.searchByYear(year);
				system("pause");
			}
			else if (num == 2)
			{
				int price;
				cout << "Enter price: ";
				cin >> price;
				cars.searchByYear(price);
				system("pause");
			}
			else if (num == 3)
			{
				float volume;
				cout << "Enter volume: ";
				cin >> volume;
				cars.searchByYear(volume);
				system("pause");
			}
			else cout << "wrong num!" << endl;
		}
		else if (x == 5)
		{
			cars.sortByYear();
			system("pause");
		}
		else if (x == 6)
		{
			cout << "Bye!" << endl;
			return 0;
		}
		else if (x < 1 || x > 6)
		{
			cout << "Wrong number try again" << endl;
			system("pause");
		}
	}
	return 0;
}