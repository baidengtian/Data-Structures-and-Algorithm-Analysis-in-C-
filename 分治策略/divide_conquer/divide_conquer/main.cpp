#include <iostream>
#include <vector>

//---------------------------------------------------------------
//function: 
//           �������������ֵ
//Access:
//            null
//Parameter:
//          [in]  -  a b c 
//Returns:
//           - �����
//Date:
//          2019/12/24 
//author:   lsyy(18844183403@163.com)
//---------------------------------------------------------------

inline int max3(int a, int b, int c)
{
	int max = 0;
	if(a > b)
		max = a;
	else
		max = b;
	if(max < c)
		max = c;
	return max;
}
//---------------------------------------------------------------
//function: 
//           ����˼����һ�������������е�����
//Access:
//            null
//Parameter:
//          [in]  - a ���� left ��߽� right �ұ߽�
//Returns:
//           - ��������к�
//Date:
//          2019/12/24 
//author:   lsyy(18844183403@163.com)
//---------------------------------------------------------------
int maxSumRec(const std::vector<int> &a, int left, int right)
{
	if(left == right)
		if(a[left] > 0)
			return a[left];
		else
			return 0;

	int center = (left + right) / 2;
	int maxLeftSum = maxSumRec(a, left, center);
	int maxRightSum = maxSumRec(a, center + 1, right);
	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for(int i = center; i >= left; --i)
	{
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum)
		{
			maxLeftBorderSum = leftBorderSum;
		}
	}
	int maxRightBorderSum = 0, rightBorderSum = 0;
	for(int j = center + 1; j <= right; ++j)
	{
		rightBorderSum += a[j];
		if(rightBorderSum > maxRightBorderSum)
			maxRightBorderSum = rightBorderSum;
	}

	return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
//---------------------------------------------------------------
//function: 
//           ��֧���Ե���
//Access:
//            null
//Parameter:
//          [in]  - a ���� 
//Returns:
//           - ��������к�
//Date:
//          2019/12/24 
//author:   lsyy(18844183403@163.com)
//---------------------------------------------------------------
int maxSubSum3(const std::vector<int> &a)
{
	return maxSumRec(a,0,a.size() - 1);
}

int main()
{
	int ai[8] = {4 , -3, 5, -2, -1, 2, 6, -2};
	std::vector<int> vi(ai,ai+8);
	int a = maxSubSum3(vi);
	return 0;
}




