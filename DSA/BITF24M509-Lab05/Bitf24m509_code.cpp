#include <iostream>
#include <vector>
using namespace std;

class SparseMatrix
{
    struct matelem
    {
        int row;
        int col;
        int value;
    };

    int rows;
    int cols;
    vector<matelem> elements;

public:

    SparseMatrix(int r, int c)
    {
        rows = r;
        cols = c;
    }

    void addElementAt(int row, int col, int val)
    {
        if(val != 0)
        {
            matelem e;
            e.row = row;
            e.col = col;
            e.value = val;
            elements.push_back(e);
        }
    }

    int elementAt(int row, int col)
    {
        for(int i=0;i<elements.size();i++)
        {
            if(elements[i].row == row && elements[i].col == col)
                return elements[i].value;
        }
        return 0;
    }

    void showMatrixData()
    {
        cout<<"Row Col Value"<<endl;

        for(int i=0;i<elements.size();i++)
        {
            cout<<elements[i].row<<" "
                <<elements[i].col<<" "
                <<elements[i].value<<endl;
        }
    }

    void showMatrix()
    {
        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cout<<elementAt(i,j)<<" ";
            }
            cout<<endl;
        }
    }

    void inputMatrix()
    {
        int value;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                cin>>value;

                if(value != 0)
                    addElementAt(i,j,value);
            }
        }
    }

    SparseMatrix transposeMatrix()
    {
        SparseMatrix t(cols,rows);

        for(int i=0;i<elements.size();i++)
        {
            t.addElementAt(elements[i].col,
                           elements[i].row,
                           elements[i].value);
        }

        return t;
    }

    void makeEmpty()
    {
        elements.clear();
    }

    bool isSquareMatrix()
    {
        return rows == cols;
    }

    SparseMatrix addMatrices(SparseMatrix &mat2)
{
    if(rows != mat2.rows || cols != mat2.cols)
    {
        cout<<"Addition not possible"<<endl;
        SparseMatrix empty(rows, cols);
        return empty;
    }

    SparseMatrix result(rows,cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            int sum = elementAt(i,j) + mat2.elementAt(i,j);

            if(sum != 0)
                result.addElementAt(i,j,sum);
        }
    }

    return result;
}

    SparseMatrix multiplyMatrices(SparseMatrix &mat2)
{
    if(cols != mat2.rows)
    {
        cout<<"Multiplication not possible"<<endl;
        SparseMatrix empty(rows, mat2.cols);
        return empty;
    }

    SparseMatrix result(rows, mat2.cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<mat2.cols;j++)
        {
            int sum = 0;

            for(int k=0;k<cols;k++)
            {
                sum += elementAt(i,k) * mat2.elementAt(k,j);
            }

            if(sum != 0)
                result.addElementAt(i,j,sum);
        }
    }

    return result;
}
};


int main()
{
    int r,c;

    cout<<"Enter rows and cols for matrix 1: ";
    cin>>r>>c;

    SparseMatrix mat1(r,c);

    cout<<"Enter matrix values:"<<endl;
    mat1.inputMatrix();

    cout<<"\nMatrix 1:"<<endl;
    mat1.showMatrix();

    cout<<"\nTriple Representation:"<<endl;
    mat1.showMatrixData();


    cout<<"\nTranspose:"<<endl;
    SparseMatrix t = mat1.transposeMatrix();
    t.showMatrix();


    if(mat1.isSquareMatrix())
        cout<<"\nMatrix is Square"<<endl;
    else
        cout<<"\nMatrix is NOT Square"<<endl;


    cout<<"\nEnter rows and cols for matrix 2: ";
    cin>>r>>c;

    SparseMatrix mat2(r,c);

    cout<<"Enter matrix values:"<<endl;
    mat2.inputMatrix();

    cout<<"\nAddition Result:"<<endl;
    SparseMatrix add = mat1.addMatrices(mat2);
    add.showMatrix();


    cout<<"\nMultiplication Result:"<<endl;
    SparseMatrix mul = mat1.multiplyMatrices(mat2);
    mul.showMatrix();


    return 0;
}