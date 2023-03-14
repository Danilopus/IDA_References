#include <iostream>


int Get_Int();
int Get_Dbl();

int Random_Number_Int(int Range_min, int Range_max) 
{
	//srand(time(NULL));
	return Range_min + rand() % (Range_max - Range_min + 1); 
}

void References()
{
	int My_Number = 111, My_Number_2 = 222;
	//Reference to a variable
	int& _reference_My_Number = My_Number; // Must be initialized at the time of declaration

	std::cout << "\n" << "_reference_My_Number = " << _reference_My_Number;

	_reference_My_Number = My_Number_2; // same as *(&My_Number)=My_Number_2;

	std::cout << "\n" << "_reference_My_Number = " << _reference_My_Number;
	std::cout << "\n" << "My_Number = " << My_Number;

	if (&_reference_My_Number == &My_Number)
		std::cout << "\n" << "Adress of reference = Adress of variable";
}

template <typename ANY> void Real_Swap_var(ANY Num1, ANY Num2)
{
	ANY _temp = Num2;
	Num2 = Num1;
	Num1 = _temp;
}
template <typename ANY> void Real_Swap(ANY *Num1, ANY *Num2) //Working, but have to pass adresses
{
	ANY _temp = *Num2;
	*Num2 = *Num1;
	*Num1 = _temp;
}
template <typename ANY> void Real_Swap(ANY &Num1, ANY &Num2) //Working out fine!
{
	ANY _temp = Num2;
	Num2 = Num1;
	Num1 = _temp;
	std::swap(Num1, Num2);
}

void References_applications_functions_parameters()
{
	//References applications
	int N = 5, M = 25;
	std::cout << "N = " << N << ", M = " << M;
	Real_Swap(&N, &M);
	std::cout << "\n\nReal_Swap(&N, &M) ";
	std::cout << "\n" << "N = " << N << ", M = " << M;

	Real_Swap(N, M);
	std::cout << "\n\n" << "Real_Swap(N, M) ";
	std::cout << "\n" << "N = " << N << ", M = " << M;
}

int ARRAY_2DIM[10][2] = {};

int &function(int index)
{
	return ARRAY_2DIM[index][1];
}


int main()
{
	std::cout << "\n\n" << "Array initialising";
	for (int i = 0; i < 10; i++)
	{
		std::cout << "\n\n" << "Enter [" << i + 1 << "] element -> ";
		ARRAY_2DIM[i][0] = Get_Int();
		function(i)= ARRAY_2DIM[i][0];
	}

	std::cout << "\n\n" << "ARRAY_2DIM:\n";
	for (int i =0;i<10;i++)
		std::cout << ARRAY_2DIM[i][0] <<"\t" << function(i) << "\n";




	std::cout << "\n\n";
	system("pause");
	return 0;
}

int Get_Int()
{
	int a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
	}
	return a;
}
int Get_Dbl()
{
	double a;
	while (!(std::cin >> a) || (std::cin.peek() != '\n'))
	{
		std::cin.clear();
		while (std::cin.get() != '\n');
		std::cout << "[Input error! Integer expected]\n";
	}
	return a;
}