//Implement pow(x, n).
//���ַ������ַ���$x^n = x^{n/2} * x^{n/2} * x^{n\%2}$
#pragma once

class SolutionPow 
{
public:
	double pow(double x, int n) 
	{
		if (n < 0) return 1.0 / power(x, -n);
		else return power(x, n);
	}
private:
	double power(double x, int n) 
	{
		if (n == 0) return 1;
		double v = power(x, n >> 1);
		if (n & 1 == 0) return v * v;
		else return v * v * x;
	}
};

class SlutionSqrt
{
public:
	int sqrt(int x)
	{
		int left = 1, right = x / 2;
		int last_mid; // ��¼���һ�� mid

		if (x < 2) return x;

		while (left <= right)
		{
			const int mid = left + (right - left) / 2;

			if (x / mid > mid)
			{ 
				// ��Ҫ�� x > mid * mid�������
				left = mid + 1;
				last_mid = mid;
			}
			else if (x / mid < mid) 
			{
				right = mid - 1;
			}
			else 
			{
				return mid;
			}
		}
		return last_mid;
	}
private:

};

