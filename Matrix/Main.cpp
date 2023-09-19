#include <iostream>
#include <math.h>
using namespace std;

#define delimiter "\n-----------------------------------------------------------------\n"

class Matrix
{
private:
    int Row;
    int Col;
    int** arr;
public:
    int GetMij(int i, int j)
    {
        if ((Row > 0) && (Col > 0))
            return arr[i][j];
        else
            return 0;
    }
    int GetRow()
    {
        return Row;
    }
    int GetCol()
    {
        return Col;
    }
    void SetMij(int i, int j, int value)
    {
        if ((i < 0) || (i >= Row))
            return;
        if ((j < 0) || (j >= Col))
            return;
       arr[i][j] = value;
    }
                                             // Constructors
    Matrix():arr(new int* [Row])
    {
        cout << "DefaulConstructor:\t" << this << endl;
    }

    Matrix(int Row, int Col):Row(Row),Col(Col),arr(new int*[Row])
    {
        for (int i = 0; i < Row; i++)
            arr[i] = (int*)new int[Col];

        for (int i = 0; i < Row; i++)
            for (int j = 0; j < Col; j++)
                arr[i][j] = 0;
    }

    Matrix(const Matrix& other):Row(other.Row),Col(other.Col),arr(new int*[Row])
    {
        for (int i = 0; i < Row; i++)
            this->arr[i] = (int*) new int[Col];

        for (int i = 0; i < Row; i++)
            for (int j = 0; j < Col; j++)
                this->arr[i][j] = other.arr[i][j];
    }
    ~Matrix()
    {
        if (Col > 0)
        {
           for (int i = 0; i < Row; i++)
                delete[] arr[i];
        }

        if (Row > 0)
            delete[] arr;
    }
                                    //Operators
    Matrix operator=(const Matrix& other)
    {
        if (Col > 0)
        {
            for (int i = 0; i < Row; i++)
                delete[] arr[i];
        }
        if (Row > 0)
        {
            delete[] arr;
        }
        this->Row = other.Row;
        this->Col = other.Col;
        this->arr = (int**) new int * [Row];
        for (int i = 0; i < Row; i++)
            arr[i] = (int*) new int[Col];
        for (int i = 0; i < Row; i++)
            for (int j = 0; j < Col; j++)
                arr[i][j] = other.arr[i][j];
        return *this;
    }
                                     // Methods
    void print()
    {
        for (int i = 0; i < Row; i++)
        {
            for (int j = 0; j < Col; j++)
                cout << arr[i][j] << "\t";
            cout << endl;
        }
        cout << endl;
    }   
};
                            //Operators
Matrix operator+(Matrix left, Matrix right)
{
    if ((left.GetRow() != right.GetRow()) || (left.GetCol() != right.GetCol()))
    {
        cout << "С данными матрицами нельзя произвести операцию сложения.";
        return left;
    }
    Matrix temp(left.GetRow(), left.GetCol());
    for (int i = 0; i < left.GetRow(); i++)
    {
        for (int j = 0; j < left.GetCol(); j++)
          temp.SetMij(i,j,left.GetMij(i,j)+right.GetMij(i,j));
        cout << endl;
    }
    return temp;        
}
Matrix operator-(Matrix left, Matrix right)
{
    if ((left.GetRow() != right.GetRow()) || (left.GetCol() != right.GetCol()))
    {
        cout << "С данными матрицами нельзя произвести операцию вычитания.";
        return left;
    }
    Matrix temp(left.GetRow(), left.GetCol());
    for (int i = 0; i < left.GetRow(); i++)
    {
        for (int j = 0; j < left.GetCol(); j++)
            temp.SetMij(i, j, left.GetMij(i, j) - right.GetMij(i, j));
        cout << endl;
    }
    return temp;
}
Matrix operator*(int mult, Matrix left)
{
    Matrix temp(left.GetRow(), left.GetCol());
    for (int i = 0; i < left.GetRow(); i++)
    {
        for (int j = 0; j < left.GetCol(); j++)
            temp.SetMij(i, j, left.GetMij(i, j)*mult);
        cout << endl;
    }
    return temp;
}
Matrix operator*(Matrix left, Matrix right)
{
    if (left.GetCol() != right.GetRow())
    {
        cout << "С данными матрицами нельзя произвести операцию перемножения.";
        return left;
    }
    Matrix result(left.GetRow(), right.GetCol());
    for (int i = 0; i < left.GetRow(); ++i)
    {
        for (int j = 0; j < right.GetCol(); ++j)
        {
            result.SetMij(i,j,0);
            for (int k = 0; k < left.GetCol(); ++k)
                result.SetMij(i, j, result.GetMij(i, j) + left.GetMij(i, k) * right.GetMij(k, j));
        }
    }
    return result;
}

void main()
{
    setlocale(LC_ALL, "");
    Matrix m1(3,2);
    for (int i = 0; i < m1.GetRow(); i++)
        for (int j = 0; j < m1.GetCol(); j++)
            m1.SetMij(i,j,rand() % 10);
    m1.print();
    cout << delimiter;
    Matrix m2(2, 3);
    for (int i = 0; i < m2.GetRow(); i++)
        for (int j = 0; j < m2.GetCol(); j++)
            m2.SetMij(i, j, rand() % 10);
    m2.print();
    /*cout << delimiter;
    Matrix m3 = m1 + m2;
    m3.print();
    cout << delimiter;
    Matrix m4 = m1 - m2;
    m4.print();*/
    cout << delimiter;
    Matrix m5 = m1 * m2;
    m5.print();
}