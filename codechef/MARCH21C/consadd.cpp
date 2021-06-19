#include <bits/stdc++.h>

using namespace std;

int r,c,x;

class Matrix{
public:
    long **m;    
    void allocMatrix();
    void deallocMatrix();    
    Matrix(int row, int collumn);
    Matrix(Matrix *m1, Matrix *m2);
    ~Matrix();
    void readMatrix();
    void displayMatrix();
    void setRow(int row, int p);
    void setColl(int col, int p);
    void consAdd1d_row();
    void consAdd1d_col();
    bool isZero();
};

Matrix::Matrix(int row, int collumn){
    allocMatrix();
}

Matrix::Matrix(Matrix *m1, Matrix *m2){
	allocMatrix();
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			m[i][j]=m1->m[i][j]-m2->m[i][j];
}

Matrix::~Matrix(){
    deallocMatrix();
}

void Matrix::allocMatrix(){
    m = new long *[r];
    for (int i = 0; i < r; i++)
        m[i] = new long[c];
}

void Matrix::deallocMatrix(){
    for (int i = 0; i < r; i++)
        delete[] m[i];

    delete[] m;
}

void Matrix::readMatrix(){
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            // //cout << "Enter [" << i << "][" << j << "] th element : ";
            cin >> m[i][j];
        }
}

void Matrix::displayMatrix(){
    // //cout << "Displaying matrix content :: \n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << "   " << m[i][j];
        cout << "\n";
    }
    cout << "\n";
}

void Matrix::consAdd1d_row(){
	//cout<<"in Cons Add 1d Row\n";	
	// displayMatrix();

	for(int j=0; j<r; j++){
		int carry=0;
		queue<int>q;
		for(int i=0; i<c; i++){
			// cout<<m[j][i]<<" -> ";
				
			if(i >= x){
				// cout<<carry<<" decreasedby "
					// <<q.front()<<" to ";
				carry -= q.front();
				q.pop();
				// cout<<carry<<" ";
			}
			// cout<<m[j][i]-carry<<"pushed ";
			q.push(m[j][i]-carry);
			if(i<=c-x)
				carry += m[j][i]-carry;
			// cout<<carry;
			m[j][i] -= carry;
			// cout<<"\n";
		}
		// cout<<"\n";
	}

	// displayMatrix();
}

void Matrix::consAdd1d_col(){
	//cout<<"in Cons Add 1d Col\n";
	
	// displayMatrix();

	for(int i=0; i<c; i++){
		int carry=0;
		queue<int>q;
		for(int j=0; j<r; j++){
			//cout<<m[j][i]<<" -> ";
			
			if(j >= x){
				//cout<<carry<<" decreasedto ";
				carry -= q.front();
				q.pop();
				//cout<<carry<<" ";
			}
			q.push(m[j][i]-carry);
			if(j<=r-x)
				carry += m[j][i]-carry;
			//cout<<carry;
			m[j][i] -= carry;
			//cout<<"\n";
		}
		//cout<<"\n";
	}

	// displayMatrix();
}

bool Matrix::isZero(){
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if( m[i][j]!=0)
				return false;
		}
	}

	return true;
}

void func(){
	cin>>r>>c>>x;
	Matrix A(r,c), B(r,c);
	A.readMatrix();
	B.readMatrix();
	Matrix C( &A, &B);
	// A.displayMatrix();
	// B.displayMatrix();
	// C.displayMatrix();
	
	// C.displayMatrix();

	C.consAdd1d_row();
	// C.displayMatrix();

	C.consAdd1d_col();
	// C.displayMatrix();

	if(C.isZero())
		cout<<"Yes";
	else
		cout<<"No";


	cout<<"\n";
}

int main(){
	int t;
	cin>>t;
	while(t--)
		func();
}