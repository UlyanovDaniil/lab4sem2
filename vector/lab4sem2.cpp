#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include <ctime>

void mainint()
{
  TVector<int> v1;
  TVector<int> v2(4);
  TVector<int> v3(v2);

  std::cout << "v1 = " << v1 << "\tv2 = " << v2 << "\tv3 = " << v3 << "\n";

  std::cout << "length v2 = " << v2.GetLen() << "\n";

  for (int i = 0; i < v2.GetLen(); i++)
  {
    v2[i] = rand() % 20 + 1;
    v3[i] = rand() % 20 + 1;
  }

  std::cout << "v2 = " << v2 << "\tv3 = " << v3 << "\n";

  std::cout << "v2 + v3 = " << v2 + v3 << "\n";
  std::cout << "v2 - v3 = " << v2 - v3 << "\n";
  std::cout << "v2 * v3 = " << v2 * v3 << "\n";
  std::cout << "v2 / v3 = " << v2 / v3 << "\n";

  TVector<TVector<int>> fm1(3);
  TVector<int> v4(4), v5(4), v6(4);

  v1.ReSize(3);
  v1[0] = 2; v1[1] = 4; v1[2] = 3;
  for (int i = 0; i < v4.GetLen(); i++)
  {
    v4[i] = rand() % 20 + 1;
    v5[i] = rand() % 20 + 1;
    v6[i] = rand() % 20 + 1;
  }
  fm1[0] = v4; fm1[1] = v5; fm1[2] = v6;

  std::cout << "v1 * fm1 = " << v1 * fm1 << "\n";

  v1 = v2;

  if (v1 == v2)
  {
    std::cout << "v1 == v2" << "\n";
  }
  else
  {
    std::cout << "v1 != v2" << "\n";
  }

  if (v2 != v3)
  {
    std::cout << "v2 != v3" << "\n";
  }
  else
  {
    std::cout << "v2 == v3" << "\n";
  }

  std::cout << "v3[2] = " << v3[2] << "\n";

  std::cout << "v1 = " << v1 << "\tv2 = " << v2 << "\n";
  v1.ReSize(3);
  v2.ReSize(7);
  std::cout << "v1 = " << v1 << "\tv2 = " << v2 << "\n";

  v2[0] = 5; v2[1] = 9; v2[2] = 5; v2[3] = 5; v2[4] = 8; v2[5] = 7; v2[6] = 5;

  std::cout << "v2 = " << v2 << "\n";

  std::cout << "5 in v2 meet: " << v2.CountElem(5) << "\n";

  int k = 0;
  int* masindex1 = v2.MasIndex(5, k);

  std::cout << "5 in v2 have index: ";
  for (int i = 0; i < k - 1; i++)
  {
    std::cout << masindex1[i] << ", ";
  }
  std::cout << masindex1[k - 1] << "\n";

  v4.ReSize(10); v5.ReSize(10); v6.ReSize(10);
  for (int i = 0; i < v4.GetLen(); i++)
  {
    v4[i] = rand() % 20;
    v5[i] = rand() % 20;
    v6[i] = rand() % 20;
  }

  std::cout << "v4 = " << v4 << "\tv5 = " << v5 << "\tv6 = " << v6 << "\n";

  v4.SortPuzirec();
  v5.SortVstavka();
  v6.SortBistraya(0, v6.GetLen() - 1);

  std::cout << "v4 = " << v4 << "\tv5 = " << v5 << "\tv6 = " << v6 << "\n";

  std::cout << "v3:";
  std::cin >> v3;

  std::cout << "v3 = " << v3 << "\n";


  std::cout << "\n";


  TMatrix<int> m1;
  TMatrix<int> m2(3);
  TMatrix<int> m3(4, 3);
  TMatrix<int> m4(fm1);
  TMatrix<int> m5(m4);

  std::cout << "m1 = " << m1 << "\nm2 =\n" << m2 << "\nm3 =\n" << m3 << "\nm4 =\n" << m4 << "\nm5 =\n" << m5 << "\n";

  std::cout << "width m2 = " << m2.GetWidth() << "\n";

  for (int i = 0; i < m4.GetWidth(); i++)
  {
    for (int j = 0; j < m4.GetLen(); j++)
    {
      m4[i][j] = rand() % 20 + 1;
      m5[i][j] = rand() % 20 + 1;
    }
  }

  std::cout << "m4 + m5 =\n" << m4 + m5 << "\n";
  std::cout << "m4 - m5 =\n" << m4 - m5 << "\n";

  m4.ReSize(3, 3); m5.ReSize(3, 3);

  std::cout << "m4 * m5 =\n" << m4 * m5 << "\n";

  std::cout << "m4 * v1 = " << m4 * v1 << "\n";

  m1 = fm1;

  std::cout << "m1 = fm1 =\n" << m1 << "\n";

  m2 = m1;

  if (m1 == m2)
  {
    std::cout << "m1 == m2" << "\n";
  }
  else
  {
    std::cout << "m1 != m2" << "\n";
  }

  if (m2 != m3)
  {
    std::cout << "m2 != m3" << "\n";
  }
  else
  {
    std::cout << "m2 == m3" << "\n";
  }

  std::cout << "m2[1] = " << m2[1] << "\n";

  std::cout << "m4 =\n" << m4 << "\nm5 =\n" << m5 << "\n";

  m4.ReSize(2, 2); m5.ReSize(5, 4);

  std::cout << "m4 =\n" << m4 << "\nm5 =\n" << m5 << "\n";

  m3[0][0] = 4; m3[0][1] = 3; m3[0][2] = 4; m3[0][3] = 8;
  m3[1][0] = 4; m3[1][1] = 2; m3[1][2] = 5; m3[1][3] = 4;
  m3[2][0] = 1; m3[2][1] = 4; m3[2][2] = 6; m3[2][3] = 7;

  std::cout << "m3 =\n" << m3 << "\n";

  std::cout << "4 in m3 meet: " << m3.CountElem(4) << "\n";

  int** masindex2 = m3.MasIndex(4, k);

  std::cout << "4 in m3 have index: ";
  for (int i = 0; i < k - 1; i++)
  {
    std::cout << masindex2[i][0] << " " << masindex2[i][1] << ", ";
  }
  std::cout << masindex2[k - 1][0] << " " << masindex2[k - 1][1] << "\n";

  std::cout << "m2:";
  std::cin >> m2;

  std::cout << "m2 =\n" << m2 << "\n";
}

void maindouble()
{
  TVector<double> v1;
  TVector<double> v2(4);
  TVector<double> v3(v2);

  std::cout << "v1 = " << v1 << "\tv2 = " << v2 << "\tv3 = " << v3 << "\n";

  std::cout << "length v2 = " << v2.GetLen() << "\n";

  for (int i = 0; i < v2.GetLen(); i++)
  {
    v2[i] = (double)rand() / (double)1000 + 1;
    v3[i] = (double)rand() / (double)1000 + 1;
  }

  std::cout << "v2 = " << v2 << "\tv3 = " << v3 << "\n";

  std::cout << "v2 + v3 = " << v2 + v3 << "\n";
  std::cout << "v2 - v3 = " << v2 - v3 << "\n";
  std::cout << "v2 * v3 = " << v2 * v3 << "\n";
  std::cout << "v2 / v3 = " << v2 / v3 << "\n";

  TVector<TVector<double>> fm1(3);
  TVector<double> v4(4), v5(4), v6(4);

  v1.ReSize(3);
  v1[0] = 2.33; v1[1] = 4.45; v1[2] = 3.253;
  for (int i = 0; i < v4.GetLen(); i++)
  {
    v4[i] = (double)rand() / (double)1000 + 1;
    v5[i] = (double)rand() / (double)1000 + 1;
    v6[i] = (double)rand() / (double)1000 + 1;
  }
  fm1[0] = v4; fm1[1] = v5; fm1[2] = v6;

  std::cout << "v1 * fm1 = " << v1 * fm1 << "\n";

  v1 = v2;

  if (v1 == v2)
  {
    std::cout << "v1 == v2" << "\n";
  }
  else
  {
    std::cout << "v1 != v2" << "\n";
  }

  if (v2 != v3)
  {
    std::cout << "v2 != v3" << "\n";
  }
  else
  {
    std::cout << "v2 == v3" << "\n";
  }

  std::cout << "v3[2] = " << v3[2] << "\n";

  std::cout << "v1 = " << v1 << "\tv2 = " << v2 << "\n";
  v1.ReSize(3);
  v2.ReSize(7);
  std::cout << "v1 = " << v1 << "\tv2 = " << v2 << "\n";

  v2[0] = 5.46; v2[1] = 9.1; v2[2] = 5.46; v2[3] = 5.46; v2[4] = 8.25; v2[5] = 7.7; v2[6] = 5.46;

  std::cout << "v2 = " << v2 << "\n";

  std::cout << "5.46 in v2 meet: " << v2.CountElem(5.46) << "\n";

  int k = 0;
  int* masindex1 = v2.MasIndex(5.46, k);

  std::cout << "5.46 in v2 have index: ";
  for (int i = 0; i < k - 1; i++)
  {
    std::cout << masindex1[i] << ", ";
  }
  std::cout << masindex1[k - 1] << "\n";

  v4.ReSize(8); v5.ReSize(8); v6.ReSize(8);
  for (int i = 0; i < v4.GetLen(); i++)
  {
    v4[i] = (double)rand() / (double)1000 + 1;
    v5[i] = (double)rand() / (double)1000 + 1;
    v6[i] = (double)rand() / (double)1000 + 1;
  }

  std::cout << "v4 = " << v4 << "\tv5 = " << v5 << "\tv6 = " << v6 << "\n";

  v4.SortPuzirec();
  v5.SortVstavka();
  v6.SortBistraya(0, v6.GetLen() - 1);

  std::cout << "v4 = " << v4 << "\tv5 = " << v5 << "\tv6 = " << v6 << "\n";

  std::cout << "v3:";
  std::cin >> v3;

  std::cout << "v3 = " << v3 << "\n";


  std::cout << "\n";


  TMatrix<double> m1;
  TMatrix<double> m2(3);
  TMatrix<double> m3(4, 3);
  TMatrix<double> m4(fm1);
  TMatrix<double> m5(m4);

  std::cout << "m1 = " << m1 << "\nm2 =\n" << m2 << "\nm3 =\n" << m3 << "\nm4 =\n" << m4 << "\nm5 =\n" << m5 << "\n";

  std::cout << "width m2 = " << m2.GetWidth() << "\n";

  for (int i = 0; i < m4.GetWidth(); i++)
  {
    for (int j = 0; j < m4.GetLen(); j++)
    {
      m4[i][j] = (double)rand() / (double)1000 + 1;
      m5[i][j] = (double)rand() / (double)1000 + 1;
    }
  }

  std::cout << "m4 + m5 =\n" << m4 + m5 << "\n";
  std::cout << "m4 - m5 =\n" << m4 - m5 << "\n";

  m4.ReSize(3, 3); m5.ReSize(3, 3);

  std::cout << "m4 * m5 =\n" << m4 * m5 << "\n";

  std::cout << "m4 * v1 = " << m4 * v1 << "\n";

  m1 = fm1;

  std::cout << "m1 = fm1 =\n" << m1 << "\n";

  m2 = m1;

  if (m1 == m2)
  {
    std::cout << "m1 == m2" << "\n";
  }
  else
  {
    std::cout << "m1 != m2" << "\n";
  }

  if (m2 != m3)
  {
    std::cout << "m2 != m3" << "\n";
  }
  else
  {
    std::cout << "m2 == m3" << "\n";
  }

  std::cout << "m2[1] = " << m2[1] << "\n";

  std::cout << "m4 =\n" << m4 << "\nm5 =\n" << m5 << "\n";

  m4.ReSize(2, 2); m5.ReSize(5, 4);

  std::cout << "m4 =\n" << m4 << "\nm5 =\n" << m5 << "\n";

  m3[0][0] = 4.43; m3[0][1] = 3.6; m3[0][2] = 4.43; m3[0][3] = 8.99;
  m3[1][0] = 4.43; m3[1][1] = 2.23; m3[1][2] = 5.75; m3[1][3] = 4.43;
  m3[2][0] = 1.5; m3[2][1] = 4.43; m3[2][2] = 6.43; m3[2][3] = 7.28;

  std::cout << "m3 =\n" << m3 << "\n";

  std::cout << "4.43 in m3 meet: " << m3.CountElem(4.43) << "\n";

  int** masindex2 = m3.MasIndex(4.43, k);

  std::cout << "4.43 in m3 have index: ";
  for (int i = 0; i < k - 1; i++)
  {
    std::cout << masindex2[i][0] << " " << masindex2[i][1] << ", ";
  }
  std::cout << masindex2[k - 1][0] << " " << masindex2[k - 1][1] << "\n";

  std::cout << "m2:";
  std::cin >> m2;

  std::cout << "m2 =\n" << m2 << "\n";
}

int main()
{
  int x = 0;

  std::cout << "1. int" << "\n" << "2. double" << "\n";

  std::cin >> x;

  switch (x)
  {
  case 1:
  {
    mainint();
    break;
  }
  case 2:
  {
    maindouble();
    break;
  }
  default:
    break;
  }

  return 0;
}